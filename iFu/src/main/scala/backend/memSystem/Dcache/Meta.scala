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
    val isWrite = Bool()
    val wmeta = new MetaLine

    // mshr来读meta的时候所选择的路
    val replacePos = UInt(log2Ceil(nWays).W)

    // replay将命中的路
    val hitPos = UInt(log2Ceil(nWays).W)

    // 将要写入的路
    val writePos = UInt(log2Ceil(nWays).W)
}

class MetaResp extends CoreBundle with HasDcacheParameters{
    // 用valid来表示是否命中
    val rmeta  = new MetaLine
    // 如果一个store命中了一个readOnly，就认为是miss
    val hit = Bool()
    val hitPos = UInt(log2Ceil(nWays).W)
    // 如果没有命中的时候，可以进行替换的位置
    val replacePos = UInt(log2Ceil(nWays).W)
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
        
        // val reset = Input(Bool())

        val hasDirty  = Output(Bool())
        val dirtyMeta = Output(new MetaLine)
        val dirtyIdx  = Output(UInt(nIdxBits.W))
        val dirtyPos  = Output(UInt(log2Ceil(nWays).W))

        val fenceTakeDirtyMeta = Input(Bool()) //拿走一个脏行，之后就将其

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
        io.dirtyIdx := RegNext(dirtyIdx)
        io.dirtyPos := RegNext(dirtyPos)
        io.hasDirty := RegNext(dirtySet.reduce(_||_))
        // val dirtyMeta = meta.read(dirtyIdx, true.B)(dirtyPos)
        val dirtyMeta = Wire(new MetaLine)
        dirtyMeta := 0.U.asTypeOf(new MetaLine)
        for(w <- 0 until nSets){
            when(dirtyIdx === w.U){
                dirtyMeta := meta(w).read(dirtyPos)
            }
        }
        io.dirtyMeta := dirtyMeta

        when (io.fenceTakeDirtyMeta) {
            // dirtyTable对应位置0,将这个脏行直接全0覆盖
            dirtyTable(dirtyIdx) := dirtyTable(dirtyIdx).asUInt & (~(1.asUInt << dirtyPos)).asUInt
            // meta.write(dirtyIdx, VecInit(Seq.fill(nWays)(dirtyMeta)), cleanedMask.asBools)
            for(w <- 0 until nSets){
                when(dirtyIdx === w.U){
                    meta(w).write(dirtyPos,0.U.asTypeOf(new MetaLine))
                }
            }
        }
    // lsuRead
    for(w <- 0 until memWidth){

        // val rmetaSet = meta.read(io.lsuRead(w).req.bits.idx, io.lsuRead(w).req.valid)
        // val rmetaSet =   meta(io.lsuRead(w).req.bits.idx).read(0.U, nWays)
        val rmetaSetChannel = Wire(Vec(nSets,Vec(nWays, new MetaLine)))
        val rmetaSet = Wire(Vec(nWays, new MetaLine))
        rmetaSet := 0.U.asTypeOf(Vec(nWays, new MetaLine))
        val ridx = RegNext(io.lsuRead(w).req.bits.idx)
        // val rmetaSet = VecInit((0 until nWays).map(i => meta(io.lsuRead(w).req.bits.idx).read(i.U))
        for(i <- 0 until nSets){
            // 这里的时序是，先当周期传递valid信号到read函数，让各个Mem去读读取各个meta的Set的所有内容
            // ，然后一周期以后再根据RegNext(idx)选择对应的Set，从而实现rmetaSet有一个周期的延迟
            val lsuReadEn = io.lsuRead(w).req.valid && (io.lsuRead(w).req.bits.idx === i.U)
            for(j <- 0 until nWays){
                rmetaSetChannel(i)(j) := meta(i).read(j.U , lsuReadEn)
            }
        }

        rmetaSet := rmetaSetChannel(ridx)
        // isWrite用来触发Store的命中机制
        val wantWrite = io.lsuRead(w).req.bits.isWrite
        val blockAddr = Cat(io.lsuRead(w).req.bits.tag, io.lsuRead(w).req.bits.idx)
        val hitoh = VecInit(rmetaSet.map((x: MetaLine) => (x.tag === RegNext(io.lsuRead(w).req.bits.tag)) &&
          !(io.readOnlyBlockAddr.valid &&  (RegNext(blockAddr) === io.readOnlyBlockAddr.bits) && RegNext(wantWrite))
            // tag 要匹配，并且传进来的如果是一个试图访问只读块的store指令，就认为是miss
        )).asUInt

        val isfull = rmetaSet.map(_.valid).reduce(_ && _)
        val invalidPos = PriorityEncoder(VecInit(rmetaSet.map((x: MetaLine) => !(x.valid))).asUInt)

        val youngestPos = RegInit(0.U)//FindMin(VecInit(rmetaSet.map(_.age)), VecInit(rmetaSet.map(_.valid)))
        youngestPos := youngestPos +1.U

        io.lsuRead(w).resp.valid := RegNext(io.lsuRead(w).req.valid)
        io.lsuRead(w).resp.bits.hit := hitoh.orR
        io.lsuRead(w).resp.bits.hitPos := PriorityEncoder(hitoh)
        io.lsuRead(w).resp.bits.rmeta := rmetaSet(PriorityEncoder(hitoh))
        io.lsuRead(w).resp.bits.replacePos := Mux(isfull, youngestPos , invalidPos)

        // when(io.lsuRead(w).req.valid && debug_clock < 150.U){
        //     printf(p"clock:${debug_clock}\n")
        //     printf(p"lsuRead($w).req.bits.idx:${io.lsuRead(w).req.bits.idx}\n")
        //     printf(p"lsuRead($w).req.bits.tag:${io.lsuRead(w).req.bits.tag}\n")
        //     printf(p"hitoh:${hitoh}\n")
        // }


        
    }

