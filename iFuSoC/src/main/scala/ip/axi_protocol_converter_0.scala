package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input}
import common.AXI

class axi_protocol_converter_0 extends BlackBox {
    val io = IO(new Bundle {
        val aclk = Input(Bool())
        val aresetn = Input(Bool())
        val s_axi = new AXI
        val m_axi = Flipped(new AXI)
    })
}
