
package iFu.backend

import chisel3._
import chisel3.util._

import iFu.axi3._
import iFu.sma._

import iFu.common._
import iFu.common.Consts._
import iFu.util._


import iFu.difftest._

trait HasDcacheParameters extends HasCoreParameters{
    val nTagBits       = dcacheParameters.nTagBits
    val nIdxBits       = dcacheParameters.nIdxBits
    val nOffsetBits    = dcacheParameters.nOffsetBits
    val n1vIdxBits     = dcacheParameters.n1vIdxBits
    val nAgeBits       = dcacheParameters.nAgebits
    val nRowBits       = dcacheParameters.nRowBits
    val nRowBytes      = dcacheParameters.nRowBytes
    val nRowWords      = dcacheParameters.nRowWords
    val nTotalWords    = dcacheParameters.nTotalWords
    val nSets          = dcacheParameters.nSets
    val nWays          = dcacheParameters.nWays
    val coreDataBits   = dcacheParameters.coreDataBits
    val nBlockAddrBits = dcacheParameters.nBlockAddrBits
    val nFirstMSHRs    = dcacheParameters.nFirstMSHRs
    val nSecondMSHRs   = dcacheParameters.nSecondMSHRs

    def getWordOffset(vaddr: UInt): UInt    = dcacheParameters.getWordOffset(vaddr)
    def getIdx(vaddr: UInt): UInt       = dcacheParameters.getIdx(vaddr)
    def getTag(vaddr: UInt): UInt       = dcacheParameters.getTag(vaddr)
    def getBlockAddr(vaddr: UInt): UInt = dcacheParameters.getBlockAddr(vaddr)
    def isStore(req : DCacheReq): Bool  = dcacheParameters.isStore(req)

    def isMMIO(req : DCacheReq): Bool  = dcacheParameters.isMMIO(req)

    def isLL(req : DCacheReq): Bool  = dcacheParameters.isLL(req)

    def isSC(req: DCacheReq): Bool = dcacheParameters.isSC(req)
}

class DCacheBundle  extends CoreBundle with HasDcacheParameters{
    // val error = new DCacheErrors
    val lsu = Flipped(new LSUDMemIO)
    val smar = Vec(2, new SMAR)
    val smaw = Vec(2, new SMAW)
}


class NonBlockingDcache extends Module with HasDcacheParameters{
    val io = IO(new DCacheBundle)

    // 解释:
    // replay : mshr的replay请求
    // refill : wfu的重填数据请求
    // lsu : lsu的请求
    // prefetch : prefetch的请求
    // replace_find : mshr的fetch请求(期间会读取meta,送给WFU)
    // nil : 什么都不做
    // fence_read : 清空所有的dirty行

    io.lsu.req.ready := false.B
    for(w <- 0 until memWidth){
        io.lsu.resp(w) := 0.U.asTypeOf(new Valid(new DCacheResp))
    }

    for (w <- 0 until memWidth) {
        io.lsu.nack(w) := 0.U.asTypeOf(new Valid(new DCacheReq))
    }


    val replay :: wb :: refill ::  replace_find :: lsu :: mmio_req :: mmio_resp  :: prefetch  :: fence_read :: fence_clear :: cacop :: nil :: Nil = Enum(12)

    val mmiou = Module(new MMIOUnit) 
    mmiou.io.mmioReq.valid := false.B
    mmiou.io.mmioReq.bits := 0.U.asTypeOf(new DCacheReq)
    
    io.smaw(0) <> mmiou.io.smaw
    io.smar(0) <> mmiou.io.smar

    // 替换单元
    val wfu = Module(new WriteFetchUnit)
    wfu.io.req_valid := false.B
    wfu.io.req_addr := 0.U
    wfu.io.meta_resp := 0.U.asTypeOf(new DcacheMetaResp)
    wfu.io.req_wb_only := false.B
    wfu.io.wfu_read_resp := 0.U.asTypeOf(Valid(new DCacheResp))
    io.smaw(1) <> wfu.io.smaw
    io.smar(1) <> wfu.io.smar

    val wbValid = wfu.io.wfu_read_req.valid
    val refillValid = wfu.io.wfu_write_req.valid

    
    // 判断axi会空闲的要求是,wfu和mmiou都要ready,并且流水线中没有正在运行的replace_find,wb,refill和mmioreq,mmio_resp
    
    val mmiouReady = WireInit(false.B)
    val wfuReady = WireInit(false.B)


    // 存储meta信息
    val meta = Module(new DcacheMetaLogic)

    // 端口设置
    meta.io.lsuRead(0).req := 0.U.asTypeOf(Valid(new DcacheMetaReq))
    meta.io.lsuRead(1).req := 0.U.asTypeOf(Valid(new DcacheMetaReq))

    meta.io.lsuWrite.req := 0.U.asTypeOf(Valid(new DcacheMetaReq))
    
    meta.io.missReplace.req := 0.U.asTypeOf(Valid(new DcacheMetaReq))

    meta.io.refillLogout.req := 0.U.asTypeOf(Valid(new DcacheMetaReq))

    meta.io.lineFreeze.req := 0.U.asTypeOf(Valid(new DcacheMetaReq))

