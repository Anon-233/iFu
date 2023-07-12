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
val nWays        =2
val tagSz         = vaddrBits - log2Ceil(fetchWidth) - 1
val nSets        = 128
val extendedNSets = 128


def fetchIdx(addr: UInt) = addr >> log2Ceil(fetchBytes)


class BTBEntry extends Bundle {
    val offset   = SInt(offsetSz.W)
    val extended = Bool()
}

val btbEntrySz = offsetSz + 1



class BtbMeta extends Bundle {
    val isBr = Bool()
    val tag   = UInt(tagSz.W)
}

val btbMetaSz = tagSz + 1

class BtbPredictMeta extends Bundle {
    val writeWay = UInt(log2Ceil(nWays).W)
}

class Btb{
    io = IO(Bundle{
        val s0PC = Input(UInt(vaddrBits.W))
        val s0valid = Input(Bool())
        val s2targs  = Output(Vec(bankWidth, Valid(UInt(vaddrBitsExtended.W))))
        
        val s2br = Output(Vec(bankWidth, Bool()))
        val s2jal = Output(Vec(bankWidth, Bool()))
        val s2taken = Output(Vec(bankWidth, Bool()))

        val s3meta = Output(new BtbPredictMeta)

        val s1update = Input(Valid(new UpdateInfo))
    })

    s0idx := fetchIdx(io.s0PC)
    s1idx := RegNext(s0idx) 
    s1valid := RegNext(io.s0valid)
    s1PC := RegNext(io.s0PC)

    val reseting = RegInit(true.B)
    val resetIdx   = RegInit(0.U(log2Ceil(nSets).W))
    when(reseting){
        resetIdx := resetIdx + 1.U
    }
    when(resetIdx === (nSets-1).U){
        reseting := false.B
    }

    val meta = Seq.fill(nWays) { SyncReadMem(nSets, Vec(bankWidth, UInt(btbMetaSz.W))) }
    val btb  = Seq.fill(nWays) { SyncReadMem(nSets, Vec(bankWidth, UInt(btbEntrySz.W))) }
    val ebtb = SyncReadMem(extendedNSets, UInt(vaddrBitsExtended.W))

    val s1meta = Wire(new BtbPredictMeta)
    io.s3meta := RegNext(RegNext(s1meta))

    val s1rbtb = VecInit(btb.map(b => VecInit(b.read(s0idx, s0valid).map(_.asTypeOf(new BtbEntry)))))
    val s1rmeta = VecInit(meta.map(m => VecInit(m.read(s0idx, s0valid).map(_.asTypeOf(new BtbMeta)))))
    val s1rebtb = ebtb.read(s0idx, s0valid)
    
    val s1tag = s1_idx >> log2Ceil(nSets)

    val s1hitOHs = VecInit((0 until bankWidth)map{
        i => VecInit((0 until nWays)map{
            j => s1rmeta(j)(i).tag === s1tag
        })
    })

    val s1hits = s1hitOHs.map{oh => oh.reduce(_||_)}
    val s1hitWays = s1hitOHs.map{oh => PriorityEncoder(oh)}

    for (w <- 0 until bankWidth){
        val entryMeta = s1rmeta(s1hitWays(w))(w)
        val entryBtb = s1rbtb(s1hitWays(w))(w)
        val isBr = entryMeta.isBr && !reseting && s1valid && s1hits(w)
        val isJal = !entryMeta.isBr && !reseting && s1valid && s1hits(w)
        // 1周期处理信号，但是等到第二周期才会用，才会传出，故都regnext
        io.s2targs(w).valid := RegNext(!reseting && s1valid && s1hits(w))
        io.s2targs(w).bits := RegNext(Mux(
            entryBtb.extended,
            s1rebtb,
            (s1PC.asSInt + entryBtb.offset + (w << 2)).asUInt))
        io.s2br(w) := RegNext(isBr)
        io.s2jal(w) := RegNext(isJal)
        io.s2taken(w) := RegNext(isJal)
    }

    val calculateWay = {
        val rmeta = Cat(VecInit(s1rmeta.map{w => VecInit(w.map(_.tag))}.asUInt, s1tag))
        val l = log2Ceil(nWays)
        val nChunks = (rmeta.getWidth+ l -1) / l
        val chunks = (0 until nChunks)map{i=>
            rmeta(min((i+1)*l,rmeta.getWidth)-1,i*l)
        }
        chunks.reduce(_^_)
    }

    s1meta.writeWay := Mux(s1hits.reduce(_||_),
        PriorityEncoder(s1.hitohs.map(_.asUInt).reduce(_|_)),
        calculateWay)
    
    val s1updateCfiIdx = s1update.bits.cfiIdx.bits
    val s1updateMeta = s1update.bits.meta.btbMeta
    
    val maxOffsetValue = (~(0.U)((offsetSz-1).W)).asSInt
    val minOffsetValue = Cat(1.B, (0.U)((offsetSz-1).W)).asSInt
    val newOffsetValue = (s1update.bits.target.asSInt -
                            (s1update.bits.PC + (s1update.bits.cfiIdx.bits<<2)).asSInt)
    
    val needExtend = (newOffsetValue > maxOffsetValue ||
                        newOffsetValue < minOffsetValue)

    val s1updateWBtbData = Wire(new BtbEntry)

    s1updateWBtbData.extended := needExtend
    s1updateWBtbData.offset := newOffsetValue

    val s1updateIdx = fetchIdx(s1update.bits.PC)

    val s1updatewBtbMask = (UIntToOH(s1updateCfiIdx)&
        Fill(bankWidth, s1update.bits.cfiIdx.valid && s1_update.bits.cfiTaken && s1update.bits.isCommitUpdates))
    
    val s1updatewMetaMask = ((s1updatewBtbMask|s1update.bits.brMask)&
        (Fill(bankWidth,s1update.valid && s1update.bits.btbMispredicts)))

    val s1updatewMetaData = Wire(Vec(bankWidth, new BtbMeta))

    for (w <- 0 until bankWidth){
        s1updatewMetaData(w).tag := Mux(s1update.bits.btbMispredicts(w) ,0.U ,s1updateIdx >> log2Ceil(nSets))
        s1updatewMetaData(w).isBr := s1update.bits.brMask(w)
    }

    for (w <- 0 until nWays){
        when (reseting){
            btb(w).write(
            resetIdx,
            VecInit(Seq.fill(bankWidth){ 0.U(btbEntrySz.W)}),
            (~(0.U(bankWidth.W))).asBools
            )

            meta(w).write(
            resetIdx,
            VecInit(Seq.fill(bankWidth){ 0.U(btbMetaSz.W)}),
            (~(0.U(bankWidth.W))).asBools
            )
        }.otherwise(s1_update_meta.writeWay === w.U ){
            btb(w).write(
            s1updateIdx,
            VecInit(Seq.fill(bankWidth){s1updateWBtbData}),
            (s1updatewBtbMask).asBools
            )

            meta(w).write(
            s1updateIdx,
            VecInit(s1updatewMetaData.map(_.asUint)),
            (s1updatewMetaMask).asBools
            )
        }
    }

    when (s1updatewBtbMask =/= 0.U && needExtend){
        ebtb.write(s1updateIdx , s1update.bits.target)
    }


}