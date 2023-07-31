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
    val lreg = io.commit.debug_ldst
    val wdata = io.commit.debug_wdata

    debug_reg(lreg) := wdata
  }
  for(w <-0 until lregSz){
    io.lregOut(w) := debug_reg(w)
  }



}
