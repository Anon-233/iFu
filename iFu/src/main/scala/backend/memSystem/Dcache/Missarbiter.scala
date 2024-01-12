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
    val missAllocPos = Input(Vec(memWidth,UInt(log2Ceil(nWays).W)))
    val mshrisFull = Input(Bool())
    val mshrstqIdx = Input(UInt(lsuParameters.stqAddrSz.W))
    val mshrhasStore = Input(Bool())
    val sendNack = Output(Vec(memWidth , Bool()))
    val sendResp = Output(Vec(memWidth , Bool()))
    val pipeNumber = Output(UInt(1.W))
    val storeFailed = Output(Bool())
    val replacePos = Output(UInt(log2Ceil(nWays).W))
    val mshrReq = Valid(new DCacheReq)

  })

  dontTouch(io)
  //先以传入的为初值
  io.sendResp := 0.U.asTypeOf(Vec(memWidth , Bool()))
  io.sendNack := 0.U.asTypeOf(Vec(memWidth , Bool()))
  io.pipeNumber := 0.U(1.W)
  io.replacePos := 0.U(log2Ceil(nWays).W)
  io.storeFailed := false.B
  io.mshrReq := 0.U.asTypeOf(Valid(new DCacheReq))

  when((io.miss(0) && io.alive(0)) && (!io.miss(1) || !io.alive(1))) {
    // 只有1号流水线是hit的时候，才会去写0号的miss

    // 判定0号的返回情况
    io.sendResp(0) := false.B

    when(isStore(io.req(0))) {
      
      // store miss
      when(io.mshrhasStore){
        // 如果已经有store,看看是不是自己,只有存的不是自己的那些store，才会发回nack
        when(io.mshrstqIdx =/= io.req(0).uop.stqIdx){
          io.sendNack(0) := true.B
          io.storeFailed := true.B
        }.otherwise{
          // 是自己的store，不发回nack
          io.sendNack(0) := false.B
          io.storeFailed := false.B
        }
        

      }.otherwise{
          // 当前没有store指令,尝试写入
          when(!io.mshrisFull) {
          io.mshrReq.valid := true.B
          // 这里要包括data，addr，uop，特别注意还有mask
          io.mshrReq.bits := io.req(0)
          io.replacePos := io.missAllocPos(0)
          io.pipeNumber := 0.U
        }
        // 只要不满，自己写成功了，就不发回nack
        when(io.mshrisFull){
          io.sendNack(0) := true.B
          io.storeFailed := true.B
        }.otherwise{
          io.sendNack(0) := false.B
          io.storeFailed := false.B
        }
      }

    }.otherwise {

      // 对于load指令，只要mshr不满，就可以写入,写入了就不发回nack
      when(!io.mshrisFull) {
        io.mshrReq.valid := true.B
        // 这里要包括data，addr，uop，特别注意还有mask
        io.mshrReq.bits := io.req(0)
        io.replacePos := io.missAllocPos(0)
        io.pipeNumber := 0.U
      }
      io.sendNack(0) := Mux(io.mshrisFull, true.B, false.B)
    }

  }.elsewhen((!io.miss(0) || !io.alive(0)) && (io.miss(1) && io.alive(1))) {
    // 写1号的miss
    when(!io.mshrisFull) {

      io.mshrReq.valid := true.B
      io.mshrReq.bits := io.req(1)
      io.replacePos := io.missAllocPos(1)
      io.pipeNumber := 1.U
    }

    // 判定1号的返回情况(1号一定是load指令)
    io.sendResp(1) := false.B
    io.sendNack(1) := Mux(io.mshrisFull, true.B, false.B)


  }.elsewhen((io.miss(0) && io.alive(0)) && (io.miss(1) && io.alive(1))) {
    // 1号优先级高，写1号的
    when(!io.mshrisFull) {

      io.mshrReq.valid := true.B
      io.mshrReq.bits := io.req(1)
      io.replacePos := io.missAllocPos(1)
      io.pipeNumber := 1.U
    }

    // 1号是load指令，看情况返回
    io.sendResp(1) := false.B
    io.sendNack(1) := Mux(io.mshrisFull, true.B, false.B)

    // 0号不会写进去，load 和 store 都要发回nack
    io.sendResp(0) := false.B
    io.sendNack(0) := true.B

  }


}