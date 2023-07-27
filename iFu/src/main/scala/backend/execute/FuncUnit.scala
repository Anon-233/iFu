package iFu.backend

import chisel3._
import chisel3.util._
import iFu.common.{CoreBundle, MicroOp}

object FUConst {
    val FUC_SZ = 8// TODO
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

case class SupportedFuncs(
    val alu: Boolean = false,
    val jmp: Boolean = false,
    val mem: Boolean = false,
    val muldiv: Boolean = false,
    val csr: Boolean = false
    // val cnt: Boolean = false
    // val tlb: Boolean = false
)

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
    val isBr = io.req.valid && !killed && uop.isBr && !uop.isSFB
    val isJalr = io.req.valid && !killed && uop.isJalr

    when (isBr || isJalr) {
        if (!isJmpUnit) {
            assert(pcSel =/= PC_PLUS4)
        }
        when (pcSel === PC_PLUS4) {
            mispredict := uop.taken
        }
        when (pcSel === PC_BRJMP) {
            mispredict := !uop.taken
        }
    }

    val brInfo = Wire(new BrResolutionInfo())

    brInfo.valid := isBr || isJalr
    brInfo.mispredict := mispredict
    brInfo.uop := uop
    brInfo.cfiType := Mux(isJalr, CFI_JALR, Mux(isBr, CFI_BR, CFI_X))
    brInfo.taken := isTaken
    brInfo.pcSel := pcSel
    brInfo.jalrTarget := DontCare

    val targetOffset = imm
    if (isJmpUnit) {
        val jalrTargetBase = io.req.bits.rs1Data.asSInt
        val jalrTarget = (jalrTargetBase + targetOffset).asUInt
        brinfo.jalrTarget := jalrTarget

        val cfiIdx = ((uop.pc_lob ^ Mux(io.getFtqPC.entry.start_bank === 1.U, 1.U << log2Ceil(bankBytes), 0.U)))(log2Ceil(fetchWidth),1)

        when (pc_sel === PC_JALR) {
        mispredict := !io.getFtqPC.next_val ||
                        (io.getFtqPC.next_pc =/= jalrTarget) ||
                        !io.getFtqPC.entry.cfiIdx.valid ||
                        (io.getFtqPC.entry.cfiIdx.bits =/= cfiIdx)
        }
    }
    brinfo.target_offset := target_offset
    io.brInfo := brInfo

    val rValids = RegInit(VecInit(Seq.fill(numStages){ false.B }))
    val rData = Reg(Vec(numStages, UInt(xLen.W)))
    val rPred = Reg(Vec(numStages, Bool()))
    val aluOut = Mux(io.req.bits.uop.is_sfb_shadow && io.req.bits.predData,
        Mux(io.req.bits.uop.ldst_is_rs1, io.req.bits.rs1Data, io.req.bits.rs2Data),
        alu.io.out)
    rValids(0) := io.req.valid
    rData(0) := Mux(io.req.bits.uop.is_sfb_br, pcSel === PC_BRJMP, aluOut)
    rPred(0) := io.req.bits.uop.is_sfb_shadow && io.req.bits.predData
    for (i <- 1 until numStages) {
        rValids(i) := rValids(i - 1)
        rData(i) := rData(i - 1)
        rPred(i) := rPred(i - 1)
    }

    io.resp.bits.data := rData(numStages - 1)
    io.resp.bits.predicated := rPred(numStages - 1)

    require (numStages >= 1)
    require (numBypassStages >= 1)
    io.bypass(0).valid := io.req.valid
    io.bypass(0).bits.data := Mux(io.req.bits.uop.is_sfb_br, pcSel === PC_BRJMP, aluOut)
    for (i <- 1 until numStages) {
        io.bypass(i).valid := rValids(i - 1)
        io.bypass(i).bits.data := rData(i - 1)
    }
}

// 乘法还可以bypass???
class PipelinedMulUnit(numStages: Int = 3) extends PipelinedFuncUnit (
    numStages = numStages,
    numBypassStages = 0,
    earliestBypassStage = 0
) {
    val imult = Module(new MultStar())

    imult.io.req.valid := io.req.valid
    imult.io.req.bits.fn := io.req.bits.uop.ctrl.op_fcn
    imult.io.req.bits.op1 := io.req.bits.rs1Data
    imult.io.req.bits.op2 := io.req.bits.rs2Data

    io.resp.bits.data := imult.io.resp.bits.data
}

