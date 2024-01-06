
package iFu

import chisel3._
import chisel3.util._

import iFu.common._

class cmtZipper extends CoreModule {
    val io = IO(new Bundle{
        val rawCommit = Input(new debugCommit)
        val zippedCommit = Output(new debugCommit)
    })

    //-------------------------------------
    val cmtsz = robParameters.retireWidth
    //-------------------------------------

    val rawCommit = RegNext(io.rawCommit)

    val idxs = Wire(Vec(cmtsz, Valid(UInt(log2Ceil(cmtsz).W))))
    idxs := 0.U.asTypeOf(Vec(cmtsz, Valid(UInt(log2Ceil(cmtsz).W))))

    when (rawCommit.arch_valids.reduce(_|_)) {
        // 初始化头元素
        idxs(0).valid := rawCommit.arch_valids(0)
        idxs(0).bits  := Mux(rawCommit.arch_valids(0), 0.U, 3.U/*2'b11*/)

        for (i <- 1 until 4) {
            idxs(i).valid := rawCommit.arch_valids(i)
            idxs(i).bits  := Mux(rawCommit.arch_valids(i), idxs(i-1).bits + 1.U, idxs(i-1).bits)
        }
    }

    io.zippedCommit := 0.U.asTypeOf(new debugCommit)

    for (i <- 0 until 4) {
        val valid = idxs(i).valid
        val idx = idxs(i).bits

        when (valid) {
            io.zippedCommit.arch_valids(idx) := true.B
            io.zippedCommit.debug_pc(idx)    := rawCommit.debug_pc(i)
            io.zippedCommit.debug_ldst(idx)  := rawCommit.debug_ldst(i)
            io.zippedCommit.debug_insts(idx) := rawCommit.debug_insts(i)
            io.zippedCommit.debug_wdata(idx) := rawCommit.debug_wdata(i)
            io.zippedCommit.debug_wen(idx)   := rawCommit.debug_wen(i)
        }
    }
}