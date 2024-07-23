package iFu.frontend

import chisel3._
import chisel3.util._
import iFu.frontend.FrontendUtils._

import scala.math.min
import iFu.common.Consts._
import chisel3.util.random.LFSR
import iFu.frontend.FrontendUtils._
import ram.SDPRam

class BTBEntry extends Bundle with HasBtbParameters {
    val offset   = SInt(offsetSz.W)
    val extended = Bool()
}

class BTBMeta extends Bundle with HasBtbParameters {
    val tag   = UInt(tagSz.W)
    val is_br = Bool()
}

class BTBPredictMeta extends Bundle with HasBtbParameters {
    val writeWay = UInt(log2Ceil(nWays).W)
    val hit = Bool()
}

class BTBIO extends Bundle with HasBtbParameters {
    val s0valid = Input(Bool())
    val s0pc    = Input(UInt(vaddrBits.W))

    val s2br    = Output(Vec(fetchWidth, Bool()))
    val s2jal   = Output(Vec(fetchWidth, Bool()))
    val s2taken = Output(Vec(fetchWidth, Bool()))
    val s2targs = Output(Vec(fetchWidth, Valid(UInt(vaddrBits.W))))

    val s3meta  = Output(Vec(fetchWidth, new BTBPredictMeta))

    val s1update = Input(Valid(new BranchPredictionUpdate))
}

class BTBPredictor extends Module with HasBtbParameters{
    val io = IO(new BTBIO)

    val meta = Seq.fill(nWays) { Module(new SDPRam(nSets, new BTBMeta, fetchWidth)) }
    val btb  = Seq.fill(nWays) { Module(new SDPRam(nSets, new BTBEntry, fetchWidth)) }
    val ebtb = Module(new SDPRam(extendedNSets, UInt(vaddrBits.W)))

// ---------------------------------------------
//      Reset Logic
    val reset_en  = RegInit(true.B)
    val reset_idx = RegInit(0.U(log2Ceil(nSets).W))
    when (reset_en) {
        reset_idx := reset_idx + 1.U
    }
    when (reset_idx === (nSets - 1).U) {
        reset_en := false.B
    }
// ---------------------------------------------

// ---------------------------------------------
//      Predict Logic
    val s0_valid   = io.s0valid
    val s0_tag_idx = fetchIdx(io.s0pc)

    val s1_valid   = RegNext(io.s0valid)
    val s1_pc      = RegNext(io.s0pc)
    val s1_tag_idx = fetchIdx(s1_pc)

    // stage 1: read btb, meta, ebtb, and prepare hit signals
    val s1_btb = VecInit(btb.map(b => {b.io.raddr := s0_tag_idx
        b.io.rdata}))
    val s1_meta = VecInit(meta.map(m => {m.io.raddr := s0_tag_idx
        m.io.rdata
    }))
    ebtb.io.raddr := s0_tag_idx
    val s1_ebtb = ebtb.io.rdata.head

    val s1_tag = s1_tag_idx >> log2Ceil(nSets)
    val s1_hit_OHs = VecInit((0 until fetchWidth) map { i =>
        VecInit((0 until nWays) map { w =>
            s1_meta(w)(i).tag === s1_tag.asUInt
        })
    })
    val s1_hits = s1_hit_OHs.map(_.asUInt.orR)
    val s1_hit_ways = s1_hit_OHs.map(oh => PriorityEncoder(oh))

    for (w <- 0 until fetchWidth) {
        // s1 stage
        val resp_valid = !reset_en && s1_valid && s1_hits(w)
        val entry_meta = s1_meta(s1_hit_ways(w))(w)
        val entry_btb  = s1_btb(s1_hit_ways(w))(w)
        // s2 stage
        val is_br  = RegNext(resp_valid && entry_meta.is_br)
        val is_jal = RegNext(resp_valid && !entry_meta.is_br)
        io.s2br(w)          := is_br
        io.s2jal(w)         := is_jal
        io.s2taken(w)       := is_jal
        io.s2targs(w).valid := RegNext(resp_valid)
        io.s2targs(w).bits  := RegNext(Mux(entry_btb.extended,
                s1_ebtb,
                ((fetchAlign(s1_pc) | (w << 2).asUInt).asSInt + entry_btb.offset.asSInt).asUInt
        ))
    }
// ---------------------------------------------

// ---------------------------------------------
//      Prepare Meta for Update
    val repl_way_update_en = s1_valid && !s1_hits.reduce(_||_)
    val repl_way = LFSR(nWays, repl_way_update_en)(log2Ceil(nWays) - 1, 0)

