package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input, Output}
import common.{AXI, TFT}

class axi_tft_0 extends BlackBox {
    val io = IO(new Bundle {
        val md_error = Output(Bool())
        val ip2intc_irpt = Output(Bool())
        val m_axi_clk = Input(Bool())
        val m_axi_aresetn = Input(Bool())
        val m_axi = Flipped(new AXI)
        val s_axi_clk = Input(Bool())
        val s_axi_aresetn = Input(Bool())
        val s_axi = new AXI
        val sys_tft_clk = Input(Bool())
        val tft = new TFT
    })
}
