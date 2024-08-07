package ip

import chisel3.{BlackBox, Bool, Bundle, Input, Output, UInt, fromIntToWidth}
import common.AXI

class spi_flash_ctrl extends BlackBox {
    val io = IO(new Bundle {
        val aclk = Input(Bool())
        val aresetn = Input(Bool())
        val spi_addr = Input(UInt(16.W))
        val fast_wakeup = Input(Bool())
        val s = new AXI
        val power_down_req = Input(Bool())
        val power_down_ack = Input(Bool())
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
