package iFu.common

import chisel3._

final case class BPUParameters(
    // TODO: add more parameters
)

trait HasCoreParameters {
    val vaddrBits: Int = 32     // 虚拟地址位数
    val coreInstrBytes: Int = 4 // 指令字节数
    val fetchWidth: Int = 8     // 一次取值宽度
    val nBanks: Int = 2
    val bpdParams: BPUParameters = BPUParameters()
}
