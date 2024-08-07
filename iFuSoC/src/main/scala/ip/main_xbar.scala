package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input}
import common.AXI

class main_xbar extends BlackBox {
    val io = IO(new Bundle {
        val aclk = Input(Bool())
        val aresetn = Input(Bool())
        val s_axi = new AXI
        val m0_axi = Flipped(new AXI)
        val m1_axi = Flipped(new AXI)
        
    })
}
