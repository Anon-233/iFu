package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.util._
import iFu.common.Consts._
import iFu.common.CauseCode._


class RobIO(val numWritePorts: Int) extends CoreBundle {
    val enq_valids        = Input(Vec(coreWidth, Bool()))
    val enq_uops          = Input(Vec(coreWidth, new MicroOp))
    val enq_partial_stall = Input(Bool())

    val xcpt_fetch_pc = Input(UInt(vaddrBits.W))

    val rob_tail_idx = Output(UInt(robParameters.robAddrSz.W))
    val rob_head_idx = Output(UInt(robParameters.robAddrSz.W))

    val brupdate = Input(new BrUpdateInfo)

    val wb_resps = Flipped(Vec(numWritePorts, Valid(new ExeUnitResp)))

    // store stage
    val lsu_clr_bsy = Input(Vec(memWidth, Valid(UInt(robParameters.robAddrSz.W))))
    val lxcpt       = Flipped(new ValidIO(new Exception))

    // commit stage
    val commit = Output(new CommitSignals)

    // load指令位于ROB头指针处
    val com_load_is_at_rob_head = Output(Bool())

    // excetion to CSR
    val com_xcpt = Valid(new CommitExceptionSignals)

    // val csr_stall = Input(Bool())

    // flush signals
    // 可能因为异常，流水线延迟或者访存阶段错误等,发送给frondend
    val flush = Valid(new CommitExceptionSignals)

    val empty = Output(Bool())
    val ready = Output(Bool())

    val flush_frontend = Output(Bool())


    //---------------------debug
    val debug_wb_valids = Input(Vec(numWritePorts, Bool()))
    val debug_wb_wdata  = Input(Vec(numWritePorts, Bits(xLen.W)))
    val debug_wb_ldst   = Input(Vec(numWritePorts, UInt(lregSz.W)))
    val debug_wb_pc     = Input(Vec(numWritePorts, UInt(32.W)))
}

class Rob(val numWritePorts: Int) extends CoreModule {
    val io = IO(new RobIO(numWritePorts))

    // -------------------------------
    val numRobRows = robParameters.numRobRows
    val numRobEntries = robParameters.numRobEntries
    // -------------------------------

    // state
    val stateReset :: stateNormal ::stateRollback ::stateWatiTillEmpty :: Nil = Enum(4)
    val robState = RegInit(stateReset)

    // rob pointers
    val robHead    = RegInit(0.U(log2Ceil(numRobRows).W))
    val robHeadLsb = RegInit(0.U(log2Ceil(coreWidth).W))
    val robHeadIdx = Cat(robHead, robHeadLsb)

    val robTail    = RegInit(0.U(log2Ceil(numRobRows).W))
    val robTailLsb = RegInit(0.U(log2Ceil(coreWidth).W))
    val robTailIdx = Cat(robTail, robTailLsb)

    // 有什么用
    val comIdx = Mux(robState === stateRollback, robTail, robHead)

    val willCommit        = Wire(Vec(coreWidth, Bool()))
    val canCommit         = Wire(Vec(coreWidth, Bool()))
    val isXcpt2Commit     = Wire(Vec(coreWidth, Bool()))

    // 4 instr, which one is valid and exception is true
    val canThrowException = Wire(Vec(coreWidth, Bool()))

    val robHeadVals    = Wire(Vec(coreWidth, Bool()))
    val robHeadUsesLdq = Wire(Vec(coreWidth, Bool()))
    
    val exceptionThrown = Wire(Bool())

    val rXcptVal      = RegInit(false.B)
    val rXcptUop      = Reg(new MicroOp)
    val rXcptBadvaddr = Reg(UInt(paddrBits.W))

    io.flush_frontend := rXcptVal

    val maybeFull = RegInit(false.B)
    val full  = (robHead === robTail) && maybeFull
    val empty = (robHead === robTail) && (robHeadVals.asUInt === 0.U)

