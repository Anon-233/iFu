package iFu

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.frontend._
import iFu.frontend.FrontendUtils.bankAlign
import iFu.backend._
import iFu.util._

class iFuCore extends CoreModule {
    val io = IO(new CoreBundle {
        // input logic clk, reset,
        // output ibus_req_t  ireq,
        // input  ibus_resp_t iresp,
        // output dbus_req_t  dreq,
        // input  dbus_resp_t dresp,
        // input logic [7:0] ext_int

        //        val interrupts = Input(new freechips.rocketchip.tile.CoreInterrupts())
        // val ptw_tlb = new freechips.rocketchip.rocket.TLBPTWIO()
    })
    //**********************************
    // construct all of the modules
    val fetchWidth  = frontendParams.fetchWidth
    val decodeWidth = coreWidth
    val bankBytes   = frontendParams.iCacheParams.bankBytes

    val ifu = Module(new Frontend)

    // Only holds integer-registerfile execution units.
    val exe_units = new ExecutionUnits
    val jmp_unit_idx = exe_units.jmp_unit_idx
    val jmp_unit = exe_units(jmp_unit_idx)


    val numIrfWritePorts = exe_units.numIrfWritePorts + memWidth
    val numMemIrfWritePorts = exe_units.numMemIrfWritePorts
    val numIrfReadPorts = exe_units.numIrfReadPorts

    val numFastWakeupPorts = exe_units.count(_.bypassable)
    val numAlwaysBypassable = exe_units.count(_.alwaysBypassable)

    val numIntIssueWakeupPorts = numIrfWritePorts + numFastWakeupPorts - numAlwaysBypassable // + memWidth for ll_wb
    val numIntRenameWakeupPorts = numIntIssueWakeupPorts

    val decode_units = for (w <- 0 until decodeWidth) yield {
        val d = Module(new DecodeUnit); d
    }
    val dec_brmask_logic = Module(new BranchMaskGenerationLogic)
    val rename_stage = Module(new RenameStage(coreWidth, numPRegs, numIntRenameWakeupPorts))
    val pred_rename_stage = Module(new PredRenameStage(coreWidth, ftqSz, 1))
    val rename_stages = Seq(rename_stage, pred_rename_stage)

    val memIssueParam = issueParams.filter(_.iqType == IQT_MEM)(0)
    val intIssueParam = issueParams.filter(_.iqType == IQT_INT)(0)
    val mem_iss_unit = Module(new IssueUnitAgeOrdered(memIssueParam, numIntIssueWakeupPorts))
    /*mem_iss_unit.suggestName("mem_issue_unit")*/
    val int_iss_unit = Module(new IssueUnitAgeOrdered(intIssueParam, numIntIssueWakeupPorts))
    /*int_iss_unit.suggestName("int_issue_unit")*/

    val issue_units = Seq(mem_iss_unit, int_iss_unit)
    val dispatcher = Module(new BasicDispatcher)
    val ftqSz      = frontendParams.numFTQEntries
    val iregfile = Module(new RegisterFileSynthesizable(
        numPRegs,
        numIrfReadPorts,
        numIrfWritePorts,
        xLen,
        Seq.fill(memWidth) {
            true
        } ++ exe_units.bypassable_write_port_mask)) // bypassable ll_wb
    val pregfile = Module(new RegisterFileSynthesizable(
        ftqSz,
        exe_units.numIrfReaders,
        1,
        1,
        Seq(true))) // The jmp unit is always bypassable
    pregfile.io := DontCare // Only use the IO if enableSFBOpt

    // wb arbiter for the 0th ll writeback
    // TODO: 不需要仲裁器

    val ll_wbarb         = Module(new Arbiter(new ExeUnitResp(xLen), 1 ))
    //            (if (usingFPU) 1 else 0) +
    //            (if (usingRoCC) 1 else 0)))
    val iregister_read = Module(new RegisterRead(
        issue_units.map(_.issueWidth).sum,
        exe_units.withFilter(_.readsIrf).map(_.supportedFuncUnits).toSeq,
        numIrfReadPorts,
        exe_units.withFilter(_.readsIrf).map(x => 2).toSeq,
        exe_units.numTotalBypassPorts,
        jmp_unit.numStages,
        xLen))
    val rob = Module(new Rob(numIrfWritePorts))
    // Used to wakeup registers in rename and issue. ROB needs to listen to something else.
    val int_iss_wakeups = Wire(Vec(numIntIssueWakeupPorts, Valid(new ExeUnitResp)))
    val int_ren_wakeups = Wire(Vec(numIntRenameWakeupPorts, Valid(new ExeUnitResp)))
    val pred_wakeup = Wire(Valid(new ExeUnitResp(1)))

    require(exe_units.length == issue_units.map(_.issueWidth).sum)

    //***********************************
    // Pipeline State Registers and Wires

    // Decode/Rename1 Stage
    val dec_valids = Wire(Vec(coreWidth, Bool())) // are the decoded instruction valid? It may be held up though.
    val dec_uops = Wire(Vec(coreWidth, new MicroOp()))
    val dec_fire = Wire(Vec(coreWidth, Bool())) // can the instruction fire beyond decode?
    // (can still be stopped in ren or dis)
    val dec_ready = Wire(Bool())
    val dec_xcpts = Wire(Vec(coreWidth, Bool()))
    val ren_stalls = Wire(Vec(coreWidth, Bool()))

    // Rename2/Dispatch stage
    val dis_valids = Wire(Vec(coreWidth, Bool()))
    val dis_uops = Wire(Vec(coreWidth, new MicroOp))
    val dis_fire = Wire(Vec(coreWidth, Bool()))
    val dis_ready = Wire(Bool())

    // Issue Stage/Register Read
    val iss_valids = Wire(Vec(exe_units.numIrfReaders, Bool()))
    val iss_uops = Wire(Vec(exe_units.numIrfReaders, new MicroOp()))
    val bypasses = Wire(Vec(exe_units.numTotalBypassPorts, Valid(new ExeUnitResp(xLen))))
    val pred_bypasses = Wire(Vec(jmp_unit.numStages, Valid(new ExeUnitResp(1))))
    require(jmp_unit.bypassable)

    // --------------------------------------
    // Dealing with branch resolutions

    // The individual branch resolutions from each ALU
    val brinfos = Reg(Vec(coreWidth, new BrResolutionInfo()))

