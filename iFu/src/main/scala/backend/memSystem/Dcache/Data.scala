package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.util._


class DataReq extends CoreBundle with HasDcacheParameters{
    val isWrite = Bool()
    
    val idx = UInt(nIdxBits.W)

    // mshr来读data的时候所选择的路
    val replacePos = UInt(log2Ceil(nWays).W)

    // 将命中的路
    val hitPos = UInt(log2Ceil(nWays).W)

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



    // 数据结构
    // val data = SyncReadMem(nSets, Vec(nWays,Vec(nRowWords, UInt(32.W))))
    // val data = VecInit(Seq.fill(nSets)(SyncReadMem(nWays,Vec(nRowWords,UInt(32.W)))))
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

    
    val lsu_R :: lsu_W :: mshr_R :: rpu_W :: replay_R :: replay_W :: none :: Nil = Enum(7)

    // Read

    val readType =  Wire(Vec(memWidth,UInt(3.W)))
    val readValid = Wire(Vec(memWidth,Bool()))
    val readIdx =   Wire(Vec(memWidth,(UInt(nIdxBits.W))))
    val readPos =   Wire(Vec(memWidth,(UInt(log2Ceil(nWays).W))))

    val readResp = Wire(Vec(memWidth, Valid(new DataResp)))

    for(w <- 0 until memWidth){
        readType(w) := Mux(io.lsuRead(w).req.valid,lsu_R,
                        Mux(io.mshrRead.req.valid,mshr_R,
                        Mux(io.replayRead.req.valid,replay_R, none)))

        readValid(w) := io.lsuRead(w).req.valid || io.mshrRead.req.valid || io.replayRead.req.valid

        readIdx(w) := Mux(io.lsuRead(w).req.valid,io.lsuRead(w).req.bits.idx,
                        Mux(io.mshrRead.req.valid,io.mshrRead.req.bits.idx,
                        Mux(io.replayRead.req.valid,io.replayRead.req.bits.idx,0.U)))

        readPos(w) := Mux(io.lsuRead(w).req.valid,io.lsuRead(w).req.bits.hitPos,
                        Mux(io.mshrRead.req.valid,io.mshrRead.req.bits.replacePos,
                        Mux(io.replayRead.req.valid,io.replayRead.req.bits.hitPos,0.U)))
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

    RegNext(readType) match{
        case lsu_R => {
            for(w <- 0 until memWidth){
                io.lsuRead(w).resp := readResp(w)
            }
        }
        case mshr_R => {
            io.mshrRead.resp := readResp(0)
        }
        case replay_R => {
            io.replayRead.resp := readResp(0)
        }
    }


    //write 

    val writeType =  Wire(Vec(memWidth,UInt(3.W)))
    val writeValid = Wire(Vec(memWidth,Bool()))
    val writeIdx =   Wire(Vec(memWidth,(UInt(nIdxBits.W))))
    val writePos =   Wire(Vec(memWidth,(UInt(log2Ceil(nWays).W))))
    val writeData =  Wire(Vec(memWidth,Vec(nRowWords,UInt(32.W))))

    val writeResp = Wire(Vec(memWidth, Valid(new DataResp)))


    for(w <-0 until memWidth){
        writeType(w) := Mux(io.lsuWrite(w).req.valid,lsu_W,
                        Mux(io.rpuWrite.req.valid,rpu_W,
                        Mux(io.replayWrite.req.valid,replay_W, none)))

        writeValid(w) := io.lsuWrite(w).req.valid || io.rpuWrite.req.valid || io.replayWrite.req.valid

        writeIdx(w) := Mux(io.lsuWrite(w).req.valid,io.lsuWrite(w).req.bits.idx,
                        Mux(io.rpuWrite.req.valid,io.rpuWrite.req.bits.idx,
                        Mux(io.replayWrite.req.valid,io.replayWrite.req.bits.idx,0.U)))

        writePos(w) := Mux(io.lsuWrite(w).req.valid,io.lsuWrite(w).req.bits.writePos,
                        Mux(io.rpuWrite.req.valid,io.rpuWrite.req.bits.writePos,
                        Mux(io.replayWrite.req.valid,io.replayWrite.req.bits.writePos,0.U)))

        writeData(w) := Mux(io.lsuWrite(w).req.valid,io.lsuWrite(w).req.bits.wdata,
                        Mux(io.rpuWrite.req.valid,io.rpuWrite.req.bits.wdata,
                        Mux(io.replayWrite.req.valid,io.replayWrite.req.bits.wdata,0.U.asTypeOf(Vec(nRowWords,UInt(32.W))))))
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

    RegNext(writeType) match{
        case lsu_W => {
            for(w <- 0 until memWidth){
                io.lsuWrite(w).resp := writeResp(w)
            }
        }
        case rpu_W => {
            io.rpuWrite.resp := writeResp(0)
        }
        case replay_W => {
            io.replayWrite.resp := writeResp(0)
        }
    }



    // // lsuRead
    // for(w <- 0 until memWidth){
    //     // val rdataSet = data.read(io.lsuRead(w).req.bits.idx, io.lsuRead(w).req.valid)
    //     // io.lsuRead(w).resp.valid := RegNext(io.lsuRead(w).req.valid)
    //     // io.lsuRead(w).resp.bits.rdata := rdataSet(RegNext(io.lsuRead(w).req.bits.hitPos))
    //     val rdataChannel = Wire(Vec(nSets,Vec(nRowWords,UInt(32.W))))//因为读取有一周期的延迟,需要维持nSet个channel接收读取到的结果
    //     val ridx = RegNext(io.lsuRead(w).req.bits.idx)//一周期后对应的idx
    //     // data(io.lsuRead(w).req.bits.idx).read(io.lsuRead(w).req.bits.hitPos, io.lsuRead(w).req.valid)
    //     // 这里的时序是，先当周期传递valid信号和idx到read函数，让各个Mem去读读取各个data的Set的所有内容
    //     // ，然后一周期以后再根据RegNext(idx)选择对应的Set，从而实现rdata有一个周期的延迟
    //     for(i <- 0 until nSets){
    //         val lsuReadEn = io.lsuRead(w).req.valid && (io.lsuRead(w).req.bits.idx === i.U)
    //         rdataChannel(i) := data(i).read(io.lsuRead(w).req.bits.hitPos, lsuReadEn)
    //     }
    //     io.lsuRead(w).resp.valid := RegNext(io.lsuRead(w).req.valid)
    //     io.lsuRead(w).resp.bits.rdata := rdataChannel(ridx)
    // }


    // // lsuWrite
    // for(w <- 0 until memWidth){
    //     when(!reseting && io.lsuWrite(w).req.valid && io.lsuWrite(w).req.bits.isWrite){

    //         // data.write(io.lsuWrite(w).req.bits.idx, VecInit(Seq.fill(nWays)(io.lsuWrite(w).req.bits.wdata)), io.lsuWrite(w).req.bits.wayMask.asBools)
    //         // data(io.lsuWrite(w).req.bits.idx).write(io.lsuWrite(w).req.bits.writePos, io.lsuWrite(w).req.bits.wdata)
    //         for(i <- 0 until nSets){
    //             when(io.lsuWrite(w).req.bits.idx === i.U){
    //                 data(i).write(io.lsuWrite(w).req.bits.writePos, io.lsuWrite(w).req.bits.wdata)
    //             }
    //         }
    //     }
    //     io.lsuWrite(w).resp.valid := RegNext(io.lsuWrite(w).req.valid)
    //     io.lsuWrite(w).resp.bits := DontCare
    // }


    // // mshrRead
    // // val replaceDataSet = data.read(io.mshrRead.req.bits.idx, io.mshrRead.req.valid)
    // val replaceDataChannel = Wire(Vec(nSets,Vec(nRowWords,UInt(32.W))))
    // val replaceidx = RegNext(io.mshrRead.req.bits.idx)
    // // data(io.mshrRead.req.bits.idx).read(io.mshrRead.req.bits.replacePos, io.mshrRead.req.valid)
    // for(i <- 0 until nSets){
    //     val mshrReadEn = io.mshrRead.req.valid && (io.mshrRead.req.bits.idx === i.U)
    //     replaceDataChannel(i) := data(i).read(io.mshrRead.req.bits.replacePos, mshrReadEn)
    // }
    // io.mshrRead.resp.valid := RegNext(io.mshrRead.req.valid)
    // io.mshrRead.resp.bits.rdata := replaceDataChannel(replaceidx)

    // // rpuWrite
    // when(!reseting && io.rpuWrite.req.valid && io.rpuWrite.req.bits.isWrite){
    //     // data.write(io.rpuWrite.req.bits.idx, VecInit(Seq.fill(nWays)(io.rpuWrite.req.bits.wdata)), io.rpuWrite.req.bits.wayMask.asBools)
    //     // data(io.rpuWrite.req.bits.idx).write(io.rpuWrite.req.bits.writePos, io.rpuWrite.req.bits.wdata)
    //     for(i <- 0 until nSets){
    //         when(io.rpuWrite.req.bits.idx === i.U){
    //             data(i).write(io.rpuWrite.req.bits.writePos, io.rpuWrite.req.bits.wdata)
    //         }
    //     }
    // }
    // io.rpuWrite.resp.valid := RegNext(io.rpuWrite.req.valid)
    // io.rpuWrite.resp.bits := DontCare

    // // replayRead
    // // val hitPos = RegNext(io.replayRead.req.bits.hitPos)
    // // val hitDataSet = data.read(io.replayRead.req.bits.idx, io.replayRead.req.valid)
    // val hitDataChannel = Wire(Vec(nSets,Vec(nRowWords,UInt(32.W))))
    // val hitidx = RegNext(io.replayRead.req.bits.idx)
    // // data(io.replayRead.req.bits.idx).read(io.replayRead.req.bits.hitPos, io.replayRead.req.valid)
    // for(i <- 0 until nSets){
    //     val replayReadEn = io.replayRead.req.valid && (io.replayRead.req.bits.idx === i.U)
    //     hitDataChannel(i) := data(i).read(io.replayRead.req.bits.hitPos, replayReadEn)
    // }
    // io.replayRead.resp.valid := RegNext(io.replayRead.req.valid)
    // io.replayRead.resp.bits.rdata := hitDataChannel(hitidx)

    // //replayWrite
    // when(!reseting && io.replayWrite.req.valid && io.replayWrite.req.bits.isWrite) {
    //     // data.write(io.replayWrite.req.bits.idx, VecInit(Seq.fill(nWays)(io.replayWrite.req.bits.wdata)), io.replayWrite.req.bits.wayMask.asBools)
    //     // data(io.replayWrite.req.bits.idx).write(io.replayWrite.req.bits.writePos, io.replayWrite.req.bits.wdata)
    //     for(i <- 0 until nSets){
    //         when(io.replayWrite.req.bits.idx === i.U){
    //             data(i).write(io.replayWrite.req.bits.writePos, io.replayWrite.req.bits.wdata)
    //         }
    //     }
    // }
    // io.replayWrite.resp.valid := RegNext(io.replayWrite.req.valid)
    // io.replayWrite.resp.bits := DontCare

}