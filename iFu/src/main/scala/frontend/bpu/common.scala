package iFu.frontend

import chisel3._
import chisel3.util._
import scala.math.min


trait HasBPUParameters {
    val coreInstBytes = 4
    val vaddrBits = 32
    val bankWidth = 4
    val fetchWidth = 8
    val nBanks = 2
    val localHistoryLength = 16
    val globalHistoryLength = 32
    val fetchBytes = 32
    val bankBytes = fetchBytes / nBanks
    val blockBytes = 64  //待确认
    val blockOffBits = log2Ceil(blockBytes)
    val numChunks = blockBytes / bankBytes
    val nRasEntries = 8
    val ftqSz = 40

    val CFI_SZ = 2
    val BSRC_SZ = 2
    val EnableBPD = true
}

trait HasTageParameters extends HasBPUParameters {
    val nWrBypassEntries = 2
    val tageNTables = 6
    val tageUBitPeriod = 2048
}

trait HasUbtbParameters extends HasBPUParameters {
    val nWays = 16
    def tagSz = vaddrBits - log2Ceil(fetchBytes)
    val offsetSz = 6
    val nWrBypassEntries = 2

    def bimWrite(v: UInt, taken: Bool): UInt = {
    val oldBimSatTaken  = v === 3.U
    val oldBimSatNtaken = v === 0.U
    Mux(oldBimSatTaken  &&  taken, 3.U,
      Mux(oldBimSatNtaken && !taken, 0.U,
      Mux(taken, v + 1.U, v - 1.U)))
    }

}

trait HasBimParameters extends HasBPUParameters {
    val nSets = 2048
    // val nSets = 1024
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
    // val nSets        = 128
    // val extendedNSets = 128
    val nSets = 64
    val extendedNSets = 64
    val offsetSz = 13
    val BTBEntrySz = offsetSz + 1

    val BTBMetaSz = tagSz + 1
}
