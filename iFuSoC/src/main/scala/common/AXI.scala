package common

import chisel3.{Bundle, Input, Output, UInt, Wire, fromIntToWidth}

object AXI3Len {
    val awaddr = 32
    val awprot = 3
    val awvalid = 1
    val awready = 1
    val awsize = 3
    val awburst = 2
    val awcache = 4
    val awlen = 4
    val awlock = 2
    val awqos = 4
    val awid = 4
    val wdata = 32
    val wstrb = 4
    val wvalid = 1
    val wready = 1
    val wlast = 1
    val wid = 4
    val bresp = 2
    val bvalid = 1
    val bready = 1
    val bid = 4
    val araddr = 32
    val arprot = 3
    val arvalid = 1
    val arready = 1
    val arsize = 3
    val arburst = 2
    val arcache = 4
    val arlock = 2
    val arlen = 4
    val arqos = 4
    val arid = 4
    val rdata = 32
    val rresp = 2
    val rvalid = 1
    val rready = 1
    val rlast = 1
    val rid = 4
}

object AXI4Len {
    val awaddr = 32
    val awprot = 3
    val awvalid = 1
    val awready = 1
    val awsize = 3
    val awburst = 2
    val awcache = 4
    val awlen = 4
    val awlock = 2
    val awqos = 4
    val awregion = 4
    val awid = 4
    val wdata = 32
    val wstrb = 4
    val wvalid = 1
    val wready = 1
    val wlast = 1
    val bresp = 2
    val bvalid = 1
    val bready = 1
    val bid = 4
    val araddr = 32
    val arprot = 3
    val arvalid = 1
    val arready = 1
    val arsize = 3
    val arburst = 2
    val arcache = 4
    val arlock = 2
    val arlen = 4
    val arqos = 4
    val arregion = 4
    val arid = 4
    val rdata = 32
    val rresp = 2
    val rvalid = 1
    val rready = 1
    val rlast = 1
    val rid = 4
}

object AXI4SLen {
    val valid = 1
    val ready = 1
    val data = 24
    val keep = 3
    val strb = 3
    val user = 1
    val last = 1
    val id = 1
    val dest = 1
}

class AXI3 extends Bundle {
    val awaddr = Output(UInt(AXI3Len.awaddr.W))
    val awprot = Output(UInt(AXI3Len.awprot.W))
    val awvalid = Output(UInt(AXI3Len.awvalid.W))
    val awready = Input(UInt(AXI3Len.awready.W))
    val awsize = Output(UInt(AXI3Len.awsize.W))
    val awburst = Output(UInt(AXI3Len.awburst.W))
    val awcache = Output(UInt(AXI3Len.awcache.W))
    val awlen = Output(UInt(AXI3Len.awlen.W))
    val awlock = Output(UInt(AXI3Len.awlock.W))
    val awqos = Output(UInt(AXI3Len.awqos.W))
    val awid = Output(UInt(AXI3Len.awid.W))
    val wdata = Output(UInt(AXI3Len.wdata.W))
    val wstrb = Output(UInt(AXI3Len.wstrb.W))
    val wvalid = Output(UInt(AXI3Len.wvalid.W))
    val wready = Input(UInt(AXI3Len.wready.W))
    val wlast = Output(UInt(AXI3Len.wlast.W))
    val wid = Output(UInt(AXI3Len.wid.W))
    val bresp = Input(UInt(AXI3Len.bresp.W))
    val bvalid = Input(UInt(AXI3Len.bvalid.W))
    val bready = Output(UInt(AXI3Len.bready.W))
    val bid = Input(UInt(AXI3Len.bid.W))
    val araddr = Output(UInt(AXI3Len.araddr.W))
    val arprot = Output(UInt(AXI3Len.arprot.W))
    val arvalid = Output(UInt(AXI3Len.arvalid.W))
    val arready = Input(UInt(AXI3Len.arready.W))
    val arsize = Output(UInt(AXI3Len.arsize.W))
    val arburst = Output(UInt(AXI3Len.arburst.W))
    val arcache = Output(UInt(AXI3Len.arcache.W))
    val arlock = Output(UInt(AXI3Len.arlock.W))
    val arlen = Output(UInt(AXI3Len.arlen.W))
    val arqos = Output(UInt(AXI3Len.arqos.W))
    val arid = Output(UInt(AXI3Len.arid.W))
    val rdata = Input(UInt(AXI3Len.rdata.W))
    val rresp = Input(UInt(AXI3Len.rresp.W))
    val rvalid = Input(UInt(AXI3Len.rvalid.W))
    val rready = Output(UInt(AXI3Len.rready.W))
    val rlast = Input(UInt(AXI3Len.rlast.W))
    val rid = Input(UInt(AXI3Len.rid.W))
}

