package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._

class MetaData extends CoreBundle {
    val valid = Bool()
    val dirty = Bool()
    val tag = UInt(tagBits.W)
    // val age = UInt(dCacheAgeBits.W)
}

class MetaReadReq extends CoreBundle {
    val idx   = UInt(idxBits.W)
    val tag   = UInt(tagBits.W)
    val wayMux = UInt(nWays.W)
}

class MeatWriteReq extends MetaReadReq {
    val data = new MetaData
}

class DualMetaReadReq extends CoreBundle {
    val req    = Vec(memWidth, new MetaReadReq)
}

class MetaArray extends CoreModule {
    val io = IO(new Bundle {
        val read  = Vec(memWidth, Flipped(Decoupled(new MetaReadReq)))
        val write = Flipped(Decoupled(new MeatWriteReq))
        val resp  = Output(Vec(memWidth, Vec(nWays, new MetaData)))
    })

    val array = SyncReadMem(nSets, Vec(nWays, new MetaData))

    val rstEn = RegInit(true.B)
    val rstCnt = RegInit(0.U(log2Ceil(nSets).W))
    when (rstCnt === (nSets - 1).U) { rstEn := false.B }
    rstCnt := WrapInc(rstCnt, nSets)

    val wEn   = rstEn || io.write.fire
    val waddr = Mux(rstEn, rstCnt, io.write.bits.idx)
    val wdata = Mux(rstEn, 0.U.asTypeOf(new MetaData), io.write.bits.data)
    val wmask = Mux(rstEn, -1.S, io.write.bits.wayMux).asBools

    when (wEn) {
        array.write(waddr, VecInit.fill(nWays)(wdata), wmask)
    }
    
    for (i <- 0 until memWidth) {
        io.read(i).ready := !rstEn || !wEn
        io.resp(i) := array.read(io.read(i).bits.idx, io.read(i).valid)
    }

    io.write.ready := !rstEn
}