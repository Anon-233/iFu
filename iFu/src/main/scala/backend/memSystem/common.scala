package backend.memSystem
import chisel3._
import chisel3.util._


class MicroOp extends Bundle
{
  // val uopc             = UInt(UOPC_SZ.W)       // micro-op code
  val inst             = UInt(32.W)
  val debug_inst       = UInt(32.W)
  val is_rvc           = Bool()
  val debug_pc         = UInt(10.W)
  // val iq_type          = UInt(IQT_SZ.W)        // which issue unit do we use?
  // val fu_code          = UInt(FUConstants.FUC_SZ.W) // which functional unit do we use?
  // val ctrl             = new CtrlSignals

  // What is the next state of this uop in the issue window? useful
  // for the compacting queue.
  val iw_state         = UInt(2.W)
  // Has operand 1 or 2 been waken speculatively by a load?
  // Only integer operands are speculaively woken up,
  // so we can ignore p3.
  val iw_p1_poisoned   = Bool()
  val iw_p2_poisoned   = Bool()

  val is_br            = Bool()                      // is this micro-op a (branch) vs a regular PC+4 inst?
  val is_jalr          = Bool()                      // is this a jump? (jal or jalr)
  val is_jal           = Bool()                      // is this a JAL (doesn't include JR)? used for branch unit
  val is_sfb           = Bool()                      // is this a sfb or in the shadow of a sfb

  val br_mask          = UInt(40.W)  // which branches are we being speculated under?
  val br_tag           = UInt(20.W)

  // Index into FTQ to figure out our fetch PC.
  val ftq_idx          = UInt(10.W)
  // This inst straddles two fetch packets
  val edge_inst        = Bool()
  // Low-order bits of our own PC. Combine with ftq[ftq_idx] to get PC.
  // Aligned to a cache-line size, as that is the greater fetch granularity.
  // TODO: Shouldn't this be aligned to fetch-width size?
  val pc_lob           = UInt(10.W)

  // Was this a branch that was predicted taken?
  val taken            = Bool()

  val imm_packed       = UInt(20.W) // densely pack the imm in decode...
                                              // then translate and sign-extend in execute
  val csr_addr         = UInt(5.W)    // only used for critical path reasons in Exe
  // val rob_idx          = UInt(robAddrSz.W)
  // val ldq_idx          = UInt(ldqAddrSz.W)
  // val stq_idx          = UInt(stqAddrSz.W)
  // val rxq_idx          = UInt(log2Ceil(numRxqEntries).W)
  // val pdst             = UInt(maxPregSz.W)
  // val prs1             = UInt(maxPregSz.W)
  // val prs2             = UInt(maxPregSz.W)
  // val prs3             = UInt(maxPregSz.W)
  // val ppred            = UInt(log2Ceil(ftqSz).W)

  val prs1_busy        = Bool()
  val prs2_busy        = Bool()
  val prs3_busy        = Bool()
  val ppred_busy       = Bool()
  // val stale_pdst       = UInt(maxPregSz.W)
  val exception        = Bool()
  // val exc_cause        = UInt(xLen.W)          // TODO compress this down, xlen is insanity
  val bypassable       = Bool()                      // can we bypass ALU results? (doesn't include loads, csr, etc...)
  val mem_cmd          = UInt(2.W)          // sync primitives/cache flushes
  val mem_size         = UInt(2.W)
  val mem_signed       = Bool()
  val is_fence         = Bool()
  val is_fencei        = Bool()
  val is_amo           = Bool()
  val usesLdq         = Bool()
  val usesStq         = Bool()
  val is_sys_pc2epc    = Bool()                      // Is a ECall or Breakpoint -- both set EPC to PC.
  val is_unique        = Bool()                      // only allow this instruction in the pipeline, wait for STQ to
                                                     // drain, clear fetcha fter it (tell ROB to un-ready until empty)
  val flush_on_commit  = Bool()                      // some instructions need to flush the pipeline behind them