    meta.io.wfuWrite.req := 0.U.asTypeOf(Valid(new DcacheMetaReq))
    
    meta.io.replayRead.req := 0.U.asTypeOf(Valid(new DcacheMetaReq))

    meta.io.replayWrite.req := 0.U.asTypeOf(Valid(new DcacheMetaReq))

    meta.io.fetchDirty.req := 0.U.asTypeOf(Valid(new DcacheMetaReq))
    
    meta.io.lineClear.req := 0.U.asTypeOf(Valid(new DcacheMetaReq))
    
    meta.io.cacopRead.req := 0.U.asTypeOf(Valid(new DcacheMetaReq))

    meta.io.cacopWrite.req := 0.U.asTypeOf(Valid(new DcacheMetaReq))

    // 存储data信息
    val data = Module(new DcacheDataLogic)
    // 端口设置
    data.io.lsuRead(0).req := 0.U.asTypeOf(Valid(new DcacheDataReq))
    data.io.lsuRead(1).req := 0.U.asTypeOf(Valid(new DcacheDataReq))

    data.io.lsuWrite.req := 0.U.asTypeOf(Valid(new DcacheDataReq))
    
     data.io.wfuRead.req := 0.U.asTypeOf(Valid(new DcacheDataReq))
    
     data.io.wfuWrite.req := 0.U.asTypeOf(Valid(new DcacheDataReq))

    data.io.replayRead.req := 0.U.asTypeOf(Valid(new DcacheDataReq))

    data.io.replayWrite.req := 0.U.asTypeOf(Valid(new DcacheDataReq))


    val replace_findValid = Wire(Bool())
    val mshrReplayValid =Wire(Bool())
    val fenceReadValid = Wire(Bool())
    val fenceClearValid = Wire(Bool())
    val prefetchValid = Wire(Bool())

    // val cacopValid = Wire(Bool())

    val lsuNormalValid = Wire(Bool())
    val lsuMMIOValid = Wire(Bool())

    // 判断输入的有没有mmio请求
    val lsuhasMMIO = io.lsu.req.bits.map( req =>
        req.valid && isMMIO(req.bits)
    ).reduce(_||_)

    // 流水线里面有mmioresp的时候，下一个fire的请求不要进来
    lsuMMIOValid := io.lsu.req.fire && lsuhasMMIO /* && mmiouReady */
    lsuNormalValid := io.lsu.req.fire && !lsuhasMMIO

    // val lsuhasStore = io.lsu.req.bits.map( req =>
    //     req.valid && isStore(req.bits)
    // ).reduce(_||_)

    // 存储mshr的信息
    val mshrs = Module(new MSHRFile)

    replace_findValid := mshrs.io.newFetchreq.valid && wfuReady

    mshrs.io.brupdate := io.lsu.brupdate
    mshrs.io.exception := io.lsu.exception
    mshrReplayValid := mshrs.io.replay.valid
    mshrs.io.fetchedBlockAddr := 0.U
    mshrs.io.fetchReady := false.B
    mshrs.io.fetchedpos := 0.U
    mshrs.io.req.valid := false.B
    mshrs.io.req.bits := 0.U.asTypeOf(new DCacheReq)

    // lsu还在发force_order并且dcache行里面还有dirty，就进行在总线空闲时进行fence操作
    fenceReadValid :=/*  false.B && */ (io.lsu.fence_dmem && meta.io.fetchDirty.resp.bits.hasDirty) && wfuReady 

    // wfu做完之后去清除掉对应的meta行
    fenceClearValid := wfu.io.line_clear_req.valid

    // 只要meta没有dirty，就可以回应fence，不需要管流水线和mshr状态（如果里面有没做完的指令，lsu肯定非空，unique仍然会停留在dispatch）
    io.lsu.ordered := /* true.B || */ !meta.io.fetchDirty.resp.bits.hasDirty

    // TODO:   cacopValid := //


    prefetchValid := false.B

    // 检查全局，如果此时流水线的s0和s1阶段状态为lsu并且有store，就将其kill掉
    val s2StoreFailed = WireInit(false.B)

    val doingMMIO = WireInit(false.B)
    // 对于普通lsu请求,如果当周期检测到有高于lsu优先级请求的话，就将ready置零，下周期lsu发送不过来，同时再去执行非lsu请求
    // 对于mmio的lsu请求,要看总线是否空闲,如果总线空闲,就可以发,如果总线不空闲,就不让发
    io.lsu.req.ready := !(wbValid   ||
                          refillValid ||
                          fenceClearValid  || 
                          mshrReplayValid ||
                          replace_findValid /* || */
                        // 这个信号用于判断s2storeFailed的时候不去接当周期lsu的请求
                        // 不是在这里拒掉 ，而是在s0valid的时候看一下再kill掉，这样改善时序
                         /*  (lsuhasStore && s2StoreFailed) ||  */
                        // 如果lsu是mmio ， 不需要堵在口上，送进去，看不行就replay就好  
                         /*  (io.lsu.req.valid && lsuhasMMIO && !mmiouReady) */
                        )

  
    // 总线相关请求是最高优先级,包括wb和refill这两个请求,他们互斥,只有一个会发生
    // lsuMMIOValid 和 mmioRespValid 也是总线请求
    // fenceClear 和 fenceRead也都属于总线请求
    // (同一时间,以上六个最多只有一个发生)
    
