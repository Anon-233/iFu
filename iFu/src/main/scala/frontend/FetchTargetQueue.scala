package iFu.frontend

import chisel3._
import chisel3.util._
import iFu.common._
import iFu.common.Consts._
import iFu.util._
import iFu.frontend.FrontendUtils._
import ram.SDPRam

class FTQBundle extends CoreBundle {
    val fetchWidth      = frontendParams.fetchWidth
    val numRasEntries   = frontendParams.bpdParams.numRasEntries

    val cfiIdx          = Valid(UInt(log2Ceil(fetchWidth).W))
    val cfiTaken        = Bool()
    val cfiMispredicted = Bool()
    val cfiType         = UInt(CFI_SZ.W)
    // mask of branches which were visible in this fetch bundle
    val brMask          = UInt(fetchWidth.W)
    val cfiIsCall       = Bool()
    val cfiIsRet        = Bool()

    val rasTop          = UInt(vaddrBits.W)
    val rasIdx          = UInt(log2Ceil(numRasEntries).W)
}

class GetPCFromFtqIO extends CoreBundle {

    val numFTQEntries = frontendParams.numFTQEntries

    val ftqIdx  = Input(UInt(log2Ceil(numFTQEntries).W))

    val entry   = Output(new FTQBundle)
    val gHist   = Output(new GlobalHistory)

    val pc      = Output(UInt(vaddrBits.W))
    val compc   = Output(UInt(vaddrBits.W))

    // the nextpc may not be valid (stalled or still being fetched)
    val nextVal = Output(Bool())
    val nextpc  = Output(UInt(vaddrBits.W))
}

class FetchTargetQueue extends CoreModule {
    val numFTQEntries      = frontendParams.numFTQEntries
    val numRasEntries      = frontendParams.bpdParams.numRasEntries
    val fetchWidth         = frontendParams.fetchWidth
    val fetchBytes         = frontendParams.fetchBytes
    val idxSz              = log2Ceil(numFTQEntries)

    val io = IO(new Bundle {
        val enq          = Flipped(Decoupled(new FetchBundle))
        val enqIdx       = Output(UInt(idxSz.W))

        // ROB 传来的最新被提交的指令所在的ftqIdx
        val deq          = Flipped(Valid(UInt(idxSz.W)))

        // 两个接口，每个端口只需传入一个ftqidx 就可以传出pc以及有关信息
        val getFtqpc     = Vec(2, new GetPCFromFtqIO)

        // 预测错误指令所处的 ftqIdx
        val redirect     = Input(Valid(UInt(idxSz.W)))

        // brUpdate 是后端传来的update分支预测信息
        val brUpdate     = Input(new BrUpdateInfo)

        // bpdUpdate 用于分支预测器更新
        val bpdUpdate    = Output(Valid(new BranchPredictionUpdate))

        // 控制ras更新的信息
        val rasUpdate    = Output(Bool())
        val rasUpdateIdx = Output(UInt(log2Ceil(numRasEntries).W))
        val rasUpdatepc  = Output(UInt(vaddrBits.W))
    })

    val train_ptr    = RegInit(0.U(idxSz.W))
    val commited_ptr = RegInit(0.U(idxSz.W))
    val bpu_ptr      = RegInit(1.U(idxSz.W))  // 下一个入队的指令的ftqIdx

    // 标记队列是否已满
    val full = (
        (WrapInc(bpu_ptr, numFTQEntries) === train_ptr) ||
        (WrapInc(WrapInc(bpu_ptr, numFTQEntries), numFTQEntries) === train_ptr)
    ) // why need at least 2 empty entries?

    val pcs   = Reg(Vec(numFTQEntries, UInt(vaddrBits.W)))
    val meta  = SyncReadMem(numFTQEntries, Vec(fetchWidth ,new PredictionMeta))
    val ram   = Reg(Vec(numFTQEntries, new FTQBundle))
    val gHist = Seq.fill(2) { Module(new SDPRam(numFTQEntries, new GlobalHistory)) }

    val previousgHist = RegInit((0.U).asTypeOf(new GlobalHistory))
    val previousEntry = RegInit((0.U).asTypeOf(new FTQBundle))
    val previouspc    = RegInit(0.U(vaddrBits.W))

    // 入队操作
    val newEntry = Wire(new FTQBundle)
    newEntry.cfiIdx          := io.enq.bits.cfiIdx
    newEntry.cfiTaken        := io.enq.bits.cfiIdx.valid
    newEntry.cfiMispredicted := false.B
    newEntry.cfiType         := io.enq.bits.cfiType
    newEntry.cfiIsCall       := io.enq.bits.cfiIsCall
    newEntry.cfiIsRet        := io.enq.bits.cfiIsRet
    newEntry.rasTop          := io.enq.bits.rasTop
    newEntry.rasIdx          := io.enq.bits.gHist.rasIdx
    newEntry.brMask          := io.enq.bits.brMask & io.enq.bits.mask

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

    when(io.enq.fire) {
        pcs(bpu_ptr) := io.enq.bits.pc

        // 进行写入操作
        meta.write(bpu_ptr, io.enq.bits.bpdMeta)
        ram(bpu_ptr) := newEntry

        // 每次入队更新previous的保存内容
        previouspc    := io.enq.bits.pc
        previousEntry := newEntry
        previousgHist := newgHist

        bpu_ptr := WrapInc(bpu_ptr, numFTQEntries)
    }
    gHist.foreach(g => {
        g.io.wen := io.enq.fire
        g.io.waddr := bpu_ptr
        g.io.wdata.head := newgHist
        g.io.wstrobe := 1.U
    })
    io.enqIdx := bpu_ptr

