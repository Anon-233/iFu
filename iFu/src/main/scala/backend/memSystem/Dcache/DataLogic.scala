
package iFu.backend

import chisel3._
import chisel3.util._
import scala.annotation.switch

import iFu.common._
import iFu.common.Consts._
import iFu.util._

class DcacheDataReq extends CoreBundle with HasDcacheParameters {
    val idx      = UInt(nIdxBits.W)
    val offset   = UInt(log2Ceil(nRowWords).W)
    val pos  = UInt(log2Ceil(nWays).W)

    val data    = UInt(xLen.W)

}

class DcacheDataResp extends CoreBundle with HasDcacheParameters {
    val data = UInt(xLen.W)
}

class DcacheDataIO extends CoreBundle with HasDcacheParameters {
    val req  = Input(Valid(new DcacheDataReq))
    val resp = Output(Valid(new DcacheDataResp))
}

class DcacheDataLogic extends Module with HasDcacheParameters{
    val io = IO(new CoreBundle{
        val lsuRead     = Vec( memWidth ,new DcacheDataIO)
        val lsuWrite    = new DcacheDataIO
        val wfuRead    = new DcacheDataIO
        val wfuWrite    = new DcacheDataIO
        val replayRead  = new DcacheDataIO
        val replayWrite = new DcacheDataIO
    })

    for (w <- 0 until memWidth) {
        io.lsuRead(w).resp  := 0.U.asTypeOf(Valid(new DcacheDataResp))
    }
    io.lsuWrite.resp := 0.U.asTypeOf(Valid(new DcacheDataResp))
    io.wfuRead.resp    := 0.U.asTypeOf(Valid(new DcacheDataResp))
    io.wfuWrite.resp    := 0.U.asTypeOf(Valid(new DcacheDataResp))
    io.replayRead.resp  := 0.U.asTypeOf(Valid(new DcacheDataResp))
    io.replayWrite.resp := 0.U.asTypeOf(Valid(new DcacheDataResp))

    // data
    val data = Module(new DcacheData)

    val lsu_R :: lsu_W :: wfu_R :: wfu_W :: replay_R :: replay_W :: none :: Nil = Enum(7)

    // Read
    val haslsuRead = io.lsuRead.map(x=>x.req.valid).reduce(_|_)

    val readType =  Wire(UInt(3.W))
    val readValid = Wire(Vec(memWidth,Bool()))

    val readReq = Wire(Vec(memWidth,new DcacheDataReq))

    val readResp = Wire(Vec(memWidth, Valid(new DcacheDataResp)))
    readResp := 0.U.asTypeOf(Vec(memWidth, Valid(new DcacheDataResp)))

    for (w <- 0 until memWidth) {
        readType := Mux(haslsuRead, lsu_R,
                       Mux(io.wfuRead.req.valid,   wfu_R,
                       Mux(io.replayRead.req.valid, replay_R,
                                                    none)))
        
        readValid(w) := io.lsuRead(w).req.valid ||
                        io.wfuRead.req.valid ||
                        io.replayRead.req.valid

        readReq(w) := Mux(io.lsuRead(w).req.valid, io.lsuRead(w).req.bits,
                               Mux(io.wfuRead.req.valid,   io.wfuRead.req.bits,
                               Mux(io.replayRead.req.valid, io.replayRead.req.bits,
                                                            0.U.asTypeOf(new DcacheDataReq))))
        
        
    }

    for(w <- 0 until memWidth){
        data.io.read(w).req.valid := readValid(w)
        data.io.read(w).req.bits := readReq(w)

        readResp(w) := data.io.read(w).resp
    }




    for (w <- 0 until memWidth) {
        switch (RegNext(readType)) {
            is (lsu_R) {
                io.lsuRead(w).resp := readResp(w)
            }
            is (wfu_R) {
                io.wfuRead.resp := readResp(w)
            }
            is (replay_R) {
                io.replayRead.resp := readResp(w)
            }
        }
    }

    //write 
    val writeType  = Wire(UInt(3.W))

    val writeValid = Wire(Bool())
    val writeReq = Wire(new DcacheDataReq)
    val writeResp = Wire(Valid(new DcacheDataResp))
    writeResp := 0.U.asTypeOf(Valid(new DcacheDataResp))

    writeValid := io.lsuWrite.req.valid ||
                  io.wfuWrite.req.valid ||
                  io.replayWrite.req.valid

    writeType := Mux(io.lsuWrite.req.valid, lsu_W,
                    Mux(io.wfuWrite.req.valid, wfu_W,
                    Mux(io.replayWrite.req.valid, replay_W,
                                                none)))

    writeReq := Mux(io.lsuWrite.req.valid, io.lsuWrite.req.bits,
                        Mux(io.wfuWrite.req.valid, io.wfuWrite.req.bits,
                        Mux(io.replayWrite.req.valid, io.replayWrite.req.bits,
                                                        0.U.asTypeOf(new DcacheDataReq))))


    data.io.write.req.valid := writeValid
    data.io.write.req.bits := writeReq

    //写数据的时候 返回一个有效位就行
    writeResp.valid := data.io.write.resp.valid

    switch(RegNext(writeType)){
        is(lsu_W){
            io.lsuWrite.resp := writeResp
        }
        is(wfu_W){
            io.wfuWrite.resp := writeResp
        }
        is(replay_W){
            io.replayWrite.resp := writeResp
        }
    }

}