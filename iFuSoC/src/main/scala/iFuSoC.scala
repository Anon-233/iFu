package iFu

import chisel3._
import chisel3.experimental.Analog

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
    val addr = Output(UInt(13.W))
    val ba = Output(UInt(2.W))
    val ras_n = Output(Bool())
    val cas_n = Output(Bool())
    val we_n = Output(Bool())
    val odt = Output(Bool())
    val reset_n = Output(Bool())
    val cke = Output(Bool())
    val dm = Output(UInt(2.W))
    val dqs_p = Input(UInt(2.W))
    val dqs_n = Input(UInt(2.W))
    val ck_p = Output(Bool())
    val ck_n = Output(Bool())
}

class TX extends Bundle {
    val mtxclk_0 = Input(Bool())
    val mtxen_0 = Output(Bool())
    val mtxd_0 = Output(UInt(4.W))
    val mtxerr_0 = Output(Bool())
}

class RX extends Bundle {
    val mrxclk_0 = Input(Bool())
    val mrxdv_0 = Input(Bool())
    val mrxd_0 = Input(UInt(4.W))
    val mrxerr_0 = Input(Bool())
    val mcoll_0 = Input(Bool())
    val mcrs_0 = Input(Bool())
}

class MIIM extends Bundle {
    val mdc_0 = Output(Bool())
    val mdio_0 = Analog(1.W)
}

class MAC extends Bundle {
    val tx = new TX
    val rx = new RX
    val miim = new MIIM
    val phy_rstn = Output(Bool())
}

class EJTAG extends Bundle {
    val TRST = Input(Bool())
    val TCK = Input(Bool())
    val TDI = Input(Bool())
    val TMS = Input(Bool())
    val TDO = Output(Bool())
}

class UART extends Bundle {
    val RX = Analog(1.W)
    val TX = Analog(1.W)
}

class NAND extends Bundle {
    val CLE = Output(Bool())
    val ALE = Output(Bool())
    val RDY = Input(Bool())
    val DATA = Analog(8.W)
    val RD = Output(Bool())
    val CE = Output(Bool())
    val WR = Output(Bool())
}

class SPI extends Bundle {
    val CLK = Output(Bool())
    val CS = Output(Bool())
    val MISO = Analog(1.W)
    val MOSI = Analog(1.W)
}

class LCD extends Bundle {
    val csel = Output(Bool())
    val data_tri_io = Analog(16.W)
    val nrst = Output(Bool())
    val rd = Output(Bool())
    val rs = Output(Bool())
    val wr = Output(Bool())
    val lighton = Output(Bool())
}

class PS2 extends Bundle {
    val clk_tri_io = Analog(1.W)
    val dat_tri_io = Analog(1.W)
}

class VGA extends Bundle {
    val r = Analog(4.W)
    val g = Analog(4.W)
    val b = Analog(4.W)
    val hsync = Output(Bool())
    val vsync = Output(Bool())
}

class iFuSoC extends Module {
    val io = IO(new Bundle {
        val gpio = new GPIO
        val ddr3 = new DDR3
        val mac = new MAC
        val ejtag = new EJTAG
        val uart = new UART
        val nand = new NAND
        val spi = new SPI
        val lcd = new LCD
        val ps2 = new PS2
        val vga = new VGA
    })
    io := DontCare
}
