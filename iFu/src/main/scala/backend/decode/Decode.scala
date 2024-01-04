package iFu.backend

import chisel3._
import chisel3.util._
import iFu.isa.Instructions._
import iFu.common.Consts._
import iFu.common.CauseCode._
import iFu.common._
import iFu.util._
import iFu.util.ImplicitCast.uintToBitPat
import iFu.backend.DecodeLogic

//TODO 增加Ori的检测，为move指令。增加andi的检测，为Nop指令  Done
//TODO ALU Decode
//TODO CSR指令中rd既是源操作数(rs1)，又是目的操作数 Done
//TODO B和BL的uop均为uopJAL，BL的目的寄存器恒为1 Done
//TODO Wired Decode和TLB Decode

abstract trait DecodeTable {
    val DC2 = BitPat.dontCare(2)
    val DC1 = BitPat.dontCare(1)
    def decode_default: List[BitPat] =
    //
    //       is val inst?                          imm_sel                       bypassable (aka, known/fixed latency)
    //       |    micro-code                          |  uses_ldg                |  is_br
    //       |    |  iq-type                          |  |  uses_stq             |  |  is_pc2epc
    //       |    |     |     func unit               |  |  |  is_amo            |  |  |  is_unique(clear pipeline for it)
    //       |    |     |      |     dst_type         |  |  |  |  is_fence       |  |  |  |  flush_on_commit
    //       |    |     |      |     |    rs1_typ     |  |  |  |  |  is_fencei   |  |  |  |  |    csr_cmd
    //       |    |     |      |     |    |           |  |  |  |  |  |           |  |  |  |  |    |
    //       |    |     |      |     |    | rs2_type  |  |  |  |  |  |           |  |  |  |  |    |
    //       |    |     |      |     |    |    |      |  |  |  |  |  |  mem_cmd  |  |  |  |  |    |
        List(N, uopX, IQT_X, FU_X, RT_X, DC1, DC1, immX, X, X, X, X, N, /*M_X,*/ X, X, N, N, X, CSR_N)

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
    val bypassable      = Bool() //rename中需要
    val is_br           = Bool() //
    val is_sys_pc2epc   = Bool() //pc to epc（例外）
    val inst_unique     = Bool() //
    val flush_on_commit = Bool()
    val csr_cmd         = UInt(CSR_SZ.W)

    def decode(instr: UInt, table: Iterable[(BitPat, List[BitPat])]) = {
        val decoder = DecodeLogic(instr, XDecode.decode_default, table) //返回一个List[BitPat] 若匹配不到，则返回默认值
        val sigs = Seq(
            legal, uopc, iq_type, fu_code, dst_type, rs1_type,
            rs2_type, imm_sel, uses_ldq, uses_stq, is_amo,
            is_dbar, is_ibar, /*mem_cmd, */bypassable,
            is_br, is_sys_pc2epc, inst_unique, flush_on_commit, csr_cmd
        )
        sigs zip decoder map { case (s, d) => s := d } //将对应位相匹配
        this
    }

}

