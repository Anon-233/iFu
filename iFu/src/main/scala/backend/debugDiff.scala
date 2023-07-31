package iFu.backend

import chisel3._
import chisel3.util._
import iFu.common._

class debugDiff extends CoreModule {
  val io = IO(new Bundle {
    val commit = Input(new CommitSignals())
    val lregOut = Output(Vec(lregSz,UInt(xLen.W)))
  })

  val debug_reg = Mem(lregSz,UInt(xLen.W))
  val inst = io.commit.debug_insts  //这个接pc，注意判断是否为bubble

  for(w <- 0 until coreWidth){
    val lreg = io.commit.debug_ldst  //这个接目的寄存器
    val wdata = io.commit.debug_wdata  //这个接写入数据

    debug_reg(lreg) := wdata
  }
  for(w <-0 until lregSz){
    io.lregOut(w) := debug_reg(w) //接寄存器堆
  }



}