    // 然后是mshrrepplay,和replace_find
    // 然后lsu的请求
    // 然而fenceRead的时候其实是清除脏位,往往配合未完成的store指令一起做完才算完事,因此要给lsu和mshr,replay让步
    // 优先级很低,可以等着,但是fenceClear是要点名清除某一行,那个周期发了必须做,之后就没这个信号了,因此fenceClear优先级要在总线最高级那里

    val s0valid = Wire(Vec(memWidth, Bool()))

    for(w<- 0 until memWidth){
        when(w.U === 0.U){
            s0valid(w) := Mux(lsuMMIOValid || lsuNormalValid, io.lsu.req.bits(w).valid && !(s2StoreFailed && isStore(io.lsu.req.bits(w).bits)),
                wbValid || refillValid || fenceClearValid || mshrReplayValid || replace_findValid || fenceReadValid || prefetchValid)
        }.otherwise{
            // 能用到这个else的只有lsu的请求,包括lsuMMIOValid/lsuNormalValid
            s0valid(w) := Mux( lsuMMIOValid || lsuNormalValid, io.lsu.req.bits(w).valid, false.B)
        }
    }

    val dontCareReq = 0.U.asTypeOf(new DCacheReq)

    val s0req = WireInit(0.U.asTypeOf(Vec(memWidth , new DCacheReq)))

    for(w <- 0 until memWidth){
        when(w.U === 0.U){
            s0req(w) := Mux(wbValid, wfu.io.wfu_read_req.bits,
                        Mux( refillValid,   wfu.io.wfu_write_req.bits, 
                        Mux( fenceClearValid,     wfu.io.line_clear_req.bits,        
                        Mux( lsuMMIOValid,   io.lsu.req.bits(w).bits,
                        // 这里的mmioresp是DcacheReq作为载体,data是可能的rdata,uop是对应uop
                        Mux( mshrReplayValid, mshrs.io.replay.bits,
                        Mux( replace_findValid,   mshrs.io.newFetchreq.bits,
                        Mux( lsuNormalValid,  io.lsu.req.bits(w).bits,
                        Mux( fenceReadValid,      dontCareReq,
                        Mux( prefetchValid ,    dontCareReq, dontCareReq)))))))))
        }otherwise{
            s0req(w) := Mux(lsuMMIOValid || lsuNormalValid, io.lsu.req.bits(w).bits, dontCareReq)
        }
        
    }



    val s0state =   Mux( wbValid, wb,
                    Mux( refillValid,   refill,
                    Mux( fenceClearValid, fence_clear,        
                    Mux( lsuMMIOValid,   mmio_req,
                    Mux( mshrReplayValid, replay,
                    Mux( replace_findValid,   replace_find,
                    Mux( lsuNormalValid,  lsu,
                    Mux( fenceReadValid,      fence_read,
                    Mux( prefetchValid ,    prefetch, nil)))))))))

    // 做判断接replay请求
    mshrs.io.replay.ready := s0state === replay


    //wfu拿到的新的写回信息 
    val s0newMeta = wfu.io.new_meta
    val s0fetchReady = wfu.io.fetch_ready

    // 需要s0pos的一定是单条流水线并且处理cache的请求类型
    val s0pos = WireInit(0.U(log2Ceil(nWays).W))
    s0pos := Mux( wbValid, wfu.io.pos,
            Mux( refillValid,   wfu.io.pos,         
            Mux( mshrReplayValid, mshrs.io.replaypos,
            Mux( fenceClearValid,     wfu.io.pos,
                                     0.U))))


    // replace_find 的时候传出来的去fetch的地址
    val s0fetchAddr = WireInit(0.U(vaddrBits.W)) 

    //最后一个refill进行到s2到告诉mshr去激活(将表1的waiting转成ready)
    val s0activateAddr = wfu.io.fetched_addr

