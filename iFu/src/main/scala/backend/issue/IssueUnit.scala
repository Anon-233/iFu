package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._

case class IssueParams(
    iqType: Int,
    numIssueSlots: Int,
    dispatchWidth: Int,
    issueWidth: Int
)

trait IssueStateEnum {
    // s_invalid -> no valid uop
    // s_valid_1 -> normal valid uop
    // s_valid_2 -> STA-like uop
    val s_invalid :: s_valid_1 :: s_valid_2 :: Nil = Enum(3)
}

class IssueUnitWakeup(val pregSz: Int) extends Bundle {
    val pdst = UInt(pregSz.W)   // physical destination register
    val poisoned = Bool()
}

class IssueUnitIO(
    val dispatchWidth: Int,
    val numWakeupPorts: Int,
    val issueWidth: Int
) extends CoreBundle {
    val disUops = Vec(dispatchWidth, Flipped(Decoupled(new MicroOp)))

    val wakeup = Vec(numWakeupPorts, Flipped(Valid(new IssueUnitWakeup(/*TODO*/))))
    val predWakeup = Flipped(Valid(UInt(log2Ceil(ftqSz).W)))
    val specLdWakeup = Vec(/*TODO*/, Flipped(Valid(UInt(/*TODO*/))))
    val ldMiss = Input(Bool())

    val fuTypes = Vec(issueWidth, Input(Bits(/*TODO*/)))

    val brUpdate = Input(new BrUpdateInfo())
    val flushPipeline = Input(Bool())

    val issueValids = Vec(issueWidth, Output(Bool()))
    val issueUops = Vec(issueWidth, Output(new MicroOp))
}

abstract class IssueUnit(
    val iqType: Int,    // TODO: iqType?
    val numIssueSlots: Int,
    val dispatchWidth: Int,
    val numWakeupPorts: Int,
    val issueWidth: Int
) extends CoreModule with IssueStateEnum {
    val io = IO(new IssueUnitIO(dispatchWidth, numWakeupPorts, issueWidth))

    val disUops = Array.fill(dispatchWidth) { Wire(new MicroOp) }
    for (w <- 0  until dispatchWidth) {
        disUops(w) := io.disUops(w).bits
        disUops(w).iw_state := s_valid_1
        disUops(w).iw_p1_poinsoned := false.B
        disUops(w).iw_p2_poinsoned := false.B

        when((io.disUops(w).bits.uopc === uopSta)) {
            disUops(w).iw_state := s_valid_2
        }

        if (iqType == IQT_MEM.litValue) {
            assert(!(io.disUops(w).valid && io.disUops(w).bits.ppred_busy))
            disUops(w).ppred_busy := false.B
        }
    }

    val slots = (0 until numIssueSlots).map {
        case i => Module(new IssueSlot(numWakeupPorts))
    }
    val slotsIOs = VecInit(slots.map(_.io))

    for (w <- 0 until numIssueSlots) {
        slotsIOs(i).wakeup := io.wakeup
        slotsIOs(i).predWakeup := io.predWakeup
        slotsIOs(i).specLdWakeup := io.specLdWakeup
        slotsIOs(i).ldMiss := io.ldMiss
        slotsIOs(i).brUpdate := io.brUpdate
        slotsIOs(i).kill := io.flushPipeline
    }
}