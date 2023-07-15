package iFu.frontend

import chisel3._
import chisel3.util._

import scala.math.min

class GlobalHistory extends Bundle  with HasBPUParameters{
    val history = UInt(globalHistoryLength.W)

    val currentSawBranchNotTaken = Bool()

    val newSawBrannchNotTaken = Bool()
    val newSawBranchTaken = Bool()

    val rasIdx = UInt(log2Ceil(nRasEntries).W)

    def histories(bank : Int) = {
        require (nBanks == 2)
        if(bank == 0) history
        else {
            Mux( newSawBranchTaken    ,     history << 1 | 1.U,
            (Mux(newSawBrannchNotTaken   ,  history << 1 ,
                                            history)))
        }
    }

    def === (g : GlobalHistory): Bool = {
        (history === g.history) && 
        (newSawBrannchNotTaken === g.newSawBrannchNotTaken) &&
        (newSawBranchTaken === g.newSawBranchTaken) && (rasIdx === g.rasIdx)
    }

    def =/= (g : GlobalHistory): Bool = !(this === g)

    def update (branches: UInt , cfiTaken : Bool , cfiIsBr : Bool ,
    cfiIdx : UInt , cfiValid : Bool , addr : UInt ,
    cfiIsCall : Bool , cfiIsRet : Bool ):GlobalHistory = {

        val cfiIdxFixed = cfiIdx(log2Ceil(fetchWidth)-1,0)
        val cfiIdxOH = UIntToOH(cfiIdxFixed)
        val newHistory = Wire(new GlobalHistory)

        // 这个信号记录了未发生跳转的分支
        val notTakenBranches = branches & 
                            Mux(cfiValid,
                                MaskLower(cfiIdxOH) & ~Mux(cfiIsBr && cfiTaken , cfiIdxOH, 0.U(fetchWidth.W)),
                                ~(0.U(fetchWidth.W))
                                    )
        
        require(nBanks == 2)
        val base = histories(1)
        val cfiInBank0 = cfiValid && cfiTaken && (cfiIdxFixed < bankWidth.U)
        val ignoreSecondBank = cfiInBank0 || mayNotBeDualBanked(addr)
        val firstBankeSawNotTaken = notTakenBranches(bankWidth-1,0).orR || currentSawBranchNotTaken

        newHistory.currentSawBranchNotTaken :=false.B

        when(ignoreSecondBank){

        }.otherwise{
            newHistory.history := Mux(cfiIsBr && cfiInBank0  , histories(1) << 1 | 1.U,
                                  Mux(firstBankeSawNotTaken , histories(1) << 1,
                                                            histories(1)))
            newHistory.newSawBrannchNotTaken := notTakenBranches(2*bankWidth-1,bankWidth).orR
            newHistory.newSawBranchTaken := cfiValid && cfiTaken && cfiIsBr && !cfiInBank0
        }

        newHistory.rasIdx := Mux(cfiValid && cfiIsCall, WrapInc(rasIdx, nRasEntries.asUInt),
                                Mux(cfiValid && cfiIsRet , WrapDec(rasIdx, nRasEntries), rasIdx))
        
        
        newHistory
    }

}