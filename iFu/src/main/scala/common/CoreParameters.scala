package iFu.common

import chisel3._

final case class BPUParameters(
    // TODO: add more parameters
)

final case class FrontendParameters(
    // TODO: add more parameters
)

trait HasCoreParameters {
    val vaddrBits: Int = 32     // 虚拟地址位数
    val coreInstrBytes: Int = 4 // 指令字节数
    val frontendParams: FrontendParameters = FrontendParameters()
    val bpdParams: BPUParameters = BPUParameters()
}
