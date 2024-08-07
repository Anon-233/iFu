package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input, UInt, fromIntToWidth}
import common.AXI

class CoreIO extends AXI {
    val aclk = Input(Bool())
    val aresetn = Input(Bool())
    val intrpt = Input(UInt(8.W))
}

class core_top extends BlackBox {
    val io = IO(new Bundle {
        val aclk = Input(Bool())
        val aresetn = Input(Bool())
        val intrpt = Input(UInt(8.W))
        val axi = Flipped(new AXI)
    })
//    val io = IO(new CoreIO)
}
