package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input, Output, UInt, fromIntToWidth}
import common.{AXI3, AXI3Len, NAND, UART}

class axi2apb_misc extends BlackBox {
    val axiParams = new AXI3Len
    axiParams.awqos = 0
    axiParams.arqos = 0
    val io = IO(new Bundle {
        val clk = Input(Bool())
        val rst_n = Input(Bool())
        val axi_s = Flipped(new AXI3(axiParams))
        val apb_ready_dma = Output(Bool())
        val apb_rw_dma = Input(Bool())
        val apb_psel_dma = Input(Bool())
        val apb_enab_dma = Input(Bool())
        val apb_addr_dma = Input(UInt(20.W))
        val apb_wdata_dma = Input(UInt(32.W))
        val apb_rdata_dma = Output(UInt(32.W))
        val apb_valid_dma = Input(Bool())
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