    //-----------------tool def---------------------
    def GetRowIdx(robIdx : UInt): UInt ={
        return (robIdx >> log2Ceil(coreWidth)).asUInt
    }
    def GetBankIdx(robIdx :UInt):UInt = {
        return robIdx(log2Ceil(coreWidth)-1, 0).asUInt
    }

    // Used for trace port, for debug purposes only
    val rob_debug_inst_mem   = SyncReadMem(numRobRows, Vec(coreWidth, UInt(32.W)))
    val rob_debug_inst_wmask = WireInit(VecInit(0.U(coreWidth.W).asBools))
    val rob_debug_inst_wdata = Wire(Vec(coreWidth, UInt(32.W)))
    rob_debug_inst_mem.write(robTail, rob_debug_inst_wdata, rob_debug_inst_wmask)
    val rob_debug_inst_rdata = rob_debug_inst_mem.read(robHead, willCommit.reduce(_||_))

    //---------------------------------------------

    for (w <- 0 until coreWidth) {
        def MatchBank(bankIdx : UInt): Bool = (bankIdx === w.U)

        val robVal        = RegInit(VecInit(Seq.fill(numRobRows){ false.B }))
        val robBsy        = Reg(Vec(numRobRows, Bool()))
        val robUop        = Reg(Vec(numRobRows,new MicroOp))
        val robException  = Reg(Vec(numRobRows, Bool()))
        val robPredicated = Reg(Vec(numRobRows, Bool()))

        val rob_debug_wdata = Mem(numRobRows, UInt(xLen.W))
        val rob_debug_ldst  = Mem(numRobRows,UInt(lregSz.W))
        val rob_debug_pc    = Mem(numRobRows,UInt(32.W))

        //------------------dispatch stage------------------
        //enqueue

        rob_debug_inst_wmask(w) := io.enq_valids(w)
        rob_debug_inst_wdata(w) := io.enq_uops(w).debug_inst

        when (io.enq_valids(w)) {
            robVal(robTail)        := true.B
            robBsy(robTail)        := !(io.enq_uops(w).is_fence ||
                                        io.enq_uops(w).is_fencei ||
                                        io.enq_uops(w).is_nop ||
                                        io.enq_uops(w).excCause === SYS ||
                                        io.enq_uops(w).excCause === BRK)
            robException(robTail)  := io.enq_uops(w).exception
            robUop(robTail)        := io.enq_uops(w)
            robPredicated(robTail) := false.B
        } .elsewhen (io.enq_valids.reduce(_|_) && !robVal(robTail)) {
            robUop(robTail).debug_inst := BUBBLE
        }

        //------------------writeback-----------------------

        for(i <- 0 until numWritePorts){
            val wbResp = io.wb_resps(i)
            val wbUop  = wbResp.bits.uop
            val rowIdx = GetRowIdx(wbUop.robIdx)
            when (wbResp.valid && MatchBank(GetBankIdx(wbUop.robIdx))) {
                robBsy(rowIdx)        := false.B
                robPredicated(rowIdx) := wbResp.bits.predicated
            }
        }

        //-----------------lsu------------------------

        for(clr_rob_idx <- io.lsu_clr_bsy){
            when (clr_rob_idx.valid && MatchBank(GetBankIdx(clr_rob_idx.bits))) {
                robBsy(GetRowIdx(clr_rob_idx.bits)) := false.B
            }
        }

        //----------------exception-----------------

        when (io.lxcpt.valid && MatchBank(GetBankIdx(io.lxcpt.bits.uop.robIdx))) {
            robException(GetRowIdx(io.lxcpt.bits.uop.robIdx)) := true.B
        }
        
        canThrowException(w) := robVal(robHead) && robException(robHead)

        //---------------output:commit------------
        canCommit(w) := robVal(robHead) && !(robBsy(robHead)) /* && !io.csr_stall */
        isXcpt2Commit(w) := (robUop(robHead).excCause === SYS) || (robUop(robHead).excCause === BRK)

        io.commit.valids(w)      := willCommit(w)
        io.commit.arch_valids(w) := willCommit(w) && !robPredicated(comIdx)
        io.commit.uops(w)        := robUop(comIdx)
        io.commit.debug_insts(w) := rob_debug_inst_rdata(w)

        // 感觉没什么用
        when (
            io.brupdate.b2.mispredict &&
            MatchBank(GetBankIdx(io.brupdate.b2.uop.robIdx)) &&
            GetRowIdx(io.brupdate.b2.uop.robIdx) === comIdx
        ) {
            io.commit.uops(w).taken := io.brupdate.b2.taken
        }

        val rbkRow = robState === stateRollback && !full

        io.commit.rbk_valids(w) := rbkRow && robVal(comIdx)
        io.commit.rollback      := (robState === stateRollback)

        when (rbkRow) {
            robVal(comIdx)       := false.B
            robException(comIdx) := false.B
        }

        for (i <- 0 until numRobRows) {
            var brMask = robUop(i).brMask
            when (IsKilledByBranch(io.brupdate,brMask)) {
                robVal(i)            := false.B
                robUop(i).debug_inst := BUBBLE
            } .elsewhen (robVal(i)) {
                robUop(i).brMask := GetNewBrMask(io.brupdate,brMask)
            }
        }

        // 感觉这个也没什么地方用
        when (
            io.brupdate.b2.mispredict &&
            MatchBank(GetBankIdx(io.brupdate.b2.uop.robIdx))
        ) {
            robUop(GetRowIdx(io.brupdate.b2.uop.robIdx)).taken := io.brupdate.b2.taken
        }

        //------------------commit--------------------------
        when (willCommit(w)) {
            robVal(robHead) := false.B
        }

        //--------------------output-----------------------
        robHeadVals(w)    := robVal(robHead)
        robHeadUsesLdq(w) := robUop(robHead).use_ldq

        when (willCommit(w)) {
            robUop(robHead).debug_inst := BUBBLE
        } .elsewhen (rbkRow) {
            robUop(robTail).debug_inst := BUBBLE
        }

        // 给 debug 用的
        for (i <- 0 until numWritePorts) {
            val rob_idx = io.wb_resps(i).bits.uop.robIdx
            when (io.debug_wb_valids(i) && MatchBank(GetBankIdx(rob_idx))) {
                rob_debug_wdata(GetRowIdx(rob_idx)) := io.debug_wb_wdata(i)
                rob_debug_ldst(GetRowIdx(rob_idx))  := io.debug_wb_ldst(i)
                rob_debug_pc(GetRowIdx(rob_idx))    := io.debug_wb_pc(i)
            }
            val temp_uop = robUop(GetRowIdx(rob_idx))

            assert (!(io.wb_resps(i).valid && MatchBank(GetBankIdx(rob_idx)) &&
                    !robVal(GetRowIdx(rob_idx))),
                    "[rob] writeback (" + i + ") occurred to an invalid ROB entry.")
            assert (!(io.wb_resps(i).valid && MatchBank(GetBankIdx(rob_idx)) &&
                    !robBsy(GetRowIdx(rob_idx))),
                    "[rob] writeback (" + i + ") occurred to a not-busy ROB entry.")
            assert (!(io.wb_resps(i).valid && MatchBank(GetBankIdx(rob_idx)) &&
                    temp_uop.ldst_val && temp_uop.pdst =/= io.wb_resps(i).bits.uop.pdst),
                    "[rob] writeback (" + i + ") occurred to the wrong pdst.")
        }
        io.commit.debug_wdata(w) := rob_debug_wdata(robHead)
        io.commit.debug_ldst(w)  := rob_debug_ldst(robHead)
        io.commit.debug_pc(w)    := rob_debug_pc(robHead)
    }

