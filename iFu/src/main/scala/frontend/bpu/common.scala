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
    
    def fetchIdx(addr: UInt) = addr >> log2Ceil(fetchBytes)
    def WrapInc(x: UInt, max: UInt) = Mux(x === max, 0.U, x + 1.U)

        
    def WrapDec(value: UInt, n: Int): UInt = {
        // "n" is the number of increments, so we wrap at n-1.
        if (isPow2(n)) {
        (value - 1.U)(log2Ceil(n)-1,0)
        } else {
        val wrap = (value === 0.U)
        Mux(wrap, (n-1).U, value - 1.U)
        }
    }

    def MaskLower(in: UInt) = {
        val n = in.getWidth
        (0 until n).map(i => in >> i.U).reduce(_|_)
    }
    def bank(addr: UInt) = if (nBanks == 2) addr(log2Ceil(bankBytes)) else 0.U
    def isLastBankInBlock(addr: UInt) = {
        (nBanks == 2).B && addr(blockOffBits-1, log2Ceil(bankBytes)) === (numChunks-1).U
    }
    def mayNotBeDualBanked(addr: UInt) = {
        require(nBanks == 2)
        isLastBankInBlock(addr)
    }

    def bankAlign(addr: UInt) = ~(~addr | (bankBytes-1).U)


    def nextBank(addr: UInt) = bankAlign(addr) + bankBytes.U
    def nextFetch(addr: UInt) = {

        require(nBanks == 2)
        bankAlign(addr) + Mux(mayNotBeDualBanked(addr), bankBytes.U, fetchBytes.U)
    }

    def fetchMask(addr: UInt) = {
        val idx = addr(log2Ceil(fetchWidth)+log2Ceil(coreInstBytes)-1, log2Ceil(coreInstBytes))
        
        val shamt = idx(log2Ceil(fetchWidth)-2, 0)
        val end_mask = Mux(mayNotBeDualBanked(addr), Fill(fetchWidth/2, 1.U), Fill(fetchWidth, 1.U))
        ((1 << fetchWidth)-1).U << shamt & end_mask
    }

    def bankMask(addr: UInt) = {
        val idx = addr(log2Ceil(fetchWidth)+log2Ceil(coreInstBytes)-1, log2Ceil(coreInstBytes))
        Mux(mayNotBeDualBanked(addr), 1.U(2.W), 3.U(2.W))
    }
}

trait HasLoopParameters extends HasBPUParameters {
    val nSets = 16
    val nWays = 4
    val tagSz = 10
    val nWrBypassEntries = 2
}

trait HasTageParameters extends HasBPUParameters {
    val nWrBypassEntries = 2
    val tageNTables = 6
    val tageUBitPeriod = 2048
}

trait HasUbtbParameters extends HasBPUParameters {
    val nWays = 16
    val tagSz = 10
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
    val nSets        = 128
    val extendedNSets = 128
    val offsetSz = 13
    val btbEntrySz = offsetSz + 1

    val btbMetaSz = tagSz + 1
}


trait HasFTQParameters extends HasBPUParameters {


}

trait HasFBParameters extends HasBPUParameters{
    
}