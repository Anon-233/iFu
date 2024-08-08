package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input, UInt, fromIntToWidth}
import common.AXI4StreamUpper

class stream_ctl_0 extends BlackBox {
    val io = IO(new Bundle {
        val aclk = Input(Bool())
        val aresetn = Input(Bool())
        val ctl_reg1 = Input(UInt(32.W))
        val m_axis_video = new AXI4StreamUpper
        val s_axis_video = Flipped(new AXI4StreamUpper)
    })
}
