package iFu.frontend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.util._
import iFu.tlb._
import iFu.backend.PreDecode
import iFu.frontend.FrontendUtils._
import iFu.common.CauseCode._

//TODO 重命名GlobalHistory,如果之后RAS增加计数器，Histories的update函数需要更改，

class FetchResp extends CoreBundle {
    // parameters
    val fetchWidth = frontendParams.fetchWidth

    val pc         = UInt(vaddrBits.W)
    val instrs     = UInt((fetchWidth * coreInstrBits).W)
    val mask       = UInt(fetchWidth.W)
    val exception  = Valid(new ITLBException)
    val gHist      = new GlobalHistory
}

class FetchBundle extends CoreBundle {
    // parameters
    val fetchWidth         = frontendParams.fetchWidth
    val fetchBytes         = frontendParams.fetchBytes
    val numFTQEntries      = frontendParams.numFTQEntries
    val nBanks             = frontendParams.iCacheParams.nBanks

    val pc              = UInt(vaddrBits.W) // fetch PC, possibly unaligned.
    val instrs          = Vec(fetchWidth, Bits(coreInstrBits.W))
    val sfbs            = Vec(fetchWidth, Bool())
    val sfb_masks       = Vec(fetchWidth, UInt((2 * fetchWidth).W))
    val sfb_dests       = Vec(fetchWidth, UInt((log2Ceil(fetchBytes) + 1).W))
    val shadowable_mask = Vec(fetchWidth, Bool())
    val shadowed_mask   = Vec(fetchWidth, Bool())

    val cfiIdx    = Valid(UInt(log2Ceil(fetchWidth).W))
    val cfiType   = UInt(CFI_SZ.W)
    val cfiIsCall = Bool()
    val cfiIsRet  = Bool()
    val rasTop    = UInt(vaddrBits.W)
    val ftqIdx    = UInt(log2Ceil(numFTQEntries).W)
    val mask      = UInt(fetchWidth.W)    // the purpose and specific details of the mask need more information, check later
    val brMask    = UInt(fetchWidth.W)
    val gHist     = new GlobalHistory
    val exception = Valid(new ITLBException)
    val bpdMeta   = Vec(nBanks, Vec(bankWidth, new PredictionMeta))
}

class FrontendToCoreIO extends CoreBundle {
    val numFTQEntries   = frontendParams.numFTQEntries

    val fetchPacket = new DecoupledIO(new FetchBufferResp)

    // 1 for xcpt/jalr/auipc/flush
    val getFtqPc        = Vec(2, new GetPCFromFtqIO)

    val brupdate        = Input(new BrUpdateInfo)

    // Redirects change the PC
    val redirect_flush  = Input(Bool())
    val redirect_val    = Input(Bool())
    val redirect_pc     = Input(UInt())    //分支指令的结果
    val redirect_ftq_idx= Input(UInt())
    val redirect_ghist  = Input(new GlobalHistory)

    val commit          = Flipped(Valid(UInt(numFTQEntries.W)))
    val flush_icache    = Input(Bool())
}

class FrontendIO extends CoreBundle {
    val core = new FrontendToCoreIO

    val ireq  = Output(new CBusReq)
    val iresp = Input(new CBusResp)
}

class Frontend extends CoreModule {
// --------------------------------------------------------
// Parameters and constants
    val fetchWidth    = frontendParams.fetchWidth
    val numRasEntries = frontendParams.bpdParams.numRasEntries
    val bankWidth     = frontendParams.bankWidth
    val nBanks        = frontendParams.iCacheParams.nBanks
    val lineBytes     = frontendParams.iCacheParams.lineBytes
    val fetchBytes    = frontendParams.fetchBytes
    val bankBytes     = frontendParams.iCacheParams.bankBytes
    val instrBytes    = frontendParams.instrBytes
// --------------------------------------------------------
    val io = IO(new FrontendIO)

    // Module definition
    val bpd          = Module(new BranchPredictor)
    val ras          = Module(new Ras)  // TODO: should ras be a part of bpd?
    val icache       = Module(new ICache(frontendParams.iCacheParams))
    val tlb          = Module(new ITLB)
    val fetch_buffer = Module(new FetchBuffer)
    val ftq          = Module(new FetchTargetQueue)

