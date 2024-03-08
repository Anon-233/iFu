package iFu.frontend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.util._
import iFu.frontend.FrontendUtils._

class GlobalHistory extends CoreBundle{
    /*--------------------------*/
    val globalHistoryLength = frontendParams.bpdParams.globalHistoryLength
    val numRasEntries       = frontendParams.bpdParams.numRasEntries
    val fetchWidth          = frontendParams.fetchWidth
    val bankWidth           = frontendParams.bankWidth
    /*--------------------------*/
    val old_history = UInt((globalHistoryLength).W)
    val currentSawBranchNotTaken = Bool()
    val newSawBranchNotTaken = Bool()
    val newSawBranchTaken = Bool()

    val rasIdx = UInt(log2Ceil(numRasEntries).W)

    def histories(bank: Int): UInt = {
        if (bank == 0) {
            old_history
        } else {
            Mux(newSawBranchTaken,       (old_history << 1).asUInt | 1.U,
            Mux(newSawBranchNotTaken,   (old_history << 1).asUInt,
                                            old_history))
        }
    }

    def ===(other: GlobalHistory): Bool = {
        ((old_history === other.old_history) &&
         (newSawBranchNotTaken === other.newSawBranchNotTaken) &&
         (newSawBranchTaken === other.newSawBranchTaken))
    }

    def =/=(other: GlobalHistory): Bool = !(this === other)

    def update(
        branches: UInt, cfi_taken: Bool, cfi_is_br: Bool, cfi_idx: UInt,
        cfi_valid: Bool, addr: UInt, cfi_is_call: Bool, cfi_is_ret: Bool
    ): GlobalHistory = {
        // branches: 传进来的predinfo里面有效分支指令的mask
        // cfi_taken: 这里面确实存在taken的指令
        // cfi_is_br: 这条指令是branch
        // cfi_idx: 这条指令在fetchWidth中的位置
        // cfi_valid: 这条指令是有效的
        // addr: 这条指令的地址
        // cfi_is_call: 这条指令是call
        // cfi_is_ret: 这条指令是ret
        val cfi_idx_fixed = cfi_idx(log2Ceil(fetchWidth) - 1, 0)
        val cfi_idx_oh = UIntToOH(cfi_idx_fixed)
        val new_history = Wire(new GlobalHistory)
        val not_taken_branches = branches & Mux(cfi_valid,
            MaskLower(cfi_idx_oh) & (~Mux(cfi_is_br && cfi_taken, cfi_idx_oh, 0.U(fetchWidth.W))).asUInt,
            (~(0.U(fetchWidth.W))).asUInt
        )

        val cfi_in_bank_0 = cfi_valid && cfi_taken && cfi_idx_fixed < bankWidth.U
        val ignore_second_bank = cfi_in_bank_0 || isLastBankInBlock(addr)

        val first_bank_saw_not_taken = not_taken_branches(bankWidth - 1, 0) =/= 0.U || currentSawBranchNotTaken
        new_history.currentSawBranchNotTaken := false.B
        when (ignore_second_bank) {
            new_history.old_history := histories(1)
            new_history.newSawBranchNotTaken := first_bank_saw_not_taken
            new_history.newSawBranchTaken := cfi_is_br && cfi_in_bank_0
        } .otherwise {
            new_history.old_history :=
                Mux(cfi_is_br && cfi_in_bank_0, (histories(1) << 1).asUInt | 1.U,
                Mux(first_bank_saw_not_taken,   (histories(1) << 1).asUInt,
                                                histories(1)))
            new_history.newSawBranchNotTaken := not_taken_branches(fetchWidth - 1, bankWidth) =/= 0.U
            new_history.newSawBranchTaken := cfi_valid && cfi_taken && cfi_is_br && !cfi_in_bank_0
        }

        new_history.rasIdx :=
            Mux(cfi_valid && cfi_is_call,   WrapInc(rasIdx, numRasEntries),
            Mux(cfi_valid && cfi_is_ret,    WrapDec(rasIdx, numRasEntries),
                                            rasIdx))
        new_history
    }
}
