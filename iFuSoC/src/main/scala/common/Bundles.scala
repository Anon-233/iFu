package common

import chisel3.experimental.Analog
import chisel3.{Bool, Bundle, Input, Output, UInt, fromIntToWidth}

class GPIO extends Bundle {
    val led = Output(UInt(16.W))
    val led_rg0 = Output(UInt(2.W))
    val led_rg1 = Output(UInt(2.W))
    val num_csn = Output(UInt(8.W))
    val num_a_g = Output(UInt(7.W))
    val switch = Output(UInt(8.W))
    val btn_key_col = Output(UInt(4.W))
    val btn_key_row = Input(UInt(4.W))
    val btn_step = Input(UInt(2.W))
}

class DDR3 extends Bundle {
    val dq = Analog(16.W)
    val dqs_p = Analog(2.W)
    val dqs_n = Analog(2.W)
    val addr = Output(UInt(13.W))
    val ba = Output(UInt(3.W))
    val ras_n = Output(Bool())
    val cas_n = Output(Bool())
    val we_n = Output(Bool())
    val reset_n = Output(Bool())
    val ck_p = Output(Bool())
    val ck_n = Output(Bool())
    val cke = Output(Bool())
    val dm = Output(UInt(2.W))
    val odt = Output(Bool())
}

class MAC extends Bundle {
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
}

class EJTAG extends Bundle {
    val TRST = Input(Bool())
    val TCK = Input(Bool())
    val TDI = Input(Bool())
    val TMS = Input(Bool())
    val TDO = Output(Bool())
}

class UART extends Bundle {
    val txd_i = Input(Bool())
    val txd_o = Output(Bool())
    val txd_oe = Output(Bool())
    val rxd_i = Input(Bool())
    val rxd_o = Output(Bool())
    val rxd_oe = Output(Bool())
    val rts_o = Output(Bool())
    val dtr_o = Output(Bool())
    val cts_i = Input(Bool())
    val dsr_i = Input(Bool())
    val dcd_i = Input(Bool())
    val ri_i = Input(Bool())
}

class NAND extends Bundle {
    val cle = Output(Bool())
    val ale = Output(Bool())
    val rdy = Input(UInt(4.W))
    val rd = Output(Bool())
    val ce = Output(UInt(4.W))
    val wr = Output(Bool())
    val dat_i = Input(UInt(8.W))
    val dat_o = Output(UInt(8.W))
    val dat_oe = Output(Bool())
}

class SPI extends Bundle {
    val csn_o = Output(UInt(4.W))
    val csn_en = Output(UInt(4.W))
    val sck_o = Output(Bool())
    val sdo_i = Input(Bool())
    val sdo_o = Output(Bool())
    val sdo_en = Output(Bool())
    val sdi_i = Input(Bool())
    val sdi_o = Output(Bool())
    val sdi_en = Output(Bool())
}

class LCD extends Bundle {
    val nrst = Output(Bool())
    val csel = Output(Bool())
    val rs = Output(Bool())
    val wr = Output(Bool())
    val rd = Output(Bool())
    val data_in = Input(UInt(16.W))
    val data_out = Output(UInt(16.W))
    val data_z = Output(UInt(16.W))
}

class PS2 extends Bundle {
    val CLK_i = Input(Bool())
    val CLK_o = Output(Bool())
    val CLK_t = Output(Bool())
    val DAT_i = Input(Bool())
    val DAT_o = Output(Bool())
    val DAT_t = Output(Bool())
}

class TFT extends Bundle {
    val hsync = Output(Bool())
    val vsync = Output(Bool())
    val de = Output(Bool())
    val dps = Output(Bool())
    val vga_clk = Output(Bool())
    val vga_r = Output(UInt(6.W))
    val vga_g = Output(UInt(6.W))
    val vga_b = Output(UInt(6.W))
}
