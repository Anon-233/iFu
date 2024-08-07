package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input, Output}
import common.AXI

class axi_clock_converter_0 extends BlackBox {
    val io = IO(new Bundle {
        val s_axi_aclk = Input(Bool())
        val s_axi_aresetn = Input(Bool())
        val s_axi = new AXI
        val m_axi_aclk = Output(Bool())
        val m_axi_aresetn = Output(Bool())
        val m_axi = Flipped(new AXI)
    })
}
