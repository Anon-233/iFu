package iFu.common

import chisel3._
import chisel3.util._
import iFu.common.Consts._

class CSRParameters{
    val TLB_INDEX_LENGTH: Int = 5
    val TLBIDX_r: Int = 16-TLB_INDEX_LENGTH
    val TLBIDX_INDEX:Int = TLB_INDEX_LENGTH

    val PALEN: Int = 32
    val TLBELO_r: Int = 36-PALEN
    val TLBELO_ppn: Int = PALEN-12

    val TIMER_LENGTH: Int = 32
    val TCFG_initval: Int = TIMER_LENGTH-2

    val CSR_CRMD = 0.U(14.W)
    val CSR_PRMD = 1.U(14.W)
    val CSR_EUEN = 2.U(14.W)
    val CSR_ECFG = 4.U(14.W)
    val CSR_ESTAT = 5.U(14.W)
    val CSR_ERA = 6.U(14.W)
    val CSR_BADV = 7.U(14.W)
    val CSR_EENTRY = 12.U(14.W)
    val CSR_TLBIDX = 16.U(14.W)
    val CSR_TLBEHI = 17.U(14.W)
    val CSR_TLBELO0 = 18.U(14.W)
    val CSR_TLBELO1 = 19.U(14.W)
    val CSR_ASID = 24.U(14.W)
    val CSR_PGDL = 25.U(14.W)
    val CSR_PGDH = 26.U(14.W)
    val CSR_PGD = 27.U(14.W)
    val CSR_CPUID = 32.U(14.W)
    val CSR_SAVE0 = 48.U(14.W)
    val CSR_SAVE1 = 49.U(14.W)
    val CSR_SAVE2 = 50.U(14.W)
    val CSR_SAVE3 = 51.U(14.W)
    val CSR_TID = 64.U(14.W)
    val CSR_TCFG = 65.U(14.W)
    val CSR_TVAL = 66.U(14.W)
    val CSR_TICLR = 68.U(14.W)
    val CSR_LLBCTL = 96.U(14.W)
    val CSR_TLBRENTRY = 136.U(14.W)
    val CSR_CTAG = 152.U(14.W)
    val CSR_DMW0 = 384.U(14.W)
    val CSR_DMW1 = 385.U(14.W)
}

class BPUParameters {
    val globalHistoryLength: Int = 8
    val numRasEntries: Int       = 16
    val localHistoryLength:Int = 2 
}

class ICacheParameters {
    val nBanks: Int       = 2
    val nSets: Int        = 64
    val nWays: Int        = 8
    val lineBytes:Int     = 64
    val indexBits: Int    = log2Ceil(nSets)
    val offsetBits : Int  = log2Ceil(lineBytes)
    val untagBits: Int    = indexBits + offsetBits
    val tagBits: Int      = 32 - untagBits
    val bankBytes: Int    = 4 * 4
    val banksPerLine: Int = lineBytes / bankBytes
    require(isPow2(banksPerLine))
}

class FrontendParameters{
    val fetchWidth: Int                = 8
    val fetchBytes: Int                = fetchWidth * 4
    val numFTQEntries: Int             = 40
    val numFetchBufferEntries: Int     = 32
    val iCacheParams: ICacheParameters = new ICacheParameters
    val bpdParams: BPUParameters       = new BPUParameters
    val bankWidth: Int                 = fetchWidth / iCacheParams.nBanks
    val instrBytes:Int                 = 4
}

class ROBParameters {
    val coreWidth: Int = 4
    val retireWidth: Int = 4 //decodeWidth
    val numRobEntries:Int = 128
    val numRobRows: Int = numRobEntries/coreWidth
    val robAddrSz: Int = log2Ceil(numRobRows) + log2Ceil(coreWidth)
}

class LSUParameters{
    val numSTQEntries: Int = 32
    val numLDQEntries: Int = 32
    val ldqAddrSz    : Int = log2Ceil(numLDQEntries)
    val stqAddrSz    : Int = log2Ceil(numSTQEntries)
    val MINI_EXCEPTION_MEM_ORDERING: Int = 2
}

class DcacheParameters {
    val nRowBits = 512
    def nRowBytes = nRowBits / 8
    def nRowWords = nRowBits / 32
    val nSets = 64
    val nWays = 8
    val nMSHR = 8
    val nTLBEntries = 32
    def nOffsetBits = log2Ceil(nRowBytes)
    def nIdxBits = log2Ceil(nSets)
    def nTagBits = 32 - nOffsetBits - nIdxBits
    val coreDataBits = 32
    val vaddrBits = 32
    def nBlockAddrBits = vaddrBits - nOffsetBits

    val memWidth = 2

    val nFirstMSHRs = 4
    val nSecondMSHRs = 8

    def IsKilledByBranch (brupdate: BrUpdateInfo, uop: MicroOp): Bool = {
        return maskMatch(brupdate.b1.mispredictMask, uop.brMask)
    }

    def maskMatch(msk1: UInt, msk2: UInt): Bool = (msk1 & msk2) =/= 0.U

    def getIdx(vaddr: UInt): UInt = vaddr(nOffsetBits + nIdxBits - 1, nOffsetBits)
    def getTag(vaddr: UInt): UInt = vaddr(vaddrBits - 1, vaddrBits - nTagBits)
    def getBlockAddr(vaddr: UInt): UInt = vaddr(vaddrBits - 1, nOffsetBits)

    def isStore(req : DCacheReq): Bool = req.uop.use_stq

}

case class IssueParams(
    iqType: Int,        // issue queue type: IQT_INT, IQT_MEM
    numIssueSlots: Int, // number of issue slots
    dispatchWidth: Int,
    issueWidth: Int    // maximum number of uops issued per cycle
)

trait HasCoreParameters {
    val resetPC: Int = 0x1c000000
    val xLen: Int = 32
    val vaddrBits: Int = xLen
    val paddrBits: Int = xLen
    val coreInstrBytes: Int = 4
    val coreInstrBits: Int = coreInstrBytes * 8
    val coreWidth = 4
    val memWidth = 2
    val maxBrCount: Int = 20
    val brTagSz: Int = log2Ceil(maxBrCount)
    val numLRegs: Int = 32
    val lregSz: Int = log2Ceil(numLRegs)
    val numPRegs: Int = 108
    val pregSz: Int = log2Ceil(numPRegs)
    val frontendParams: FrontendParameters = new FrontendParameters
    val robParameters: ROBParameters = new ROBParameters
    val lsuParameters: LSUParameters = new LSUParameters
    val dcacheParameters: DcacheParameters = new DcacheParameters
    val issueParams: Seq[IssueParams] = Seq(
        IssueParams(issueWidth = 2, numIssueSlots = 24, iqType = IQT_MEM.litValue.toInt, dispatchWidth = 4),
        IssueParams(issueWidth = 4, numIssueSlots = 40, iqType = IQT_INT.litValue.toInt, dispatchWidth = 4))
    val enableSFBOpt: Boolean = true
    val csrParameters: CSRParameters = new CSRParameters
}
