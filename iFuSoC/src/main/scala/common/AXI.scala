package common

import chisel3.reflect.DataMirror
import chisel3.util.Cat
import chisel3.{ActualDirection, Bundle, Data, Input, Output, UInt, Wire, fromIntToLiteral, fromIntToWidth}

object AssignZero {
    def apply(data: Data): Unit = {
        if (DataMirror.directionOf(data) == ActualDirection.Input) {
            data := 0.U.asTypeOf(data)
        }
    }
}

class AXI3Len(dataWidth: Int = 32) {
    assert(dataWidth == 32 || dataWidth == 64)
    var width = dataWidth
    var byteNum = dataWidth / 8
    var awaddr = 32
    var awprot = 3
    var awvalid = 1
    var awready = 1
    var awsize = 3
    var awburst = 2
    var awcache = 4
    var awlen = byteNum
    var awlock = 2
    var awqos = 4
    var awid = 4
    var wdata = dataWidth
    var wstrb = byteNum
    var wvalid = 1
    var wready = 1
    var wlast = 1
    var wid = 4
    var bresp = 2
    var bvalid = 1
    var bready = 1
    var bid = 4
    var araddr = 32
    var arprot = 3
    var arvalid = 1
    var arready = 1
    var arsize = 3
    var arburst = 2
    var arcache = 4
    var arlock = 2
    var arlen = byteNum
    var arqos = 4
    var arid = 4
    var rdata = dataWidth
    var rresp = 2
    var rvalid = 1
    var rready = 1
    var rlast = 1
    var rid = 4
    
    def double: AXI3Len = {
        val newParam = new AXI3Len
        getClass.getDeclaredFields.foreach(f => {
            if (f.getType.getName == "int") {
                val old = f.getInt(newParam)
                f.setInt(newParam, old * 2)
            }
        })
        newParam
    }
}

class AXI4Len(dataWidth: Int = 32) {
    assert(dataWidth == 32 || dataWidth == 64)
    var width = dataWidth
    var byteNum = dataWidth / 8
    var awaddr = 32
    var awprot = 3
    var awvalid = 1
    var awready = 1
    var awsize = 3
    var awburst = 2
    var awcache = 4
    var awlen = byteNum
    var awlock = 2
    var awqos = 4
    var awregion = 4
    var awid = 4
    var wdata = dataWidth
    var wstrb = byteNum
    var wvalid = 1
    var wready = 1
    var wlast = 1
    var bresp = 2
    var bvalid = 1
    var bready = 1
    var bid = 4
    var araddr = 32
    var arprot = 3
    var arvalid = 1
    var arready = 1
    var arsize = 3
    var arburst = 2
    var arcache = 4
    var arlock = 2
    var arlen = byteNum
    var arqos = 4
    var arregion = 4
    var arid = 4
    var rdata = dataWidth
    var rresp = 2
    var rvalid = 1
    var rready = 1
    var rlast = 1
    var rid = 4
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

class AXI3(len: AXI3Len = new AXI3Len) extends Bundle {
    val awaddr = Output(UInt(len.awaddr.W))
    val awprot = Output(UInt(len.awprot.W))
    val awvalid = Output(UInt(len.awvalid.W))
    val awready = Input(UInt(len.awready.W))
    val awsize = Output(UInt(len.awsize.W))
    val awburst = Output(UInt(len.awburst.W))
    val awcache = Output(UInt(len.awcache.W))
    val awlen = Output(UInt(len.awlen.W))
    val awlock = Output(UInt(len.awlock.W))
    val awqos = Output(UInt(len.awqos.W))
    val awid = Output(UInt(len.awid.W))
    val wdata = Output(UInt(len.wdata.W))
    val wstrb = Output(UInt(len.wstrb.W))
    val wvalid = Output(UInt(len.wvalid.W))
    val wready = Input(UInt(len.wready.W))
    val wlast = Output(UInt(len.wlast.W))
    val wid = Output(UInt(len.wid.W))
    val bresp = Input(UInt(len.bresp.W))
    val bvalid = Input(UInt(len.bvalid.W))
    val bready = Output(UInt(len.bready.W))
    val bid = Input(UInt(len.bid.W))
    val araddr = Output(UInt(len.araddr.W))
    val arprot = Output(UInt(len.arprot.W))
    val arvalid = Output(UInt(len.arvalid.W))
    val arready = Input(UInt(len.arready.W))
    val arsize = Output(UInt(len.arsize.W))
    val arburst = Output(UInt(len.arburst.W))
    val arcache = Output(UInt(len.arcache.W))
    val arlock = Output(UInt(len.arlock.W))
    val arlen = Output(UInt(len.arlen.W))
    val arqos = Output(UInt(len.arqos.W))
    val arid = Output(UInt(len.arid.W))
    val rdata = Input(UInt(len.rdata.W))
    val rresp = Input(UInt(len.rresp.W))
    val rvalid = Input(UInt(len.rvalid.W))
    val rready = Output(UInt(len.rready.W))
    val rlast = Input(UInt(len.rlast.W))
    val rid = Input(UInt(len.rid.W))
    
