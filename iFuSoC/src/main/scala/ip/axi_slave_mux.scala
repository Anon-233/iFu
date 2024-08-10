package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input}
import common.{AXI3, AXI3Len}

class axi_slave_mux extends BlackBox {
    val axiParams = new AXI3Len
    axiParams.awqos = 0
    axiParams.arqos = 0
    val io = IO(new Bundle {
        val axi_s_aclk = Input(Bool())
        val axi_s_aresetn = Input(Bool())
        val spi_boot = Input(Bool())
        val axi_s = Flipped(new AXI3(axiParams))
        val s0 = new AXI3(axiParams)
        val s1 = new AXI3(axiParams)
        val s2 = new AXI3(axiParams)
        val s3 = new AXI3(axiParams)
        val s4 = new AXI3(axiParams)
    })
}
