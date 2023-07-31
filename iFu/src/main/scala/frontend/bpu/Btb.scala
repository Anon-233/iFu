package iFu.frontend

import chisel3._
import chisel3.util._
import iFu.frontend.FrontendUtils._
import scala.math.min



class BtbEntry extends Bundle with HasBtbParameters {
    val offset   = SInt(offsetSz.W)
    val extended = Bool()
}





class BtbMeta extends Bundle with HasBtbParameters {
    val isBr = Bool()
    val tag   = UInt(tagSz.W)
}



class BtbPredictMeta extends Bundle with HasBtbParameters {
    val writeWay = UInt(log2Ceil(nWays).W)
    val hit = Bool()
}

class BtbPredictor extends Module with HasBtbParameters{
    val io = IO(new Bundle{
        val s0pc = Input(UInt(vaddrBits.W))
        val s0valid = Input(Bool())
        val s2targs  = Output(Vec(bankWidth, Valid(UInt(vaddrBits.W))))
        
        val s2br = Output(Vec(bankWidth, Bool()))
        val s2jal = Output(Vec(bankWidth, Bool()))
        val s2taken = Output(Vec(bankWidth, Bool()))

        val s3meta = Output(Vec(bankWidth,new BtbPredictMeta))

        val s1update = Input(Valid(new BankedUpdateInfo))
    })

    val clockcnt = RegInit((0.U)(10.W))
    clockcnt := clockcnt + 1.U
    printf("Btb Clock %d :\n", clockcnt)

    val s0idx = fetchIdx(io.s0pc)
    val s1idx = RegNext(s0idx) 
    val s1valid = RegNext(io.s0valid)
    val s1pc = RegNext(io.s0pc)

    val reseting = RegInit(true.B)
    val resetIdx   = RegInit(0.U(log2Ceil(nSets).W))
    when(reseting){
        resetIdx := resetIdx + 1.U
    }
    when(resetIdx === (nSets-1).U){
        reseting := false.B
    }

    val meta = Seq.fill(nWays) { SyncReadMem(nSets, Vec(bankWidth, new BtbMeta))}
    val btb  = Seq.fill(nWays) { SyncReadMem(nSets, Vec(bankWidth, new BtbEntry))}
    val ebtb = SyncReadMem(extendedNSets, UInt(vaddrBits.W))

    val s1meta = Wire(Vec (bankWidth ,new BtbPredictMeta))
    io.s3meta := RegNext(RegNext(s1meta))

    val s1rbtb = VecInit(btb.map(b => b.read(s0idx.asUInt, io.s0valid)))
    val s1rmeta = VecInit(meta.map(m => m.read(s0idx.asUInt, io.s0valid)))

    // 相较于Ubtb,这里专门给offset装不下的指令
    val s1rebtb = ebtb.read(s0idx.asUInt, io.s0valid)
    
    val s1tag = s1idx >> log2Ceil(nSets)

    val s1hitOHs = VecInit((0 until bankWidth)map{
        i => VecInit((0 until nWays)map{
            j => s1rmeta(j)(i).tag === s1tag.asUInt
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
            (s1pc.asSInt + entryBtb.offset + (w << 2).asSInt).asUInt))
        io.s2br(w) := RegNext(isBr)
        io.s2jal(w) := RegNext(isJal)
        io.s2taken(w) := RegNext(isJal)
    }

    val calculateWay = {
        val rmeta = Cat((VecInit(s1rmeta.map{w => VecInit(w.map(_.tag))})).asUInt, s1tag(tagSz-1,0))
        val l = log2Ceil(nWays)
        val nChunks = (rmeta.getWidth+ l -1) / l
        val chunks = (0 until nChunks)map{ i=>
            rmeta(min((i+1)*l,rmeta.getWidth)-1,i*l)
        }
        chunks.reduce(_^_)
    }

    for (w <- 0 until bankWidth){
    s1meta(w).writeWay := Mux(s1hits(w),
        PriorityEncoder(s1hitOHs(w).asUInt),
        calculateWay)

    s1meta(w).hit := s1hits(w)
    }
    
    val s1update = io.s1update
    val s1updateCfiIdx = s1update.bits.cfiIdx.bits
    val s1updateMeta = VecInit(s1update.bits.meta.map(_.btbMeta.asTypeOf(new BtbPredictMeta)))
    
    val maxOffsetValue = (~(0.U)((offsetSz-1).W)).asSInt
    val minOffsetValue = Cat(1.B, (0.U)((offsetSz-1).W)).asSInt
    val newOffsetValue = (s1update.bits.target.asSInt -
                            (s1update.bits.pc.asSInt + (s1update.bits.cfiIdx.bits<<2).asSInt))
    // 相较于Ubtb,这里专门处理了offset的问题
    val needExtend = (newOffsetValue > maxOffsetValue ||
                        newOffsetValue < minOffsetValue)

    val s1updateWBtbData = Wire(new BtbEntry)

    s1updateWBtbData.extended := needExtend
    s1updateWBtbData.offset := newOffsetValue

    val s1updateIdx = fetchIdx(s1update.bits.pc)

    val s1updatewBtbMask = (UIntToOH(s1updateCfiIdx) &
        Fill(bankWidth, s1update.bits.cfiIdx.valid && s1update.bits.cfiTaken && s1update.bits.isCommitUpdate))
    
    val s1updatewMetaMask = ((s1updatewBtbMask | s1update.bits.brMask) &
        (Fill(bankWidth, s1update.valid && s1update.bits.isCommitUpdate)) |  
        (Fill(bankWidth, s1update.valid ) & s1update.bits.btbMispredicts))

    val s1updatewMetaData = Wire(Vec(bankWidth, new BtbMeta))

    for (w <- 0 until bankWidth){
        s1updatewMetaData(w).tag := Mux(s1update.bits.btbMispredicts(w) ,0.U ,s1updateIdx >> log2Ceil(nSets))
        s1updatewMetaData(w).isBr := s1update.bits.brMask(w)
    }

    for (w <- 0 until nWays){
        when (reseting){
            btb(w).write(
            resetIdx,
            VecInit(Seq.fill(bankWidth){ 0.U.asTypeOf(new BtbEntry)}),
            (~(0.U(bankWidth.W))).asBools
            )

            meta(w).write(
            resetIdx,
            VecInit(Seq.fill(bankWidth){ 0.U.asTypeOf(new BtbMeta)}),
            (~(0.U(bankWidth.W))).asBools
            )
            // 命中，写到对应的way
        }.elsewhen(s1updateMeta(w).writeWay === w.U && s1updateMeta(w).hit){
            btb(w).write(
            s1updateIdx.asUInt,
            VecInit(Seq.fill(bankWidth){s1updateWBtbData}),
            (s1updatewBtbMask).asBools
            )

            meta(w).write(
            s1updateIdx.asUInt,
            s1updatewMetaData,
            (s1updatewMetaMask).asBools
            )
        }
    }

    when (s1updatewBtbMask =/= 0.U && needExtend){
        ebtb.write(s1updateIdx.asUInt, s1update.bits.target)
    }
    
}