    // TODO prefetch

    
    // s0阶段接入mshr对meta的read请求,接入lsu(replay)对meta的read请求,接入axi对meta的write请求
    when(s0state === lsu){

        for(w <- 0 until memWidth){
                meta.io.lsuRead(w).req.valid := s0valid(w)
                meta.io.lsuRead(w).req.bits.idx := getIdx(s0req(w).addr)
                //这里用到TLB之后,需要将虚拟地址转换为物理地址,采用的是VIPT,因此可能要等下周期TLB的结果
                //s0不需要tag，s1 再传
                meta.io.lsuRead(w).req.bits.tag := getTag(s0req(w).addr)

                // 单纯通知meta是不是一个写指令，不会实际store
                meta.io.lsuRead(w).req.bits.isStore := (isStore(s0req(w)))
        }

    }.elsewhen(s0state === replay){

        meta.io.replayRead.req.valid := s0valid(0)
        meta.io.replayRead.req.bits.idx := getIdx(s0req(0).addr)
        meta.io.replayRead.req.bits.tag := getTag(s0req(0).addr)
        meta.io.replayRead.req.bits.isStore := (isStore(s0req(0)))

    }.elsewhen(s0state === replace_find){

        // 实际上是传入idx,返回的是对应metaSet被替换掉的那一行的信息
        meta.io.missReplace.req.valid := s0valid(0)
        meta.io.missReplace.req.bits.idx := getIdx(s0req(0).addr)
        // 想fetch的地址保存在s0fetchAddr
        s0fetchAddr := s0req(0).addr

    }.elsewhen(s0state === refill){
        // 如果取好，通告地址，以及refill到的行号
        when(s0fetchReady){
            mshrs.io.fetchReady := s0fetchReady
            mshrs.io.fetchedBlockAddr := getBlockAddr(s0activateAddr)
            mshrs.io.fetchedpos := s0pos
        }

        // refill的时候,判断addr的地址是不是那一行的第一个字,如果是,先告诉meta这一行将被invalid
        when(s0req(0).addr(nOffsetBits -1, 2) === 0.U){
            meta.io.refillLogout.req.valid := s0valid(0)
            meta.io.refillLogout.req.bits.idx := getIdx(s0req(0).addr)
            meta.io.refillLogout.req.bits.pos := s0pos
        }

    }.elsewhen(s0state === wb){
        
    }.elsewhen(s0state === mmio_resp || s0state === mmio_req){
        // mmio在s0不走cache,没什么做的
    }.elsewhen(s0state === fence_read){
        // 要告诉meta，fenceRead一行出来
        meta.io.fetchDirty.req.valid := true.B
        meta.io.fetchDirty.req.bits.isFence := true.B
    }.elsewhen(s0state === fence_clear){

    }.otherwise{
        // TODO prefetch cacop
    }


// ================================ s1 ==================================


    val s1valid = Wire(Vec(memWidth, Bool()))
    for(w <- 0 until memWidth){
        s1valid(w) := RegNext(
                        s0valid(w) &&
                        !((s0state === lsu || s0state === mmio_req) && (isStore(s0req(w)) && s2StoreFailed)) && 
                        !(s0state === lsu && (!isStore(s0req(w)) && IsKilledByBranch(io.lsu.brupdate, s0req(w).uop))) &&
                        !(s0state === replay && (!isStore(s0req(w)) && IsKilledByBranch(io.lsu.brupdate, s0req(w).uop)))&&
                        !(s0state === lsu && (!isStore(s0req(w)) && io.lsu.exception)) &&
                        !(s0state === replay && (!isStore(s0req(w)) && io.lsu.exception))
                        ) &&
                        !io.lsu.s1_kill(w)
    }

    val s1state = RegNext(s0state)

    val s1req = RegNext(s0req)
    // 所有真正的lsu事务都需要在s1阶段进行brmask的更新(mmio_req,replay,lsu)
    // when(s1state === lsu || s1state === replay || s1state === mmio_req){
    for (w <- 0 until memWidth){ 
        s1req(w).uop.brMask := GetNewBrMask(io.lsu.brupdate,s0req(w).uop) 
    }
    // }



    // mshr的read请求所需信息
    val s1fetchAddr = RegNext(s0fetchAddr)
    // refill好的信息
    val s1fetchReady = RegNext(s0fetchReady)
    val s1newMeta = RegNext(s0newMeta)
    val s1activateAddr = RegNext(s0activateAddr)

    // 这个是除了普通lsu请求之外需要的s1pos
    val s1pos = RegNext(s0pos)

    // 这个是给lsu请求看hit路用的
    val s1hitpos = WireInit(0.U.asTypeOf(Vec(memWidth , UInt(log2Ceil(nWays).W))))

    // 如果hit,记录下hit的Pos
    val s1hit = WireInit(0.U.asTypeOf(Vec(memWidth , Bool())))

