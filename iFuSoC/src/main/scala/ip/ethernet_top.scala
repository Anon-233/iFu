package ip

import chisel3.experimental.Analog
import chisel3.{BlackBox, Bool, Bundle, Flipped, Input, Output, UInt, fromIntToWidth}
import common.{AXI3, AXI3Len, MAC}

class ethernet_top extends BlackBox {
    val axiParams = new AXI3Len
    axiParams.awqos = 0
    axiParams.arqos = 0
    val io = IO(new Bundle {
        val hclk = Input(Bool())
        val hrst_ = Input(Bool())
        val m = new AXI3(axiParams)
        val s = Flipped(new AXI3(axiParams))
        val interrupt_0 = Output(Bool())
        val mtxclk_0 = Input(Bool())
        val mtxd_0 = Output(UInt(4.W))
        val mtxen_0 = Output(Bool())
        val mtxerr_0 = Output(Bool())
        val mrxclk_0 = Input(Bool())
        val mrxd_0 = Input(UInt(4.W))
        val mrxdv_0 = Input(Bool())
        val mrxerr_0 = Input(Bool())
        val mcoll_0 = Input(Bool())
        val mcrs_0 = Input(Bool())
        val md_i_0 = Input(Bool())
        val mdc_0 = Output(Bool())
        val md_o_0 = Output(Bool())
        val md_oe_0 = Output(Bool())
    })
}
