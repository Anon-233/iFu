package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input}
import common.{AXI3, AXI3Len}

class main_xbar extends BlackBox {
    val io = IO(new Bundle {
        val aclk = Input(Bool())
        val aresetn = Input(Bool())
        val s_axi = Flipped(new AXI3)
        val m_axi = new AXI3((new AXI3Len).double)
    })
}
