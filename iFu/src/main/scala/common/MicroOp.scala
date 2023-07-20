package iFu.common

import chisel3._
import chisel3.util._

class MicroOp extends CoreBundle with MicroOpCode {
    val pcLowBits = UInt(log2Ceil(frontendParams.iCacheParams.blockBytes).W)
    val instr = UInt(coreInstrBits.W)
    val uopc = UInt(UOPC_SZ)
    val ftqIdx = UInt(log2Ceil(frontendParams.numFTQEntries).W)
    val taken = Bool()

    val iqType = UInt(IQT_SZ.W)
    val fuCode = UInt(FUC_SZ.W)
    val ctrl = new CtrlSignals

    val iwState = UInt(2.W)
    val iw_p1_poisoned = Bool()
    val iw_p2_poisoned = Bool()

    val isBr = Bool()
    val isJal = Bool()
    val isJalr = Bool()
    val isSFB = Bool()

    val brMask = UInt(maxBrCount.W)
    val brTag = UInt(brTagSz.W)

    val ftqIdx = UInt(log2Ceil(ftqSz).W)

    val taken = Bool()

    val immPacked = UInt(/*TODO*/)

    val csrAddr = UInt(/*TODO*/)

    val robIdx = UInt(/*TODO*/)
    val ldqIdx = UInt(/*TODO*/)
    val stqIdx = UInt(/*TODO*/)
    // val rxqIdx = UInt(/*TODO*/) // ???

    val pdst = UInt(maxPregSz.W)
    val prs1 = UInt(maxPregSz.W)
    val prs2 = UInt(maxPregSz.W)
    val ppred = UInt(log2Ceil(ftqSz).W)

    val prs1_busy = Bool()
    val prs2_busy = Bool()
    val ppred_busy = Bool()
    
    val stale_pdst = UInt(maxPregSz.W)

    val exception = Bool()
    val excCause = UInt(/*TODO*/)

    val bypassable = Bool()

    val mem_cmd = UInt(/*TODO*/)
    val mem_size = UInt(/*TODO*/)
    val mem_signed = Bool()

    val is_fence = Bool()
    val is_fencei = Bool()
    val is_amo = Bool()

    val use_ldq = Bool()
    val use_stq = Bool()

    val is_sys_pc2epc = Bool()

    val is_unique = Bool()

    val flush_on_commit = Bool()

    def is_sfb_br = isBr && isSFB
    def is_sfb_shadow = isSFB && !isBr

    val ldst_is_rs1 = Bool()

    val ldst = UInt(lregSz.W)
    val lrs1 = UInt(lregSz.W)
    val lrs2 = UInt(lregSz.W)

    val ldst_val = Bool()
    val dst_rtype = UInt(/*TODO*/)
    val lrs1_rtype = UInt(/*TODO*/)
    val lrs2_rtype = UInt(/*TODO*/)

    val xcpt_pf_if = Bool()
    val xcpt_ae_if = Bool()
    val xcpt_ma_if = Bool()
    val bp_debug_if = Bool()
    val bp_xcpt_if = Bool()

    val debug_fsrc = UInt(/*TODO*/)
    val debug_tsrc = UInt(/*TODO*/)

    def allocate_brtag = (isBr && !isSFB) || isJalr
    def rf_wen = dst_rtype =/= RT_X
    def unsafe = use_ldq || (use_stq && !is_fence) || isBr || isJalr
    def fu_code_is(_fu: UInt) = (fuCode & _fu) =/= 0.U
}

class CtrlSignals extends Bundle {
    val br_type     = UInt(BR_N.getWidth.W)
    val op1_sel     = UInt(OP1_X.getWidth.W)
    val op2_sel     = UInt(OP2_X.getWidth.W)
    val imm_sel     = UInt(IS_X.getWidth.W)
    val op_fcn      = UInt((new freechips.rocketchip.rocket.ALUFN).SZ_ALU_FN.W)
    val fcn_dw      = Bool()
    val csr_cmd     = UInt(freechips.rocketchip.rocket.CSR.SZ.W)
    val is_load     = Bool()
    val is_sta      = Bool()
    val is_std      = Bool()
}
