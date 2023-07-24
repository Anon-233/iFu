package iFu.backend

import chisel3._
import chisel3.util._
import iFu.common._

class BusyTableResp extends Bundle
{
    val prs1_busy = Bool()
    val prs2_busy = Bool()
}

class BusyTable(
    val plWidth : Int,
    val numPregs: Int,
    val numWbPorts: Int)extends CoreModule
{
    val pregSize = log2Ceil(numPregs)

    val io = IO(new CoreBundle(){
        val ren_uops = Input(Vec(plWidth,new MicroOp))
        val busy_resps = Output(Vec(plWidth,new BusyTableResp))
        val rebusy_reqs = Input(Vec(plWidth,Bool()))

        val wb_pdsts = Input(Vec(numWbPorts,UInt(pregSize.W)))
        val wb_valids = Input(Vec(numWbPorts,Bool()))
    })

    val busyTable = RegInit(0.U(numPregs.W))

    //将写回的寄存器置为非忙
    val busyTableWb = busyTable & ~(io.wb_pdsts zip io.wb_valids)
    .map { case (pdst,valid) => UIntToOH(pdst) & Fill(numPregs,valid.asUInt)}.reduce(_|_)


    //将新分配的寄存器置为忙
    val busyTableNext = busyTableWb | (io.ren_uops zip io.rebusy_reqs)
    .map{case (uop,req) => UIntToOH(uop.pdst) & Fill(numPregs, req.asUInt)}.reduce(_|_)

    //更新busytable
    busyTable := busyTableNext

    //输出
    //这里我们将不考虑转发，转发逻辑在外面顶层模块进行
    for (i <- 0 until plWidth){
        io.busy_resps(i).prs1_busy := busyTable(io.ren_uops(i).prs1)
        io.busy_resps(i).prs2_busy := busyTable(io.ren_uops(i).prs2)
    }
}