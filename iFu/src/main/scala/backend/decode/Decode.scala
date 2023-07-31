package iFu.backend

import chisel3._
import chisel3.util._
import iFu.isa.Instructions._
import iFu.common.Consts._
import iFu.common._
import iFu.util._
import iFu.backend.DecodeLogic
import iFu.backend.{CSR, MemoryOpConstants}


//TODO 增加Ori的检测，为move指令。增加andi的检测，为Nop指令  Done
//TODO ALU Decode
//TODO CSR指令中rd既是源操作数(rs1)，又是目的操作数 Done
//TODO B和BL的uop均为uopJAL，BL的目的寄存器恒为1 Done
//TODO Wired Decode和TLB Decode

object CSR {
    // commands
    val SZ = 3
    def X = BitPat.dontCare(SZ)
    def N = 0.U(SZ.W)
    def R = 2.U(SZ.W)
    def I = 4.U(SZ.W)
    def W = 5.U(SZ.W)
    def S = 6.U(SZ.W)
    def C = 7.U(SZ.W)
}

object MemoryOpConstants {
    val NUM_XA_OPS = 9
    val M_SZ        = 5
    def M_X         = BitPat("b?????");
    def M_XRD       = "b00000".U; // int load
    def M_XWR       = "b00001".U; // int store
    def M_PFR       = "b00010".U; // prefetch with intent to read
    def M_PFW       = "b00011".U; // prefetch with intent to write
    def M_XA_SWAP   = "b00100".U
    def M_FLUSH_ALL = "b00101".U  // flush all lines
    def M_XLL       = "b00110".U  //XLC -> XLL
    def M_XSC       = "b00111".U
    def M_XA_ADD    = "b01000".U
    def M_XA_XOR    = "b01001".U
    def M_XA_OR     = "b01010".U
    def M_XA_AND    = "b01011".U
    def M_XA_MIN    = "b01100".U
    def M_XA_MAX    = "b01101".U
    def M_XA_MINU   = "b01110".U
    def M_XA_MAXU   = "b01111".U
    def M_FLUSH     = "b10000".U // write back dirty data and cede R/W permissions
    def M_PWR       = "b10001".U // partial (masked) store
    def M_PRODUCE   = "b10010".U // write back dirty data and cede W permissions
    def M_CLEAN     = "b10011".U // write back dirty data and retain R/W permissions
    def M_SFENCE    = "b10100".U // SFENCE.VMA
    def M_HFENCEV   = "b10101".U // HFENCE.VVMA
    def M_HFENCEG   = "b10110".U // HFENCE.GVMA
    def M_WOK       = "b10111".U // check write permissions but don't perform a write
    def M_HLVX      = "b10000".U // HLVX instruction

//    def isAMOLogical(cmd: UInt) = cmd.isOneOf(M_XA_SWAP, M_XA_XOR, M_XA_OR, M_XA_AND)
//    def isAMOArithmetic(cmd: UInt) = cmd.isOneOf(M_XA_ADD, M_XA_MIN, M_XA_MAX, M_XA_MINU, M_XA_MAXU)
//    def isAMO(cmd: UInt) = isAMOLogical(cmd) || isAMOArithmetic(cmd)
//    def isPrefetch(cmd: UInt) = cmd === M_PFR || cmd === M_PFW
//    def isRead(cmd: UInt) = cmd.isOneOf(M_XRD, M_HLVX, M_XLR, M_XSC) || isAMO(cmd)
//    def isWrite(cmd: UInt) = cmd === M_XWR || cmd === M_PWR || cmd === M_XSC || isAMO(cmd)
//    def isWriteIntent(cmd: UInt) = isWrite(cmd) || cmd === M_PFW || cmd === M_XLR
}

abstract trait DecodeTable {
    val DC2 = BitPat.dontCare(2)

