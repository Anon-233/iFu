package iFu.frontend

import scala.math.min

import chisel3._
import chisel3.util._

import iFu.frontend.FrontendUtils._
import iFu.util._

class TagePredictMeta extends Bundle with HasTageParameters {
    val provider    = Valid(UInt(log2Ceil(tageNTables).W))
    val altDiffers  = Output(Bool())
    val providerU   = Output(UInt(2.W))
    val providerCtr = Output(UInt(3.W))
    val allocate    = Valid(UInt(log2Ceil(tageNTables).W))
}

class TageTable (    // uBitPeriod -> the period of clearing u bits
    val nRows: Int, val tagSz: Int, val histLength: Int, val uBitPeriod: Int
) extends Module with HasTageParameters {
// ---------------------------------------------
//      Class Definitions
    class TageEntry extends Bundle with HasTageParameters {
        val valid = Bool()
        val tag   = UInt(tagSz.W)
        val pred  = UInt(3.W)   // 3-bit counter
    }

    class TageResp extends Bundle {
        val pred = UInt(3.W)
        val u    = UInt(2.W)
    }

    class TAGETableIO extends Bundle with HasBtbParameters {
        val s1_valid        = Input(Bool())
        val s1_pc           = Input(UInt(vaddrBits.W))
        val s1_ghist        = Input(UInt(globalHistoryLength.W))

        val s3_resp         = Output(Vec(bankWidth, Valid(new TageResp)))

        val update_mask     = Input(Vec(bankWidth, Bool()))
        val update_taken    = Input(Vec(bankWidth, Bool()))
        val update_alloc    = Input(Vec(bankWidth, Bool()))
        val update_old_pred = Input(Vec(bankWidth, UInt(3.W)))
        val update_pc       = Input(UInt(vaddrBits.W))
        val update_hist     = Input(UInt(globalHistoryLength.W))
        val update_u_mask   = Input(Vec(bankWidth, Bool()))
        val update_u        = Input(Vec(bankWidth, UInt(2.W)))
    }
// ---------------------------------------------

    val io = IO(new TAGETableIO)

    val hi_us = SyncReadMem(nRows, Vec(bankWidth, Bool()))
    val lo_us = SyncReadMem(nRows, Vec(bankWidth, Bool()))
    val table = SyncReadMem(nRows, Vec(bankWidth, new TageEntry))

// ---------------------------------------------
//      Helper functions
    def computeFoldedHist(hist: UInt, l: Int): UInt = {
        val nChunks = (globalHistoryLength + l - 1) / l
        val hist_chunks = (0 until nChunks) map { i =>
            hist(min((i + 1) * l, globalHistoryLength) - 1, i * l)
        }
        hist_chunks.reduce(_ ^ _)
    }

    def computeTagandHash(unhashed_idx: UInt, hist: UInt): (UInt, UInt) = {
        val idx_history = computeFoldedHist(hist, log2Ceil(nRows))
        val idx = (unhashed_idx ^ idx_history)(log2Ceil(nRows) - 1, 0)
        val tag_history = computeFoldedHist(hist, tagSz)
        val tag = ((unhashed_idx >> log2Ceil(nRows)).asUInt ^ tag_history)(tagSz - 1, 0)
        (idx, tag)
    }

    def inc_ctr(ctr: UInt, taken: Bool): UInt = {
        Mux(!taken,
            Mux(ctr === 0.U, 0.U, ctr - 1.U),
            Mux(ctr === 7.U, 7.U, ctr + 1.U)
        )
    }
// ---------------------------------------------

// ---------------------------------------------
//      Reset Logic
    val reset_en  = RegInit(true.B)
    val reset_idx = RegInit(0.U(log2Ceil(nRows).W))
    when (reset_en) {
        reset_idx := reset_idx + 1.U
    }
    when (reset_idx === (nRows - 1).U) {
        reset_en := false.B
    }
// ---------------------------------------------

// ---------------------------------------------
//      Predict Logic
    val (s1_hash_idx, s1_tag) = computeTagandHash(fetchIdx(io.s1_pc), io.s1_ghist)

    val s2_tag = RegNext(s1_tag)

    val s2_tage = VecInit(
        table.read(s1_hash_idx, io.s1_valid).map {_.asTypeOf(new TageEntry)}
    )
    val s2_hi_us = hi_us.read(s1_hash_idx, io.s1_valid)
    val s2_lo_us = lo_us.read(s1_hash_idx, io.s1_valid)

    val s2_hits = VecInit(s2_tage.map(t => t.valid && t.tag === s2_tag))

    for (w <- 0 until bankWidth) {
        io.s3_resp(w).valid     := RegNext(s2_hits(w))
        io.s3_resp(w).bits.pred := RegNext(s2_tage(w).pred)
        io.s3_resp(w).bits.u    := RegNext(Cat(s2_hi_us(w), s2_lo_us(w)))
    }
// ---------------------------------------------

// ---------------------------------------------
//      Update Logic
    val clear_u_cnt = RegInit(0.U((log2Ceil(uBitPeriod) + log2Ceil(nRows) + 1).W))
    when (reset_en) {
        clear_u_cnt := 1.U
    } .otherwise {
        clear_u_cnt := clear_u_cnt + 1.U
    }

    val clearing_u     = clear_u_cnt(log2Ceil(uBitPeriod) - 1, 0) === 0.U
    val clearing_hi_us = clearing_u && clear_u_cnt(log2Ceil(uBitPeriod) + log2Ceil(nRows)) === 1.U
    val clearing_lo_us = clearing_u && clear_u_cnt(log2Ceil(uBitPeriod) + log2Ceil(nRows)) === 0.U
    val clearing_u_idx = clear_u_cnt >> log2Ceil(uBitPeriod)

    val (update_idx, update_tag) = computeTagandHash(fetchIdx(io.update_pc), io.update_hist)

    val update_hi_us_data = Wire(Vec(bankWidth, Bool()))
    val update_lo_us_data = Wire(Vec(bankWidth, Bool()))
    val update_table_data = Wire(Vec(bankWidth, new TageEntry()))

    val wr_bypass_tag     = Reg(Vec(nWrBypassEntries, UInt(tagSz.W)))
    val wr_bypass_idx     = Reg(Vec(nWrBypassEntries, UInt(log2Ceil(nRows).W)))
    val wr_bypass_pred    = Reg(Vec(nWrBypassEntries, Vec(bankWidth, UInt(3.W))))
    val wr_bypass_enq_idx = RegInit(0.U(log2Ceil(nWrBypassEntries).W))

    val wr_bypass_hits = VecInit((0 until nWrBypassEntries).map { i =>
        !reset_en &&
        wr_bypass_idx(i) === update_idx &&
        wr_bypass_tag(i) === update_tag
    })

    val wr_bypass_hit     = wr_bypass_hits.reduce(_||_)
    val wr_bypass_hit_idx = PriorityEncoder(wr_bypass_hits)

    for (w <- 0 until bankWidth) {
        update_hi_us_data(w)       := io.update_u(w)(1)
        update_lo_us_data(w)       := io.update_u(w)(0)
        update_table_data(w).pred  := Mux(
            io.update_alloc(w),
            Mux(io.update_taken(w), 4.U, 3.U),
            Mux(
                wr_bypass_hit,
                inc_ctr(wr_bypass_pred(wr_bypass_hit_idx)(w), io.update_taken(w)),
                inc_ctr(io.update_old_pred(w), io.update_taken(w))
            )
        )
        update_table_data(w).valid := true.B
        update_table_data(w).tag   := update_tag
    }

    when (io.update_mask.reduce(_||_)) {
        when (wr_bypass_hit) {
            wr_bypass_pred(wr_bypass_hit_idx) := VecInit(update_table_data.map(_.pred))
        } .otherwise {
            wr_bypass_pred(wr_bypass_enq_idx) := VecInit(update_table_data.map(_.pred))
            wr_bypass_tag(wr_bypass_enq_idx)  := update_tag
            wr_bypass_idx(wr_bypass_enq_idx)  := update_idx
            wr_bypass_enq_idx := WrapInc(wr_bypass_enq_idx, nWrBypassEntries)
        }
    }

    hi_us.write(
        Mux(reset_en,       reset_idx, 
        Mux(clearing_hi_us, clearing_u_idx.asUInt,
                            update_idx)
        ),
        Mux(reset_en,       VecInit(Seq.fill(bankWidth) { false.B }),
        Mux(clearing_hi_us, VecInit(Seq.fill(bankWidth) { false.B }),
                            update_hi_us_data)
        ),
        Mux(reset_en,       VecInit(Seq.fill(bankWidth) { true.B }),
        Mux(clearing_hi_us, VecInit(Seq.fill(bankWidth) { true.B }),
                            io.update_u_mask)
        )
    )
    lo_us.write(
        Mux(reset_en,       reset_idx, 
        Mux(clearing_lo_us, clearing_u_idx.asUInt,
                            update_idx)
        ),
        Mux(reset_en,       VecInit(Seq.fill(bankWidth) { false.B }),
        Mux(clearing_lo_us, VecInit(Seq.fill(bankWidth) { false.B }),
                            update_lo_us_data)
        ),
        Mux(reset_en,       VecInit(Seq.fill(bankWidth) { true.B }),
        Mux(clearing_lo_us, VecInit(Seq.fill(bankWidth) { true.B }),
                            io.update_u_mask)
        )
    )
    table.write(
        Mux(reset_en, reset_idx, update_idx),
        Mux(reset_en,
            VecInit(Seq.fill(bankWidth) { 0.U.asTypeOf(new TageEntry) }),
            update_table_data
        ),
        Mux(reset_en,
            VecInit(Seq.fill(bankWidth) { true.B }),
            io.update_mask
        )
    )
// ---------------------------------------------
}

