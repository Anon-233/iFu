
package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.util._

class Missarbiter extends CoreModule with HasDcacheParameters {
    val io = IO(new Bundle{
        val req   = Input(Vec(memWidth, new DCacheReq))
        val alive = Input(Vec(memWidth, Bool()))
        val miss  = Input(Vec(memWidth, Bool()))

        val sendNack    = Output(Vec(memWidth , Bool()))
        val sendResp    = Output(Vec(memWidth , Bool()))
        val storeFailed = Output(Bool())

        val mshrReq = Decoupled(new DCacheReq)
    })
    if (!FPGAPlatform) dontTouch(io)

    io.sendResp    := 0.U.asTypeOf(Vec(memWidth, Bool()))
    io.sendNack    := 0.U.asTypeOf(Vec(memWidth, Bool()))
    io.storeFailed := false.B

    io.mshrReq.valid := false.B
    io.mshrReq.bits  := DontCare

    val wantaccess = Wire(Vec(memWidth, Bool()))
    for (i <- 0 until memWidth) {
        wantaccess(i) := io.miss(i) && io.alive(i)
    }

    when (wantaccess(0) && !wantaccess(1)) {
        io.sendResp(0) := false.B
        io.sendNack(0) := !io.mshrReq.ready
        io.storeFailed := !io.mshrReq.ready && isStore(io.req(0))

        io.mshrReq.valid := true.B
        io.mshrReq.bits  := io.req(0)
    } .elsewhen(!wantaccess(0) && wantaccess(1)) {
        io.sendResp(1) := false.B
        io.sendNack(1) := !io.mshrReq.ready

        io.mshrReq.valid := true.B
        io.mshrReq.bits  := io.req(1)
    } .elsewhen(wantaccess(0) && wantaccess(1)) { // priority: 1 > 0
        // pipeline 0
        io.sendResp(0) := false.B
        io.sendNack(0) := true.B
        io.storeFailed := isStore(io.req(0))

        // pipeline 1
        io.sendResp(1) := false.B
        io.sendNack(1) := !io.mshrReq.ready

        // send request to mshr
        io.mshrReq.valid := true.B
        io.mshrReq.bits  := io.req(1)
    }
}