    when(s1state === lsu){
        for(w <- 0 until memWidth){
            // s1 发送paddr 用于判断hit
            // 如果是lsu状态，那么在s1需要将addr转换为paddr

            // s1req(w).addr := io.lsu.s1_paddr(w)
            // meta.io.lsuRead(w).req.bits.tag := getTag(io.lsu.s1_paddr(w))

            when(meta.io.lsuRead(w).resp.valid){
                //在resp之前，meta内部判断是否是store,如果是store,就要判断是否是readOnly,如果是readOnly,就回传来miss
                when(meta.io.lsuRead(w).resp.bits.hit || (isSC(s1req(w)) && !io.lsu.llbit )) {
                    s1hit(w) := true.B
                    s1hitpos(w) := meta.io.lsuRead(w).resp.bits.pos
                    // 接下来要去读data
                    data.io.lsuRead(w).req.valid := s1valid(w)
                    data.io.lsuRead(w).req.bits.idx := getIdx(s1req(w).addr)
                    data.io.lsuRead(w).req.bits.pos := s1hitpos(w)
                    data.io.lsuRead(w).req.bits.offset := getWordOffset(s1req(w).addr)
                }.otherwise{
                    s1hit(w) := false.B
                }
                
            }
        }
    }.elsewhen(s1state === replay){
        // 只保存读出的meta，然后根据他自己的信息去读data
        when(meta.io.replayRead.resp.valid){
            // 接下来要去读data
            data.io.replayRead.req.valid := s1valid(0)
            data.io.replayRead.req.bits.idx := getIdx(s1req(0).addr)
            data.io.replayRead.req.bits.pos := s1pos
            data.io.replayRead.req.bits.offset := getWordOffset(s1req(0).addr)
        }
        
    }.elsewhen(s1state === replace_find){

        when(meta.io.missReplace.resp.valid){
            // 直接把mshr的被替换的行的返回结果以及fetchAddr拉给wfu,激活wfu
            wfu.io.req_valid := s1valid(0)
            wfu.io.req_addr := s1fetchAddr
            wfu.io.meta_resp := meta.io.missReplace.resp.bits
        }

    }.elsewhen(s1state === refill){
        // 不用去读什么
    }.elsewhen(s1state === wb){
        // 去读data
         data.io.wfuRead.req.valid := s1valid(0)
         data.io.wfuRead.req.bits.idx := getIdx(s1req(0).addr)
         data.io.wfuRead.req.bits.pos := s1pos
         data.io.wfuRead.req.bits.offset := getWordOffset(s1req(0).addr)
        
    }.elsewhen(s1state === mmio_resp || s1state === mmio_req){
        // mmio_resp:s1不干活，等着后面s2交还给lsu
        // mmio_req:s1不干活，等着后面发请求给axi
    }.elsewhen(s1state === fence_read){
        when(!meta.io.fetchDirty.resp.bits.hasDirty) {
            //没有Dirty就不做了
        }.otherwise{
            // 把fenceMeatRead的结果拉给wfu
            wfu.io.req_valid := s1valid(0)
            wfu.io.req_wb_only := true.B
            wfu.io.meta_resp := meta.io.fetchDirty.resp.bits
        }
    }


    // ================================ s2 ==================================
    
    val s2state = RegNext(s1state)
    val s2req   = RegNext(s1req)

    // when(s2state === lsu || s2state === replay || s2state === mmio_req){
    for (w <- 0 until memWidth){ 
        s2req(w).uop.brMask := GetNewBrMask(io.lsu.brupdate,s1req(w).uop) 
    }
    // }

    val s2valid = WireInit(0.U.asTypeOf(Vec(memWidth , Bool())))
    for(w <- 0 until memWidth){
                        // 上个周期没被kill
        s2valid(w) := RegNext((s1valid(w) &&
                            !((s1state === lsu || s1state === mmio_req) && (isStore(s1req(w)) && s2StoreFailed)) && 
                            !(s1state === lsu && (!isStore(s1req(w)) && IsKilledByBranch(io.lsu.brupdate, s1req(w).uop))) &&
                            !(s1state === replay && (!isStore(s1req(w)) && IsKilledByBranch(io.lsu.brupdate, s1req(w).uop)))  &&
                            !(s1state === lsu && (!isStore(s1req(w)) && io.lsu.exception)) &&
                            !(s1state === replay && (!isStore(s1req(w)) && io.lsu.exception))
                            )
                            ) && 
                        (
                            // s2周期没有被kill才行，s2周期被kill的只可能分支kill,s2storeFailed本身不会对自己kill
                            !(s2state === lsu && (!isStore(s2req(w)) && IsKilledByBranch(io.lsu.brupdate, s2req(w).uop))) &&
                            !(s2state === replay && (!isStore(s2req(w)) && IsKilledByBranch(io.lsu.brupdate, s2req(w).uop))) &&
                            !(s2state === lsu && (!isStore(s2req(w)) && io.lsu.exception)) &&
                            !(s2state === replay && (!isStore(s2req(w)) && io.lsu.exception))
                        )

    }

    val s2hit = WireInit(0.U.asTypeOf(Vec(memWidth , Bool())))
    for(w <- 0 until memWidth){
        // 对于lsu的store请求，要现在mshr里面找，如果有store，就当作miss处理
        s2hit(w) := RegNext(s1hit(w)) && !(s2state === lsu && (isStore(s2req(w)) && mshrs.io.hasStore))
    }
    // 其他状态的pos (对于mshr分配到的pos，在s1才拿到自己分到的pos，这里要及时更新)
    val s2pos = RegNext(Mux(s1state === replace_find, meta.io.missReplace.resp.bits.pos, s1pos))
    // lsu请求下hit的pos
    val s2hitpos = RegNext(s1hitpos)
    // lsu阶段，如果发生了miss，将由missArbiter来决定写入mshr行为
    val missArbiter = Module(new Missarbiter)
    missArbiter.io.req := s2req
    missArbiter.io.miss := s2hit.map(x => ~x)
    for(w <- 0 until memWidth){
        missArbiter.io.alive(w) := s2valid(w) && s2state === lsu
    }
    missArbiter.io.mshrReq.ready := false.B


    // fetchAddr成功送给axi之后,就可以将告诉mshr去fetching状态转换
    val s2fetchAddr = RegNext(s1fetchAddr)
    val s2fetchReady = RegNext(s1fetchReady)
    val s2newMeta = RegNext(s1newMeta)
    val s2activateAddr = RegNext(s1activateAddr)


    var sendResp = WireInit(0.U.asTypeOf(Vec(memWidth,Bool())))
    var sendNack = WireInit(0.U.asTypeOf(Vec(memWidth,Bool())))

