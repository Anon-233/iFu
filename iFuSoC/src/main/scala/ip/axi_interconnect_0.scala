package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input, Output}
import common.{AXI3, AXI4FullUpper, AXI4Len}

class axi_interconnect_0 extends BlackBox {
    val mParams = new AXI4Len
    mParams.awid = 8
    mParams.bid = 8
    mParams.arid = 8
    mParams.rid = 8
    val io = IO(new Bundle {
        val INTERCONNECT_ACLK = Input(Bool())
        val INTERCONNECT_ARESETN = Input(Bool())
        val S00_AXI_ARESET_OUT_N = Output(Bool())
        val S00_AXI_ACLK = Input(Bool())
        val S00_AXI = Flipped(new AXI4FullUpper)
        val S01_AXI_ARESET_OUT_N = Output(Bool())
        val S01_AXI_ACLK = Input(Bool())
        val S01_AXI = Flipped(new AXI4FullUpper)
        val S02_AXI_ARESET_OUT_N = Output(Bool())
        val S02_AXI_ACLK = Input(Bool())
        val S02_AXI = Flipped(new AXI4FullUpper(new AXI4Len(64)))
        val S03_AXI_ARESET_OUT_N = Output(Bool())
        val S03_AXI_ACLK = Input(Bool())
        val S03_AXI = Flipped(new AXI4FullUpper)
        val S04_AXI_ARESET_OUT_N = Output(Bool())
        val S04_AXI_ACLK = Input(Bool())
        val S04_AXI = Flipped(new AXI4FullUpper)
        val S05_AXI_ARESET_OUT_N = Output(Bool())
        val S05_AXI_ACLK = Input(Bool())
        val S05_AXI = Flipped(new AXI4FullUpper(new AXI4Len(64)))
        val S06_AXI_ARESET_OUT_N = Output(Bool())
        val S06_AXI_ACLK = Input(Bool())
        val S06_AXI = Flipped(new AXI4FullUpper(new AXI4Len(64)))
        val M00_AXI_ARESET_OUT_N = Output(Bool())
        val M00_AXI_ACLK = Input(Bool())
        val M00_AXI = new AXI4FullUpper(mParams)
    })
}
