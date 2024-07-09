
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
    val isStore = Bool()
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
        val missReplace  = new DcacheMetaIO

        // axi的读请求，用于判断快速refill报废一行
        val refillLogout = new DcacheMetaIO//axiread
        // axi的写回请求, 第一次来写的时候来meta废除掉对应行的valid
        val wfuWrite    = new DcacheMetaIO
        // mshr 送给wfu一行去wb，期间该行不能被修改
        val lineFreeze = new DcacheMetaIO

        // replay的读请求,用于mshr的replay
        val replayRead  = new DcacheMetaIO
        // replay的写请求,用于mshr的replay
        val replayWrite = new DcacheMetaIO

        // fence
        val fetchDirty   = new DcacheMetaIO
        val lineClear  = new DcacheMetaIO

        val cacopRead   = new DcacheMetaIO
        val cacopWrite  = new DcacheMetaIO
    })

    
    for(w <- 0 until memWidth){
        io.lsuRead(w).resp := 0.U.asTypeOf(Valid(new DcacheMetaResp))
    }
    io.lsuWrite.resp := 0.U.asTypeOf(Valid(new DcacheMetaResp))
    io.missReplace.resp := 0.U.asTypeOf(Valid(new DcacheMetaResp))
    io.refillLogout.resp := 0.U.asTypeOf(Valid(new DcacheMetaResp))
    io.wfuWrite.resp := 0.U.asTypeOf(Valid(new DcacheMetaResp))
    io.lineFreeze.resp := 0.U.asTypeOf(Valid(new DcacheMetaResp))
    io.replayRead.resp := 0.U.asTypeOf(Valid(new DcacheMetaResp))
    io.replayWrite.resp := 0.U.asTypeOf(Valid(new DcacheMetaResp))
    io.fetchDirty.resp := 0.U.asTypeOf(Valid(new DcacheMetaResp))
    io.lineClear.resp := 0.U.asTypeOf(Valid(new DcacheMetaResp))
    io.cacopRead.resp := 0.U.asTypeOf(Valid(new DcacheMetaResp))
    io.cacopWrite.resp := 0.U.asTypeOf(Valid(new DcacheMetaResp))


    val meta = Module(new DcacheMeta)
    // age在此维护
    val ages = RegInit(VecInit(Seq.fill(nSets)(VecInit(Seq.fill(nWays)(0.U(nAgeBits.W))))))

    val debug_clock = RegInit(0.U(32.W))
    if(!FPGAPlatform)dontTouch(io)
    debug_clock := debug_clock + 1.U



    val lsu_R :: lsu_W :: miss_R :: refill_L :: axi_W :: line_F :: replay_R :: replay_W :: fence_R :: fence_W :: cacop_R :: cacop_W :: none :: Nil = Enum(13)
    
    //read
    val haslsuRead = io.lsuRead.map(_.req.valid).reduce(_|_)

    val readType = Wire(UInt(4.W))
    val readValid = Wire(Vec(memWidth, Bool()))
    val readReq = Wire(Vec(memWidth, new DcacheMetaReq))
    val readIdx = Wire(Vec(memWidth, UInt(nIdxBits.W)))
    val readTag = Wire(Vec(memWidth, UInt(nTagBits.W)))
    val readPos = Wire(Vec(memWidth, UInt(log2Ceil(nWays).W)))
    val readResp = 0.U.asTypeOf(Vec(memWidth, Valid(new DcacheMetaResp)))
    // lsureadinfo
    val hitoh = Wire(Vec(memWidth, UInt(nWays.W)))

    if(!FPGAPlatform)dontTouch(readType)
    if(!FPGAPlatform)dontTouch(readIdx)
    if(!FPGAPlatform)dontTouch(readPos)
    if(!FPGAPlatform)dontTouch(readTag)
    if(!FPGAPlatform)dontTouch(readResp)
    if(!FPGAPlatform)dontTouch(hitoh)

    for(w <- 0 until memWidth){
        readType := Mux(io.missReplace.req.valid, miss_R,
                    Mux(io.replayRead.req.valid, replay_R,
                    Mux(io.fetchDirty.req.valid, fence_R,
                    Mux(io.cacopRead.req.valid, cacop_R,
                    Mux(io.refillLogout.req.valid, refill_L,
                                                lsu_R)))))

        readValid(w) := io.lsuRead(w).req.valid ||
                        io.missReplace.req.valid ||
                        io.replayRead.req.valid ||
                        io.fetchDirty.req.valid ||
                        io.cacopRead.req.valid ||
                        io.refillLogout.req.valid

        readReq(w) :=   Mux(io.missReplace.req.valid, io.missReplace.req.bits,
                        Mux(io.fetchDirty.req.valid, io.fetchDirty.req.bits,
                                                    io.lsuRead(w).req.bits))

        readIdx(w) :=   Mux(io.missReplace.req.valid, io.missReplace.req.bits.idx,
                        Mux(io.replayRead.req.valid, io.replayRead.req.bits.idx,
                        Mux(io.refillLogout.req.valid , io.refillLogout.req.bits.idx,
                                                    io.lsuRead(w).req.bits.idx)))


        readPos(w) :=   Mux(io.replayRead.req.valid, io.replayRead.req.bits.pos,
                        Mux(io.refillLogout.req.valid , io.refillLogout.req.bits.pos,
                                                    0.U(log2Ceil(nWays).W)))

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
        // lsu read
        hitoh(w) := 0.U
    }


    // 一些信息的s2内部转发
    val s2_inv_val = RegInit(false.B)
    val s2_inv_idx = RegInit(0.U(nIdxBits.W))
    val s2_inv_mask = RegInit(0.U(nWays.W))
    val s2Dirval = RegInit(false.B)
    val s2Diridx = RegInit(0.U(nIdxBits.W))
    val s2Dirpos = RegInit(0.U(log2Ceil(nWays).W))
    val s2Refillval = RegInit(false.B)
    val s2Refillidx = RegInit(0.U(nIdxBits.W))
    val s2Refillpos = RegInit(0.U(log2Ceil(nWays).W))

    dontTouch(s2_inv_val)
    dontTouch(s2_inv_idx)
    dontTouch(s2_inv_mask)
    dontTouch(s2Dirval)
    dontTouch(s2Diridx)
    dontTouch(s2Dirpos)
    dontTouch(s2Refillval)
    dontTouch(s2Refillidx)
    dontTouch(s2Refillpos)

    s2_inv_val := false.B
    s2_inv_idx := 0.U
    s2_inv_mask := 0.U
    s2Dirval := false.B
    s2Diridx := 0.U
    s2Dirpos := 0.U
    s2Refillval := false.B
    s2Refillidx := 0.U
    s2Refillpos := 0.U

    for(w <- 0 until memWidth){
        
        val rmetaSet = meta.io.read(w).resp.bits.rmetaSet
        val dirtyIdx = meta.io.read(w).resp.bits.dirtyIdx
        val dirtyPos = meta.io.read(w).resp.bits.dirtyPos
        val rpos = RegNext(readPos(w))
        val ridx = RegNext(readIdx(w))
        
        val isLsuStore = RegNext(io.lsuRead(w).req.bits.isStore)
        val isReplayStore = RegNext(io.replayRead.req.bits.isStore)

        switch(RegNext(readType)){
            is(lsu_R){
                // isLsuStore用来触发Store的命中机制
                
                val rtag = RegNext(readTag(w))// no need RegNext(readTag(w)) , because  the tag is from io.lsu.s1_paddr
                hitoh(w) := VecInit(rmetaSet.map((x: MetaLine) => x.valid && x.tag === rtag /* && */
                    // 如果是一个试图访问只读块(这行被设置成只读，或者上个周期有条missReplace将把这里设置成只读)的store指令，就认为是miss
                     /* !( isLsuStore && (x.readOnly || (s2ROval && s2ROtag === rtag && s2ROidx === ridx))) */
                     )).asUInt & ~(s2_inv_mask & Fill (nWays, s2_inv_val && s2_inv_idx === ridx))
                assert(PopCount(hitoh(w)) <= 1.U,"At most one hit")
                val hitpos = PriorityEncoder(hitoh(w))
                //  如果是被refill第一个字报废的行，此时算未命中(由于现在在mshr_replace就一定会报废掉这一行，之后没必要wb refill 报废了)
                readResp(w).bits.hit := hitoh(w).orR /* && !( s2Refillval && s2Refillidx === ridx && s2Refillpos === hitpos) */
                readResp(w).bits.pos := hitpos
                readResp(w).bits.rmeta := rmetaSet(hitpos)
                
                when(hitoh(w).orR && isLsuStore){
                    // 如果是一个命中的store指令，存s2Dir信息，以防来不及告诉下个周期的missReplace这里脏了
                    s2Dirval := true.B
                    s2Diridx := ridx
                    s2Dirpos := hitpos
                }
            }
            is(replay_R){
                
                // isLsuStore用来触发Store的命中机制
                
                // val rtag = RegNext(readTag(w))
                // val replay_hitoh = VecInit(rmetaSet.map((x: MetaLine) => x.valid && x.tag === rtag && 
                //      !(x.readOnly && isLsuStore) // 如果是一个试图访问只读块的store指令，就认为是miss
                // )).asUInt
                // val hitpos = PriorityEncoder(replay_hitoh)
                // readResp(w).bits.hit := replay_hitohhitoh.orR

                // assert(replay_hitoh.orR,"replayreq must hit")
                // readResp(w).bits.pos := hitpos
                readResp(w).bits.rmeta := DontCare
                readResp(w).bits.hit := DontCare
                readResp(w).bits.idx := ridx
                // readResp(w).bits.pos := rpos

                when(isReplayStore){
                    // 如果是一个replay的store指令，存s2Dir信息，以防来不及告诉下个周期的missReplace这里脏了
                    s2Dirval := true.B
                    s2Diridx := ridx
                    s2Dirpos := rpos
                }
            }
            is(miss_R){
                
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
                // 做快速dirty的转发
                when(s2Dirval && s2Diridx === ridx && s2Dirpos === replacePos){
                    readResp(w).bits.rmeta.dirty := true.B
                }
                
                // 记录这个s1取出来的，该被设为readOnly的行的信息
                s2_inv_val := true.B
                s2_inv_idx := ridx
                s2_inv_mask := UIntToOH(replacePos)
            }

            is(fence_R){
                // fence 从返回对应脏行的meta和位置信息
                readResp(w).bits.rmeta := rmetaSet(dirtyPos)
                readResp(w).bits.hit := DontCare
                readResp(w).bits.idx := dirtyIdx
                readResp(w).bits.pos := dirtyPos
            }

            is(refill_L){
                // 记录第一个字refill来，以便报废那一行
                s2Refillval := true.B
                s2Refillidx := ridx
                s2Refillpos := rpos
            }

            // TODO cacop_R
        }
    }

    for(w <- 0 until memWidth){
        switch(RegNext(readType)){
            is(lsu_R){
                io.lsuRead(w).resp := readResp(w)
            }
            is(miss_R){
                io.missReplace.resp := readResp(w)
            }
            is(replay_R){
                io.replayRead.resp := readResp(w)
            }
            is(fence_R){
                io.fetchDirty.resp := readResp(w)

            }
        }
    }

    // 这个hasDirty要始终通过fetchDirty返回hasDirty给外界
    io.fetchDirty.resp.bits.hasDirty := meta.io.hasDirty


    //write
    //这个resp和meta数据的resp类型有区别
    val writeResp = Wire(Valid(new DcacheMetaResp))
    writeResp := 0.U.asTypeOf(Valid(new DcacheMetaResp))

    val writeValid = io.lsuWrite.req.valid ||
                     io.wfuWrite.req.valid ||
                     io.lineFreeze.req.valid ||
                     io.replayWrite.req.valid ||
                     io.lineClear.req.valid ||
                     io.cacopWrite.req.valid

    val writeType   = Mux(io.lsuWrite.req.valid,lsu_W,
                    Mux(io.wfuWrite.req.valid,axi_W,
                    Mux(io.lineFreeze.req.valid,line_F,
                    Mux(io.replayWrite.req.valid,replay_W,
                    Mux(io.lineClear.req.valid,fence_W,
                    Mux(io.cacopWrite.req.valid,cacop_W,
                                                none))))))
    val writeReq    = Mux(io.lsuWrite.req.valid, io.lsuWrite.req.bits,
                    Mux(io.wfuWrite.req.valid, io.wfuWrite.req.bits,
                    Mux(io.lineFreeze.req.valid, io.lineFreeze.req.bits,
                    Mux(io.replayWrite.req.valid, io.replayWrite.req.bits,
                    Mux(io.lineClear.req.valid, io.lineClear.req.bits,
                    Mux(io.cacopWrite.req.valid, io.cacopWrite.req.bits,
                                                0.U.asTypeOf(new DcacheMetaReq)))))))

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
            io.wfuWrite.resp := writeResp
        }
        is(line_F){
            io.lineFreeze.resp := writeResp
        }
        is(replay_W){
            io.replayWrite.resp := writeResp
        }
        is(fence_W){
            io.lineClear.resp := writeResp
        }
        is(cacop_W){
            io.cacopWrite.resp := writeResp
        }
    }

}
