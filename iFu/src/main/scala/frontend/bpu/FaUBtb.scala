package iFu.frontend

import scala.math.min

import chisel3._
import chisel3.util._
import chisel3.util.random.LFSR

import iFu.frontend.FrontendUtils._

class UBTBEntry extends Bundle with HasUbtbParameters {
    val offset = SInt(offsetSz.W)   // signed offset
}

class PredState extends Bundle {
    // 00 <-> 10 <-> 11 <-> 01
    val state = UInt(2.W)

    def isTaken = state(0)
    def init(taken: Bool) = {
        state := Mux(taken, 1.U, 0.U)
    }
    def update(taken: Bool) = {
        val next = Cat(
            taken ^ state(0),
            state(1) & (taken ^ state(0))
        )
        this.state := next
    }
}

// 用于BTB里面存储的信息，进行判断命中等信息
class UBTBMeta extends Bundle with HasUbtbParameters {
    val tag   = UInt(tagSz.W)
    val is_br = Bool()
    val state = new PredState
}

// 返回给外面预测器的信息
class UBTBPredictMeta extends Bundle with HasUbtbParameters {
    val hit       = Bool()
    val write_way = UInt(log2Ceil(nWays).W)
}

class UBTBIO extends Bundle with HasUbtbParameters {
    val s1valid  = Input(Bool())
    val s1pc     = Input(UInt(vaddrBits.W))

    val s1targs  = Output(Vec(bankWidth, Valid(UInt(vaddrBits.W))))
    val s1taken  = Output(Vec(bankWidth, Bool()))
    val s1br     = Output(Vec(bankWidth, Bool()))
    val s1jal    = Output(Vec(bankWidth, Bool()))

    val s3meta   = Output(Vec(bankWidth, new UBTBPredictMeta))

    val s1update = Input(Valid(new BankedUpdateInfo))
}

class FaUBtbPredictior  extends Module with HasUbtbParameters {
    val io = IO(new UBTBIO)

    val valid = RegInit(VecInit(Seq.fill(nWays * bankWidth)(false.B)))
    val meta  = Reg(Vec(nWays, Vec(bankWidth, new UBTBMeta)))
    val btb   = Reg(Vec(nWays, Vec(bankWidth, new UBTBEntry)))

// ---------------------------------------------
//      Predict Logic
    val s1_tag = fetchIdx(io.s1pc)
    val s1_hit_OHs = VecInit((0 until bankWidth) map { i =>
        VecInit((0 until nWays) map { w =>
            (meta(w)(i).tag === s1_tag) && valid(Cat(w.U(log2Ceil(nWays).W), i.U(log2Ceil(bankWidth).W)))
        })
    })
    val s1_hits = s1_hit_OHs.map(_.asUInt.orR)
    val s1_hit_ways = s1_hit_OHs.map(oh => PriorityEncoder(oh))

    for (w <- 0 until bankWidth) {
        val resp_valid = io.s1valid && s1_hits(w)
        val entry_meta = meta(s1_hit_ways(w))(w)

        io.s1targs(w).valid := resp_valid
        io.s1targs(w).bits  := (
            (io.s1pc | (w << 2).U).asSInt + btb(s1_hit_ways(w))(w).offset
        ).asUInt
        io.s1br(w) := resp_valid && entry_meta.is_br
        io.s1jal(w) := resp_valid && !entry_meta.is_br
        // taken: 
        //     1. br and we predict taken
        //     2. jal
        io.s1taken(w) := entry_meta.state.isTaken || !entry_meta.is_br
    }
// ---------------------------------------------

// ---------------------------------------------
//      Prepare Meta for Update
    val repl_way_update_en = io.s1valid && !s1_hits.reduce(_||_)
    val repl_way = LFSR(16, repl_way_update_en)(log2Ceil(nWays) - 1, 0)
    val s1_meta = Wire(Vec(bankWidth, new UBTBPredictMeta)) // 这个是返回给外面的信息 和meta不是同一个类型
    for (w <- 0 until bankWidth) {
        s1_meta(w).hit := s1_hits(w)
        s1_meta(w).write_way := Mux(
            s1_hits(w),
            s1_hit_ways(w),
            repl_way
        )
    }
    io.s3meta := RegNext(RegNext(s1_meta))
// ---------------------------------------------

// ---------------------------------------------
//      Update Logic
    val s1_update         = io.s1update
    val s1_update_cfi_idx = s1_update.bits.cfiIdx.bits
    val s1_update_meta    = VecInit(s1_update.bits.meta.map(_.ubtbMeta))
    val s1_update_way     = VecInit(s1_update_meta.map(_.write_way))

    // we don't care if offset > 2^13, BTB will handle it
    val new_offset = (
        (s1_update.bits.target.asSInt) -
        (s1_update.bits.pc.asSInt + (s1_update.bits.cfiIdx.bits << 2).asSInt)
    )

    // update target offset
    val wen = (
        s1_update.valid && s1_update.bits.isCommitUpdate &&
        s1_update.bits.cfiTaken && s1_update.bits.cfiIdx.valid
    )
    for (w <- 0 until bankWidth) {
        when (wen) {
            btb(s1_update_way(w))(s1_update_cfi_idx).offset := new_offset
        } 
    }

    // update predictor state
    for (w <- 0 until bankWidth) {
        val branch_taken = (
            s1_update.valid && s1_update.bits.isCommitUpdate && (
                s1_update.bits.brMask(w) ||
                (
                    s1_update.bits.cfiIdx.valid &&
                    s1_update.bits.cfiTaken &&
                    s1_update.bits.cfiIdx.bits === w.U
                )
            )
        )

        when (branch_taken) {
            val wastaken      = branch_taken || s1_update.bits.cfiIsJal
            val s1_update_tag = fetchIdx(s1_update.bits.pc)

            valid(Cat(s1_update_way(w), w.U(log2Ceil(bankWidth).W))) := true.B
            meta(s1_update_way(w))(w).is_br := s1_update.bits.brMask(w)
            meta(s1_update_way(w))(w).tag   := s1_update_tag

            when (s1_update_meta(w).hit) {
                meta(s1_update_way(w))(w).state.update(wastaken)
            } .otherwise {
                meta(s1_update_way(w))(w).state.init(wastaken)
            }
        }
    }
// ---------------------------------------------
}

