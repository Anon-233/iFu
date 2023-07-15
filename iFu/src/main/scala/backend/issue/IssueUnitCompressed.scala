package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._

class IssueUnitCompressed(
    // TODO: add parameters
) extends IssueUnit(/*TODO*/) {
    val maxShift = dispatchWidth
    val vacants = issueSlots.map(!_.valid) ++ io.disUops.map(_.valid).map(!_.asBool)
    val shamtOH = Array.fill(numIssueSlots + dispatchWidth) { Wire(UInt(maxShift.W)) }

    def getShamtOH(countOH: UInt, inc: Bool): UInt = {
        val next = Wire(UInt(maxShift.W))
        when (countOH === 0.U && inc) {
            next := 1.U
        }.elsewhen (!countOH(maxShift - 1) && inc) {
            next := (countOH << 1.U)
        }
        next
    }

    shamtOH(0) := 0.U
    (1 until numIssueSlots + dispatchWidth).map {
        case i => shamtOH(i) := getShamtOH(shamtOH(i - 1), vacants(i - 1))
    }

    val willBeValid = (0 until numIssueSlots),map(i => issueSlots(i).willBeValid) ++
                      (0 until dispatchWidth).map(i => io.disUops(i).valid &&
                                                    //    !disUops(i).exception &&
                                                    //    !disUops(i).is_fence &&
                                                    //    !disUops(i).is_fencei
                      )
    val uops = issueSlots.map(_.outUop) ++ disUops.map(_)
    for (i <- 0 until numIssueSlots) {
        issueSlots(i).inUop.valid := false.B
        issueSlots(i).inUop.bits := uop(i + 1)    // out of bounds?
        for (j <- 1 to maxShift) {
            when (shamtOH(i + j) === (1 << (j - 1)).U) {
                issueSlots(i).inUop.valid := willBeValid(i + j)
                issueSlots(i).inUop.bits := uops(i + j)
            }
        }
        issueSlots(i).clear := shamtOH(i) =/= 0.U
    }

    val willBeAvailable = (0 until numIssueSlots).map (
        i => (!issueSlots(i).willBeValid || issueSlots(i).clear) && !(issueSlots(i).inUop.valid)
    )
    val numAvailable = PopCount(willBeAvailable)
    for (w <- 0 until dispatchWidth) {
        io.disUops(w).ready := RegNext(numAvailable > w.U)
    }

    for (w <- 0 until issueWidth) {
        io.issueValids(w) := false.B
        io.issueUops(w) := NullMicroOp
        io.issueUops(w).prs1 := 0.U
        io.issueUops(w).prs2 := 0.U
        io.issueUops(w).lrs1_rtype := RT_X
        io.issueUops(w).lrs2_rtype := RT_X
    }

    // choose which uops to issue
    val requests = issueSlots.map(_.request)    // get request from each slot
    val portIssued = Array.fill(issueWidth) { false.B }

    for (i <- 0 until numIssueSlots) {  // iterate through all slots
        issueSlots(i).grant := false.B
        var uopIssued = false.B

        for (w <- 0 until issueWidth) {
            val canAllocate = (issueSlots(i).uop.fu_code & io.fuTypes(w)) =/= 0.U
            when (canAllocate && requests(i) && !uopIssued && !portIssued(w)) {
                issueSlots(i).grant := true.B
                io.issueValids(w) := true.B
                io.issueUops(w) := issueSlots(i).uop
            }
            val wasIssuedYet = portIssued(w)
            portIssued(w) = (canAllocate && requests(i) && !uopIssued) | portIssued(w)
            uopIssued = (canAllocate && requests(i) && !wasIssuedYet) | uopIssued
        }
    }
}