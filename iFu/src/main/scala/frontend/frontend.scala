package iFu.frontend

import backend.memSystem.BrUpdateInfo
import chisel3._
import chisel3.util._
import iFu.common._
import iFu.common.Consts._
import iFu.util._
import iFu.backend.{PreDecode, PreDecodeSignals}

//TODO 重命名FrontEndExceptions,GlobalHistory,如果之后RAS增加计数器，Histories的update函数需要更改，
//TODO FetchBundle重命名为FetchBufferEntry
//TODO 检查valid信号 569行
//TODO HasFrontEndparameters的函数只适用与ICache

class FrontendExceptions extends Bundle {
    val pf = new TLBExceptions
    val gf = new TLBExceptions
    val ae = new TLBExceptions
}

class GlobalHistory extends CoreBundle with FrontendUtils {
    /*--------------------------*/
    val globalHistoryLength = frontendParams.bpdParams.globalHistoryLength
    val numRasEntries       = frontendParams.bpdParams.numRasEntries
    val fetchWidth          = frontendParams.fetchWidth
    val bankWidth           = frontendParams.bankWidth
    /*--------------------------*/
    val old_history = UInt((globalHistoryLength).W)
    val currentSawBranchNotTaken = Bool()
    val newSawBranchNotTaken = Bool()
    val newSawBranchTaken = Bool()

    val rasIdx = UInt(log2Ceil(numRasEntries).W)

    def histories(bank: Int): UInt = {
        if (bank == 0) {
            old_history
        } else {
            Mux(newSawBranchTaken,       old_history << 1 | 1.U,
            Mux(newSawBranchNotTaken,   old_history << 1,
                                            old_history))
        }
    }

    def ===(other: GlobalHistory): Bool = {
        ((old_history === other.old_history) &&
         (newSawBranchNotTaken === other.newSawBranchNotTaken) &&
         (newSawBranchTaken === other.newSawBranchTaken))
    }

    def =/=(other: GlobalHistory): Bool = !(this === other)

    def update(
        branches: UInt, cfi_taken: Bool, cfi_is_br: Bool, cfi_idx: UInt,
        cfi_valid: Bool, addr: UInt, cfi_is_call: Bool, cfi_is_ret: Bool
    ): GlobalHistory = {
        val cfi_idx_fixed = cfi_idx(log2Ceil(fetchWidth) - 1, 0)
        val cfi_idx_oh = UIntToOH(cfi_idx_fixed)
        val new_history = Wire(new GlobalHistory)
        val not_taken_branches = branches & Mux(cfi_valid,
            MaskLower(cfi_idx_oh) & ~Mux(cfi_is_br && cfi_taken, cfi_idx_oh, 0.U(fetchWidth.W)),
            ~(0.U(fetchWidth.W))
        )

        val cfi_in_bank_0 = cfi_valid && cfi_taken && cfi_idx_fixed < bankWidth.U
        val ignore_second_bank = cfi_in_bank_0 || isLastBankInBlock(addr)

        val first_bank_saw_not_taken = not_taken_branches(bankWidth - 1, 0) =/= 0.U || currentSawBranchNotTaken
        new_history.currentSawBranchNotTaken := false.B
        when (ignore_second_bank) {
            new_history.old_history := histories(1)
            new_history.newSawBranchNotTaken := first_bank_saw_not_taken
            new_history.newSawBranchTaken := cfi_is_br && cfi_in_bank_0
        } .otherwise {
            new_history.old_history :=
                Mux(cfi_is_br && cfi_in_bank_0, histories(1) << 1 | 1.U,
                Mux(first_bank_saw_not_taken,   histories(1) << 1,
                                                histories(1)))
            new_history.newSawBranchNotTaken := not_taken_branches(fetchWidth - 1, bankWidth) =/= 0.U
            new_history.newSawBranchTaken := cfi_valid && cfi_taken && cfi_is_br && !cfi_in_bank_0
        }

        new_history.rasIdx :=
            Mux(cfi_valid && cfi_is_call,   WrapInc(rasIdx, numRasEntries),
            Mux(cfi_valid && cfi_is_ret,    WrapDec(rasIdx, numRasEntries),
                                            rasIdx))
        new_history
    }
}

