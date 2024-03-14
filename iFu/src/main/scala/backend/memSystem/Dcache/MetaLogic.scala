
package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.util._


class MetaLine extends CoreBundle with HasDcacheParameters {
    val valid = Bool()
    val dirty = Bool()
    val readOnly = Bool()
    val fixed = Bool()
    val tag   = UInt(nTagBits.W)

    // No age here, it is preserved at MetaLogic , because we need 
    // hit or miss to decide how to update age
}


class DcacheMetaReq extends CoreBundle with HasDcacheParameters{
    val idx    = UInt(nIdxBits.W)
    // 读的时候用于匹配
    val tag    = UInt(nTagBits.W)
    // 读的时候的路号,写回时候的路号
    val pos = UInt(log2Ceil(nWays).W)

    // 要写回的行首信息
    val setvalid = Valid(Bool())
    val setdirty = Valid(Bool())
    val setfixed = Valid(Bool())
    val setreadOnly = Valid(Bool())
    // 写的时候作为新行的tag
    val setTag = Valid(UInt(nTagBits.W))


    // 用于判断是否是lsu的store指令,判断readOnly
    val isLsuStore = Bool()
    // 对于fence指令需要自己找脏行
    val isFence = Bool()

    val cacop_type = UInt(2.W)

}

// different with MetaResp, it return a single line
class DcacheMetaResp extends CoreBundle with HasDcacheParameters{
    val rmeta  = new MetaLine
    // 如果一个store命中了一个readOnly，就认为是miss
    val hit = Bool()

    // 用于fence通路实时向外界反应是否有脏行
    val hasDirty = Bool()

    // 指定接下来传到Data的idx , pos信息
    val idx = UInt(nIdxBits.W)
    val pos = UInt(log2Ceil(nWays).W)

}

class DcacheMetaIO extends CoreBundle with HasDcacheParameters{
    val req = Input(Valid(new DcacheMetaReq))
    val resp = Output(Valid(new DcacheMetaResp))
}

class DcacheMetaLogic extends Module with HasDcacheParameters{
    val io = IO(new CoreBundle{ 
        val lsuRead     = Vec( memWidth ,new DcacheMetaIO)
        val lsuWrite    = new DcacheMetaIO

        // 计算并拿到被替换的行，紧接着会发给总线那边
        val mshrRead    = new DcacheMetaIO

        // axi的读请求，经过总线mshrRead拿到一次地址之后，第一次进来拿的时候标记readOnly
        // axi的写回请求, 第一次来写的时候来meta废除掉对应行的valid
        val axiWrite    = new DcacheMetaIO

        // replay的读请求,用于mshr的replay
        val replayRead  = new DcacheMetaIO
        // replay的写请求,用于mshr的replay
        val replayWrite = new DcacheMetaIO

        val fenceRead   = new DcacheMetaIO
        val fenceWrite  = new DcacheMetaIO

        val cacopRead   = new DcacheMetaIO
        val cacopWrite  = new DcacheMetaIO
    })

    

    for(w <- 0 until memWidth){
        io.lsuRead(w).resp := 0.U.asTypeOf(Valid(new DcacheMetaResp))
    }
    io.lsuWrite.resp := 0.U.asTypeOf(Valid(new DcacheMetaResp))
    io.mshrRead.resp := 0.U.asTypeOf(Valid(new DcacheMetaResp))
    io.axiWrite.resp := 0.U.asTypeOf(Valid(new DcacheMetaResp))
    io.replayRead.resp := 0.U.asTypeOf(Valid(new DcacheMetaResp))
    io.replayWrite.resp := 0.U.asTypeOf(Valid(new DcacheMetaResp))
    io.fenceRead.resp := 0.U.asTypeOf(Valid(new DcacheMetaResp))
    io.fenceWrite.resp := 0.U.asTypeOf(Valid(new DcacheMetaResp))
    io.cacopRead.resp := 0.U.asTypeOf(Valid(new DcacheMetaResp))
    io.cacopWrite.resp := 0.U.asTypeOf(Valid(new DcacheMetaResp))


    val meta = Module(new DcacheMeta)
    // age在此维护
    val ages = RegInit(VecInit(Seq.fill(nSets)(VecInit(Seq.fill(nWays)(0.U(nAgeBits.W))))))

    val debug_clock = RegInit(0.U(32.W))
    dontTouch(io)
    debug_clock := debug_clock + 1.U



    val lsu_R :: lsu_W :: mshr_R :: axi_W :: replay_R :: replay_W :: fence_R :: fence_W :: cacop_R :: cacop_W :: none :: Nil = Enum(11)
    
    //read
    val haslsuRead = io.lsuRead.map(_.req.valid).reduce(_|_)

