package ip

import chisel3.{BlackBox, Bool, Bundle, Input, Output}

class clk_wiz_0 extends BlackBox {
    val io = IO(new Bundle {
        val clk_out1 = Output(Bool())
        val clk_in1 = Input(Bool())
    })
}