    io.ireq            := icache.io.cbusReq
    icache.io.cbusResp := io.iresp

    icache.io.invalidate := io.core.flush_icache

// --------------------------------------------------------
// Stage 0 -> select next pc, send request to icache, bpd
    // s0 is not a real stage, it is hidden in s1, so below variables are wire
    val s0_valid           = WireInit(false.B)
    val s0_vpc             = WireInit(0.U(vaddrBits.W))
    val s0_ghist           = WireInit((0.U).asTypeOf(new GlobalHistory))
    val s0_is_replay       = WireInit(false.B)
    val s0_replay_tlb_resp = Wire(new ITLBResp)

    // the first cycle after reset, the frontend will fetch from resetPC
    when (RegNext(reset.asBool) && !reset.asBool) {
        s0_valid := true.B
        s0_vpc   := resetPC.U(vaddrBits.W)
        s0_ghist := 0.U.asTypeOf(new GlobalHistory)
    }

    icache.io.req.valid     := s0_valid
    icache.io.req.bits.addr := s0_vpc

    bpd.io.f0req.valid      := s0_valid
    bpd.io.f0req.bits.pc    := s0_vpc
    bpd.io.f0req.bits.gHist := s0_ghist
// --------------------------------------------------------
    val f1_clear     = WireInit(false.B)
    val s1_valid     = RegNext(s0_valid, false.B)
    val s1_vpc       = RegNext(s0_vpc)
    val s1_ghist     = RegNext(s0_ghist)
    val s1_is_replay = RegNext(s0_is_replay)
// --------------------------------------------------------
// Stage 1 -> access tlb, send paddr to icache, and use bpd.f1 to predict next pc
    // access TLB
    tlb.io.req.valid      := s1_valid && !s1_is_replay && !f1_clear
    tlb.io.req.bits.vaddr := s1_vpc
    val f1_tlb_resp = Mux(
        s1_is_replay,
        RegNext(s0_replay_tlb_resp),
        tlb.io.resp
    )

    // send paddr to icache
    icache.io.s1_paddr := f1_tlb_resp.paddr
    icache.io.s1_kill  := tlb.io.resp.exception.valid || f1_clear

    // branch prediction
    val f1_bpd_resp = bpd.io.resp.f1
    val f1_valid_instr_mask = fetchMask(s1_vpc)
    val f1_redirect_instrs = (0 until fetchWidth).map{ i=>
        s1_valid && f1_valid_instr_mask(i) &&
        f1_bpd_resp.predInfos(i).predictedpc.valid && (
            f1_bpd_resp.predInfos(i).isJal ||
            (f1_bpd_resp.predInfos(i).isBranch && f1_bpd_resp.predInfos(i).taken)
        )
    }
    val f1_do_redirect = f1_redirect_instrs.reduce(_||_)
    val f1_redirect_instr_idx = PriorityEncoder(f1_redirect_instrs)
    val f1_tgts = VecInit(f1_bpd_resp.predInfos.map(_.predictedpc.bits))
    val f1_predicted_target = Mux(
        f1_do_redirect,
        f1_tgts(f1_redirect_instr_idx),
        nextFetch(s1_vpc)
    )
    // use the predicted information to update the global history
    val f1_predicted_ghist = s1_ghist.update(
        VecInit(f1_bpd_resp.predInfos.map(p =>
            p.isBranch && p.predictedpc.valid
        )).asUInt & f1_valid_instr_mask,
        f1_bpd_resp.predInfos(f1_redirect_instr_idx).taken && f1_do_redirect,
        f1_bpd_resp.predInfos(f1_redirect_instr_idx).isBranch,
        f1_redirect_instr_idx,
        f1_do_redirect,
        s1_vpc,
        false.B,
        false.B
    )

    // if current cycle is valid, use the predicted target as the next fetch pc
    when (s1_valid) {
        s0_valid := !f1_tlb_resp.exception.valid
        s0_vpc   := f1_predicted_target
        s0_ghist := f1_predicted_ghist
    }
// --------------------------------------------------------
    val f2_clear     = WireInit(false.B)
    val s2_valid     = RegNext(s1_valid && !f1_clear, false.B)
    val s2_vpc       = RegNext(s1_vpc)
    val s2_ghist     = Reg(new GlobalHistory)
    val s2_is_replay = RegNext(s1_is_replay) && s2_valid
    val s2_tlb_resp  = RegNext(f1_tlb_resp)
// --------------------------------------------------------
// Stage 2 -> check and prepare for replay, and use bpd.f2 to redirect(if needed)
    // when replay happened, don't send request to tlb again
    s0_replay_tlb_resp := s2_tlb_resp