    // 下面是s2执行的内容
    when(s2state === lsu){
        // 生成初处理过的send，nack信号，用于返回给lsu，同时生成StoreFailed,用来清空后面可能有的store
        missArbiter.io.mshrReq <> mshrs.io.req
        
        s2StoreFailed := missArbiter.io.storeFailed
        sendNack := missArbiter.io.sendNack
        sendResp := missArbiter.io.sendResp
        

        // 以上将所有中途kill或者miss的请求都处理完了，接下来处理hit且活着的请求
        for(w <- 0 until memWidth){
            when(s2hit(w)){
                sendResp(w):= s2valid(w)
                sendNack(w):= false.B

                when(isStore(s2req(w))){
                    // meta,data写操作
                    // meta拉高dirty位
                    meta.io.lsuWrite.req.valid := s2valid(w)
                    meta.io.lsuWrite.req.bits.idx := getIdx(s2req(w).addr)
                    meta.io.lsuWrite.req.bits.pos := s2hitpos(w)

                    meta.io.lsuWrite.req.bits.setdirty.valid := true.B
                    meta.io.lsuWrite.req.bits.setdirty.bits := true.B
                    
                    //data 执行写操作
                    val rdata = data.io.lsuRead(w).resp.bits.data
                    val wdata = WordWrite(s2req(w) , rdata)


                    data.io.lsuWrite.req.valid := Mux(isSC(s2req(w)) , s2valid(w) && io.lsu.llbit , s2valid(w))
                    data.io.lsuWrite.req.bits.idx := getIdx(s2req(w).addr)
                    data.io.lsuWrite.req.bits.pos := s2hitpos(w)
                    data.io.lsuWrite.req.bits.offset := getWordOffset(s2req(w).addr)
                    data.io.lsuWrite.req.bits.data := wdata

                    io.lsu.resp(w).bits.data := Mux(isSC(s2req(w)), io.lsu.llbit.asUInt , 0.U)
                    io.lsu.resp(w).bits.uop := s2req(w).uop

                }.otherwise{
                    // load，现在的meta,data自带转发功能不用特别判断什么

                    io.lsu.resp(w).bits.data := data.io.lsuRead(w).resp.bits.data
                    io.lsu.resp(w).bits.uop := s2req(w).uop
                }
            }
        }
    }.elsewhen(s2state === replay){
        // 统一在0号位处理
        sendResp(0) := s2valid(0)
        sendNack(0) := false.B
        sendResp(1) := false.B
        sendNack(1) := false.B
        // 只要s2valid(0)就是hit
        when(isStore(s2req(0))) {
            // store
            
            // meta拉高dirty位
            meta.io.replayWrite.req.valid := s2valid(0)
            meta.io.replayWrite.req.bits.idx := getIdx(s2req(0).addr)
            meta.io.replayWrite.req.bits.pos := s2pos

            meta.io.replayWrite.req.bits.setdirty.valid := true.B
            meta.io.replayWrite.req.bits.setdirty.bits := true.B

            val replay_rdata = data.io.replayRead.resp.bits.data
            val replay_wdata = WordWrite(s2req(0), replay_rdata)
            // data执行写操作
            data.io.replayWrite.req.valid := Mux(isSC(s2req(0)) , s2valid(0) && io.lsu.llbit , s2valid(0))
            data.io.replayWrite.req.bits.idx := getIdx(s2req(0).addr)
            data.io.replayWrite.req.bits.pos := s2pos
            data.io.replayWrite.req.bits.offset := getWordOffset(s2req(0).addr)
            data.io.replayWrite.req.bits.data := replay_wdata

            io.lsu.resp(0).bits.data := Mux(isSC(s2req(0)), io.lsu.llbit.asUInt , 0.U)
            io.lsu.resp(0).bits.uop := s2req(0).uop
        }.otherwise {
            // 准备resp
            io.lsu.resp(0).bits.data := data.io.replayRead.resp.bits.data
            io.lsu.resp(0).bits.uop := s2req(0).uop
        }

    }.elsewhen(s2state === replace_find){
        // 激活wfu在1阶段就做完了
        // 在s2，将那一行的readOnly拉高，直到该行处理完毕，不允许st指令操作这一行
        meta.io.lineFreeze.req.valid := s2valid(0)
        meta.io.lineFreeze.req.bits.idx := getIdx(s2fetchAddr)
        meta.io.lineFreeze.req.bits.pos := s2pos
        meta.io.lineFreeze.req.bits.setreadOnly.valid := true.B
        meta.io.lineFreeze.req.bits.setreadOnly.bits := true.B
    }.elsewhen(s2state ===fence_read){
        // 激活wfu在1阶段就做完了,这里可能之后做fenceWrite的清除对应meta行
    }.elsewhen(s2state === wb){
        // 将读到的data给wfu
        wfu.io.wfu_read_resp.valid :=  data.io.wfuRead.resp.valid
        wfu.io.wfu_read_resp.bits.data :=  data.io.wfuRead.resp.bits.data

        // wb的时候,判断addr的地址是不是那一行的最后一个字,如果是,废除掉对应那个pos的metaline（即将被refill 破坏）
        when(s2req(0).addr(nOffsetBits -1, 2) === 0xf.U){
            meta.io.wfuWrite.req.valid := s2valid(0)
            meta.io.wfuWrite.req.bits.idx := getIdx(s2req(0).addr)
            meta.io.wfuWrite.req.bits.pos := s2pos

            meta.io.wfuWrite.req.bits.setvalid.valid := true.B
            meta.io.wfuWrite.req.bits.setvalid.bits := false.B
        }
        
        // resp和nack都不发
        for (w <- 0 until memWidth) {
            sendResp(w) := false.B
            sendNack(w) := false.B
        }

    }.elsewhen(s2state === refill){

        // 去写data,这里不是st请求，而是refill的内部事务，因此不需要做llbit的判断
         data.io.wfuWrite.req.valid := s2valid(0)
         data.io.wfuWrite.req.bits.idx := getIdx(s2req(0).addr)
         data.io.wfuWrite.req.bits.pos := s2pos
         data.io.wfuWrite.req.bits.offset := getWordOffset(s2req(0).addr)
         data.io.wfuWrite.req.bits.data := s2req(0).data

        // 一个关于meta的特殊情况
        // refill的时候,判断addr的地址是不是那一行的第一个字,如果是,废除掉对应那个pos的metaline
        when(s2req(0).addr(nOffsetBits -1, 2) === 0.U){
            meta.io.wfuWrite.req.valid := s2valid(0)
            meta.io.wfuWrite.req.bits.idx := getIdx(s2req(0).addr)
            meta.io.wfuWrite.req.bits.pos := s2pos

            meta.io.wfuWrite.req.bits.setvalid.valid := true.B
            meta.io.wfuWrite.req.bits.setvalid.bits := false.B
        }
        
        // s2fetchReady 的时候,所有data将要写完了,这个时候可以将新的meta写入
        when(s2fetchReady){
            // 通告地址，以及refill到的行号
            // mshrs.io.fetchReady := s2fetchReady
            // mshrs.io.fetchedBlockAddr := getBlockAddr(s2activateAddr)
            // mshrs.io.fetchedpos := s2pos
            // 告诉meta.io.wfuWrite要写入的行号
            meta.io.wfuWrite.req.valid := s2valid(0)
            meta.io.wfuWrite.req.bits.idx := getIdx(s2req(0).addr)
            meta.io.wfuWrite.req.bits.pos := s2pos

            meta.io.wfuWrite.req.bits.setvalid.valid := true.B
            meta.io.wfuWrite.req.bits.setvalid.bits := s2newMeta.valid

            meta.io.wfuWrite.req.bits.setdirty.valid := true.B
            meta.io.wfuWrite.req.bits.setdirty.bits := s2newMeta.dirty

            meta.io.wfuWrite.req.bits.setreadOnly.valid := true.B
            meta.io.wfuWrite.req.bits.setreadOnly.bits := s2newMeta.readOnly

            // 解除fixed
            meta.io.wfuWrite.req.bits.setfixed.valid := true.B
            meta.io.wfuWrite.req.bits.setfixed.bits := s2newMeta.fixed

            // 将新的tag写入
            meta.io.wfuWrite.req.bits.setTag.valid := true.B
            meta.io.wfuWrite.req.bits.setTag.bits := s2newMeta.tag
        }
    }.elsewhen(s2state === mmio_req){
        // 查pipeline，要求lsu发送的时候0号或1号是mmio请求，不会同时发两个

        val mmio_req = Mux(s2valid(0), s2req(0), s2req(1))
        when(isSC(mmio_req) && !io.lsu.llbit){
            // 如果是一个llbit为0的sc指令，那么直接返回llbit，不真正执行
            // 选择0号做回复
            sendResp(0) := s2valid(0) || s2valid(1)
            sendNack(0) := false.B
            sendResp(1) := false.B
            sendNack(1) := false.B
            io.lsu.resp(0).bits.data := io.lsu.llbit.asUInt
            io.lsu.resp(0).bits.uop := mmio_req.uop
        }.otherwise{
            // mmiou必须空闲
            // assert(mmiou.io.ready , "mmiou must be idle")
            mmiou.io.mmioReq.valid := s2valid(0) || s2valid(1)
            // 存入请求本身
            mmiou.io.mmioReq.bits := mmio_req
            when(!mmiou.io.mmioReq.fire){
                assert(!(mmiou.io.mmioReq.valid && !isStore(mmio_req)),
                    "a mmio load request is sent but there is another store in mmio unit")
                // 当前不接受，说明busy，这种情况一定是store，发nack，然后拉高storeFailed
                // 0号发nack
                sendResp(0) := false.B
                sendNack(0) := s2valid(0) || s2valid(1)
                sendResp(1) := false.B
                sendNack(1) := false.B
                s2StoreFailed := s2valid(0) || s2valid(1)
            }
        }
    }.elsewhen(s2state === mmio_resp){
        
        // 装载newDataLine的0号数据作为可能的读操作的resp的data
        for(w <- 0 until memWidth){
            // DcacheReq类,req的uop还是那个请求的uop，但是如果是一个ld指令，那么这里的data（原store的写入数据）将作为读取到的data的载体
            io.lsu.resp(0).bits.data := Mux(isSC(s2req(0)), io.lsu.llbit.asUInt , s2req(0).data)
            io.lsu.resp(0).bits.uop  := s2req(0).uop
        }
        // 选择0号做回复
        sendResp(0) := s2valid(0)
        sendNack(0) := false.B
        sendResp(1) := false.B
        sendNack(1) := false.B
    }.elsewhen(s2state === fence_clear){
        // 清除对应的meta行的dirty位
        meta.io.lineClear.req.valid := s2valid(0)
        meta.io.lineClear.req.bits.isFence := true.B

        meta.io.lineClear.req.bits.idx := getIdx(s2req(0).addr)
        meta.io.lineClear.req.bits.pos := s2pos

        meta.io.lineClear.req.bits.setdirty.valid := true.B
        meta.io.lineClear.req.bits.setdirty.bits := false.B

        // 彻底清除这一行
        meta.io.lineClear.req.bits.setvalid.valid := false.B
        meta.io.lineClear.req.bits.setvalid.bits := false.B

        meta.io.lineClear.req.bits.setreadOnly.valid := false.B
        meta.io.lineClear.req.bits.setreadOnly.bits := false.B

        meta.io.lineClear.req.bits.setfixed.valid := false.B
        meta.io.lineClear.req.bits.setfixed.bits := false.B

        meta.io.lineClear.req.bits.setTag.valid := false.B
        meta.io.lineClear.req.bits.setTag.bits := 0.U

    }.elsewhen(s2state === prefetch){
        // TODO
    }.elsewhen(s2state === nil){
        // 
    }


