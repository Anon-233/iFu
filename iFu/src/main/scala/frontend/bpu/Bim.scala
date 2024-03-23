package iFu.frontend

import chisel3._
import chisel3.util._

import iFu.util._
import iFu.frontend.FrontendUtils._

class BIMPredictMeta extends Bundle with HasBimParameters {
    val bim = UInt(2.W)
}

class BIMIO extends Bundle with HasBimParameters {
    val s0valid  = Input(Bool())
    val s0pc     = Input(UInt(vaddrBits.W))

    val s2taken  = Output(Vec(bankWidth, Bool()))

    val s3meta   = Output(Vec(bankWidth, new BIMPredictMeta))

    val s1update = Input(Valid(new BankedUpdateInfo))
}

class BimPredictor extends Module with HasBimParameters {
    val io = IO(new BIMIO)

    val bim_ram = SyncReadMem(nSets, Vec(bankWidth, UInt(2.W)))

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
    val s0_tag = fetchIdx(io.s0pc)

    // s0 send request, s1 get response, s2 use response
    val s2_bim = RegNext(VecInit(bim_ram.read(s0_tag.asUInt,io.s0valid).map(_.asTypeOf(UInt(2.W)))))

    // val s2_valid = RegNext(RegNext(io.s0valid))

    for (w <- 0 until bankWidth) {
        // val resp_valid = !reset_en && s2_valid
        // io.s2taken(w) := resp_valid && s2_bim(w)(1)
        io.s2taken(w) := s2_bim(w)(1)
    }
// ---------------------------------------------

// ---------------------------------------------
//      Prepare Meta for Update
    val s2_meta = Wire(Vec(bankWidth, new BIMPredictMeta))
    for (w <- 0 until bankWidth) {
        s2_meta(w).bim := s2_bim(w)
    }
    io.s3meta := RegNext(s2_meta)
// ---------------------------------------------

// ---------------------------------------------
//      Update Logic
    val s1_update      = io.s1update
    val s1_update_idx  = fetchIdx(io.s1update.bits.pc)
    val s1_update_meta = VecInit(s1_update.bits.meta.map(_.bimMeta))

    val s1_update_mask = Wire(Vec(bankWidth,Bool()))
    val s1_update_data = Wire(Vec(bankWidth, UInt(2.W)))

    // TODO: why we need this?
    val wr_bypass_regs    = Reg(Vec(nWrBypassEntries, Vec(bankWidth, UInt(2.W))))
    val wr_bypass_idxs    = Reg(Vec(nWrBypassEntries, UInt(log2Ceil(nSets).W)))
    val wr_bypass_enq_idx = RegInit(0.U(log2Ceil(nWrBypassEntries).W))

    val wr_bypass_hits = VecInit((0 until nWrBypassEntries).map { i =>
        !reset_en &&
        wr_bypass_idxs(i) === s1_update_idx(log2Ceil(nSets) - 1, 0)
    })
    val wr_bypass_hit     = wr_bypass_hits.reduce(_||_)
    val wr_bypass_hit_idx = PriorityEncoder(wr_bypass_hits)

    for (w <- 0 until bankWidth) {
        s1_update_mask(w) := false.B
        s1_update_data(w) := Mux(wr_bypass_hit, wr_bypass_regs(wr_bypass_hit_idx)(w), s1_update_meta(w).asUInt)

        val update_pc  = s1_update.bits.pc + (w << 2).U
        val update_idx = fetchIdx(update_pc)

        when(
            s1_update.bits.brMask(w) ||
            (s1_update.bits.cfiIdx.valid && s1_update.bits.cfiIdx.bits === w.U)
        ) {
            val was_taken = (
                (s1_update.bits.cfiIdx.valid) &&
                (s1_update.bits.cfiIdx.bits === w.U) &&
                (
                    (s1_update.bits.cfiIsBr && s1_update.bits.brMask(w) && s1_update.bits.cfiTaken) ||
                    s1_update.bits.cfiIsJal
                )
            )
            val old_bim = Mux(
                wr_bypass_hit,
                wr_bypass_regs(wr_bypass_hit_idx)(w),
                s1_update_meta(w).asUInt
            )

            s1_update_mask(w) := true.B
            s1_update_data(w) := bimWrite(old_bim, was_taken)
        }
    }

    bim_ram.write(
        Mux(reset_en, reset_idx, s1_update_idx),
        Mux(reset_en, VecInit(Seq.fill(bankWidth){ 2.U(2.W) }), s1_update_data),
        Mux(reset_en, (~(0.U(bankWidth.W))), s1_update_mask.asUInt).asBools
    )

    when (s1_update_mask.reduce(_||_) && s1_update.valid && s1_update.bits.isCommitUpdate) {
        when (wr_bypass_hit) {
            wr_bypass_regs(wr_bypass_hit_idx) := s1_update_data
        } .otherwise {
            wr_bypass_regs(wr_bypass_enq_idx) := s1_update_data
            wr_bypass_idxs(wr_bypass_enq_idx) := s1_update_idx
            wr_bypass_enq_idx := WrapInc(wr_bypass_enq_idx, nWrBypassEntries)
        }
    }
// ---------------------------------------------
}
