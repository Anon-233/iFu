package iFu.frontend

import chisel3._
import chisel3.util._
import iFu.common._

/**
  * we need to add the following parameters:
  * coreWidth MicroOp
  * 
  * ----------------------------------------
  * we need to add the following class:
  * HasFrontendParameters
  * HasFrontendParameters
  * 
  */

class FetchBufferResp() extends CoreBundle
{
    val uops = Vec(coreWidth,Valid(new MicroOp()))
}

class FetchBuffer() extends CoreBundle
    with HasCoreParameters
{
    val io = IO(new CoreBundle{
        val clear = Input(Bool())

        val enq = Flipped(Decoupled(new FetchBundle()))
        val deq = new DecoupledIO(new FetchBufferResp())
    })
    val numEnt = frontendParams.numFBEntries

    val numRow = numEnt / coreWidth

    val Opram = Reg(Vec(numEnt, new MicroOp))

    val deqVec = Wire(Vec(numRow, Vec(coreWidth, new MicroOp)))

    val head = RegInit(1.U(numRow.W))
    val tail = RegInit(1.U(numEnt.W))

    val mayFull = RegInit(false.B) //入队置为1


    //入队阶段
    def rotateLeft(in : UInt, k:Int) = {
        val n =in.getWidth
        Cat(in(n-k-1,0),in(n-1,n-k))
    }

    val mayHitHead = (1 until frontendParams.fetchWidth).map(k => VecInit(rotateLeft(tail, k).asBools.zipWithIndex.filter
    {case (e,i) => i % coreWidth == 0}.map {case (e,i) => e}).asUInt).map(tail => head & tail).reduce(_|_).orR
    val atHead = (VecInit(tail.asBools.zipWithIndex.filter {case (e,i) => i % coreWidth == 0}
    .map {case (e,i) => e}).asUInt & head).orR
    val doEnqueue = !(atHead && mayFull || mayHitHead)

    io.enq.ready := doEnqueue

    val inMask = Wire(Vec(frontendParams.fetchWidth, Bool()))
    val inUops = Wire(Vec(frontendParams.fetchWidth, new MicroOp()))

    for(b <- 0 until nBanks){
        for (w <- 0 until frontendParams.iCacheParams.bankWidth){
            val i =(b*frontendParams.iCacheParams.bankWidth) + w

            val pcLowbit = (bankAlign(io.enq.bits.pc) + (i << 1).U)

            inUops(i) := DontCare
            inMask(i) := io.enq.valid && io.enq.bits.mask(i)
            inUops(i).pcLowBits := pcLowbit

            inUops(i).isSFB := io.enq.bits.sfbs(i) || io.enq.bits.shadowed_mask(i)

            inUops(i).ftqIdx := io.enq.bits.ftq_idx
            inUops(i).instr := io.enq.bits.exp_insts(i)
            inUops(i).taken := io.enq.bits.cfi_idx === i.U && io.enq.bits.cfi_idx.valid
            
            /*
            inUops(i).xcpt_pf_if     := io.enq.bits.xcpt_pf_if
            inUops(i).xcpt_ae_if     := io.enq.bits.xcpt_ae_if
            inUops(i).bp_debug_if    := io.enq.bits.bp_debug_if_oh(i)
            inUops(i).bp_xcpt_if     := io.enq.bits.bp_xcpt_if_oh(i)
            */
        }
    }

    val enq_idxs = Wire(Vec(frontendParams.fetchWidth,UInt(numEnt.W)))

    def inc(ptr: UInt) = {
        val n = ptr.getWidth
        Cat(ptr(n-2,0), ptr(n-1))
    }

    var enq_idx = tail
    for (i <- 0 until frontendParams.fetchWidth){
        enq_idxs(i) := enq_idx
        enq_idx = Mux(inMask(i),inc(enq_idx),enq_idx)
    }

    //写入
    for( i <- 0 until frontendParams.fetchWidth){
        for(j <- 0 until numEnt){
            when (doEnqueue && inMask(i) && enq_idxs(i)(j)){
                Opram(j) := inUops(i)
            }
        }
    }

    //出队阶段
    val mayHitTail = VecInit((0 until numEnt).map(i =>
                          head(i/coreWidth) && (!mayFull || (i % coreWidth != 0).B))).asUInt & tail
    val slotWillHitTail = (0 until numRow).map(i => mayHitTail((i+1)*coreWidth-1, i*coreWidth)).reduce(_|_)
    val willHitTail = slotWillHitTail.orR

    val doDequeue = io.deq.ready && !willHitTail

    val deqVal = (~MaskUpper(slotWillHitTail)).asBools

    for(i <- 0 until numEnt){
        deqVec(i/coreWidth)(i%coreWidth) := Opram(i)
    }

    io.deq.bits.uops zip deqVal           map {case (d,v) => d.valid := v}
    io.deq.bits.uops zip Mux1H(head, deqVec) map {case (d,q) => d.bits  := q}
    io.deq.valid := deqVal.reduce(_||_)

    //更新
    when (doEnqueue){
        tail := enq_idx
        when (inMask.reduce(_||_)){
            mayFull := true.B
        }
    }

    when (doDequeue) {
        head := inc(head)
        mayFull := false.B
    }

    when (io.clear) {
        head := 1.U
        tail := 1.U
        mayFull := false.B
    }


    when(reset.asBool){
        io.deq.bits.uops map { u => u.valid := false.B}
    }

}