    def zip(that: AXI3): AXI3 = {
        val result = Wire(new AXI3(len.double))
        elements.foreach{ case (name, data) =>
            val thatData = that.elements(name)
            val resData = result.elements(name)
            val width = data.getWidth
            if (DataMirror.directionOf(data) == ActualDirection.Input) {
                data := resData.asUInt(2 * width - 1, width)
                thatData := resData.asUInt(width - 1, 0)
            } else {
                resData := Cat(data.asUInt, thatData.asUInt)
            }
        }
        result
    }
}

class AXI4Full(len: AXI4Len = new AXI4Len) extends Bundle {
    val awaddr = Output(UInt(len.awaddr.W))
    val awprot = Output(UInt(len.awprot.W))
    val awvalid = Output(UInt(len.awvalid.W))
    val awready = Input(UInt(len.awready.W))
    val awsize = Output(UInt(len.awsize.W))
    val awburst = Output(UInt(len.awburst.W))
    val awcache = Output(UInt(len.awcache.W))
    val awlen = Output(UInt(len.awlen.W))
    val awlock = Output(UInt(len.awlock.W))
    val awqos = Output(UInt(len.awqos.W))
    val awregion = Output(UInt(len.awregion.W))
    val awid = Output(UInt(len.awid.W))
    val wdata = Output(UInt(len.wdata.W))
    val wstrb = Output(UInt(len.wstrb.W))
    val wvalid = Output(UInt(len.wvalid.W))
    val wready = Input(UInt(len.wready.W))
    val wlast = Output(UInt(len.wlast.W))
    val bresp = Input(UInt(len.bresp.W))
    val bvalid = Input(UInt(len.bvalid.W))
    val bready = Output(UInt(len.bready.W))
    val bid = Input(UInt(len.bid.W))
    val araddr = Output(UInt(len.araddr.W))
    val arprot = Output(UInt(len.arprot.W))
    val arvalid = Output(UInt(len.arvalid.W))
    val arready = Input(UInt(len.arready.W))
    val arsize = Output(UInt(len.arsize.W))
    val arburst = Output(UInt(len.arburst.W))
    val arcache = Output(UInt(len.arcache.W))
    val arlock = Output(UInt(len.arlock.W))
    val arlen = Output(UInt(len.arlen.W))
    val arqos = Output(UInt(len.arqos.W))
    val arregion = Output(UInt(len.arregion.W))
    val arid = Output(UInt(len.arid.W))
    val rdata = Input(UInt(len.rdata.W))
    val rresp = Input(UInt(len.rresp.W))
    val rvalid = Input(UInt(len.rvalid.W))
    val rready = Output(UInt(len.rready.W))
    val rlast = Input(UInt(len.rlast.W))
    val rid = Input(UInt(len.rid.W))
}

class AXI4FullUpper(len: AXI4Len = new AXI4Len) extends Bundle {
    val AWADDR = Output(UInt(len.awaddr.W))
    val AWPROT = Output(UInt(len.awprot.W))
    val AWVALID = Output(UInt(len.awvalid.W))
    val AWREADY = Input(UInt(len.awready.W))
    val AWSIZE = Output(UInt(len.awsize.W))
    val AWBURST = Output(UInt(len.awburst.W))
    val AWCACHE = Output(UInt(len.awcache.W))
    val AWLEN = Output(UInt(len.awlen.W))
    val AWLOCK = Output(UInt(len.awlock.W))
    val AWQOS = Output(UInt(len.awqos.W))
    val AWREGION = Output(UInt(len.awregion.W))
    val AWID = Output(UInt(len.awid.W))
    val WDATA = Output(UInt(len.wdata.W))
    val WSTRB = Output(UInt(len.wstrb.W))
    val WVALID = Output(UInt(len.wvalid.W))
    val WREADY = Input(UInt(len.wready.W))
    val WLAST = Output(UInt(len.wlast.W))
    val BRESP = Input(UInt(len.bresp.W))
    val BVALID = Input(UInt(len.bvalid.W))
    val BREADY = Output(UInt(len.bready.W))
    val BID = Input(UInt(len.bid.W))
    val ARADDR = Output(UInt(len.araddr.W))
    val ARPROT = Output(UInt(len.arprot.W))
    val ARVALID = Output(UInt(len.arvalid.W))
    val ARREADY = Input(UInt(len.arready.W))
    val ARSIZE = Output(UInt(len.arsize.W))
    val ARBURST = Output(UInt(len.arburst.W))
    val ARCACHE = Output(UInt(len.arcache.W))
    val ARLOCK = Output(UInt(len.arlock.W))
    val ARLEN = Output(UInt(len.arlen.W))
    val ARQOS = Output(UInt(len.arqos.W))
    val ARREGION = Output(UInt(len.arregion.W))
    val ARID = Output(UInt(len.arid.W))
    val RDATA = Input(UInt(len.rdata.W))
    val RRESP = Input(UInt(len.rresp.W))
    val RVALID = Input(UInt(len.rvalid.W))
    val RREADY = Output(UInt(len.rready.W))
    val RLAST = Input(UInt(len.rlast.W))
    val RID = Input(UInt(len.rid.W))
    