    def decode_default: List[BitPat] =
    //                                                                  frs3_en                        wakeup_delay
    //     is val inst?                                                 |  imm sel                     |    bypassable (aka, known/fixed latency)
    //     |                                                            |  |     uses_ldq              |    |  is_br
    //     |     is single-prec?                        rs1 regtype     |  |     |  uses_stq           |    |  |
    //     |     |  micro-code                          |       rs2 type|  |     |  |  is_amo          |    |  |
    //     |     |  |         iq-type  func unit        |       |       |  |     |  |  |  is_fence     |    |  |
    //     |     |  |         |        |                |       |       |  |     |  |  |  |  is_fencei |    |  |  is breakpoint or ecall?
    //     |     |  |         |        |        dst     |       |       |  |     |  |  |  |  |  mem    |    |  |  |  is unique? (clear pipeline for it)
    //     |     |  |         |        |        regtype |       |       |  |     |  |  |  |  |  cmd    |    |  |  |  |  flush on commit
    //     |     |  |         |        |        |       |       |       |  |     |  |  |  |  |  |      |    |  |  |  |  |  csr cmd
    //     |     |  |         |        |        |       |       |       |  |     |  |  |  |  |  |      |    |  |  |  |  |  |
        List(N, uopX, IQT_INT, FU_X, RT_X, DC2, DC2, X, immX, X, X, X, X, N, /*M_X,*/ DC2, X, X, N, N, X, CSR.X)

    val table: Array[(BitPat, List[BitPat])]
}


class CtrlSigs extends Bundle {
    val legal           = Bool() //合法指令
    val uopc            = UInt(UOPC_SZ.W) //指令对应的uop操作
    val iq_type         = UInt(IQT_SZ.W) //issue queue type
    val fu_code         = UInt(FUC_SZ.W) //function code
    val dst_type        = UInt(1.W) //
    val rs1_type        = UInt(1.W) //
    val rs2_type        = UInt(1.W) //
    val imm_sel         = UInt(immX.getWidth.W) //立即数选择
    val uses_ldq        = Bool() //是否使用load
    val uses_stq        = Bool() //是否使用store
    val is_amo          = Bool() //原子指令
    val is_dbar         = Bool() //栅障指令
    val is_ibar         = Bool()
    /*val mem_cmd         = UInt(M_SZ.W)*/ //
    val wakeup_delay    = UInt(2.W) // TODO: 删除
    val bypassable      = Bool() //rename中需要
    val is_br           = Bool() //
    val is_sys_pc2epc   = Bool() //pc to epc（例外）
    val inst_unique     = Bool() //
    val flush_on_commit = Bool()
    val csr_cmd         = UInt(CSR.SZ.W)

    def decode(instr: UInt, table: Iterable[(BitPat, List[BitPat])]) = {
        val decoder = DecodeLogic(instr, XDecode.decode_default, table) //返回一个List[BitPat] 若匹配不到，则返回默认值
        val sigs = Seq(
            legal, uopc, iq_type, fu_code, dst_type, rs1_type,
            rs2_type, imm_sel, uses_ldq, uses_stq, is_amo,
            is_dbar, is_ibar, /*mem_cmd, */wakeup_delay, bypassable,
            is_br, is_sys_pc2epc, inst_unique, flush_on_commit, csr_cmd
        )
        sigs zip decoder map { case (s, d) => s := d } //将对应位相匹配
        this
    }
}

