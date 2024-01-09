package iFu.tlb

import chisel3._
import chisel3.util._

import iFu.common._

class ITLBCSRContext extends CoreBundle {
    //
}

class ITLBReq extends CoreBundle {
    val vaddr = UInt(vaddrBits.W)
}

// PIF PPI ADEF
class ITLBExceptions extends CoreBundle {
    val is_pif  = Bool()
    val is_ppi  = Bool()
    val is_adef = Bool()
}

class ITLBResp extends CoreBundle {
    val paddr      = UInt(32.W)
    val exceptions = Valid(new ITLBExceptions)
}

class ITLBIO extends CoreBundle {
    val kill = Input(Bool())
    val ctx  = Input(new ITLBCSRContext)
    val req  = Flipped(Decoupled(new ITLBReq))
    val resp = Output(new ITLBResp)

    // val r_req  = //  to  TLBData
    // val r_resp = // from TLBData
}

class ITLB extends CoreModule {
    val io = IO(new ITLBIO)

    io.req.ready := true.B

// -----------------------------------------
//        Address Translation Logic
    io.resp.paddr := io.req.bits.vaddr
// -----------------------------------------

// -----------------------------------------
//        Exceptions Detection Logic
    val is_pif  = false.B // TODO: detect this when connecting with TLBData
    val is_ppi  = false.B // TODO: detect this when connecting with TLBData
    val is_adef = io.req.bits.vaddr(1, 0) === 0.U // pc must be aligned to 4

    io.resp.exceptions.valid := is_pif || is_ppi || is_adef
    io.resp.exceptions.bits.is_pif  := is_pif
    io.resp.exceptions.bits.is_ppi  := is_ppi
    io.resp.exceptions.bits.is_adef := is_adef
// -----------------------------------------
}