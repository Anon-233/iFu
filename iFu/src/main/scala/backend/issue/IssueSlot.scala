package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._

class IssueSlotIO(val numWakeupPorts: Int) extends CoreBundle {
    val valid  = Output(Bool())
    val willBeValid = Output(Bool())
    val request = Output(Bool())
    val grant = Input(Bool())

    val brUpdate = Input(new BrUpdateInfo)
    val kill = Input(Bool())
    val clear = Input(Bool())
    val ldSpecMiss = Input(Bool())

    val wakeupPorts = Vec(numWakeupPorts, Flipped(Valid(new IssueWakeup(maxPregSz.W))))
    val predWakeupPorts = Flipped(Valid(UInt(log2Ceil(ftqSz).W)))
    val specLdWakeupPorts = Vec(memWidth, Flipped(Valid(UInt(maxPregSz.W))))

    val inUop = Flipped(Valid(new MicroOp))
    val outUop = Output(new MicroOp) // passed to next slot uop
    val uop = Output(new MicroOp)   // issued uop
}

class IssueSlot(val numWakeupPorts: Int) extends CoreModule with IssueState {
    val io = IO(new IssueSlotIO(numWakeupPorts))

    val state = RegInit(s_invalid)
    val p1 = RegInit(false.B)
    val p2 = RegInit(false.B)
    val ppred = RegInit(false.B)
    val p1Poisoned = RegInit(false.B)
    val p2Poisoned = RegInit(false.B)
    val slotUop = RegInit(NullMicroOp)

    val nextState = WireInit(state)
    val nextUopc = WireInit(slotUop.uopc)
    val nextLRs1Rtype = WireInit(slotUop.lrs1Rtype)
    val nextLRs2Rtype = WireInit(slotUop.lrs2Rtype)
    val nextUop = Mux(io.inUop.valid, io.inUop.bits, slotUop)
    p1Poisoned := false.B
    p2Poisoned := false.B
    val nextP1Poisoned = Mux(io.inUop.valid, io.inUop.bits.p1Poisoned, p1Poisoned)
    val nextP2Poisoned = Mux(io.inUop.valid, io.inUop.bits.p2Poisoned, p2Poisoned)
    
    when (io.kill) {
        state := s_invalid
    }.elsewhen (io.inUop.valid) {
        state := io.inUop.bits.iw_state
    }.elsewhen (io.clear) {
        state := s_invalid
    }.otherwise {
        state := nextState
    }

    when (io.kill) {
        nextState := s_invalid
    }.elsewhen (
        (io.grant && (state === s_valid_1)) ||
        (io.grant && (state === s_valid_2) && p1 && p2 && ppred)
    ){
        when (!(io.ldSpecMiss && (p1Poisoned || p2Poisoned))) {
            nextState := s_invalid
        }
    }.elsewhen (io.grant && (state === s_valid_2)) {
        when (!(io.ldSpecMiss && (p1Poisoned || p2Poisoned))) {
            nextState := s_valid_1
            when (p1) {
                slotUop.uopc := uopSTD
                nextUopc := uopSTD
                slotUop.lrs1Rtype := RT_X
                nextLRs1Rtype := RT_X
            }.otherwise {
                slotUop.lrs2Rtype := RT_X
                nextLRs2Rtype := RT_X
            }
        }
    }

    when (io.inUop.valid) {
        slotUop := io.inUop.bits
    }

    val nextP1 = WireInit(p1)
    val nextP2 = WireInit(p2)
    val nextPpred = WireInit(ppred)

    when (io.inUop.valid) {
        p1 := !(io.inUop.bits.prs1Busy)
        p2 := !(io.inUop.bits.prs2Busy)
        ppred := !(io.inUop.bits.ppredBusy)
    }

    when (io.ldSpecMiss && nextP1Poisoned) { p1 := false.B }
    when (io.ldSpecMiss && nextP2Poisoned) { p2 := false.B }

    for (i <- 0 until numWakeupPorts) {
        when (io.wakeupPorts(i).valid && (io.wakeupPorts(i).bits.pdst === nextUop.prs1)) {
            p1 := true.B
        }
        when (io.wakeupPorts(i).valid && (io.wakeupPorts(i).bits.pdst === nextUop.prs2)) {
            p2 := true.B
        }
    }

    when (io.predWakeupPorts.valid && io.predWakeupPorts.bits === nextUop.ppred) {
        ppred := true.B
    }

    for (w <- 0 until memWidth) {
        when (
            io.specLdWakeupPorts(w).valid &&
            io.specLdWakeupPorts(w).bits === nextUop.prs1 &&
            nextUop.lrs1Rtype === RT_FIX
        ) {
            p1 := true.B
            p1Poisoned := true.B
        }
        when (
            io.specLdWakeupPorts(w).valid &&
            io.specLdWakeupPorts(w).bits === nextUop.prs2 &&
            nextUop.lrs2Rtype === RT_FIX
        ) {
            p2 := true.B
            p2Poisoned := true.B
        }
    }

    val nextBrMask = GetNewBrMask(io.brUpdate, slotUop)

    when (IsKilledByBranch(io.brUpdate, slotUop)) {
        nextState := s_invalid
    }

    when (!io.inUop.valid) {
        slotUop.br_mask := nextBrMask
    }

    when (state === s_valid_1) {
        io.request := p1 && p2 && ppred && !io.kill
    }.elsewhen (state === s_valid_2) {
        io.request := (p1 || p2) && ppred && !io.kill
    }.otherwise {
        io.request := false.B
    }

    io.valid := isValid
    io.uop := slotUop
    io.uop.iw_p1_poisoned := p1Poisoned
    io.uop.iw_p2_poisoned := p2Poisoned

    val mayVacate = io.grant && ((state === s_valid_1) || (state === s_valid_2) && p1 && p2 && ppred)
    val squashGrant = io.ldSpecMiss && (p1Poisoned || p2Poisoned)
    io.willBeValid := isValid && !(mayVacate && !squashGrant)

    io.outUop := slotUop
    io.outUop.iw_state := nextState
    io.outUop.uopc := nextUopc
    io.outUop.lrs1Rtype := nextLRs1Rtype
    io.outUop.lrs2Rtype := nextLRs2Rtype
    io.outUop.br_mask := nextBrMask
    io.outUop.prs1_busy := !p1
    io.outUop.prs2_busy := !p2
    io.outUop.ppred_busy := !ppred
    io.outUop.iw_p1_poisoned := p1Poisoned
    io.outUop.iw_p2_poisoned := p2Poisoned

    when (state === s_valid_2) {
        when (p1 && p2 && ppred) {
            ;
        }.elsewhen (p1 && ppred) {
            io.uop.uopc := slotUop.uopc
            io.uop.lrs2_rtype := RT_X
        }.elsewhen (p2 && ppred) {
            io.uop.uopc := uopSTD
            io.uop.lrs1_rtype := RT_X
        }
    }
}