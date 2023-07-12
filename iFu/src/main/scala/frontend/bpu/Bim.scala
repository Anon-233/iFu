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

val nSets = 2048

val nWrBypassEntries = 2

def fetchIdx(addr: UInt) = addr >> log2Ceil(fetchBytes)
def WrapInc(x: UInt, max: UInt) = Mux(x === max, 0.U, x + 1.U)

class BimPredictMeta {
    val bims  = Vec(bankWidth, UInt(2.W))
}

def bimWrite(v: UInt, taken: Bool): UInt = {
val oldBimSatTaken  = v === 3.U
val oldBimSatNtaken = v === 0.U
Mux(oldBimSatTaken  &&  taken, 3.U,
    Mux(oldBimSatNtaken && !taken, 0.U,
    Mux(taken, v + 1.U, v - 1.U)))
}

class Bimpredictor {
    io = IO(Bundle{
        val s0PC = Input(UInt(vaddrBits.W))
        val s0valid = Input(Bool())

        val s2taken = Output(Vec(bankWidth, Bool()))

        val s3meta = Output(new BtbPredictMeta)

        val s1update = Input(Valid(new UpdateInfo))
    })

    val s2meta = Wire(new BimPredictMeta)

    val reseting =RegInit(true.B)
    val resetIdx =RegInit(0.U(log2Ceil(nSets).W))

    when(reseting){
        resetIdx := resetIdx + 1.U
    }

    when(resetIdx === (nSets-1).U){ reseting := false.B}

    val ram = SyncReadMem(nSets,Vec(bankWidth,UInt(2.W)))

    val s0idx = fetchIdx(s0PC)
    val s2valid = RegNext(RegNext(s0valid))

    val s2rdata = RegNext(ram.read(s0idx,Uint(2.W)))

    for(w <- 0 until bankWidth){
        io.s2taken(w) := s2valid && s2rdata(w)(1) && !reseting
        s2meta.bims(w) := s2rdata(w)
    }

    val s1updatewData = Wire(Vec(bankWidth,UInt(2.W)))
    val s1updateIdx = fetchIdx(io.s1update.bits.PC)
    val s1updatewMask = Wire(Vec(bankWidth,Bool()))
    val s1updateMeta = io.s1update.bits.meta.bimMeta

    val wrBypassIdxs = Reg(Vec(nWrBypassEntries,UInt(log2Ceil(nSets).W)))
    val wrBypass = Reg(Vec(nWrBypassEntries,Vec(bankWidth,UInt(2.W))))
    val wrBypassEnqIdx = RegInit(0.U(log2Ceil(nWrBypassEntries).W))

    val wrBypassHits = VecInit((0 until nWrBypassEntries) map { i =>
        !reseting &&
        wrBypassIdxs(i) === s1updateIdx(log2Ceil(nSets)-1,0)
    })

    val wrBypassHit = wrBypassHits.reduce(_||_)
    val wrBypassHitIdx = PriorityEncoder(wrBypassHits)

    for(w <- 0 until bankWidth){
        s1updatewMask(w) := false.B
        s1updatewData(w) := DontCare

        val updatePC = io.s1update.bits.PC + (w << 2).U
        val updateIdx = fetchIdx(updatePC)

        when(s1update.bits.brMask(w)||
            (s1update.bits.cfiIdx.valid && s1update.bits.cfiIdx.bits === w.U))
        {
            val was_taken = (
                s1updateMeta.bits.cfiIdx.valid &&
                (s1_update.bits.cfiIdx.bits === w.U) &&
                (
                    (s1update.bits.cfiIsBr) && (s1update.bits.cfiIsBr && s1update.bits.brmask(w) && s1update.bits.cfiTaken) ||
                    s1update.bits.cfiIsJal 
                )
            )
            val oldbimvalue = Mux(wrBypassHit ,
                wrBypass(wrBypassHitIdx)(w),
                s1updateMeta.bims(w)
            )

            s1updatewMask(w) := true.B
            s1updatewData(w) := bimWrite(oldbimvalue,was_taken)
        }
    }

    when(reseting){
        ram.write(resetIdx,VecInit(Seq.fill(bankWidth){2.U}), (~(0.U(bankWidth.W))))
    }.otherwise(s1update.valid && s1update.bits.isCommitUpdate){
        ram.write(s1updateIdx,s1updatewData,s1updatewMask.asUInt.asBools)
    }

    when(s1updatewMask.reduce(_||_) && s1update.valid && s1update.bits.isCommitUpdate){
        when (wrBypassHit){
            wrBypass(wrBypassHitIdx) := s1updatewData
        }.otherwise{
            wrBypass(wrBypassEnqIdx) := s1updatewData
            wrBypassIdxs(wrBypassEnqIdx) := s1updateIdx
            wrBypassEnqIdx := WrapInc(wrBypassEnqIdx,nWrBypassEntries)
        }
    }

    io.s3meta := RegNext(s2meta)

}