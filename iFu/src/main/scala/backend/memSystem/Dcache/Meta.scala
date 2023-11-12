package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.util._


class MetaLine extends CoreBundle with HasDcacheParameters {
    val valid = Bool()
    val dirty = Bool()
    val tag   = UInt(nTagBits.W)
    val age   = UInt(10.W)
}


class MetaReq extends CoreBundle with HasDcacheParameters{
    val idx    = UInt(nIdxBits.W)
    val tag    = UInt(nTagBits.W)

    val readPos = UInt(log2Ceil(nWays).W)

    val isWrite = Bool()
    val wmeta = new MetaLine
    // 将要写入的路
    val writePos = UInt(log2Ceil(nWays).W)
}

class MetaResp extends CoreBundle with HasDcacheParameters{
    // 用valid来表示是否命中
    val rmeta  = new MetaLine
    // 如果一个store命中了一个readOnly，就认为是miss
    val hit = Bool()

    // 用于fence通路实时向外界反应是否有脏行
    val hasDirty = Bool()


    val idx = UInt(nIdxBits.W)
    val pos = UInt(log2Ceil(nWays).W)
}

class DcacheMetaIO extends CoreBundle with HasDcacheParameters{
    val req = Input(Valid(new MetaReq))
    val resp = Output(Valid(new MetaResp))
}

class DcacheMeta extends Module with HasDcacheParameters{
    val io = IO(new CoreBundle{ 
        val lsuRead     = Vec( memWidth ,new DcacheMetaIO)
        val lsuWrite    = Vec( memWidth ,new DcacheMetaIO)
        val mshrRead    = new DcacheMetaIO
        val rpuWrite    = new DcacheMetaIO
        val replayRead  = new DcacheMetaIO
        val replayWrite = new DcacheMetaIO
        val fenceRead   = new DcacheMetaIO
        val fenceClean  = new DcacheMetaIO
        val readOnlyBlockAddr = Input(Valid(UInt(32.W)))
    })

    

    for(w <- 0 until memWidth){
        io.lsuRead(w).resp := 0.U.asTypeOf(Valid(new MetaResp))
        io.lsuWrite(w).resp := 0.U.asTypeOf(Valid(new MetaResp))
    }

    io.mshrRead.resp := 0.U.asTypeOf(Valid(new MetaResp))
    io.rpuWrite.resp := 0.U.asTypeOf(Valid(new MetaResp))
    io.replayRead.resp := 0.U.asTypeOf(Valid(new MetaResp))
    io.replayWrite.resp := 0.U.asTypeOf(Valid(new MetaResp))
    io.fenceRead.resp := 0.U.asTypeOf(Valid(new MetaResp))
    io.fenceClean.resp := 0.U.asTypeOf(Valid(new MetaResp))

    // 数据结构
    // val meta = SyncReadMem(nSets, Vec(nWays, new MetaLine))

    //val meta = VecInit(Seq.fill(nSets)(SyncReadMem(nWays, new MetaLine)))
    val meta = Array.fill(nSets)(SyncReadMem(nWays, new MetaLine))
    // 同步记录meta里面有效的的dirty行
    val dirtyTable = RegInit(VecInit(Seq.fill(nSets)(0.U(nWays.W))))

    val debug_clock = RegInit(0.U(32.W))
    dontTouch(debug_clock)
    dontTouch(io)
    debug_clock := debug_clock + 1.U

    // reset
    val reseting = RegInit(true.B)
    val resetIdx = RegInit(0.U(nIdxBits.W))
    resetIdx := WrapInc(resetIdx, nSets)

    when(resetIdx === (nSets - 1).U) {
        reseting := false.B
    }

    when(reseting){

        for( i <- 0 until nSets){
            when(resetIdx === i.U){
                for(j <- 0 until nWays){
                    meta(i).write(j.U, 0.U.asTypeOf(new MetaLine))
                }
                dirtyTable(resetIdx) := 0.U
            }
        }
    }

    // Find dirtyLine
    val dirtySet = dirtyTable.map((x:UInt) => x.orR)
    val dirtyIdx = PriorityEncoder(dirtySet)
    val dirtyPos = PriorityEncoder(dirtyTable(dirtyIdx))
    val hasDirty = dirtySet.reduce(_||_)

    // 实时向外界反应是否有脏行
    io.fenceRead.resp.bits.hasDirty := hasDirty

