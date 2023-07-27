package iFu.backend

import chisel3._
import chisel3.util._
import iFu.common._


class RobIO(
    val numWakeupPorts: Int
) extends CoreBundle
{

    val enq_valids = Input(Vec(coreWidth,Bool()))
    val enq_uops = Input(Vec(coreWidth,new MicroOp()))
    val enq_partial_stall = Input(Bool())

    val xcpt_fetch_pc = Input(UInt(vaddrBitsExtended.W))
    //output
    val rob_tail_idx = Output(UInt(robAddrSz.W))
    val rob_pnr_idx = Output(UInt(robAddrSz.W))
    val rob_head_idx = Output(UInt(robAddrSz.W))

    val brupdate = Input(new BrUpdataInfo())
    //写回阶段
    val wb_resps = Flipped(Vec(numWakeupPorts,Valid(new ExeUnitResp(xLen max fLen+1))))

    //store stage
    val lsu_clr_bsy = Input(Vec(memWidth +1,Valid(UInt(robAddrSz.W))))

    val lsu_clr_unsafe = Input(Vec(memWidth,Valid(robAddrSz.W)))

    val lxcpt = Flipped(new ValidIO(new Exception()))

    //commit stage
    val commit = Output(new CommitSignals())

    //load指令位于ROB头指针处
    val com_load_is_at_rob_head = Output(Bool())

    //excetion to CSR
    val com_xcpt = Valid(new CommitExceptionSignals())

    val csr_stall = Input(Bool())

    //flush signals
    //可能因为异常，流水线延迟或者访存阶段错误等,发送给frondend
    val flush = Valid(new CommitExceptionSignals)

    val empty = Output(Bool())
    val ready = Output(Bool())

    val flush_frontend = Output(Bool())


}

class CommitSignals extends CoreBundle
{
    val valids = Vec(retireWidth, Bool())
    val arch_valids = Vec(retireWidth,Bool())
    val uops = Vec(retireWidth,new MicroOP())
    //val fflags = Valid(UInt(5.W))

    //maybe use
    //val debug
    
    val rbk_valids = Vec(retireWidth,Bool())
    val rollback = Bool()
}

class CommitExceptionSignals extends CoreBundle
{
    val ftq_idx = UInt(log2Ceil(ftqSz).W)
    //val edge_inst = Bool()
    //val is_rvc = Bool()
    val pc_lob = UInt(log2Ceil(icBlockBytes).W)
    val cause = UInt(xLen.W)
    val badvaddr = UInt(xLen.W)

    val flush_typ = FlushTypes()
}

object FlushTypes
{
    def SZ =3
    def apply() = UInt(SZ.W)
    def none = 0.W
    def xcpt = 1.U
    def eret = (2+1).U
    def refetch = 2.U
    def next = 4.U

    def useCsrEvec(typ: UInt): Bool = typ(0)
    def useSamePC(typ: UInt): Bool = typ === refetch
    def usePCplus4(typ: UInt): Bool = typ === next

    def getType(valid: Bool, i_xcpt: Bool, i_eret: Bool, i_refetch: Bool):UInt = {
        val ret = 
            Mux(!valid,none,
            Mux(i_eret,eret,
            Mux(i_xcpt,xcpt,
            Mux(i_refetch,refetch,
            next))))
        ret
    }

}

class Exception extends CoreBundle
{
    val uop = new MicroOp()
    //TODO:update cause to loogarch
    val cause = Bits(log2Ceil(freechips.rocketchip.rocket.Causes.all.max+2).W)
    val badvaddr = UInt(coreMaxAddrBits.W)
}