class FetchResp extends CoreBundle {
    /*--------------------------*/
    val fetchWidth = frontendParams.fetchWidth
    /*--------------------------*/
    val pc      = UInt(vaddrBits.W)
    val data    = UInt((fetchWidth * coreInstrBits).W)
    val mask    = UInt(fetchWidth.W)
    val xcpt    = new FrontendExceptions
    val gHist   = new GlobalHistory
    // val fsrc    = UInt(BSRC_SZ.W)
}

class FetchBundle extends CoreBundle {
    /*--------------------------*/
    val fetchWidth         = frontendParams.fetchWidth
    val fetchBytes         = frontendParams.fetchBytes
    val numFTQEntries      = frontendParams.numFTQEntries
    val nBanks             = frontendParams.iCacheParams.nBanks
    val localHistoryLength = frontendParams.bpdParams.localHistoryLength
    /*--------------------------*/
    val pc              = UInt(vaddrBits.W) // fetch PC, possibly unaligned.
    val next_pc         = UInt(vaddrBits.W) // maybe not used?
    val instrs          = Vec(fetchWidth, Bits(coreInstrBits.W))
    val sfbs            = Vec(fetchWidth, Bool())
    val sfb_masks       = Vec(fetchWidth, UInt((2 * fetchWidth).W))
    val sfb_dests       = Vec(fetchWidth, UInt((1 + log2Ceil(fetchBytes)).W))
    val shadowable_mask = Vec(fetchWidth, Bool())
    val shadowed_mask   = Vec(fetchWidth, Bool())

    val cfiIdx         = Valid(UInt(log2Ceil(fetchWidth).W))
    val cfiType        = UInt(CFI_SZ.W)
    val cfiIsCall     = Bool()
    val cfiIsRet      = Bool()

    val rasTop         = UInt(vaddrBits.W)

    val ftqIdx         = UInt(log2Ceil(numFTQEntries).W)
    val mask            = UInt(fetchWidth.W)    // the purpose and specific details of the mask need more information, check later

    val brMask         = UInt(fetchWidth.W)

    val gHist           = new GlobalHistory
    val lHist           = Vec(nBanks, UInt(localHistoryLength.W))

    val xcpt_pf_if      = Bool()    // I-TLB miss(instruction fetch fault)
    val xcpt_ae_if      = Bool()    // Access exception

    val bpdMeta         = Vec(nBanks, new PredictionMeta)

    // val fsrc            = UInt(BSRC_SZ.W)
}

class FrontendToCPUIO extends CoreBundle {  // from core to frontend instead of from frontend to core
    /*--------------------------*/
    val numFTQEntries   = frontendParams.numFTQEntries
    /*--------------------------*/
    val fetchPacket = Flipped(new DecoupledIO(new FetchBufferResp))

    // 1 for xcpt/jalr/auipc/flush
    val getFtqPc        = Flipped(Vec(2, new GetPCFromFtqIO))

    // do we need this?
    // //Breakpoint info
    // val status          = Output(new MStatus)
    // val bp              = Output(Vec(nBreakpoints, new BP))
    // val mcontext        = Output(UInt(mcontextWidth.W))
    // val scontext        = Output(UInt(scontextWidth.W))

    val sfence          = Valid(new SFenceReq)

    val brupdate        = Output(new BrUpdateInfo)

    //Redirects change the PC
    val redirect_flush  = Output(Bool())
    val redirect_val    = Output(Bool())
    val redirect_pc     = Output(UInt())    //分支指令的结果
    val redirect_ftq_idx= Output(UInt())
    val redirect_ghist  = Output(new GlobalHistory)

    val commit          = Valid(UInt(numFTQEntries.W))
    val flush_icache    = Output(Bool())
}

class FrontendIO extends CoreBundle {
    val cpu = Flipped(new FrontendToCPUIO())
    // val ptw = new TLBPTWIO   // do we need this?
    // val errors = new ICacheErrors
}

/**TODO
 * icache，ras，tlb,ptw的实例化
 * bpd的接口 .354 preds修改
 */
//TODO Frontend.273 bpd，RAS,icache的接口

class Frontend extends CoreModule with FrontendUtils {
    /*--------------------------*/
    val fetchWidth    = frontendParams.fetchWidth
    val numRasEntries = frontendParams.bpdParams.numRasEntries
    val bankWidth     = frontendParams.bankWidth
    val nBanks        = frontendParams.iCacheParams.nBanks
    val lineBytes     = frontendParams.iCacheParams.lineBytes
    val fetchBytes    = frontendParams.fetchBytes
    val bankBytes     = frontendParams.iCacheParams.bankBytes
    val instrBytes    = frontendParams.instrBytes
    /*--------------------------*/
    val io = IO(new FrontendIO)

