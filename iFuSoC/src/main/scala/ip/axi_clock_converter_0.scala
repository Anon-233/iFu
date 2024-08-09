package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input, Output}
import common.AXI3

class axi_clock_converter_0 extends BlackBox {
    val io = IO(new Bundle {
        val s_axi_aclk = Input(Bool())
        val s_axi_aresetn = Input(Bool())
        val s_axi = Flipped(new AXI3)
        val m_axi_aclk = Input(Bool())
        val m_axi_aresetn = Input(Bool())
        val m_axi = new AXI3
    })
}
