package iFu.frontend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.util._
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

    val ftqIdx = Input(UInt(log2Ceil(numFTQEntries).W))
    val pc     = Output(UInt(vaddrBits.W))
    val compc  = Output(UInt(vaddrBits.W))
    val entry  = Output(new FTQBundle)
    val gHist  = Output(new GlobalHistory)

    val nextVal = Output(Bool())
    val nextpc  = Output(UInt(vaddrBits.W))
}

class FetchTargetQueue extends CoreModule {
// ------------------------------------
    val numFTQEntries = frontendParams.numFTQEntries
    val numRasEntries = frontendParams.bpdParams.numRasEntries
    val nBanks        = frontendParams.iCacheParams.nBanks
    val bankBytes     = frontendParams.iCacheParams.bankBytes
    val fetchWidth    = frontendParams.fetchWidth
    val idxSz         = log2Ceil(numFTQEntries)
// ------------------------------------
    val io = IO(new Bundle {
        val enq    = Flipped(Decoupled(new FetchBundle))
        val enqIdx = Output(UInt(idxSz.W))

        // from rob commit
        val deq = Flipped(Valid(UInt(idxSz.W)))

        val getFtqpc = Vec(2, new GetPCFromFtqIO)

        // 预测错误指令所处的 ftqIdx
        val redirect = Input(Valid(UInt(idxSz.W)))

        // brUpdate 是后端传来的update分支预测信息
        val brUpdate = Input(new BrUpdateInfo)

        val bpdUpdate    = Output(Valid(new BranchPredictionUpdate))
        val rasUpdate    = Output(Bool())
        val rasUpdateIdx = Output(UInt(log2Ceil(numRasEntries).W))
        val rasUpdatepc  = Output(UInt(vaddrBits.W))
    })

    val pc_mem  = Reg(Vec(numFTQEntries, UInt(vaddrBits.W)))
    val meta    = SyncReadMem(numFTQEntries, Vec(nBanks, Vec(bankWidth, new PredictionMeta)))
    val entries = Reg(Vec(numFTQEntries, new FTQBundle))
    val gHist   = Seq.fill(2) { SyncReadMem(numFTQEntries, new GlobalHistory) }

    val bpu_ptr  = RegInit(0.U(idxSz.W))
    val comm_ptr = RegInit(0.U(idxSz.W))

    val first_empty = RegInit(true.B)

    val prev_pc    = RegInit(0.U(vaddrBits.W))
    val prev_entry = RegInit(0.U.asTypeOf(new FTQBundle))
    val prev_gHist = RegInit(0.U.asTypeOf(new GlobalHistory))

// ---------------------------------------------
//      enq logic
    when (io.enq.fire) {
        val enq_pc = io.enq.bits.pc

        val enq_entry = Wire(new FTQBundle)
        enq_entry.cfiIdx          := io.enq.bits.cfiIdx
        enq_entry.cfiTaken        := io.enq.bits.cfiIdx.valid
        enq_entry.cfiMispredicted := false.B
        enq_entry.cfiType         := io.enq.bits.cfiType
        enq_entry.cfiIsCall       := io.enq.bits.cfiIsCall
        enq_entry.cfiIsRet        := io.enq.bits.cfiIsRet
        enq_entry.rasTop          := io.enq.bits.rasTop
        enq_entry.rasIdx          := io.enq.bits.gHist.rasIdx
        enq_entry.brMask          := io.enq.bits.brMask & io.enq.bits.mask
        enq_entry.startBank       := bank(io.enq.bits.pc)

        val enq_gHist = Mux(
            io.enq.bits.gHist.currentSawBranchNotTaken,
            io.enq.bits.gHist,
            prev_gHist.update(
                prev_entry.brMask,
                prev_entry.cfiTaken,
                prev_entry.brMask(prev_entry.cfiIdx.bits),
                prev_entry.cfiIdx.bits,
                prev_entry.cfiIdx.valid,
                prev_pc,
                prev_entry.cfiIsCall,
                prev_entry.cfiIsRet
            )
        )

        pc_mem(bpu_ptr) := enq_pc
        meta.write(bpu_ptr, io.enq.bits.bpdMeta)
        entries(bpu_ptr) := enq_entry
        gHist.map(g => g.write(bpu_ptr, enq_gHist))

        prev_pc    := enq_pc
        prev_entry := enq_entry
        prev_gHist := enq_gHist

        bpu_ptr := WrapInc(bpu_ptr, numFTQEntries)
    }
    io.enqIdx    := bpu_ptr
    io.enq.ready := !(WrapInc(bpu_ptr, numFTQEntries) === comm_ptr)
// ---------------------------------------------

// ---------------------------------------------
//      deq logic
    when (io.deq.valid) {
        comm_ptr    := io.deq.bits
        first_empty := false.B
    }
// ---------------------------------------------

// ---------------------------------------------
//      bpu update logic
    val bpu_train_en = RegNext(io.deq.valid && !first_empty, false.B)
    val bpu_idx      = WrapDec(io.deq.bits, numFTQEntries)
    val bpu_pc       = RegNext(pc_mem(bpu_idx))
    val bpu_entry    = RegNext(entries(bpu_idx))
    val bpu_meta     = meta.read(bpu_idx, true.B)
    val bpu_gHist    = gHist(0).read(bpu_idx, true.B)
    val bpu_tgt      = RegNext(pc_mem(io.deq.bits))