    // Module definition
    val bpd    = Module(new BranchPredictor())
    val ras    = Module(new Ras)
    val icache = Module(new ICache(frontendParams.iCacheParams))
    val tlb    = Module(new TLB)
    val fb     = Module(new FetchBuffer)
    val ftq    = Module(new FetchTargetQueue)

    icache.io.invalidate := io.cpu.flush_icache

    // --------------------------------------------------------
    // **** NextPC Select (F0) ****
    //      Send request to ICache
    // --------------------------------------------------------

    // note: s0 stage is not a real stage, so the below values are Wire instead of Reg
    // in fact, the s0 stage is hidden within the s1 stage
    val s0_vpc                = WireInit(0.U(vaddrBits.W))
    val s0_ghist              = WireInit((0.U).asTypeOf(new GlobalHistory))
    // val s0_tsrc               = WireInit(0.U(BSRC_SZ.W))
    val s0_valid              = WireInit(false.B)
    val s0_is_replay          = WireInit(false.B)
    val s0_is_sfence          = WireInit(false.B)
    val s0_replay_tlb_resp    = Wire(new TLBResp)
    val s0_replay_bpd_resp    = Wire(new BranchPredictionBundle)
    val s0_replay_ppc         = Wire(UInt(vaddrBits.W))

    when (RegNext(reset.asBool) && !reset.asBool) { // the first cycle after reset
        s0_valid    := true.B
        s0_vpc      := resetPC.U(vaddrBits.W)
        s0_ghist    := (0.U).asTypeOf(new GlobalHistory)    // TODO: cold boot
        // s0_tsrc     := BSRC_C
    }

    icache.io.req.valid     := s0_valid
    icache.io.req.bits.addr := s0_vpc

    bpd.io.f0req.valid      := s0_valid
    bpd.io.f0req.bits.pc    := s0_vpc
    bpd.io.f0req.bits.ghist := s0_ghist

    // --------------------------------------------------------
    // **** ICache Access (F1) ****
    //      Translate VPC
    // --------------------------------------------------------

    val s1_vpc       = RegNext(s0_vpc)
    val s1_valid     = RegNext(s0_valid, false.B)
    val s1_ghist     = RegNext(s0_ghist)
    val s1_is_replay = RegNext(s0_is_replay)
    val s1_is_sfence = RegNext(s0_is_sfence)
    // val s1_tsrc      = RegNext(s0_tsrc) // TODO: maybe more simple

    val f1_clear     = WireInit(false.B)

    tlb.io.req.valid            := (s1_valid && !s1_is_replay && !f1_clear) || s1_is_sfence
    tlb.io.req.bits.cmd         := DontCare
    tlb.io.req.bits.vaddr       := s1_vpc
    tlb.io.req.bits.passthrough := false.B  // may be changed
    tlb.io.req.bits.size        := log2Ceil(fetchWidth * instrBytes).U  // what is this?
    // tlb.io.req.bits.v           := io.ptw.status.v
    // tlb.io.req.bits.prv         := io.ptw.status.prv
    tlb.io.sfence               := RegNext(io.cpu.sfence)
    // tlb.io.kill                 := false.B

    // 如果s1阶段将要进行replay，则不考虑tlb miss
    // 因为此时tlb resp的值是被replay的值，而被replay的值来源之前的s2

    // TODO: TLB miss should call exception
    val s1_tlb_miss = !s1_is_replay && tlb.io.resp.miss
    val s1_tlb_resp = Mux(s1_is_replay, RegNext(s0_replay_tlb_resp), tlb.io.resp)
    val s1_ppc = Mux(s1_is_replay, RegNext(s0_replay_ppc), tlb.io.resp.paddr)
    val s1_bpd_resp = bpd.io.resp.f1

    icache.io.s1_paddr  := s1_ppc
    icache.io.s1_kill   := tlb.io.resp.miss || f1_clear