    val s1_update_info = Wire(Vec(fetchWidth, new BTBPredictMeta))
    for (w <- 0 until fetchWidth) {
        s1_update_info(w).hit := s1_hits(w)
        s1_update_info(w).writeWay := Mux(
            s1_hits(w),
            s1_hit_ways(w),
            repl_way
        )
    }
    io.s3meta := RegNext(RegNext(s1_update_info))
// ---------------------------------------------

// ---------------------------------------------
//      Update Logic
    val s1_update         = io.s1update
    val s1_update_cfi_idx = s1_update.bits.cfiIdx.bits
    val s1_update_meta    = VecInit(s1_update.bits.meta.map(_.BTBMeta))
    val s1_update_ways    = VecInit(s1_update_meta.map(_.writeWay))
    val s1_update_way     = s1_update_ways(s1_update_cfi_idx)
    val s1_update_idx     = fetchIdx(s1_update.bits.pc)

    val max_offset = Cat(0.B, ~0.U((offsetSz - 1).W)).asSInt
    val min_offset = Cat(1.B,  0.U((offsetSz - 1).W)).asSInt
    val new_offset = s1_update.bits.target.asSInt -
    (fetchAlign(s1_update.bits.pc) | (s1_update.bits.cfiIdx.bits << 2).asUInt).asSInt

    val need_extend = new_offset > max_offset || new_offset < min_offset

    val s1_update_wmeta = Wire(Vec(fetchWidth, new BTBMeta))
    for (w <- 0 until fetchWidth) {
        s1_update_wmeta(w).tag   := s1_update_idx >> log2Ceil(nSets)
        s1_update_wmeta(w).is_br := s1_update.bits.brMask(w)
    }

    val s1_update_wbtb = Wire(new BTBEntry)
    s1_update_wbtb.offset   := new_offset
    s1_update_wbtb.extended := need_extend

    val s1_update_wbtb_mask = UIntToOH(s1_update_cfi_idx) & Fill(fetchWidth, s1_update.valid && s1_update.bits.cfiIdx.valid && s1_update.bits.cfiTaken)
    val s1_update_wmeta_mask = s1_update_wbtb_mask

    for (w <- 0 until nWays) {
        meta(w).io.wen := reset_en || s1_update_way === w.U
        meta(w).io.waddr := Mux(reset_en, reset_idx, s1_update_idx)
        meta(w).io.wdata := Mux(reset_en, VecInit(Seq.fill(fetchWidth) {0.U.asTypeOf(new BTBMeta)}), s1_update_wmeta)
        meta(w).io.wstrobe := Mux(reset_en, ~0.U(fetchWidth.W), s1_update_wmeta_mask.asUInt)
        btb(w).io.wen := reset_en || s1_update_way === w.U
        btb(w).io.waddr := Mux(reset_en, reset_idx, s1_update_idx)
        btb(w).io.wdata := VecInit(Seq.fill(fetchWidth) {Mux(reset_en, 0.U.asTypeOf(new BTBEntry), s1_update_wbtb)})
        btb(w).io.wstrobe := Mux(reset_en, ~0.U(fetchWidth.W), s1_update_wbtb_mask.asUInt)
    }

    ebtb.io.wen := s1_update_wbtb_mask =/= 0.U && need_extend
    ebtb.io.waddr := s1_update_idx
    ebtb.io.wdata.head := s1_update.bits.target
    ebtb.io.wstrobe := 1.U
// ---------------------------------------------

// ---------------------------------------------
//      Performance Counter
    // TODO
// ---------------------------------------------
}
