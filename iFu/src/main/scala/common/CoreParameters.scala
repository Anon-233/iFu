package iFu.common

import backend.decode.common.IQT_INT
import chisel3._
import common.Consts
import iFu.backend.IssueParams

final case class BPUParameters(
    // TODO: add more parameters
)

final case class ICacheParameters(
    blockBytes: Int = 256,
    nBanks: Int = 2,
    bankWidth: Int = 128, // blockBytes / nBanks
    nSets: Int = 666666,
    nWays: Int = 4,
    tagBits: Int = 666666,
    untagBits: Int = 666666,
    blockOffBits : Int = 666666,
    refillCycles : Int = 666666,
    bankBytes: Int = 666666

)

final case class FrontendParameters(
    iCacheParams: ICacheParameters = ICacheParameters(),
    numFTQEntries: Int = 40,
    numFBEntries: Int = 32,
    fetchWidth: Int = 8,
    fetchBytes: Int = 32
)

trait HasCoreParameters extends Consts{
    val vaddrBits: Int = 32                     // 虚拟地址位数
    val paddrBits: Int = 32                     //物理地址位数
    val coreInstrBytes: Int = 4                 // 指令字节数
    val coreInstrBits: Int = coreInstrBytes * 8 // 指令位数
    val bpdParams: BPUParameters = BPUParameters()
    val frontendParams: FrontendParameters = FrontendParameters()
    val coreWidth = 4                           // coreWith
    val nBanks: Int = 2
    val xLen: Int = 32
    val issueParams: Seq[IssueParams] = Seq(
        IssueParams(issueWidth = 1, numIssueSlots = 16, iqType = IQT_MEM.litValue, dispatchWidth = 1),
        IssueParams(issueWidth = 2, numIssueSlots = 16, iqType = IQT_INT.litValue, dispatchWidth = 1))
}
