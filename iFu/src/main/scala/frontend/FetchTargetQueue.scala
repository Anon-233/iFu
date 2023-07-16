package iFu.frontend

import chisel3._
import chisel3.util._



class FetchBundle() extends Bundle with HasFBParameters
{
  val pc            = UInt(vaddrBits.W)
  val nextpc       = UInt(vaddrBits.W)
  val insts         = Vec(fetchWidth, Bits(32.W))
  val expInsts     = Vec(fetchWidth, Bits(32.W))

  // Information for sfb folding
  // NOTE: This IS NOT equivalent to uop.pc_lob, that gets calculated in the FB
  val sfbs                 = Vec(fetchWidth, Bool())
  val sfbMasks            = Vec(fetchWidth, UInt((2*fetchWidth).W))
  val sfbDests            = Vec(fetchWidth, UInt((1+log2Ceil(fetchBytes)).W))
  val shadowableMask      = Vec(fetchWidth, Bool())
  val shadowedMask        = Vec(fetchWidth, Bool())

  val cfiIdx       = Valid(UInt(log2Ceil(fetchWidth).W))
  val cfiType      = UInt(CFI_SZ.W)
  val cfiIsCall   = Bool()
  val cfiIsRet    = Bool()

  val rasTop       = UInt(vaddrBits.W)

  val ftqIdx       = UInt(log2Ceil(ftqSz).W)
  val mask          = UInt(fetchWidth.W) // mark which words are valid instructions

  val brMask       = UInt(fetchWidth.W)

  val gHist         = new GlobalHistory
  val lHist         = Vec(nBanks, UInt(localHistoryLength.W))

  val xcptPfIf    = Bool() // I-TLB miss (instruction fetch fault).
  val xcptAeIf    = Bool() // Access exception.

//   val bp_debug_if_oh= Vec(fetchWidth, Bool())
//   val bp_xcpt_if_oh = Vec(fetchWidth, Bool())


  val bpdMeta      = Vec (nBanks,Vec(bankWidth , new  PredictionMeta))

  // Source of the prediction from this bundle
  val fsrc    = UInt(BSRC_SZ.W)
  // Source of the prediction to this bundle
  val tsrc    = UInt(BSRC_SZ.W)
}

class FTQBundle extends Bundle with HasFTQParameters    {

  // // TODO compress out high-order bits
  // val fetch_pc  = UInt(vaddrBits.W)
  // IDX of instruction that was predicted taken, if any
  val cfiIdx   = Valid(UInt(log2Ceil(fetchWidth).W))
  // Was the CFI in this bundle found to be taken? or not
  val cfiTaken = Bool()
  // Was this CFI mispredicted by the branch prediction pipeline?
  val cfiMispredicted = Bool()
  // What type of CFI was taken out of this bundle
  val cfiType = UInt(CFI_SZ.W)
  // mask of branches which were visible in this fetch bundle
  val brMask   = UInt(fetchWidth.W)
  // This CFI is likely a CALL
  val cfiIsCall   = Bool()
  // This CFI is likely a RET
  val cfiIsRet    = Bool()
  // What was the top of the RAS that this bundle saw?
  val rasTop = UInt(vaddrBits.W)
  val rasIdx = UInt(log2Ceil(nRasEntries).W)

  // Which bank did this start from?
  val startBank = UInt(1.W)

  // // Metadata for the branch predictor
  // val bpdMeta = Vec(nBanks, UInt(bpdMaxMetaLength.W))
}

/**
 * IO to provide a port for a FunctionalUnit to get the PC of an instruction.
 * And for JALRs, the PC of the next instruction.
 */
class GetPCFromFtqIO extends Bundle with HasFTQParameters
{
  val ftqIdx   = Input(UInt(log2Ceil(ftqSz).W))

  val entry     = Output(new FTQBundle)
  val gHist     = Output(new GlobalHistory)

  val pc        = Output(UInt(vaddrBits.W))
  val compc    = Output(UInt(vaddrBits.W))

  // the nextpc may not be valid (stalled or still being fetched)
  val nextVal  = Output(Bool())
  val nextpc   = Output(UInt(vaddrBits.W))
}

/**
 * Queue to store the fetch PC and other relevant branch predictor signals that are inflight in the
 * processor.
 *
 * 
 */
class FetchTargetQueue extends Module with HasFTQParameters
{
  val numEntries = ftqSz
  private val idxSz = log2Ceil(numEntries)