    var blockCommit = (robState =/= stateNormal) && (robState =/= stateWatiTillEmpty) || RegNext(exceptionThrown) || RegNext(RegNext(exceptionThrown))
    var willThrowException = false.B
    var blockXcpt = false.B

    for (w <- 0 until coreWidth) {
        willThrowException = (canThrowException(w) && !blockCommit && !blockXcpt) || willThrowException
        willCommit(w) := canCommit(w) && (!canThrowException(w) || isXcpt2Commit(w)) && !blockCommit
        blockCommit = (robHeadVals(w) && (!canCommit(w) || canThrowException(w))) ||blockCommit
        blockXcpt = willCommit(w)
    }

    exceptionThrown := willThrowException
    val isMiniException = io.com_xcpt.bits.cause === MINI_EXCEPTION_MEM_ORDERING
    io.com_xcpt.valid := exceptionThrown && !isMiniException
    io.com_xcpt.bits.cause := rXcptUop.excCause
    io.com_xcpt.bits.vaddrWriteEnable := rXcptUop.vaddrWriteEnable
    io.com_xcpt.bits.uop := rXcptUop

    io.com_xcpt.bits.badvaddr := Sext(rXcptBadvaddr, xLen)
    val insnSysPc2epc = robHeadVals.reduce(_||_) && PriorityMux(robHeadVals,io.commit.uops.map{u => u.is_sys_pc2epc})
    