    val f1_mask = fetchMask(s1_vpc)
    val f1_redirects = (0 until fetchWidth).map{ i=>
        s1_valid && f1_mask(i) && s1_bpd_resp.predInfos(i).predictedpc.valid &&
        (s1_bpd_resp.predInfos(i).isJal ||
        (s1_bpd_resp.predInfos(i).isBranch && s1_bpd_resp.predInfos(i).taken))
    }
    val f1_do_redirect = f1_redirects.reduce(_||_)
    val f1_redirect_idx = PriorityEncoder(f1_redirects)
    val f1_tgts = s1_bpd_resp.predInfos.map(_.predictedpc.bits)
    val f1_predicted_target = Mux(f1_do_redirect, f1_tgts(f1_redirect_idx),
                                                  nextFetch(s1_vpc)
    )
    val f1_predicted_ghist = s1_ghist.update(
        s1_bpd_resp.predInfos.map(p => p.isBranch && p.predictedpc.valid).asUInt & f1_mask,
        s1_bpd_resp.predInfos(f1_redirect_idx).taken && f1_do_redirect,
        s1_bpd_resp.predInfos(f1_redirect_idx).isBranch,
        f1_redirect_idx,
        f1_do_redirect,
        s1_vpc,
        false.B,
        false.B
    )

    // 当前s1寄存器有效 注意，s1阶段可能会replay
    when (s1_valid && !s1_tlb_miss) {
        s0_valid     := !(s1_tlb_resp.ae.inst || s1_tlb_resp.pf.inst) // 发生tlb异常时停止取指
        // s0_tsrc      := BSRC_1
        s0_vpc       := f1_predicted_target
        s0_ghist     := f1_predicted_ghist
        s0_is_replay := false.B
    }

    // --------------------------------------------------------
    // **** ICache Response (F2) ****
    // --------------------------------------------------------

    val s2_valid     = RegNext(s1_valid && !f1_clear, false.B)
    val s2_vpc       = RegNext(s1_vpc)
    val s2_ghist     = Reg(new GlobalHistory)
    val s2_ppc       = RegNext(s1_ppc)
    // val s2_tsrc      = RegNext(s1_tsrc)
    val s2_tlb_resp  = RegNext(s1_tlb_resp)
    val s2_tlb_miss  = RegNext(s1_tlb_miss)
    val s2_is_replay = RegNext(s1_is_replay) && s2_valid

    val f2_clear     = WireInit(false.B)
    // val s2_fsrc      = WireInit(BSRC_1)
    val f3_ready     = Wire(Bool())

    val s2_xcpt = s2_valid && (s2_tlb_resp.ae.inst || s2_tlb_resp.pf.inst) && !s2_is_replay

    icache.io.s2_kill := s2_xcpt

    s2_ghist := s1_ghist

    val f2_mask = fetchMask(s2_vpc)
    val f2_bpd_resp = bpd.io.resp.f2
    val f2_redirects = (0 until fetchWidth).map{ i =>
        s2_valid && f2_mask(i) && f2_bpd_resp.predInfos(i).predictedpc.valid &&
        (f2_bpd_resp.predInfos(i).isJal ||
        (f2_bpd_resp.predInfos(i).isBranch && f2_bpd_resp.predInfos(i).taken))
    }
    val f2_redirect_idx = PriorityEncoder(f2_redirects)
    val f2_tgts = f2_bpd_resp.predInfos.map(_.predictedpc.bits)
    val f2_do_redirect = f2_redirects.reduce(_||_)
    val f2_predicted_target = Mux(f2_do_redirect, f2_tgts(f2_redirect_idx),
                                                  nextFetch(s2_vpc)
    )
    val f2_predicted_ghist = s2_ghist.update(
        f2_bpd_resp.predInfos.map(p => p.isBranch && p.predictedpc.valid).asUInt & f2_mask,
        f2_bpd_resp.predInfos(f2_redirect_idx).taken && f2_do_redirect,
        f2_bpd_resp.predInfos(f2_redirect_idx).isBranch,
        f2_redirect_idx,
        f2_do_redirect,
        s2_vpc,
        false.B,
        false.B
    )

    val f2_correct_f1_ghist = s1_ghist =/= f2_predicted_ghist