    val lsu_R :: lsu_W :: mshr_R :: rpu_W :: replay_R :: replay_W :: fence_R :: fence_C :: none :: Nil = Enum(9)
    
    //read
    val readType = Wire(Vec(memWidth, UInt(3.W)))
    val readValid = Wire(Vec(memWidth, Bool()))
    val readIdx = Wire(Vec(memWidth, UInt(nIdxBits.W)))
    val readPos = Wire(Vec(memWidth, UInt(log2Ceil(nWays).W)))
    val readTag = Wire(Vec(memWidth, UInt(nTagBits.W)))
    val readResp = Wire(Vec(memWidth, Valid(new MetaResp)))
    readResp := 0.U.asTypeOf(Vec(memWidth, Valid(new MetaResp)))
    dontTouch(readType)
    dontTouch(readValid)
    dontTouch(readIdx)
    dontTouch(readPos)
    dontTouch(readTag)
    dontTouch(readResp)

    for(w <- 0 until memWidth){
        readType(w) := Mux(io.lsuRead(w).req.valid, lsu_R,
                        Mux(io.mshrRead.req.valid, mshr_R,
                        Mux(io.replayRead.req.valid, replay_R,
                        Mux(io.fenceRead.req.valid, fence_R,none))))

        readValid(w) := io.lsuRead(w).req.valid ||
                        io.mshrRead.req.valid ||
                        io.replayRead.req.valid ||
                        (io.fenceRead.req.valid && hasDirty)

        readIdx(w) := Mux(io.lsuRead(w).req.valid,io.lsuRead(w).req.bits.idx,
                        Mux(io.mshrRead.req.valid,io.mshrRead.req.bits.idx,
                        Mux(io.replayRead.req.valid,io.replayRead.req.bits.idx,
                        Mux(io.fenceRead.req.valid,dirtyIdx,0.U))))

        readPos(w) := Mux(io.lsuRead(w).req.valid,0.U, // in this case , it need do match to find a pos by itself
                        Mux(io.mshrRead.req.valid,io.mshrRead.req.bits.readPos,
                        Mux(io.replayRead.req.valid,io.replayRead.req.bits.readPos,
                        Mux(io.fenceRead.req.valid,dirtyPos,0.U))))
        
        // only lsu_R need Tag to match
        readTag(w) := Mux(io.lsuRead(w).req.valid, io.lsuRead(w).req.bits.tag, 0.U)
    }



