package iFu.frontend

import chisel3._
import chisel3.util._
import chisel3.util.random.LFSR

import iFu.frontend.FrontendUtils._
import scala.math.min

class BTBEntry extends Bundle with HasBtbParameters {
    val offset   = SInt(offsetSz.W)
    val extended = Bool()
}

class BTBMeta extends Bundle with HasBtbParameters {
    val tag   = UInt(tagSz.W)
    val is_br = Bool()
}

class BTBPredictMeta extends Bundle with HasBtbParameters {
    val hit       = Bool()
    val write_way = UInt(log2Ceil(nWays).W)
}

class BTBIO extends Bundle with HasBtbParameters {
    val s0valid  = Input(Bool())
    val s0pc     = Input(UInt(vaddrBits.W))

    val s2targs  = Output(Vec(bankWidth, Valid(UInt(vaddrBits.W))))
    val s2taken  = Output(Vec(bankWidth, Bool()))
    val s2br     = Output(Vec(bankWidth, Bool()))
    val s2jal    = Output(Vec(bankWidth, Bool()))

    val s3meta   = Output(Vec(bankWidth, new BTBPredictMeta))

    val s1update = Input(Valid(new BankedUpdateInfo))
}

class BtbPredictor extends Module with HasBtbParameters {
    val io = IO(new BTBIO)

    val valid = Seq.fill(nWays) { SyncReadMem(nSets, Vec(bankWidth, Bool())) }
    val meta  = Seq.fill(nWays) { SyncReadMem(nSets, Vec(bankWidth, new BTBMeta)) }
    val btb   = Seq.fill(nWays) { SyncReadMem(nSets, Vec(bankWidth, new BTBEntry)) }
    val ebtb  = SyncReadMem(extendedNSets, UInt(vaddrBits.W))

// ---------------------------------------------
//      Reset Logic
    val reset_en = RegInit(true.B)
    val reset_idx   = RegInit(0.U(log2Ceil(nSets).W))
    when (reset_en) {
        reset_idx := reset_idx + 1.U
    }
    when (reset_idx === (nSets-1).U) {
        reset_en := false.B
    }
// ---------------------------------------------

// ---------------------------------------------
//      Predict Logic
    val s0_tag_idx = fetchIdx(io.s0pc)

    // s0 send read request and s1 receive read response
    val s1_valids = VecInit(valid.map(v => v.read(s0_tag_idx.asUInt, io.s0valid)))
    val s1_meta   = VecInit(meta.map(m => m.read(s0_tag_idx.asUInt, io.s0valid)))
    val s1_btb    = VecInit(btb.map(b => b.read(s0_tag_idx.asUInt, io.s0valid)))
    val s1_ebtb   = ebtb.read(s0_tag_idx.asUInt, io.s0valid)

    val s1_valid   = RegNext(io.s0valid)
    val s1_pc      = RegNext(io.s0pc)

    val s1_tag_idx = fetchIdx(s1_pc)
    val s1_tag     = s1_tag_idx >> log2Ceil(nSets)
    val s1_idx     = s1_tag_idx(log2Ceil(nSets) - 1, 0)

    val s1_hit_OHs = VecInit((0 until bankWidth) map { idx =>
        VecInit((0 until nWays) map { n =>
            (s1_meta(n)(idx).tag === s1_tag.asUInt) &&
            s1_valids(n)(idx)
        })
    })

    val s1_hits     = s1_hit_OHs.map(_.asUInt.orR)
    val s1_hit_ways = s1_hit_OHs.map(oh => PriorityEncoder(oh))

