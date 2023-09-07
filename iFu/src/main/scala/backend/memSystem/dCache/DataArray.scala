package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._

class DataReadReq extends CoreBundle {
    val wayMUx = UInt(nWays.W)
    val addr   = UInt(untagBits.W)
}

class DataWriteReq extends DataReadReq {
    val wmask  = Vec(rowWords, Bool())
    val data   = UInt(128.W)
}

class DualDataReadReq extends CoreBundle {
    val valid = Vec(memWidth, Bool())
    val req   = Vec(memWidth, new DataReadReq)
}

class DataArray extends CoreModule {
    val io = IO(new CoreBundle {
        val read  = Vec(memWidth, Flipped(Valid(new DataReadReq)))
        val write = Flipped(Valid(new DataWriteReq))
        val resp  = Output(Vec(memWidth, Vec(nWays, UInt(xLen.W))))
    })

    val waddr  = io.write.bits.addr >> 2 // 4 bytes per word
    val raddr1 = io.read(0).bits.addr >> 2
    val raddr2 = io.read(1).bits.addr >> 2

    for (w <- 0 until nWays) {
        val depth = nSets * rowWords
        val array = SyncReadMem(depth, Vec(4, UInt(8.W)))

        when (io.write.valid && io.write.bits.wayMux(w)) {
            array.write(waddr, io.write.data, io.write.bits.wmask)
        }
        io.resp(0)(w) := RegNext(
            array.read(raddr1, io.read(0).wayMux(w) && io.read(0).valid).asUInt
        )
        io.resp(1)(w) := RegNext(
            array.read(raddr2, io.read(1).wayMux(w) && io.read(1).valid).asUInt
        )
    }
}
