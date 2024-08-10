package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input, Output, UInt, fromIntToWidth}
import common.{AXI3, AXI3Len, GPIO}

class confreg extends BlackBox {
    val axiParams = new AXI3Len
    axiParams.awqos = 0
    axiParams.arqos = 0
    val io = IO(new Bundle {
        val aclk = Input(Bool())
        val aresetn = Input(Bool())
        val s = Flipped(new AXI3(axiParams))
        val order_addr_reg = Output(UInt(32.W))
        val write_dma_end = Input(Bool())
        val finish_read_order = Input(Bool())
        val cr00 = Output(UInt(32.W))
        val cr01 = Output(UInt(32.W))
        val cr02 = Output(UInt(32.W))
        val cr03 = Output(UInt(32.W))
        val cr04 = Output(UInt(32.W))
        val cr05 = Output(UInt(32.W))
        val cr06 = Output(UInt(32.W))
        val cr07 = Output(UInt(32.W))
        val led = Output(UInt(16.W))
        val led_rg0 = Output(UInt(2.W))
        val led_rg1 = Output(UInt(2.W))
        val num_csn = Output(UInt(8.W))
        val num_a_g = Output(UInt(7.W))
        val switch = Output(UInt(8.W))
        val btn_key_col = Output(UInt(4.W))
        val btn_key_row = Input(UInt(4.W))
        val btn_step = Input(UInt(2.W))
        val vga_reg = Output(UInt(32.W))
    })
}