    // handle tlb exceptions
    val s2_xcpt = s2_valid && s2_tlb_resp.exception.valid && !s2_is_replay

    icache.io.s2_kill := s2_xcpt

    // set the default value, if bpd.f2 agree with bpd.f1, we will use the updated value
    s2_ghist := s1_ghist

    // branch prediction
    val f2_bpd_resp = bpd.io.resp.f2
    val f2_valid_instr_mask = fetchMask(s2_vpc)
    val f2_redirect_instrs = (0 until fetchWidth).map{ i =>
        s2_valid && f2_valid_instr_mask(i) &&
        f2_bpd_resp.predInfos(i).predictedpc.valid && (
            f2_bpd_resp.predInfos(i).isJal ||
            (f2_bpd_resp.predInfos(i).isBranch && f2_bpd_resp.predInfos(i).taken)
        )
    }
    val f2_do_redirect = f2_redirect_instrs.reduce(_||_)
    val f2_redirect_instr_idx = PriorityEncoder(f2_redirect_instrs)
    val f2_tgts = VecInit(f2_bpd_resp.predInfos.map(_.predictedpc.bits))
    val f2_predicted_target = Mux(
        f2_do_redirect,
        f2_tgts(f2_redirect_instr_idx),
        nextFetch(s2_vpc)
    )
    // use the predicted information to update the global history
    val f2_predicted_ghist = s2_ghist.update(
        VecInit(f2_bpd_resp.predInfos.map(p =>
            p.isBranch && p.predictedpc.valid
        )).asUInt & f2_valid_instr_mask,
        f2_bpd_resp.predInfos(f2_redirect_instr_idx).taken && f2_do_redirect,
        f2_bpd_resp.predInfos(f2_redirect_instr_idx).isBranch,
        f2_redirect_instr_idx,
        f2_do_redirect,
        s2_vpc,
        false.B,
        false.B
    )

    // check if bpd.f2 agree with bpd.f1
    val f2_correct_f1_ghist = s1_ghist =/= f2_predicted_ghist

    // note: s0 is not a real stage
    val f3_ready = Wire(Bool())
    when (
        (s2_valid && !icache.io.resp.valid) ||  // cache miss
        (s2_valid && icache.io.resp.valid && !f3_ready) // f3 full
    ) {
        s0_valid     := !s2_tlb_resp.exception.valid || s2_is_replay
        s0_vpc       := s2_vpc
        s0_ghist     := s2_ghist
        s0_is_replay := s2_valid && icache.io.resp.valid
        f1_clear     := true.B
    } .elsewhen (s2_valid && f3_ready) {
        when (s1_valid && s1_vpc === f2_predicted_target && !f2_correct_f1_ghist) {
            // all right, use the predicted information to update the global history
            s2_ghist := f2_predicted_ghist
        }
        when ((s1_valid && (s1_vpc =/= f2_predicted_target || f2_correct_f1_ghist)) || !s1_valid) {
            // redirect, next cycle, s2_ghist is meaningless, so we don't care
            s0_valid := !(s2_tlb_resp.exception.valid && !s2_is_replay)
            s0_vpc   := f2_predicted_target
            s0_ghist := f2_predicted_ghist
            f1_clear := true.B
        }
    }
// --------------------------------------------------------
    val f3_clear = WireInit(false.B)
    val f3_ifu_resp = withReset(reset.asBool || f3_clear) {
        Module(new Queue(new FetchResp, 1, pipe = true, flow = false))
    }
    val f3_bpd_resp = withReset(reset.asBool || f3_clear) {
        Module(new Queue(new BranchPredictionBundle, 1, pipe = true, flow = true))
    }
    val ras_read_idx = RegInit(0.U(log2Ceil(numRasEntries).W))
// --------------------------------------------------------
// Stage 3 -> 
    // do enqueue
    f3_ifu_resp.io.enq.valid := (
        s2_valid && !f2_clear && (          // stage 2 is valid and (
            icache.io.resp.valid ||         //     icache return instrctions or
            s2_tlb_resp.exception.valid     //     tlb exception happens
        )                                   // )
    )
    f3_ifu_resp.io.enq.bits.pc        := s2_vpc
    f3_ifu_resp.io.enq.bits.instrs    := Mux(s2_xcpt, 0.U, icache.io.resp.bits.data)
    f3_ifu_resp.io.enq.bits.gHist     := s2_ghist
    f3_ifu_resp.io.enq.bits.mask      := fetchMask(s2_vpc)
    f3_ifu_resp.io.enq.bits.exception := s2_tlb_resp.exception

