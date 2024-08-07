package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input, Output}
import common.AXI

class v_frmbuf_rd_0 extends BlackBox {
    val io = IO(new Bundle {
        val ap_clk = Input(Bool())
        val ap_rst_n = Input(Bool())
        val interrupt = Output(Bool())
        val s_axi_CTRL = new AXI
        val m_axi_mm_video = Flipped(new AXI)
        val m_axis_video = Flipped(new AXI)
    })
}
