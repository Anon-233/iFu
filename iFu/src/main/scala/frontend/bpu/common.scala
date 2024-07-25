package iFu.frontend

import chisel3._
import chisel3.util._

trait HasBPUParameters {
    val globalHistoryLength: Int = 8
    val vaddrBits = 32
    val fetchWidth = 4
    val fetchBytes = fetchWidth * 4
}

trait HasTageParameters extends HasBPUParameters {
    val nWrBypassEntries = 2
    val tageNTables = 6
    val tageUBitPeriod = 2048
}

trait HasUbtbParameters extends HasBPUParameters {
    // val nWays = 16
    val nWays = 4
    /* def tagSz = vaddrBits - log2Ceil(fetchBytes) */
    def tagSz = 8
    val offsetSz = 6
}

trait HasBimParameters extends HasBPUParameters {
    val nSets = 512
    val nWrBypassEntries = 2

    def bimWrite(v: UInt, taken: Bool): UInt = {
        val oldBimSatTaken  = v === 3.U
        val oldBimSatNtaken = v === 0.U
        Mux(oldBimSatTaken  &&  taken, 3.U,
        Mux(oldBimSatNtaken && !taken, 0.U,
        Mux(taken, v + 1.U, v - 1.U)))
    }
}

trait HasBtbParameters extends HasBPUParameters {
    val nWays        = 2
    def tagSz        = vaddrBits - log2Ceil(nSets) - log2Ceil(fetchBytes)
    val nSets = 64
    val lowBitSz = 16
}

trait HasLocalHistoryParameters extends HasBPUParameters {
    val localHistoryLength = 15
    val nLHRs = 64
    val nCounters = 8192
    val nLHRBits = log2Ceil(nLHRs)
    val nCounterBits = log2Ceil(nCounters)

    def update(v: UInt, taken: Bool): UInt = {
        val extended = Cat(0.U(1.W), v)
        val newCnt = Mux(taken, extended + 1.U, extended - 1.U)
        Mux(newCnt(2), v, newCnt(1, 0))
    }

    def hash(pc: UInt, hist: UInt): UInt = {
        hist
    }
}