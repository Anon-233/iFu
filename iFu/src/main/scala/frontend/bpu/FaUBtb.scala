package iFu.frontend

import chisel3._
import chisel3.util._
import iFu.frontend.FrontendUtils._
import scala.math.min


class UbtbEntry extends Bundle with HasUbtbParameters{
    val offset   = SInt(offsetSz.W)
}

// 用于BTB里面存储的信息，进行判断命中等信息
class UbtbMeta extends Bundle  with HasUbtbParameters{
    val isBr = Bool()
    val tag   = UInt(tagSz.W)
    val ctr   = UInt(2.W)
}

// 返回给外面预测器的信息
class UbtbPredictMeta   extends Bundle  with HasUbtbParameters {
    val hit  = Bool()
    val writeWay = UInt(log2Ceil(nWays).W)
}


class FaUBtbPredictior  extends Module with HasUbtbParameters {
    val io = IO(new Bundle{
        val s1valid = Input(Bool())
        val s1pc = Input(UInt(vaddrBits.W))
        val s1targs  = Output(Vec(bankWidth, Valid(UInt(vaddrBits.W))))
        val s1taken = Output(Vec(bankWidth, Bool()))
        val s1br = Output(Vec(bankWidth, Bool()))
        val s1jal = Output(Vec(bankWidth, Bool()))

        val s3meta = Output(Vec(bankWidth,new UbtbPredictMeta))

        val s1update = Input(Valid(new BankedUpdateInfo))
    })

    val clockcnt = RegInit((0.U)(10.W))
    clockcnt := clockcnt + 1.U
    printf("FaUBtb Clock %d :\n", clockcnt)
    
    // 都是Reg类型存储,故当周期可读,下一周期可写
    val meta     = RegInit((0.U).asTypeOf(Vec(nWays, Vec(bankWidth, new UbtbMeta))))
    val btb      = Reg(Vec(nWays, Vec(bankWidth, new UbtbEntry)))

    val s1idx = fetchIdx(io.s1pc)
    val s1tag = s1idx
    // 找命中
    val s1hitOHs = VecInit((0 until bankWidth) map { i =>
        VecInit((0 until nWays) map { w =>
          meta(w)(i).tag === s1tag(tagSz-1,0)
        })
    })
    val s1hits = s1hitOHs.map(_.asUInt.orR)
    val s1hitWays = s1hitOHs.map(oh => PriorityEncoder(oh))

    val s1meta = Wire(Vec(bankWidth,new UbtbPredictMeta))//区分，这个是返回给外面的信息,和meta不是同一个类型
    val s1valid = io.s1valid

    // 命中了就返回ubtb存储的该指令相关信息
    for (w <- 0 until bankWidth){
        val entryMeta = meta(s1hitWays(w))(w)
        val respValid = s1valid && s1hits(w)
        io.s1targs(w).valid := respValid
        io.s1targs(w).bits  := (io.s1pc.asSInt + (w << 2).S + btb(s1hitWays(w))(w).offset).asUInt
        io.s1br(w) := entryMeta.isBr && respValid
        io.s1jal(w) := !entryMeta.isBr && respValid
        io.s1taken(w) := !entryMeta.isBr || entryMeta.ctr(1)

        s1meta(w).hit := s1hits(w)
    }

    io.s3meta := RegNext(RegNext(s1meta))

    val calculateWay ={
    val rMetas = Cat(VecInit(meta.map(e => VecInit(e.map(_.tag)))).asUInt, s1tag)
    val l = log2Ceil(nWays)
    val nChunks = (rMetas.getWidth + l - 1) / l
    val chunks = (0 until nChunks) map { i =>
        rMetas(min((i+1)*l, rMetas.getWidth)-1, i*l)
    }
    chunks.reduce(_^_)
    }
    // 他们以后如果要写回,写回哪一位,要是现在表里有就是那里,不然的话随机计算出一位
    for(w <- 0 until bankWidth){
        s1meta(w).writeWay := Mux(
        s1hits(w),
        PriorityEncoder(s1hitOHs(w)),
        calculateWay
    )
    }
    

    val s1update = io.s1update

    // 更新的一些信息准备
    val s1updateCfiIdx = s1update.bits.cfiIdx.bits
    val s1updateMeta = VecInit(s1update.bits.meta.map(_.ubtbMeta))
    val s1updateWay = VecInit(s1updateMeta.map(_.writeWay))

    val maxOffsetValue = (~(0.U)((offsetSz-1).W)).asSInt
    val minOffsetValue = Cat(1.B, (0.U)((offsetSz-1).W)).asSInt

    // 这里硬算,即使可能被仅有13位的offset阶段,这留给BTB去处理
    val newOffsetValue = (s1update.bits.target.asSInt -
                            (s1update.bits.pc + (s1update.bits.cfiIdx.bits<<2)).asSInt)
    
    val s1updateWBtbData = Wire(new UbtbEntry)
    s1updateWBtbData.offset := newOffsetValue
    val s1updatewBtbMask =(UIntToOH(s1updateCfiIdx)&
        Fill(bankWidth,s1update.bits.cfiIdx.valid&&s1update.valid&&s1update.bits.cfiTaken&&s1update.bits.isCommitUpdate))
    val s1updatewMetaMask = ((s1updatewBtbMask|s1update.bits.brMask)&
        Fill(bankWidth,s1update.valid&&s1update.bits.isCommitUpdate))
    
    val wenable = (s1update.valid && s1update.bits.cfiTaken && s1update.bits.cfiIdx.valid 
                && s1update.bits.isCommitUpdate)
    // 更新
    for (w <- 0 until bankWidth){
        when(wenable){
            when(s1updateMeta(w).hit){
                btb(s1updateWay(w))(s1updateCfiIdx).offset := newOffsetValue
            } 
        } 
    }

    for (w <-0 until bankWidth) {
        val successbranchtaken = s1update.valid && s1update.bits.isCommitUpdate &&
            (s1update.bits.brMask(w)||(s1update.bits.cfiIdx.bits === w.U && s1update.bits.cfiTaken && s1update.bits.cfiIdx.valid))

        when (successbranchtaken){
            when (s1updateMeta(w).hit){
                val wastaken = successbranchtaken || s1update.bits.cfiIsJal
                val s1updateIdx = fetchIdx(s1update.bits.pc)

                meta(s1updateWay(w))(w).isBr := s1update.bits.brMask(w)
                meta(s1updateWay(w))(w).tag := s1updateIdx
                meta(s1updateWay(w))(w).ctr := Mux(!s1updateMeta(w).hit,
                Mux(wastaken, 3.U, 0.U),
                bimWrite(meta(s1updateWay(w))(w).ctr, wastaken)
                )
            }
            
        }
    }

}

