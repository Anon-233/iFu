package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input}
import common.{AXI3, AXI4Lite}

class axi_protocol_converter_0 extends BlackBox {
    val io = IO(new Bundle {
        val aclk = Input(Bool())
        val aresetn = Input(Bool())
        val s_axi = Flipped(new AXI3)
        val m_axi = new AXI4Lite
    })
}
