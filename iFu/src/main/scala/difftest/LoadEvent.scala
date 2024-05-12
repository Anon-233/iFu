package iFu.difftest

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._

import iFu.difftest._

class LoadEventCommit extends CoreBundle {
    val debug_uop = Vec(robParameters.retireWidth, new MicroOp)
    val debug_paddr = Vec(robParameters.retireWidth, UInt(32.W))
    val debug_vaddr = Vec(robParameters.retireWidth, UInt(32.W))
    val valids = Vec(robParameters.retireWidth, Bool())
}


class LoadEventCommits extends CoreModule {
    val io = IO(new Bundle {
        val rawCommit = Input(new LoadEventCommit)
        val exception = Input(Bool())
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

    val zippedCommit = WireInit(0.U.asTypeOf(new LoadEventCommit))

    for (i <- 0 until 4) {
        val valid = idxs(i).valid
        val idx = idxs(i).bits

        when (valid) {
            zippedCommit.valids(idx) := rawCommit.valids(i)
            zippedCommit.debug_paddr(idx) := rawCommit.debug_paddr(i)
            zippedCommit.debug_vaddr(idx) := rawCommit.debug_vaddr(i)
            zippedCommit.debug_uop(idx) := rawCommit.debug_uop(i)
        }
    }

    dontTouch(zippedCommit)

    for(i <- 0 until 4) {
        val difftest = Module(new DifftestLoadEvent)
        val dif_uop = zippedCommit.debug_uop(i)
        val ll_w   =  dif_uop.use_ldq && dif_uop.is_ll
        val ld_w  = dif_uop.use_ldq && !dif_uop.is_ll && dif_uop.mem_size === 2.U
        val ld_hu = dif_uop.use_ldq && !dif_uop.is_ll && dif_uop.mem_size === 1.U && !dif_uop.mem_signed
        val ld_h   = dif_uop.use_ldq && !dif_uop.is_ll && dif_uop.mem_size === 1.U && dif_uop.mem_signed
        val ld_bu = dif_uop.use_ldq && !dif_uop.is_ll && dif_uop.mem_size === 0.U && !dif_uop.mem_signed
        val ld_b  = dif_uop.use_ldq && !dif_uop.is_ll && dif_uop.mem_size === 0.U && dif_uop.mem_signed
        difftest.io.clock  := clock
        difftest.io.coreid := 0.U   // only support 1 core now
        difftest.io.index := i.U
        difftest.io.valid := VecInit(Cat(0.U(2.W), ll_w, ld_w, ld_hu, ld_h, ld_bu, ld_b) & Fill(8, zippedCommit.valids(i))).asUInt
        val fake_paddr = zippedCommit.debug_paddr(i) | 0xf8000000L.U //assume all load is mmio
        dontTouch(fake_paddr)
        difftest.io.paddr := fake_paddr
        difftest.io.vaddr := zippedCommit.debug_vaddr(i) 
        
    }
}