    val readType = Wire(UInt(4.W))
    val readValid = Wire(Vec(memWidth, Bool()))
    val readReq = Wire(Vec(memWidth, new DcacheMetaReq))
    val readIdx = Wire(Vec(memWidth, UInt(nIdxBits.W)))
    val readTag = Wire(Vec(memWidth, UInt(nTagBits.W)))
    val readPos = Wire(Vec(memWidth, UInt(log2Ceil(nWays).W)))
    val readResp = 0.U.asTypeOf(Vec(memWidth, Valid(new DcacheMetaResp)))
    dontTouch(readType)
    dontTouch(readIdx)
    dontTouch(readPos)
    dontTouch(readTag)
    dontTouch(readResp)

    for(w <- 0 until memWidth){
        readType :=  Mux(haslsuRead , lsu_R,
                        Mux(io.mshrRead.req.valid, mshr_R,
                        Mux(io.replayRead.req.valid, replay_R,
                        Mux(io.fenceRead.req.valid, fence_R,
                        Mux(io.cacopRead.req.valid, cacop_R,
                                                    none)))))

        readValid(w) := io.lsuRead(w).req.valid ||
                        io.mshrRead.req.valid ||
                        io.replayRead.req.valid ||
                        io.fenceRead.req.valid ||
                        io.cacopRead.req.valid

        readReq(w) := Mux(io.lsuRead(w).req.valid, io.lsuRead(w).req.bits,
                        Mux(io.mshrRead.req.valid, io.mshrRead.req.bits,
                        Mux(io.replayRead.req.valid, io.replayRead.req.bits,
                        Mux(io.fenceRead.req.valid, io.fenceRead.req.bits,
                        Mux(io.cacopRead.req.valid, io.cacopRead.req.bits,
                                                    0.U.asTypeOf(new DcacheMetaReq))))))

        readIdx(w) := Mux(io.lsuRead(w).req.valid, io.lsuRead(w).req.bits.idx,
                        Mux(io.mshrRead.req.valid, io.mshrRead.req.bits.idx,
                        Mux(io.replayRead.req.valid, io.replayRead.req.bits.idx,
                        Mux(io.fenceRead.req.valid, io.fenceRead.req.bits.idx,
                        
                        Mux(io.cacopRead.req.valid, io.cacopRead.req.bits.idx,
                                                    0.U(nIdxBits.W))))))


        readPos(w) := Mux(io.lsuRead(w).req.valid, io.lsuRead(w).req.bits.pos,
                        Mux(io.mshrRead.req.valid, io.mshrRead.req.bits.pos,
                        Mux(io.replayRead.req.valid, io.replayRead.req.bits.pos,
                        Mux(io.fenceRead.req.valid, io.fenceRead.req.bits.pos,
                
                        Mux(io.cacopRead.req.valid, io.cacopRead.req.bits.pos,
                                                    0.U(log2Ceil(nWays).W))))))

        // only lsuRead and cacopRead need tag 
        readTag(w) := Mux(io.lsuRead(w).req.valid, io.lsuRead(w).req.bits.tag,
                        Mux(io.cacopRead.req.valid, io.cacopRead.req.bits.tag,
                                                    0.U(nTagBits.W)))
                        

    }

    for(w<- 0 until memWidth){
        meta.io.read(w).req.valid := readValid(w)
        meta.io.read(w).req.bits := readReq(w)

        readResp(w).valid := meta.io.read(w).resp.valid
        // idx怎么进来的，就怎么出去 
        readResp(w).bits.idx := RegNext(readIdx(w))

        // 其他项根据情况在下面配置
    }



