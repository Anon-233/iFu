package iFu.common

import chisel3._
import chisel3.util._

import iFu.backend.AluFuncCode
import iFu.common.Consts._

class MicroOp extends CoreBundle {
    // ---------------------------------------------------------
    val numFTQEntries: Int   = frontendParams.numFTQEntries
    val iCacheLineBytes: Int = frontendParams.iCacheParams.lineBytes
    val robAddrSz: Int       = robParameters.robAddrSz
    val ldqAddrSz: Int       = lsuParameters.ldqAddrSz
    val stqAddrSz: Int       = lsuParameters.stqAddrSz
    // ---------------------------------------------------------
    val pcLowBits: UInt = UInt(log2Ceil(iCacheLineBytes).W)
    val instr: UInt     = UInt(coreInstrBits.W)
    val uopc: UInt      = UInt(UOPC_SZ.W)
    val iqType: UInt    = UInt(IQT_SZ.W)
    val fuCode: UInt    = UInt(FUC_SZ.W)

    val ftqIdx: UInt = UInt(log2Ceil(frontendParams.numFTQEntries).W)

    val isBr: Bool   = Bool()
    val isJal: Bool  = Bool()
    val isJalr: Bool = Bool()
    val isSFB: Bool  = Bool()
    val taken: Bool  = Bool()

    val brMask: UInt = UInt(maxBrCount.W)
    val brTag: UInt  = UInt(brTagSz.W)

    val ldst_is_rs1: Bool = Bool()
    val ldst: UInt        = UInt(lregSz.W)
    val lrs1: UInt        = UInt(lregSz.W)
    val lrs2: UInt        = UInt(lregSz.W)
    val ldst_val: Bool    = Bool()
    val dst_rtype: UInt   = UInt(RT_X.getWidth.W)
    val lrs1_rtype: UInt  = UInt(RT_X.getWidth.W)
    val lrs2_rtype: UInt  = UInt(RT_X.getWidth.W)
    val pdst: UInt       = UInt(pregSz.W)
    val prs1: UInt       = UInt(pregSz.W)
    val prs2: UInt       = UInt(pregSz.W)
    val ppred: UInt      = UInt(log2Ceil(numFTQEntries).W)
    val stale_pdst: UInt = UInt(pregSz.W)

    val bypassable: Bool = Bool()

    val immPacked: UInt = UInt(26.W)

    val robIdx: UInt = UInt(robAddrSz.W)
    val ldqIdx: UInt = UInt(ldqAddrSz.W)
    val stqIdx: UInt = UInt(stqAddrSz.W)

    val iwState: UInt        = UInt(2.W)
    val iw_p1_poisoned: Bool = Bool()
    val iw_p2_poisoned: Bool = Bool()

    val prs1_busy: Bool  = Bool()
    val prs2_busy: Bool  = Bool()
    val ppred_busy: Bool = Bool()

    val xcpt_valid: Bool = Bool()
    val xcpt_cause: UInt = UInt(15.W)
    val vaddrWriteEnable: Bool = Bool()
    val instr_misalign : Bool = Bool()
    val ctrl = new CtrlSignals

    val tlb_op: UInt = UInt(5.W)

    val use_ldq: Bool = Bool()
    val use_stq: Bool = Bool()

    // val mem_cmd: UInt = UInt(/*TODO*/)
    val mem_size: UInt   = UInt(2.W)
    val mem_signed: Bool = Bool()

    val is_dbar: Bool  = Bool()
    val is_ibar: Bool = Bool()
    val is_ll: Bool     = Bool()
    val is_sc: Bool     = Bool()

    val is_sys_pc2epc: Bool = Bool()
    val is_unique: Bool = Bool()
    val flush_on_commit: Bool = Bool()

    val debug_inst: UInt    = if (!FPGAPlatform) UInt(coreInstrBits.W) else null
    val debug_pc: UInt      = if (!FPGAPlatform) UInt(32.W) else null
    val debug_mispred: Bool = if (!FPGAPlatform) Bool() else null

    def is_sfb_br: Bool             = isBr && isSFB
    def is_sfb_shadow: Bool         = isSFB && !isBr
    def allocate_brtag: Bool        = (isBr && !isSFB) || isJalr
    def rf_wen: Bool                = dst_rtype =/= RT_X
    def fu_code_is(_fu: UInt): Bool = (fuCode & _fu) =/= 0.U
    def is_nop: Bool                = uopc === uopNOP
}

class CtrlSignals extends CoreBundle {
    val br_type: UInt     = UInt(BR_N.getWidth.W)
    val op1_sel: UInt     = UInt(OP1_X.getWidth.W)
    val op2_sel: UInt     = UInt(OP2_X.getWidth.W)
    val imm_sel: UInt     = UInt(immX.getWidth.W)
    val op_fcn: UInt      = UInt(AluFuncCode().SZ_ALU_FN.W)
    val fcn_dw: Bool      = Bool()
    val csr_cmd: UInt     = UInt(CSR_SZ.W)
    val is_load: Bool     = Bool()
    val is_sta: Bool      = Bool()
    val is_std: Bool      = Bool()
}
