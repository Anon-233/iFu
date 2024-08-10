package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input, Output, UInt, fromIntToWidth}
import common.{AXI3, AXI3Len}

class spi_flash_ctrl extends BlackBox {
    val axiParams = new AXI3Len
    axiParams.awqos = 0
    axiParams.arqos = 0
    val io = IO(new Bundle {
        val aclk = Input(Bool())
        val aresetn = Input(Bool())
        val spi_addr = Input(UInt(16.W))
        val fast_startup = Input(Bool())
        val s = Flipped(new AXI3(axiParams))
        val power_down_req = Input(Bool())
        val power_down_ack = Output(Bool())
        val csn_o = Output(UInt(4.W))
        val csn_en = Output(UInt(4.W))
        val sck_o = Output(Bool())
        val sdo_i = Input(Bool())
        val sdo_o = Output(Bool())
        val sdo_en = Output(Bool())
        val sdi_i = Input(Bool())
        val sdi_o = Output(Bool())
        val sdi_en = Output(Bool())
        val inta_o = Output(Bool())
    })
}