class Rob(
    val numWakeupPorts: Int
) extends CoreModule
{
    val io = IO(new RobIO(numWakeupPorts))

    //state
    val stateReset :: stateNormal ::stateRollback ::stateWatiTillEmpty ::Nil = Enum(4)
    val robState = RegInit(stateReset)

    val robHead = RegInit(0.U(log2Ceil(numRobRows).W))
    val robHeadLsb = RegInit(0.U((1 max log2Ceil(coreWidth)).W))
    val robHeadIdx = if (coreWidth == 1) robHead else Cat(robHead,robHeadLsb)

    val robTail = RegInit(0.U(log2Ceil(numRobRows).W))
    val robTailLsb = RegInit(0.U((1 max logCeil(coreWidth)).W))
    val robTailIdx = if (coreWidth ==1 )robTail else Cat(robTail,robTailLsb)
    
    //maybe not use
    //val robPnr = RegInit(0.U(log2Ceil(numRobRows).W))
    //val robPnrLsb = RegInit(0.U((1 max log2Ceil(coreWidth)).W))
    //val robPnrIdx = if(coreWidth ==1) robPnr else Cat(robPnr,robPnrLsb)

    val comIdx = Mux(robState === stateRollback,robTail,robHead)

    val maybeFull = RegInit(false.B)
    val full = Wire(Bool())
    val empty = Wire(Bool())

    val willCommit = Wire(Vec(coreWidth,Bool()))
    val canCommit = Wire(Vec(coreWidth,Bool()))
    val canThrowException = Wire(Vec(coreWidth,Bool()))

    //val rob_pnr_unsafe      = Wire(Vec(coreWidth, Bool())) // are the instructions at the pnr unsafe?
    val robHeadVals = Wire(Vec(coreWidth,Bool()))
    val robTailVals = Wire(Vec(coreWidth,Bool()))
    val robHeadUsesStq = Wire(Vec(coreWidth,Bool()))
    val robHeadUsesLdq = Wire(Vec(coreWidth,Bool()))
    
    val exceptionThrown = Wire(Bool())

    val rXcptVal = RegInit(false.B)
    val rXcptUop = Reg(new MicroOP())
    val rXcptBadvaddr = Reg(UInt(coreMaxAddrBits.W))
    io.flush_frontend := rXcptVal

    //-----------------tool def---------------------
    def GetRowIdx(robIdx : UInt) :UInt ={
        if(coreWidth == 1) return robIdx
        else return robIdx >> log2Ceil(coreWidth).U
    }
    def GetBankIdx(robIdx :UInt):UInt ={
        if (coreWidth ==1 ) return 0.U
        else {return robIdx(log2Ceil(coreWidth)-1,0).asUInt}
    }

    //---------------------------------------------

    val robUnsafeMasked = WireInit(VecInit(Seq.fill(numRobRows << log2Ceil(coreWidth)){false.B}))

    for (w <-0 until coreWidth) {
        def MatchBank(bankIdx : UInt) :Bool = (bankIdx === w.U)

        val robVal = RegInit(VecInit(Seq.fill(numRobRows){false.B}))
        val robBsy = Reg(Vec(numRobRows, Bool()))
        val robUnsafe = Reg(Vec(numRobRows, Bool()))
        val robUop = Reg(Vec(numRobRows,new MicroOp()))
        val robException = Reg(Vec(numRobRows, Bool()))
        val robPredicated = Reg(Vec(numRobRows, Bool()))

        //------------------dispatch stage------------------
        //enqueue
        when (io.enq_valids(w)){
            robVal(robTail) := true.B
            robBsy(robTail) := !(io.enq_uops(w).is_fence || io.enq_uops(w).is_fencei)
            robUnsafe(robTail) := io.enq_uops(w).unsafe
            robException(robTail) := io.enq_uops(w).exception
            robUop(robTail) := io.enq_uops(w)
            robPredicated(robTail) := false.B

        }

        //------------------writeback-----------------------
        for(i <- 0 until numWakeupPorts){
            val wbResp = io.wb_resps(i)
            val wbUop = wbResp.bits.uop
            val rowIdx = GetRowIdx(wbUop.rob_idx)
            when(wbResp.valid && MatchBank(GetBankIdx(wbUop.rob_idx))){
                robBsy(rowIdx) := false.B
                robUnsafe(rowIdx) := false.B
                robPredicated(rowIdx) := wbResp.bits.predicated
            }
        }


        //-----------------lsu------------------------
        for(clr_rob_idx <- io.lsu_clr_bsy){
            when(clr_rob_idx.valid && MatchBank(GetBankIdx(clr_rob_idx.bits))){
                val cidx = GetRowIdx(clr_rob_idx.bits)
                robBsy(cidx) := false.B
                robUnsafe(cidx) := false.B
            }
        }
        for (clr <- io.lsu_clr_unsafe){
            when(clr.valid && MatchBank(GetBankIdx(clr.bits))){
                val cidx = GetRowIdx(clr.bits)
                robUnsafe(cidx) := false.B
            }
        }


        //----------------exception-----------------
        when(io.lxcpt.valid && MatchBank(GetBankIdx(io.lxcpt.bits.uop.robidx))) {
            robException(GetRowIdx(io.lxcpt.bits.uop.rob_idx)) := true.B
                //错误应该只可能是发生存储-加载顺序异常(Memory Ordering Failure)。当 store 指令与其后的 load 指令有共同的目标地址时，类似 RAW 冲突，若 load 指令在 store 之前发射(Issue)，load 命令将从内存中读取错误的值。
                
        }
        
        canThrowException(w) := robVal(robHead) && robException(robHead)

        //---------------output:commit------------
        canCommit(w) := robVal(robHead) && !(robBsy(robHead)) && !io.csr_stall

        io.commit.valids(w) := willCommit(w)
        io.commit.arch_valids(w) := willCommit(w) && !robPredicated(comIdx)
        io.commit.uops(w) := robUop(comIdx)
        

        when(io.brupdate.b2.mispredict &&
            MatchBank(GetBankIdx(io.brupdate.b2.uop.rob_idx)) &&
            GetRowIdx(io.brupdate.b2.uop.rob_idx) === comIdx) {
                io.commit.uops(w).token := io.brupdate.b2.taken 
            }

        val rbkRow = robState === stateRollback && !full

        io.commit.rbk_valids(w) := rbkRow && robVal(comIdx)
        io.commit.rollback := (robState === stateRollback)

        when(rbkRow){
            robVal(comIdx) := false.B
            robException(comIdx) := false.B
        }

        //------------------wrong branch-------------------

        for(i <- 0 until numRobRows){
            var brMask = robUop(i).br_mask

            when(IsKilledByBranch(io.brupdate,br_mask))
            {
                robVal(i) :=false.B
            } .elsewhen (robVal(i)){
                robUop(i).br_mask := GetNewBrMask(io.brupdate,brMask)
            }
        }

        when(io.brupdate.b2.mispredict &&
        MatchBank(GetBankIdx(io.brupdate.b2.uop.rob_idx))){
            robUop(GetRowIdx(io.brupdate.b2.uop.rob_idx)).taken := io.brupdate.b2.taken
        }



        //------------------commit--------------------------
        when(willCommit(w)) {
            robVal(robHead) := false.B
        }

        //--------------------output-----------------------
        robHeadVals(w) := robVal(robHead)
        robTailVals(w) := robVal(robTail)
        robHeadUsesLdq(w) := robUop(robHead).uses_ldq
        robHeadUsesStq(w) := robUop(robHead).uses_stq

        for( i<- 0 until numRobRows){
            robUnsafeMasked((i<<log2Ceil(coreWidth)) + w) := robVal(i) && (robUnsafe(i) || robException(i))

        }

        //rob_pnr_unsafe(w) := rob_val(rob_pnr) && (rob_unsafe(rob_pnr) || rob_exception(rob_pnr))

    }


    val blockCommit = (robState =/= stateNormal) && (robState =/= stateWatiTillEmpty) || RegNext(exceptionThrown) ||RegNext(RegNext(exceptionThrown))
    val willThrowException = false.B
    val blockXcpt = false.B

    for(w<- 0 until coreWidth) {
        willThrowException = (canThrowException(w) && !blockCommit && !blockXcpt) || willThrowException
        willCommit(w) := canCommit(w) && !canThrowException(w) && !blockCommit
        blockCommit = (robHeadVals(w) && (!canCommit(w) || canThrowException(w))) ||blockCommit
        blockXcpt = willCommit(w)
    }

    exceptionThrown := willThrowException
    val isMiniException = io.com_xcpt.bits.cause === MINI_EXCEPTION_MEM_ORDERING
    io.com_xcpt.valid := exceptionThrown && !isMiniException
    io.com_xcpt.bits.cause := rXcptUop.exc_cause

    io.com_xcpt.bits.badvaddr := Sext(rXcptBadvaddr, xLen)
    val insnSysPc2epc = robHeadVals.reduce(_||_) && PriorityMux(robHeadvals,io.commit.uops.map{u => u.is_sys_pc2epc})
    
    val refetchInst = exceptionThrown || insnSysPc2epc
    val comXcptUop = PriorityMux(robHeadVals,io.commit.uops)
    io.com_xcpt.bits.ftq_idx := comXcptUop.ftq_idx
    io.com_xcpt.bits.edge_inst := comXcptUop.edge_inst
    io.com_xcpt.bits.is_rvc := comXcptUop.is_rvc
    io.com_xcpt.bits.pc_lob := comXcptUop.pc_lob


    //------------------flush-------------------

    val flushCommitMask = Range(0,coreWidth).map{i => io.commit.valids(i) && io.commit.uops(i).flush_on_commit}
    val flushCommit = flushCommitMask.reduce(_|_)
    val flushVal = exceptionThrown || flushCommit

    val flushUop = Mux(exceptionThrown,comXcptUop,Mux1H(flushCommitMask,io.commit.uops))

    //优化时序，延迟一个周期
    io.flush.valid := flushVal
    io.flush.bits.ftq_idx := flushUop.ftq_idx
    io.flush.bits.pc_lob := flushUop.pc_lob
    io.flush.bits.edge_inst := flushUop.edge_inst
    io.flush.bits.is_rvc := flushUop.is_rvc
    io.flush.bits.flush_typ := FlushTypes.getType(flushVal,
                                                exceptionThrown && !isMiniException,
                                                flushCommit && flushUop.uopc === uopERET,
                                                refetch_inst)

    

    //------------------exception-------------------
    val nextXcptUop = Wire(new MicroOP())
    nextXcptUop := rXcptUop
    val enqXcpts = Wire(Vec(coreWidth,Bool()))
    for(i <- 0 until coreWidth) {
        enqXcpts(i) := io.enq_valids(i) && io.enq_uops(i).exception
    }

    when(!(io.flush.valid || exceptionThrown) && robState =/= stateRollback){
        when(io.lxcpt.valid){
            val newXcptUop = io.lxcpt.bits.uop

            when(!rXcptVal || IsOlder(newXcptUop.rob_idx,rXcptUop.rob_idx,robHeadIdx)){
                rXcptVal := true.B
                nextXcptUop := newXcptUop
                nextXcptUop.exc_cause := io.lxcpt.bits.cause
                rXcptBadvaddr := io.lxcpt.bits.badvaddr
            }
        } .elsewhen (!rXcptVal && enqXcpts.reduce(_|_)){
            val idx = enqXcpts.indexWhere{i: Bool => i}

            rXcptVal := true.B
            nextXcptUop := io.enq_uop(idx)
            rXcptBadvaddr := AlignPCToBoundary(io.xcpt_fetch_pc,icBlockBytes) | io.enq_uop(idx).pc_lob
        }
    }

    rXcptUop := nextXcptUop
    rXcptUop.br_mask := GetNewBrMask(io.brupdate,nextXcptUop)
    when(io.flush.valid || IsKilledByBranch(io.brupdate,nextXcptUop)){
        rXcptVal := false.B
    }

    //--------------------Robhead-------------------
    val robDeq = WireInit(false.B)
    val rPartialRow = RegInit(false.B)


    when(io.enq_valids.reduce(_|_)){
        rPartialRow := io.enq_partial_stall
    }

    val finishedCommittingRow = (io.commit.valids.asUInt =/= 0.U) &&
                                ((willCommit.asUInt ^ robHeadVals.asUInt) === 0.U) &&
                                !(rPartialRow && robHead === robTail && !maybeFull)

    when(finishedCommittingRow){
        robHead := WrapInc(robHead,numRobRows)
        robHeadLsb := 0.U
        robDeq := true.B
    } .otherwise {
        robHeadLsb := OHToUInt(PriorityEncoderOH(robHeadVals.asUInt))
    }

    //TODO:pnr??

    //------------------------robtail-------------------
    val robEnq = WireInit(false.B)

    when(robState === stateRollback && (robTail =/= robHead || maybeFull)){
        robTail := WrapDec(robTail,numRobRows)
        robTailLsb := (coreWidth-1).U
        robDeq := true.B
    } .elsewhen(robState === stateRollback && (robTail === robHead) && !maybeFull){
        robTailLsb :=robHeadLsb
    }.elsewhen(io.brupdate.b2.mispredict){
        robTail := WrapInc(GetRowIdx(io.brupdate.b2.uop.rob_idx),numRobRows)
        robTailLsb := 0.U
    } .elsewhen(io.enq_valids.asUInt =/= 0.U !io.enq_partial_stall){
        robTail := WrapInc(robTail,numRobRows)
        robTailLsb := 0.U
        robEnq := true.B
    } .elsewhen(io.enq_valids.asUInt =/= 0.U && io.enq_partial_stall){
        robTailLsb := PriorityEncoder(~MaskLower(io.enq_valids.asUInt))
    }

    //----------------------maybefull--------------------
    maybeFull := !robDeq &&(robEnq||maybeFull) || io.brupdate.b1.mispredict_mask =/= 0.U
    full := robTail === robHead && maybeFull
    empty :=(robHead === robTail) && (robHeadVals.asUInt ===0.U)

    io.rob_head_idx := robHeadIdx
    io.rob_tail_idx := robTailIdx
    io.empty := empty
    io.ready := (robState === stateNormal) && !full && !rXcptVal

    //---------------------state change(FSM)-------------------

    switch(robState){
        is(stateReset){
            robState := stateNormal
        }
        is(stateNormal){
            when(RegNext(RegNext(exceptionThrown))){
                robState := stateRollback
            } .otherwise{
                for (w <-0 until coreWidth){
                    //进入rob的指令一旦检测到is_unque就暂停rob
                    when(io.enq_valids(w) && io.enq_uops(w).is_unique){
                        robState := stateWatiTillEmpty
                    }
                }
            }
        }
        is(stateRollback){
            when (empty){
                robState := stateNormal
            }
        }
        is(stateWatiTillEmpty){
            when(RegNext(exceptionThrown)){
                robState := stateRollback
            } .elsewhen (empty){
                robState := stateNormal
            }
        }
    }


    io.com_load_is_at_rob_head := RegNext(robHeadUsesLdq(PriorityEncoder(robHeadVals.asUInt)) && !willCommit.reduce(_||_))


}


//------------------------------------------utils------------------------------
object WrapDec
{
  def apply(value: UInt, n: Int): UInt = {
      val wrap = (value === 0.U)
      Mux(wrap, (n-1).U, value - 1.U)
  }
}

object WrapInc
{
  def apply(value: UInt, n: Int): UInt = {
      val wrap = (value === (n-1).U)
      Mux(wrap, 0.U, value + 1.U)
  }
}

object Sext
{
    def apply(x: UInt, length: Int): UInt = {
        if (x.getWidth == length) return x
        else return Cat(Fill(length-x.getWidth, x(x.getWidth-1)), x)
    }
}

