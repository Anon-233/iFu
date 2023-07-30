package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.util._

class FreeList (
    val plWidth: Int,
    val numPregs: Int,
    val numLregs: Int
) extends CoreModule {
    val pregSize = log2Ceil(numPregs)

    val io = IO(new Bundle {
        val reqs = Input(Vec(plWidth, Bool()))
        val alloc_pregs = Output(Vec(plWidth, Valid(UInt(pregSize.W))))

        //ROB返回
        val dealloc_pregs = Input(Vec(plWidth, Valid(UInt(pregSize.W))))

        val ren_br_tags   = Input(Vec(plWidth, Valid(UInt(brTagSz.W))))

        val brupdate = Input(new BrUpdateInfo)
    })

    //除了x0其他的寄存器刚开始都是free
    val freeList = RegInit(UInt(numPregs.W), ~(1.U(numPregs.W)))
    val brAllocList = Reg(Vec(maxBrCount, UInt(numPregs.W)))

    //分配
    val selPreg = SelectFirstN(freeList, plWidth)
    val selPregFire = Wire(Vec(plWidth, Bool()))

    val allocPreg = io.alloc_pregs map (a => UIntToOH(a.bits))
    val allocPregMask = (allocPreg zip io.reqs).scanRight(0.U(n.W)){ case ((a,r),m) => m | a & Fill(n,r) }

    //标记分配mask
    val selMask = (selPreg zip selPregFire) map { case (s,f) => s & Fill(numPregs,f) }.reduce(_|_)
    //预测错误的分支中空闲物理寄存器的独热码集合
    val brDeallocs = brAllocList(io.brupdate.b2.uop.br_tag) & Fill(numPregs, io.brupdate.b2.mispredict)
    //需要释放的物理寄存器独热码集合
    val deallocMask = io.dealloc_pregs.map(d => UIntToOH(d.bits)(numPregs - 1,0) & Fill(numPregs, d.valid)).reduce(_|_) | brDeallocs

    val brSlots = VecInit(io.ren_br_tags.map(tag => tag.valid)).asUInt

    //分支指令分配列表
    for (i <- 0 until maxBrCount) {
        val listReq = VecInit(io.ren_br_tags.map(tag => UIntToOH(tag.bits)(i))).asUInt & brSlots
        val newList = listReq.orR
        brAllocList(i) := Mux(
            newList,
            Mux1H(listReq, allocPregMask.slice(1, plWidth + 1)),
            brAllocList(i) & ~brDeallocs | allocPregMask(0)
        )
    }

    //更新
    freeList := (freeList & ~selMask | deallocMask) & ~(1.U(numpregs.W))

    //输出
    for (w <- 0 until plWidth) {
        val can = selPreg(w).orR
        val rValid = RegInit(false.B)
        val rSel = RegEnable(OHToUInt(selPreg(w)), selPregFire(w))

        rValid := rValid & !io.reqs(w) || can
        selPregFire(w) := (!rValid || io.reqs(w)) && can

        io.alloc_pregs(w).bits := rSel
        io.alloc_pregs(w).valid := rValid
    }

    // val rValids = RegInit(VecInit(Seq.fill(plWidth)(false.B)))
    // val rPregs  = Reg(Vec(plWidth, UInt(pregSize.W)))

    // val selPregs = SelectFirstN(freeList, plWidth)
    // val newPregs = selPregs.map(s => s.orR)

    // // alloc logic
    // for (w <- 0 until plWidth) {
    //     io.alloc_pregs(w).valid := rValids(w)
    //     io.alloc_pregs(w).bits := rPregs(w)
    // }

    // // fill logic
    // for (w <- 0 until plWidth) {
    //     rValids(w) := (rValids(w) && !io.reqs(w)) || newPregs(w)

    //     val needNewPreg := !rValids(w) || io.reqs(w)
    //     val rPregWriteEn := needNewPreg(w) && newPregs(w)
    //     when (rPregWriteEn) {
    //         rPregs(w) := selPregs(w)
    //     }
    // }
}
