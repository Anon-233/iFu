package iFu.common

import chisel3._
import chisel3.util._

// 参考：https://gitlab.com/fudan-systa/nscscc-la/-/blob/main/vsrc/util/CBusArbiter.sv

class CBusArbiter extends CoreModule{
    val io = IO(new Bundle{
        val ireqs = Input(Vec(2, new CBusReq))    // from i$
        val iresps = Output(Vec(2, new CBusResp))
        val oreq = Output(new CBusReq)    // to AXI
        val oresp = Input(new CBusResp)
    })

    val busy = RegInit(false.B)
    val index = RegInit(0.U(log2Ceil(ireqs.size).W)) 

    val select = Mux(io.ireqs(0).valid, 0.U(log2Ceil(ireqs.size).W), 
                 Mux(io.ireqs(1).valid, 1.U(log2Ceil(ireqs.size).W),
                                        0.U(log2Ceil(ireqs.size).W)))
    val selectedReq = io.ireqs(select)

    io.oreq := Mux(busy, io.ireqs(index), 0.U.asTypeOf(new CBusReq))
    io.iresps := 0.U.asTypeOf(Vec(2, new CBusResp))
    io.iresps(index) := io.oresp

    when (busy) {
        when (io.oresp.isLast) { busy := false.B }
    } .otherwise {  // busy = false
        busy  := selectedReq.valid
        index := select
    }
}
