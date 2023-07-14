package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._

class IssueUnitCompressed(
    // TODO
) extends IssueUnit(/*TODO*/) {
    val maxShift = dispatchWidth
    val vacants = slotsIOs.map(!_.valid) ++ io.disUops.map(_.valid).map(!_.asBool)
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

    val willBeValid = (0 until numIssueSlots),map(i => slotsIOs(i).willBeValid) ++
                      (0 until dispatchWidth).map(i => io.disUops(i).valid &&
                                                    //    !disUops(i).exception &&
                                                    //    !disUops(i).is_fence &&
                                                    //    !disUops(i).is_fencei
                      )
    val uops = slotsIOs.map(_.outUop) ++ disUops.map(_)
    for (i <- 0 until numIssueSlots) {
        slotsIOs(i).inUop.valid := false.B
        slotsIOs(i).inUop.bits := uop(i + 1)    // out of bounds?
        for (j <- 1 to maxShift) {
            when (shamtOH(i + j) === (1 << (j - 1)).U) {
                slotsIOs(i).inUop.valid := willBeValid(i + j)
                slotsIOs(i).inUop.bits := uops(i + j)
            }
        }
        slotsIOs(i).clear := shamtOH(i) =/= 0.U
    }

    val willBeAvailable = (0 until numIssueSlots).map (
        i => (!slotsIOs(i).willBeValid || slotsIOs(i).clear) && !(slotsIOs(i).inUop.valid)
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

    val request = slotsIOs.map(_.request)
    val issued = Array.fill(issueWidth) { false.B }

    for (i <- 0 until numIssueSlots) {
        slotsIOs(i).grant := false.B
        var uopIssued = false.B

        for (w <- 0 until issueWidth) {
            val canAllocate = (slotsIOs(i).uop.fu_code & io.fuTypes(w)) =/= 0.U
            when (request(i) && !uopIssued && canAllocate && !issued(w)) {
                slotsIOs(i).grant := true.B
                io.issueValids(w) := true.B
                io.issueUops(w) := slotsIOs(i).uop
            }
            val wasIssuedYet = issued(w)
            issued(w) = (request(i) && !uopIssued && canAllocate) | issued(w)
            uopIssued = (request(i) && canAllocate && !wasIssuedYet) | uopIssued
        }
    }
}