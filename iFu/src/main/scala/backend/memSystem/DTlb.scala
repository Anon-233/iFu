package backend.memSystem

import chisel3._
import chisel3.util._
import iFu.common._
import iFu.frontend.{SFenceReq, TLBReq, TLBResp}

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
        io.resp(w).pf   := false.B
        io.resp(w).gf   := false.B
        io.resp(w).ae   := false.B
        io.resp(w).ma   := false.B
        io.req(w).ready := true.B

    }
}
