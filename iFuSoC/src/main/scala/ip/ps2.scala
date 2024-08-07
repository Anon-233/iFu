package ip

import chisel3.{BlackBox, Bool, Bundle, Input, Output, UInt, fromIntToWidth}
import common.PS2

class ps2 extends BlackBox {
    val io = IO(new Bundle {
        val clk = Input(Bool())
        val reset_n = Input(Bool())
        val paddr = Input(UInt(4.W))
        val penable = Input(Bool())
        val psel = Input(Bool())
        val byteenable = Input(UInt(4.W))
        val write = Input(Bool())
        val writedata = Input(UInt(32.W))
        val perr = Output(Bool())
        val PS2 = new PS2
        val irq = Output(Bool())
        val readdata = Output(UInt(32.W))
        val waitrequest_n = Output(Bool())
    })
}
