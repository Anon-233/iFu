package iFu.frontend

import chisel3._
import chisel3.util._
import iFu.frontend.FrontendUtils._
import iFu.util._



class BimPredictMeta extends Bundle with HasBimParameters{
    val bim  = UInt(2.W)
}


class BimPredictor extends Module with HasBimParameters{
    val io = IO(new Bundle{
        val s0pc = Input(UInt(vaddrBits.W))
        val s0valid = Input(Bool())

        val s2taken = Output(Vec(bankWidth, Bool()))

        val s3meta = Output(Vec(bankWidth,new BimPredictMeta))

        val s1update = Input(Valid(new BankedUpdateInfo))
    })

    val clockcnt = RegInit((0.U)(10.W))
    clockcnt := clockcnt + 1.U

    val s2meta = Wire(Vec(bankWidth,new BimPredictMeta))

    val reseting =RegInit(true.B)
    val resetIdx =RegInit(0.U(log2Ceil(nSets).W))

    when(reseting){
        resetIdx := resetIdx + 1.U
    }

    when(resetIdx === (nSets-1).U){ reseting := false.B}

    val bimRam = SyncReadMem(nSets,Vec(bankWidth,UInt(2.W)))

    val s0idx = fetchIdx(io.s0pc)
    val s2valid = RegNext(RegNext(io.s0valid))

    val s2rdata = RegNext(VecInit(bimRam.read(s0idx.asUInt,io.s0valid).map(_.asTypeOf(UInt(2.W)))))

    for(w <- 0 until bankWidth){
        io.s2taken(w) := s2valid && s2rdata(w)(1) && !reseting
        s2meta(w).bim := s2rdata(w)
    }

    val s1update = io.s1update
    val s1updatewData = Wire(Vec(bankWidth,UInt(2.W)))
    val s1updateIdx = fetchIdx(io.s1update.bits.pc)
    val s1updatewMask = Wire(Vec(bankWidth,Bool()))
    val s1updateMeta = VecInit(io.s1update.bits.meta.map(_.bimMeta))

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

        val updatepc = io.s1update.bits.pc + (w << 2).U
        val updateIdx = fetchIdx(updatepc)

        when(s1update.bits.brMask(w)||
            (s1update.bits.cfiIdx.valid && s1update.bits.cfiIdx.bits === w.U))
        {
            val wasTaken = (
                s1update.bits.cfiIdx.valid &&
                (s1update.bits.cfiIdx.bits === w.U) &&
                (
                    (s1update.bits.cfiIsBr) && (s1update.bits.cfiIsBr && s1update.bits.brMask(w) && s1update.bits.cfiTaken) ||
                    s1update.bits.cfiIsJal
                )
            )
            val oldbimvalue = Mux(wrBypassHit ,
                wrBypass(wrBypassHitIdx)(w),
                s1updateMeta(w).asUInt
            )

            s1updatewMask(w) := true.B
            s1updatewData(w) := bimWrite(oldbimvalue.asUInt,wasTaken)
        }
    }

    when(reseting){
        bimRam.write(resetIdx,VecInit(Seq.fill(bankWidth){2.U}), (~(0.U(bankWidth.W))).asBools)
    }.elsewhen(s1update.valid && s1update.bits.isCommitUpdate){
        bimRam.write(s1updateIdx.asUInt,s1updatewData,s1updatewMask.asUInt.asBools)
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