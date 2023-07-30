package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._

trait IssueState {
    // s_invalid -> no valid instruction
    // s_valid_1 -> normal valid instruction
    // s_valid_2 -> store-like instruction
    val s_invalid :: s_valid_1 :: s_valid_2 :: Nil = Enum(3)

    def isValid(s: UInt): Bool = s =/= s_invalid
    def isInvalid(s: UInt): Bool = s === s_invalid
}

class IssueWakeup(val pregSz: Int) extends Bundle {
    val pdst = UInt(pregSz.W)   // physical destination register
    val poisoned = Bool()
}

class IssueUnitIO (
    val dispatchWidth: Int,
    val numWakeupPorts: Int,
    val issueWidth: Int
) extends CoreBundle {
    val ftqSz = frontendParams.numFTQEntries

    val disUops = Vec(dispatchWidth, Flipped(Decoupled(new MicroOp)))

    // normal wakeup
    val wakeupPorts = Vec(numWakeupPorts, Flipped(Valid(new IssueWakeup(pregSz.W))))
    // SFB wakeup
    val predWakeupPorts = Flipped(Valid(UInt(log2Ceil(ftqSz).W)))
    // speculative load wakeup
    val specLdWakeupPorts = Vec(memWidth, Flipped(Valid(UInt(pregSz.W))))
    val ldMiss = Input(Bool())  // load miss happened

    val fuTypes = Input(Vec(issueWidth, Bits(FUC_SZ.W)))

    val brUpdate = Input(new BrUpdateInfo)
    val flushPipeline = Input(Bool())

    val issueValids = Output(Vec(issueWidth, Bool()))
    val issueUops = Output(Vec(issueWidth, new MicroOp))
}

abstract class AbsIssueUnit (
    val iqType: Int,
    val numIssueSlots: Int,
    val dispatchWidth: Int,
    val numWakeupPorts: Int,
    val issueWidth: Int
) extends CoreModule with IssueState with MicroOpCode {
    val io = IO(new IssueUnitIO(dispatchWidth, numWakeupPorts, issueWidth))

    val disUops = Wire(Vec(dispatchWidth, new MicroOp))
    
    for (w <- 0 until dispatchWidth) {
        disUops(w) := io.disUops(w).bits
        disUops(w).iw_state := s_valid_1
        disUops(w).iw_p1_poinsoned := false.B
        disUops(w).iw_p2_poinsoned := false.B

        when (
            (io.disUops(w).bits.uopc === uopSTA) ||
            (io.disUops(w).bits.uopc === uopAMO_AG)
        ) {
            disUops(w).iw_state := s_valid_2
        }

        if (iqType == IQT_MEM.litValue) {
            assert(!(io.disUops(w).valid && io.disUops(w).bits.ppred_busy))
            disUops(w).ppred_busy := false.B
        }
    }

    val slots = (0 until numIssueSlots).map {
        case _ => Module(new IssueSlot(numWakeupPorts))
    }
    val issueSlots = VecInit(slots.map(_.io))

    for (w <- 0 until numIssueSlots) {
        issueSlots(i).wakeupPorts       := io.wakeupPorts
        issueSlots(i).predWakeupPorts   := io.predWakeupPorts
        issueSlots(i).specLdWakeupPorts := io.specLdWakeupPorts
        issueSlots(i).ldSpecMiss        := io.ldMiss
        issueSlots(i).brUpdate          := io.brUpdate
        issueSlots(i).kill              := io.flushPipeline
    }
}