    f3_ready := f3_ifu_resp.io.enq.ready

    // send request to ras, use ras_read_idx for replay(when f3 is full)
    ras.io.read_idx := ras_read_idx
    when (f3_ifu_resp.io.enq.fire) {
        ras_read_idx    := f3_ifu_resp.io.enq.bits.gHist.rasIdx
        ras.io.read_idx := f3_ifu_resp.io.enq.bits.gHist.rasIdx
    }

    f3_bpd_resp.io.enq.valid := (
        RegNext(f3_ifu_resp.io.enq.ready) &&    // f3 is not full
        f3_ifu_resp.io.deq.valid                // f4 is not full
    )
    f3_bpd_resp.io.enq.bits  := bpd.io.resp.f3

    bpd.io.f3fire := f3_bpd_resp.io.enq.fire

    val f4_ready = Wire(Bool())
    f3_ifu_resp.io.deq.ready := f4_ready
    f3_bpd_resp.io.deq.ready := f4_ready

    val f3_fetchResp             = f3_ifu_resp.io.deq.bits
    val f3_bank_mask             = bankMask(f3_fetchResp.pc)
    val f3_instrs                = f3_fetchResp.instrs
    val f3_aligned_pc            = bankAlign(f3_fetchResp.pc)
    val f3_is_last_bank_in_block = isLastBankInBlock(f3_aligned_pc)
    val f3_redirects             = Wire(Vec(fetchWidth, Bool()))
    val f3_tgts                  = Wire(Vec(fetchWidth, UInt(vaddrBits.W)))
    val f3_cfi_types             = Wire(Vec(fetchWidth, UInt(CFI_SZ.W)))
    val f3_shadowed_mask         = Wire(Vec(fetchWidth, Bool()))
    val f3_fetch_bundle          = Wire(new FetchBundle)
    val f3_mask                  = Wire(Vec(fetchWidth, Bool()))
    val f3_br_mask               = Wire(Vec(fetchWidth, Bool()))
    val f3_call_mask             = Wire(Vec(fetchWidth, Bool()))
    val f3_ret_mask              = Wire(Vec(fetchWidth, Bool()))
    val f3_btb_mispredicts       = Wire(Vec(fetchWidth, Bool()))

