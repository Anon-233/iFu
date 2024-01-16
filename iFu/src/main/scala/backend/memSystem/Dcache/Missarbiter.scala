
package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.util._

class Missarbiter extends CoreModule with HasDcacheParameters {
  val io = IO(new Bundle{
    val req = Input(Vec(memWidth , new DCacheReq))
    val miss = Input(Vec(memWidth , Bool()))
    val alive = Input(Vec(memWidth , Bool()))
    val sendNack = Output(Vec(memWidth , Bool()))
    val sendResp = Output(Vec(memWidth , Bool()))
    val storeFailed = Output(Bool())
    val mshrReq = Decoupled(new DCacheReq)
  })

  dontTouch(io)

  io.sendResp := 0.U.asTypeOf(Vec(memWidth , Bool()))
  io.sendNack := 0.U.asTypeOf(Vec(memWidth , Bool()))
  io.storeFailed := false.B
  io.mshrReq.valid := false.B
  io.mshrReq.bits := 0.U.asTypeOf(new DCacheReq)

  
  val wantaccess = Wire(Vec(memWidth , Bool()))
  for(i <- 0 until memWidth){
    // 有效的miss指令，才会参与竞争 
    wantaccess(i) := io.miss(i) && io.alive(i)
  }

  when(wantaccess(0) && !wantaccess(1)){

    // 判定0号的返回情况
    io.mshrReq.valid := true.B
    io.mshrReq.bits := io.req(0)

    io.sendResp(0) := false.B
    // mshr会在内部判断自己能不能接收,只需要看ready即可判断进不进得去
    // 写进去就不用发nack了
    io.sendNack(0) := Mux(io.mshrReq.ready, false.B, true.B)

    // 特别的如果是store指令，还要判断store是否成功
    when( isStore(io.req(0))){
      io.storeFailed := !io.mshrReq.ready
    }


  }.elsewhen(!wantaccess(0) && wantaccess(1)){
    

    // 判定1号的返回情况(1号一定是load指令)
    io.mshrReq.valid := true.B
    io.mshrReq.bits := io.req(1)

    io.sendResp(1) := false.B
    io.sendNack(1) := Mux(io.mshrReq.ready, false.B, true.B)


  }.elsewhen((io.miss(0) && io.alive(0)) && (io.miss(1) && io.alive(1))) {

    // 0号按存不进去处理
    io.sendResp(0) := false.B
    io.sendNack(0) := true.B
    // 对于0号store指令,拉高storeFailed
    when(isStore(io.req(0))){
      io.storeFailed := true.B
    }
    

    // 1号优先级高，写1号的
    io.mshrReq.valid := true.B
    io.mshrReq.bits := io.req(1)

    io.sendResp(1) := false.B
    io.sendNack(1) := Mux(io.mshrReq.ready, false.B, true.B)
    
  }


}