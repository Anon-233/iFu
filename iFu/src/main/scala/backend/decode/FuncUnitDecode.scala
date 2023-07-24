package backend.decode

import backend.decode.FunUDConsts._
import backend.decode.XDecode._
import backend.decode.common.{immS12, immS14, immS16, immS20, immS26, immU12, immU20, immU5, immX}
import chisel3._
import chisel3.util._
import iFu.backend.{AluFuncCode, DecodeLogic, DivFuncCode, MultFuncCode}
import iFu.common.{CoreBundle, CoreModule, MicroOp, MicroOpCode}
/**
 * Control signal bundle for register renaming
 */
//TODO 增加CSR相关指令，IDLE，RDCNT等

object FunUDConsts
{
    // Branch Type
    val BR_N = 0.U(4.W) // Next 存疑
    val BR_NE = 1.U(4.W) // Branch on NotEqual
    val BR_EQ = 2.U(4.W) // Branch on Equal
    val BR_GE = 3.U(4.W) // Branch on Greater/Equal
    val BR_GEU = 4.U(4.W) // Branch on Greater/Equal Unsigned
    val BR_LT = 5.U(4.W) // Branch on Less Than
    val BR_LTU = 6.U(4.W) // Branch on Less Than Unsigned
    val BR_J = 7.U(4.W) // Jump
    val BR_JR = 8.U(4.W) // Jump Register

    // RS1 Operand Select Signal
    val OP1_RS1 = 0.U(2.W) // Register Source #1
    val OP1_ZERO = 1.U(2.W)
    val OP1_PC = 2.U(2.W)
    val OP1_X = BitPat("b??")

    // RS2 Operand Select Signal
    val OP2_RS2 = 0.U(3.W) // Register Source #2
    val OP2_IMM = 1.U(3.W) // immediate
    val OP2_ZERO = 2.U(3.W) // constant 0
    val OP2_NEXT = 3.U(3.W) // constant 2/4 (for PC+2/4)
    val OP2_IMMC = 4.U(3.W) // for CSR imm found in RS1
    val OP2_X = BitPat("b???")

    // Register File Write Enable Signal
    val REN_0 = false.B
    val REN_1 = true.B

    // Is 32b Word or 64b Doubldword?
    val SZ_DW = 1
    val DW_X = true.B // Bool(xLen==64)
    val DW_32 = false.B
    val DW_64 = true.B
    val DW_XPR = true.B // Bool(xLen==64)

    // Memory Enable Signal
    val MEN_0 = false.B
    val MEN_1 = true.B
    val MEN_X = false.B

    // Immediate Extend Select
    val IS_I = 0.U(3.W) // I-Type  (LD,ALU)
    val IS_S = 1.U(3.W) // S-Type  (ST)
    val IS_B = 2.U(3.W) // SB-Type (BR)
    val IS_U = 3.U(3.W) // U-Type  (LUI/AUIPC)
    val IS_J = 4.U(3.W) // UJ-Type (J/JAL)
    val IS_X = BitPat("b???")
}
class RRdCtrlSigs extends CoreBundle
{
    val br_type          = UInt(BR_N.getWidth.W)
    val use_alupipe      = Bool()
    val use_muldivpipe   = Bool()
    val use_mempipe      = Bool()
    val op_fcn      = Bits((new AluFuncCode).SZ_ALU_FN.W)
    val fcn_dw      = Bool()
    val op1_sel     = UInt(OP1_X.getWidth.W)
    val op2_sel     = UInt(OP2_X.getWidth.W)
    val imm_sel     = UInt(IS_X.getWidth.W)
    val rf_wen      = Bool()
    val csr_cmd     = Bits(CSR.SZ.W)

    def decode(uopc: UInt, table: Iterable[(BitPat, List[BitPat])]) = {
        val decoder = DecodeLogic(uopc, AluRRdDecode.default, table)
        val sigs = Seq(br_type, use_alupipe, use_muldivpipe, use_mempipe, op_fcn,
            fcn_dw, op1_sel, op2_sel, imm_sel, rf_wen, csr_cmd)
        sigs zip decoder map {case(s,d) => s := d}
        this
    }
}

/**
 * Default register read constants
 */
abstract trait RRdDecodeConstants
{
    val aluFn = new AluFuncCode
    val mulFn = new MultFuncCode
    val divFn = new DivFuncCode
    val default: List[BitPat] =
        List[BitPat](BR_N , Y, N, N, aluFn.FN_ADD , DW_X  , OP1_X   , OP2_X   , IS_X, REN_0, CSR.N)
    val table: Array[(BitPat, List[BitPat])]
}

