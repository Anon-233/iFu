package iFu.frontend.predictors

import chisel3._
import chisel3.util._
import iFu.frontend.predictors._

val vaddrBits = 32
val bankWidth = 4
val fetchWidth = 8
val nBanks = 2

val localHistoryLength = 16
val maxMetaLength = 16
val fetchBytes = 32
val offsetSz = 13
val nWays        =16 
val tagSz         = vaddrBits - log2Ceil(fetchWidth) - 1
val nWrBypassEntries = 2

def fetchIdx(addr: UInt) = addr >> log2Ceil(fetchBytes)

class UbtbEntry extends Bundle {
    val offset   = SInt(offsetSz.W)
}

// 用于BTB里面存储的信息，进行判断命中等信息
class UbtbMeta extends Bundle {
    val isBr = Bool()
    val tag   = UInt(tagSz.W)
    val ctr   = UInt(2.W)
}

// 返回给外面预测器的信息
class UbtbPredictMeta  {
    val hits  = Vec(bankWidth, Bool())
    val writeWay = UInt(log2Ceil(nWays).W)
}

def bimWrite(v: UInt, taken: Bool): UInt = {
    val oldBimSatTaken  = v === 3.U
    val oldBimSatNtaken = v === 0.U
    Mux(oldBimSatTaken  &&  taken, 3.U,
      Mux(oldBimSatNtaken && !taken, 0.U,
      Mux(taken, v + 1.U, v - 1.U)))
}

class FaUBtb{
    io = IO(Bundle{
        val s1PC = Input(UInt(vaddrBits.W))
        val s1targs  = Output(Vec(bankWidth, Valid(UInt(vaddrBitsExtended.W))))
        val s1taken = Output(Vec(bankWidth, Bool()))
        val s1br = Output(Vec(bankWidth, Bool()))
        val s1jal = Output(Vec(bankWidth, Bool()))

        val s3meta = Output(new UbtbPredictMeta)

        val s1update = Input(Valid(new UpdateInfo))
    })
    
    val meta     = RegInit((0.U).asTypeOf(Vec(nWays, Vec(bankWidth, new UbtbMeta))))
    val btb      = Reg(Vec(nWays, Vec(bankWidth, new UbtbEntry)))

    val s1idx = fetchIdx(io.s1PC)
    val s1tag = s1idx

    val s1hitOHs = VecInit((0 until bankWidth) map { i =>
        VecInit((0 until nWays) map { w =>
          meta(w)(i).tag === s1tag(tagSz-1,0)
        })
    })
    val s1hits = s1hitOHs.map(_.asUInt.orR)
    val s1hitWays = s1hitOHs.map(oh => PriorityEncoder(oh))

    val s1meta = new UbtbPredictMeta//区分，这个是返回给外面的信息

    for (w <- 0 until bankWidth){
        val entry_meta = meta(s1hitWays(w))(w)
        val respvalid = s1_valid && s1_hits(w)
        io.s1targs(w).valid := respvalid
        io.s1targs(w).bits  := (s1_PC.asSInt + (w << 1).S + btb(s1_hit_ways(w))(w).offset).asUInt
        io.s1br(w) := entry_meta.isBr && respvalid
        io.s1jal(w) := !entry_meta.isBr && respvalid
        io.s1taken(w) := !entry_meta.isBr || entry_meta.ctr(1)

        s1_meta.hits(w) := s1_hits(w)
    }

    io.s3meta := RegNext(RegNext(s1meta))

    val calculateWay ={
    val r_metas = Cat(VecInit(meta.map(e => VecInit(e.map(_.tag)))).asUInt, s1tag)
    val l = log2Ceil(nWays)
    val nChunks = (r_metas.getWidth + l - 1) / l
    val chunks = (0 until nChunks) map { i =>
        r_metas(min((i+1)*l, r_metas.getWidth)-1, i*l)
    }
    chunks.reduce(_^_)
    }
    s1meta.writeWay := Mux(
        s1hits.reduce(_||_),
        PriorityEncoder(s1hitOHs.map(_.asUInt).reduce(_|_)),
        calculateWay
    )

    val s1updateCfiIdx = s1update.bits.cfiIdx.bits
    val s1updateMeta = s1update.bits.meta.ubtbMeta
    val s1updateway = s1updateMeta.writeWay

    val maxOffsetValue = (~(0.U)((offsetSz-1).W)).asSInt
    val minOffsetValue = Cat(1.B, (0.U)((offsetSz-1).W)).asSInt
    val newOffsetValue = (s1update.bits.target.asSInt -
                            (s1update.bits.PC + (s1update.bits.cfiIdx.bits<<2)).asSInt)
    
    val s1updateWBtbData = Wire(new UbtbEntry)
    s1updateWBtbData.offset = newOffsetValue
    val s1updatewBtbMask =(UIntToOH(s1updateCfiIdx)&
        Fill(bankWidth,s1update.bits.cfiIdx.valid&&s1update.valid&&s1update.bits.cfiTaken&&s1_update.bits.isCommitUpdate))
    val s1updatewMetaMask = ((s1updatewBtbMask|s1update.bits.brMask)&
        Fill(bankWidth,s1update.valid&&s1update.bits.isCommitUpdate))
    
    val wenable = (s1update.valid && s1update.bits.cfiTaken && s1update.bits.cfiIdx.valid 
                && s1update.bits.isCommitUpdate)
    when(wenable){
        btb(s1updateway)(s1updateCfiIdx).offset := newOffsetValue
    } 

    for (w <-0 until bankWidth) {
        val successbranchtaken = s1update.valid && s1update.bits.isCommitUpdate &&
            (s1update.bits.brMask(w)||(s1update.cfiIdx === w.U && s1update.bits.cfiTaken && s1update.bits.cfiIdx.valid))

        when (successbranchtaken){
            val wastaken = successbranchtaken || s1update.bits.cfiIsJal
            val s1updateIdx = fetchIdx(s1update.bits.PC)

            meta(s1updateway)(w).isBr := s1update.bits.brMask(w)
            meta(s1_update_writeWay)(w).tag := s1updateIdx
            meta(s1_update_writeWay)(w).ctr := Mux(!s1updateMeta.his(w),
                Mux(wastaken, 3.U, 0.U),
                bimWrite(s1updateMeta.ctr(w), wastaken)
            )
        }
    }

}