    // "Merged" branch update info from all ALUs
    // brmask contains masks for rapidly clearing mispredicted instructions
    // brindices contains indices to reset pointers for allocated structures
    //           brindices is delayed a cycle
    val brupdate = Wire(new BrUpdateInfo)
    val b1 = Wire(new BrUpdateMasks)
    val b2 = Reg(new BrResolutionInfo)

    brupdate.b1 := b1
    brupdate.b2 := b2

    for ((b, a) <- brinfos zip exe_units.alu_units) {
        b := a.io.brinfo
        b.valid := a.io.brinfo.valid && !rob.io.flush.valid
    }
    b1.resolveMask := brinfos.map(x => x.valid << x.uop.brTag).reduce(_ | _)
    b1.mispredictMask := brinfos.map(x => (x.valid && x.mispredict) << x.uop.brTag).reduce(_ | _)

    // Find the oldest mispredict and use it to update indices
    var mispredict_val = false.B
    var oldest_mispredict = brinfos(0)
    for (b <- brinfos) {
        val use_this_mispredict = !mispredict_val ||
                b.valid && b.mispredict && IsOlder(b.uop.robIdx, oldest_mispredict.uop.robIdx, rob.io.rob_head_idx)

        mispredict_val = mispredict_val || (b.valid && b.mispredict)
        oldest_mispredict = Mux(use_this_mispredict, b, oldest_mispredict)
    }

    b2.mispredict := mispredict_val
    b2.cfiType := oldest_mispredict.cfiType
    b2.taken := oldest_mispredict.taken
    b2.pcSel := oldest_mispredict.pcSel
    b2.uop := UpdateBrMask(brupdate, oldest_mispredict.uop)
    b2.jalrTarget := RegNext(jmp_unit.io.brinfo.jalrTarget)
    b2.targetOffset := oldest_mispredict.targetOffset

    val oldest_mispredict_ftq_idx = oldest_mispredict.uop.ftqIdx


    assert(!((brupdate.b1.mispredictMask =/= 0.U || brupdate.b2.mispredict)
            && rob.io.commit.rollback), "Can't have a mispredict during rollback.")

    ifu.io.exe.brupdate := brupdate

    for (eu <- exe_units) {
        eu.io.brupdate := brupdate
    }


    // Load/Store Unit & ExeUnits
    val mem_units = exe_units.memory_units
    val mem_resps = mem_units.map(_.io.mem_iresp)
    for (i <- 0 until memWidth) {
        mem_units(i).io.lsu_io <> lsu.io.core.exe(i)
    }


    //    val csr = Module(new freechips.rocketchip.rocket.CSRFile(perfEvents, boomParams.customCSRs.decls))
    //    csr.io.inst foreach { c => c := DontCare }
    //    csr.io.rocc_interrupt := io.rocc.interrupt


    //-------------------------------------------------------------
    //-------------------------------------------------------------
    // **** Fetch Stage/Frontend ****
    //-------------------------------------------------------------
    //-------------------------------------------------------------
    ifu.io.exe.redirect_val := false.B
    ifu.io.exe.redirect_flush := false.B

    // Breakpoint info
    //    ifu.io.exe.status  := csr.io.status
    //    ifu.io.exe.bp      := csr.io.bp
    //    ifu.io.exe.mcontext := csr.io.mcontext
    //    ifu.io.exe.scontext := csr.io.scontext

    ifu.io.exe.flush_icache := (0 until coreWidth).map { i =>
        (rob.io.commit.arch_valids(i) && rob.io.commit.uops(i).is_fencei) /*||
                (RegNext(dec_valids(i) && dec_uops(i).isJalr && csr.io.status.debug))*/
    }.reduce(_ || _)

    val icBlockBytes = frontendParams.iCacheParams.lineBytes
    when(RegNext(rob.io.flush.valid)) {
        ifu.io.exe.redirect_val := true.B
        ifu.io.exe.redirect_flush := true.B
        val flush_typ = RegNext(rob.io.flush.bits.flush_typ)
        // Clear the global history when we flush the ROB (exceptions, AMOs, unique instructions, etc.)
        val new_ghist = WireInit((0.U).asTypeOf(new GlobalHistory))
        new_ghist.currentSawBranchNotTaken := true.B
        new_ghist.rasIdx := ifu.io.exe.getFtqPc(0).entry.rasIdx
        ifu.io.exe.redirect_ghist := new_ghist
        when(FlushTypes.useCsrEvec(flush_typ)) {
            ifu.io.exe.redirect_pc := Mux(flush_typ === FlushTypes.eret,
                RegNext(RegNext(csr.io.evec)),
                csr.io.evec)
        }.otherwise {
            val flush_pc = (AlignPCToBoundary(ifu.io.exe.getFtqPc(0).pc, icBlockBytes)
                    + RegNext(rob.io.flush.bits.pc_lob))

            val flush_pc_next = flush_pc + Mux(RegNext(rob.io.flush.bits.is_rvc), 2.U, 4.U)
            ifu.io.exe.redirect_pc := Mux(FlushTypes.useSamePC(flush_typ),
                flush_pc, flush_pc_next)

        }
        ifu.io.exe.redirect_ftq_idx := RegNext(rob.io.flush.bits.ftq_idx)
    }.elsewhen(brupdate.b2.mispredict && !RegNext(rob.io.flush.valid)) {
        val block_pc = AlignPCToBoundary(ifu.io.exe.getFtqPc(1).pc, icBlockBytes)
        val uop_maybe_pc = block_pc | brupdate.b2.uop.pcLowBits
        val npc = uop_maybe_pc +  4.U
        val jal_br_target = Wire(UInt(vaddrBits.W))
        jal_br_target := (uop_maybe_pc.asSInt + brupdate.b2.targetOffset +
                (Fill(vaddrBits - 1, brupdate.b2.uop.edge_inst) << 1).asSInt).asUInt
        val bj_addr = Mux(brupdate.b2.cfiType === CFI_JALR, brupdate.b2.jalrTarget, jal_br_target)
        val mispredict_target = Mux(brupdate.b2.pcSel === PC_PLUS4, npc, bj_addr)
        ifu.io.exe.redirect_val := true.B
        ifu.io.exe.redirect_pc := mispredict_target
        ifu.io.exe.redirect_flush := true.B
        ifu.io.exe.redirect_ftq_idx := brupdate.b2.uop.ftqIdx
        val use_same_ghist = (brupdate.b2.cfiType === CFI_BR &&
                !brupdate.b2.taken &&
                bankAlign(block_pc) === bankAlign(npc))
        val ftq_entry = ifu.io.exe.getFtqPc(1).entry
        val cfi_idx = (brupdate.b2.uop.pcLowBits ^
                Mux(ftq_entry.startBank === 1.U, 1.U << log2Ceil(bankBytes), 0.U))(log2Ceil(fetchWidth), 1)
        val ftq_ghist = ifu.io.exe.getFtqPc(1).gHist
        val next_ghist = ftq_ghist.update(
            ftq_entry.brMask.asUInt,
            brupdate.b2.taken,
            brupdate.b2.cfiType === CFI_BR,
            cfi_idx,
            true.B,
            ifu.io.exe.getFtqPc(1).pc,
            ftq_entry.cfiIsCall && ftq_entry.cfiIdx.bits === cfi_idx,
            ftq_entry.cfiIsCall && ftq_entry.cfiIdx.bits === cfi_idx)


        ifu.io.exe.redirect_ghist := Mux(
            use_same_ghist,
            ftq_ghist,
            next_ghist)
        ifu.io.exe.redirect_ghist.currentSawBranchNotTaken := use_same_ghist
    }.elsewhen(rob.io.flush_frontend || brupdate.b1.mispredictMask =/= 0.U) {
        ifu.io.exe.redirect_flush := true.B
    }