    var redirect_found = false.B
    for (b <- 0 until nBanks) {
        val bank_instrs = f3_instrs(
            (b + 1) * bankWidth * coreInstrBits - 1, b * bankWidth * coreInstrBits
        )
        for (w <- 0 until bankWidth) {
            val i     = b * bankWidth + w
            val pc    = f3_aligned_pc + (i << log2Ceil(coreInstrBytes)).U
            val instr = bank_instrs(w * coreInstrBits + coreInstrBits - 1, w * coreInstrBits)

            val pre_decoder = Module(new PreDecode)
            pre_decoder.io.pc    := pc
            pre_decoder.io.instr := instr
            val brsigs = pre_decoder.io.out

            f3_fetch_bundle.instrs(i) := instr
            f3_mask(i) := f3_ifu_resp.io.deq.valid && f3_fetchResp.mask(i) && !redirect_found
            f3_tgts(i) := Mux(
                brsigs.cfiType === CFI_JALR,
                f3_bpd_resp.io.deq.bits.predInfos(i).predictedpc.bits, // maybe wrong
                brsigs.target   // surelly right
            )
            f3_btb_mispredicts(i) := (
                brsigs.cfiType === CFI_JAL &&   // predecode can only correct JAL
                f3_bpd_resp.io.deq.bits.predInfos(i).predictedpc.valid &&
                (f3_bpd_resp.io.deq.bits.predInfos(i).predictedpc.bits =/= brsigs.target)
            )

            // 1 bit more to prevent overflow
            val offset_from_aligned_pc = (
                (i << 2).U((log2Ceil(lineBytes) + 1).W) + brsigs.sfbOffset.bits
            )
            val lower_mask = Wire(UInt((2 * fetchWidth).W)) // sfb_br's position
            val upper_mask = Wire(UInt((2 * fetchWidth).W)) // sfb_br_tgt's position
            lower_mask := UIntToOH(i.U)
            upper_mask := UIntToOH(
                offset_from_aligned_pc(log2Ceil(fetchWidth * 2 + 1) + 1, 2)
            ) << Mux(f3_is_last_bank_in_block, bankWidth.U, 0.U)

            /**
             * 判断是否是sfb指令，如果是Cacheline的最后一个bank，那么最多只能取3个bank（跨Cacheline）
             * 正常情况，可以取4个bank
             */
            f3_fetch_bundle.sfbs(i) := (
                f3_mask(i) && brsigs.sfbOffset.valid &&
                (offset_from_aligned_pc <= Mux(f3_is_last_bank_in_block, (fetchBytes + bankBytes).U, (2 * fetchBytes).U))
            )
            // sfb_masks -> br 和 tgt 之间不包括br和tgt的指令
            // 0 -> 不在范围内 1 -> 在范围内
            f3_fetch_bundle.sfb_masks(i) := (~MaskLower(lower_mask)).asUInt & (~MaskUpper(upper_mask)).asUInt
            /**
             * 没有发生异常
             * bank有效
             * 是shadowable的或者该位置指令无效
             */
            f3_fetch_bundle.shadowable_mask(i) := (
                !f3_fetch_bundle.exception.valid &&
                f3_bank_mask(b) && (brsigs.shadowable || !f3_mask(i))   // TODO: do we need f3_mask(i) here?
            )
            f3_fetch_bundle.sfb_dests(i) := offset_from_aligned_pc

            /**
                s3阶段重定向的条件
                1. 是jal/jalr指令
                2. 是条件分支指令并被预测跳转(sfb不被预测)
             */
            f3_redirects(i) := f3_mask(i) && (
                brsigs.cfiType === CFI_JAL || brsigs.cfiType === CFI_JALR ||
                (brsigs.cfiType === CFI_BR && f3_bpd_resp.io.deq.bits.predInfos(i).taken)
            )
            f3_br_mask(i)   := f3_mask(i) && brsigs.cfiType === CFI_BR
            f3_cfi_types(i) := brsigs.cfiType
            f3_call_mask(i) := brsigs.isCall
            f3_ret_mask(i)  := brsigs.isRet

            redirect_found = redirect_found || f3_redirects(i)
        }
    }

    f3_fetch_bundle.mask          := f3_mask.asUInt
    f3_fetch_bundle.brMask        := f3_br_mask.asUInt
    f3_fetch_bundle.pc            := f3_fetchResp.pc
    f3_fetch_bundle.ftqIdx        := 0.U
    f3_fetch_bundle.exception     := f3_fetchResp.exception
    f3_fetch_bundle.shadowed_mask := f3_shadowed_mask
    f3_fetch_bundle.cfiIdx.valid  := f3_redirects.reduce(_||_)
    f3_fetch_bundle.cfiIdx.bits   := PriorityEncoder(f3_redirects)
    f3_fetch_bundle.cfiType       := f3_cfi_types(f3_fetch_bundle.cfiIdx.bits)
    f3_fetch_bundle.cfiIsCall     := f3_call_mask(f3_fetch_bundle.cfiIdx.bits)
    f3_fetch_bundle.cfiIsRet      := f3_ret_mask(f3_fetch_bundle.cfiIdx.bits)
    f3_fetch_bundle.gHist         := f3_ifu_resp.io.deq.bits.gHist
    f3_fetch_bundle.bpdMeta       := f3_bpd_resp.io.deq.bits.meta
    f3_fetch_bundle.rasTop        := ras.io.read_addr

    val f3_predicted_target = Mux(f3_redirects.reduce(_||_),
        Mux(f3_fetch_bundle.cfiIsRet, ras.io.read_addr,
            f3_tgts(PriorityEncoder(f3_redirects))),
        nextFetch(f3_fetch_bundle.pc)
    )

