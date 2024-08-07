package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input}
import common.{APB4, LCD}

class nt35510 extends BlackBox {
    val io = IO(new Bundle {
        val nrst = Input(Bool())
        val clk = Input(Bool())
        val APB = Flipped(new APB4(1))
        val LCD = new LCD
    })
}