    // Tell the FTQ it can deallocate entries by passing youngest ftq_idx.
    val youngest_com_idx = (coreWidth - 1).U - PriorityEncoder(rob.io.commit.valids.reverse)
    ifu.io.exe.commit.valid := rob.io.commit.valids.reduce(_ | _) || rob.io.com_xcpt.valid
    ifu.io.exe.commit.bits := Mux(rob.io.com_xcpt.valid,
        rob.io.com_xcpt.bits.ftq_idx,
        rob.io.commit.uops(youngest_com_idx).ftqIdx)

    assert(!(rob.io.commit.valids.reduce(_ | _) && rob.io.com_xcpt.valid),
        "ROB can't commit and except in same cycle!")

    for (i <- 0 until memWidth) {
        when(RegNext(lsu.io.core.exe(i).req.bits.sfence.valid)) {
            ifu.io.exe.sfence := RegNext(lsu.io.core.exe(i).req.bits.sfence)
        }
    }

    //-------------------------------------------------------------
    //-------------------------------------------------------------
    // **** Branch Prediction ****
    //-------------------------------------------------------------
    //-------------------------------------------------------------

    //-------------------------------------------------------------
    //-------------------------------------------------------------
    // **** Decode Stage ****
    //-------------------------------------------------------------
    //-------------------------------------------------------------

    // track mask of finished instructions in the bundle
    // use this to mask out insts coming from FetchBuffer that have been finished
    // for example, back pressure may cause us to only issue some instructions from FetchBuffer
    // but on the next cycle, we only want to retry a subset
    val dec_finished_mask = RegInit(0.U(coreWidth.W))

    //-------------------------------------------------------------
    // Pull out instructions and send to the Decoders

    ifu.io.exe.fetchPacket.ready := dec_ready
    val dec_fbundle = ifu.io.exe.fetchPacket.bits

    //-------------------------------------------------------------
    // Decoders

    for (w <- 0 until coreWidth) {
        dec_valids(w) := ifu.io.exe.fetchPacket.valid && dec_fbundle.uops(w).valid &&
                !dec_finished_mask(w)
        decode_units(w).io.enq.uop := dec_fbundle.uops(w).bits
        decode_units(w).io.status := csr.io.status
        decode_units(w).io.csr_decode <> csr.io.decode(w)
        decode_units(w).io.interrupt := csr.io.interrupt
        decode_units(w).io.interrupt_cause := csr.io.interrupt_cause

        dec_uops(w) := decode_units(w).io.deq.uop
    }

    //-------------------------------------------------------------
    // FTQ GetPC Port Arbitration

    val jmp_pc_req = Wire(Decoupled(UInt(log2Ceil(ftqSz).W)))
    val xcpt_pc_req = Wire(Decoupled(UInt(log2Ceil(ftqSz).W)))
    val flush_pc_req = Wire(Decoupled(UInt(log2Ceil(ftqSz).W)))

    val ftq_arb = Module(new Arbiter(UInt(log2Ceil(ftqSz).W), 3))

    // Order by the oldest. Flushes come from the oldest instructions in pipe
    // Decoding exceptions come from youngest
    ftq_arb.io.in(0) <> flush_pc_req
    ftq_arb.io.in(1) <> jmp_pc_req
    ftq_arb.io.in(2) <> xcpt_pc_req

    // Hookup FTQ
    ifu.io.exe.get_pc(0).ftq_idx := ftq_arb.io.out.bits
    ftq_arb.io.out.ready := true.B

    // Branch Unit Requests (for JALs) (Should delay issue of JALs if this not ready)
    jmp_pc_req.valid := RegNext(iss_valids(jmp_unit_idx) && iss_uops(jmp_unit_idx).fuCode === FU_JMP)
    jmp_pc_req.bits := RegNext(iss_uops(jmp_unit_idx).ftqIdx)

    jmp_unit.io.getFtqPc := DontCare
    jmp_unit.io.getFtqPc.pc := ifu.io.exe.getFtqPc(0).pc
    jmp_unit.io.getFtqPc.entry := ifu.io.exe.getFtqPc(0).entry
    jmp_unit.io.getFtqPc.nextVal := ifu.io.exe.getFtqPc(0).nextVal
    jmp_unit.io.getFtqPc.nextpc := ifu.io.exe.getFtqPc(0).nextpc


    // Frontend Exception Requests
    val xcpt_idx = PriorityEncoder(dec_xcpts)
    xcpt_pc_req.valid := dec_xcpts.reduce(_ || _)
    xcpt_pc_req.bits := dec_uops(xcpt_idx).ftqIdx
    //rob.io.xcpt_fetch_pc := RegEnable(ifu.io.exe.get_pc.fetch_pc, dis_ready)
    rob.io.xcpt_fetch_pc := ifu.io.exe.getFtqPc(0).pc

