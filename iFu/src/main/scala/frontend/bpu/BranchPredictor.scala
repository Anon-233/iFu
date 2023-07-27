package iFu.frontend

import chisel3._
import chisel3.util._


class BranchPredictionRequest(implicit p: Parameters) extends BoomBundle()(p)
{
  val pc    = UInt(vaddrBitsExtended.W)
  val ghist = new GlobalHistory
}

class BranchPredictor(implicit p: Parameters) extends Module()(p)
 with HasBPUParameters
{
  val io = IO(new Bundle {

    // Requests and responses
    val f0req = Flipped(Valid(new BranchPredictionRequest))

    val resp = Output(new Bundle {
      val f1 = new BranchPredictionBundle
      val f2 = new BranchPredictionBundle
      val f3 = new BranchPredictionBundle
    })

    val f3fire = Input(Bool())

    // Update
    val update = Input(Valid(new BranchPredictionUpdate))

  })

  val bpdStr = new StringBuilder
  bpdStr.append(BoomCoreStringPrefix("==Branch Predictor Memory Sizes==\n"))
  val bankedPredictors = (0 until nBanks) map ( b => {
    val m = Module(new BankedPredictor)
  })

  val bankedLhistProviders = Seq.fill(nBanks) { Module(if (localHistoryNSets > 0) new LocalBranchPredictorBank else new NullLocalBranchPredictorBank) }


  {
    require(nBanks == 2)

    bankedPredictors(0).io.f1lhist := bankedLhistProviders(0).io.f1lhist
    bankedPredictors(1).io.f1lhist := bankedLhistProviders(1).io.f1lhist

    when (bank(io.f0req.bits.pc) === 0.U) {
      bankedLhistProviders(0).io.f0valid := io.f0req.valid
      bankedLhistProviders(0).io.f0pc    := bankAlign(io.f0req.bits.pc)

      bankedLhistProviders(1).io.f0valid := io.f0req.valid
      bankedLhistProviders(1).io.f0pc    := nextBank(io.f0req.bits.pc)

      bankedPredictors(0).io.f0valid := io.f0req.valid
      bankedPredictors(0).io.f0pc    := bankAlign(io.f0req.bits.pc)
      bankedPredictors(0).io.f0mask  := fetchMask(io.f0req.bits.pc)

      bankedPredictors(1).io.f0valid := io.f0req.valid
      bankedPredictors(1).io.f0pc    := nextBank(io.f0req.bits.pc)
      bankedPredictors(1).io.f0mask  := ~(0.U(bankWidth.W))
    } .otherwise {
      bankedLhistProviders(0).io.f0valid := io.f0req.valid && !mayNotBeDualBanked(io.f0req.bits.pc)
      bankedLhistProviders(0).io.f0pc    := nextBank(io.f0req.bits.pc)

      bankedLhistProviders(1).io.f0valid := io.f0req.valid
      bankedLhistProviders(1).io.f0pc    := bankAlign(io.f0req.bits.pc)

      bankedPredictors(0).io.f0valid := io.f0req.valid && !mayNotBeDualBanked(io.f0req.bits.pc)
      bankedPredictors(0).io.f0pc    := nextBank(io.f0req.bits.pc)
      bankedPredictors(0).io.f0mask  := ~(0.U(bankWidth.W))

      bankedPredictors(1).io.f0valid := io.f0req.valid
      bankedPredictors(1).io.f0pc    := bankAlign(io.f0req.bits.pc)
      bankedPredictors(1).io.f0mask  := fetchMask(io.f0req.bits.pc)
    }
    when (RegNext(bank(io.f0req.bits.pc) === 0.U)) {
      bankedPredictors(0).io.f1ghist  := RegNext(io.f0req.bits.ghist.histories(0))
      bankedPredictors(1).io.f1ghist  := RegNext(io.f0req.bits.ghist.histories(1))
    } .otherwise {
      bankedPredictors(0).io.f1ghist  := RegNext(io.f0req.bits.ghist.histories(1))
      bankedPredictors(1).io.f1ghist  := RegNext(io.f0req.bits.ghist.histories(0))
    }
  }


  for (i <- 0 until nBanks) {
    bankedLhistProviders(i).io.f3TakenBr := bankedPredictors(i).io.resp.f3.map ( p =>
      p.isBr && p.predictedPc.valid && p.taken
    ).reduce(_||_)
  }

  {
    require(nBanks == 2)
    val b0fire = io.f3fire && RegNext(RegNext(RegNext(bankedPredictors(0).io.f0valid)))
    val b1fire = io.f3fire && RegNext(RegNext(RegNext(bankedPredictors(1).io.f0valid)))
    bankedPredictors(0).io.f3fire := b0fire
    bankedPredictors(1).io.f3fire := b1fire

    bankedLhistProviders(0).io.f3fire := b0fire
    bankedLhistProviders(1).io.f3fire := b1fire



    // The branch prediction metadata is stored un-shuffled
    io.resp.f3.meta(0)    := bankedPredictors(0).io.f3meta
    io.resp.f3.meta(1)    := bankedPredictors(1).io.f3meta

    io.resp.f3.lhist(0)   := bankedLhistProviders(0).io.f3lhist
    io.resp.f3.lhist(1)   := bankedLhistProviders(1).io.f3lhist

    when (bank(io.resp.f1.pc) === 0.U) {
      for (i <- 0 until bankWidth) {
        io.resp.f1.preds(i)           := bankedPredictors(0).io.resp.f1(i)
        io.resp.f1.preds(i+bankWidth) := bankedPredictors(1).io.resp.f1(i)
      }
    } .otherwise {
      for (i <- 0 until bankWidth) {
        io.resp.f1.preds(i)           := bankedPredictors(1).io.resp.f1(i)
        io.resp.f1.preds(i+bankWidth) := bankedPredictors(0).io.resp.f1(i)
      }
    }

    when (bank(io.resp.f2.pc) === 0.U) {
      for (i <- 0 until bankWidth) {
        io.resp.f2.preds(i)           := bankedPredictors(0).io.resp.f2(i)
        io.resp.f2.preds(i+bankWidth) := bankedPredictors(1).io.resp.f2(i)
      }
    } .otherwise {
      for (i <- 0 until bankWidth) {
        io.resp.f2.preds(i)           := bankedPredictors(1).io.resp.f2(i)
        io.resp.f2.preds(i+bankWidth) := bankedPredictors(0).io.resp.f2(i)
      }
    }

    when (bank(io.resp.f3.pc) === 0.U) {
      for (i <- 0 until bankWidth) {
        io.resp.f3.preds(i)           := bankedPredictors(0).io.resp.f3(i)
        io.resp.f3.preds(i+bankWidth) := bankedPredictors(1).io.resp.f3(i)
      }
    } .otherwise {
      for (i <- 0 until bankWidth) {
        io.resp.f3.preds(i)           := bankedPredictors(1).io.resp.f3(i)
        io.resp.f3.preds(i+bankWidth) := bankedPredictors(0).io.resp.f3(i)
      }
    }
  }

  io.resp.f1.pc := RegNext(io.f0req.bits.pc)
  io.resp.f2.pc := RegNext(io.resp.f1.pc)
  io.resp.f3.pc := RegNext(io.resp.f2.pc)

  // We don't care about meta from the f1 and f2 resps
  // Use the meta from the latest resp
  io.resp.f1.meta := DontCare
  io.resp.f2.meta := DontCare
  io.resp.f1.lhist := DontCare
  io.resp.f2.lhist := DontCare


  for (i <- 0 until nBanks) {
    bankedPredictors(i).io.update.bits.isMispredictUpdate := io.update.bits.isMispredictUpdate
    bankedPredictors(i).io.update.bits.isRepairUpdate     := io.update.bits.isRepairUpdate

    bankedPredictors(i).io.update.bits.meta             := io.update.bits.meta(i)
    bankedPredictors(i).io.update.bits.lhist            := io.update.bits.lhist(i)
    bankedPredictors(i).io.update.bits.cfiIdx.bits     := io.update.bits.cfiIdx.bits
    bankedPredictors(i).io.update.bits.cfiTaken        := io.update.bits.cfiTaken
    bankedPredictors(i).io.update.bits.cfiMispredicted := io.update.bits.cfiMispredicted
    bankedPredictors(i).io.update.bits.cfiIsBr        := io.update.bits.cfiIsBr
    bankedPredictors(i).io.update.bits.cfiIsJal       := io.update.bits.cfiIsJal
    bankedPredictors(i).io.update.bits.cfiIsJalr      := io.update.bits.cfiIsJalr
    bankedPredictors(i).io.update.bits.target           := io.update.bits.target

    bankedLhistProviders(i).io.update.mispredict := io.update.bits.isMispredictUpdate
    bankedLhistProviders(i).io.update.repair     := io.update.bits.isRepairUpdate
    bankedLhistProviders(i).io.update.lhist      := io.update.bits.lhist(i)
  }

 {
    require(nBanks == 2)
    // Split the single update bundle for the fetchpacket into two updates
    // 1 for each bank.

    when (bank(io.update.bits.pc) === 0.U) {
      val b1UpdateValid = io.update.valid &&
        (!io.update.bits.cfiIdx.valid || io.update.bits.cfiIdx.bits >= bankWidth.U)

      bankedLhistProviders(0).io.update.valid := io.update.valid && io.update.bits.brMask(bankWidth-1,0) =/= 0.U
      bankedLhistProviders(1).io.update.valid := b1UpdateValid && io.update.bits.brMask(fetchWidth-1,bankWidth) =/= 0.U

      bankedLhistProviders(0).io.update.pc := bankAlign(io.update.bits.pc)
      bankedLhistProviders(1).io.update.pc := nextBank(io.update.bits.pc)

      bankedPredictors(0).io.update.valid := io.update.valid
      bankedPredictors(1).io.update.valid := b1UpdateValid

      bankedPredictors(0).io.update.bits.pc := bankAlign(io.update.bits.pc)
      bankedPredictors(1).io.update.bits.pc := nextBank(io.update.bits.pc)

      bankedPredictors(0).io.update.bits.brMask := io.update.bits.brMask
      bankedPredictors(1).io.update.bits.brMask := io.update.bits.brMask >> bankWidth

      bankedPredictors(0).io.update.bits.btbMispredicts  := io.update.bits.btbMispredicts
      bankedPredictors(1).io.update.bits.btbMispredicts  := io.update.bits.btbMispredicts >> bankWidth

      bankedPredictors(0).io.update.bits.cfiIdx.valid := io.update.bits.cfiIdx.valid && io.update.bits.cfiIdx.bits < bankWidth.U
      bankedPredictors(1).io.update.bits.cfiIdx.valid := io.update.bits.cfiIdx.valid && io.update.bits.cfiIdx.bits >= bankWidth.U

      bankedPredictors(0).io.update.bits.ghist := io.update.bits.ghist.histories(0)
      bankedPredictors(1).io.update.bits.ghist := io.update.bits.ghist.histories(1)
    } .otherwise {
      val b0UpdateValid = io.update.valid && !mayNotBeDualBanked(io.update.bits.pc) &&
        (!io.update.bits.cfiIdx.valid || io.update.bits.cfiIdx.bits >= bankWidth.U)

      bankedLhistProviders(1).io.update.valid := io.update.valid && io.update.bits.brMask(bankWidth-1,0) =/= 0.U
      bankedLhistProviders(0).io.update.valid := b0UpdateValid && io.update.bits.brMask(fetchWidth-1,bankWidth) =/= 0.U

      bankedLhistProviders(1).io.update.pc := bankAlign(io.update.bits.pc)
      bankedLhistProviders(0).io.update.pc := nextBank(io.update.bits.pc)

      bankedPredictors(1).io.update.valid := io.update.valid
      bankedPredictors(0).io.update.valid := b0UpdateValid

      bankedPredictors(1).io.update.bits.pc := bankAlign(io.update.bits.pc)
      bankedPredictors(0).io.update.bits.pc := nextBank(io.update.bits.pc)

      bankedPredictors(1).io.update.bits.brMask := io.update.bits.brMask
      bankedPredictors(0).io.update.bits.brMask := io.update.bits.brMask >> bankWidth

      bankedPredictors(1).io.update.bits.btbMispredicts  := io.update.bits.btbMispredicts
      bankedPredictors(0).io.update.bits.btbMispredicts  := io.update.bits.btbMispredicts >> bankWidth

      bankedPredictors(1).io.update.bits.cfiIdx.valid := io.update.bits.cfiIdx.valid && io.update.bits.cfiIdx.bits < bankWidth.U
      bankedPredictors(0).io.update.bits.cfiIdx.valid := io.update.bits.cfiIdx.valid && io.update.bits.cfiIdx.bits >= bankWidth.U

      bankedPredictors(1).io.update.bits.ghist := io.update.bits.ghist.histories(0)
      bankedPredictors(0).io.update.bits.ghist := io.update.bits.ghist.histories(1)
    }

  }

  when (io.update.valid) {
    when (io.update.bits.cfiIsBr && io.update.bits.cfiIdx.valid) {
      assert(io.update.bits.brMask(io.update.bits.cfiIdx.bits))
    }
  }
}

