package iFu.common

import chisel3._

trait HasCoreParameters {
    val fetchWidth: Int = 8     // 一次取值宽度
    val nBanks: Int = 2
}
