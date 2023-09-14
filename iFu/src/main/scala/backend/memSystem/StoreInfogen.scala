package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.util._

class StoreInfogen extends CoreModule with HasDcacheParameters{
    val io = IO(new Bundle{
        val req = Input(Vec(memWidth , new DCacheReq))
        val writebackPos = Input(Vec(memWidth , UInt(log2Ceil(nWays).W)))
        val handleDataLine = Input(Vec(memWidth ,Vec(nRowWords,UInt(32.W))))
        val handleMetaLine = Input(Vec(memWidth , new MetaLine))
        val metaWriteReq = Output(Vec(memWidth ,Valid(new MetaReq)))
        val dataWriteReq = Output(Vec(memWidth , Valid(new DataReq)))
    })

    io.metaWriteReq := 0.U.asTypeOf(Vec(memWidth ,Valid(new MetaReq)))
    io.dataWriteReq := 0.U.asTypeOf(Vec(memWidth ,Valid(new DataReq)))


    val finalwbDataLine = WireInit(0.U.asTypeOf(Vec(memWidth, Vec(nRowWords, UInt(32.W)))))
    val finalwbMetaLine = WireInit(0.U.asTypeOf(Vec(memWidth, new MetaLine)))
    finalwbDataLine := io.handleDataLine
    finalwbMetaLine := io.handleMetaLine


    for(w <- 0 until memWidth){

        val memSize = io.req(w).uop.mem_size
        val wordOffset = io.req(w).addr(log2Ceil(nRowWords) + 1, 2)
        val wdata = Wire(Vec(4, UInt(8.W)))
        val lob = io.req(w).data(7, 0)
        val loh = io.req(w).data(15, 0)
        val low = io.req(w).data(31, 0)
        // 初始化
        for (i <- 0 until 4) {
            wdata(i) := io.handleDataLine(w)(wordOffset)(i*8+7,i*8)
        }

        when(memSize === 0.U) {

            when(io.req(w).mask === "b0001".U) {
                wdata(0) := lob
            }
              .elsewhen(io.req(w).mask === "b0010".U) {
                  wdata(1) := lob
              }
              .elsewhen(io.req(w).mask === "b0100".U) {
                  wdata(2) := lob
              }
              .elsewhen(io.req(w).mask === "b1000".U) {
                  wdata(3) := lob
              }

        }.elsewhen(memSize === 1.U) {

            when(io.req(w).mask === "b0011".U) {
                wdata(0) := loh(7, 0)
                wdata(1) := loh(15, 8)
            }.elsewhen(io.req(w).mask === "b1100".U) {
                wdata(2) := loh(7, 0)
                wdata(3) := loh(15, 8)
            }

        }.elsewhen(memSize === 2.U) {
            when(io.req(w).mask === "b1111".U) {
                wdata(0) := low(7, 0)
                wdata(1) := low(15, 8)
                wdata(2) := low(23, 16)
                wdata(3) := low(31, 24)
            }
        }


        finalwbDataLine(w)(wordOffset) := wdata.asUInt
        finalwbMetaLine(w).dirty := true.B

        io.metaWriteReq(w).valid := true.B
        io.metaWriteReq(w).bits.idx := getIdx(io.req(w).addr)
        io.metaWriteReq(w).bits.wmeta := finalwbMetaLine(w)
        io.metaWriteReq(w).bits.wayMask := 1.U << io.writebackPos(w).asUInt


        io.dataWriteReq(w).valid := true.B
        io.dataWriteReq(w).bits.wayMask := 1.U << io.writebackPos(w).asUInt
        io.dataWriteReq(w).bits.idx := getIdx(io.req(w).addr)
        io.dataWriteReq(w).bits.wdata := finalwbDataLine(w)

    }


}