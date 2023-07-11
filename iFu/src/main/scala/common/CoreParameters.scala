package iFu.common

import chisel3._

final case class BPUParameters(
    // TODO: add more parameters
)

final case class ICacheParameters(
    blockBytes: Int = 256,
    nBanks: Int = 2,
    bankWidth: Int = 128 // blockBytes / nBanks

)

final case class FrontendParameters(
    iCacheParams: ICacheParameters = ICacheParameters(),
    numFTQEntries: Int = 40,
    numFBEntries: Int = 32,
    fetchWidth: Int = 8
)

trait HasCoreParameters {
    val vaddrBits: Int = 32                     // 虚拟地址位数
    val coreInstrBytes: Int = 4                 // 指令字节数
    val coreInstrBits: Int = coreInstrBytes * 8 // 指令位数
    val bpdParams: BPUParameters = BPUParameters()
    val frontendParams: FrontendParameters = FrontendParameters()
    val coreWidth = 4                           // coreWith
    val nBanks: Int = 2
}