case class TageParams (
    tableInfo: Seq[Tuple3[Int,Int,Int]] = Seq(
    //   nRows, tagSz, histLength
        (  128,     7,         2),  
        (  128,     7,         4),
        (  256,     8,         8),
        (  256,     8,        16),
        (  128,     9,        32),
        (  128,     9,        64),
    )
)

class TAGEIO extends Bundle with HasTageParameters {
    val f1valid         = Input(Bool())
    val f1pc            = Input(UInt(vaddrBits.W))
    val f1gHist         = Input(UInt(globalHistoryLength.W))
    val previousf3Taken = Input(Vec(bankWidth, Bool()))

    val f3taken         = Output(Vec(bankWidth, Bool()))

    val f3meta          = Output(Vec(bankWidth , new TagePredictMeta))

    val f1update        = Input(Valid(new BankedUpdateInfo))
}

class TagePredictor (
    params: TageParams = TageParams()
) extends Module with HasTageParameters {
    val io = IO(new TAGEIO)

    val tage_tables = params.tableInfo.map {
        case (nRows, tagSz, histLength) => {
            val t = Module(new TageTable(nRows, tagSz, histLength, tageUBitPeriod))
            t.io.s1_valid := io.f1valid
            t.io.s1_pc    := io.f1pc
            t.io.s1_ghist := io.f1gHist
            t
        }
    }

// ---------------------------------------------
//      Helper functions
    def inc_u(u: UInt, alt_differs: Bool, mispredict: Bool): UInt = {
        Mux(!alt_differs, u,
        Mux(mispredict, Mux(u === 0.U, 0.U, u - 1.U),
                        Mux(u === 3.U, 3.U, u + 1.U)))
    }
// ---------------------------------------------

    val table_resps = VecInit(tage_tables.map(_.io.s3_resp))

    val s1updateMeta = VecInit(io.f1update.bits.meta.map(_.tageMeta))
    val s1updateMispredictMask = UIntToOH(io.f1update.bits.cfiIdx.bits)&
        Fill(bankWidth,io.f1update.bits.cfiMispredicted)

    val s1updateMask = WireInit(0.U.asTypeOf(Vec(tageNTables, Vec(bankWidth, Bool()))))
    val s1updateUMask = WireInit(0.U.asTypeOf(Vec(tageNTables, Vec(bankWidth, Bool()))))

    val s1updateTaken = Wire(Vec(tageNTables, Vec(bankWidth, Bool())))
    val s1updateOldCtr = Wire(Vec(tageNTables, Vec(bankWidth, UInt(3.W))))
    val s1updateAlloc = Wire(Vec(tageNTables, Vec(bankWidth, Bool())))
    val s1updateU = Wire(Vec(tageNTables, Vec(bankWidth, UInt(2.W))))

    val f3meta = Wire(Vec(bankWidth, new TagePredictMeta))
    io.f3meta := f3meta

    for (w <- 0 until bankWidth) {
        // 可供选择的预测信息
        var altPred = io.previousf3Taken(w)
        // 如果有表命中,最后面那个表预测时,给他提供的一个可选择的预测信息
        var final_altpred = WireInit(io.previousf3Taken(w))
        var provided =false.B
        var provider = 0.U

        io.f3taken(w) := io.previousf3Taken(w)

        for (i <- 0 until tageNTables) {
            val hit  = table_resps(i)(w).valid
            val pred = table_resps(i)(w).bits.pred
            when (hit) {
                io.f3taken(w) := Mux(pred === 3.U || pred === 4.U, altPred , pred(2))
                final_altpred := altPred
            }
            // 记录是否有表项命中
            provided = provided || hit
            // 记录最后一个命中表项的表号,
            provider = Mux(hit, i.U, provider)
            // 作为备选项,如果有命中他每次提供的都是最近的前一个命中表号,如果没有就是previousf3Taken,也即预测前的值
            altPred = Mux(hit, pred(2), altPred)
        }

        // 完善meta信息
        f3meta(w).provider.valid := provided
        f3meta(w).provider.bits := provider
        f3meta(w).altDiffers := final_altpred =/= io.f3taken(w)
        f3meta(w).providerU := table_resps(provider)(w).bits.u
        f3meta(w).providerCtr := table_resps(provider)(w).bits.pred

        // 如果有表找到作为最终的provider，那么同时意味着这个表之后的更大的表都没有命中，所以这个表之后的表都可以被分配
        // 分配位置的条件是：1.表没有命中 2.表的u位为0 3.表不是provider
        val allocatableSlots = (
            VecInit(table_resps.map(r => !r(w).valid && r(w).bits.u === 0.U)).asUInt &
              (~(MaskLower(UIntToOH(provider))& Fill(tageNTables, provided))).asUInt
        )

        // 可分配位置的方式是：
        //  1.如果有多个位置可供选择，那么优先选择被分配过的位置
        //  2.如果没有被分配过的位置，那么随机选择一个位置
        val allocLFSR = random.LFSR(tageNTables max 2)

        val firstEntry = PriorityEncoder(allocatableSlots)
        val maskedEntry = PriorityEncoder(allocatableSlots & allocLFSR)
        val allocEntry = Mux(allocatableSlots(maskedEntry),
            maskedEntry,
            firstEntry
        )

        f3meta(w).allocate.valid := allocatableSlots.orR
        f3meta(w).allocate.bits := allocEntry

        // 更新所使用的wasTaken信号
        val updateWasTaken = (
            io.f1update.bits.cfiIdx.valid &&
            ( io.f1update.bits.cfiIdx.bits === w.U )&&
            io.f1update.bits.cfiTaken
        )

        // 对包里面的跳转指令并且是发生了commit的指令进行有关信息更新
        when (io.f1update.bits.brMask(w) && io.f1update.valid && io.f1update.bits.isCommitUpdate){
            // 如果当时确实找到了一个provider表,那么就更新这个表对应的信息
            when (s1updateMeta(w).provider.valid){
                val provider = s1updateMeta(w).provider.bits

                s1updateMask(provider)(w) := true.B
                s1updateUMask(provider)(w) := true.B
                // 更新u位
                val new_u = inc_u(  s1updateMeta(w).providerU, 
                                    s1updateMeta(w).altDiffers,
                                    updateWasTaken)
                
                s1updateU(provider)(w) := new_u
                // 更新Taken信息,ctr
                s1updateTaken(provider)(w) := updateWasTaken
                s1updateOldCtr(provider)(w) := s1updateMeta(w).providerCtr
                // 这一个表既然当时作为provider,那么就不会被分配
                s1updateAlloc(provider)(w) := false.B
            }
        }
    }

    val s1update = io.f1update
    // commit的有效更新
    when (s1update.valid && s1update.bits.isCommitUpdate && s1update.bits.cfiIdx.valid){
        val idx = s1update.bits.cfiIdx.bits
        val allocate = s1updateMeta(idx).allocate
        // 如果存在分配的表,那么就更新这个表的信息
        when (allocate.valid){
            s1updateMask(allocate.bits)(idx) := true.B
            s1updateUMask(allocate.bits)(idx) := true.B
            s1updateU(allocate.bits)(idx) := 0.U
            s1updateTaken(allocate.bits)(idx) := s1update.bits.cfiTaken
            s1updateAlloc(allocate.bits)(idx) := true.B
        } .otherwise{
            val provider = s1updateMeta(idx).provider
            val decrMask = Mux(provider.valid, ~MaskLower(UIntToOH(provider.bits)), 0.U)

            for (i <- 0 until tageNTables){
                when (decrMask(i)){
                    s1updateUMask(i)(idx) := true.B
                    s1updateU (i)(idx) := 0.U
                }
            }
        }
    }

    for (i <- 0 until tageNTables) {
        for ( w <- 0 until bankWidth){
            tage_tables(i).io.update_mask(w) := RegNext(s1updateMask(i)(w))
            
            tage_tables(i).io.update_taken(w) := RegNext(s1updateTaken(i)(w))
            tage_tables(i).io.update_old_pred(w) := RegNext(s1updateOldCtr(i)(w))
            tage_tables(i).io.update_alloc(w) := RegNext(s1updateAlloc(i)(w))

            tage_tables(i).io.update_u(w) := RegNext(s1updateU(i)(w))
            tage_tables(i).io.update_u_mask(w) := RegNext(s1updateUMask(i)(w))
        }

        tage_tables(i).io.update_pc := RegNext(io.f1update.bits.pc)
        tage_tables(i).io.update_hist := RegNext(io.f1update.bits.gHist.asUInt)
    }
}
