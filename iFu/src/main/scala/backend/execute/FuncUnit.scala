package iFu.backend

import chisel3._
import chisel3.util._

object FUConst {
    val FUC_SZ = // TODO
    val FU_X = BitPat.dontCare(FUC_SZ)
    val FU_ALU = 1.U(FUC_SZ.W)
    val FU_JMP = 2.U(FUC_SZ.W)
    val FU_MEM = 4.U(FUC_SZ.W)
    val FU_MUL = 8.U(FUC_SZ.W)
    val FU_DIV = 16.U(FUC_SZ.W)
    val FU_CSR = 32.U(FUC_SZ.W)
    // val FN_CNT = 64.U(FUC_SZ.W)
    // val FN_TLB = 128.U(FUC_SZ.W) // ???
}

import FUConst._

case class SupportedFuncs() {
    val alu: Boolean = false,
    val jmp: Boolean = false,
    val mem: Boolean = false,
    val muldiv: Boolean = false,
    val csr: Boolean = false
    // val cnt: Boolean = false
    // val tlb: Boolean = false
}

class FuncUnitReq extends CoreBundle {
    val kill = Bool()
    val uop = new MicroOp()
    val rs1Data = UInt(xLen.W)
    val rs2Data = UInt(xLen.W)
    val predData = Bool()
}

class FuncUnitResp extends CoreBundle {
    val uop = new MicroOp()
    val predicated = Bool()
    val data = UInt(xLen.W)
    val addr = UInt(xLen.W)
    // val mxcpt = // TODO
    // val sfence = // TODO
}

class BrUpdateMasks extends CoreBundle {
    val resolveMask = UInt(maxBrCount.W)
    val mispredictMask = UInt(maxBrCount.W)
}

class BrResolutionInfo extends CoreBundle {
    val uop = new MicroOp()
    val valid = Bool()
    val mispredict = Bool()
    val taken = Bool()
    val cfiType = UInt(CFI_SZ.W)
    val pcSel = UInt(2.W)
    val jalrTarget = UInt(xLen.W)
    val targetOffset = SInt() // ???
}

class BrUpdateInfo extends CoreBundle  {
    val b1 = new BrUpdateMasks()
    val b2 = new BrResolutionInfo()
}

abstract class FuncUnit(
    val isPiplined: Boolean,
    val numStages: Int,
    val numBypassStages: Int,
    val isJmpUnit: Boolean,
    val isAluUnit: Boolean,
    val isMemAddrCalcUnit: Boolean,
) extends CoreModule {
    val io = IO(new Bundle {
        val req = Flipped(Decoupled(new FuncUnitReq()))
        val resp = Decoupled(new FuncUnitResp())
        val brUpdate = Input(new BrUpdateInfo())
        val bypass = Output(Vec(numBypassStage, new ExeUnitResp()))
        val brInfo = if (isAluUnit) Output(new BrResolutionInfo()) else null
        val getFtqPC = if (isJmpUnit) Flipped(new GetPCFromFtqIO()) else null
        val status = if (isMemAddrCalcUnit) Input(new MStatus()) else null

        val bp = if (isMemAddrCalcUnit) Input(Vec(nBreakpoints, new BP)) else null
        val mcontext = if (isMemAddrCalcUnit) Input(UInt(mcontextWidth.W)) else null
        val scontext = if (isMemAddrCalcUnit) Input(UInt(scontextWidth.W)) else null
    })
}