    flush_pc_req.valid := rob.io.flush.valid
    flush_pc_req.bits := rob.io.flush.bits.ftq_idx

    // Mispredict requests (to get the correct target)
    ifu.io.exe.getFtqPc(1).ftqIdx := oldest_mispredict_ftq_idx


    //-------------------------------------------------------------
    // Decode/Rename1 pipeline logic

    dec_xcpts := dec_uops zip dec_valids map { case (u, v) => u.exception && v }
    val dec_xcpt_stall = dec_xcpts.reduce(_ || _) && !xcpt_pc_req.ready
    // stall fetch/dcode because we ran out of branch tags
    val branch_mask_full = Wire(Vec(coreWidth, Bool()))

    val dec_hazards = (0 until coreWidth).map(w =>
        dec_valids(w) &&
                (!dis_ready
                        || rob.io.commit.rollback
                        || dec_xcpt_stall
                        || branch_mask_full(w)
                        || brupdate.b1.mispredictMask =/= 0.U
                        || brupdate.b2.mispredict
                        || ifu.io.exe.redirect_flush))

    val dec_stalls = dec_hazards.scanLeft(false.B)((s, h) => s || h).takeRight(coreWidth)
    dec_fire := (0 until coreWidth).map(w => dec_valids(w) && !dec_stalls(w))

    // all decoders are empty and ready for new instructions
    dec_ready := dec_fire.last

    when(dec_ready || ifu.io.exe.redirect_flush) {
        dec_finished_mask := 0.U
    }.otherwise {
        dec_finished_mask := dec_fire.asUInt | dec_finished_mask
    }

    //-------------------------------------------------------------
    // Branch Mask Logic

    dec_brmask_logic.io.brupdate := brupdate
    dec_brmask_logic.io.flush_pipeline := RegNext(rob.io.flush.valid)

    for (w <- 0 until coreWidth) {
        dec_brmask_logic.io.is_branch(w) := !dec_finished_mask(w) && dec_uops(w).allocate_brtag
        dec_brmask_logic.io.will_fire(w) := dec_fire(w) &&
                dec_uops(w).allocate_brtag // ren, dis can back pressure us
        dec_uops(w).brTag := dec_brmask_logic.io.br_tag(w)
        dec_uops(w).brMask := dec_brmask_logic.io.br_mask(w)
    }

    branch_mask_full := dec_brmask_logic.io.is_full

    //-------------------------------------------------------------
    //-------------------------------------------------------------
    // **** Register Rename Stage ****
    //-------------------------------------------------------------
    //-------------------------------------------------------------

    // Inputs
    for (rename <- rename_stages) {
        rename.io.kill := ifu.io.exe.redirect_flush
        rename.io.brupdate := brupdate

        rename.io.dec_fire := dec_fire
        rename.io.dec_uops := dec_uops

        rename.io.dis_fire := dis_fire
        rename.io.dis_ready := dis_ready

        rename.io.com_valids := rob.io.commit.valids
        rename.io.com_uops := rob.io.commit.uops
        rename.io.rbk_valids := rob.io.commit.rbk_valids
        rename.io.rollback := rob.io.commit.rollback
    }


    // Outputs
    dis_uops := rename_stage.io.ren2_uops
    dis_valids := rename_stage.io.ren2_mask
    ren_stalls := rename_stage.io.ren_stalls


    /**
     * TODO This is a bit nasty, but it's currently necessary to
     * split the INT/FP rename pipelines into separate instantiations.
     * Won't have to do this anymore with a properly decoupled FP pipeline.
     */
    for (w <- 0 until coreWidth) {
        val i_uop = rename_stage.io.ren2_uops(w)
        val f_uop = if (usingFPU) fp_rename_stage.io.ren2_uops(w) else NullMicroOp
        val p_uop = if (enableSFBOpt) pred_rename_stage.io.ren2_uops(w) else NullMicroOp
        val f_stall = if (usingFPU) fp_rename_stage.io.ren_stalls(w) else false.B
        val p_stall = if (enableSFBOpt) pred_rename_stage.io.ren_stalls(w) else false.B

        // lrs1 can "pass through" to prs1. Used solely to index the csr file.
        dis_uops(w).prs1 := Mux(dis_uops(w).lrs1_rtype === RT_FLT, f_uop.prs1,
            Mux(dis_uops(w).lrs1_rtype === RT_FIX, i_uop.prs1, dis_uops(w).lrs1))
        dis_uops(w).prs2 := Mux(dis_uops(w).lrs2_rtype === RT_FLT, f_uop.prs2, i_uop.prs2)
        dis_uops(w).prs3 := f_uop.prs3
        dis_uops(w).ppred := p_uop.ppred
        dis_uops(w).pdst := Mux(dis_uops(w).dst_rtype === RT_FLT, f_uop.pdst,
            Mux(dis_uops(w).dst_rtype === RT_FIX, i_uop.pdst,
                p_uop.pdst))
        dis_uops(w).stale_pdst := Mux(dis_uops(w).dst_rtype === RT_FLT, f_uop.stale_pdst, i_uop.stale_pdst)

        dis_uops(w).prs1_busy := i_uop.prs1_busy && (dis_uops(w).lrs1_rtype === RT_FIX) ||
                f_uop.prs1_busy && (dis_uops(w).lrs1_rtype === RT_FLT)
        dis_uops(w).prs2_busy := i_uop.prs2_busy && (dis_uops(w).lrs2_rtype === RT_FIX) ||
                f_uop.prs2_busy && (dis_uops(w).lrs2_rtype === RT_FLT)
        dis_uops(w).prs3_busy := f_uop.prs3_busy && dis_uops(w).frs3_en
        dis_uops(w).ppred_busy := p_uop.ppred_busy && dis_uops(w).is_sfb_shadow

        ren_stalls(w) := rename_stage.io.ren_stalls(w) || f_stall || p_stall
    }

    //-------------------------------------------------------------
    //-------------------------------------------------------------
    // **** Dispatch Stage ****
    //-------------------------------------------------------------
    //-------------------------------------------------------------

    //-------------------------------------------------------------
    // Rename2/Dispatch pipeline logic

