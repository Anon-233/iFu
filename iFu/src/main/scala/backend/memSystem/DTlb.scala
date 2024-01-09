package backend.memSystem

import chisel3._
import chisel3.util._
import iFu.common._
class TLBResp extends CoreBundle {
    // lookup responses
    val miss = Bool()
    /** physical address */
    val paddr = UInt(32.W)
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
class DTlb extends CoreModule{
    val io = IO(new Bundle {
        val req = Flipped(Vec(memWidth, Decoupled(new TLBReq(0))))
        val resp = Output(Vec(memWidth, new TLBResp))
//        val sfence = Input(Valid(new SFenceReq))
        val kill = Input(Bool())
    })
    io := DontCare
    for(w <- 0 until memWidth){
        io.resp(w).miss := false.B
        io.resp(w).paddr:= io.req(w).bits.vaddr
        io.req(w).ready := true.B

    }
}
