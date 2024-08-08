package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input, Output}
import common.{AXI3, MAC}

class ethernet_top extends BlackBox {
    val io = IO(new Bundle {
        val hclk = Input(Bool())
        val hrst_ = Input(Bool())
        val m = new AXI3
        val s = Flipped(new AXI3)
        val interrupt0 = Output(Bool())
        val mac = new MAC
    })
}