    when (io.deq.valid) {
        commited_ptr := io.deq.bits
    }

    val bpdIdx    = Mux(io.redirect.valid, io.redirect.bits,
                                           train_ptr)
    val bpdEntry  = RegNext(ram(bpdIdx))
    gHist(0).io.raddr := bpdIdx
    val bpdgHist  = gHist(0).io.rdata.head
    val bpdMeta   = meta.read(bpdIdx, true.B)
    val bpdpc     = RegNext(pcs(bpdIdx))
    val bpdTarget = RegNext(pcs(WrapInc(bpdIdx, numFTQEntries)))

    val doCommitUpdate = (
        train_ptr =/= commited_ptr                    &&    // has some committed instructions to train
        WrapInc(train_ptr, numFTQEntries) =/= bpu_ptr &&    // training data's target is valid
        !io.redirect.valid && !RegNext(io.redirect.valid)
    )

    io.bpdUpdate.valid := false.B
    io.bpdUpdate.bits  := DontCare
    when (RegNext(doCommitUpdate)) {
        val cfiIdx = bpdEntry.cfiIdx.bits

        io.bpdUpdate.valid := (
            (bpdEntry.cfiIdx.valid || bpdEntry.brMask =/= 0.U)
        )
        io.bpdUpdate.bits.pc              := bpdpc
        io.bpdUpdate.bits.brMask          := Mux(
            bpdEntry.cfiIdx.valid,
                MaskLower(UIntToOH(cfiIdx)) & bpdEntry.brMask,
                bpdEntry.brMask
        )
        io.bpdUpdate.bits.cfiIdx          := bpdEntry.cfiIdx
        io.bpdUpdate.bits.cfiMispredicted := bpdEntry.cfiMispredicted
        io.bpdUpdate.bits.cfiTaken        := bpdEntry.cfiTaken
        io.bpdUpdate.bits.target          := bpdTarget
        io.bpdUpdate.bits.cfiIsBr         := bpdEntry.brMask(cfiIdx)
        io.bpdUpdate.bits.cfiIsJal        := bpdEntry.cfiType === CFI_BL || bpdEntry.cfiType === CFI_JIRL
        io.bpdUpdate.bits.gHist           := bpdgHist
        io.bpdUpdate.bits.meta            := bpdMeta
    }

    when (doCommitUpdate) {
        train_ptr := WrapInc(train_ptr, numFTQEntries)
    }

    io.enq.ready := RegNext(!full || doCommitUpdate)

//-------------------------------------------------------------
// fix bpu_ptr
    when (io.redirect.valid) {
        bpu_ptr := WrapInc(io.redirect.bits, numFTQEntries)
    }
//-------------------------------------------------------------
// fix ras in global history
    val rasUpdate    = WireInit(false.B)
    val rasUpdatepc  = WireInit(0.U(vaddrBits.W))
    val rasUpdateIdx = WireInit(0.U(log2Ceil(numRasEntries).W))

    io.rasUpdate    := RegNext(rasUpdate)
    io.rasUpdatepc  := RegNext(rasUpdatepc)
    io.rasUpdateIdx := RegNext(rasUpdateIdx)
//-------------------------------------------------------------
// fix ram entry(ftq meta)
    val old_entry = ram(io.redirect.bits)   // the entry of the mispredicted br
    val new_entry = WireInit(old_entry)     // prepare a new entry for commit update
    when (io.redirect.valid) {  // redirect happens
        when (io.brUpdate.b2.mispredict) {  // redirect is caused by a misprediction
            val new_cfi_idx = io.brUpdate.b2.uop.pcLowBits(log2Ceil(fetchWidth) - 1 + log2Ceil(instrBytes), log2Ceil(instrBytes))
            new_entry.cfiIdx.valid    := true.B
            new_entry.cfiIdx.bits     := new_cfi_idx
            new_entry.cfiTaken        := io.brUpdate.b2.taken
            new_entry.cfiMispredicted := true.B
            new_entry.cfiIsCall       := old_entry.cfiIsCall && old_entry.cfiIdx.bits === new_cfi_idx
            new_entry.cfiIsRet        := old_entry.cfiIsRet  && old_entry.cfiIdx.bits === new_cfi_idx
        }

        rasUpdate    := true.B
        rasUpdatepc  := old_entry.rasTop
        rasUpdateIdx := old_entry.rasIdx
    } .elsewhen (RegNext(io.redirect.valid)) {
        previousEntry := RegNext(new_entry)
        previousgHist := bpdgHist
        previouspc    := bpdpc

        ram(RegNext(io.redirect.bits)) := RegNext(new_entry)
    }
//-------------------------------------------------------------
// core read ports
    for (i <- 0 until 2) {
        val idx = io.getFtqpc(i).ftqIdx
        val nextIdx = WrapInc(idx, numFTQEntries)
        val nextIsEnq = (nextIdx === bpu_ptr) && io.enq.fire
        val nextpc = Mux(nextIsEnq, io.enq.bits.pc, pcs(nextIdx))
        val getEntry = ram(idx)
        io.getFtqpc(i).entry       := RegNext(getEntry)
        if (i == 1) {
            gHist(1).io.raddr      := idx
            io.getFtqpc(i).gHist   := gHist(1).io.rdata.head
        } else {
            io.getFtqpc(i).gHist   := DontCare
        }

        io.getFtqpc(i).pc      := RegNext(pcs(idx))
        io.getFtqpc(i).nextpc  := RegNext(nextpc)
        io.getFtqpc(i).nextVal := RegNext(nextIdx =/= bpu_ptr || nextIsEnq)
        io.getFtqpc(i).compc   := RegNext(pcs(Mux(io.deq.valid, io.deq.bits, commited_ptr)))
    }
}