    // lsuWrite
    for(w <- 0 until memWidth){
        
        // when(io.lsuWrite(w).req.valid && debug_clock < 150.U){
        //     printf(p"clock:${debug_clock}\n")
        //     printf(p"lsuWrite($w).req.bits.idx:${io.lsuWrite(w).req.bits.idx}\n")
        //     printf(p"lsuWrite($w).req.bits.wayMask:${io.lsuWrite(w).req.bits.wayMask}\n")
        //     printf(p"lsuWrite($w).req.bits.wmeta:\n${io.lsuWrite(w).req.bits.wmeta}\n")
        // }



        when(!reseting && io.lsuWrite(w).req.valid && io.lsuWrite(w).req.bits.isWrite){
            // meta.write(io.lsuWrite(w).req.bits.idx, VecInit(Seq.fill(nWays)(io.lsuWrite(w).req.bits.wmeta)), io.lsuWrite(w).req.bits.wayMask.asBools)
            // meta(io.lsuWrite(w).req.bits.idx).write(io.lsuWrite(w).req.bits.writePos, io.lsuWrite(w).req.bits.wmeta)

            // 对于写的时序来说,当周期传递信息,这条write函数语句就会在下一周期完成写回,不用RegNext控制idx去筛选
            // 对比,读的时候,是赋值语句,等号右边会当成是所有setmeta都执行一遍的值,然后根据idx去筛选,这样就需要RegNext控制idx
            // 而写的时候,是写函数,没有赋值,因此这条语句是条件执行,只有当idx符合的时候才会在对应的SyncReadMem执行,因此不需要RegNext控制idx
            for(i <- 0 until nSets){
                when(io.lsuWrite(w).req.bits.idx === i.U){
                    meta(i).write(io.lsuWrite(w).req.bits.writePos, io.lsuWrite(w).req.bits.wmeta)
                }
            }
            // 维护dirtyTable
            dirtyTable(io.lsuWrite(w).req.bits.idx) := dirtyTable(io.lsuWrite(w).req.bits.idx) | ( 1.U << io.lsuWrite(w).req.bits.writePos).asUInt
        }

        io.lsuWrite(w).resp.valid := RegNext(io.lsuWrite(w).req.valid)
        io.lsuWrite(w).resp.bits := DontCare

    }

    // mshrRead
    // val replacePos = RegNext(io.mshrRead.req.bits.replacePos)
    // val replaceMetaSet = meta.read(io.mshrRead.req.bits.idx, io.mshrRead.req.valid)
    val replaceMetaChannel = Wire(Vec(nSets, new MetaLine))
    val replaceidx = RegNext(io.mshrRead.req.bits.idx)
    // meta(io.mshrRead.req.bits.idx).read(io.mshrRead.req.bits.replacePos, io.mshrRead.req.valid)
    for(i <- 0 until nSets){
        val mshrReadEn = io.mshrRead.req.valid && (io.mshrRead.req.bits.idx === i.U)
        replaceMetaChannel(i) := meta(i).read(io.mshrRead.req.bits.replacePos, mshrReadEn)
    }
    io.mshrRead.resp.valid := RegNext(io.mshrRead.req.valid)
    io.mshrRead.resp.bits.rmeta := replaceMetaChannel(replaceidx)
    io.mshrRead.resp.bits.hit := DontCare
    io.mshrRead.resp.bits.hitPos := DontCare
    io.mshrRead.resp.bits.replacePos := DontCare

