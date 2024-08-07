package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input, Output}
import common.AXI

class axi_interconnect_0 extends BlackBox {
    val io = IO(new Bundle {
        val INTERCONNECT_ACLK = Input(Bool())
        val INTERCONNECT_ARESETN = Input(Bool())
        val s00_axi_areset_out_n = Output(Bool())
        val s00_axi_aclk = Output(Bool())
        val s00_axi = new AXI
        val s01_axi_areset_out_n = Output(Bool())
        val s01_axi_aclk = Output(Bool())
        val s01_axi = new AXI
        val s02_axi_areset_out_n = Output(Bool())
        val s02_axi_aclk = Output(Bool())
        val s02_axi = new AXI
        val s03_axi_areset_out_n = Output(Bool())
        val s03_axi_aclk = Output(Bool())
        val s03_axi = new AXI
        val s04_axi_areset_out_n = Output(Bool())
        val s04_axi_aclk = Output(Bool())
        val s04_axi = new AXI
        val s05_axi_areset_out_n = Output(Bool())
        val s05_axi_aclk = Output(Bool())
        val s05_axi = new AXI
        val s06_axi_areset_out_n = Output(Bool())
        val s06_axi_aclk = Output(Bool())
        val s06_axi = new AXI
        val m00_axi_areset_out_n = Output(Bool())
        val m00_axi = Flipped(new AXI)
    })
}
