package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input, Output, UInt, fromIntToWidth}
import common.{APB2, AXI3, NAND, UART}

class axi2apb_misc extends BlackBox {
    val io = IO(new Bundle {
        val clk = Input(Bool())
        val rst_n = Input(Bool())
        val axi_s = Flipped(new AXI3)
        val apb = Flipped(new APB2)
        val apb_ready_dma = Output(Bool())
        val dma_grant = Output(Bool())
        val dma_req_o = Output(Bool())
        val dma_ack_i = Input(Bool())
        val uart0 = new UART
        val uart0_int = Output(Bool())
        val nand_type = Input(UInt(2.W))
        val nand = new NAND
        val nand_int = Output(Bool())
    })
}
