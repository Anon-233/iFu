package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.util._
import scala.annotation.switch


class DataReq extends CoreBundle with HasDcacheParameters{
    val isWrite = Bool()
    
    val idx = UInt(nIdxBits.W)

    val readPos = UInt(log2Ceil(nWays).W)

    val wdata = Vec(nRowWords,UInt(32.W))
    // 将要写入的路 
    val writePos = UInt(log2Ceil(nWays).W)
}

class DataResp extends CoreBundle with HasDcacheParameters{
    val rdata = Vec(nRowWords,UInt(32.W))
}

class DcacheDataIO extends CoreBundle with HasDcacheParameters{
    val req = Input(Valid(new DataReq))
    val resp = Output(Valid(new DataResp))
}


class DcacheData extends Module with HasDcacheParameters{
    val io = IO(new CoreBundle{
        val lsuRead = Vec( memWidth ,new DcacheDataIO)
        val lsuWrite = Vec( memWidth ,new DcacheDataIO)
        val mshrRead = new DcacheDataIO
        val rpuWrite = new DcacheDataIO
        val replayRead = new DcacheDataIO
        val replayWrite = new DcacheDataIO
        val fenceRead   = new DcacheDataIO
        val fenceClean  = new DcacheDataIO
//        val reset = Input(Bool())
    })


    for (w <- 0 until memWidth) {
        io.lsuRead(w).resp := 0.U.asTypeOf(Valid(new DataResp))
        io.lsuWrite(w).resp := 0.U.asTypeOf(Valid(new DataResp))
    }

    io.mshrRead.resp := 0.U.asTypeOf(Valid(new DataResp))
    io.rpuWrite.resp := 0.U.asTypeOf(Valid(new DataResp))
    io.replayRead.resp := 0.U.asTypeOf(Valid(new DataResp))
    io.replayWrite.resp := 0.U.asTypeOf(Valid(new DataResp))
    io.fenceRead.resp := 0.U.asTypeOf(Valid(new DataResp))
    io.fenceClean.resp := 0.U.asTypeOf(Valid(new DataResp))

    // data
    val data = Array.fill(nSets)(SyncReadMem(nWays,Vec(nRowWords,UInt(32.W))))
    // reset
    val reseting = RegInit(true.B)
    val resetIdx =  RegInit(0.U(nIdxBits.W))

    when(reseting){
        when(resetIdx === (nSets-1).U){
            reseting := false.B
        }.otherwise{
            resetIdx := resetIdx + 1.U
        }
    }

    when(reseting){
        val resetData = VecInit(Seq.fill(nRowWords)(0.U(32.W)))
        for(i <- 0 until nSets){
            when(resetIdx === i.U){
                for(j <- 0 until nWays){
                    data(i).write(j.U , resetData)
                }
            }
        }
    }

    
    val lsu_R :: lsu_W :: mshr_R :: rpu_W :: replay_R :: replay_W :: fence_R :: fence_C :: none :: Nil = Enum(9)

    // Read

    val readType =  Wire(Vec(memWidth,UInt(3.W)))
    val readValid = Wire(Vec(memWidth,Bool()))
    val readIdx =   Wire(Vec(memWidth,(UInt(nIdxBits.W))))
    val readPos =   Wire(Vec(memWidth,(UInt(log2Ceil(nWays).W))))

    val readResp = Wire(Vec(memWidth, Valid(new DataResp)))
    readResp := 0.U.asTypeOf(Vec(memWidth, Valid(new DataResp)))

    for(w <- 0 until memWidth){
        readType(w) := Mux(io.lsuRead(w).req.valid,lsu_R,
                        Mux(io.mshrRead.req.valid,mshr_R,
                        Mux(io.replayRead.req.valid,replay_R,
                        Mux(io.fenceRead.req.valid,fence_R,none))))

        readValid(w) := io.lsuRead(w).req.valid || 
                        io.mshrRead.req.valid ||
                        io.replayRead.req.valid ||
                        io.fenceRead.req.valid

        readIdx(w) := Mux(io.lsuRead(w).req.valid,io.lsuRead(w).req.bits.idx,
                        Mux(io.mshrRead.req.valid,io.mshrRead.req.bits.idx,
                        Mux(io.replayRead.req.valid,io.replayRead.req.bits.idx,
                        Mux(io.fenceRead.req.valid,io.fenceRead.req.bits.idx,0.U))))

        readPos(w) := Mux(io.lsuRead(w).req.valid,io.lsuRead(w).req.bits.readPos,
                        Mux(io.mshrRead.req.valid,io.mshrRead.req.bits.readPos,
                        Mux(io.replayRead.req.valid,io.replayRead.req.bits.readPos,
                        Mux(io.fenceRead.req.valid,io.fenceRead.req.bits.readPos,0.U))))
    }