  val io = IO(new Bundle {
    // Enqueue one entry for every fetch cycle.

    // 入队的FetchBundle
    val enq = Flipped(Decoupled(new FetchBundle()))
    // Pass to FetchBuffer (newly fetched instructions).

    // 记录该Bundle入队时指针
    val enqIdx = Output(UInt(idxSz.W))


    // ROB tells us the youngest committed ftqIdx to remove from FTQ.
    // ROB 传来的最新被提交的指令所在的dtqIdx
    val deq = Flipped(Valid(UInt(idxSz.W)))

    // Give PC info to BranchUnit.

    // 两个接口，每个端口只需传入一个ftqidx，就可以传出pc以及有关信息
    val getFtqpc = Vec(2, new GetPCFromFtqIO())


    // Used to regenerate PC for trace port stuff in FireSim
    // Don't tape this out, this blows up the FTQ
    // val debug_ftqIdx  = Input(Vec(coreWidth, UInt(log2Ceil(ftqSz).W)))
    // val debug_fetch_pc = Output(Vec(coreWidth, UInt(vaddrBits.W)))

    // 重定向信息的作用是，当发生分支预测错误时，需要将ftq中的指令重定向到正确的地址
    val redirect = Input(Valid(UInt(idxSz.W)))

    // brUpdate 是后端传来的update分支预测信息
    val brUpdate = Input(new BrUpdateInfo)

    // bpdUpdate是传出去，并最终用于分支预测器更新的信息
    val bpdUpdate = Output(Valid(new BranchPredictionUpdate))

    // 控制ras更新的信息
    val rasUpdate = Output(Bool())
    val rasUpdateIdx = Output(UInt(log2Ceil(nRasEntries).W))
    val rasUpdatepc  = Output(UInt(vaddrBits.W))

  })

  val clockcnt = RegInit((0.U)(10.W))
    clockcnt := clockcnt + 1.U
    printf("FetchTargetQueue Clock %d :\n", clockcnt)


  val bpdPtr    = RegInit(0.U(idxSz.W))
// 
  val deqPtr    = RegInit(0.U(idxSz.W))

//下一个入队的位置
  val enqPtr    = RegInit(1.U(idxSz.W))

// 标记队列是否已满
  val full = ((WrapInc(WrapInc(enqPtr, numEntries), numEntries) === bpdPtr) ||
              (WrapInc(enqPtr, numEntries) === bpdPtr))


  val pcs      = Reg(Vec(numEntries, UInt(vaddrBits.W)))
  val meta     = SyncReadMem(numEntries, Vec(nBanks, UInt(bpdMaxMetaLength.W)))
  val ram      = Reg(Vec(numEntries, new FTQBundle))
  val gHist    = Seq.fill(2) { SyncReadMem(numEntries, new GlobalHistory) }
  val lHist    = if (useLHist) {
    Some(SyncReadMem(numEntries, Vec(nBanks, UInt(localHistoryLength.W))))
  } else {
    None
  }
// 入队的信号
  val doEnq = io.enq.fire


  // This register lets us initialize the gHist to 0

  val previousgHist = RegInit((0.U).asTypeOf(new GlobalHistory))
  val previousEntry = RegInit((0.U).asTypeOf(new FTQBundle))
  val previouspc    = RegInit(0.U(vaddrBits.W))

//   入队操作
  when (doEnq) {
    // 入队PC入对应位置
    pcs(enqPtr)           := io.enq.bits.pc

    val newEntry = Wire(new FTQBundle)
    // 准备写入信息，也即newEntry的信息 
    newEntry.cfiIdx   := io.enq.bits.cfiIdx
    // Initially, if we see a CFI, it is assumed to be taken.
    // Branch resolutions may change this
    newEntry.cfiTaken     := io.enq.bits.cfiIdx.valid
    newEntry.cfiMispredicted := false.B
    newEntry.cfiType      := io.enq.bits.cfiType
    newEntry.cfiIsCall   := io.enq.bits.cfiIsCall
    newEntry.cfiIsRet    := io.enq.bits.cfiIsRet
    newEntry.rasTop       := io.enq.bits.rasTop
    newEntry.rasIdx       := io.enq.bits.gHist.rasIdx
    newEntry.brMask       := io.enq.bits.brMask & io.enq.bits.mask
    newEntry.startBank    := bank(io.enq.bits.pc)

    // 全局历史，如果currentSawBranchNotTaken为true，那么就用这个历史，否则用根据上一个表项更新的历史
    val newgHist = Mux(io.enq.bits.gHist.currentSawBranchNotTaken,
      io.enq.bits.gHist,
      previousgHist.update(
        previousEntry.brMask,
        previousEntry.cfiTaken,
        previousEntry.brMask(previousEntry.cfiIdx.bits),
        previousEntry.cfiIdx.bits,
        previousEntry.cfiIdx.valid,
        previouspc,
        previousEntry.cfiIsCall,
        previousEntry.cfiIsRet
      )
    )

    // 进行写入操作
    lHist.map( l => l.write(enqPtr, io.enq.bits.lHist))
    gHist.map( g => g.write(enqPtr, newgHist))
    meta.write(enqPtr, io.enq.bits.bpdMeta)
    ram(enqPtr) := newEntry

    // 每次入队更新previous的保存内容
    previouspc    := io.enq.bits.pc
    previousEntry := newEntry
    previousgHist := newgHist

    enqPtr := WrapInc(enqPtr, numEntries)
  }