  // Preditation
  // def is_sfb_br        = is_br && is_sfb && enableSFBOpt.B // Does this write a predicate
  // def is_sfb_shadow    = !is_br && is_sfb && enableSFBOpt.B // Is this predicated
  val ldst_is_rs1      = Bool() // If this is set and we are predicated off, copy rs1 to dst,
                                // else copy rs2 to dst

  // logical specifiers (only used in Decode->Rename), except rollback (ldst)
  // val ldst             = UInt(lregSz.W)
  // val lrs1             = UInt(lregSz.W)
  // val lrs2             = UInt(lregSz.W)
  // val lrs3             = UInt(lregSz.W)

  val ldst_val         = Bool()              // is there a destination? invalid for stores, rd==x0, etc.
  val dst_rtype        = UInt(2.W)
  val lrs1_rtype       = UInt(2.W)
  val lrs2_rtype       = UInt(2.W)
  val frs3_en          = Bool()

  // floating point information
  val fp_val           = Bool()             // is a floating-point instruction (F- or D-extension)?
                                            // If it's non-ld/st it will write back exception bits to the fcsr.
  val fp_single        = Bool()             // single-precision floating point instruction (F-extension)

  // frontend exception information
  val xcpt_pf_if       = Bool()             // I-TLB page fault.
  val xcpt_ae_if       = Bool()             // I$ access exception.
  val xcpt_ma_if       = Bool()             // Misaligned fetch (jal/brjumping to misaligned addr).
  val bp_debug_if      = Bool()             // Breakpoint
  val bp_xcpt_if       = Bool()             // Breakpoint


  // What prediction structure provides the prediction FROM this op
  // val debug_fsrc       = UInt(BSRC_SZ.W)
  // What prediction structure provides the prediction TO this op
  // val debug_tsrc       = UInt(BSRC_SZ.W)

  // Do we allocate a branch tag for this?
  // SFB branches don't get a mask, they get a predicate bit
  // def allocate_brtag   = (is_br && !is_sfb) || is_jalr

  // // Does this register write-back
  // def rf_wen           = dst_rtype =/= RT_X

  // // Is it possible for this uop to misspeculate, preventing the commit of subsequent uops?
  // def unsafe           = uses_ldq || (uses_stq && !is_fence) || is_br || is_jalr

  // def fu_code_is(_fu: UInt) = (fu_code & _fu) =/= 0.U
}


trait HasDcacheParameters {
    val nRowBits = 256
    def nRowBytes = nRowBits / 8
    def nRowWords = nRowBits / 32
    val nSets = 64
    val nWays = 8
    val nMSHR = 8
    val nTLBEntries = 32
    def nOffsetBits = log2Ceil(nRowWords)
    def nIdxBits = log2Ceil(nSets)
    def nTagBits = 32 - nOffsetBits - nIdxBits
    val coreDataBits = 32
    val vaddrBits = 32
    def nBlockAddrBits = vaddrBits - nOffsetBits

    val nFirstMSHRs = 4
    val nSecondMSHRs = 8

    def IsKilledByBranch (brupdate: BrUpdateInfo, uop: MicroOp): Bool = {
    return maskMatch(brupdate.b1.mispredict_mask, uop.br_mask)
    }

    def maskMatch(msk1: UInt, msk2: UInt): Bool = (msk1 & msk2) =/= 0.U

    def getIdx(vaddr: UInt): UInt = vaddr(nOffsetBits + nIdxBits - 1, nOffsetBits)
    def getTag(vaddr: UInt): UInt = vaddr(vaddrBits - 1, vaddrBits - nTagBits)
    def getBlockAddr(vaddr: UInt): UInt = vaddr(vaddrBits - 1, nOffsetBits)

    def isStore(req : DCacheReq): Bool = req.uop.usesStq

}





class BrUpdateInfo extends Bundle{
  val b1 = new BrUpdateInfo1
}

class BrUpdateInfo1 extends Bundle {
  val mispredict = Bool()
  val mispredict_mask = UInt(40.W)
}