class AXI4Full extends Bundle {
    val awaddr = Output(UInt(AXI4Len.awaddr.W))
    val awprot = Output(UInt(AXI4Len.awprot.W))
    val awvalid = Output(UInt(AXI4Len.awvalid.W))
    val awready = Input(UInt(AXI4Len.awready.W))
    val awsize = Output(UInt(AXI4Len.awsize.W))
    val awburst = Output(UInt(AXI4Len.awburst.W))
    val awcache = Output(UInt(AXI4Len.awcache.W))
    val awlen = Output(UInt(AXI4Len.awlen.W))
    val awlock = Output(UInt(AXI4Len.awlock.W))
    val awqos = Output(UInt(AXI4Len.awqos.W))
    val awregion = Output(UInt(AXI4Len.awregion.W))
    val awid = Output(UInt(AXI4Len.awid.W))
    val wdata = Output(UInt(AXI4Len.wdata.W))
    val wstrb = Output(UInt(AXI4Len.wstrb.W))
    val wvalid = Output(UInt(AXI4Len.wvalid.W))
    val wready = Input(UInt(AXI4Len.wready.W))
    val wlast = Output(UInt(AXI4Len.wlast.W))
    val bresp = Input(UInt(AXI4Len.bresp.W))
    val bvalid = Input(UInt(AXI4Len.bvalid.W))
    val bready = Output(UInt(AXI4Len.bready.W))
    val bid = Input(UInt(AXI4Len.bid.W))
    val araddr = Output(UInt(AXI4Len.araddr.W))
    val arprot = Output(UInt(AXI4Len.arprot.W))
    val arvalid = Output(UInt(AXI4Len.arvalid.W))
    val arready = Input(UInt(AXI4Len.arready.W))
    val arsize = Output(UInt(AXI4Len.arsize.W))
    val arburst = Output(UInt(AXI4Len.arburst.W))
    val arcache = Output(UInt(AXI4Len.arcache.W))
    val arlock = Output(UInt(AXI4Len.arlock.W))
    val arlen = Output(UInt(AXI4Len.arlen.W))
    val arqos = Output(UInt(AXI4Len.arqos.W))
    val arregion = Output(UInt(AXI4Len.arregion.W))
    val arid = Output(UInt(AXI4Len.arid.W))
    val rdata = Input(UInt(AXI4Len.rdata.W))
    val rresp = Input(UInt(AXI4Len.rresp.W))
    val rvalid = Input(UInt(AXI4Len.rvalid.W))
    val rready = Output(UInt(AXI4Len.rready.W))
    val rlast = Input(UInt(AXI4Len.rlast.W))
    val rid = Input(UInt(AXI4Len.rid.W))
}

class AXI4FullUpper extends Bundle {
    val AWADDR = Output(UInt(AXI4Len.awaddr.W))
    val AWPROT = Output(UInt(AXI4Len.awprot.W))
    val AWVALID = Output(UInt(AXI4Len.awvalid.W))
    val AWREADY = Input(UInt(AXI4Len.awready.W))
    val AWSIZE = Output(UInt(AXI4Len.awsize.W))
    val AWBURST = Output(UInt(AXI4Len.awburst.W))
    val AWCACHE = Output(UInt(AXI4Len.awcache.W))
    val AWLEN = Output(UInt(AXI4Len.awlen.W))
    val AWLOCK = Output(UInt(AXI4Len.awlock.W))
    val AWQOS = Output(UInt(AXI4Len.awqos.W))
    val AWREGION = Output(UInt(AXI4Len.awregion.W))
    val AWID = Output(UInt(AXI4Len.awid.W))
    val WDATA = Output(UInt(AXI4Len.wdata.W))
    val WSTRB = Output(UInt(AXI4Len.wstrb.W))
    val WVALID = Output(UInt(AXI4Len.wvalid.W))
    val WREADY = Input(UInt(AXI4Len.wready.W))
    val WLAST = Output(UInt(AXI4Len.wlast.W))
    val BRESP = Input(UInt(AXI4Len.bresp.W))
    val BVALID = Input(UInt(AXI4Len.bvalid.W))
    val BREADY = Output(UInt(AXI4Len.bready.W))
    val BID = Input(UInt(AXI4Len.bid.W))
    val ARADDR = Output(UInt(AXI4Len.araddr.W))
    val ARPROT = Output(UInt(AXI4Len.arprot.W))
    val ARVALID = Output(UInt(AXI4Len.arvalid.W))
    val ARREADY = Input(UInt(AXI4Len.arready.W))
    val ARSIZE = Output(UInt(AXI4Len.arsize.W))
    val ARBURST = Output(UInt(AXI4Len.arburst.W))
    val ARCACHE = Output(UInt(AXI4Len.arcache.W))
    val ARLOCK = Output(UInt(AXI4Len.arlock.W))
    val ARLEN = Output(UInt(AXI4Len.arlen.W))
    val ARQOS = Output(UInt(AXI4Len.arqos.W))
    val ARREGION = Output(UInt(AXI4Len.arregion.W))
    val ARID = Output(UInt(AXI4Len.arid.W))
    val RDATA = Input(UInt(AXI4Len.rdata.W))
    val RRESP = Input(UInt(AXI4Len.rresp.W))
    val RVALID = Input(UInt(AXI4Len.rvalid.W))
    val RREADY = Output(UInt(AXI4Len.rready.W))
    val RLAST = Input(UInt(AXI4Len.rlast.W))
    val RID = Input(UInt(AXI4Len.rid.W))
    
