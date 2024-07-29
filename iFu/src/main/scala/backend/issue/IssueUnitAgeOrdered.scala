package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._

class IssueUnitAgeOrdered (
    issParams: IssueParams,
    numWakeupPorts: Int
) extends AbsIssueUnit (
    issParams.iqType,
    issParams.numIssueSlots,
    issParams.dispatchWidth,
    numWakeupPorts,
    issParams.issueWidth
) {
    val maxShift = dispatchWidth
    val vacants = issueSlots.map(_.valid).map(!_.asBool) ++ io.disUops.map(_.valid).map(!_.asBool)
    val shamtOH = Array.fill(numIssueSlots + dispatchWidth) { Wire(UInt(maxShift.W)) }

    def getShamtOH(countOH: UInt, inc: Bool): UInt = {
        val next = Wire(UInt(maxShift.W))
        next := countOH
        when (countOH === 0.U && inc) {
            next := 1.U
        } .elsewhen (!countOH(maxShift - 1) && inc) {
            next := (countOH << 1.U)
        }
        next
    }

    shamtOH(0) := 0.U
    (1 until numIssueSlots + dispatchWidth).map {
        case i => shamtOH(i) := getShamtOH(shamtOH(i - 1), vacants(i - 1))
    }

    val willBeValid = (0 until numIssueSlots).map(i => issueSlots(i).willBeValid) ++
                      (0 until dispatchWidth).map(i =>
                        io.disUops(i).valid && !disUops(i).xcpt_valid &&
                        !disUops(i).is_ibar && !disUops(i).is_nop
                      )

    val uops = issueSlots.map(_.outUop) ++ disUops.map(uop => uop)
    
    for (i <- 0 until numIssueSlots) {
        issueSlots(i).inUop.valid := false.B
        issueSlots(i).inUop.bits := uops(i + 1)

        for (j <- 1 to maxShift) {
            when (shamtOH(i + j) === (1 << (j - 1)).U) {
                issueSlots(i).inUop.valid := willBeValid(i + j)
                issueSlots(i).inUop.bits := uops(i + j)
            }
        }
        issueSlots(i).clear := shamtOH(i) =/= 0.U
    }

    val willBeAvailable = (0 until numIssueSlots).map (i =>
        (!issueSlots(i).willBeValid || issueSlots(i).clear) && !(issueSlots(i).inUop.valid)
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
            val canAllocate = (issueSlots(i).uop.fuCode & io.fuTypes(w)) =/= 0.U
            when (canAllocate && requests(i) && !uopIssued && !portIssued(w)) {
                issueSlots(i).grant := true.B
                io.issueValids(w) := true.B
                io.issueUops(w) := issueSlots(i).uop
                // why not?
                // portIssued(w) = true.B
                // uopIssued = true.B
            }
            val wasPortIssuedYet = portIssued(w)
            portIssued(w) = (canAllocate && requests(i) && !uopIssued) | portIssued(w)
            uopIssued = (canAllocate && requests(i) && !wasPortIssuedYet) | uopIssued
        }
    }
}
