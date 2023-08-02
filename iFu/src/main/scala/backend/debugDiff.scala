package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._

class debugDiff extends CoreModule {
  val io = IO(new Bundle {
    val commit = Input(new CommitSignals())
    val lregOut = Output(Vec(numLRegs,UInt(xLen.W)))
  })

  val debug_reg = RegInit(VecInit(Seq.fill(numLRegs)(0.U(32.W))))


  for(w <- 0 until coreWidth){
    when (io.commit.valids(w)) { //TODO:是否要换成arch_valids?
      val lreg = io.commit.uops(w).ldst //这个接目的寄存器
      val wdata = io.commit.debug_wdata(w) //这个接写入数据
      val valid = io.commit.debug_insts(w) =/= BUBBLE //判断指令是否有效

      val wen = io.commit.uops(w).ldst_val

      when(valid && wen && lreg =/= 0.U) {
        debug_reg(lreg) := wdata
      }
    } .otherwise {
      val valid = false
    }
  }
  for(w <-0 until numLRegs){
    val regRead = debug_reg(w)   //这个接寄存器堆
    io.lregOut(w) := regRead //接寄存器堆
  }



}
