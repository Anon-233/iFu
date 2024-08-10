package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input, Output}
import common.{AXI4Full, AXI4Len, AXI4Lite, TFT}

class axi_tft_0 extends BlackBox {
    val mParams = new AXI4Len
    mParams.awid = 0
    mParams.awlen = 8
    mParams.awlock = 0
    mParams.awqos = 0
    mParams.awregion = 0
    mParams.bid = 0
    mParams.arid = 0
    mParams.arlen = 8
    mParams.arlock = 0
    mParams.arqos = 0
    mParams.arregion = 0
    mParams.rid = 0
    val sParams = new AXI4Len
    sParams.awprot = 0
    sParams.arprot = 0
    val io = IO(new Bundle {
        val md_error = Output(Bool())
        val ip2intc_irpt = Output(Bool())
        val m_axi_aclk = Input(Bool())
        val m_axi_aresetn = Input(Bool())
        val m_axi = new AXI4Full(mParams)
        val s_axi_aclk = Input(Bool())
        val s_axi_aresetn = Input(Bool())
        val s_axi = Flipped(new AXI4Lite(sParams))
        val sys_tft_clk = Input(Bool())
        val tft = new TFT
    })
}