    val refetchInst = exceptionThrown || insnSysPc2epc
    val comXcptUop = PriorityMux(robHeadVals,io.commit.uops)
    io.com_xcpt.bits.ftq_idx := comXcptUop.ftqIdx
    //io.com_xcpt.bits.edge_inst := comXcptUop.edge_inst
    //io.com_xcpt.bits.is_rvc := comXcptUop.is_rvc
    io.com_xcpt.bits.pc_lob := comXcptUop.pcLowBits
    io.com_xcpt.bits.flush_typ := DontCare

    //------------------flush-------------------

    val flushCommitMask = Range(0,coreWidth).map{i => io.commit.valids(i) && io.commit.uops(i).flush_on_commit}
    val flushCommit = flushCommitMask.reduce(_|_)
    val flushVal = exceptionThrown || flushCommit

    val flushUop = Mux(exceptionThrown,comXcptUop,Mux1H(flushCommitMask,io.commit.uops))

    //优化时序，延迟一个周期
    io.flush.valid := flushVal
    io.flush.bits.uop := DontCare
    io.flush.bits.ftq_idx := flushUop.ftqIdx
    io.flush.bits.pc_lob := flushUop.pcLowBits
    //io.flush.bits.edge_inst := flushUop.edge_inst
    //io.flush.bits.is_rvc := flushUop.is_rvc
    io.flush.bits.flush_typ := FlushTypes.getType(flushVal,
                                                exceptionThrown && !isMiniException,
                                                flushCommit && flushUop.uopc === uopERET,
                                                refetchInst)
    io.flush.bits.cause :=DontCare
    io.flush.bits.badvaddr := DontCare
    io.flush.bits.vaddrWriteEnable := flushUop.vaddrWriteEnable
    //------------------exception-------------------
    val nextXcptUop = Wire(new MicroOp())
    nextXcptUop := rXcptUop
    val enqXcpts = Wire(Vec(coreWidth,Bool()))
    for(i <- 0 until coreWidth) {
        enqXcpts(i) := io.enq_valids(i) && io.enq_uops(i).exception
    }

    when(!(io.flush.valid || exceptionThrown) && robState =/= stateRollback){
        when(io.lxcpt.valid){
            val newXcptUop = io.lxcpt.bits.uop

            when(!rXcptVal || IsOlder(newXcptUop.robIdx,rXcptUop.robIdx,robHeadIdx)){
                rXcptVal := true.B
                nextXcptUop := newXcptUop
                nextXcptUop.excCause := io.lxcpt.bits.cause
                rXcptBadvaddr := io.lxcpt.bits.badvaddr
            }
        } .elsewhen (!rXcptVal && enqXcpts.reduce(_|_)){
            val idx = enqXcpts.indexWhere{i: Bool => i}

            rXcptVal := true.B
            nextXcptUop := io.enq_uops(idx)
            rXcptBadvaddr := AlignPCToBoundary(io.xcpt_fetch_pc,frontendParams.iCacheParams.lineBytes) | io.enq_uops(idx).pcLowBits
        }
    }