abstract class PipelinedFuncUnit(
    numStages: Int,
    numBypassStages: Int,
    earliestBypassStage: Int,
    isJmpUnit: Boolean = false,
    isAluUnit: Boolean = false,
    isMemAddrCalcUnit: Boolean = false,
) extends FuncUnit (
    isPiplined = true,
    numStages = numStages,
    numBypassStages = numBypassStages,
    isJmpUnit = isJmpUnit,
    isAluUnit = isAluUnit,
    isMemAddrCalcUnit = isMemAddrCalcUnit,
) {
    io.req.ready := true.B

    if (numStages > 0) {
        val rValids = RegInit(VecInit(Seq.fill(numStages){ false.B }))
        val rUops = Reg(Vec(numStages, new MicroOp()))

        rValids(0) := io.req.valid && !IsKilledByBranch(io.brUpdate, io.req.bits.uop) && !io.req.bits.kill
        rUops(0) := io.req.bits.uop
        rUops(0).brMask := GetNewBrMask(io.brUpdate, io.req.bits.uop)
        for (i <- 1 until numStages) {
            rValids(i) := rValids(i - 1) && !IsKilledByBranch(io.brUpdate, rUops(i-1)) && !io.req.bits.kill
            rUops(i) := rUops(i - 1)
            rUops(i).brMask := GetNewBrMask(io.brUpdate, rUops(i - 1))

            // should bypass late a cycle after the alu calculated the result
            // if (numBypassStages > 0) {
            //     io.bypass(i - 1).bits.uop := rUops(i - 1)
            // }
        }

        io.resp.valid := rValids(numStages - 1) && !IsKilledByBranch(io.brUpdate, rUops(numStages - 1))
        io.resp.bits.predicated := false.B  // default
        io.resp.bits.uop := rUops(numStages - 1)
        io.resp.bits.uop.brMask := GetNewBrMask(io.brUpdate, rUops(numStages - 1))

        if (numBypassStages >0 && earliestBypassStage == 0) {
            io.bypass(0).bits.uop := io.req.bits.uop
            for (i <- 1 until numBypassStages) {
                io.bypass(i).bits.uop := rUops(i - 1)
            }
        }
    } else {
        require (numStages == 0)

        io.resp.valid := io.req.valid && !IsKilledByBranch(io.brUpdate, io.req.bits.uop)
        io.resp.bits.predicated := false.B  // default
        io.resp.bits.uop := io.req.bits.uop
        io.resp.bits.uop.brMask := GetNewBrMask(io.brUpdate, io.req.bits.uop)
    }
}

// 问题：
//    1. 如果ALU有多个周期，那么第一周期计算结果谁来存
class ALUUnit(
    isJmpUnit: Boolean = false,
    numStages: Int = 1,
) extends PipelinedFuncUnit (
    numStages = numStages,
    numBypassStages = numStages,
    earliestBypassStage = 0,
    isAluUnit = true,
    isJmpUnit = isJmpUnit
) {
    val uop = io.req.bits.uop

    val imm = ImmGen(uop.immPacked, uop.ctrl.imms_el)

    val op1Data: UInt = null
    if (isJmpUnit) {
        val block_pc = AlignPCToBoundary(io.getFtqPC.pc, icBlockBytes)
        val uop_pc  = (block_pc | uop.pcLowBits)

        op1Data = Mux(uop.ctrl.op1_sel === OP1_RS1, io.req.bits.rs1Data,
                  Mux(uop.ctrl.op1_sel === OP1_PC,  uop_pc, 0.U))
    }  else {
        op1Data = Mux(uop.ctrl.op1_sel === OP1_RS1, io.req.bits.rs1Data, 0.U)
    }
    val op2Data = Mux(uop.ctrl.op2_sel === OP2_IMM, imm,
                  Mux(uop.ctrl.op2_sel === OP2_RS2, io.req.bits.rs2Data, 
                  Mux(uop.ctrl.op2_sel === OP2_NEXT, 4.U)))

    val alu = Module(new Alu())
    alu.io.fn := uop.ctrl.op_fcn
    alu.io.op1 := op1Data
    alu.io.op2 := op2Data

    val killed = WireInit(false.B)
    when (io.req.bits.kill || IsKilledByBranch(io.brUpdate, uop)) {
        killed := true.B
    }

    val rs1 = io.req.bits.rs1Data
    val rs2 = io.req.bits.rs2Data
    val brEq = rs1 === rs2
    val brLtu = rs1.asUInt < rs2.asUInt
    val brLt = (~(rs1(xLen-1) ^ rs2(xLen-1)) & br_ltu |
                rs1(xLen-1) & ~rs2(xLen-1)).asBool

    val pcSel = MuxLookup(uop.ctrl.br_type, PC_PLUS4,
        Seq(
            BR_N -> PC_PLUS4,
            BR_NE -> Mux(!brEq, PC_BRJMP, PC_PLUS4),
            BR_EQ -> Mux(brEq, PC_BRJMP, PC_PLUS4),
            BR_GE -> Mux(!brLt, PC_BRJMP, PC_PLUS4),
            BR_GEU -> Mux(!brLtu, PC_BRJMP, PC_PLUS4),
            BR_LT -> Mux(brLt, PC_BRJMP, PC_PLUS4),
            BR_LTU -> Mux(brLtu, PC_BRJMP, PC_PLUS4),
            BR_J -> PC_BRJMP,
            BR_JR -> PC_JALR
        )
    )

    val isTaken = io.req.valid && !killed &&
                 (uop.isBr || uop.isJalr || uop.isJal) && (pcSel =/= PC_PLUS4)
    
}