    for (w <- 0 until bankWidth) {
        val resp_valid = !reset_en && s1_valid && s1_hits(w)
        val entry_meta = s1_meta(s1_hit_ways(w))(w)
        val entry_btb  = s1_btb(s1_hit_ways(w))(w)

        val is_br = resp_valid &&  entry_meta.is_br
        val is_bl = resp_valid && !entry_meta.is_br

        // s2 send response to frontend
        io.s2targs(w).valid := RegNext(resp_valid)
        io.s2targs(w).bits  := RegNext(Mux(
            entry_btb.extended,  // if offset > 2^13
            s1_ebtb,
            ((s1_pc | (w << 2).U).asSInt + entry_btb.offset).asUInt
        ))
        io.s2br(w)    := RegNext(is_br)
        io.s2jal(w)   := RegNext(is_bl)
        // btb can only predict taken for bl
        io.s2taken(w) := RegNext(is_bl)
    }

// ---------------------------------------------
//      Prepare Meta for Update
    val repl_way_update_en = s1_valid && !s1_hits.reduce(_||_)
    val repl_way = LFSR(16, repl_way_update_en)(log2Ceil(nWays) - 1, 0)
    val s1_meta = Wire(Vec(bankWidth, new BTBPredictMeta))
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
    val s1_update_cfi_idx = s1update.bits.cfiIdx.bits
    val s1_update_meta    = VecInit(s1_update.bits.meta.map(_.btbMeta))

    val max_offset = (~(0.U)((offsetSz - 1).W)).asSInt
    val min_offset = Cat(1.U(1.W), (0.U)((offsetSz - 1).W)).asSInt
    val new_offset = (
        s1_update.bits.target.asSInt -
        (s1update.bits.pc.asSInt + (s1update.bits.cfiIdx.bits << 2).asSInt)
    )
    // handle offset > 2^13
    val need_extend = (new_offset > max_offset) || (new_offset < min_offset)

    val s1_update_tag_idx = fetchIdx(s1_update.bits.pc)
    val s1_update_tag     = s1_update_tag_idx >> log2Ceil(nSets)
    val s1_update_idx     = s1_update_tag_idx(log2Ceil(nSets) - 1, 0)

    val s1_update_btb_mask = (
        UIntToOH(s1_update_cfi_idx) &   // position
        Fill(                           // enable
            bankWidth,
            s1_update.bits.cfiIdx.valid &&
            s1_update.bits.cfiTaken &&
            s1_update.bits.isCommitUpdate
        )
    )
    val s1_update_meta_mask = (
        (s1_update_btb_mask | s1_update.bits.brMask) &
        (Fill(bankWidth, s1_update.valid && s1_update.bits.isCommitUpdate)) |
        (Fill(bankWidth, s1_update.valid) & s1update.bits.btbMispredicts)
    )

    val s1_update_btb_data = Wire(new BTBEntry)
    s1_update_btb_data.offset   := new_offset
    s1_update_btb_data.extended := need_extend
    val s1_update_meta_data = Wire(Vec(bankWidth, new BTBMeta))
    for (w <- 0 until bankWidth) {
        s1_update_meta_data(w).tag := Mux(
            s1_update.bits.btbMispredicts(w),
            0.U,
            s1_update_tag
        )
        s1_update_meta_data(w).is_br := s1_update.bits.brMask(w)
    }

    for (w <- 0 until nWays) {
        when (reset_en) {
            valid(w).write(
                reset_idx,
                VecInit(Seq.fill(bankWidth){ false.B }),
                (~(0.U(bankWidth.W))).asBools
            )
            meta(w).write(
                reset_idx,
                VecInit(Seq.fill(bankWidth){ 0.U.asTypeOf(new BTBMeta) }),
                (~(0.U(bankWidth.W))).asBools
            )
            btb(w).write(
                reset_idx,
                VecInit(Seq.fill(bankWidth){ 0.U.asTypeOf(new BTBEntry) }),
                (~(0.U(bankWidth.W))).asBools
            )
        } .elsewhen (s1_update_meta(w).write_way === w.U && s1_update_meta(w).hit) {
            valid(w).write(
                s1_update_idx,
                s1_update_btb_mask.asBools,
                s1_update_btb_mask.asBools
            )
            meta(w).write(
                s1_update_idx,
                s1_update_meta_data,
                s1_update_meta_mask.asBools
            )
            btb(w).write(
                s1_update_idx,
                VecInit(Seq.fill(bankWidth){s1updateWBtbData}),
                s1_update_btb_mask.asBools
            )
        }
    }

    when (s1_update_btb_mask =/= 0.U && need_extend) {
        ebtb.write(s1_update_idx, s1update.bits.target)
    }
}
