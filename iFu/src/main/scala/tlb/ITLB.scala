package iFu.tlb

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.CauseCode._
import iFu.backend.DMW

class ITLBCSRContext extends CoreBundle {
    val dmw0 = new DMW
    val dmw1 = new DMW
}

class ITLBReq extends CoreBundle {
    val vaddr = UInt(vaddrBits.W)
}

// PIF PPI ADEF TLBR
class ITLBException extends CoreBundle {
    val xcpt_cause = UInt(causeCodeBits.W)
}

class ITLBResp extends CoreBundle {
    val paddr      = UInt(32.W)
    val exception = Valid(new ITLBException)
}

class ITLBIO extends CoreBundle {
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
//        Exception Detection Logic
    val is_pif  = false.B // TODO: detect this when connecting with TLBData
    val is_ppi  = false.B // TODO: detect this when connecting with TLBData
    val is_tlbr = false.B // TODO: detect this when connecting with TLBData
    val is_adef = io.req.bits.vaddr(1, 0) =/= 0.U // pc must be aligned to 4

    io.resp.exception.valid := is_pif || is_ppi || is_adef || is_tlbr
    when (is_pif) {
        io.resp.exception.bits.xcpt_cause := PIF
    } .elsewhen (is_ppi) {
        io.resp.exception.bits.xcpt_cause := PPI
    } .elsewhen (is_adef) {
        io.resp.exception.bits.xcpt_cause := ADEF
    } .elsewhen (is_tlbr) {
        io.resp.exception.bits.xcpt_cause := TLBR
    } .otherwise {
        io.resp.exception.bits.xcpt_cause := 0.U
    }
// -----------------------------------------
}
