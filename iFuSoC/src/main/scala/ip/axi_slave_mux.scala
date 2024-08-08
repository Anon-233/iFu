package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input}
import common.AXI3

class axi_slave_mux extends BlackBox {
    val io = IO(new Bundle {
        val axi_s_aclk = Input(Bool())
        val axi_s_aresetn = Input(Bool())
        val spi_boot = Input(Bool())
        val axi_s = new AXI3
        val s0 = Flipped(new AXI3)
        val s1 = Flipped(new AXI3)
        val s2 = Flipped(new AXI3)
        val s3 = Flipped(new AXI3)
        val s4 = Flipped(new AXI3)
    })
}
