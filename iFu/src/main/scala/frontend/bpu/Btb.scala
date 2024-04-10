package iFu.frontend

import chisel3._
import chisel3.util._
import iFu.frontend.FrontendUtils._
import scala.math.min
import iFu.common.Consts._
import chisel3.util.random.LFSR

import iFu.frontend.FrontendUtils._

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

    val s2br    = Output(Vec(bankWidth, Bool()))
    val s2jal   = Output(Vec(bankWidth, Bool()))
    val s2taken = Output(Vec(bankWidth, Bool()))
    val s2targs = Output(Vec(bankWidth, Valid(UInt(vaddrBits.W))))

    val s3meta  = Output(Vec(bankWidth, new BTBPredictMeta))

    val s1update = Input(Valid(new BankedUpdateInfo))
}

class BTBPredictor extends Module with HasBtbParameters{
    val io = IO(new BTBIO)

    val meta = Seq.fill(nWays) {
        SyncReadMem(nSets, Vec(bankWidth, UInt(BTBMetaSz.W)))
    }
    val btb  = Seq.fill(nWays) {
        SyncReadMem(nSets, Vec(bankWidth, UInt(BTBEntrySz.W)))
    }
    val ebtb = SyncReadMem(extendedNSets, UInt(vaddrBits.W))

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
    val s1_btb = VecInit(btb.map(b => VecInit(
        b.read(s0_tag_idx.asUInt, s0_valid).map(_.asTypeOf(new BTBEntry))
    )))
    val s1_meta = VecInit(meta.map(m => VecInit(
        m.read(s0_tag_idx.asUInt, s0_valid).map(_.asTypeOf(new BTBMeta))
    )))
    val s1_ebtb = ebtb.read(s0_tag_idx.asUInt, s0_valid)

    val s1_tag = s1_tag_idx >> log2Ceil(nSets)
    val s1_hit_OHs = VecInit((0 until bankWidth) map { i =>
        VecInit((0 until nWays) map { w =>
            s1_meta(w)(i).tag === s1_tag.asUInt
        })
    })
    val s1_hits = s1_hit_OHs.map(_.asUInt.orR)
    val s1_hit_ways = s1_hit_OHs.map(oh => PriorityEncoder(oh))

    for (w <- 0 until bankWidth) {
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
                ((s1_pc | (w << 2).asUInt).asSInt + entry_btb.offset.asSInt).asUInt
        ))
    }
// ---------------------------------------------

// ---------------------------------------------
//      Prepare Meta for Update
    val repl_way_update_en = s1_valid && !s1_hits.reduce(_||_)
    val repl_way = LFSR(nWays, repl_way_update_en)(log2Ceil(nWays) - 1, 0)

    val s1_update_info = Wire(Vec(bankWidth, new BTBPredictMeta))
    for (w <- 0 until bankWidth) {
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

    val max_offset = Cat(0.B, ~(0.U((offsetSz - 1).W))).asSInt
    val min_offset = Cat(1.B,  (0.U((offsetSz - 1).W))).asSInt
    val new_offset = (
        (s1_update.bits.target.asSInt) -
        (s1_update.bits.pc + (s1_update.bits.cfiIdx.bits << 2)).asSInt
    )
    val need_extend = (
        new_offset > max_offset || new_offset < min_offset
    )

    val s1_update_wmeta = Wire(Vec(bankWidth, new BTBMeta))
    for (w <- 0 until bankWidth) {
        s1_update_wmeta(w).tag   := Mux(
            s1_update.bits.btbMispredicts(w),
            0.U,
            s1_update_idx >> log2Ceil(nSets)
        )
        s1_update_wmeta(w).is_br := s1_update.bits.brMask(w)
    }

    val s1_update_wbtb = Wire(new BTBEntry)
    s1_update_wbtb.offset   := new_offset
    s1_update_wbtb.extended := need_extend

    val s1_update_wbtb_mask = (
        UIntToOH(s1_update_cfi_idx) &
        Fill(bankWidth, s1_update.bits.cfiIdx.valid && s1_update.bits.cfiTaken && s1_update.bits.isCommitUpdate)
    )
    val s1_update_wmeta_mask = (
        (s1_update_wbtb_mask | s1_update.bits.brMask) &
        ( Fill(bankWidth, s1_update.valid && s1_update.bits.isCommitUpdate) |  
         (Fill(bankWidth, s1_update.valid) & s1_update.bits.btbMispredicts)
        )
    )

    for (w <- 0 until nWays) {
        when (reset_en || s1_update_way === w.U){
            meta(w).write(
                Mux(reset_en, reset_idx, s1_update_idx),
                Mux(reset_en,
                    VecInit(Seq.fill(bankWidth) { 0.U(BTBMetaSz.W) }),
                    VecInit(s1_update_wmeta.map(_.asUInt))
                ),
                Mux(reset_en,
                    ~(0.U(bankWidth.W)),
                    (s1_update_wmeta_mask).asUInt
                ).asBools
            )
            btb(w).write(
                Mux(reset_en, reset_idx, s1_update_idx),
                Mux(reset_en, 
                    VecInit(Seq.fill(bankWidth) { 0.U(BTBEntrySz.W) }),
                    VecInit(Seq.fill(bankWidth) { s1_update_wbtb.asUInt })
                ),
                Mux(reset_en,
                    ~(0.U(bankWidth.W)),
                    s1_update_wbtb_mask.asUInt
                ).asBools
            )
        }
    }

    when (s1_update_wbtb_mask =/= 0.U && need_extend) {
        ebtb.write(s1_update_idx.asUInt, s1_update.bits.target)
    }
// ---------------------------------------------

// ---------------------------------------------
//      Performance Counter
    // TODO
// ---------------------------------------------
}
