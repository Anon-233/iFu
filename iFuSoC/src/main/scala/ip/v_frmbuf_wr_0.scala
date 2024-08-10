package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input, Output}
import common.{AXI4FullUpper, AXI4Len, AXI4LiteUpper, AXI4StreamUpper}

class v_frmbuf_wr_0 extends BlackBox {
    val mParams = new AXI4Len(64)
    mParams.awid = 0
    mParams.bid = 0
    mParams.arid = 0
    mParams.rid = 0
    val io = IO(new Bundle {
        val ap_clk = Input(Bool())
        val ap_rst_n = Input(Bool())
        val interrupt = Output(Bool())
        val s_axi_CTRL = Flipped(new AXI4LiteUpper)
        val m_axi_mm_video = new AXI4FullUpper(mParams)
        val s_axis_video = Flipped(new AXI4StreamUpper)
    })
}