    rXcptUop := nextXcptUop
    rXcptUop.brMask := GetNewBrMask(io.brupdate,nextXcptUop)
    when(io.flush.valid || IsKilledByBranch(io.brupdate,nextXcptUop)){
        rXcptVal := false.B
    }

    assert (!(exceptionThrown && !rXcptVal),
    "ROB trying to throw an exception, but it doesn't have a valid xcpt_cause")

    assert (!(empty && rXcptVal),
    "ROB is empty, but believes it has an outstanding exception.")

    assert (!(willThrowException && (GetRowIdx(rXcptUop.robIdx) =/= robHead)),
    "ROB is throwing an exception, but the stored exception information's " +
    "rob_idx does not match the rob_head")

    //--------------------Robhead-------------------

    val robDeq = WireInit(false.B)
    val rPartialRow = RegInit(false.B)


    when(io.enq_valids.reduce(_|_)){
        rPartialRow := io.enq_partial_stall
    }

    val finishedCommittingRow = (
        (io.commit.valids.asUInt =/= 0.U) &&
        ((willCommit.asUInt ^ robHeadVals.asUInt) === 0.U) &&
        !(rPartialRow && robHead === robTail && !maybeFull)
    )

    when (finishedCommittingRow) {
        robHead    := WrapInc(robHead,numRobRows)
        robHeadLsb := 0.U
        robDeq     := true.B
    } .otherwise {
        robHeadLsb := OHToUInt(PriorityEncoderOH(robHeadVals.asUInt))
    }

    //------------------------robtail-------------------

    val robEnq = WireInit(false.B)

    when (robState === stateRollback && (robTail =/= robHead || maybeFull)) {
        robTail    := WrapDec(robTail, numRobRows)
        robTailLsb := (coreWidth-1).U
        robDeq     := true.B
    } .elsewhen (robState === stateRollback && (robTail === robHead) && !maybeFull) {
        robTailLsb := robHeadLsb
    } .elsewhen (io.brupdate.b2.mispredict) {
        robTail    := WrapInc(GetRowIdx(io.brupdate.b2.uop.robIdx), numRobRows)
        robTailLsb := 0.U
    } .elsewhen (io.enq_valids.asUInt =/= 0.U && !io.enq_partial_stall) {
        robTail    := WrapInc(robTail,numRobRows)
        robTailLsb := 0.U
        robEnq     := true.B
    } .elsewhen(io.enq_valids.asUInt =/= 0.U && io.enq_partial_stall) {
        robTailLsb := PriorityEncoder(~MaskLower(io.enq_valids.asUInt))
    }

    //----------------------maybefull--------------------
    maybeFull := !robDeq &&(robEnq||maybeFull) || io.brupdate.b1.mispredictMask =/= 0.U

    io.rob_head_idx := robHeadIdx
    io.rob_tail_idx := robTailIdx
    io.empty := empty
    io.ready := (robState === stateNormal) && !full && !rXcptVal

    //---------------------state change(FSM)-------------------

    switch (robState) {
        is (stateReset) {
            robState := stateNormal
        }
        is (stateNormal) {
            when (RegNext(RegNext(exceptionThrown))) {
                robState := stateRollback
            } .otherwise {
                for (w <- 0 until coreWidth){
                    // 进入rob的指令一旦检测到is_unque就暂停rob
                    when(io.enq_valids(w) && io.enq_uops(w).is_unique){
                        robState := stateWatiTillEmpty
                    }
                }
            }
        }
        is (stateRollback) {
            when (empty) {
                robState := stateNormal
            }
        }
        is (stateWatiTillEmpty) {
            when (RegNext(exceptionThrown)) {
                robState := stateRollback
            } .elsewhen (empty) {
                robState := stateNormal
            }
        }
    }
    io.com_load_is_at_rob_head := RegNext(robHeadUsesLdq(PriorityEncoder(robHeadVals.asUInt)) && !willCommit.reduce(_||_))
}
