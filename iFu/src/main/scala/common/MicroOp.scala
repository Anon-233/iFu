package iFu.common

import chisel3._
import chisel3.util._

class MicroOp extends CoreBundle with MicroOpCode {
    val pcLowBits = UInt(log2Ceil(frontendParams.iCacheParams.blockBytes).W)
    val instr = UInt(coreInstrBits.W)
    val uopc = UInt(UOPC_SZ)
    val ftqIdx = UInt(log2Ceil(frontendParams.numFTQEntries).W)
    val taken = Bool()
    val isSFB = Bool()
}