    for(w <- 0 until memWidth){
        
        val rmetaSet = meta.io.read(w).resp.bits.rmetaSet
        val dirtyIdx = meta.io.read(w).resp.bits.dirtyIdx
        val dirtyPos = meta.io.read(w).resp.bits.dirtyPos
        val rpos = RegNext(readPos(w))
        val ridx = RegNext(readIdx(w))
        

        switch(RegNext(readType)){
            is(lsu_R){
                // isLsuStore用来触发Store的命中机制
                val isLsuStore = RegNext(io.lsuRead(w).req.bits.isLsuStore)
                val rtag = RegNext(readTag(w))
                val hitoh = VecInit(rmetaSet.map((x: MetaLine) => x.valid && x.tag === rtag && 
                     !(x.readOnly && isLsuStore) // 如果是一个试图访问只读块的store指令，就认为是miss
                )).asUInt
                val hitpos = PriorityEncoder(hitoh)
                readResp(w).bits.hit := hitoh.orR
                readResp(w).bits.pos := hitpos
                readResp(w).bits.rmeta := rmetaSet(hitpos)

            }
            is(replay_R){
                
                // isLsuStore用来触发Store的命中机制
                // val isLsuStore = RegNext(io.lsuRead(w).req.bits.isLsuStore)
                // val rtag = RegNext(readTag(w))
                // val replay_hitoh = VecInit(rmetaSet.map((x: MetaLine) => x.valid && x.tag === rtag && 
                //      !(x.readOnly && isLsuStore) // 如果是一个试图访问只读块的store指令，就认为是miss
                // )).asUInt
                // val hitpos = PriorityEncoder(replay_hitoh)
                // readResp(w).bits.hit := replay_hitohhitoh.orR

                // assert(replay_hitoh.orR,"replayreq must hit")

                // readResp(w).bits.pos := hitpos
                readResp(w).bits.rmeta := rmetaSet(rpos)
                readResp(w).bits.hit := DontCare
                readResp(w).bits.idx := ridx
                readResp(w).bits.pos := rpos
            }
            is(mshr_R){
                
                val isfull = rmetaSet.map(_.valid).reduce(_ && _)
                // 读到的是一个set，里面有nWays个age
                val rAgeSet = ages(ridx)
                
                // 当前的替换策略暂时设置为，寻找valid为假且fixed为假的行
                val invalidPos =  PriorityEncoder(VecInit(rmetaSet.map((x: MetaLine) => !x.valid && !x.fixed)).asUInt)
                // 否则从fixed为假的行中挑一个
                // (暂时没设置真的youngest)
                // val youngestPos = PriorityEncoder(VecInit(rmetaSet.map((x: MetaLine) => !x.fixed)).asUInt)
                
                // 这是随机替换策略
                val youngestPos = debug_clock(log2Ceil(nWays)-1,0)
                //满了取替换，没满取无效
                val replacePos = Mux(isfull, youngestPos, invalidPos)

                // 得以替换的路
                readResp(w).bits.pos := replacePos
                // 可能读到的是有效的，也可能是无效的行 ,送到axi那边自行判断要不要先写回总线
                readResp(w).bits.rmeta := rmetaSet(replacePos)
            }


            is(fence_R){
                // fence 从返回对应脏行的meta和位置信息
                readResp(w).bits.rmeta := rmetaSet(dirtyPos)
                readResp(w).bits.hit := DontCare
                readResp(w).bits.idx := dirtyIdx
                readResp(w).bits.pos := dirtyPos
            }

            // TODO cacop_R
        }
    }

    for(w <- 0 until memWidth){
        switch(RegNext(readType)){
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

    // 这个hasDirty要始终通过fenceRead返回hasDirty给外界
    io.fenceRead.resp.bits.hasDirty := meta.io.hasDirty


    //write
    //这个resp和meta数据的resp类型有区别
    val writeResp = Wire(Valid(new DcacheMetaResp))
    writeResp := 0.U.asTypeOf(Valid(new DcacheMetaResp))

    val writeValid = io.lsuWrite.req.valid ||
                     io.axiWrite.req.valid ||
                     io.replayWrite.req.valid ||
                     io.fenceWrite.req.valid ||
                     io.cacopWrite.req.valid

    val writeType   = Mux(io.lsuWrite.req.valid,lsu_W,
                    Mux(io.axiWrite.req.valid,axi_W,
                    Mux(io.replayWrite.req.valid,replay_W,
                    Mux(io.fenceWrite.req.valid,fence_W,
                    Mux(io.cacopWrite.req.valid,cacop_W,
                                                none)))))
    val writeReq    = Mux(io.lsuWrite.req.valid, io.lsuWrite.req.bits,
                    Mux(io.axiWrite.req.valid, io.axiWrite.req.bits,
                    Mux(io.replayWrite.req.valid, io.replayWrite.req.bits,
                    Mux(io.fenceWrite.req.valid, io.fenceWrite.req.bits,
                    Mux(io.cacopWrite.req.valid, io.cacopWrite.req.bits,
                                                0.U.asTypeOf(new DcacheMetaReq))))))

    // write 的行为由传入方定义好了,因此此处统一正常读写就好
    meta.io.write.req.valid := writeValid
    meta.io.write.req.bits := writeReq
    // 写meta没什么好返回的,返回一个valid就好
    writeResp.valid := meta.io.write.resp.valid

    switch(RegNext(writeType)){
        is(lsu_W){
            io.lsuWrite.resp := writeResp
        }
        is(axi_W){
            io.axiWrite.resp := writeResp
        }
        is(replay_W){
            io.replayWrite.resp := writeResp
        }
        is(fence_W){
            io.fenceWrite.resp := writeResp
        }
        is(cacop_W){
            io.cacopWrite.resp := writeResp
        }
    }

}