        // rpuWrite
    when(!reseting && io.rpuWrite.req.valid && io.rpuWrite.req.bits.isWrite){


        // when(io.rpuWrite.req.bits.wmeta.valid && debug_clock < 150.U){
        //     printf(p"clock:${debug_clock}\n")
        //     printf(p"rpuWrite.req.bits.idx:${ io.rpuWrite.req.bits.idx}\n")
        //     printf(p"rpuWrite.req.bits.wayMask:${io.rpuWrite.req.bits.wayMask}\n")
        //     printf(p"rpuWrite.req.bits.wmeta:\n${io.rpuWrite.req.bits.wmeta}\n")
        // }


        // meta.write(io.rpuWrite.req.bits.idx, VecInit(Seq.fill(nWays)(io.rpuWrite.req.bits.wmeta)), io.rpuWrite.req.bits.wayMask.asBools)
        // meta(io.rpuWrite.req.bits.idx).write(io.rpuWrite.req.bits.writePos, io.rpuWrite.req.bits.wmeta)
        for(i <- 0 until nSets){
            when(io.rpuWrite.req.bits.idx === i.U){
                meta(i).write(io.rpuWrite.req.bits.writePos, io.rpuWrite.req.bits.wmeta)
            }
        }
        // 维护dirtyTable,RPU写回的一定是干净的，因此把对应位置的dirty位清零
        // dirtyTable(io.rpuWrite.req.bits.idx) := dirtyTable(io.rpuWrite.req.bits.idx) | ( io.rpuWrite.req.bits.wayMask & Fill(nWays,io.rpuWrite.req.bits.wmeta.dirty)).asUInt
        dirtyTable(io.rpuWrite.req.bits.idx) := dirtyTable(io.rpuWrite.req.bits.idx) & (~(1.U << io.rpuWrite.req.bits.writePos)).asUInt
    }
    io.rpuWrite.resp.valid := RegNext(io.rpuWrite.req.valid)
    io.rpuWrite.resp.bits := DontCare


    // replayRead
    // val hitPos = RegNext(io.replayRead.req.bits.hitPos)
    // val hitMetaSet = meta.read(io.replayRead.req.bits.idx, io.replayRead.req.valid)
    val hitMetaChannel = Wire(Vec(nSets, new MetaLine))
    val hitidx = RegNext(io.replayRead.req.bits.idx)
    // meta(io.replayRead.req.bits.idx).read(io.replayRead.req.bits.hitPos, io.replayRead.req.valid)
    for(i <- 0 until nSets){
        val replayReadEn = io.replayRead.req.valid && (io.replayRead.req.bits.idx === i.U)
        hitMetaChannel(i) := meta(i).read(io.replayRead.req.bits.hitPos, replayReadEn)
    }
    io.replayRead.resp.valid := RegNext(io.replayRead.req.valid)
    io.replayRead.resp.bits.rmeta := hitMetaChannel(hitidx)
    io.replayRead.resp.bits.hit := true.B
    io.replayRead.resp.bits.hitPos := RegNext(io.replayRead.req.bits.hitPos)
    io.replayRead.resp.bits.replacePos := DontCare


    //replayWrite
    when(!reseting && io.replayWrite.req.valid && io.replayWrite.req.bits.isWrite) {
        // when(io.replayWrite.req.bits.wmeta.valid && debug_clock < 150.U){
        //     printf(p"clock:${debug_clock}\n")
        //     printf(p"replayWrite.req.bits.idx:${io.replayWrite.req.bits.idx}\n")
        //     printf(p"replayWrite.req.bits.wayMask:${io.replayWrite.req.bits.wayMask}\n")
        //     printf(p"replayWrite.req.bits.wmeta:\n${io.replayWrite.req.bits.wmeta}\n")
        // }
        // meta.write(io.replayWrite.req.bits.idx, VecInit(Seq.fill(nWays)(io.replayWrite.req.bits.wmeta)), io.replayWrite.req.bits.wayMask.asBools)
        // meta(io.replayWrite.req.bits.idx).write(io.replayWrite.req.bits.writePos, io.replayWrite.req.bits.wmeta)
        for(i <- 0 until nSets){
            when(io.replayWrite.req.bits.idx === i.U){
                meta(i).write(io.replayWrite.req.bits.writePos, io.replayWrite.req.bits.wmeta)
            }
        }
        // 维护dirtyTable
        dirtyTable(io.replayWrite.req.bits.idx) := dirtyTable(io.replayWrite.req.bits.idx) | ( 1.U << io.replayWrite.req.bits.writePos).asUInt
    }
    io.replayWrite.resp.valid := RegNext(io.replayWrite.req.valid)
    io.replayWrite.resp.bits := DontCare

}
