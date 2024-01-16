
package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.util._


// 区分DcacheMetaResp
class MetaResp extends CoreBundle with HasDcacheParameters{
    val rmetaSet  = Vec(nWays, new MetaLine)
    // 供外界判断是否有dirty
    val hasDirty  = Bool()
}

class MetaIO extends CoreBundle with HasDcacheParameters{
    val req  = Input(Valid(new DcacheMetaReq))
    val resp = Output(Valid(new MetaResp))
}

class DcacheMeta extends Module with HasDcacheParameters{
    val io = IO(new CoreBundle{ 
        val read     = Vec( memWidth ,new MetaIO)
        val write    = new MetaIO
    })

    val valids = RegInit(VecInit(Seq.fill(nSets)(VecInit(Seq.fill(nWays)(false.B)))))
    val dirtys = RegInit(VecInit(Seq.fill(nSets)(VecInit(Seq.fill(nWays)(false.B)))))
    val readOnlys = RegInit(VecInit(Seq.fill(nSets)(VecInit(Seq.fill(nWays)(false.B)))))
    val fixeds = RegInit(VecInit(Seq.fill(nSets)(VecInit(Seq.fill(nWays)(false.B)))))
    val tags = SyncReadMem(nSets, Vec(nWays, UInt(nTagBits.W)))

    // reset tags
    val reseting = RegInit(true.B)
    val resetIdx = RegInit(0.U(nIdxBits.W))

    when (reseting) {
        when (resetIdx === (nSets - 1).U) {
            reseting := false.B
        }
        tags.write(resetIdx, VecInit(Seq.fill(nWays)(0.U)))
        valids(resetIdx) := VecInit(Seq.fill(nWays)(false.B))
        resetIdx := resetIdx + 1.U
    }

    // preserve dirty position
    val dirtyIdx = Wire(UInt(nIdxBits.W))
    dirtyIdx := PriorityEncoder(valids zip dirtys map { case (v, d) => (v.asUInt & d.asUInt).orR })

    val hasDirty = dirtys.map(_.asUInt.orR).reduce(_ || _)
    // 通过0号口持续向外传
    io.read(0).resp.bits.hasDirty := RegNext(hasDirty)
    // read
    val rvalid  = io.read.map( _.req.valid)
    val rreq    = io.read.map( _.req.bits)
    val ridx    = rreq.map( req => Mux(req.isFence, dirtyIdx, req.idx))

    val rtags    = Wire(Vec(memWidth, Vec(nWays, UInt(nTagBits.W))))
    val rmetaSet = Wire(Vec(memWidth, Vec(nWays, new MetaLine)))

    rtags := 0.U.asTypeOf(Vec(memWidth, Vec(nWays, UInt(nTagBits.W))))
    rmetaSet := 0.U.asTypeOf(Vec(memWidth, Vec(nWays, new MetaLine)))

    for (w <- 0 until memWidth) {
        io.read(w).resp := 0.U.asTypeOf(Valid(new MetaResp))
        // read tags
        rtags(w) := tags.read(ridx(w))
        for (i <- 0 until nWays) {
            // assemble metaSet
            rmetaSet(w)(i).valid := RegNext(valids(ridx(w))(i))
            rmetaSet(w)(i).dirty := RegNext(dirtys(ridx(w))(i))
            rmetaSet(w)(i).readOnly := RegNext(readOnlys(ridx(w))(i))
            rmetaSet(w)(i).fixed := RegNext(fixeds(ridx(w))(i))
            rmetaSet(w)(i).tag := rtags(w)(i)
        }
        io.read(w).resp.bits.rmetaSet := rmetaSet(w)
        io.read(w).resp.valid := RegNext(rvalid(w))
    }

    // write
    val wvalid  = io.write.req.valid
    val wreq    = io.write.req.bits
    val widx    = wreq.idx
    val wpos    = wreq.pos
    val wmask   = UIntToOH(wpos)


    io.write.resp := 0.U.asTypeOf(Valid(new MetaResp))

    when(wvalid){
        // write tags
        when(wreq.setTag.valid){
            tags.write(widx, VecInit(Seq.fill(nWays)(wreq.setTag.bits)), wmask.asBools)
        }
        
        // write valids
        when(wreq.setvalid.valid){
            valids(widx)(wpos) := wreq.setvalid.bits
        }

        // write dirtys
        when(wreq.setdirty.valid){
            dirtys(widx)(wpos) := wreq.setdirty.bits
        }

        // write readOnlys
        when(wreq.setreadOnly.valid){
            readOnlys(widx)(wpos) := wreq.setreadOnly.bits
        }

        // write fixeds
        when(wreq.setfixed.valid){
            fixeds(widx)(wpos) := wreq.setfixed.bits
        }
    }
    
    io.write.resp.valid := RegNext(wvalid)
    
    // bypass
    val bypass = Wire(Vec(memWidth, Bool()))
    dontTouch(bypass)
    for (w <- 0 until memWidth) {
        bypass(w) := rvalid(w) && wvalid && (ridx(w) === widx)
        // 当周期判断，下周期转发
        val wpos_bypass = RegNext(wpos)
        when (RegNext(bypass(w))) {
            // 看看write操作对应位有修改吗，如果有，用写的值，没有的话，还是保留原来读到的rmetaSet的值
            io.read(w).resp.bits.rmetaSet(wpos_bypass).valid := Mux(RegNext(wreq.setvalid.valid), RegNext(wreq.setvalid.bits), rmetaSet(w)(wpos).valid)
            io.read(w).resp.bits.rmetaSet(wpos_bypass).dirty := Mux(RegNext(wreq.setdirty.valid), RegNext(wreq.setdirty.bits), rmetaSet(w)(wpos).dirty)
            io.read(w).resp.bits.rmetaSet(wpos_bypass).readOnly := Mux(RegNext(wreq.setreadOnly.valid), RegNext(wreq.setreadOnly.bits), rmetaSet(w)(wpos).readOnly)
            io.read(w).resp.bits.rmetaSet(wpos_bypass).tag := Mux(RegNext(wreq.setTag.valid), RegNext(wreq.setTag.bits), rmetaSet(w)(wpos).tag)
        }
    }



}