    // 当本周期s2需要阻塞时，下一周期s2寄存器valid为假，并且会将内容传给s1寄存器（通过s0）
    when (
        (s2_valid && !icache.io.resp.valid) ||
        (s2_valid && icache.io.resp.valid && !f3_ready)
    ) {
        // TODO: when exception happened, and f3 ready is false, then s0 valid is flase?????
        s0_valid     := !(s2_tlb_resp.ae.inst || s2_tlb_resp.pf.inst) || s2_is_replay || s2_tlb_miss
        s0_vpc       := s2_vpc
        s0_is_replay := s2_valid && icache.io.resp.valid
        s0_ghist     := s2_ghist
        // s0_tsrc      := s2_tsrc
        f1_clear     := true.B
    } .elsewhen(s2_valid && f3_ready) {
        when(s1_valid && s1_vpc === f2_predicted_target && !f2_correct_f1_ghist){
            s2_ghist := f2_predicted_ghist
        }
        when((s1_valid && (s1_vpc =/= f2_predicted_target || f2_correct_f1_ghist)) || !s1_valid){
            // TODO: same problem as above
            s0_valid     := !((s2_tlb_resp.ae.inst || s2_tlb_resp.pf.inst) && !s2_is_replay)
            s0_vpc       := f2_predicted_target
            s0_is_replay := false.B
            s0_ghist     := f2_predicted_ghist
            // s2_fsrc      := BSRC_2
            // s0_tsrc      := BSRC_2
            f1_clear     := true.B
        }
    }
    s0_replay_bpd_resp := f2_bpd_resp
    s0_replay_tlb_resp := s2_tlb_resp
    s0_replay_ppc := s2_ppc

    // --------------------------------------------------------
    // **** F3 ****
    //      PreDecode
    // --------------------------------------------------------

    val f3_clear = WireInit(false.B)
    val f4_ready = Wire(Bool())
    val f3 = withReset(reset.asBool || f3_clear) {
        Module(new Queue(new FetchResp, 1, pipe = true, flow = false))
    }
    // f3_bpd_resp的输入是f3的数据，输出也是f3的数据（flow）。
    val f3_bpd_resp = withReset(reset.asBool || f3_clear) {
        Module(new Queue(new BranchPredictionBundle, 1, pipe = true, flow = true))
    }

    f3_ready := f3.io.enq.ready

    /**
     * 进s3条件：
     *  1. s2指令有效
     *  2. icache返回结果有效，或者是tlb除了miss以外的异常。miss情况可能可以由ptw解决，所以暂时不入队
     */
    // TODO 没有ptw，s2_tlb_miss或许不需要判定is_replay，并把s2_tlb_miss与ae，pf合在一起
    f3.io.enq.valid := (s2_valid && !f2_clear &&
        (icache.io.resp.valid || ((s2_tlb_resp.ae.inst || s2_tlb_resp.pf.inst) && !s2_tlb_miss))
    )
    f3.io.enq.bits.pc    := s2_vpc
    f3.io.enq.bits.data  := Mux(s2_xcpt, 0.U, icache.io.resp.bits.data)
    f3.io.enq.bits.gHist := s2_ghist
    f3.io.enq.bits.mask  := fetchMask(s2_vpc)
    f3.io.enq.bits.xcpt  := s2_tlb_resp // ????
    // f3.io.enq.bits.fsrc  := s2_fsrc
    // f3.io.enq.bits.tsrc := s2_tsrc

    // RAS输入在s2，输出在s3
    val ras_read_idx = RegInit(0.U(log2Ceil(numRasEntries).W))  // ensure that the RAS response is in the same cycle as f3
    ras.io.read_idx := ras_read_idx
    when (f3.io.enq.fire) {
        ras_read_idx := f3.io.enq.bits.gHist.rasIdx
        ras.io.read_idx := f3.io.enq.bits.gHist.rasIdx
    }

    f3_bpd_resp.io.enq.valid := f3.io.deq.valid && RegNext(f3.io.enq.ready)
    f3_bpd_resp.io.enq.bits := bpd.io.resp.f3

    bpd.io.f3fire := f3_bpd_resp.io.enq.fire

    f3.io.deq.ready := f4_ready
    f3_bpd_resp.io.deq.ready := f4_ready