    def toLower: AXI4Full = {
        val copy = Wire(new AXI4Full(len))
        copy.elements.foreach { case (name, data) =>
            data <> elements(name.toUpperCase)
        }
        copy
    }
    
    def toLowerAXI3: AXI3 = {
        elements.foreach{ case (_, data) => AssignZero(data) }
        val axi3param = new AXI3Len(len.width)
        val copy = Wire(new AXI3(axi3param))
        copy.elements.foreach { case (name, data) =>
            AssignZero(data)
            val thisName = name.toUpperCase
            if (elements.contains(thisName)) {
                data <> elements(thisName)
            }
        }
        
        copy
    }
}

class AXI4Lite(len: AXI4Len = new AXI4Len) extends Bundle {
    val awaddr = Output(UInt(len.awaddr.W))
    val awprot = Output(UInt(len.awprot.W))
    val awvalid = Output(UInt(len.awvalid.W))
    val awready = Input(UInt(len.awready.W))
    val wdata = Output(UInt(len.wdata.W))
    val wstrb = Output(UInt(len.wstrb.W))
    val wvalid = Output(UInt(len.wvalid.W))
    val wready = Input(UInt(len.wready.W))
    val bresp = Input(UInt(len.bresp.W))
    val bvalid = Input(UInt(len.bvalid.W))
    val bready = Output(UInt(len.bready.W))
    val araddr = Output(UInt(len.araddr.W))
    val arprot = Output(UInt(len.arprot.W))
    val arvalid = Output(UInt(len.arvalid.W))
    val arready = Input(UInt(len.arready.W))
    val rdata = Input(UInt(len.rdata.W))
    val rresp = Input(UInt(len.rresp.W))
    val rvalid = Input(UInt(len.rvalid.W))
    val rready = Output(UInt(len.rready.W))
}

class AXI4LiteUpper(len: AXI4Len = new AXI4Len) extends Bundle {
    val AWADDR = Output(UInt(len.awaddr.W))
    val AWVALID = Output(UInt(len.awvalid.W))
    val AWREADY = Input(UInt(len.awready.W))
    val WDATA = Output(UInt(len.wdata.W))
    val WSTRB = Output(UInt(len.wstrb.W))
    val WVALID = Output(UInt(len.wvalid.W))
    val WREADY = Input(UInt(len.wready.W))
    val BRESP = Input(UInt(len.bresp.W))
    val BVALID = Input(UInt(len.bvalid.W))
    val BREADY = Output(UInt(len.bready.W))
    val ARADDR = Output(UInt(len.araddr.W))
    val ARVALID = Output(UInt(len.arvalid.W))
    val ARREADY = Input(UInt(len.arready.W))
    val RDATA = Input(UInt(len.rdata.W))
    val RRESP = Input(UInt(len.rresp.W))
    val RVALID = Input(UInt(len.rvalid.W))
    val RREADY = Output(UInt(len.rready.W))
    
    def toLower: AXI4Lite = {
        val copy = Wire(new AXI4Lite(len))
        elements.foreach { case (name, data) =>
            data <> copy.elements(name.toLowerCase)
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