    val f3_predicted_ghist = f3_fetch_bundle.gHist.update(
        f3_fetch_bundle.brMask,
        f3_fetch_bundle.cfiIdx.valid,
        f3_fetch_bundle.brMask(f3_fetch_bundle.cfiIdx.bits),
        f3_fetch_bundle.cfiIdx.bits,
        f3_fetch_bundle.cfiIdx.valid,
        f3_fetch_bundle.pc,
        f3_fetch_bundle.cfiIsCall,
        f3_fetch_bundle.cfiIsRet
    )

    ras.io.write_valid := false.B
    ras.io.write_addr  := (f3_aligned_pc.asSInt + (f3_fetch_bundle.cfiIdx.bits << 2).asSInt + 4.S).asUInt
    ras.io.write_idx   := WrapInc(f3_fetch_bundle.gHist.rasIdx, numRasEntries)

    val f3_correct_f1_ghist = s1_ghist =/= f3_predicted_ghist
    val f3_correct_f2_ghist = s2_ghist =/= f3_predicted_ghist

    when (f3_ifu_resp.io.deq.valid && f4_ready) {
        when(f3_fetch_bundle.cfiIsCall && f3_fetch_bundle.cfiIdx.valid){
            ras.io.write_valid := true.B
        }

        when (s2_valid && s2_vpc === f3_predicted_target&& !f3_correct_f2_ghist) {
            f3_ifu_resp.io.enq.bits.gHist := f3_predicted_ghist
        } .elsewhen (!s2_valid && s1_valid && s1_vpc === f3_predicted_target && !f3_correct_f1_ghist) {
            s2_ghist := f3_predicted_ghist
        } .elsewhen (
            (s2_valid && (s2_vpc =/= f3_predicted_target || f3_correct_f2_ghist)) ||
            (!s2_valid && s1_valid && (s1_vpc =/= f3_predicted_target || f3_correct_f1_ghist)) ||
            (!s2_valid && !s1_valid)
        ) {
            f2_clear     := true.B
            f1_clear     := true.B
            s0_valid     := !f3_fetch_bundle.exception.valid
            s0_vpc       := f3_predicted_target
            s0_is_replay := false.B
            s0_ghist     := f3_predicted_ghist
        }
    }
// -------------------------------------------------------
    val f4 = withReset(reset.asBool || f4_clear) {
        Module(new Queue(new FetchBundle, 1, pipe = true, flow = false))
    }

    val f4_btb_corrections = Module(new Queue(new BranchPredictionUpdate, 2))
// -------------------------------------------------------

    val f4_clear = WireInit(false.B)

    f4_btb_corrections.io.enq.valid                   := f3_ifu_resp.io.deq.fire && f3_btb_mispredicts.reduce(_||_)
    f4_btb_corrections.io.enq.bits                    := DontCare
    f4_btb_corrections.io.enq.bits.isMispredictUpdate := false.B
    f4_btb_corrections.io.enq.bits.isRepairUpdate     := false.B
    f4_btb_corrections.io.enq.bits.btbMispredicts     := f3_btb_mispredicts.asUInt
    f4_btb_corrections.io.enq.bits.pc                 := f3_fetch_bundle.pc
    f4_btb_corrections.io.enq.bits.gHist              := f3_fetch_bundle.gHist
    f4_btb_corrections.io.enq.bits.meta               := f3_fetch_bundle.bpdMeta