  io.enqIdx := enqPtr

  io.bpdUpdate.valid := false.B
  io.bpdUpdate.bits  := DontCare

  when (io.deq.valid) {
    deqPtr := io.deq.bits
  }

  // This register avoids a spurious bpd update on the first fetch packet
  val firstEmpty = RegInit(true.B)

  // We can update the branch predictors when we know the target of the
  // CFI in this fetch bundle

  // 接下来的代码是为了准备bpdUpdate的信息，这包括RAS和BPD

  val rasUpdate = WireInit(false.B)
  val rasUpdatepc = WireInit(0.U(vaddrBits.W))
  val rasUpdateIdx = WireInit(0.U(log2Ceil(nRasEntries).W))
  io.rasUpdate     := RegNext(rasUpdate)
  io.rasUpdatepc  := RegNext(rasUpdatepc)
  io.rasUpdateIdx := RegNext(rasUpdateIdx)

  val bpdUpdateMispredict = RegInit(false.B)
  val bpdUpdateRepair = RegInit(false.B)
  val bpdRepairIdx = Reg(UInt(log2Ceil(ftqSz).W))
  val bpdEndIdx = Reg(UInt(log2Ceil(ftqSz).W))
  val bpdRepairpc = Reg(UInt(vaddrBits.W))

  val bpdIdx = Mux(io.redirect.valid, io.redirect.bits,
    Mux(bpdUpdateRepair || bpdUpdateMispredict, bpdRepairIdx, bpdPtr))
  val bpdEntry = RegNext(ram(bpdIdx))
  val bpdgHist = gHist(0).read(bpdIdx, true.B)
  val bpdlHist = if (useLHist) {
    lHist.get.read(bpdIdx, true.B)
  } else {
    VecInit(Seq.fill(nBanks) { 0.U })
  }
  val bpdMeta  = meta.read(bpdIdx, true.B) // TODO fix these SRAMs
  val bpdpc    = RegNext(pcs(bpdIdx))
  val bpdTarget = RegNext(pcs(WrapInc(bpdIdx, numEntries)))

  // 如果发生了EX阶段分支预测错误，同一个周期传回来几个信号，包括io.redirect.valid和io.brUpdate.b2.mispredict
  // 这里有点像状态机,首先是重定向->分支预测错误->分支预测错误修复->分支预测错误修复完成
  // 结合最下面的代码,在重定向周期,会做两件事,首先是enqPtr指向重定向的位置,相当于清空预测错误之后的信息记录
  // 以及
  when (io.redirect.valid) {
    
    bpdUpdateMispredict := false.B
    bpdUpdateRepair     := false.B
  } .elsewhen (RegNext(io.brUpdate.b2.mispredict)) {
    bpdUpdateMispredict := true.B
    bpdRepairIdx        := RegNext(io.brUpdate.b2.uop.ftqIdx)
    bpdEndIdx           := RegNext(enqPtr)
  } .elsewhen (bpdUpdateMispredict){
    bpdUpdateMispredict := false.B
    bpdUpdateRepair     := true.B
    bpdRepairIdx        := WrapInc(bpdRepairIdx, numEntries)
  } .elsewhen (bpdUpdateRepair && RegNext(bpdUpdateMispredict)) {
    bpdRepairpc         := bpdpc
    bpdRepairIdx        := WrapInc(bpdRepairIdx, numEntries)
  } .elsewhen (bpdUpdateRepair) {
    bpdRepairIdx        := WrapInc(bpdRepairIdx, numEntries)
    when (WrapInc(bpdRepairIdx, numEntries) === bpdEndIdx ||
      bpdpc === bpdRepairpc)  {
      bpdUpdateRepair := false.B
    }
  }