class MemAddrCalcUnit extends PipelinedFuncUnit(
    numStages = 0,
    numBypassStages = 0,
    earliestBypassStage = 0,
    isMemAddrCalcUnit = true
) {
    // perform address calculation
    val imm = ImmGen(uop.immPacked, uop.ctrl.imms_el)
    val addr = (io.req.bits.rs1Data.asSInt + imm).asUInt

    val store_data = io.req.bits.rs2Data

    io.resp.bits.addr := addr
    io.resp.bits.data := store_data

    // Handle misaligned exceptions
    val size = io.req.bits.uop.mem_size
    val misaligned =
        (size === 1.U && (addr(0) =/= 0.U)) ||
        (size === 2.U && (addr(1,0) =/= 0.U)) ||
        (size === 3.U && (addr(2,0) =/= 0.U))

    // val bkptu = Module(new BreakpointUnit(nBreakpoints))
    // bkptu.io.status   := io.status
    // bkptu.io.bp       := io.bp
    // bkptu.io.pc       := DontCare
    // bkptu.io.ea       := addr
    // bkptu.io.mcontext := io.mcontext
    // bkptu.io.scontext := io.scontext

    val ma_ld  = io.req.valid && io.req.bits.uop.uopc === uopLD && misaligned
    val ma_st  = io.req.valid && (io.req.bits.uop.uopc === uopSTA || io.req.bits.uop.uopc === uopAMO_AG) && misaligned
    // val dbg_bp = io.req.valid && ((io.req.bits.uop.uopc === uopLD  && bkptu.io.debug_ld) ||
    //                                 (io.req.bits.uop.uopc === uopSTA && bkptu.io.debug_st))
    // val bp     = io.req.valid && ((io.req.bits.uop.uopc === uopLD  && bkptu.io.xcpt_ld) ||
    //                                 (io.req.bits.uop.uopc === uopSTA && bkptu.io.xcpt_st))

    def checkExceptions(x: Seq[(Bool, UInt)]) =
        (x.map(_._1).reduce(_||_), PriorityMux(x))
    val (xcpt_val, xcpt_cause) = checkExceptions(List(
        (ma_ld,  (Causes.misaligned_load).U),   // TODO: change the cause code
        (ma_st,  (Causes.misaligned_store).U),
        (dbg_bp, (CSR.debugTriggerCause).U),
        (bp,     (Causes.breakpoint).U)))

    io.resp.bits.mxcpt.valid := xcpt_val
    io.resp.bits.mxcpt.bits  := xcpt_cause

    io.resp.bits.sfence.valid := io.req.valid && io.req.bits.uop.mem_cmd === M_SFENCE
    io.resp.bits.sfence.bits.rs1 := io.req.bits.uop.mem_size(0)
    io.resp.bits.sfence.bits.rs2 := io.req.bits.uop.mem_size(1)
    io.resp.bits.sfence.bits.addr := io.req.bits.rs1_data
    io.resp.bits.sfence.bits.asid := io.req.bits.rs2_data
}

abstract class IterativeFuncUnit extends FuncUnit (
    isPiplined = false,
    numStages = 1,
    numBypassStages = 0
) {
    val rUop = Reg(new MicroOp())
    val doKill = Wire(Bool())
    doKill := io.req.bits.kill

    when (io.req.fire) {
        doKill := IsKilledByBranch(io.brUpdate, io.req.bits.uop) || io.req.bits.kill
        rUop := io.req.bits.uop
        rUop.brMask := GetNewBrMask(io.brUpdate, io.req.bits.uop)
    } .otherwise {
        doKill = IsKilledByBranch(io.brUpdate, rUop) || io.req.bits.kill
        rUop.brMask := GetNewBrMask(io.brUpdate, rUop)
    }
    io.resp.bits.uop := rUop
}

class DivUnit extends IterativeFuncUnit {
    val div = Module(new SRT16Divider())

    div.io.req.valid := io.req.valid
    div.io.req.bits.fn := io.req.bits.uop.ctrl.op_fcn
    div.io.req.bits.op1 := io.req.bits.rs1Data
    div.io.req.bits.op2 := io.req.bits.rs2Data
    io.req.ready := div.io.req.ready

    div.io.kill := this.doKill

    io.resp.valid := div.io.resp.valid && !this.doKill
    div.io.resp.ready := io.resp.ready
    io.resp.bits.data := div.io.resp.bits.data
}