package common

import chisel3.{Bundle, Input, Output, UInt, fromIntToWidth}

object AXILen {
    val awid = 4
    val awaddr = 32
    val awlen = 4
    val awsize = 3
    val awburst = 2
    val awlock = 2
    val awcache = 4
    val awprot = 3
    val awvalid = 1
    val awready = 1
    val wid = 4
    val wdata = 32
    val wstrb = 4
    val wlast = 1
    val wvalid = 1
    val wready = 1
    val bid = 4
    val bresp = 2
    val bvalid = 1
    val bready = 1
    val arid = 4
    val araddr = 32
    val arlen = 4
    val arsize = 3
    val arburst = 2
    val arlock = 2
    val arcache = 4
    val arprot = 3
    val arvalid = 1
    val arready = 1
    val rid = 4
    val rdata = 32
    val rresp = 2
    val rlast = 1
    val rvalid = 1
    val rready = 1
}

// TODO: axi3, axi4, axi4lite, axi4stream
class AXI extends Bundle {
    val awid = Input(UInt(AXILen.awid.W))
    val awaddr = Input(UInt(AXILen.awaddr.W))
    val awlen = Input(UInt(AXILen.awlen.W))
    val awsize = Input(UInt(AXILen.awsize.W))
    val awburst = Input(UInt(AXILen.awburst.W))
    val awlock = Input(UInt(AXILen.awlock.W))
    val awcache = Input(UInt(AXILen.awcache.W))
    val awprot = Input(UInt(AXILen.awprot.W))
    val awvalid = Input(UInt(AXILen.awvalid.W))
    val awready = Output(UInt(AXILen.awready.W))
    val wready = Output(UInt(AXILen.wready.W))
    val wid = Input(UInt(AXILen.wid.W))
    val wdata = Input(UInt(AXILen.wdata.W))
    val wstrb = Input(UInt(AXILen.wstrb.W))
    val wlast = Input(UInt(AXILen.wlast.W))
    val wvalid = Input(UInt(AXILen.wvalid.W))
    val bid = Output(UInt(AXILen.bid.W))
    val bresp = Output(UInt(AXILen.bresp.W))
    val bvalid = Output(UInt(AXILen.bvalid.W))
    val bready = Input(UInt(AXILen.bready.W))
    val arid = Input(UInt(AXILen.arid.W))
    val araddr = Input(UInt(AXILen.araddr.W))
    val arlen = Input(UInt(AXILen.arlen.W))
    val arsize = Input(UInt(AXILen.arsize.W))
    val arburst = Input(UInt(AXILen.arburst.W))
    val arlock = Input(UInt(AXILen.arlock.W))
    val arcache = Input(UInt(AXILen.arcache.W))
    val arprot = Input(UInt(AXILen.arprot.W))
    val arvalid = Input(UInt(AXILen.arvalid.W))
    val arready = Output(UInt(AXILen.arready.W))
    val rready = Input(UInt(AXILen.rready.W))
    val rid = Output(UInt(AXILen.rid.W))
    val rdata = Output(UInt(AXILen.rdata.W))
    val rresp = Output(UInt(AXILen.rresp.W))
    val rlast = Output(UInt(AXILen.rlast.W))
    val rvalid = Output(UInt(AXILen.rvalid.W))
}