    val dis_prior_slot_valid = dis_valids.scanLeft(false.B)((s, v) => s || v)
    val dis_prior_slot_unique = (dis_uops zip dis_valids).scanLeft(false.B) { case (s, (u, v)) => s || v && u.is_unique }
    val wait_for_empty_pipeline = (0 until coreWidth).map(w => (dis_uops(w).is_unique) &&
            (!rob.io.empty || !lsu.io.core.fencei_rdy || dis_prior_slot_valid(w)))

    val dis_hazards = (0 until coreWidth).map(w =>
        dis_valids(w) &&
                (!rob.io.ready
                        || ren_stalls(w)
                        || lsu.io.core.ldq_full(w) && dis_uops(w).use_ldq
                        || lsu.io.core.stq_full(w) && dis_uops(w).use_stq
                        || !dispatcher.io.ren_uops(w).ready
                        || wait_for_empty_pipeline(w)
                        || dis_prior_slot_unique(w)
                        || brupdate.b1.mispredictMask =/= 0.U
                        || brupdate.b2.mispredict
                        || ifu.io.exe.redirect_flush))


    lsu.io.core.fence_dmem := (dis_valids zip wait_for_empty_pipeline).map { case (v, w) => v && w }.reduce(_ || _)

    val dis_stalls = dis_hazards.scanLeft(false.B)((s, h) => s || h).takeRight(coreWidth)
    dis_fire := dis_valids zip dis_stalls map { case (v, s) => v && !s }
    dis_ready := !dis_stalls.last

    //-------------------------------------------------------------
    // LDQ/STQ Allocation Logic

    for (w <- 0 until coreWidth) {
        // Dispatching instructions request load/store queue entries when they can proceed.
        dis_uops(w).ldqIdx := lsu.io.core.dis_ldq_idx(w)
        dis_uops(w).stqIdx := lsu.io.core.dis_stq_idx(w)
    }

    //-------------------------------------------------------------
    // Rob Allocation Logic

    rob.io.enq_valids := dis_fire
    rob.io.enq_uops := dis_uops
    rob.io.enq_partial_stall := dis_stalls.last // TODO come up with better ROB compacting scheme.
    rob.io.csr_stall := csr.io.csr_stall

    // Minor hack: ecall and breaks need to increment the FTQ deq ptr earlier than commit, since
    // they write their PC into the CSR the cycle before they commit.
    // Since these are also unique, increment the FTQ ptr when they are dispatched
    when(RegNext(dis_fire.reduce(_ || _) && dis_uops(PriorityEncoder(dis_fire)).is_sys_pc2epc)) {
        ifu.io.exe.commit.valid := true.B
        ifu.io.exe.commit.bits := RegNext(dis_uops(PriorityEncoder(dis_valids)).ftqIdx)
    }

    for (w <- 0 until coreWidth) {
        // note: this assumes uops haven't been shifted - there's a 1:1 match between PC's LSBs and "w" here
        // (thus the LSB of the rob_idx gives part of the PC)
        if (coreWidth == 1) {
            dis_uops(w).robIdx := rob.io.rob_tail_idx
        } else {
            dis_uops(w).robIdx := Cat(rob.io.rob_tail_idx >> log2Ceil(coreWidth).U,
                w.U(log2Ceil(coreWidth).W))
        }
    }



    //-------------------------------------------------------------
    // Dispatch to issue queues

    // Get uops from rename2
    for (w <- 0 until coreWidth) {
        dispatcher.io.ren_uops(w).valid := dis_fire(w)
        dispatcher.io.ren_uops(w).bits := dis_uops(w)
    }

    var iu_idx = 0
    // Send dispatched uops to correct issue queues
    // Backpressure through dispatcher if necessary
    for (i <- 0 until issueParams.size) {
        issue_units(iu_idx).io.disUops <> dispatcher.io.dis_uops(i)
        iu_idx += 1
    }


    //-------------------------------------------------------------
    //-------------------------------------------------------------
    // **** Issue Stage ****
    //-------------------------------------------------------------
    //-------------------------------------------------------------

    require(issue_units.map(_.issueWidth).sum == exe_units.length)

    var iss_wu_idx = 1
    var ren_wu_idx = 1
    // The 0th wakeup port goes to the ll_wbarb
    int_iss_wakeups(0).valid := ll_wbarb.io.out.fire && ll_wbarb.io.out.bits.uop.dst_rtype === RT_FIX
    int_iss_wakeups(0).bits := ll_wbarb.io.out.bits

    int_ren_wakeups(0).valid := ll_wbarb.io.out.fire && ll_wbarb.io.out.bits.uop.dst_rtype === RT_FIX
    int_ren_wakeups(0).bits := ll_wbarb.io.out.bits

    for (i <- 1 until memWidth) {
        int_iss_wakeups(i).valid := mem_resps(i).valid && mem_resps(i).bits.uop.dst_rtype === RT_FIX
        int_iss_wakeups(i).bits := mem_resps(i).bits

        int_ren_wakeups(i).valid := mem_resps(i).valid && mem_resps(i).bits.uop.dst_rtype === RT_FIX
        int_ren_wakeups(i).bits := mem_resps(i).bits
        iss_wu_idx += 1
        ren_wu_idx += 1
    }

    // loop through each issue-port (exe_units are statically connected to an issue-port)
    for (i <- 0 until exe_units.length) {
        if (exe_units(i).writesIrf) {
            val fast_wakeup = Wire(Valid(new ExeUnitResp(xLen)))
            val slow_wakeup = Wire(Valid(new ExeUnitResp(xLen)))
            fast_wakeup := DontCare
            slow_wakeup := DontCare

            val resp = exe_units(i).io.iresp
            assert(!(resp.valid && resp.bits.uop.rf_wen && resp.bits.uop.dst_rtype =/= RT_FIX))

            // Fast Wakeup (uses just-issued uops that have known latencies)
            fast_wakeup.bits.uop := iss_uops(i)
            fast_wakeup.valid := iss_valids(i) &&
                    iss_uops(i).bypassable &&
                    iss_uops(i).dst_rtype === RT_FIX &&
                    iss_uops(i).ldst_val &&
                    !(lsu.io.core.ld_miss && (iss_uops(i).iw_p1_poisoned || iss_uops(i).iw_p2_poisoned))

            // Slow Wakeup (uses write-port to register file)
            slow_wakeup.bits.uop := resp.bits.uop
            slow_wakeup.valid := resp.valid &&
                    resp.bits.uop.rf_wen &&
                    !resp.bits.uop.bypassable &&
                    resp.bits.uop.dst_rtype === RT_FIX

            if (exe_units(i).bypassable) {
                int_iss_wakeups(iss_wu_idx) := fast_wakeup
                iss_wu_idx += 1
            }
            if (!exe_units(i).alwaysBypassable) {
                int_iss_wakeups(iss_wu_idx) := slow_wakeup
                iss_wu_idx += 1
            }

            if (exe_units(i).bypassable) {
                int_ren_wakeups(ren_wu_idx) := fast_wakeup
                ren_wu_idx += 1
            }
            if (!exe_units(i).alwaysBypassable) {
                int_ren_wakeups(ren_wu_idx) := slow_wakeup
                ren_wu_idx += 1
            }
        }
    }
    require(iss_wu_idx == numIntIssueWakeupPorts)
    require(ren_wu_idx == numIntRenameWakeupPorts)
    require(iss_wu_idx == ren_wu_idx)