    // 最后整理resp和nack
    io.lsu.nack(0).bits := s2req(0)
    io.lsu.nack(1).bits := s2req(1)
    // 按情况返回resp或nack(replay不用看kill，lsukiil自然为假)
    for(w <- 0 until memWidth){
        io.lsu.nack(w).valid := sendNack(w)
        io.lsu.resp(w).valid := sendResp(w)
    }

    // mmiou 挑一个没有人用resp的周期发resp
    mmiou.io.mmioResp.ready := !sendResp(0)

    when(mmiou.io.mmioResp.fire){
        // 0号发resp
        io.lsu.resp(0).valid := true.B
        io.lsu.resp(0).bits.data := mmiou.io.mmioResp.bits.data
        io.lsu.resp(0).bits.uop := mmiou.io.mmioResp.bits.uop
    }

    // difftest
    val isRealStoreState = (s2state === lsu || s2state === replay || mmiou.io.mmioResp.fire)

    if(!FPGAPlatform){
        val difftest = Module(new DifftestStoreEvent)
        //{4'b0, llbit && sc_w, st_w, st_h, st_b}
        val sc_w =  isRealStoreState && io.lsu.resp(0).valid && io.lsu.resp(0).bits.uop.is_sc
        val st_w =  isRealStoreState && io.lsu.resp(0).valid && io.lsu.resp(0).bits.uop.use_stq &&  io.lsu.resp(0).bits.uop.mem_size === 2.U
        val st_h =  isRealStoreState && io.lsu.resp(0).valid && io.lsu.resp(0).bits.uop.use_stq &&  io.lsu.resp(0).bits.uop.mem_size === 1.U
        val st_b =  isRealStoreState && io.lsu.resp(0).valid && io.lsu.resp(0).bits.uop.use_stq &&  io.lsu.resp(0).bits.uop.mem_size === 0.U
        // disable now
        difftest.io.valid := /* 0.U  & */ VecInit(Cat((0.U(4.W)), io.lsu.llbit && sc_w, st_w, st_h, st_b)).asUInt
        difftest.io.clock := clock
        difftest.io.coreid := 0.U // only support 1 core now
        difftest.io.index := 0.U
        difftest.io.storePAddr := Mux(mmiou.io.mmioResp.fire, mmiou.io.mmioResp.bits.addr , s2req(0).addr)
        difftest.io.storeVAddr := 0.U
        difftest.io.storeData := Mux(mmiou.io.mmioResp.fire,WordWrite(mmiou.io.mmioResp.bits, 0.U(32.W))
                                                                                        ,WordWrite(s2req(0), 0.U(32.W)))
    }
    

    mmiouReady := mmiou.io.mmioReq.ready &&
                 (s1state =/= mmio_req) && 
                 (s2state =/= mmio_req)
    
    wfuReady  := wfu.io.ready && 
                 (s1state =/= fence_read && s1state =/= fence_clear && s1state =/= replace_find && s1state =/= wb && s1state =/= refill) &&
                 (s2state =/= fence_read && s2state =/= fence_clear && s2state =/= replace_find && s2state =/= wb && s2state =/= refill)

    doingMMIO := s1state === mmio_req || s2state === mmio_req || !mmiou.io.mmioReq.ready

    // TODO enable continuous hit store forwarding(DONE)
    // TODO simplify the IO channel of DCacheData and DCacheMeta(DONE)

    // TODO mmio(DONE)
    // TODO reconstrcut the DCache(DONE)
    // TODO lr/sc
}
