package iFu.common

import chisel3._
import chisel3.util._
import iFu.common.Consts._

class BPUParameters {
    val localHistoryLength: Int  = 0
    val globalHistoryLength: Int = 0
    val numRasEntries: Int       = 0
}

class ICacheParameters {
    val nBanks: Int        = 0
    val nSets: Int         = 0
    val nWays: Int         = 0
    val lineBytes:Int      = 0
    val tagBits: Int       = 0
    val untagBits: Int     = 0
    val offsetBits : Int   = log2Ceil(lineBytes)
    val bytesPerBeat: Int  = 0
    val refillCycles : Int = lineBytes/bytesPerBeat
    val bankBytes: Int     = 4 * 4
    val banksPerLine: Int  = lineBytes/bankBytes
}

class FrontendParameters{
    val fetchWidth: Int                = 0
    val fetchBytes: Int                = fetchWidth * 4
    val numFTQEntries: Int             = 0
    val numFetchBufferEntries: Int     = 0
    val iCacheParams: ICacheParameters = new ICacheParameters
    val bpdParams: BPUParameters       = new BPUParameters
    val bankWidth: Int                 = fetchWidth / iCacheParams.nBanks
    val instrBytes:Int                 = 4
    require(iCacheParams.nBanks == 2)


    // How many "chunks"/interleavings make up a cache line?
    val numChunks = iCacheParams.lineBytes / iCacheParams.bankBytes

    // Which bank is the address pointing to?
    def bank(addr: UInt) = addr(log2Ceil(iCacheParams.bankBytes))

    def isLastBankInBlock(addr: UInt) = {
        addr(iCacheParams.offsetBits - 1, log2Ceil(iCacheParams.bankBytes)) === (numChunks - 1).U
    }
    def blockAlign(addr: UInt) = ~(~addr | (iCacheParams.lineBytes - 1).U)

    def bankAlign(addr: UInt) = ~(~addr | (iCacheParams.bankBytes - 1).U)

    def packetBasePC(addr: UInt) = addr >> log2Ceil(fetchBytes)

    def nextBank(addr: UInt) = bankAlign(addr) + iCacheParams.bankBytes.U

    def nextFetch(addr: UInt) = {
        bankAlign(addr) + Mux(isLastBankInBlock(addr), iCacheParams.bankBytes.U, fetchBytes.U)
    }

    def fetchMask(addr: UInt) = {
        val idx = addr(log2Ceil(fetchWidth) + log2Ceil(instrBytes) - 1, log2Ceil(instrBytes))
        val shamt = idx(log2Ceil(fetchWidth) - 2, 0)
        val end_mask = Mux(isLastBankInBlock(addr), Fill(fetchWidth / 2, 1.U), Fill(fetchWidth, 1.U))
        ((1 << fetchWidth) - 1).U << shamt & end_mask

    }

    def bankMask(addr: UInt) = {
        val idx = addr(log2Ceil(fetchWidth) + log2Ceil(instrBytes) - 1, log2Ceil(instrBytes))
        Mux(isLastBankInBlock(addr), 1.U(2.W), 3.U(2.W))

    }
}

trait HasCoreParameters {
    val xLen: Int = 32
    val vaddrBits: Int = xLen
    val paddrBits: Int = xLen
    val coreInstrBytes: Int = 4
    val coreInstrBits: Int = coreInstrBytes * 8
    val coreWidth = 4

    val frontendParams: FrontendParameters = new FrontendParameters
    val issueParams: Seq[IssueParams] = Seq(
        IssueParams(issueWidth = 1, numIssueSlots = 16, iqType = IQT_MEM.litValue, dispatchWidth = 1),
        IssueParams(issueWidth = 2, numIssueSlots = 16, iqType = IQT_INT.litValue, dispatchWidth = 1))
}