    // jmp unit performs fast wakeup of the predicate bits
    require(jmp_unit.bypassable)
    pred_wakeup.valid := (iss_valids(jmp_unit_idx) &&
            iss_uops(jmp_unit_idx).is_sfb_br &&
            !(lsu.io.core.ld_miss && (iss_uops(jmp_unit_idx).iw_p1_poisoned || iss_uops(jmp_unit_idx).iw_p2_poisoned))
            )
    pred_wakeup.bits.uop := iss_uops(jmp_unit_idx)
    pred_wakeup.bits.data := DontCare
    pred_wakeup.bits.predicated := DontCare

    // Perform load-hit speculative wakeup through a special port (performs a poison wake-up).
    issue_units map { iu =>
        iu.io.specLdWakeupPorts := lsu.io.core.spec_ld_wakeup
    }


    // Connect the predicate wakeup port
    issue_units map { iu =>
        iu.io.predWakeupPorts.valid := false.B
        iu.io.predWakeupPorts.bits := DontCare
    }
    if (enableSFBOpt) {
        int_iss_unit.io.predWakeupPorts.valid := pred_wakeup.valid
        int_iss_unit.io.predWakeupPorts.bits := pred_wakeup.bits.uop.pdst
    }


    // ----------------------------------------------------------------
    // Connect the wakeup ports to the busy tables in the rename stages

    for ((renport, intport) <- rename_stage.io.wakeups zip int_ren_wakeups) {
        renport <> intport
    }

    if (enableSFBOpt) {
        pred_rename_stage.io.wakeups(0) := pred_wakeup
    } else {
        pred_rename_stage.io.wakeups := DontCare
    }

    // If we issue loads back-to-back endlessly (probably because we are executing some tight loop)
    // the store buffer will never drain, breaking the memory-model forward-progress guarantee
    // If we see a large number of loads saturate the LSU, pause for a cycle to let a store drain
    val loads_saturating = (mem_iss_unit.io.issueValids(0) && mem_iss_unit.io.issueUops(0).use_ldq)
    val saturating_loads_counter = RegInit(0.U(5.W))
    when(loads_saturating) {
        saturating_loads_counter := saturating_loads_counter + 1.U
    }
            .otherwise {
                saturating_loads_counter := 0.U
            }
    val pause_mem = RegNext(loads_saturating) && saturating_loads_counter === ~(0.U(5.W))

    var iss_idx = 0
    var int_iss_cnt = 0
    var mem_iss_cnt = 0
    for (w <- 0 until exe_units.length) {
        var fu_types = exe_units(w).io.fu_types
        val exe_unit = exe_units(w)
        if (exe_unit.readsIrf) {
            if (exe_unit.supportedFuncUnits.muldiv) {
                // Supress just-issued divides from issuing back-to-back, since it's an iterative divider.
                // But it takes a cycle to get to the Exe stage, so it can't tell us it is busy yet.
                val idiv_issued = iss_valids(iss_idx) && iss_uops(iss_idx).fu_code_is(FU_DIV)
                fu_types = fu_types & RegNext(~Mux(idiv_issued, FU_DIV, 0.U))
            }

            if (exe_unit.hasMem) {
                iss_valids(iss_idx) := mem_iss_unit.io.issueValids(mem_iss_cnt)
                iss_uops(iss_idx) := mem_iss_unit.io.issueUops(mem_iss_cnt)
                mem_iss_unit.io.fuTypes(mem_iss_cnt) := Mux(pause_mem, 0.U, fu_types)
                mem_iss_cnt += 1
            } else {
                iss_valids(iss_idx) := int_iss_unit.io.issueValids(int_iss_cnt)
                iss_uops(iss_idx) := int_iss_unit.io.issueUops(int_iss_cnt)
                int_iss_unit.io.fuTypes(int_iss_cnt) := fu_types
                int_iss_cnt += 1
            }
            iss_idx += 1
        }
    }
    require(iss_idx == exe_units.numIrfReaders)

    issue_units.map(_.io.brUpdate := brupdate)
    issue_units.map(_.io.flushPipeline := RegNext(rob.io.flush.valid))

    // Load-hit Misspeculations
    require(mem_iss_unit.issueWidth <= 2)
    issue_units.map(_.io.ldMiss := lsu.io.core.ld_miss)

    //mem_units.map(u => u.io.com_exception := RegNext(rob.io.flush.valid))

    // Wakeup (Issue & Writeback)
    for {
        iu <- issue_units
        (issport, wakeup) <- iu.io.wakeupPorts zip int_iss_wakeups
    } {
        issport.valid := wakeup.valid
        issport.bits.pdst := wakeup.bits.uop.pdst
        issport.bits.poisoned := wakeup.bits.uop.iw_p1_poisoned || wakeup.bits.uop.iw_p2_poisoned

        require(iu.io.wakeupPorts.length == int_iss_wakeups.length)
    }

    //-------------------------------------------------------------
    //-------------------------------------------------------------
    // **** Register Read Stage ****
    //-------------------------------------------------------------
    //-------------------------------------------------------------

    // Register Read <- Issue (rrd <- iss)
    iregister_read.io.rf_read_ports <> iregfile.io.read_ports
    iregister_read.io.prf_read_ports := DontCare
    if (enableSFBOpt) {
        iregister_read.io.prf_read_ports <> pregfile.io.read_ports
    }