    io.bpdUpdate.valid := bpu_train_en

    io.bpdUpdate.bits.isMispredictUpdate := false.B
    io.bpdUpdate.bits.isRepairUpdate     := false.B
    io.bpdUpdate.bits.pc                 := bpu_pc
    io.bpdUpdate.bits.btbMispredicts     := 0.U
    io.bpdUpdate.bits.brMask             := bpu_entry.brMask
    io.bpdUpdate.bits.cfiIdx             := bpu_entry.cfiIdx
    io.bpdUpdate.bits.cfiMispredicted    := bpu_entry.cfiMispredicted
    io.bpdUpdate.bits.cfiTaken           := bpu_entry.cfiTaken
    io.bpdUpdate.bits.target             := bpu_tgt
    io.bpdUpdate.bits.cfiIsBr            := bpu_entry.brMask(bpu_entry.cfiIdx.bits)
    io.bpdUpdate.bits.cfiIsJal           := bpu_entry.cfiType === CFI_JAL || bpu_entry.cfiType === CFI_JALR
    io.bpdUpdate.bits.gHist              := bpu_gHist
    io.bpdUpdate.bits.meta               := bpu_meta
// ---------------------------------------------

    val redirectIdx = io.redirect.bits
    val redirectEntry = entries(redirectIdx)
    val new_entry = WireInit(redirectEntry)

    val ras_update_valid = WireInit(false.B)
    val ras_update_pc    = WireInit(0.U(vaddrBits.W))
    val ras_update_idx   = WireInit(0.U(log2Ceil(numRasEntries).W))

    when (io.redirect.valid) {
        val curr_ptr = io.redirect.bits
        val next_ptr = WrapInc(io.redirect.bits, numFTQEntries)

        bpu_ptr := next_ptr

        when (io.brUpdate.b2.mispredict) {
            val cfi_idx = (
                io.brUpdate.b2.uop.pcLowBits ^ Mux(redirectEntry.startBank === 1.U, (1.U << log2Ceil(bankBytes)).asUInt, 0.U)
            )(log2Ceil(fetchWidth) + 1, 2)

            new_entry.cfiIdx.valid    := true.B
            new_entry.cfiIdx.bits     := cfi_idx
            new_entry.cfiMispredicted := true.B  // 是否有用存疑
            new_entry.cfiTaken        := io.brUpdate.b2.taken
            new_entry.cfiIsCall       := redirectEntry.cfiIsCall && redirectEntry.cfiIdx.bits === cfi_idx
            new_entry.cfiIsRet        := redirectEntry.cfiIsRet  && redirectEntry.cfiIdx.bits === cfi_idx
        }

        ras_update_valid := true.B
        ras_update_pc    := redirectEntry.rasTop
        ras_update_idx   := redirectEntry.rasIdx

        prev_pc    := pc_mem(curr_ptr)
        prev_entry := entries(curr_ptr)
        prev_gHist := gHist(0).read(curr_ptr, true.B)

        entries(io.redirect.bits) := new_entry
    }

    io.rasUpdate    := ras_update_valid
    io.rasUpdatepc  := ras_update_pc
    io.rasUpdateIdx := ras_update_idx

    for (i <- 0 until 2) {
        val idx         = io.getFtqpc(i).ftqIdx
        val next_idx    = WrapInc(idx, numFTQEntries)
        val next_is_enq = (next_idx === enqPtr) && io.enq.fire
        val next_pc     = Mux(next_is_enq, io.enq.bits.pc, pc_mem(next_idx))

        io.getFtqpc(i).entry := RegNext(entries(idx))
        if (i == 1) {
            io.getFtqpc(i).gHist := gHist(1).read(idx, true.B)
        } else {
            io.getFtqpc(i).gHist := DontCare
        }

        io.getFtqpc(i).pc      := RegNext(pc_mem(idx))
        io.getFtqpc(i).nextVal := RegNext(next_idx =/= bpu_ptr || next_is_enq)
        io.getFtqpc(i).nextpc  := RegNext(next_pc)
        io.getFtqpc(i).compc   := RegNext(pc_mem(Mux(io.deq.valid, io.deq.bits, comm_ptr)))
    }
}