object XDecode extends DecodeTable  {
                //
                //      is val inst?                                                imm_sel                          bypassable (aka, known/fixed latency)
                //      |  micro-code                                                |     uses_ldg                   |  is_br
                //      |  |              iq-type                                    |     |  uses_stq                |  |  is_pc2epc
                //      |  |                 |       func unit                       |     |  |  is_amo               |  |  |  is_unique(clear pipeline for it)
                //      |  |                 |        |       dst_type               |     |  |  |  is_fence          |  |  |  |  flush_on_commit
                //      |  |                 |        |       |       rs1_type       |     |  |  |  |  is_fencei      |  |  |  |  |    csr_cmd
                //      |  |                 |        |       |       |              |     |  |  |  |  |              |  |  |  |  |    |
                //      |  |                 |        |       |       |    rs2_type  |     |  |  |  |  |              |  |  |  |  |    |
                //      |  |                 |        |       |       |       |      |     |  |  |  |  |  mem_cmd     |  |  |  |  |    |
    val table: Array[(BitPat, List[BitPat])] = Array(//       |       |       |      |     |  |  |  |  |    |         |  |  |  |  |    |
        LLW     -> List(Y, uopLLW       , IQT_MEM, FU_MEM, RT_FIX, RT_FIX, RT_X  , immS14, Y, N, N, N, N, /*M_XLL,*/  N, N, N, Y, Y, CSR_N),
        SCW     -> List(Y, uopAMO_AG    , IQT_MEM, FU_MEM, RT_FIX, RT_FIX, RT_X  , immS14, N, Y, Y, N, N, /*M_XSC,*/  N, N, N, Y, Y, CSR_N),
        PRELD   -> List(Y, uopLD        , IQT_MEM, FU_MEM, RT_X  , RT_FIX, RT_X  , immS12, N, N, N, N, N, /*M_X  ,*/  N, N, N, N, N, CSR_N),//暂定为load指令
        DBAR    -> List(Y, uopDBAR      , IQT_MEM, FU_MEM, RT_X  , RT_X  , RT_X  , immX  , N, Y, N, Y, N, /*M_X  ,*/  N, N, N, Y, Y, CSR_N),
        IBAR    -> List(Y, uopNOP       , IQT_MEM, FU_X  , RT_X  , RT_X  , RT_X  , immX  , N, N, N, N, Y, /*M_X  ,*/  N, N, N, Y, Y, CSR_N),
        SRLIW   -> List(Y, uopSRLIW     , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_X  , immU5 , N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
        SRAIW   -> List(Y, uopSRAIW     , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_X  , immU5 , N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
        SRLW    -> List(Y, uopSRLW      , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
        SRAW    -> List(Y, uopSRAW      , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
        SLLIW   -> List(Y, uopSLLIW     , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_X  , immU5 , N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
        MODWU   -> List(Y, uopMODWU     , IQT_INT, FU_DIV, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/  N, N, N, N, N, CSR_N),
        DIVWU   -> List(Y, uopDIVWU     , IQT_INT, FU_DIV, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/  N, N, N, N, N, CSR_N),
        DIVW    -> List(Y, uopDIVW      , IQT_INT, FU_DIV, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/  N, N, N, N, N, CSR_N),
        MODW    -> List(Y, uopMODW      , IQT_INT, FU_DIV, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/  N, N, N, N, N, CSR_N),
        MULHWU  -> List(Y, uopMULHWU    , IQT_INT, FU_MUL, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/  N, N, N, N, N, CSR_N),
        MULHW   -> List(Y, uopMULHW     , IQT_INT, FU_MUL, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/  N, N, N, N, N, CSR_N),
        MULW    -> List(Y, uopMULW      , IQT_INT, FU_MUL, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/  N, N, N, N, N, CSR_N),
        ORN     -> List(Y, uopORN       , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
        ANDN    -> List(Y, uopANDN      , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
       PCADDU12I-> List(Y, uopPCADDU12I , IQT_INT, FU_JMP, RT_FIX, RT_X  , RT_X  , immU20, N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
        PCADDI  -> List(Y, uopPCADDI    , IQT_INT, FU_JMP, RT_FIX, RT_X  , RT_X  , immS20, N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
        LU12IW  -> List(Y, uopLU12IW    , IQT_INT, FU_ALU, RT_FIX, RT_X  , RT_X  , immU20, N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
        OR      -> List(Y, uopOR        , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
        NOR     -> List(Y, uopNOR       , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
        LDW     -> List(Y, uopLD        , IQT_MEM, FU_MEM, RT_FIX, RT_FIX, RT_X  , immS12, Y, N, N, N, N, /*M_XRD,*/  N, N, N, N, N, CSR_N),
        LDH     -> List(Y, uopLD        , IQT_MEM, FU_MEM, RT_FIX, RT_FIX, RT_X  , immS12, Y, N, N, N, N, /*M_XRD,*/  N, N, N, N, N, CSR_N),
        LDHU    -> List(Y, uopLD        , IQT_MEM, FU_MEM, RT_FIX, RT_FIX, RT_X  , immS12, Y, N, N, N, N, /*M_XRD,*/  N, N, N, N, N, CSR_N),
        LDB     -> List(Y, uopLD        , IQT_MEM, FU_MEM, RT_FIX, RT_FIX, RT_X  , immS12, Y, N, N, N, N, /*M_XRD,*/  N, N, N, N, N, CSR_N),
        LDBU    -> List(Y, uopLD        , IQT_MEM, FU_MEM, RT_FIX, RT_FIX, RT_X  , immS12, Y, N, N, N, N, /*M_XRD,*/  N, N, N, N, N, CSR_N),
        STW     -> List(Y, uopSTA       , IQT_MEM, FU_MEM, RT_X  , RT_FIX, RT_FIX, immS12, N, Y, N, N, N, /*M_XWR,*/  N, N, N, N, N, CSR_N),
        STH     -> List(Y, uopSTA       , IQT_MEM, FU_MEM, RT_X  , RT_FIX, RT_FIX, immS12, N, Y, N, N, N, /*M_XWR,*/  N, N, N, N, N, CSR_N),
        STB     -> List(Y, uopSTA       , IQT_MEM, FU_MEM, RT_X  , RT_FIX, RT_FIX, immS12, N, Y, N, N, N, /*M_XWR,*/  N, N, N, N, N, CSR_N),
        ADDIW   -> List(Y, uopADDIW     , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_X  , immS12, N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
        ANDI    -> List(Y, uopANDI      , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_X  , immU12, N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
        ORI     -> List(Y, uopORI       , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_X  , immU12, N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
        XORI    -> List(Y, uopXORI      , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_X  , immU12, N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
        SLTI    -> List(Y, uopSLTI      , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_X  , immS12, N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
        SLTUI   -> List(Y, uopSLTUI     , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_X  , immS12, N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
        SLLW    -> List(Y, uopSLLW      , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
        ADDW    -> List(Y, uopADD       , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
        SUBW    -> List(Y, uopSUB       , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
        SLT     -> List(Y, uopSLT       , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
        SLTU    -> List(Y, uopSLTU      , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
        AND     -> List(Y, uopAND       , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
        XOR     -> List(Y, uopXOR       , IQT_INT, FU_ALU, RT_FIX, RT_FIX, RT_FIX, immX  , N, N, N, N, N, /*M_X  ,*/  Y, N, N, N, N, CSR_N),
        JIRL    -> List(Y, uopJIRL      , IQT_INT, FU_JMP, RT_FIX, RT_FIX, RT_X  , immS16, N, N, N, N, N, /*M_X  ,*/  N, N, N, N, N, CSR_N),
        B       -> List(Y, uopJAL       , IQT_INT, FU_JMP, RT_X  , RT_X  , RT_X  , immS26, N, N, N, N, N, /*M_X  ,*/  N, N, N, N, N, CSR_N),
        BL      -> List(Y, uopJAL       , IQT_INT, FU_JMP, RT_FIX, RT_X  , RT_X  , immS26, N, N, N, N, N, /*M_X  ,*/  N, N, N, N, N, CSR_N),
        BEQ     -> List(Y, uopBEQ       , IQT_INT, FU_ALU, RT_X  , RT_FIX, RT_FIX, immS16, N, N, N, N, N, /*M_X  ,*/  N, Y, N, N, N, CSR_N),
        BNE     -> List(Y, uopBNE       , IQT_INT, FU_ALU, RT_X  , RT_FIX, RT_FIX, immS16, N, N, N, N, N, /*M_X  ,*/  N, Y, N, N, N, CSR_N),
        BGE     -> List(Y, uopBGE       , IQT_INT, FU_ALU, RT_X  , RT_FIX, RT_FIX, immS16, N, N, N, N, N, /*M_X  ,*/  N, Y, N, N, N, CSR_N),
        BGEU    -> List(Y, uopBGEU      , IQT_INT, FU_ALU, RT_X  , RT_FIX, RT_FIX, immS16, N, N, N, N, N, /*M_X  ,*/  N, Y, N, N, N, CSR_N),
        BLT     -> List(Y, uopBLT       , IQT_INT, FU_ALU, RT_X  , RT_FIX, RT_FIX, immS16, N, N, N, N, N, /*M_X  ,*/  N, Y, N, N, N, CSR_N),
        BLTU    -> List(Y, uopBLTU      , IQT_INT, FU_ALU, RT_X  , RT_FIX, RT_FIX, immS16, N, N, N, N, N, /*M_X  ,*/  N, Y, N, N, N, CSR_N),
    )
}

// object TLBDeocde extends DecodeTable {
//                 //
//                 //      is val inst?                                                imm_sel                        bypassable (aka, known/fixed latency)
//                 //      |  micro-code                                                |    uses_ldg                 |  is_br
//                 //      |     |           iq-type                        rs1 regtype |    |  uses_stq              |  |  is_pc2epc
//                 //      |     |              |       func unit                       |    |  |  is_amo             |  |  |  is_unique(clear pipeline for it)
//                 //      |     |              |        |       dst_type          |    |    |  |  |  is_fence        |  |  |  |  flush_on_commit
//                 //      |     |              |        |       |       rs1_type       |    |  |  |  |  is_fencei    |  |  |  |  |  csr_cmd
//                 //      |     |              |        |       |       |              |    |  |  |  |  |            |  |  |  |  |  |
//                 //      |     |              |        |       |       |    rs2_type  |    |  |  |  |  |            |  |  |  |  |  |
//                 //      |     |              |        |       |       |       |      |    |  |  |  |  |  mem_cmd   |  |  |  |  |  |
//     val table: Array[(BitPat, List[BitPat])] = Array( //      |       |       |      |    |  |  |  |  |    |       |  |  |  |  |  |
//         TLBSRCH -> List(Y, uopTLBSRCH),
//         TLBFILL -> List(Y, uopTLBFILL),
//         TLBRD   -> List(Y, uopTLBRD),
//         TLBWR   -> List(Y, uopTLBWR),
//         INVTLB  -> List(Y, uopINVTLB)
//     )
// }

 object CSRDecode extends DecodeTable {
                       //
                       // is val inst?                                                imm_sel                        bypassable (aka, known/fixed latency)
                       // |   micro-code                                                |   uses_ldg                 |  is_br
                       // |      |            iq-type                        rs1 regtype |   |  uses_stq             |  | is_pc2epc
                       // |      |               |       func unit                       |   |  |  is_amo            |  |  |  is_unique(clear pipeline for it)
                       // |      |               |        |       dst_type          |    |   |  |  |  is_fence       |  |  |  |  flush_on_commit
                       // |      |               |        |       |       rs1_type       |   |  |  |  |  is_fencei   |  |  |  |  |  csr_cmd
                       // |      |               |        |       |       |              |   |  |  |  |  |           |  |  |  |  |    |
                       // |      |               |        |       |       |    rs2_type  |   |  |  |  |  |           |  |  |  |  |    |
                       // |      |               |        |       |       |       |      |   |  |  |  |  |  mem_cmd  |  |  |  |  |    |
     val table:  Array[(BitPat, List[BitPat])] = Array(     //   |       |       |      |   |  |  |  |  |    |      |  |  |  |  |    |
         CSRRD    -> List(Y, uopCSRRD       , IQT_INT, FU_CSR, RT_FIX, RT_X  , RT_X  , immX, N, N, N, N, N,/* M_X,*/ N, N, N, Y, Y, CSR_R),
         CSRWR    -> List(Y, uopCSRWR       , IQT_INT, FU_CSR, RT_FIX, RT_FIX, RT_X  , immX, N, N, N, N, N,/* M_X,*/ N, N, N, Y, Y, CSR_W),
         CSRXCHG1 -> List(Y, uopCSRXCHG     , IQT_INT, FU_CSR, RT_FIX, RT_FIX, RT_FIX, immX, N, N, N, N, N,/* M_X,*/ N, N, N, Y, Y, CSR_M),
         CSRXCHG2 -> List(Y, uopCSRXCHG     , IQT_INT, FU_CSR, RT_FIX, RT_FIX, RT_FIX, immX, N, N, N, N, N,/* M_X,*/ N, N, N, Y, Y, CSR_M),
         CSRXCHG3 -> List(Y, uopCSRXCHG     , IQT_INT, FU_CSR, RT_FIX, RT_FIX, RT_FIX, immX, N, N, N, N, N,/* M_X,*/ N, N, N, Y, Y, CSR_M),
         CSRXCHG4 -> List(Y, uopCSRXCHG     , IQT_INT, FU_CSR, RT_FIX, RT_FIX, RT_FIX, immX, N, N, N, N, N,/* M_X,*/ N, N, N, Y, Y, CSR_M),
         CSRXCHG5 -> List(Y, uopCSRXCHG     , IQT_INT, FU_CSR, RT_FIX, RT_FIX, RT_FIX, immX, N, N, N, N, N,/* M_X,*/ N, N, N, Y, Y, CSR_M),
         CSRXCHG6 -> List(Y, uopCSRXCHG     , IQT_INT, FU_CSR, RT_FIX, RT_FIX, RT_FIX, immX, N, N, N, N, N,/* M_X,*/ N, N, N, Y, Y, CSR_M),
         CSRXCHG7 -> List(Y, uopCSRXCHG     , IQT_INT, FU_CSR, RT_FIX, RT_FIX, RT_FIX, immX, N, N, N, N, N,/* M_X,*/ N, N, N, Y, Y, CSR_M),
         CSRXCHG8 -> List(Y, uopCSRXCHG     , IQT_INT, FU_CSR, RT_FIX, RT_FIX, RT_FIX, immX, N, N, N, N, N,/* M_X,*/ N, N, N, Y, Y, CSR_M),
         CSRXCHG9 -> List(Y, uopCSRXCHG     , IQT_INT, FU_CSR, RT_FIX, RT_FIX, RT_FIX, immX, N, N, N, N, N,/* M_X,*/ N, N, N, Y, Y, CSR_M),
         CSRXCHG10-> List(Y, uopCSRXCHG     , IQT_INT, FU_CSR, RT_FIX, RT_FIX, RT_FIX, immX, N, N, N, N, N,/* M_X,*/ N, N, N, Y, Y, CSR_M),
         CSRXCHG11-> List(Y, uopCSRXCHG     , IQT_INT, FU_CSR, RT_FIX, RT_FIX, RT_FIX, immX, N, N, N, N, N,/* M_X,*/ N, N, N, Y, Y, CSR_M),
         CSRXCHG12-> List(Y, uopCSRXCHG     , IQT_INT, FU_CSR, RT_FIX, RT_FIX, RT_FIX, immX, N, N, N, N, N,/* M_X,*/ N, N, N, Y, Y, CSR_M),
         CSRXCHG13-> List(Y, uopCSRXCHG     , IQT_INT, FU_CSR, RT_FIX, RT_FIX, RT_FIX, immX, N, N, N, N, N,/* M_X,*/ N, N, N, Y, Y, CSR_M),
         CSRXCHG14-> List(Y, uopCSRXCHG     , IQT_INT, FU_CSR, RT_FIX, RT_FIX, RT_FIX, immX, N, N, N, N, N,/* M_X,*/ N, N, N, Y, Y, CSR_M),
         CSRXCHG15-> List(Y, uopCSRXCHG     , IQT_INT, FU_CSR, RT_FIX, RT_FIX, RT_FIX, immX, N, N, N, N, N,/* M_X,*/ N, N, N, Y, Y, CSR_M),

         ERTN    -> List(Y, uopERET        , IQT_INT, FU_CSR, RT_X  , RT_X  , RT_X  , immX, N, N, N, N, N,/* M_X,*/ N, N, N, Y, Y, CSR_R),//TODO 改成 CSR_I
         SYSCALL -> List(Y, uopERET        , IQT_INT, FU_CSR, RT_X  , RT_X  , RT_X  , immX, N, N, N, N, N,/* M_X,*/ N, N, Y, Y, Y, CSR_R),
         BREAK   -> List(Y, uopERET        , IQT_INT, FU_CSR, RT_X  , RT_X  , RT_X  , immX, N, N, N, N, N,/* M_X,*/ N, N, Y, Y, Y, CSR_R),
     )
//     val default_table : List[BitPat] = List(N, )

 }
 object WeirdDecode extends DecodeTable {
                     //                                                                                          wakeup_delay
                 //      is val inst?                                                imm_sel                      |   bypassable (aka, known/fixed latency)
                 //      |  micro-code                                                |    uses_ldg               |   |  is_br
                 //      |     |           iq-type                        rs1 regtype |    |  uses_stq            |   |  |  is_pc2epc
                 //      |     |              |       func unit                       |    |  |  is_amo           |   |  |  |  is_unique(clear pipeline for it)
                 //      |     |              |        |       dst_type          |    |    |  |  |  is_fence      |   |  |  |  |  flush_on_commit
                 //      |     |              |        |       |       rs1_type       |    |  |  |  |  is_fencei  |   |  |  |  |  |  csr_cmd
                 //      |     |              |        |       |       |              |    |  |  |  |  |          |   |  |  |  |  |  |
                 //      |     |              |        |       |       |    rs2_type  |    |  |  |  |  |          |   |  |  |  |  |  |
                 //      |     |              |        |       |       |       |      |    |  |  |  |  |  mem_cmd |   |  |  |  |  |  |
      val table: Array[(BitPat, List[BitPat])] = Array( //      |       |       |      |    |  |  |  |  |    |     |   |  |  |  |  |  |
//          IDLE    -> List(Y, uopIDLE),
          CACOP   -> List(Y, uopNOP       , IQT_MEM, FU_X  , RT_X  , RT_X  , RT_X  , immX  , N, N, N, N, Y, /*M_X  ,*/  N, N, N, Y, Y, CSR_N)
//          RDCNTIDW-> List(Y, uopRDCNTIDW  , IQT_INT, FU_CNT, RT_FIX, RT_X  , RT_X  , immX, N, N, N, N, N, 0.U, Y, N, N, N, N, CSR_N),
//          RDCNTVLW-> List(Y, uopRDCNTVLW  , IQT_INT, FU_CNT, RT_FIX, RT_X  , RT_X  , immX, N, N, N, N, N, 0.U, Y, N, N, N, N, CSR_N),
//          RDCNTVHW-> List(Y, uopRDCNTVHW  , IQT_INT, FU_CNT, RT_FIX, RT_X  , RT_X  , immX, N, N, N, N, N, 0.U, Y, N, N, N, N, CSR_N)
      )
}


//TODO 修改CSRFile

class CSRExcept extends Bundle{
    val valid   = Bool()
    val totalCode = UInt(causeCodeBits.W)

//    def csrdecode(instr: UInt, table: Iterable[(BitPat, List[BitPat])]): Unit = {
//        val decoder = DecodeLogic(instr, CSRDecode.decode_default, table) //返回一个List[BitPat] 若匹配不到，则返回默认值
//        val sigs = Seq(
//           valid, totalCode
//        )
//        sigs zip decoder map { case (s, d) => s := d } //将对应位相匹配
//        this
//    }
}
class DecodeUnitIO() extends CoreBundle {
    val enq = new Bundle { val uop = Input(new MicroOp()) }
    val deq = new Bundle { val uop = Output(new MicroOp()) }

    // from CSRFile
    // val status = Input(new freechips.rocketchip.rocket.MStatus())
     val interrupt = Input(Bool())
//     val interrupt_cause = Input(UInt(xLen.W))
}
//TODO 添加对CSR环境下异常指令的检测
class DecodeUnit extends CoreModule {
    val io = IO(new DecodeUnitIO)
//    io <> DontCare

    val uop = Wire(new MicroOp)
    uop := io.enq.uop

    var decode_table = XDecode.table
    decode_table ++= CSRDecode.table
    decode_table ++= WeirdDecode.table
    // val interrupt_table = ExceptionInstrDecode.table
    // if(usingCSR) decode_table ++= CSRDecode.table
    // if(usingTLB) decode_table ++= TLBDeocde.table
    // if(usingWired)decode_table ++= WeirdDecode.table
    
    val inst = uop.instr
    val cs = Wire(new CtrlSigs).decode(inst, decode_table)
//    val ins = Wire(new CSRExcept).csrdecode(inst,ExceptionInstrDecode.table)
    // TODO: 异常检测
    def checkExceptions(x: Seq[(Bool, UInt)]) =
         (x.map(_._1).reduce(_||_), PriorityMux(x))
    val cs_legal = cs.legal
    val id_illegal_insn = !cs_legal
    val xcpt_valid = WireInit(false.B)
    val xcpt_cause = WireInit(0.U(15.W))
    when(io.interrupt){    //TODO: isSFB是否应该删掉
        xcpt_cause := INT
        xcpt_valid := true.B
    } .elsewhen(uop.instr_misalign){
        xcpt_valid := true.B
        xcpt_cause := ADEF
    } .elsewhen(inst === SYSCALL || inst === BREAK){
        when(inst === SYSCALL) {
            xcpt_cause := SYS
            xcpt_valid := true.B
        } .otherwise{
            xcpt_cause := BRK
            xcpt_valid := true.B
        }
    } .elsewhen(id_illegal_insn){
            xcpt_cause := INE
            xcpt_valid := true.B
    }

    uop.vaddrWriteEnable := false.B
    when(xcpt_valid && (xcpt_cause === ADEF || xcpt_cause === ALE)){
        uop.vaddrWriteEnable := true.B
    }
    uop.exception := xcpt_valid
    uop.excCause  := xcpt_cause


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

    uop.isBr    := cs.is_br
    uop.isJal   := (uop.uopc === uopJAL)
    uop.isJalr  := (uop.uopc === uopJIRL)
    io.deq.uop  := uop
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
