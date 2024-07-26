package iFu.frontend

import chisel3._
import chisel3.util._

trait HasBPUParameters {
    val globalHistoryLength: Int = 8
    val vaddrBits = 32
    val fetchWidth = 4
    val fetchBytes = fetchWidth * 4

    

    val mixSize = 24
    def mixHILO(pc: UInt): UInt = Cat(pc(vaddrBits - 1 , mixSize) , pc(mixSize - 1, 0) ^ pc(vaddrBits - 1 , vaddrBits - mixSize))
    

    // val targetSz = 15
    val targetSz = 18

    def getTargetPC(pc: UInt , target : UInt): UInt = {
        Cat(pc(vaddrBits - 1, targetSz + 2) , target(targetSz - 1 , 0) , 0.U(2.W))
    }

    def getTarget(tgtpc : UInt): UInt = tgtpc(targetSz + 2 - 1 , 2)
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
    // def tagSz = 8

    // tag视野大小
    val tagView = 16
    // val offsetSz = 6
    def tagSz = tagView - log2Ceil(fetchBytes) + 1
    def getTag(pc: UInt): UInt =  pc(tagView , log2Ceil(fetchBytes))
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
    // def tagSz        = vaddrBits - log2Ceil(nSets) - log2Ceil(fetchBytes)
    val nSets = 64
    // val lowBitSz = 16

    def nIdxBits = log2Ceil(nSets)
    def getIdx(pc: UInt): UInt = pc(nIdxBits + log2Ceil(fetchBytes) - 1, log2Ceil(fetchBytes))
    val tagView = 16
    def tagSz = tagView - nIdxBits - log2Ceil(fetchBytes) + 1
    def getTag(pc: UInt): UInt = pc(tagView , nIdxBits + log2Ceil(fetchBytes))
}

trait HasLocalHistoryParameters extends HasBPUParameters {
    val localHistoryLength = 13
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
        // val nChunks = (localHistoryLength + nCounterBits - 1) / nCounterBits
        // val hist_chunks = (0 until nChunks) map { i =>
        //     hist(math.min((i + 1) * nCounterBits, localHistoryLength) - 1, i * nCounterBits)
        // }
        // hist_chunks.reduce(_ ^ _) ^ pc(nCounterBits + log2Ceil(fetchBytes) - 1, log2Ceil(fetchBytes))
        hist
    }
}


trait HasAsmParameters extends HasBPUParameters {
    val nHists = 4096
    val nBTBEntries = 512
    val nCounterBits = 2
    val nLocalHistBits = log2Ceil(nHists)
    val nIdxBits = log2Ceil(nBTBEntries)
    val tagViewSize = 16

    // val mixSize = 24
    // def mixHILO(pc: UInt): UInt = Cat(pc(vaddrBits - 1 , mixSize) , pc(mixSize - 1, 0) ^ pc(vaddrBits - 1 , vaddrBits - mixSize))
    def getIdx(pc: UInt): UInt = pc(nIdxBits + log2Ceil(fetchBytes) - 1, log2Ceil(fetchBytes))
    def getTag(pc: UInt): UInt = /* Cat(pc( tagViewSize , nIdxBits + log2Ceil(fetchBytes) ), pc(log2Ceil(fetchBytes) - 1, 2)) */
                                pc(tagViewSize , nIdxBits + log2Ceil(fetchBytes))
    val nTagBits = tagViewSize - nIdxBits - 4 + 1

    // val nTargetBits = 15
    // def getTargetPC(pc: UInt , target : UInt): UInt = {
    //     Cat(pc(vaddrBits - 1, nTargetBits + 2) , target , 0.U(2.W))
    // }

    // def getTarget(tgtpc : UInt): UInt = tgtpc(nTargetBits + 1 , 2)

}
