package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input}
import common.{APB4, AXI4Lite}

class axi_apb_bridge_connect extends BlackBox {
    val io = IO(new Bundle {
        val s_axi_aclk = Input(Bool())
        val s_axi_aresetn = Input(Bool())
        val s_axi = Flipped(new AXI4Lite)
        val m_apb = new APB4(2)
    })
}
