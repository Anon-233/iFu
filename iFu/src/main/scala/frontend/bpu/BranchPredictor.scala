package iFu.frontend

import chisel3._
import chisel3.util._
import iFu.common._
import iFu.frontend.FrontendUtils._


class BranchPredictionRequest extends CoreBundle
{
  val pc    = UInt(vaddrBits.W)
  val gHist = new GlobalHistory
}

class BranchPredictor extends Module
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

  // val bankedPredictors = Seq(nBanks, Module(ne0dw BankedPredictor))
  val bankedPredictors = (0 until nBanks).map( i => Module(new BankedPredictor))



    require(nBanks == 2)

    when (bank(io.f0req.bits.pc) === 0.U) {

      bankedPredictors(0).io.f0valid := io.f0req.valid
      bankedPredictors(0).io.f0pc    := bankAlign(io.f0req.bits.pc)
      bankedPredictors(0).io.f0mask  := fetchMask(io.f0req.bits.pc)

      bankedPredictors(1).io.f0valid := io.f0req.valid
      bankedPredictors(1).io.f0pc    := nextBank(io.f0req.bits.pc)
      bankedPredictors(1).io.f0mask  := ~(0.U(bankWidth.W))
    } .otherwise {


      bankedPredictors(0).io.f0valid := io.f0req.valid && !mayNotBeDualBanked(io.f0req.bits.pc)
      bankedPredictors(0).io.f0pc    := nextBank(io.f0req.bits.pc)
      bankedPredictors(0).io.f0mask  := ~(0.U(bankWidth.W))

      bankedPredictors(1).io.f0valid := io.f0req.valid
      bankedPredictors(1).io.f0pc    := bankAlign(io.f0req.bits.pc)
      bankedPredictors(1).io.f0mask  := fetchMask(io.f0req.bits.pc)
    }
    when (RegNext(bank(io.f0req.bits.pc) === 0.U)) {
      bankedPredictors(0).io.f1ghist  := RegNext(io.f0req.bits.gHist.histories(0))
      bankedPredictors(1).io.f1ghist  := RegNext(io.f0req.bits.gHist.histories(1))
    } .otherwise {
      bankedPredictors(0).io.f1ghist  := RegNext(io.f0req.bits.gHist.histories(1))
      bankedPredictors(1).io.f1ghist  := RegNext(io.f0req.bits.gHist.histories(0))
    }


  
    require(nBanks == 2)
    val b0fire = io.f3fire && RegNext(RegNext(RegNext(bankedPredictors(0).io.f0valid)))
    val b1fire = io.f3fire && RegNext(RegNext(RegNext(bankedPredictors(1).io.f0valid)))
    bankedPredictors(0).io.f3fire := b0fire
    bankedPredictors(1).io.f3fire := b1fire




    // The branch prediction metadata is stored un-shuffled
    io.resp.f3.meta(0)    := bankedPredictors(0).io.f3meta
    io.resp.f3.meta(1)    := bankedPredictors(1).io.f3meta


    when (bank(io.resp.f1.pc) === 0.U) {
      for (i <- 0 until bankWidth) {
        io.resp.f1.predInfos(i)           := bankedPredictors(0).io.resp.f1(i)
        io.resp.f1.predInfos(i+bankWidth) := bankedPredictors(1).io.resp.f1(i)
      }
    } .otherwise {
      for (i <- 0 until bankWidth) {
        io.resp.f1.predInfos(i)           := bankedPredictors(1).io.resp.f1(i)
        io.resp.f1.predInfos(i+bankWidth) := bankedPredictors(0).io.resp.f1(i)
      }
    }

    when (bank(io.resp.f2.pc) === 0.U) {
      for (i <- 0 until bankWidth) {
        io.resp.f2.predInfos(i)           := bankedPredictors(0).io.resp.f2(i)
        io.resp.f2.predInfos(i+bankWidth) := bankedPredictors(1).io.resp.f2(i)
      }
    } .otherwise {
      for (i <- 0 until bankWidth) {
        io.resp.f2.predInfos(i)           := bankedPredictors(1).io.resp.f2(i)
        io.resp.f2.predInfos(i+bankWidth) := bankedPredictors(0).io.resp.f2(i)
      }
    }

    when (bank(io.resp.f3.pc) === 0.U) {
      for (i <- 0 until bankWidth) {
        io.resp.f3.predInfos(i)           := bankedPredictors(0).io.resp.f3(i)
        io.resp.f3.predInfos(i+bankWidth) := bankedPredictors(1).io.resp.f3(i)
      }
    } .otherwise {
      for (i <- 0 until bankWidth) {
        io.resp.f3.predInfos(i)           := bankedPredictors(1).io.resp.f3(i)
        io.resp.f3.predInfos(i+bankWidth) := bankedPredictors(0).io.resp.f3(i)
      }
    }
  

  io.resp.f1.pc := RegNext(io.f0req.bits.pc)
  io.resp.f2.pc := RegNext(io.resp.f1.pc)
  io.resp.f3.pc := RegNext(io.resp.f2.pc)

  // We don't care about meta from the f1 and f2 resps
  // Use the meta from the latest resp
  io.resp.f1.meta := DontCare
  io.resp.f2.meta := DontCare


  for (i <- 0 until nBanks) {
    bankedPredictors(i).io.update.bits.isMispredictUpdate := io.update.bits.isMispredictUpdate
    bankedPredictors(i).io.update.bits.isRepairUpdate     := io.update.bits.isRepairUpdate

    bankedPredictors(i).io.update.bits.meta             := io.update.bits.meta(i)
    bankedPredictors(i).io.update.bits.cfiIdx.bits     := io.update.bits.cfiIdx.bits
    bankedPredictors(i).io.update.bits.cfiTaken        := io.update.bits.cfiTaken
    bankedPredictors(i).io.update.bits.cfiMispredicted := io.update.bits.cfiMispredicted
    bankedPredictors(i).io.update.bits.cfiIsBr        := io.update.bits.cfiIsBr
    bankedPredictors(i).io.update.bits.cfiIsJal       := io.update.bits.cfiIsJal
    bankedPredictors(i).io.update.bits.cfiIsJalr      := io.update.bits.cfiIsJalr
    bankedPredictors(i).io.update.bits.target           := io.update.bits.target

  }

 
    require(nBanks == 2)
    // Split the single update bundle for the fetchpacket into two updates
    // 1 for each bank.

    when (bank(io.update.bits.pc) === 0.U) {
      val b1UpdateValid = io.update.valid &&
        (!io.update.bits.cfiIdx.valid || io.update.bits.cfiIdx.bits >= bankWidth.U)


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

      bankedPredictors(0).io.update.bits.gHist := io.update.bits.gHist.histories(0)
      bankedPredictors(1).io.update.bits.gHist := io.update.bits.gHist.histories(1)
    } .otherwise {
      val b0UpdateValid = io.update.valid && !mayNotBeDualBanked(io.update.bits.pc) &&
        (!io.update.bits.cfiIdx.valid || io.update.bits.cfiIdx.bits >= bankWidth.U)


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

      bankedPredictors(1).io.update.bits.gHist := io.update.bits.gHist.histories(0)
      bankedPredictors(0).io.update.bits.gHist := io.update.bits.gHist.histories(1)
    }

  

  when (io.update.valid) {
    when (io.update.bits.cfiIsBr && io.update.bits.cfiIdx.valid) {
      assert(io.update.bits.brMask(io.update.bits.cfiIdx.bits))
    }
  }
}

