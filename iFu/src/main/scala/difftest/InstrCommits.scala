
package iFu.difftest

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._

import iFu.difftest._

class InstrCommit extends CoreBundle {
    val debug_uopc  = Vec(robParameters.retireWidth, UInt(UOPC_SZ.W))
    val debug_insts = Vec(robParameters.retireWidth, UInt(32.W))
    val debug_wdata = Vec(robParameters.retireWidth, UInt(xLen.W))
    val debug_ldst  = Vec(robParameters.retireWidth, UInt(lregSz.W))
    val debug_pc    = Vec(robParameters.retireWidth, UInt(32.W))
    val debug_wen   = Vec(robParameters.retireWidth,Bool())

    val valids      = Vec(robParameters.retireWidth,Bool())
}

class InstrCommits extends CoreModule {
    val io = IO(new Bundle{
        val rawCommit = Input(new InstrCommit)
        val exception = Input(Bool())
        val fill_idx  = if (!FPGAPlatform) Input(UInt(5.W)) else null
    })

    //-------------------------------------
    val cmtsz = robParameters.retireWidth
    //-------------------------------------

    val rawCommit = RegNext(io.rawCommit)

    val idxs = Wire(Vec(cmtsz, Valid(UInt(log2Ceil(cmtsz).W))))
    idxs := 0.U.asTypeOf(Vec(cmtsz, Valid(UInt(log2Ceil(cmtsz).W))))

    when (rawCommit.valids.reduce(_|_)) {
        // 初始化头元素
        idxs(0).valid := rawCommit.valids(0) && !io.exception
        idxs(0).bits  := Mux(rawCommit.valids(0), 0.U, 3.U/*2'b11*/)

        for (i <- 1 until 4) {
            idxs(i).valid := rawCommit.valids(i) && !io.exception
            idxs(i).bits  := Mux(rawCommit.valids(i), idxs(i-1).bits + 1.U, idxs(i-1).bits)
        }
    }

    val zippedCommit = WireInit(0.U.asTypeOf(new InstrCommit))

    for (i <- 0 until 4) {
        val valid = idxs(i).valid
        val idx = idxs(i).bits

        when (valid) {
            zippedCommit.valids(idx) := true.B
            zippedCommit.debug_pc(idx)    := rawCommit.debug_pc(i)
            zippedCommit.debug_ldst(idx)  := rawCommit.debug_ldst(i)
            zippedCommit.debug_insts(idx) := rawCommit.debug_insts(i)
            zippedCommit.debug_wdata(idx) := rawCommit.debug_wdata(i)
            zippedCommit.debug_wen(idx)   := rawCommit.debug_wen(i)
            zippedCommit.debug_uopc(idx)  := rawCommit.debug_uopc(i)
        }
    }

    for (i <- 0 until 4) {
        val difftest = Module(new DifftestInstrCommit)
        difftest.io.clock  := clock
        difftest.io.coreid := 0.U   // only support 1 core now

        difftest.io.index          := i.U
        difftest.io.valid          := zippedCommit.valids(i)
        difftest.io.pc             := zippedCommit.debug_pc(i)
        difftest.io.instr          := zippedCommit.debug_insts(i)
        difftest.io.skip           := false.B
        difftest.io.is_TLBFILL     := zippedCommit.debug_uopc(i) === uopTLBFILL
        difftest.io.TLBFILL_index  := Cat(0.U(3.W), io.fill_idx - 1.U)
        difftest.io.is_CNTinst     := false.B
        difftest.io.timer_64_value := 0.U
        difftest.io.wen            := zippedCommit.debug_wen(i)
        difftest.io.wdest          := zippedCommit.debug_ldst(i)
        difftest.io.wdata          := zippedCommit.debug_wdata(i)
        difftest.io.csr_rstat      := false.B
        difftest.io.csr_data       := 0.U
    }
}