object XDecode extends DecodeTable  {
                //                                                                                          wakeup_delay
                //      is val inst?                                                imm_sel                      |   bypassable (aka, known/fixed latency)
                //      |  micro-code                                                |     uses_ldg               |   |  is_br
                //      |  |              iq-type                                    |     |  uses_stq            |   |  |  is_pc2epc
                //      |  |                 |       func unit                       |     |  |  is_amo           |   |  |  |  is_unique(clear pipeline for it)
                //      |  |                 |        |       dst_type               |     |  |  |  is_fence      |   |  |  |  |  flush_on_commit
                //      |  |                 |        |       |       rs1_type       |     |  |  |  |  is_fencei  |   |  |  |  |  |  csr_cmd
                //      |  |                 |        |       |       |              |     |  |  |  |  |          |   |  |  |  |  |  |
                //      |  |                 |        |       |       |    rs2_type  |     |  |  |  |  |          |   |  |  |  |  |  |
                //      |  |                 |        |       |       |       |      |     |  |  |  |  |  mem_cmd |   |  |  |  |  |  |
    val table: Array[(BitPat, List[BitPat])] = Array(//       |       |       |      |     |  |  |  |  |    |     |   |  |  |  |  |  |
        LLW     -> List(Y, uopLLW       , IQT_MEM, FU_MEM, RT_FIX, RT_FIX, RT_X  , immS14, Y, N, N, N, N, /*M_XLL,*/ 0.U, N, N, N, Y, Y, CSR.N),
        SCW     -> List(Y, uopAMO_AG    , IQT_MEM, FU_MEM, RT_FIX, RT_FIX, RT_X  , immS14, N, Y, Y, N, N, /*M_XSC,*/ 0.U, N, N, N, Y, Y, CSR.N),
        PRELD   -> List(Y, uopLD        , IQT_MEM, FU_MEM, RT_X  , RT_FIX, RT_X  , immS12, N, N, N, N, N, /*M_X  ,*/ 0.U, N, N, N, N, N, CSR.N),//暂定为load指令
        DBAR    -> List(Y, uopDBAR      , IQT_MEM, FU_MEM, RT_X  , RT_X  , RT_X  , immX  , N, Y, N, Y, N, /*M_X  ,*/ 0.U, N, N, N, Y, Y, CSR.N),
        IBAR    -> List(Y, uopNOP       , IQT_MEM, FU_X  , RT_X  , RT_X  , RT_X  , immX  , N, N, N, N, Y, /*M_X  ,*/ 0.U, N, N, N, Y, Y, CSR.N),
        SRLIW   -> List(Y, uopSRLIW     , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_X  , immU5 , N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
        SRAIW   -> List(Y, uopSRAIW     , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_X  , immU5 , N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
        SRLW    -> List(Y, uopSRLW      , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
        SRAW    -> List(Y, uopSRAW      , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
        SLLIW   -> List(Y, uopSLLIW     , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_X  , immU5 , N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
        MODWU   -> List(Y, uopMODWU     , IQT_INT, FU_DIV, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/ 0.U, N, N, N, N, N, CSR.N),
        DIVWU   -> List(Y, uopDIVWU     , IQT_INT, FU_DIV, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/ 0.U, N, N, N, N, N, CSR.N),
        DIVW    -> List(Y, uopDIVW      , IQT_INT, FU_DIV, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/ 0.U, N, N, N, N, N, CSR.N),
        MODW    -> List(Y, uopMODW      , IQT_INT, FU_DIV, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/ 0.U, N, N, N, N, N, CSR.N),
        MULHWU  -> List(Y, uopMULHWU    , IQT_INT, FU_MUL, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/ 0.U, N, N, N, N, N, CSR.N),
        MULHW   -> List(Y, uopMULHW     , IQT_INT, FU_MUL, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/ 0.U, N, N, N, N, N, CSR.N),
        MULW    -> List(Y, uopMULW      , IQT_INT, FU_MUL, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/ 0.U, N, N, N, N, N, CSR.N),
        ORN     -> List(Y, uopORN       , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
        ANDN    -> List(Y, uopANDN      , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
       PCADDU12I-> List(Y, uopPCADDU12I , IQT_INT, FU_JMP, RT_FIX, RT_X  , RT_X  , immU20, N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
        PCADDI  -> List(Y, uopPCADDI    , IQT_INT, FU_JMP, RT_FIX, RT_X  , RT_X  , immS20, N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
        LU12IW  -> List(Y, uopLU12IW    , IQT_INT, FU_ALU, RT_FIX, RT_X  , RT_X  , immU20, N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
        OR      -> List(Y, uopOR        , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
        NOR     -> List(Y, uopNOR       , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
        LDW     -> List(Y, uopLD        , IQT_MEM, FU_MEM, RT_FIX, RT_FIX, RT_X  , immS12, Y, N, N, N, N, /*M_XRD,*/ 3.U, N, N, N, N, N, CSR.N),
        LDH     -> List(Y, uopLD        , IQT_MEM, FU_MEM, RT_FIX, RT_FIX, RT_X  , immS12, Y, N, N, N, N, /*M_XRD,*/ 3.U, N, N, N, N, N, CSR.N),
        LDHU    -> List(Y, uopLD        , IQT_MEM, FU_MEM, RT_FIX, RT_FIX, RT_X  , immS12, Y, N, N, N, N, /*M_XRD,*/ 3.U, N, N, N, N, N, CSR.N),
        LDB     -> List(Y, uopLD        , IQT_MEM, FU_MEM, RT_FIX, RT_FIX, RT_X  , immS12, Y, N, N, N, N, /*M_XRD,*/ 3.U, N, N, N, N, N, CSR.N),
        LDBU    -> List(Y, uopLD        , IQT_MEM, FU_MEM, RT_FIX, RT_FIX, RT_X  , immS12, Y, N, N, N, N, /*M_XRD,*/ 3.U, N, N, N, N, N, CSR.N),
        STW     -> List(Y, uopSTA       , IQT_MEM, FU_MEM, RT_X  , RT_FIX, RT_FIX, immS12, N, Y, N, N, N, /*M_XWR,*/ 0.U, N, N, N, N, N, CSR.N),
        STH     -> List(Y, uopSTA       , IQT_MEM, FU_MEM, RT_X  , RT_FIX, RT_FIX, immS12, N, Y, N, N, N, /*M_XWR,*/ 0.U, N, N, N, N, N, CSR.N),
        STB     -> List(Y, uopSTA       , IQT_MEM, FU_MEM, RT_X  , RT_FIX, RT_FIX, immS12, N, Y, N, N, N, /*M_XWR,*/ 0.U, N, N, N, N, N, CSR.N),
        ADDIW   -> List(Y, uopADDIW     , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_X  , immS12, N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
        ANDI    -> List(Y, uopANDI      , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_X  , immU12, N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
        ORI     -> List(Y, uopORI       , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_X  , immU12, N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
        XORI    -> List(Y, uopXORI      , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_X  , immU12, N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
        SLTI    -> List(Y, uopSLTI      , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_X  , immS12, N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
        SLTUI   -> List(Y, uopSLTUI     , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_X  , immS12, N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
        SLLW    -> List(Y, uopSLLW      , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
        ADDW    -> List(Y, uopADD       , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
        SUBW    -> List(Y, uopSUB       , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
        SLT     -> List(Y, uopSLT       , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
        SLTU    -> List(Y, uopSLTU      , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
        AND     -> List(Y, uopAND       , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
        XOR     -> List(Y, uopXOR       , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/ 1.U, Y, N, N, N, N, CSR.N),
        JIRL    -> List(Y, uopJIRL      , IQT_INT, FU_JMP, RT_FIX, RT_FIX, RT_X  , immS16, N, N, N, N, N, /*M_X  ,*/ 1.U, N, N, N, N, N, CSR.N),
        B       -> List(Y, uopJAL       , IQT_INT, FU_JMP, RT_X  , RT_X  , RT_X  , immS26, N, N, N, N, N, /*M_X  ,*/ 1.U, N, N, N, N, N, CSR.N),
        BL      -> List(Y, uopJAL       , IQT_INT, FU_JMP, RT_FIX, RT_X  , RT_X  , immS26, N, N, N, N, N, /*M_X  ,*/ 1.U, N, N, N, N, N, CSR.N),
        BEQ     -> List(Y, uopBEQ       , IQT_INT, FU_ALU, RT_X  , RT_FIX, RT_FIX, immS16, N, N, N, N, N, /*M_X  ,*/ 0.U, N, Y, N, N, N, CSR.N),
        BNE     -> List(Y, uopBNE       , IQT_INT, FU_ALU, RT_X  , RT_FIX, RT_FIX, immS16, N, N, N, N, N, /*M_X  ,*/ 0.U, N, Y, N, N, N, CSR.N),
        BGE     -> List(Y, uopBGE       , IQT_INT, FU_ALU, RT_X  , RT_FIX, RT_FIX, immS16, N, N, N, N, N, /*M_X  ,*/ 0.U, N, Y, N, N, N, CSR.N),
        BGEU    -> List(Y, uopBGEU      , IQT_INT, FU_ALU, RT_X  , RT_FIX, RT_FIX, immS16, N, N, N, N, N, /*M_X  ,*/ 0.U, N, Y, N, N, N, CSR.N),
        BLT     -> List(Y, uopBLT       , IQT_INT, FU_ALU, RT_X  , RT_FIX, RT_FIX, immS16, N, N, N, N, N, /*M_X  ,*/ 0.U, N, Y, N, N, N, CSR.N),
        BLTU    -> List(Y, uopBLTU      , IQT_INT, FU_ALU, RT_X  , RT_FIX, RT_FIX, immS16, N, N, N, N, N, /*M_X  ,*/ 0.U, N, Y, N, N, N, CSR.N),
    )
}

// object TLBDeocde extends DecodeTable with MicroOpCode {
//                 //                                                                                          wakeup_delay
//                 //      is val inst?                                                imm_sel                      |   bypassable (aka, known/fixed latency)
//                 //      |  micro-code                                                |    uses_ldg               |   |  is_br
//                 //      |     |           iq-type                        rs1 regtype |    |  uses_stq            |   |  |  is_pc2epc
//                 //      |     |              |       func unit                       |    |  |  is_amo           |   |  |  |  is_unique(clear pipeline for it)
//                 //      |     |              |        |       dst_type          |    |    |  |  |  is_fence      |   |  |  |  |  flush_on_commit
//                 //      |     |              |        |       |       rs1_type       |    |  |  |  |  is_fencei  |   |  |  |  |  |  csr_cmd
//                 //      |     |              |        |       |       |              |    |  |  |  |  |          |   |  |  |  |  |  |
//                 //      |     |              |        |       |       |    rs2_type  |    |  |  |  |  |          |   |  |  |  |  |  |
//                 //      |     |              |        |       |       |       |      |    |  |  |  |  |  mem_cmd |   |  |  |  |  |  |
//     val table: Array[(BitPat, List[BitPat])] = Array( //      |       |       |      |    |  |  |  |  |    |     |   |  |  |  |  |  |
//         TLBSRCH -> List(Y, uopTLBSRCH),
//         TLBFILL -> List(Y, uopTLBFILL),
//         TLBRD   -> List(Y, uopTLBRD),
//         TLBWR   -> List(Y, uopTLBWR),
//         INVTLB  -> List(Y, uopINVTLB)
//     )
// }

// object CSRDecode extends DecodeTable with MicroOpCode {
//                 //                                                                                          wakeup_delay
//                 //      is val inst?                                                imm_sel                      |   bypassable (aka, known/fixed latency)
//                 //      |  micro-code                                                |    uses_ldg               |   |  is_br
//                 //      |     |           iq-type                        rs1 regtype |    |  uses_stq            |   |  |  is_pc2epc
//                 //      |     |              |       func unit                       |    |  |  is_amo           |   |  |  |  is_unique(clear pipeline for it)
//                 //      |     |              |        |       dst_type          |    |    |  |  |  is_fence      |   |  |  |  |  flush_on_commit
//                 //      |     |              |        |       |       rs1_type       |    |  |  |  |  is_fencei  |   |  |  |  |  |  csr_cmd
//                 //      |     |              |        |       |       |              |    |  |  |  |  |          |   |  |  |  |  |  |
//                 //      |     |              |        |       |       |    rs2_type  |    |  |  |  |  |          |   |  |  |  |  |  |
//                 //      |     |              |        |       |       |       |      |    |  |  |  |  |  mem_cmd |   |  |  |  |  |  |
//     val table: Array[(BitPat, List[BitPat])] = Array( //      |       |       |      |    |  |  |  |  |    |     |   |  |  |  |  |  |
//         CSRRD  -> List(Y, uopCSRRD       , IQT_INT, FU_CSR, RT_FIX, RT_X  , RT_X  , immX, N, N, N, N, N, M_X, 0.U, N, N, N, Y, Y, CSR.R),
//         CSRWR  -> List(Y, uopCSRWR       , IQT_INT, FU_CSR, RT_FIX, RT_FIX, RT_X  , immX, N, N, N, N, N, M_X, 0.U, N, N, N, Y, Y, CSR.W),
//         CSRXCHG-> List(Y, uopCSRXCHG     , IQT_INT, FU_CSR, RT_FIX, RT_FIX, RT_FIX, immX, N, N, N, N, N, M_X, 0.U, N, N, N, Y, Y, CSR.W),
//         ERTN   -> List(Y, uopERET        , IQT_INT, FU_CSR, RT_X  , RT_X  , RT_X  , immX, N, N, N, N, N, M_X, 0.U, Y, N, N, Y, Y, CSR.I),
//         SYSCALL-> List(Y, uopERET        , IQT_INT, FU_CSR, RT_X  , RT_X  , RT_X  , immX, N, N, N, N, N, M_X, 0.U, N, N, Y, Y, Y, CSR.I),
//         BREAK  -> List(Y, uopERET        , IQT_INT, FU_CSR, RT_X  , RT_X  , RT_X  , immX, N, N, N, N, N, M_X, 0.U, N, N, Y, Y, Y, CSR.I),
//     )
// }

// object WeirdDecode extends DecodeTable with MicroOpCode {
//                     //                                                                                          wakeup_delay
//                 //      is val inst?                                                imm_sel                      |   bypassable (aka, known/fixed latency)
//                 //      |  micro-code                                                |    uses_ldg               |   |  is_br
//                 //      |     |           iq-type                        rs1 regtype |    |  uses_stq            |   |  |  is_pc2epc
//                 //      |     |              |       func unit                       |    |  |  is_amo           |   |  |  |  is_unique(clear pipeline for it)
//                 //      |     |              |        |       dst_type          |    |    |  |  |  is_fence      |   |  |  |  |  flush_on_commit
//                 //      |     |              |        |       |       rs1_type       |    |  |  |  |  is_fencei  |   |  |  |  |  |  csr_cmd
//                 //      |     |              |        |       |       |              |    |  |  |  |  |          |   |  |  |  |  |  |
//                 //      |     |              |        |       |       |    rs2_type  |    |  |  |  |  |          |   |  |  |  |  |  |
//                 //      |     |              |        |       |       |       |      |    |  |  |  |  |  mem_cmd |   |  |  |  |  |  |
//     val table: Array[(BitPat, List[BitPat])] = Array( //      |       |       |      |    |  |  |  |  |    |     |   |  |  |  |  |  |
//         IDLE    -> List(Y, uopIDLE),
//         CACOP   -> List(Y, uopCACOP     , IQT_MEM, FU_MEM, RT_FIX, RT_FIX, RT_FIX, immX, N, N, N, N, N, M_X, 0.U, N, N, N, N, N, CSR.N),
//         RDCNTIDW-> List(Y, uopRDCNTIDW  , IQT_INT, FU_CNT, RT_FIX, RT_FIX, RT_FIX, immX, N, N, N, N, N, M_X, 0.U, N, N, N, N, N, CSR.N),
//         RDCNTVLW-> List(Y, uopRDCNTVLW  , IQT_INT, FU_CNT, RT_FIX, RT_FIX, RT_FIX, immX, N, N, N, N, N, M_X, 0.U, N, N, N, N, N, CSR.N),
//         RDCNTVHW-> List(Y, uopRDCNTVHW  , IQT_INT, FU_CNT, RT_FIX, RT_FIX, RT_FIX, immX, N, N, N, N, N, M_X, 0.U, N, N, N, N, N, CSR.N)
//     )
// }


//TODO 修改CSRFile

class DecodeUnitIO() extends CoreModule {
    val enq = new Bundle { val uop = Input(new MicroOp()) }
    val deq = new Bundle { val uop = Output(new MicroOp()) }

    // from CSRFile
    // val status = Input(new freechips.rocketchip.rocket.MStatus())
    // val csr_decode = Flipped(new freechips.rocketchip.rocket.CSRDecodeIO)
    // val interrupt = Input(Bool())
    // val interrupt_cause = Input(UInt(xLen.W))
}

//TODO 添加对CSR环境下异常指令的检测
class DecodeUnit extends CoreModule {
    val io = IO(new DecodeUnitIO)

    val uop = Wire(new MicroOp)
    uop := io.enq.uop

    var decode_table = XDecode.table
    // if(usingCSR) decode_table ++= CSRDecode.table
    // if(usingTLB) decode_table ++= TLBDeocde.table
    // if(usingWired)decode_table ++= WeirdDecode.table
    
    val inst = uop.instr
    val cs = Wire(new CtrlSigs).decode(inst, decode_table)

    // TODO: 异常检测
    // def checkExceptions(x: Seq[(Bool, UInt)]) =
    //     (x.map(_._1).reduce(_||_), PriorityMux(x))
    // val cs_legal = cs.legal
    // val id_illegal_insn = !cs_legal
    // val (xcpt_valid,xcpt_cause) = checkExceptions(List(
    //     (io.interrupt && !io.enq.uop.isSFB, io.interrupt_cause),
    //     (uop.bp_xcpt_if,                    (Causes.breakpoint).U),
    //     (uop.xcpt_pf_if,                    (Causes.fetch_page_fault).U),
    //     (uop.xcpt_ae_if,                    (Causes.fetch_access).U),
    //     (id_illegal_insn,                   (Causes.illegal_instruction).U)
    // ))

    uop.exception := /*xcpt_valid*/ false.B
    uop.excCause  := /*xcpt_cause*/ DontCare

    //-------------------------------------------------------------
    uop.uopc        := cs.uopc
    uop.iqType      := cs.iq_type
    uop.fuCode      := cs.fu_code

    uop.ldst        := inst(4,0)
    uop.lrs1        := inst(9,5)
    uop.lrs2        := inst(14,10)

    when(uop.uopc === uopJAL) {
        uop.ldst := 1.U
    }
    when(uop.uopc === uopBEQ || uop.uopc === uopBNE || uop.uopc === uopBGE || uop.uopc === uopBGEU || uop.uopc === uopBLT || uop.uopc === uopBLTU){
        uop.lrs2 := inst(4,0)
    }
    when(uop.uopc === uopSTA){
        uop.lrs2 := inst(4,0)
    }
    when(uop.uopc === uopCSRWR || uop.uopc === uopCSRXCHG) {
        uop.lrs1 := inst(4, 0)
        uop.lrs2 := inst(9, 5)
    }
    uop.ldst_val   := cs.dst_type =/= RT_X && !(uop.ldst === 0.U && uop.dst_rtype === RT_FIX)
    uop.dst_rtype  := cs.dst_type
    uop.lrs1_rtype := cs.rs1_type
    uop.lrs2_rtype := cs.rs2_type

    when (uop.is_sfb_shadow && cs.rs2_type === RT_X) {
        uop.lrs2_rtype := RT_FIX
        uop.lrs2 := inst(4, 0)
        uop.ldst_is_rs1 := false.B
    } .elsewhen (uop.is_sfb_shadow) {
        uop.lrs1 := inst(4, 0)
        uop.ldst_is_rs1 := true.B
    } .otherwise {
        uop.ldst_is_rs1 := false.B
    }

   /* when (!uop.is_sfb_shadow && cs.uopc === uopORI && inst(21,10) === 0.U) {
        uop.uopc := uopMOV
    }*/
    when(cs.uopc === uopANDI && inst(21,0) === 0.U){
        uop.uopc := uopNOP
    }
    when(uop.is_sfb_br){
        uop.fuCode := FU_JMP
    }

    /*uop.mem_cmd         := cs.mem_cmd*/
    uop.mem_size        := inst(23, 22)
    uop.mem_signed      := !inst(25)
    uop.use_ldq         := cs.uses_ldq
    uop.use_stq         := cs.uses_stq
    uop.is_amo          := cs.is_amo
    uop.is_fence         := cs.is_dbar
    uop.is_fencei         := cs.is_ibar
    uop.is_sys_pc2epc   := cs.is_sys_pc2epc
    uop.is_unique       := cs.inst_unique
    uop.flush_on_commit := cs.flush_on_commit
    uop.bypassable      := cs.bypassable

    uop.immPacked := inst(25,0)

    uop.isBr   := cs.is_br
    uop.isJal  := (uop.uopc === uopJAL)
    uop.isJalr := (uop.uopc === uopJIRL)
}

class BranchMaskGenerationLogic extends CoreModule
{
    val io = IO(new Bundle {
        // guess if the uop is a branch (we'll catch this later)
        val is_branch = Input(Vec(coreWidth, Bool()))
        // lock in that it's actually a branch and will fire, so we update
        // the branch_masks.
        val will_fire = Input(Vec(coreWidth, Bool()))

        // give out tag immediately (needed in rename)
        // mask can come later in the cycle
        val br_tag    = Output(Vec(coreWidth, UInt(log2Ceil(maxBrCount).W)))
        val br_mask   = Output(Vec(coreWidth, UInt(maxBrCount.W)))

        // tell decoders the branch mask has filled up, but on the granularity
        // of an individual micro-op (so some micro-ops can go through)
        val is_full   = Output(Vec(coreWidth, Bool())) //branchmask全为1

        val brupdate         = Input(new BrUpdateInfo())
        val flush_pipeline = Input(Bool())

        val debug_branch_mask = Output(UInt(maxBrCount.W))
    })

    val branch_mask = RegInit(0.U(maxBrCount.W))

    //-------------------------------------------------------------
    // Give out the branch tag to each branch micro-op

    var allocate_mask = branch_mask
    val tag_masks = Wire(Vec(coreWidth, UInt(maxBrCount.W)))

    for (w <- 0 until coreWidth) {
        // TODO this is a loss of performance as we're blocking branches based on potentially fake branches
        io.is_full(w) := (allocate_mask === ~(0.U(maxBrCount.W))) && io.is_branch(w)

        // find br_tag and compute next br_mask
        val new_br_tag = Wire(UInt(log2Ceil(maxBrCount).W))
        new_br_tag := 0.U
        tag_masks(w) := 0.U

        for (i <- maxBrCount-1 to 0 by -1) {
            when (~allocate_mask(i)) {
                new_br_tag := i.U
                tag_masks(w) := (1.U << i.U)    //会覆盖，结果是新的mask
            }
        }

        io.br_tag(w) := new_br_tag
        allocate_mask = Mux(io.is_branch(w), tag_masks(w) | allocate_mask, allocate_mask) //发射后的mask，并且由于是var类型，所以会覆盖
    }

    //-------------------------------------------------------------
    // Give out the branch mask to each micro-op
    // (kill off the bits that corresponded to branches that aren't going to fire)

    var curr_mask = branch_mask
    for (w <- 0 until coreWidth) {
        io.br_mask(w) := GetNewBrMask(io.brupdate, curr_mask)
        curr_mask = Mux(io.will_fire(w), tag_masks(w) | curr_mask, curr_mask)
    }

    //-------------------------------------------------------------
    // Update the current branch_mask

    when (io.flush_pipeline) {
        branch_mask := 0.U
    } .otherwise {
        val mask = Mux(io.brupdate.b2.mispredict,
            io.brupdate.b2.uop.brMask,
            ~(0.U(maxBrCount.W)))
        branch_mask := GetNewBrMask(io.brupdate, curr_mask) & mask
    }

    io.debug_branch_mask := branch_mask
}