    for(w <- 0 until memWidth){
        val rdataChannel = Wire(Vec(nSets,Vec(nRowWords,UInt(32.W))))
        val ridx = RegNext(readIdx(w))
        for(i <- 0 until nSets){
            val readEn = readValid(w) && (readIdx(w) === i.U)
            rdataChannel(i) := data(i).read(readPos(w), readEn)
        }

        readResp(w).valid := RegNext(readValid(w))
        readResp(w).bits.rdata := rdataChannel(ridx)
    }


    for(w <- 0 until memWidth){
        switch(RegNext(readType(w))){
            is(lsu_R){
                io.lsuRead(w).resp := readResp(w)
            }
            is(mshr_R){
                io.mshrRead.resp := readResp(w)
            }
            is(replay_R){
                io.replayRead.resp := readResp(w)
            }
            is(fence_R){
                io.fenceRead.resp := readResp(w)
            }
        }
    }

    //write 

    val writeType =  Wire(Vec(memWidth,UInt(3.W)))
    val writeValid = Wire(Vec(memWidth,Bool()))
    val writeIdx =   Wire(Vec(memWidth,(UInt(nIdxBits.W))))
    val writePos =   Wire(Vec(memWidth,(UInt(log2Ceil(nWays).W))))
    val writeData =  Wire(Vec(memWidth,Vec(nRowWords,UInt(32.W))))

    val writeResp = Wire(Vec(memWidth, Valid(new DataResp)))
    writeResp := 0.U.asTypeOf(Vec(memWidth, Valid(new DataResp)))


    for(w <-0 until memWidth){
        writeType(w) := Mux(io.lsuWrite(w).req.valid,lsu_W,
                        Mux(io.rpuWrite.req.valid,rpu_W,
                        Mux(io.replayWrite.req.valid,replay_W, none)))

        writeValid(w) := io.lsuWrite(w).req.valid || io.rpuWrite.req.valid || io.replayWrite.req.valid

        writeIdx(w) := Mux(io.lsuWrite(w).req.valid,io.lsuWrite(w).req.bits.idx,
                        Mux(io.rpuWrite.req.valid,io.rpuWrite.req.bits.idx,
                        Mux(io.replayWrite.req.valid,io.replayWrite.req.bits.idx,
                        Mux(io.fenceClean.req.valid,io.fenceClean.req.bits.idx,0.U))))

        writePos(w) := Mux(io.lsuWrite(w).req.valid,io.lsuWrite(w).req.bits.writePos,
                        Mux(io.rpuWrite.req.valid,io.rpuWrite.req.bits.writePos,
                        Mux(io.replayWrite.req.valid,io.replayWrite.req.bits.writePos,
                        Mux(io.fenceClean.req.valid,io.fenceClean.req.bits.writePos,0.U))))

        writeData(w) := Mux(io.lsuWrite(w).req.valid,io.lsuWrite(w).req.bits.wdata,
                        Mux(io.rpuWrite.req.valid,io.rpuWrite.req.bits.wdata,
                        Mux(io.replayWrite.req.valid,io.replayWrite.req.bits.wdata,
                        Mux(io.fenceClean.req.valid,0.U.asTypeOf(Vec(nRowWords,UInt(32.W))),0.U.asTypeOf(Vec(nRowWords,UInt(32.W)))))))
    }

    for(w <- 0 until memWidth){
        for(i <- 0 until nSets){
            val writeEn = !reseting && writeValid(w) && (writeIdx(w) === i.U)
            when(writeEn){
                data(i).write(writePos(w), writeData(w))
            }
        }
        writeResp(w).valid := RegNext(writeValid(w))
        writeResp(w).bits := DontCare 
    }

    for(w <- 0 until memWidth){
        switch(RegNext(writeType(w))){
            is(lsu_W){
                io.lsuWrite(w).resp := writeResp(w)
            }
            is(rpu_W){
                io.rpuWrite.resp := writeResp(w)
            }
            is(replay_W){
                io.replayWrite.resp := writeResp(w)
            }
        }
    }
}