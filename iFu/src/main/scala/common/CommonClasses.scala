package iFu.common

import chisel3._
import chisel3.util._

import iFu.common.CauseCode
class BrUpdateMasks extends CoreBundle {
    val resolveMask = UInt(maxBrCount.W)
    val mispredictMask = UInt(maxBrCount.W)
}

class BrResolutionInfo extends CoreBundle {
    val CFI_SZ = 2
    val uop = new MicroOp()
    val valid = Bool()
    val mispredict = Bool()
    val taken = Bool()
    val cfiType = UInt(CFI_SZ.W)
    val pcSel = UInt(2.W)
    val jalrTarget = UInt(xLen.W)
    val targetOffset = SInt(xLen.W) // ???
}

class BrUpdateInfo extends CoreBundle  {
    val b1 = new BrUpdateMasks()
    val b2 = new BrResolutionInfo()
}

class FuncUnitReq extends CoreBundle {
    val kill = Bool()
    val uop = new MicroOp()
    val rs1Data = UInt(xLen.W)
    val rs2Data = UInt(xLen.W)
    val predData = Bool()
}

class FuncUnitResp extends CoreBundle {
    val uop = new MicroOp()
    val predicated = Bool()
    val data = UInt(xLen.W)
    val addr = UInt(xLen.W)
    val rj   = UInt(xLen.W)
    val rd   = UInt(xLen.W)
}

class ExeUnitResp(val len: Int = 32) extends CoreBundle {
    val uop = new MicroOp
    val data = Bits(len.W)
    val rj   = Bits(len.W)
    val rd   = Bits(len.W)
    val predicated = Bool() // Was this predicated off?
}

class DCacheReq extends CoreBundle {
    val mask  = UInt(4.W)
    val addr  = UInt(32.W)
    val data  = Bits(xLen.W)
//    val is_hella = Bool() // Is this the hellacache req? If so this is not tracked in LDQ or STQ
    val uop = new MicroOp()
}

class DCacheResp extends CoreBundle {
    val data = Bits(xLen.W)
//    val is_hella = Bool()
    val uop = new MicroOp()
}

class LSUDMemIO extends CoreBundle {
    /**************************************/
    val robAddrSz = robParameters.robAddrSz
    /***************************************/
    val req         = new DecoupledIO(Vec(memWidth,Valid(new DCacheReq)))
    val s1_kill     = Output(Vec(memWidth, Bool()))
    val resp        = Flipped(Vec(memWidth, new Valid(new DCacheResp)))

    val nack        = Flipped(Vec(memWidth, new Valid(new DCacheReq)))

    val brupdate    = Output(new BrUpdateInfo)
    val exception   = Output(Bool())
    val rob_head_idx = Output(UInt(robAddrSz.W))

    val force_order = Output(Bool())
    val ordered     = Input(Bool())
}

class CommitSignals extends CoreBundle {
    val valids = Vec(robParameters.retireWidth, Bool())
    val arch_valids = Vec(robParameters.retireWidth,Bool())
    val uops = Vec(robParameters.retireWidth, new MicroOp)

    //maybe use
    //val debug

    val rbk_valids = Vec(robParameters.retireWidth,Bool())
    val rollback = Bool()

    //------------------debug
    val debug_insts = Vec(robParameters.retireWidth, UInt(32.W))
    val debug_wdata = Vec(robParameters.retireWidth, UInt(xLen.W))
    val debug_ldst = Vec(robParameters.retireWidth, UInt(lregSz.W))
    val debug_pc = Vec(robParameters.retireWidth, UInt(32.W))
}

case class SupportedFuncs (
    val alu: Boolean    = false,
    val jmp: Boolean    = false,
    val mem: Boolean    = false,
    val muldiv: Boolean = false,
    val csr: Boolean    = false,
    val cnt: Boolean    = false
    // val tlb: Boolean    = false
)

class Exception extends CoreBundle {
    val uop = new MicroOp()
    //TODO:update cause to loogarch
    val cause = Bits(CauseCode.causeCodeBits.W)
    val badvaddr = UInt(paddrBits.W)
}

class CommitExceptionSignals extends CoreBundle {
    val ftq_idx = UInt(log2Ceil(frontendParams.numFTQEntries).W)
    val pc_lob = UInt(log2Ceil(frontendParams.iCacheParams.lineBytes).W)
    val cause = UInt(15.W)
    val badvaddr = UInt(xLen.W)
    val vaddrWriteEnable = Bool()

    val uop = new MicroOp()

    val flush_typ = FlushTypes()
}