  val doCommitUpdate     = (!bpdUpdateMispredict &&
                              !bpdUpdateRepair &&
                               bpdPtr =/= deqPtr &&
                               enqPtr =/= WrapInc(bpdPtr, numEntries) &&
                              !io.brUpdate.b2.mispredict &&
                              !io.redirect.valid && !RegNext(io.redirect.valid))
  val doMispredictUpdate = bpdUpdateMispredict
  val doRepairUpdate     = bpdUpdateRepair

//   只要有更新指示，就根据读取到的信息，准备好更新信息并输出
  when (RegNext(doCommitUpdate || doRepairUpdate || doMispredictUpdate)) {
    val cfiIdx = bpdEntry.cfiIdx.bits
    val validRepair = bpdpc =/= bpdRepairpc

    io.bpdUpdate.valid := (!firstEmpty &&
                           (bpdEntry.cfiIdx.valid || bpdEntry.brMask =/= 0.U) &&
                           !(RegNext(doRepairUpdate) && !validRepair))
    io.bpdUpdate.bits.isMispredictUpdate := RegNext(doMispredictUpdate)
    io.bpdUpdate.bits.isRepairUpdate     := RegNext(doRepairUpdate)
    io.bpdUpdate.bits.pc      := bpdpc
    io.bpdUpdate.bits.btbMispredicts := 0.U
    io.bpdUpdate.bits.brMask := Mux(bpdEntry.cfiIdx.valid,
      MaskLower(UIntToOH(cfiIdx)) & bpdEntry.brMask, bpdEntry.brMask)
    io.bpdUpdate.bits.cfiIdx := bpdEntry.cfiIdx
    io.bpdUpdate.bits.cfiMispredicted := bpdEntry.cfiMispredicted
    io.bpdUpdate.bits.cfiTaken  := bpdEntry.cfiTaken
    io.bpdUpdate.bits.target     := bpdTarget
    io.bpdUpdate.bits.cfiIsBr  := bpdEntry.brMask(cfiIdx)
    io.bpdUpdate.bits.cfiIsJal := bpdEntry.cfiType === CFI_JAL || bpdEntry.cfiType === CFI_JALR
    io.bpdUpdate.bits.gHist      := bpdgHist
    io.bpdUpdate.bits.lHist      := bpdlHist
    io.bpdUpdate.bits.meta       := bpdMeta

    firstEmpty := false.B
  }

  when (doCommitUpdate) {
    bpdPtr := WrapInc(bpdPtr, numEntries)
  }

  io.enq.ready := RegNext(!full || doCommitUpdate)

  val redirectIdx = io.redirect.bits
  val redirectEntry = ram(redirectIdx)
  val redirectNewEntry = WireInit(redirectEntry)

  when (io.redirect.valid) {
    enqPtr    := WrapInc(io.redirect.bits, numEntries)

    when (io.brUpdate.b2.mispredict) {
    val newCfiIdx = (io.brUpdate.b2.uop.pc_lob ^
      Mux(redirectEntry.startBank === 1.U, 1.U << log2Ceil(bankBytes), 0.U))(log2Ceil(fetchWidth), 1)
      redirectNewEntry.cfiIdx.valid    := true.B
      redirectNewEntry.cfiIdx.bits     := newCfiIdx
      redirectNewEntry.cfiMispredicted := true.B
      redirectNewEntry.cfiTaken        := io.brUpdate.b2.taken
      redirectNewEntry.cfiIsCall      := redirectEntry.cfiIsCall && redirectEntry.cfiIdx.bits === newCfiIdx
      redirectNewEntry.cfiIsRet       := redirectEntry.cfiIsRet  && redirectEntry.cfiIdx.bits === newCfiIdx
    }

    rasUpdate     := true.B
    rasUpdatepc  := redirectEntry.rasTop
    rasUpdateIdx := redirectEntry.rasIdx

  } .elsewhen (RegNext(io.redirect.valid)) {
    previousEntry := RegNext(redirectNewEntry)
    previousgHist := bpdgHist
    previouspc    := bpdpc

    ram(RegNext(io.redirect.bits)) := RegNext(redirectNewEntry)
  }

  //-------------------------------------------------------------
  // **** Core Read PCs ****
  //-------------------------------------------------------------

  for (i <- 0 until 2) {
    val idx = io.getFtqpc(i).ftqIdx
    val nextIdx = WrapInc(idx, numEntries)
    val nextIsEnq = (nextIdx === enqPtr) && io.enq.fire
    val nextpc = Mux(nextIsEnq, io.enq.bits.pc, pcs(nextIdx))
    val getEntry = ram(idx)
    val nextEntry = ram(nextIdx)
    io.getFtqpc(i).entry     := RegNext(getEntry)
    if (i == 1)
      io.getFtqpc(i).gHist   := gHist(1).read(idx, true.B)
    else
      io.getFtqpc(i).gHist   := DontCare
    io.getFtqpc(i).pc        := RegNext(pcs(idx))
    io.getFtqpc(i).nextpc   := RegNext(nextpc)
    io.getFtqpc(i).nextVal  := RegNext(nextIdx =/= enqPtr || nextIsEnq)
    io.getFtqpc(i).compc    := RegNext(pcs(Mux(io.deq.valid, io.deq.bits, deqPtr)))
  }

  for (w <- 0 until coreWidth) {
    io.debug_fetch_pc(w) := RegNext(pcs(io.debug_ftqIdx(w)))
  }
}