    for (w <- 0 until exe_units.numIrfReaders) {
        iregister_read.io.iss_valids(w) :=
                iss_valids(w) && !(lsu.io.core.ld_miss && (iss_uops(w).iw_p1_poisoned || iss_uops(w).iw_p2_poisoned))
    }
    iregister_read.io.iss_uops := iss_uops
    iregister_read.io.iss_uops map { u => u.iw_p1_poisoned := false.B; u.iw_p2_poisoned := false.B }

    iregister_read.io.brupdate := brupdate
    iregister_read.io.kill := RegNext(rob.io.flush.valid)

    iregister_read.io.bypass := bypasses
    iregister_read.io.pred_bypass := pred_bypasses

    //-------------------------------------------------------------
    // Privileged Co-processor 0 Register File
    // Note: Normally this would be bad in that I'm writing state before
    // committing, so to get this to work I stall the entire pipeline for
    // CSR instructions so I never speculate these instructions.

    val csr_exe_unit = exe_units.csr_unit

    // for critical path reasons, we aren't zero'ing this out if resp is not valid
    val csr_rw_cmd = csr_exe_unit.io.iresp.bits.uop.ctrl.csr_cmd
    val wb_wdata = csr_exe_unit.io.iresp.bits.data

    csr.io.rw.addr := csr_exe_unit.io.iresp.bits.uop.csr_addr
    csr.io.rw.cmd := freechips.rocketchip.rocket.CSR.maskCmd(csr_exe_unit.io.iresp.valid, csr_rw_cmd)
    csr.io.rw.wdata := wb_wdata

    // Extra I/O
    // Delay retire/exception 1 cycle
    csr.io.retire := RegNext(PopCount(rob.io.commit.arch_valids.asUInt))
    csr.io.exception := RegNext(rob.io.com_xcpt.valid)
    // csr.io.pc used for setting EPC during exception or CSR.io.trace.

    csr.io.pc := (AlignPCToBoundary(ifu.io.exe.getFtqPc(0).compc, icBlockBytes)
            + RegNext(rob.io.com_xcpt.bits.pc_lob))
    // Cause not valid for for CALL or BREAKPOINTs (CSRFile will override it).
    csr.io.cause := RegNext(rob.io.com_xcpt.bits.cause)
    csr.io.ungated_clock := clock

    val tval_valid = csr.io.exception &&
            csr.io.cause.isOneOf(
                //Causes.illegal_instruction.U, we currently only write 0x0 for illegal instructions
                Causes.breakpoint.U,
                Causes.misaligned_load.U,
                Causes.misaligned_store.U,
                Causes.load_access.U,
                Causes.store_access.U,
                Causes.fetch_access.U,
                Causes.load_page_fault.U,
                Causes.store_page_fault.U,
                Causes.fetch_page_fault.U)

    csr.io.tval := Mux(tval_valid,
        RegNext(encodeVirtualAddress(rob.io.com_xcpt.bits.badvaddr, rob.io.com_xcpt.bits.badvaddr)), 0.U)

    // TODO move this function to some central location (since this is used elsewhere).
    def encodeVirtualAddress(a0: UInt, ea: UInt) =
            ea


    csr.io.interrupts := io.interrupts

    // we do not support the H-extension
    csr.io.htval := DontCare
    csr.io.gva := DontCare

    // TODO can we add this back in, but handle reset properly and save us
    //      the mux above on csr.io.rw.cmd?
    //   assert (!(csr_rw_cmd =/= rocket.CSR.N && !exe_units(0).io.resp(0).valid),
    //   "CSRFile is being written to spuriously.")

    //-------------------------------------------------------------
    //-------------------------------------------------------------
    // **** Execute Stage ****
    //-------------------------------------------------------------
    //-------------------------------------------------------------

    iss_idx = 0
    var bypass_idx = 0
    for (w <- 0 until exe_units.length) {
        val exe_unit = exe_units(w)
        if (exe_unit.readsIrf) {
            exe_unit.io.req <> iregister_read.io.exe_reqs(iss_idx)

            if (exe_unit.bypassable) {
                for (i <- 0 until exe_unit.numStages) {
                    bypasses(bypass_idx) := exe_unit.io.bypass(i)
                    bypass_idx += 1
                }
            }
            iss_idx += 1
        }
    }
    require(bypass_idx == exe_units.numTotalBypassPorts)
    for (i <- 0 until jmp_unit.numStages) {
        pred_bypasses(i) := jmp_unit.io.bypass(i)
    }

    //-------------------------------------------------------------
    //-------------------------------------------------------------
    // **** Load/Store Unit ****
    //-------------------------------------------------------------
    //-------------------------------------------------------------

    // enqueue basic load/store info in Decode
    for (w <- 0 until coreWidth) {
        lsu.io.core.dis_uops(w).valid := dis_fire(w)
        lsu.io.core.dis_uops(w).bits := dis_uops(w)
    }

    // tell LSU about committing loads and stores to clear entries
    lsu.io.core.commit := rob.io.commit

    // tell LSU that it should fire a load that waits for the rob to clear
    lsu.io.core.commit_load_at_rob_head := rob.io.com_load_is_at_rob_head

    //com_xcpt.valid comes too early, will fight against a branch that resolves same cycle as an exception
    lsu.io.core.exception := RegNext(rob.io.flush.valid)

    // Handle Branch Mispeculations
    lsu.io.core.brupdate := brupdate
    lsu.io.core.rob_head_idx := rob.io.rob_head_idx


    //-------------------------------------------------------------
    //-------------------------------------------------------------
    // **** Writeback Stage ****
    //-------------------------------------------------------------
    //-------------------------------------------------------------

    val ipregSz = pregSz
    var w_cnt = 1
    iregfile.io.write_ports(0) := WritePort(ll_wbarb.io.out, ipregSz, xLen, RT_FIX)
    ll_wbarb.io.in(0) <> mem_resps(0)
    assert(ll_wbarb.io.in(0).ready) // never backpressure the memory unit.
    for (i <- 1 until memWidth) {
        iregfile.io.write_ports(w_cnt) := WritePort(mem_resps(i), ipregSz, xLen, RT_FIX)
        w_cnt += 1
    }