    val f3_fetchResp             = f3.io.deq.bits
    val f3_bank_mask             = bankMask(f3_fetchResp.pc)
    val f3_data                  = f3_fetchResp.data
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
    for(b <- 0 until nBanks){
        val bank_data = f3_data((b + 1) * bankWidth * coreInstrBits - 1, b * bankWidth * coreInstrBits)
        for(w <- 0 until bankWidth) {

            // val bpu = Module(new BreakpointUnit(nBreakpoints))
            // bpu.io.status   := io.cpu.status
            // bpu.io.bp := io.cpu.bp
            // bpu.io.ea := DontCare
            // bpu.io.mcontext := io.cpu.mcontext
            // bpu.io.scontext := io.cpu.scontext

            val i = (b * bankWidth) + w
            val pc = (f3_aligned_pc + (i << log2Ceil(coreInstrBits)).U)
            val instr = bank_data(w * coreInstrBits + coreInstrBits - 1,w * coreInstrBits)

            val bpd_decoder = Module(new PreDecode)
            bpd_decoder.io.pc := pc
            bpd_decoder.io.instr := instr
            val brsigs = bpd_decoder.io.out

            f3_fetch_bundle.instrs(i) := instr
            f3_mask(i) := f3.io.deq.valid && f3_fetchResp.mask(i) && !redirect_found

            f3_tgts(i) := Mux(
                brsigs.cfiType === CFI_JALR,
                    f3_bpd_resp.io.deq.bits.predInfos(i).predictedpc.bits, // <- maybe wrong
                    brsigs.target   // <- right
            )
            f3_btb_mispredicts(i) := (
                brsigs.cfiType === CFI_JAL &&
                f3_bpd_resp.io.deq.bits.predInfos(i).predictedpc.valid &&
                (f3_bpd_resp.io.deq.bits.predInfos(i).predictedpc =/= brsigs.target)
            )

            // i << 1是防止溢出，因为sfbOffset <= Cacheline
            val offset_from_aligned_pc = (
                (i << 1).U((log2Ceil(lineBytes) + 1).W) + brsigs.sfbOffset.bits
            )
            val lower_mask = Wire(UInt((2 * fetchWidth).W))
            val upper_mask = Wire(UInt((2 * fetchWidth).W))
            lower_mask := UIntToOH(i.U)
            upper_mask := UIntToOH(offset_from_aligned_pc(log2Ceil(fetchBytes) + 1,1)) << Mux(f3_is_last_bank_in_block, bankWidth.U, 0.U)

            /**
             * 判断是否是sfb指令，如果是Cacheline的最后一个bank，那么最多只能取3个bank（跨Cacheline）
             * 正常情况，可以取4个bank
             */
            f3_fetch_bundle.sfbs(i) := (
                f3_mask(i) && brsigs.sfbOffset.valid &&
                (offset_from_aligned_pc <= Mux(f3_is_last_bank_in_block, (fetchBytes + bankBytes).U,(2 * fetchBytes).U))
            )
            f3_fetch_bundle.sfb_masks(i) := ~MaskLower(lower_mask) & ~MaskUpper(upper_mask)
            /**
             * 没有发生异常
             * bank有效
             * 是shadowable的或者该位置指令无效
             */
            f3_fetch_bundle.shadowable_mask(i) := (
                !(f3_fetch_bundle.xcpt_pf_if || f3_fetch_bundle.xcpt_ae_if ) &&
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
    f3_fetch_bundle.brMask       := f3_br_mask.asUInt
    f3_fetch_bundle.pc            := f3_fetchResp.pc
    f3_fetch_bundle.ftqIdx       := 0.U    // TODO: DontCare?
    f3_fetch_bundle.xcpt_pf_if    := f3_fetchResp.xcpt.pf
    f3_fetch_bundle.xcpt_ae_if    := f3_fetchResp.xcpt.ae
    // f3_fetch_bundle.fsrc          := f3_fetchResp.fsrc
    // f3_fetch_bundle.tsrc          := f3_fetchResp.tsrc
    f3_fetch_bundle.shadowed_mask := f3_shadowed_mask

    f3_fetch_bundle.cfiIdx.valid := f3_redirects.reduce(_||_)
    f3_fetch_bundle.cfiIdx.bits  := PriorityEncoder(f3_redirects)
    f3_fetch_bundle.cfiType      := f3_cfi_types(f3_fetch_bundle.cfiIdx.bits)
    f3_fetch_bundle.cfiIsCall   := f3_call_mask(f3_fetch_bundle.cfiIdx.bits)
    f3_fetch_bundle.cfiIsRet    := f3_ret_mask(f3_fetch_bundle.cfiIdx.bits)
    f3_fetch_bundle.gHist         := f3.io.deq.bits.gHist
    f3_fetch_bundle.lHist         := f3_bpd_resp.io.deq.bits.lhist
    f3_fetch_bundle.bpdMeta      := f3_bpd_resp.io.deq.bits.meta
    f3_fetch_bundle.rasTop       := ras.io.read_addr

    val f3_predicted_target = Mux(f3_redirects.reduce(_||_),
        Mux(f3_fetch_bundle.cfiIsRet, ras.io.read_addr,
            f3_tgts(PriorityEncoder(f3_redirects))),
        nextFetch(f3_fetch_bundle.pc)
    )

    f3_fetch_bundle.next_pc := f3_predicted_target
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
    ras.io.write_addr  := f3_aligned_pc + ((f3_fetch_bundle.cfiIdx.bits << 2)) + 4.U
    ras.io.write_idx   := WrapInc(f3_fetch_bundle.gHist.rasIdx, numRasEntries)

    val f3_correct_f1_ghist = s1_ghist =/= f3_predicted_ghist
    val f3_correct_f2_ghist = s2_ghist =/= f3_predicted_ghist

    when (f3.io.deq.valid && f4_ready) {
        when(f3_fetch_bundle.cfiIsCall && f3_fetch_bundle.cfiIdx.valid){
            ras.io.write_valid := true.B
        }

        when (s2_valid && s2_vpc === f3_predicted_target&& !f3_correct_f2_ghist) {
            f3.io.enq.bits.gHist := f3_predicted_ghist
        } .elsewhen (!s2_valid && s1_valid && s1_vpc === f3_predicted_target && !f3_correct_f1_ghist) {
            s2_ghist := f3_predicted_ghist
        } .elsewhen (
            (s2_valid && (s2_vpc =/= f3_predicted_target || f3_correct_f2_ghist)) ||
            (!s2_valid && s1_valid && (s1_vpc =/= f3_predicted_target || f3_correct_f1_ghist)) ||
            (!s2_valid && !s1_valid)
        ) {
            f2_clear     := true.B
            f1_clear     := true.B
            s0_valid     := !(f3_fetch_bundle.xcpt_pf_if || f3_fetch_bundle.xcpt_ae_if)
            s0_vpc       := f3_predicted_target
            s0_is_replay := false.B
            s0_ghist     := f3_predicted_ghist
            // s0_tsrc      := BSRC_3
            // f3_fetch_bundle.fsrc := BSRC_3
        }
    }

    // 当f3发现btb预测错误时，建一个队列来存储bpd更新
    val f4_btb_corrections = Module(new Queue(new BranchPredictionUpdate, 2))

    f4_btb_corrections.io.enq.valid                   := f3.io.deq.fire && f3_btb_mispredicts.reduce(_||_)
    f4_btb_corrections.io.enq.bits                    := DontCare
    f4_btb_corrections.io.enq.bits.isMispredictUpdate := false.B
    f4_btb_corrections.io.enq.bits.isRepairUpdate     := false.B
    f4_btb_corrections.io.enq.bits.btbMispredicts     := f3_btb_mispredicts.asUInt
    f4_btb_corrections.io.enq.bits.pc                 := f3_fetch_bundle.pc
    f4_btb_corrections.io.enq.bits.gHist              := f3_fetch_bundle.gHist
    f4_btb_corrections.io.enq.bits.lHist              := f3_fetch_bundle.lHist
    f4_btb_corrections.io.enq.bits.meta               := f3_fetch_bundle.bpdMeta

    // -------------------------------------------------------
    // **** F4 ****
    // -------------------------------------------------------

    val f4_clear = WireInit(false.B)
    val f4 = withReset(reset.asBool || f4_clear) {
        Module(new Queue(new FetchBundle, 1, pipe = true, flow = false))
    }

    // 下面将要处理sfbs
    val f4_shadowable_masks = VecInit((0 until fetchWidth).map{ i =>
        f4.io.deq.bits.shadowable_mask.asUInt |
        ~f4.io.deq.bits.sfb_masks(i)(fetchWidth - 1,0)    // the instructions which not in sfb shadow
    })
    val f3_shadowable_masks = VecInit((0 until fetchWidth).map{ i =>
        Mux(f4.io.enq.valid, f4.io.enq.bits.shadowable_mask.asUInt, 0.U) |
        ~f4.io.deq.bits.sfb_masks(i)(2 * fetchWidth - 1, fetchWidth)
    })
    val f4_sfbs = VecInit((0 until fetchWidth) map {i => (
        (~f4_shadowable_masks(i) === 0.U) && (~f3_shadowable_masks(i) === 0.U) &&
        f4.io.deq.bits.sfbs(i) &&
        !(f4.io.deq.bits.cfiIdx.valid && f4.io.deq.bits.cfiIdx.bits === i.U)
    )})
    val f4_sfb_valid    = f4.io.deq.valid && f4_sfbs.reduce(_||_)
    val f4_sfb_idx      = PriorityEncoder(f4_sfbs)
    val f4_sfb_mask     = f4.io.deq.bits.sfb_masks(f4_sfb_idx)
    // 如果f4阶段有sfb指令，要等待下一次fetch
    val f4_delay = (
        f4.io.deq.bits.sfbs.reduce(_||_) &&
        !f4.io.deq.bits.cfiIdx.valid &&
        !f4.io.enq.valid &&
        !(f4.io.deq.bits.xcpt_pf_if || f4.io.deq.bits.xcpt_ae_if)
    )
    when (f4_sfb_valid){
        f3_shadowed_mask := f4_sfb_mask(2 * fetchWidth - 1,fetchWidth).asBools
    }.otherwise{
        f3_shadowed_mask := VecInit(0.U(fetchWidth.W).asBools)
    }

    f4_ready        := f4.io.enq.ready
    f4.io.enq.valid := f3.io.deq.valid && !f3_clear
    f4.io.enq.bits  := f3_fetch_bundle
    f4.io.deq.ready := fb.io.enq.ready && ftq.io.enq.ready && !f4_delay

    fb.io.enq.valid             := f4.io.deq.valid && ftq.io.enq.ready && !f4_delay
    fb.io.enq.bits              := f4.io.deq.bits
    fb.io.enq.bits.ftqIdx       := ftq.io.enqIdx
    fb.io.enq.bits.sfbs         := Mux(f4_sfb_valid, UIntToOH(f4_sfb_idx), 0.U(fetchWidth.W)).asBools
    fb.io.enq.bits.shadowedMask := (
        Mux(f4_sfb_valid, f4_sfb_mask(fetchWidth - 1,0), 0.U(fetchWidth.W)) |
        f4.io.deq.bits.shadowed_mask.asUInt
    ).asBools

    ftq.io.enq.valid := f4.io.deq.valid && fb.io.enq.ready && !f4_delay
    ftq.io.enq.bits  := f4.io.deq.bits

    val bpd_update_arbiter = Module(new Arbiter(new BranchPredictionUpdate, 2))
    assert(bpd_update_arbiter.io.in(0).ready)
    bpd_update_arbiter.io.out.ready := true.B

    bpd_update_arbiter.io.in(0).valid := ftq.io.bpdUpdate.valid
    bpd_update_arbiter.io.in(0).bits  := ftq.io.bpdUpdate.bits
    bpd_update_arbiter.io.in(1) <> f4_btb_corrections.io.deq

    bpd.io.update := bpd_update_arbiter.io.out

    //ftq更新ras
    when(ftq.io.rasUpdate){
        ras.io.write_valid  := true.B
        ras.io.write_idx    := ftq.io.rasUpdateIdx
        ras.io.write_addr   := ftq.io.rasUpdatepc
    }

    // -------------------------------------------------------
    // **** To Core (F5) ****
    // -------------------------------------------------------

    io.cpu.fetchPacket <> fb.io.deq
    io.cpu.getFtqPc    <> ftq.io.getFtqpc

    ftq.io.deq            := io.cpu.commit
    ftq.io.brUpdate       := io.cpu.brupdate
    ftq.io.redirect.valid := io.cpu.redirect_val
    ftq.io.redirect.bits  := io.cpu.redirect_ftq_idx
    
    fb.io.clear := false.B

    when (io.cpu.sfence.valid) {
        fb.io.clear  := true.B
        f4_clear     := true.B
        f3_clear     := true.B
        f2_clear     := true.B
        f1_clear     := true.B

        s0_valid     := false.B
        s0_vpc       := io.cpu.sfence.bits.addr
        s0_is_replay := false.B
        s0_is_sfence := true.B
    } .elsewhen(io.cpu.redirect_flush) {
        fb.io.clear := true.B
        f4_clear    := true.B
        f3_clear    := true.B
        f2_clear    := true.B
        f1_clear    := true.B

        s0_valid := io.cpu.redirect_val
        s0_vpc := io.cpu.redirect_pc
        s0_ghist := io.cpu.redirect_ghist
        // s0_tsrc := BSRC_C
        s0_is_replay := false.B

        ftq.io.redirect.valid := io.cpu.redirect_val
        ftq.io.redirect.bits := io.cpu.redirect_ftq_idx
    }
}
