package ip

import chisel3.{BlackBox, Bool, Bundle, Input, Output}

class clk_pll_33 extends BlackBox {
    val io = IO(new Bundle {
        val clk_out1 = Output(Bool())
        val clk_out2 = Output(Bool())
        val clk_100 = Output(Bool())
        val clk_25 = Output(Bool())
        val clk_in1 = Input(Bool())
        val resetn = Input(Bool())
        val locked = Output(Bool())
    })
}
