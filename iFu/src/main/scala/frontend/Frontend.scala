package iFu.frontend

import chisel3._
import chisel3.util._

import iFu.sma._

import iFu.common._
import iFu.common.Consts._
import iFu.util._
import iFu.tlb._
import iFu.backend.PreDecode
import iFu.frontend.FrontendUtils._

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

class FrontendTLBDataIO extends CoreBundle {
    val r_req   = Output(new TLBDataRReq)
    val r_resp  = Flipped(Valid(new TLBDataRResp))
}

class FrontendCsrIO extends CoreBundle {
    val itlb_csr_cxt = Input(new ITLBCsrContext)
}

class FrontendToCoreIO extends CoreBundle {
    val numFTQEntries   = frontendParams.numFTQEntries

    val tlb_data        = new FrontendTLBDataIO
    val csr             = new FrontendCsrIO

    val fetchPacket     = new DecoupledIO(new FetchBufferResp)

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

    val smar = new SMAR
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
    val itlb          = Module(new ITLB)
    val fetch_buffer = Module(new FetchBuffer)
    val ftq          = Module(new FetchTargetQueue)

    io.smar <> icache.io.smar

    icache.io.invalidate := io.core.flush_icache

// --------------------------------------------------------
// Stage 0 -> select next pc, send request to icache, bpd
    // s0 is not a real stage, it is hidden in s1, so below variables are wire
    val s0_valid           = WireInit(false.B)
    val s0_vpc             = WireInit(0.U(vaddrBits.W))
    val s0_ghist           = WireInit(0.U.asTypeOf(new GlobalHistory))

    if(!FPGAPlatform)dontTouch(s0_valid)
    if(!FPGAPlatform)dontTouch(s0_vpc)
    if(!FPGAPlatform)dontTouch(s0_ghist)

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

    if(!FPGAPlatform)dontTouch(f1_clear)
    if(!FPGAPlatform)dontTouch(s1_valid)
    if(!FPGAPlatform)dontTouch(s1_vpc)
    if(!FPGAPlatform)dontTouch(s1_ghist)

// --------------------------------------------------------
// Stage 1 -> access tlb, send paddr to icache, and use bpd.f1 to predict next pc
    // access TLB
    io.core.tlb_data.r_req      := itlb.io.r_req
    itlb.io.r_resp              := io.core.tlb_data.r_resp
    itlb.io.itlb_csr_cxt        := io.core.csr.itlb_csr_cxt
    itlb.io.req.vaddr           := s1_vpc
    val f1_tlb_resp = itlb.io.resp

    // send paddr to icache
    icache.io.s1_paddr := f1_tlb_resp.paddr
    icache.io.s1_kill  := itlb.io.resp.exception.valid || f1_clear

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
    val s2_tlb_resp  = RegNext(f1_tlb_resp)

    if(!FPGAPlatform)dontTouch(f2_clear)
    if(!FPGAPlatform)dontTouch(s2_valid)
    if(!FPGAPlatform)dontTouch(s2_vpc)
    if(!FPGAPlatform)dontTouch(s2_ghist)
    if(!FPGAPlatform)dontTouch(s2_tlb_resp)
// --------------------------------------------------------
// Stage 2 -> use bpd.f2 to redirect(if needed)
    // handle tlb exceptions
    val s2_xcpt = s2_valid && s2_tlb_resp.exception.valid

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
        s0_valid     := !s2_tlb_resp.exception.valid
        s0_vpc       := s2_vpc
        s0_ghist     := s2_ghist
        f1_clear     := true.B
    } .elsewhen (s2_valid && f3_ready) {
        when (s1_valid && s1_vpc === f2_predicted_target && !f2_correct_f1_ghist) {
            // all right, use the predicted information to update the global history
            s2_ghist := f2_predicted_ghist
        }
        when ((s1_valid && (s1_vpc =/= f2_predicted_target || f2_correct_f1_ghist)) || !s1_valid) {
            // redirect, next cycle, s2_ghist is meaningless, so we don't care
            s0_valid := !s2_tlb_resp.exception.valid
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

            /**
                s3阶段重定向的条件
                1. 是jal/jalr指令
                2. 是条件分支指令并被预测跳转
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
    ras.io.write_addr  := f3_aligned_pc + (f3_fetch_bundle.cfiIdx.bits << 2).asUInt + 4.U
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
            s0_ghist     := f3_predicted_ghist
        }
    }

    if(!FPGAPlatform)dontTouch(f2_correct_f1_ghist)
    if(!FPGAPlatform)dontTouch(f3_correct_f1_ghist)
    if(!FPGAPlatform)dontTouch(f3_correct_f2_ghist)
    if(!FPGAPlatform)dontTouch(f1_predicted_ghist)
    if(!FPGAPlatform)dontTouch(f2_predicted_ghist)
    if(!FPGAPlatform)dontTouch(f3_predicted_ghist)
    if(!FPGAPlatform)dontTouch(f1_predicted_target)
    if(!FPGAPlatform)dontTouch(f2_predicted_target)
    if(!FPGAPlatform)dontTouch(f3_predicted_target)

// -------------------------------------------------------
    val f4_clear = WireInit(false.B)
    val f4 = withReset(reset.asBool || f4_clear) {
        Module(new Queue(new FetchBundle, 1, pipe = true, flow = false))
    }

    val f4_btb_corrections = Module(new Queue(new BranchPredictionUpdate, 2))
// -------------------------------------------------------
    f4_btb_corrections.io.enq.valid                   := f3_ifu_resp.io.deq.fire && f3_btb_mispredicts.reduce(_||_)
    f4_btb_corrections.io.enq.bits                    := DontCare
    f4_btb_corrections.io.enq.bits.btbMispredicts     := f3_btb_mispredicts.asUInt
    f4_btb_corrections.io.enq.bits.pc                 := f3_fetch_bundle.pc
    f4_btb_corrections.io.enq.bits.gHist              := f3_fetch_bundle.gHist
    f4_btb_corrections.io.enq.bits.meta               := f3_fetch_bundle.bpdMeta

    f4_ready        := f4.io.enq.ready
    f4.io.enq.valid := f3_ifu_resp.io.deq.valid && !f3_clear
    f4.io.enq.bits  := f3_fetch_bundle
    f4.io.deq.ready := fetch_buffer.io.enq.ready && ftq.io.enq.ready

    fetch_buffer.io.enq.valid             := f4.io.deq.valid && ftq.io.enq.ready
    fetch_buffer.io.enq.bits              := f4.io.deq.bits
    fetch_buffer.io.enq.bits.ftqIdx       := ftq.io.enqIdx

    ftq.io.enq.valid := f4.io.deq.valid && fetch_buffer.io.enq.ready
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
    }
// --------------------------------------------------------
}
