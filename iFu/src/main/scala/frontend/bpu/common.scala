package iFu.frontend

import chisel3._
import chisel3.util._

trait HasBPUParameters {
    val globalHistoryLength: Int = 8
    val vaddrBits = 32
    val fetchWidth = 4
    val nBanks = 2
    val bankWidth = fetchWidth / nBanks
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
    val extendedNSets = 64
    val offsetSz = 13
    val BTBEntrySz = offsetSz + 1

    val BTBMetaSz = tagSz + 1
}
