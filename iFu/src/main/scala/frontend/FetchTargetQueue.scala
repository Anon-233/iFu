package iFu.frontend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.util._
import backend.memSystem.BrUpdateInfo
import iFu.frontend.FrontendUtils._
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

    val startBank       = UInt(1.W)
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
    /*--------------------------*/
    val numFTQEntries = frontendParams.numFTQEntries
    val numRasEntries = frontendParams.bpdParams.numRasEntries
    val nBanks        = frontendParams.iCacheParams.nBanks
    val localHistoryLength = frontendParams.bpdParams.localHistoryLength
    val bankBytes     = frontendParams.iCacheParams.bankBytes
    val fetchWidth    = frontendParams.fetchWidth
    private val idxSz = log2Ceil(numRasEntries)
    /*--------------------------*/

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

    val bpdPtr = RegInit(0.U(idxSz.W))  // 尚未提交的指令的ftqIdx（对bpd更新的提交）
    val deqPtr = RegInit(0.U(idxSz.W))  // 已经提交的指令的ftqIdx（rob的提交）
    val enqPtr = RegInit(1.U(idxSz.W))  // 下一个入队的指令的ftqIdx

    // 标记队列是否已满
    val full = (
        (WrapInc(enqPtr, numFTQEntries) === bpdPtr) ||
        (WrapInc(WrapInc(enqPtr, numFTQEntries), numFTQEntries) === bpdPtr)
    )   // why need at least 2 empty entries?

    val pcs   = Reg(Vec(numFTQEntries, UInt(vaddrBits.W)))
    val meta  = SyncReadMem(numFTQEntries, Vec(nBanks, new PredictionMeta))
    val ram   = Reg(Vec(numFTQEntries, new FTQBundle))
    val gHist = Seq.fill(nBanks) { SyncReadMem(numFTQEntries, new GlobalHistory) }

    val previousgHist = RegInit((0.U).asTypeOf(new GlobalHistory))
    val previousEntry = RegInit((0.U).asTypeOf(new FTQBundle))
    val previouspc    = RegInit(0.U(vaddrBits.W))

    // 入队操作
    when (io.enq.fire) {
        pcs(enqPtr)           := io.enq.bits.pc

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
        newEntry.startBank       := bank(io.enq.bits.pc)

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
        gHist.map(g => g.write(enqPtr, newgHist))
        meta.write(enqPtr, io.enq.bits.bpdMeta)
        ram(enqPtr) := newEntry

        // 每次入队更新previous的保存内容
        previouspc    := io.enq.bits.pc
        previousEntry := newEntry
        previousgHist := newgHist

        enqPtr := WrapInc(enqPtr, numFTQEntries)
    }
    io.enqIdx := enqPtr

    when (io.deq.valid) { deqPtr := io.deq.bits }

    // 接下来的代码是为了准备 bpdUpdate 的信息，这包括 RAS 和 BPD
    val rasUpdate    = WireInit(false.B)
    val rasUpdatepc  = WireInit(0.U(vaddrBits.W))
    val rasUpdateIdx = WireInit(0.U(log2Ceil(numRasEntries).W))

    io.rasUpdate    := RegNext(rasUpdate)
    io.rasUpdatepc  := RegNext(rasUpdatepc)
    io.rasUpdateIdx := RegNext(rasUpdateIdx)

    val bpdUpdateMispredict = RegInit(false.B)
    val bpdUpdateRepair     = RegInit(false.B)
    val bpdRepairIdx        = Reg(UInt(log2Ceil(numFTQEntries).W))
    val bpdRepairpc         = Reg(UInt(vaddrBits.W))
    val bpdEndIdx           = Reg(UInt(log2Ceil(numFTQEntries).W))
    val bpdEntry            = RegNext(ram(bpdIdx))

    val bpdIdx    = Mux(io.redirect.valid,                      io.redirect.bits,
                    Mux(bpdUpdateRepair || bpdUpdateMispredict, bpdRepairIdx,
                                                                bpdPtr))
    val bpdgHist  = gHist(0).read(bpdIdx, true.B)
    val bpdMeta   = meta.read(bpdIdx, true.B)
    val bpdpc     = RegNext(pcs(bpdIdx))
    val bpdTarget = RegNext(pcs(WrapInc(bpdIdx, numFTQEntries)))

    // 如果发生了EX阶段分支预测错误，同一个周期传回来几个信号，包括io.redirect.valid和io.brUpdate.b2.mispredict
    // 这里有点像状态机,首先是重定向->分支预测错误->分支预测错误修复->分支预测错误修复完成
    // 结合最下面的代码,在重定向周期,会做两件事,首先是enqPtr指向重定向的位置,相当于清空预测错误之后的信息记录
    // 以及
    when (io.redirect.valid) {  // io.redirect.valid 与 io.brUpdate.b2.mispredict 在同一周期
        bpdUpdateMispredict := false.B
        bpdUpdateRepair     := false.B
    } .elsewhen (RegNext(io.brUpdate.b2.mispredict)) {
        bpdUpdateMispredict := true.B
        bpdRepairIdx        := RegNext(io.brUpdate.b2.uop.ftq_idx)
        bpdEndIdx           := RegNext(enqPtr)
    } .elsewhen (bpdUpdateMispredict) {
        bpdUpdateMispredict := false.B
        bpdUpdateRepair     := true.B
        bpdRepairIdx        := WrapInc(bpdRepairIdx, numFTQEntries)
    } .elsewhen (bpdUpdateRepair && RegNext(bpdUpdateMispredict)) {
        bpdRepairpc         := bpdpc
        bpdRepairIdx        := WrapInc(bpdRepairIdx, numFTQEntries)
    } .elsewhen (bpdUpdateRepair) {
        bpdRepairIdx        := WrapInc(bpdRepairIdx, numFTQEntries)
        when (
            WrapInc(bpdRepairIdx, numFTQEntries) === bpdEndIdx ||
            bpdpc === bpdRepairpc
        ) {
            bpdUpdateRepair := false.B
        }
    }

    val doMispredictUpdate = bpdUpdateMispredict
    val doRepairUpdate     = bpdUpdateRepair
    val doCommitUpdate     = (
        !bpdUpdateMispredict && !bpdUpdateRepair && bpdPtr =/= deqPtr &&
        enqPtr =/= WrapInc(bpdPtr, numFTQEntries) && !io.brUpdate.b2.mispredict &&
        !io.redirect.valid && !RegNext(io.redirect.valid)
    )

    // 只要有更新指示，就根据读取到的信息，准备好更新信息并输出

    // This register avoids a spurious bpd update on the first fetch packet
    val firstEmpty = RegInit(true.B)

    io.bpdUpdate.valid := false.B
    io.bpdUpdate.bits  := DontCare

    when (RegNext(doCommitUpdate || doRepairUpdate || doMispredictUpdate)) {
        val cfiIdx = bpdEntry.cfiIdx.bits
        val validRepair = bpdpc =/= bpdRepairpc

        io.bpdUpdate.valid := (
            !firstEmpty &&
            (bpdEntry.cfiIdx.valid || bpdEntry.brMask =/= 0.U) &&
            !(RegNext(doRepairUpdate) && !validRepair)
        )
        io.bpdUpdate.bits.isMispredictUpdate := RegNext(doMispredictUpdate)
        io.bpdUpdate.bits.isRepairUpdate     := RegNext(doRepairUpdate)
        io.bpdUpdate.bits.pc                 := bpdpc
        io.bpdUpdate.bits.btbMispredicts     := 0.U
        io.bpdUpdate.bits.brMask             := Mux(
            bpdEntry.cfiIdx.valid,
                MaskLower(UIntToOH(cfiIdx)) & bpdEntry.brMask,
                bpdEntry.brMask
        )
        io.bpdUpdate.bits.cfiIdx             := bpdEntry.cfiIdx
        io.bpdUpdate.bits.cfiMispredicted    := bpdEntry.cfiMispredicted
        io.bpdUpdate.bits.cfiTaken           := bpdEntry.cfiTaken
        io.bpdUpdate.bits.target             := bpdTarget
        io.bpdUpdate.bits.cfiIsBr            := bpdEntry.brMask(cfiIdx)
        io.bpdUpdate.bits.cfiIsJal           := bpdEntry.cfiType === CFI_JAL || bpdEntry.cfiType === CFI_JALR
        io.bpdUpdate.bits.gHist              := bpdgHist
        io.bpdUpdate.bits.meta               := bpdMeta

        firstEmpty := false.B
    }

    when (doCommitUpdate) {
        bpdPtr := WrapInc(bpdPtr, numFTQEntries)
    }

    io.enq.ready := RegNext(!full || doCommitUpdate)

    val redirectIdx = io.redirect.bits
    val redirectEntry = ram(redirectIdx)
    val redirectNewEntry = WireInit(redirectEntry)

    when (io.redirect.valid) {
        enqPtr := WrapInc(io.redirect.bits, numFTQEntries)
        when (io.brUpdate.b2.mispredict) {
            val newCfiIdx = (
                io.brUpdate.b2.uop.pc_lob ^
                Mux(redirectEntry.startBank === 1.U, (1.U << log2Ceil(bankBytes)).asUInt, 0.U)
            )(log2Ceil(fetchWidth) + 1, 2)
            redirectNewEntry.cfiIdx.valid    := true.B
            redirectNewEntry.cfiIdx.bits     := newCfiIdx
            redirectNewEntry.cfiMispredicted := true.B
            redirectNewEntry.cfiTaken        := io.brUpdate.b2.taken
            redirectNewEntry.cfiIsCall       := redirectEntry.cfiIsCall && redirectEntry.cfiIdx.bits === newCfiIdx
            redirectNewEntry.cfiIsRet        := redirectEntry.cfiIsRet  && redirectEntry.cfiIdx.bits === newCfiIdx
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
        val nextIdx = WrapInc(idx, numFTQEntries)
        val nextIsEnq = (nextIdx === enqPtr) && io.enq.fire
        val nextpc = Mux(nextIsEnq, io.enq.bits.pc, pcs(nextIdx))
        val getEntry = ram(idx)
        val nextEntry = ram(nextIdx)
        io.getFtqpc(i).entry       := RegNext(getEntry)
        if (i == 1) {
            io.getFtqpc(i).gHist   := gHist(1).read(idx, true.B)
        } else {
            io.getFtqpc(i).gHist   := DontCare
            io.getFtqpc(i).pc      := RegNext(pcs(idx))
            io.getFtqpc(i).nextpc  := RegNext(nextpc)
            io.getFtqpc(i).nextVal := RegNext(nextIdx =/= enqPtr || nextIsEnq)
            io.getFtqpc(i).compc   := RegNext(pcs(Mux(io.deq.valid, io.deq.bits, deqPtr)))
        }
    }
}