    for(w <- 0 until memWidth){
        val rmetaSetChannel = Wire(Vec(nSets,Vec(nWays,new MetaLine)))
        val rmetaSet = Wire(Vec(nWays , new MetaLine))
        val ridx = RegNext(readIdx(w))
        val rpos = RegNext(readPos(w))

        for(i <- 0 until nSets){
            val readEn = readValid(w) && (readIdx(w) === i.U)
            for(j <- 0 until nWays){
                rmetaSetChannel(i)(j) := meta(i).read(j.U , readEn)
            }
        }
        readResp(w).valid := RegNext(readValid(w))
        rmetaSet := rmetaSetChannel(ridx)

        
        switch(RegNext(readType(w))){
            is(lsu_R){
                // isWrite用来触发Store的命中机制
                val wantWrite = RegNext(io.lsuRead(w).req.bits.isWrite)
                val blockAddr = RegNext(Cat(readTag(w), readIdx(w)))
                val rtag = RegNext(readTag(w))
                val hitoh = VecInit(rmetaSet.map((x: MetaLine) => (x.tag === rtag) &&
                  !(io.readOnlyBlockAddr.valid && (blockAddr === io.readOnlyBlockAddr.bits) && wantWrite)
                    // tag 要匹配，并且传进来的如果是一个试图访问只读块的store指令，就认为是miss
                )).asUInt

                val isfull = rmetaSet.map(_.valid).reduce(_ && _)
                val invalidPos = PriorityEncoder(VecInit(rmetaSet.map((x: MetaLine) => !(x.valid))).asUInt)

                val youngestPos = RegInit(0.U) //FindMin(VecInit(rmetaSet.map(_.age)), VecInit(rmetaSet.map(_.valid)))
                youngestPos := youngestPos + 1.U
                
                readResp(w).bits.hit := hitoh.orR

                readResp(w).bits.rmeta := rmetaSet(PriorityEncoder(hitoh))
//                命中取命中的路，未命中的话，满了取替换，没满取无效
                readResp(w).bits.pos := Mux(hitoh.orR , PriorityEncoder(hitoh),
                                        Mux(isfull , youngestPos , invalidPos))
            }
            is(replay_R){
                readResp(w).bits.rmeta := rmetaSet(rpos)
                readResp(w).bits.hit := true.B
                readResp(w).bits.pos := rpos
            }
            is(mshr_R){
                readResp(w).bits.rmeta := rmetaSet(rpos)
                readResp(w).bits.hit := DontCare
                readResp(w).bits.pos := DontCare
            }
            is(fence_R){
                readResp(w).bits.rmeta := rmetaSet(rpos)
                readResp(w).bits.hit := DontCare
                readResp(w).bits.idx := ridx
                readResp(w).bits.pos := rpos
            }
        }
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

    val writeType = Wire(Vec(memWidth, UInt(3.W)))
    val writeValid = Wire(Vec(memWidth, Bool()))
    val writeIdx = Wire(Vec(memWidth, UInt(nIdxBits.W)))
    val writePos = Wire(Vec(memWidth, UInt(log2Ceil(nWays).W)))
    val writeMeta = Wire(Vec(memWidth, new MetaLine))

    val writeResp = Wire(Vec(memWidth, Valid(new MetaResp)))
    writeResp := 0.U.asTypeOf(Vec(memWidth, Valid(new MetaResp)))

    for(w <- 0 until memWidth){
        writeType(w) := Mux(io.lsuWrite(w).req.valid,lsu_W,
                        Mux(io.rpuWrite.req.valid,rpu_W,
                        Mux(io.replayWrite.req.valid,replay_W,
                        Mux(io.fenceClean.req.valid,fence_C,none))))

        writeValid(w) := io.lsuWrite(w).req.valid || 
                         io.rpuWrite.req.valid || 
                         io.replayWrite.req.valid ||
                         io.fenceClean.req.valid

        writeIdx(w) := Mux(io.lsuWrite(w).req.valid,io.lsuWrite(w).req.bits.idx,
                        Mux(io.rpuWrite.req.valid,io.rpuWrite.req.bits.idx,
                        Mux(io.replayWrite.req.valid,io.replayWrite.req.bits.idx,
                        Mux(io.fenceClean.req.valid,dirtyIdx,0.U))))

        writePos(w) := Mux(io.lsuWrite(w).req.valid,io.lsuWrite(w).req.bits.writePos,
                        Mux(io.rpuWrite.req.valid,io.rpuWrite.req.bits.writePos,
                        Mux(io.replayWrite.req.valid,io.replayWrite.req.bits.writePos,
                        Mux(io.fenceClean.req.valid,dirtyPos,0.U))))

        writeMeta(w) := Mux(io.lsuWrite(w).req.valid,io.lsuWrite(w).req.bits.wmeta,
                        Mux(io.rpuWrite.req.valid,io.rpuWrite.req.bits.wmeta,
                        Mux(io.replayWrite.req.valid,io.replayWrite.req.bits.wmeta,
                        Mux(io.fenceClean.req.valid,0.U.asTypeOf(new MetaLine),0.U.asTypeOf(new MetaLine)))))
    }

    for(w <- 0 until memWidth){
        for(i <- 0 until nSets){
            val writeEn = !reseting && writeValid(w) && (writeIdx(w) === i.U)
            when(writeEn){
                meta(i).write(writePos(w), writeMeta(w))
                // dirtyTable 的维护
                switch(writeType(w)){
                    is(lsu_W){
                        dirtyTable(writeIdx(w)) := dirtyTable(writeIdx(w)) | ( 1.U << writePos(w)).asUInt
                    }
                    
                    is(replay_W){
                        dirtyTable(writeIdx(w)) := dirtyTable(writeIdx(w)) | ( 1.U << writePos(w)).asUInt
                    }
                    is(rpu_W){
                        dirtyTable(writeIdx(w)) := dirtyTable(writeIdx(w)) & (~(1.U << writePos(w)).asUInt)
                    }
                    is(fence_C){
                        dirtyTable(writeIdx(w)) := dirtyTable(writeIdx(w)) & (~(1.U << writePos(w)).asUInt)
                    }
                }
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
            is(fence_C){
                io.fenceClean.resp := writeResp(w)
            }
        }
    }

}
