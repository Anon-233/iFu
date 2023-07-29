package iFu.backend

import chisel3._
import chisel3.util._
import iFu.common._

class debugDiff extends CoreBundle{
  val io = IO(new Bundle {
    val commit = Input(new CommitSignals())
  })


}
