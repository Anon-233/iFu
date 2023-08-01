package iFu.frontend

import chisel3._
import chisel3.util._

import iFu.common._

class SFenceReq extends CoreBundle {
    val rs1 = Bool()
    val rs2 = Bool()
    val addr = UInt(vaddrBits.W)
    /*val asid = UInt((1).W) // TODO zero-width
//    val hv = Bool()
//    val hg = Bool()*/
}

class TLBReq(lgMaxSize: Int) extends CoreBundle {
    /** request address from CPU. */
    val vaddr = UInt(vaddrBits.W)
    /** don't lookup TLB, bypass vaddr as paddr */
    val passthrough = Bool()
    /** granularity */
    val size = UInt(log2Ceil(lgMaxSize + 1).W)
    /** memory command. */
    // val cmd  = Bits(M_SZ.W)
    /*val prv = UInt(2.W)*/
    /** virtualization mode */
    /*val v = Bool()*/

}

class TLBExceptions extends Bundle {
    val ld = Bool()
    val st = Bool()
    val inst = Bool()
}

class TLBResp extends CoreBundle {
    // lookup responses
    val miss = Bool()
    /** physical address */
    val paddr = UInt(32.W)
    // val gpa = UInt(vaddrBits.W)
    // val gpa_is_pte = Bool()
    /** page fault exception */
    val pf = new TLBExceptions
    /** guest page fault exception */
    val gf = new TLBExceptions
    /** access exception */
    val ae = new TLBExceptions
    /** misaligned access exception */
    val ma = new TLBExceptions
    /** if this address is cacheable */
    // val cacheable = Bool()
    // /** if caches must allocate this address */
    // val must_alloc = Bool()
    // /** if this address is prefetchable for caches*/
    // val prefetchable = Bool()
}


class TLB extends CoreModule{
    val io = IO(new Bundle{
        val req = Flipped(Decoupled(new TLBReq(12)))
        /** response to Core */
        val resp = Output(new TLBResp())
        /** SFence Input */
        /*val sfence = Flipped(Valid(new SFenceReq))*/
    })
    io.req.ready := true.B
    io.resp.miss := false.B
    io.resp.paddr := io.req.bits.vaddr
    // io.resp.gpa := io.req.bits.vaddr
    // io.resp.gpa_is_pte = Bool()
    io.resp.pf      := 0.U.asTypeOf(new TLBExceptions)
    io.resp.gf      := 0.U.asTypeOf(new TLBExceptions)
    io.resp.ae      := 0.U.asTypeOf(new TLBExceptions)
    io.resp.ma      := 0.U.asTypeOf(new TLBExceptions)
    // io.resp.cacheable = Bool()
    // io.resp.must_alloc = Bool()
    // io.resp.prefetchable = Bool()
}
