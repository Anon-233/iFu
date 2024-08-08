package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input, Output, UInt, fromIntToWidth}
import common.{AXI3, GPIO}

class confreg extends BlackBox {
    val io = IO(new Bundle {
        val aclk = Input(Bool())
        val aresetn = Input(Bool())
        val s = Flipped(new AXI3)
        val order_addr_reg = Input(UInt(32.W))
        val write_dma_end = Input(Bool())
        val finish_read_order = Output(Bool())
        val cr00 = Output(UInt(32.W))
        val cr01 = Output(UInt(32.W))
        val cr02 = Output(UInt(32.W))
        val cr03 = Output(UInt(32.W))
        val cr04 = Output(UInt(32.W))
        val cr05 = Output(UInt(32.W))
        val cr06 = Output(UInt(32.W))
        val cr07 = Output(UInt(32.W))
        val gpio = new GPIO
        val vga_reg = Output(UInt(32.W))
    })
}
