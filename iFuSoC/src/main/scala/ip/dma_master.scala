package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input, Output, UInt, fromIntToWidth}
import common.{APB2, AXI}

class dma_master extends BlackBox {
    val io = IO(new Bundle {
        val clk = Input(Bool())
        val rst_n = Input(Bool())
        val axi = Flipped(new AXI)
        val dma_int = Output(Bool())
        val dma_ack_out = Output(Bool())
        val order_addr_in = Input(UInt(32.W))
        val dma_req_in = Input(Bool())
        val dma_gnt = Input(Bool())
        val finish_read_order = Output(Bool())
        val write_dma_end = Output(Bool())
        val apb = new APB2
    })
}