    // 下面将要处理sfbs
    val f4_shadowable_masks = VecInit((0 until fetchWidth).map{ i =>
        f4.io.deq.bits.shadowable_mask.asUInt |
        (~f4.io.deq.bits.sfb_masks(i)).asUInt(fetchWidth - 1, 0)    // the instructions which not in sfb shadow
    })
    val f3_shadowable_masks = VecInit((0 until fetchWidth).map{ i =>
        Mux(f4.io.enq.valid, f4.io.enq.bits.shadowable_mask.asUInt, 0.U) |
        (~f4.io.deq.bits.sfb_masks(i)).asUInt(2 * fetchWidth - 1, fetchWidth)
    })
    val f4_sfbs = VecInit((0 until fetchWidth) map {i =>  // 该指令能否被视为sfb br
        ((~f4_shadowable_masks(i)).asUInt === 0.U) && ((~f3_shadowable_masks(i)).asUInt === 0.U) &&
        f4.io.deq.bits.sfbs(i) &&
        !(f4.io.deq.bits.cfiIdx.valid && f4.io.deq.bits.cfiIdx.bits === i.U)
    })
    val f4_sfb_valid    = f4.io.deq.valid && f4_sfbs.reduce(_||_)
    val f4_sfb_idx      = PriorityEncoder(f4_sfbs)
    val f4_sfb_mask     = f4.io.deq.bits.sfb_masks(f4_sfb_idx)
    // 如果f4阶段有sfb指令，要等待下一次fetch
    val f4_delay = (
        f4.io.deq.bits.sfbs.reduce(_||_) &&
        !f4.io.deq.bits.cfiIdx.valid &&
        !f4.io.enq.valid &&
        !f4.io.deq.bits.exception.valid
    )
    when (f4_sfb_valid) {
        f3_shadowed_mask := f4_sfb_mask(2 * fetchWidth - 1,fetchWidth).asBools
    } .otherwise {
        f3_shadowed_mask := VecInit(0.U(fetchWidth.W).asBools)
    }

    f4_ready        := f4.io.enq.ready
    f4.io.enq.valid := f3_ifu_resp.io.deq.valid && !f3_clear
    f4.io.enq.bits  := f3_fetch_bundle
    f4.io.deq.ready := fetch_buffer.io.enq.ready && ftq.io.enq.ready && !f4_delay

    fetch_buffer.io.enq.valid             := f4.io.deq.valid && ftq.io.enq.ready && !f4_delay
    fetch_buffer.io.enq.bits              := f4.io.deq.bits
    fetch_buffer.io.enq.bits.ftqIdx       := ftq.io.enqIdx
    fetch_buffer.io.enq.bits.sfbs         := Mux(f4_sfb_valid, UIntToOH(f4_sfb_idx), 0.U(fetchWidth.W)).asBools
    fetch_buffer.io.enq.bits.shadowed_mask := (
        Mux(f4_sfb_valid, f4_sfb_mask(fetchWidth - 1,0), 0.U(fetchWidth.W)) |
        f4.io.deq.bits.shadowed_mask.asUInt
    ).asBools

    ftq.io.enq.valid := f4.io.deq.valid && fetch_buffer.io.enq.ready && !f4_delay
    ftq.io.enq.bits  := f4.io.deq.bits

    // bpd update infomation select
    val bpd_update_arb = Module(new Arbiter(new BranchPredictionUpdate, 2))
    bpd_update_arb.io.out.ready := true.B
    // from ftq
    bpd_update_arb.io.in(0).valid := ftq.io.bpdUpdate.valid
    bpd_update_arb.io.in(0).bits  := ftq.io.bpdUpdate.bits
    assert(bpd_update_arb.io.in(0).ready === true.B)
    // from f4
    bpd_update_arb.io.in(1) <> f4_btb_corrections.io.deq
    // to bpd
    bpd.io.update := bpd_update_arb.io.out

    // ras update(from ftq, redirect happened, will override the ras update in stage 3)
    when (ftq.io.rasUpdate) {
        ras.io.write_valid := true.B
        ras.io.write_idx   := ftq.io.rasUpdateIdx
        ras.io.write_addr  := ftq.io.rasUpdatepc
    }
// -------------------------------------------------------

// -------------------------------------------------------
// Stage 5 -> no a real stage, connect to core
    io.core.fetchPacket <> fetch_buffer.io.deq
    io.core.getFtqPc    <> ftq.io.getFtqpc

    ftq.io.deq            := io.core.commit
    ftq.io.brUpdate       := io.core.brupdate
    ftq.io.redirect.valid := io.core.redirect_val
    ftq.io.redirect.bits  := io.core.redirect_ftq_idx

    fetch_buffer.io.clear := false.B

    // handle redirect from core
    when (io.core.redirect_flush) {
        fetch_buffer.io.clear := true.B

        f4_clear := true.B
        f3_clear := true.B
        f2_clear := true.B
        f1_clear := true.B

        s0_valid     := io.core.redirect_val
        s0_vpc       := io.core.redirect_pc
        s0_ghist     := io.core.redirect_ghist
        s0_is_replay := false.B
    }
// --------------------------------------------------------
}
