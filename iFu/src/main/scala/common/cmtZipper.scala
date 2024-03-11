
package iFu

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._

import iFu.difftest._

class cmtZipper extends CoreModule {
    val io = IO(new Bundle{
        val rawCommit = Input(new debugCommit)
    })

    //-------------------------------------
    val cmtsz = robParameters.retireWidth
    //-------------------------------------

    val rawCommit = RegNext(io.rawCommit)

    val idxs = Wire(Vec(cmtsz, Valid(UInt(log2Ceil(cmtsz).W))))
    idxs := 0.U.asTypeOf(Vec(cmtsz, Valid(UInt(log2Ceil(cmtsz).W))))

    when (rawCommit.valids.reduce(_|_)) {
        // 初始化头元素
        idxs(0).valid := rawCommit.valids(0)
        idxs(0).bits  := Mux(rawCommit.valids(0), 0.U, 3.U/*2'b11*/)

        for (i <- 1 until 4) {
            idxs(i).valid := rawCommit.valids(i)
            idxs(i).bits  := Mux(rawCommit.valids(i), idxs(i-1).bits + 1.U, idxs(i-1).bits)
        }
    }

    if (!FPGAPlatform) {
        for (i <- 0 until 4) {
            val valid = idxs(i).valid
            val idx   = idxs(i).bits

            val difftest = Module(new DifftestInstrCommit)
            difftest.io.clock  := clock
            difftest.io.coreid := 0.U   // only support 1 core now

            difftest.io.index          := i.U
            difftest.io.valid          := valid
            difftest.io.pc             := rawCommit.debug_pc(i)
            difftest.io.instr          := rawCommit.debug_insts(i)
            difftest.io.skip           := false.B
            difftest.io.is_TLBFILL     := false.B
            difftest.io.TLBFILL_index  := 0.U
            difftest.io.is_CNTinst     := false.B
            difftest.io.timer_64_value := 0.U
            difftest.io.wen            := rawCommit.debug_wen(i)
            difftest.io.wdest          := rawCommit.debug_ldst(i)
            difftest.io.wdata          := rawCommit.debug_wdata(i)
            difftest.io.csr_rstat      := false.B
            difftest.io.csr_data       := 0.U
        }
    }
}
