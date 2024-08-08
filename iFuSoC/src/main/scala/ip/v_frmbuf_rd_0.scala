package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input, Output}
import common.{AXI3, AXI4FullUpper, AXI4LiteUpper, AXI4StreamUpper}

class v_frmbuf_rd_0 extends BlackBox {
    val io = IO(new Bundle {
        val ap_clk = Input(Bool())
        val ap_rst_n = Input(Bool())
        val interrupt = Output(Bool())
        val s_axi_CTRL = Flipped(new AXI4LiteUpper)
        val m_axi_mm_video = new AXI4FullUpper
        val m_axis_video = new AXI4StreamUpper
    })
}