/**
 * ALU register read constants
 */
object AluRRdDecode extends RRdDecodeConstants with MicroOpCode
{
    val table: Array[(BitPat, List[BitPat])] =
        Array[(BitPat, List[BitPat])](
                                      // br type
                                      // |      use alu pipe               op1 sel   op2 sel
                                      // |      |  use muldiv pipe         |         |         immsel       csr_cmd
                                      // |      |  |  use mem pipe         |         |         |     rf wen |
                                      // |      |  |  |     alu fcn        |         |         |     |      |
                                      // |      |  |  |     |              |         |         |     |      |
            BitPat(uopSRLIW)    -> List(BR_N  , Y, N, N, aluFn.FN_SRL  , OP1_RS1, OP2_IMM , immU5 , REN_1, CSR.N),
            BitPat(uopSRAIW)    -> List(BR_N  , Y, N, N, aluFn.FN_SRA  , OP1_RS1, OP2_IMM , immU5 , REN_1, CSR.N),
            BitPat(uopSRLW)     -> List(BR_N  , Y, N, N, aluFn.FN_SRL  , OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
            BitPat(uopSRAW)     -> List(BR_N  , Y, N, N, aluFn.FN_SRA  , OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
            BitPat(uopSLLIW)    -> List(BR_N  , Y, N, N, aluFn.FN_SL   , OP1_RS1, OP2_IMM , immU5 , REN_1, CSR.N),
            BitPat(uopORN)      -> List(BR_N  , Y, N, N, aluFn.FN_ORN  , OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
            BitPat(uopANDN)     -> List(BR_N  , Y, N, N, aluFn.FN_ANDN , OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
            BitPat(uopLU12IW)   -> List(BR_N  , Y, N, N, aluFn.FN_ADD  , OP1_RS1, OP2_IMM , immU20, REN_1, CSR.N),
            BitPat(uopOR)       -> List(BR_N  , Y, N, N, aluFn.FN_OR   , OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
            BitPat(uopNOR)      -> List(BR_N  , Y, N, N, aluFn.FN_NOR  , OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
            BitPat(uopADDIW)    -> List(BR_N  , Y, N, N, aluFn.FN_ADD  , OP1_RS1, OP2_IMM , immS12, REN_1, CSR.N),
            BitPat(uopANDI)     -> List(BR_N  , Y, N, N, aluFn.FN_AND  , OP1_RS1, OP2_IMM , immU12, REN_1, CSR.N),
            BitPat(uopORI)      -> List(BR_N  , Y, N, N, aluFn.FN_OR   , OP1_RS1, OP2_IMM , immU12, REN_1, CSR.N),
            BitPat(uopXORI)     -> List(BR_N  , Y, N, N, aluFn.FN_XOR  , OP1_RS1, OP2_IMM , immU12, REN_1, CSR.N),
            BitPat(uopSLTI)     -> List(BR_N  , Y, N, N, aluFn.FN_SLT  , OP1_RS1, OP2_IMM , immS12, REN_1, CSR.N),
            BitPat(uopSLTUI)    -> List(BR_N  , Y, N, N, aluFn.FN_SLTU , OP1_RS1, OP2_IMM , immS12, REN_1, CSR.N),
            BitPat(uopSLLW)     -> List(BR_N  , Y, N, N, aluFn.FN_SL   , OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
            BitPat(uopADD)      -> List(BR_N  , Y, N, N, aluFn.FN_ADD  , OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
            BitPat(uopSUB)      -> List(BR_N  , Y, N, N, aluFn.FN_SUB  , OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
            BitPat(uopSLT)      -> List(BR_N  , Y, N, N, aluFn.FN_SLT  , OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
            BitPat(uopSLTU)     -> List(BR_N  , Y, N, N, aluFn.FN_SLTU , OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
            BitPat(uopAND)      -> List(BR_N  , Y, N, N, aluFn.FN_AND  , OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
            BitPat(uopXOR)      -> List(BR_N  , Y, N, N, aluFn.FN_XOR  , OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),

            BitPat(uopBEQ)      -> List(BR_EQ , Y, N, N, aluFn.FN_SUB  , OP1_X  , OP2_X   , immS16, REN_0, CSR.N),
            BitPat(uopBNE)      -> List(BR_NE , Y, N, N, aluFn.FN_SUB  , OP1_X  , OP2_X   , immS16, REN_0, CSR.N),
            BitPat(uopBGE)      -> List(BR_GE , Y, N, N, aluFn.FN_SLT  , OP1_X  , OP2_X   , immS16, REN_0, CSR.N),
            BitPat(uopBGEU)     -> List(BR_GEU, Y, N, N, aluFn.FN_SLTU , OP1_X  , OP2_X   , immS16, REN_0, CSR.N),
            BitPat(uopBLT)      -> List(BR_LT , Y, N, N, aluFn.FN_SLT  , OP1_X  , OP2_X   , immS16, REN_0, CSR.N),
            BitPat(uopBLTU)     -> List(BR_LTU, Y, N, N, aluFn.FN_SLTU , OP1_X  , OP2_X   , immS16, REN_0, CSR.N))

}
object JmpRRdDecode extends RRdDecodeConstants
{
    val table: Array[(BitPat, List[BitPat])] =
        Array[(BitPat, List[BitPat])](
            // br type
            // |      use alu pipe                    op1 sel   op2 sel
            // |      |  use muldiv pipe              |         |         immsel       csr_cmd
            // |      |  |  use mem pipe              |         |         |     rf wen |
            // |      |  |  |  alu fcn        wd/word?|         |         |     |      |
            // |      |  |  |  |              |       |         |         |     |      |
            BitPat(uopJIRL)     -> List(BR_JR , Y, N, N, aluFn.FN_ADD  , OP1_PC , OP2_NEXT, immS16, REN_1, CSR.N),
            BitPat(uopJAL)      -> List(BR_J  , Y, N, N, aluFn.FN_ADD  , OP1_PC , OP2_NEXT, immS26, REN_1, CSR.N),
            BitPat(uopPCADDU12I)-> List(BR_N  , Y, N, N, aluFn.FN_ADD  , OP1_RS1, OP2_IMM , immU20, REN_1, CSR.N),
            BitPat(uopPCADDI)   -> List(BR_N  , Y, N, N, aluFn.FN_ADD  , OP1_RS1, OP2_IMM , immS20, REN_1, CSR.N))
}

/**
 * Multiply divider register read constants
 */
object MulDivRRdDecode extends RRdDecodeConstants
{
    val table: Array[(BitPat, List[BitPat])] =
        Array[(BitPat, List[BitPat])](
            // br type
            // |      use alu pipe                    op1 sel   op2 sel
            // |      |  use muldiv pipe              |         |         immsel       csr_cmd
            // |      |  |  use mem pipe              |         |         |     rf wen |
            // |      |  |  |  alu fcn        wd/word?|         |         |     |      |
            // |      |  |  |  |              |       |         |         |     |      |
            BitPat(uopMODWU)    -> List(BR_N  , N, Y, N, divFn.FN_REMU , OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
            BitPat(uopDIVWU)    -> List(BR_N  , N, Y, N,  divFn.FN_DIVU, OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
            BitPat(uopDIVW)     -> List(BR_N  , N, Y, N, divFn.FN_DIV  , OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
            BitPat(uopMODW)     -> List(BR_N  , N, Y, N, divFn.FN_REM  , OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
            BitPat(uopMULHW)    -> List(BR_N  , N, Y, N, mulFn.FN_MULH , OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
            BitPat(uopMULHWU)   -> List(BR_N  , N, Y, N, mulFn.FN_MULHU, OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
            BitPat(uopMULW)     -> List(BR_N  , N, Y, N, mulFn.FN_MUL  , OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
}
object MemRRdDecode extends RRdDecodeConstants
{
    val table: Array[(BitPat, List[BitPat])] =
        Array[(BitPat, List[BitPat])](
            // br type
            // |      use alu pipe                    op1 sel   op2 sel
            // |      |  use muldiv pipe              |         |         immsel       csr_cmd
            // |      |  |  use mem pipe              |         |         |     rf wen |
            // |      |  |  |  alu fcn        wd/word?|         |         |     |      |
            // |      |  |  |  |              |       |         |         |     |      |
            BitPat(uopLD)       -> List(BR_N  , N, N, Y, aluFn.FN_ADD  , OP1_RS1, OP2_IMM , immS12, REN_0, CSR.N),
            BitPat(uopSTA)      -> List(BR_N  , N, N, Y, aluFn.FN_ADD  , OP1_RS1, OP2_IMM , immS12, REN_0, CSR.N),
            BitPat(uopSTD)      -> List(BR_N  , N, N, Y, aluFn.FN_X    , OP1_RS1, OP2_RS2 , immS12, REN_0, CSR.N),
            BitPat(uopLLW)      -> List(BR_N  , N, N, Y, aluFn.FN_ADD  , OP1_RS1, OP2_IMM , immS14, REN_0, CSR.N),
            BitPat(uopAMO_AG)   -> List(BR_N  , N, N, Y, aluFn.FN_ADD  , OP1_RS1, OP2_ZERO, immS14, REN_0, CSR.N),

}



/**
 * CSR register read constants
 */
object CsrRRdDecode extends RRdDecodeConstants
{
    val table: Array[(BitPat, List[BitPat])] =
        Array[(BitPat, List[BitPat])](
            // br type
            // |      use alu pipe                    op1 sel   op2 sel
            // |      |  use muldiv pipe              |         |         immsel       csr_cmd
            // |      |  |  use mem pipe              |         |         |     rf wen |
            // |      |  |  |  alu fcn        wd/word?|         |         |     |      |
            // |      |  |  |  |              |       |         |         |     |      |
            BitPat(uopCSRWR) -> List(BR_N , Y, N, N, aluFn.FN_ADD , DW_XPR, OP1_RS1 , OP2_ZERO, IS_I, REN_1, CSR.W),
            BitPat(uopCSRRD) -> List(BR_N , Y, N, N, aluFn.FN_ADD , DW_XPR, OP1_RS1 , OP2_ZERO, IS_I, REN_1, CSR.S),
            BitPat(uopCSRXCHG) -> List(BR_N , Y, N, N, aluFn.FN_ADD , DW_XPR, OP1_RS1 , OP2_ZERO, IS_I, REN_1, CSR.C),

            BitPat(uopWFI)   -> List(BR_N , Y, N, N, aluFn.FN_ADD , DW_XPR, OP1_ZERO, OP2_IMMC, IS_I, REN_0, CSR.I),
            BitPat(uopERET)  -> List(BR_N , Y, N, N, aluFn.FN_ADD , DW_XPR, OP1_ZERO, OP2_IMMC, IS_I, REN_0, CSR.I))
}

/**
 * Register read decoder
 *
 * @param supportedUnits indicate what functional units are being used
 */
//TODO 修改RegisterReadDecode
class RegisterReadDecode(supportedUnits: SupportedFuncUnits) extends CoreModule
        with MemoryOpConstants
{
    val io = IO(new CoreBundle {
        val iss_valid = Input(Bool())
        val iss_uop   = Input(new MicroOp())

        val rrd_valid = Output(Bool())
        val rrd_uop   = Output(new MicroOp())
    })

    // Issued Instruction
    val rrd_valid = io.iss_valid
    io.rrd_uop   := io.iss_uop

    var dec_table = AluRRdDecode.table
    if (supportedUnits.jmp) dec_table ++= JmpRRdDecode.table
    if (supportedUnits.mem) dec_table ++= MemRRdDecode.table
    if (supportedUnits.muld) dec_table ++= MulDivRRdDecode.table
    if (supportedUnits.csr) dec_table ++= CsrRRdDecode.table
    val rrd_cs = Wire(new RRdCtrlSigs()).decode(io.rrd_uop.uopc, dec_table)

    // rrd_use_alupipe is unused
    io.rrd_uop.ctrl.br_type := rrd_cs.br_type
    io.rrd_uop.ctrl.op1_sel := rrd_cs.op1_sel
    io.rrd_uop.ctrl.op2_sel := rrd_cs.op2_sel
    io.rrd_uop.ctrl.imm_sel := rrd_cs.imm_sel
    io.rrd_uop.ctrl.op_fcn  := rrd_cs.op_fcn.asUInt
    io.rrd_uop.ctrl.fcn_dw  := rrd_cs.fcn_dw.asBool
    io.rrd_uop.ctrl.is_load := io.rrd_uop.uopc === uopLD
    io.rrd_uop.ctrl.is_sta  := io.rrd_uop.uopc === uopSTA || io.rrd_uop.uopc === uopAMO_AG
    io.rrd_uop.ctrl.is_std  := io.rrd_uop.uopc === uopSTD || (io.rrd_uop.ctrl.is_sta && io.rrd_uop.lrs2_rtype === RT_FIX)

    when (io.rrd_uop.uopc === uopAMO_AG || (io.rrd_uop.uopc === uopLD && io.rrd_uop.mem_cmd === M_XLL)) {
        io.rrd_uop.immPacked := 0.U
    }

    val raddr1 = io.rrd_uop.prs1 // although renamed, it'll stay 0 if lrs1 = 0
    val csr_ren = (rrd_cs.csr_cmd === CSR.S || rrd_cs.csr_cmd === CSR.C) && raddr1 === 0.U
    io.rrd_uop.ctrl.csr_cmd := Mux(csr_ren, CSR.R, rrd_cs.csr_cmd)

    //-------------------------------------------------------------
    // set outputs

    io.rrd_valid := rrd_valid
}