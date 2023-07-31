package backend.memSystem

import chisel3._
import chisel3.util._
import iFu.common._
import iFu.frontend.{SFenceReq, TLBExceptions, TLBReq, TLBResp}

class DTlb extends CoreModule{
    val io = IO(new Bundle {
        val req = Flipped(Vec(memWidth, Decoupled(new TLBReq(0))))
        val miss_rdy = Output(Bool())
        val resp = Output(Vec(memWidth, new TLBResp))
        val sfence = Input(Valid(new SFenceReq))
        val kill = Input(Bool())
    })
    for(w <- 0 until memWidth){
        io.resp(w).miss := false.B
        io.resp(w).paddr:= io.req(w).bits.vaddr
        io.resp(w).pf   := 0.U.asTypeOf(new TLBExceptions())
        io.resp(w).gf   := 0.U.asTypeOf(new TLBExceptions())
        io.resp(w).ae   := 0.U.asTypeOf(new TLBExceptions())
        io.resp(w).ma   := 0.U.asTypeOf(new TLBExceptions())
        io.req(w).ready := true.B

    }
}
