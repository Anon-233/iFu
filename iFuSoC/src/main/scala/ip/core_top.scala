package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input, UInt, fromIntToWidth}
import common.AXI3

class core_top extends BlackBox {
    val io = IO(new Bundle {
        val aclk = Input(Bool())
        val aresetn = Input(Bool())
        val intrpt = Input(UInt(8.W))
        val axi = new AXI3
    })
}
