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
    val nBanks: Int        = 2
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
