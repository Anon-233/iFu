package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.util.ImplicitCast.uintToBitPat

//TODO 增加CSR相关指令，IDLE，RDCNT等

class RRdCtrlSigs extends CoreBundle {
    val br_type        = UInt(BR_N.getWidth.W)
    val use_alupipe    = Bool()
    val use_muldivpipe = Bool()
    val use_mempipe    = Bool()
    val op_fcn         = Bits((new AluFuncCode).SZ_ALU_FN.W)
    val fcn_dw         = Bool()
    val op1_sel        = UInt(OP1_X.getWidth.W)
    val op2_sel        = UInt(OP2_X.getWidth.W)
    val imm_sel        = UInt(immX.getWidth.W)
    val rf_wen         = Bool()
    val csr_cmd        = Bits(CSR.SZ.W)

    def decode(uopc: UInt, table: Iterable[(BitPat, List[BitPat])]) = {
        val decoder = DecodeLogic(uopc, AluRRdDecode.default, table)
        val sigs = Seq(
            br_type, use_alupipe, use_muldivpipe, use_mempipe, op_fcn,
            fcn_dw, op1_sel, op2_sel, imm_sel, rf_wen, csr_cmd
        )
        sigs zip decoder map {case(s,d) => s := d}
        this
    }
}

abstract trait RRdDecodeConstants {
    val aluFn = new AluFuncCode
    val mulFn = new MultFuncCode
    val divFn = new DivFuncCode
    val default: List[BitPat] =
        List[BitPat](BR_N , Y, N, N, aluFn.FN_ADD , OP1_X   , OP2_X   , immX, REN_0, CSR.N)
    val table: Array[(BitPat, List[BitPat])]
}

object AluRRdDecode extends RRdDecodeConstants {
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
            BitPat(uopBLTU)     -> List(BR_LTU, Y, N, N, aluFn.FN_SLTU , OP1_X  , OP2_X   , immS16, REN_0, CSR.N)
        )
}

object JmpRRdDecode extends RRdDecodeConstants {
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
            BitPat(uopPCADDI)   -> List(BR_N  , Y, N, N, aluFn.FN_ADD  , OP1_RS1, OP2_IMM , immS20, REN_1, CSR.N)
        )
}

object MulDivRRdDecode extends RRdDecodeConstants {
    val table: Array[(BitPat, List[BitPat])] =
        Array[(BitPat, List[BitPat])](
            // br type
            // |      use alu pipe                    op1 sel   op2 sel
            // |      |  use muldiv pipe              |         |         immsel       csr_cmd
            // |      |  |  use mem pipe              |         |         |     rf wen |
            // |      |  |  |  alu fcn        wd/word?|         |         |     |      |
            // |      |  |  |  |              |       |         |         |     |      |
            BitPat(uopMODWU)    -> List(BR_N  , N, Y, N, divFn.FN_REMU , OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
            BitPat(uopDIVWU)    -> List(BR_N  , N, Y, N, divFn.FN_DIVU , OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
            BitPat(uopDIVW)     -> List(BR_N  , N, Y, N, divFn.FN_DIV  , OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
            BitPat(uopMODW)     -> List(BR_N  , N, Y, N, divFn.FN_REM  , OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
            BitPat(uopMULHW)    -> List(BR_N  , N, Y, N, mulFn.FN_MULH , OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
            BitPat(uopMULHWU)   -> List(BR_N  , N, Y, N, mulFn.FN_MULHU, OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N),
            BitPat(uopMULW)     -> List(BR_N  , N, Y, N, mulFn.FN_MUL  , OP1_RS1, OP2_RS2 , immX  , REN_1, CSR.N)
        )
}

object MemRRdDecode extends RRdDecodeConstants {
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
            BitPat(uopAMO_AG)   -> List(BR_N  , N, N, Y, aluFn.FN_ADD  , OP1_RS1, OP2_ZERO, immS14, REN_0, CSR.N)
        )
}

// object CsrRRdDecode extends RRdDecodeConstants {
//     val table: Array[(BitPat, List[BitPat])] =
//         Array[(BitPat, List[BitPat])](
//             // br type
//             // |      use alu pipe                    op1 sel   op2 sel
//             // |      |  use muldiv pipe              |         |         immsel       csr_cmd
//             // |      |  |  use mem pipe              |         |         |     rf wen |
//             // |      |  |  |  alu fcn        wd/word?|         |         |     |      |
//             // |      |  |  |  |              |       |         |         |     |      |
//             BitPat(uopCSRWR) -> List(BR_N , Y, N, N, aluFn.FN_ADD , DW_XPR, OP1_RS1 , OP2_ZERO, IS_I, REN_1, CSR.W),
//             BitPat(uopCSRRD) -> List(BR_N , Y, N, N, aluFn.FN_ADD , DW_XPR, OP1_RS1 , OP2_ZERO, IS_I, REN_1, CSR.S),
//             BitPat(uopCSRXCHG) -> List(BR_N , Y, N, N, aluFn.FN_ADD , DW_XPR, OP1_RS1 , OP2_ZERO, IS_I, REN_1, CSR.C),

//             BitPat(uopWFI)   -> List(BR_N , Y, N, N, aluFn.FN_ADD , DW_XPR, OP1_ZERO, OP2_IMMC, IS_I, REN_0, CSR.I),
//             BitPat(uopERET)  -> List(BR_N , Y, N, N, aluFn.FN_ADD , DW_XPR, OP1_ZERO, OP2_IMMC, IS_I, REN_0, CSR.I)
//         )
// }

class RegisterReadDecode(supportedUnits: SupportedFuncs) extends CoreModule {
    val io = IO(new CoreBundle {
        val iss_valid = Input(Bool())
        val iss_uop   = Input(new MicroOp)

        val rrd_valid = Output(Bool)
        val rrd_uop   = Output(new MicroOp)
    })

    // Issued Instruction
    io.rrd_uop   := io.iss_uop

    var dec_table = AluRRdDecode.table
    if (supportedUnits.jmp)    dec_table ++= JmpRRdDecode.table
    if (supportedUnits.mem)    dec_table ++= MemRRdDecode.table
    if (supportedUnits.muldiv) dec_table ++= MulDivRRdDecode.table
    // if (supportedUnits.csr)    dec_table ++= CsrRRdDecode.table
    val rrd_cs = Wire(new RRdCtrlSigs).decode(io.rrd_uop.uopc, dec_table)

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

    when (io.rrd_uop.uopc === uopAMO_AG /*|| (io.rrd_uop.uopc === uopLD && io.rrd_uop.mem_cmd === M_XLL)*/) {
        io.rrd_uop.immPacked := 0.U
    }

    val raddr1 = io.rrd_uop.prs1 // although renamed, it'll stay 0 if lrs1 = 0
    val csr_ren = (rrd_cs.csr_cmd === CSR.S || rrd_cs.csr_cmd === CSR.C) && raddr1 === 0.U
//    io.rrd_uop.ctrl.csr_cmd := Mux(csr_ren, CSR.R, rrd_cs.csr_cmd)

    io.rrd_valid := io.iss_valid
}