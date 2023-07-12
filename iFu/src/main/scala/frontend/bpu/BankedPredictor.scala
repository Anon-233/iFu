package iFu

import chisel3._
import chisel3.util._
import iFu.frontend.predictors._

val vaddrBits = 32
val bankWidth = 4
val fetchWidth = 8
val nBanks = 2
val localHistoryLength = 16
val fetchBytes = 32

def fetchIdx(addr: UInt) = addr >> log2Ceil(fetchBytes)

class PredictionInfo {
    val taken = Bool()

    val isBranch = Bool()

    val isJal = Bool()

    val predictedPc = UInt(vaddrBits.W)

}

class PredictionMeta{
    val bimMeta = new BimMeta
    val btbMeta = new BtbMeta
    val tageMeta = new TageMeta
    val ubtbMeta = new UbtbMeta
    val loopMeta = new LoopMeta
}

class BranchPredictionBundle{
    val PC = UInt(vaddrBits.W)
    val predInfos = Vec(fetchWidth, new PredictionInfo)
    val meta = Vec(nBanks,new PredictionMeta)
    val lhist = Vec(nBanks,UInt(localHistoryLength.W))
}

class UpdateInfo{
     // Indicates that this update is due to a speculated misprediction
    // Local predictors typically update themselves with speculative info
    // Global predictors only care about non-speculative updates
    val isMispredictUpdate = Bool()
    val isRepairUpdate = Bool()
    val btbMispredicts = UInt(fetchWidth.W)
    def isBtbMispredictUpdate = btbMispredicts =/= 0.U
    def isCommitUpdate = !(isMispredictUpdate || isRepairUpdate || isBtbMispredictUpdate)

    val PC            = UInt(vaddrBits.W)
    // Mask of instructions which are branches.
    // If these are not cfiIdx, then they were predicted not taken
    val brMask       = UInt(fetchWidth.W)
    // Which CFI was taken/mispredicted (if any)
    val cfiIdx       = Valid(UInt(log2Ceil(fetchWidth).W))
    // Was the cfi taken?
    val cfiTaken     = Bool()
    // Was the cfi mispredicted from the original prediction?
    val cfiMispredicted = Bool()
    // Was the cfi a br?
    val cfiIsBr     = Bool()
    // Was the cfi a jal/jalr?
    val cfiIsJal  = Bool()
    // Was the cfi a jalr
    val cfiIsJalr = Bool()
    //val cfi_is_ret  = Bool()

    val ghist = new GlobalHistory
    val lhist = Vec(nBanks, UInt(localHistoryLength.W))


    // What did this CFI jump to?
    val target        = UInt(vaddrBitsExtended.W)

    val meta          = Vec(nBanks, new PredictionMeta)
}


class BankedPredictorRequest
{
    val PC = Uint(vaddrBits)

    val ghist = new GlobalHistory
}

class BankedPredictorResponse
{
    val f1 = Vec(bankWidth, new PredictionInfo)
    val f2 = Vec(bankWidth, new PredictionInfo)
    val f3 = Vec(bankWidth, new PredictionInfo)
}

class BankedPredictor
{
    val io  = IO(new Bundle{
        val f0valid = Bool()
        val f0PC = Input(UInt(vaddrBits.W))
        val f0mask = Input(Uint(bankWidth.W))
        
        val f1ghist = Input(Uint(globalHistoryLength.W))
        val f1lhist = Input(Vec(nBanks, UInt(localHistoryLength.W)))

        val resp = Output(new BankedPredictorResponse)
        
        val f3meta = Output
        val f3fire = Input(Bool())

        val update = Input(Valid(new UpdateInfo))

    })

    io.resp := 0.U.asTypeOf(new BankedPredictorResponse)
    io.f3meta := 0.U

    val s0idx = fetchIdx(io.f0PC)
    val s1idx = RegNext(s0_idx)
    val s2idx = RegNext(s1_idx)
    val s3idx = RegNext(s2_idx)

    val s0valid = io.f0valid
    val s1valid = RegNext(s0valid)
    val s2valid = RegNext(s1valid)
    val s3valid = RegNext(s2valid)

    val s0mask = io.f0mask
    val s1mask = RegNext(s0mask)
    val s2mask = RegNext(s1mask)
    val s3mask = RegNext(s2mask)

    val s0PC = io.f0PC
    val s1PC = RegNext(s0PC)

    val s0update = io.update
    val s0updateIdx = fetchIdx(io.update.bits.PC)
    val s0updateValid = io.update.valid

    val s1update = RegNext(s0update)
    val s1updateIdx = RegNext(s0updateIdx)
    val s1updateValid = RegNext(s0updateValid)
    
}




