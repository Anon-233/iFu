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


  for(w <- 0 until coreWidth){
    val lreg = io.commit.debug_ldst(w)  //这个接目的寄存器
    val wdata = io.commit.debug_wdata(w)  //这个接写入数据
    val nowPc = io.commit.debug_pc(w)  //这个接pc
    val nowInst = io.commit.debug_insts(w) //当前指令
    val valid = nowInst =/= BUBBLE //判断指令是否有效

    debug_reg(lreg) := wdata
  }
  for(w <-0 until lregSz){
    val regRead = debug_reg(w)   //这个接寄存器堆
    io.lregOut(w) := regRead //接寄存器堆
  }



}
