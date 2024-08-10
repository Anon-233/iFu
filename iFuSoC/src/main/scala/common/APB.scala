package common

import chisel3.{Bool, Bundle, Input, Output, UInt, Wire, fromIntToWidth}

class APB3 extends Bundle {
    val paddr = Output(UInt(32.W))
    val psel = Output(Bool())
    val penable = Output(Bool())
    val pwrite = Output(Bool())
    val pwdata = Output(UInt(32.W))
    val pready = Input(Bool())
    val prdata = Input(UInt(32.W))
    val pslverr = Input(Bool())
}

class APB4(width: Int) extends Bundle {
    assert(width == 1 || width == 2)
    val paddr = Output(UInt(32.W))
    val psel = Output(UInt(width.W))
    val penable = Output(Bool())
    val pwrite = Output(Bool())
    val pwdata = Output(UInt(32.W))
    val pready = Input(UInt(width.W))
    val prdata = Input(UInt(32.W))
    val prdata2 = if (width == 2) Input(UInt(32.W)) else Input(UInt(0.W))
    val pslverr = Input(UInt(width.W))
    val pprot = Output(UInt(3.W))
    val pstrb = Output(UInt(4.W))
}