    for (i <- 0 until exe_units.length) {
        if (exe_units(i).writesIrf) {
            val wbresp = exe_units(i).io.iresp
            val wbpdst = wbresp.bits.uop.pdst
            val wbdata = wbresp.bits.data

            def wbIsValid(rtype: UInt) =
                wbresp.valid && wbresp.bits.uop.rf_wen && wbresp.bits.uop.dst_rtype === rtype

            val wbReadsCSR = wbresp.bits.uop.ctrl.csr_cmd =/= freechips.rocketchip.rocket.CSR.N

            iregfile.io.write_ports(w_cnt).valid := wbIsValid(RT_FIX)
            iregfile.io.write_ports(w_cnt).bits.addr := wbpdst
            wbresp.ready := true.B
            if (exe_units(i).hasCSR) {
                iregfile.io.write_ports(w_cnt).bits.data := Mux(wbReadsCSR, csr.io.rw.rdata, wbdata)
            } else {
                iregfile.io.write_ports(w_cnt).bits.data := wbdata
            }

            assert(!wbIsValid(RT_FLT), "[fppipeline] An FP writeback is being attempted to the Int Regfile.")

            assert(!(wbresp.valid &&
                    !wbresp.bits.uop.rf_wen &&
                    wbresp.bits.uop.dst_rtype === RT_FIX),
                "[fppipeline] An Int writeback is being attempted with rf_wen disabled.")

            assert(!(wbresp.valid &&
                    wbresp.bits.uop.rf_wen &&
                    wbresp.bits.uop.dst_rtype =/= RT_FIX),
                "[fppipeline] writeback being attempted to Int RF with dst != Int type exe_units(" + i + ").iresp")
            w_cnt += 1
        }
    }
    require(w_cnt == iregfile.io.write_ports.length)

    if (enableSFBOpt) {
        pregfile.io.write_ports(0).valid := jmp_unit.io.iresp.valid && jmp_unit.io.iresp.bits.uop.is_sfb_br
        pregfile.io.write_ports(0).bits.addr := jmp_unit.io.iresp.bits.uop.pdst
        pregfile.io.write_ports(0).bits.data := jmp_unit.io.iresp.bits.data
    }


    //-------------------------------------------------------------
    //-------------------------------------------------------------
    // **** Commit Stage ****
    //-------------------------------------------------------------
    //-------------------------------------------------------------

    // Writeback
    // ---------
    // First connect the ll_wport
    val ll_uop = ll_wbarb.io.out.bits.uop
    rob.io.wb_resps(0).valid := ll_wbarb.io.out.valid && !(ll_uop.uses_stq && !ll_uop.is_amo)
    rob.io.wb_resps(0).bits <> ll_wbarb.io.out.bits
    rob.io.debug_wb_valids(0) := ll_wbarb.io.out.valid && ll_uop.dst_rtype =/= RT_X
    rob.io.debug_wb_wdata(0)  := ll_wbarb.io.out.bits.data
    rob.io.debug_wb_ldst(0)   := ll_wbarb.io.out.bits.uop.ldst
    var cnt = 1
    for (i <- 1 until memWidth) {
        val mem_uop = mem_resps(i).bits.uop
        rob.io.wb_resps(cnt).valid := mem_resps(i).valid && !(mem_uop.use_stq && !mem_uop.is_amo)
        rob.io.wb_resps(cnt).bits := mem_resps(i).bits
        rob.io.debug_wb_valids(cnt) := mem_resps(i).valid && mem_uop.dst_rtype =/= RT_X
        rob.io.debug_wb_wdata(cnt) := mem_resps(i).bits.data
        rob.io.debug_wb_ldst(cnt)   := mem_uop.ldst
        cnt += 1
    }
    var f_cnt = 0 // rob fflags port index
    for (eu <- exe_units) {
        if (eu.writesIrf) {
            val resp = eu.io.iresp
            val wb_uop = resp.bits.uop
            val data = resp.bits.data

            rob.io.wb_resps(cnt).valid := resp.valid && !(wb_uop.use_stq && !wb_uop.is_amo)
            rob.io.wb_resps(cnt).bits <> resp.bits
            rob.io.debug_wb_valids(cnt) := resp.valid && wb_uop.rf_wen && wb_uop.dst_rtype === RT_FIX
            if (eu.hasCSR) {
                rob.io.debug_wb_wdata(cnt) := Mux(wb_uop.ctrl.csr_cmd =/= freechips.rocketchip.rocket.CSR.N,
                    csr.io.rw.rdata,
                    data)
            } else {
                rob.io.debug_wb_wdata(cnt) := data
                rob.io.debug_wb_ldst(cnt)  := wb_uop.ldst
            }
            cnt += 1
        }
    }

    require(cnt == numIrfWritePorts)
    require(cnt == rob.numWakeupPorts)

    // branch resolution
    rob.io.brupdate <> brupdate

/*    exe_units.map(u => u.io.status := csr.io.status)

    // Connect breakpoint info to memaddrcalcunit
    for (i <- 0 until memWidth) {
        mem_units(i).io.status := csr.io.status
        mem_units(i).io.bp := csr.io.bp
        mem_units(i).io.mcontext := csr.io.mcontext
        mem_units(i).io.scontext := csr.io.scontext
    }*/

    // LSU <> ROB
    rob.io.lsu_clr_bsy := lsu.io.core.clr_bsy
    rob.io.lxcpt <> lsu.io.core.lxcpt



    //-------------------------------------------------------------
    // **** Flush Pipeline ****
    //-------------------------------------------------------------
    // flush on exceptions, miniexeptions, and after some special instructions


    for (w <- 0 until exe_units.length) {
        exe_units(w).io.req.bits.kill := RegNext(rob.io.flush.valid)
    }

    assert(!(rob.io.com_xcpt.valid && !rob.io.flush.valid),
        "[core] exception occurred, but pipeline flush signal not set!")

    //-------------------------------------------------------------
    //-------------------------------------------------------------
    // Page Table Walker

    //    io.ptw.ptbr       := csr.io.ptbr
    //    io.ptw.status     := csr.io.status
    //    io.ptw.pmp        := csr.io.pmp
    //    io.ptw.sfence     := ifu.io.exe.sfence

    //-------------------------------------------------------------
    // *** debug for difftest
    //-------------------------------------------------------------
    val diff = new debugDiff
    val lregOut = Vec(lregSz,UInt(xLen.W))
    diff.io.commit := rob.io.commit
    lregOut := diff.io.lregOut   //use this for difftest
}