    def toLower: AXI4Full = {
        val copy = Wire(new AXI4Full)
        copy.elements.foreach { case (name, data) =>
            data <> elements(name.toUpperCase)
        }
        copy
    }
}

class AXI4Lite extends Bundle {
    val awaddr = Output(UInt(AXI4Len.awaddr.W))
    val awprot = Output(UInt(AXI4Len.awprot.W))
    val awvalid = Output(UInt(AXI4Len.awvalid.W))
    val awready = Input(UInt(AXI4Len.awready.W))
    val wdata = Output(UInt(AXI4Len.wdata.W))
    val wstrb = Output(UInt(AXI4Len.wstrb.W))
    val wvalid = Output(UInt(AXI4Len.wvalid.W))
    val wready = Input(UInt(AXI4Len.wready.W))
    val bresp = Input(UInt(AXI4Len.bresp.W))
    val bvalid = Input(UInt(AXI4Len.bvalid.W))
    val bready = Output(UInt(AXI4Len.bready.W))
    val araddr = Output(UInt(AXI4Len.araddr.W))
    val arprot = Output(UInt(AXI4Len.arprot.W))
    val arvalid = Output(UInt(AXI4Len.arvalid.W))
    val arready = Input(UInt(AXI4Len.arready.W))
    val rdata = Input(UInt(AXI4Len.rdata.W))
    val rresp = Input(UInt(AXI4Len.rresp.W))
    val rvalid = Input(UInt(AXI4Len.rvalid.W))
    val rready = Output(UInt(AXI4Len.rready.W))
}

class AXI4LiteUpper extends Bundle {
    val AWADDR = Output(UInt(AXI4Len.awaddr.W))
    val AWPROT = Output(UInt(AXI4Len.awprot.W))
    val AWVALID = Output(UInt(AXI4Len.awvalid.W))
    val AWREADY = Input(UInt(AXI4Len.awready.W))
    val WDATA = Output(UInt(AXI4Len.wdata.W))
    val WSTRB = Output(UInt(AXI4Len.wstrb.W))
    val WVALID = Output(UInt(AXI4Len.wvalid.W))
    val WREADY = Input(UInt(AXI4Len.wready.W))
    val BRESP = Input(UInt(AXI4Len.bresp.W))
    val BVALID = Input(UInt(AXI4Len.bvalid.W))
    val BREADY = Output(UInt(AXI4Len.bready.W))
    val ARADDR = Output(UInt(AXI4Len.araddr.W))
    val ARPROT = Output(UInt(AXI4Len.arprot.W))
    val ARVALID = Output(UInt(AXI4Len.arvalid.W))
    val ARREADY = Input(UInt(AXI4Len.arready.W))
    val RDATA = Input(UInt(AXI4Len.rdata.W))
    val RRESP = Input(UInt(AXI4Len.rresp.W))
    val RVALID = Input(UInt(AXI4Len.rvalid.W))
    val RREADY = Output(UInt(AXI4Len.rready.W))
    
    def toLower: AXI4Lite = {
        val copy = Wire(new AXI4Lite)
        copy.elements.foreach { case (name, data) =>
            data <> elements(name.toUpperCase)
        }
        copy
    }
}

class AXI4StreamUpper extends Bundle {
    val TVALID = Output(UInt(AXI4SLen.valid.W))
    val TREADY = Input(UInt(AXI4SLen.ready.W))
    val TDATA = Output(UInt(AXI4SLen.data.W))
    val TKEEP = Output(UInt(AXI4SLen.keep.W))
    val TSTRB = Output(UInt(AXI4SLen.strb.W))
    val TUSER = Output(UInt(AXI4SLen.user.W))
    val TLAST = Output(UInt(AXI4SLen.last.W))
    val TID = Output(UInt(AXI4SLen.id.W))
    val TDEST = Output(UInt(AXI4SLen.dest.W))
}
