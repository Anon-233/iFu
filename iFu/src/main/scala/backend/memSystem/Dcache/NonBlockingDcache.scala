
package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.util._

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

}

class DCacheBundle  extends CoreBundle with HasDcacheParameters{
    // val error = new DCacheErrors
    val lsu = Flipped(new LSUDMemIO)
    val cbusReq = Output(new CBusReq)
    val cbusResp = Input(new CBusResp)
}


class NonBlockingDcache extends Module with HasDcacheParameters{
    val io = IO(new DCacheBundle)

    // 解释:
    // replay : mshr的replay请求
    // refill : wfu的重填数据请求
    // lsu : lsu的请求
    // prefetch : prefetch的请求
    // mshrread : mshr的fetch请求(期间会读取meta,送给WFU)
    // nil : 什么都不做
    // fence_read : 清空所有的dirty行

    io.lsu.req.ready := false.B
    for(w <- 0 until memWidth){
        io.lsu.resp(w) := 0.U.asTypeOf(new Valid(new DCacheResp))
    }

    for (w <- 0 until memWidth) {
        io.lsu.nack(w) := 0.U.asTypeOf(new Valid(new DCacheReq))
    }


    val replay :: wb :: refill ::  mshrread :: lsu  :: mmioreq :: mmioresp  :: prefetch  :: fence_read :: fence_clear :: cacop :: nil :: Nil = Enum(12)



    // 替换单元
    val wfu = Module(new WriteFetchUnit)
    wfu.io.valid := false.B
    wfu.io.fetchAddr := 0.U
    wfu.io.metaresp := 0.U.asTypeOf(new DcacheMetaResp)
    wfu.io.wbOnly := false.B
    wfu.io.axiReadResp := 0.U.asTypeOf(Valid(new DCacheResp))
    wfu.io.cbusResp := 0.U.asTypeOf(new CBusResp)

    val wbValid = wfu.io.axiReadReq.valid
    val refillValid = wfu.io.axiWriteReq.valid

    val mmiou = Module(new MMIOUnit) 
    mmiou.io.mmioReq := 0.U.asTypeOf(Valid(new DCacheReq))
    mmiou.io.cbusResp := 0.U.asTypeOf(new CBusResp)
    val mmioRespValid = mmiou.io.mmioResp.valid

    // arbiter
    when(!wfu.io.ready){
        io.cbusReq := wfu.io.cbusReq
        wfu.io.cbusResp := io.cbusResp
    }.otherwise{
        io.cbusReq := mmiou.io.cbusReq
        mmiou.io.cbusResp := io.cbusResp
    }

    // 判断axi会空闲的要求是,wfu和mmiou都要ready,并且流水线中没有正在运行的mshrread,wb,refill和mmioreq,mmioresp
    val axiReady = WireInit(false.B)


    // 存储meta信息
    val meta = Module(new DcacheMetaLogic)

    // 端口设置
    val lsuMetaRead = meta.io.lsuRead
    lsuMetaRead(0).req := 0.U.asTypeOf(Valid(new DcacheMetaReq))
    lsuMetaRead(1).req := 0.U.asTypeOf(Valid(new DcacheMetaReq))

    val lsuMetaWrite = meta.io.lsuWrite
    lsuMetaWrite.req := 0.U.asTypeOf(Valid(new DcacheMetaReq))

    val mshrMetaRead = meta.io.mshrRead
    mshrMetaRead.req := 0.U.asTypeOf(Valid(new DcacheMetaReq))
    val axiMetaWrite = meta.io.axiWrite
    axiMetaWrite.req := 0.U.asTypeOf(Valid(new DcacheMetaReq))

    val replayMetaRead = meta.io.replayRead
    replayMetaRead.req := 0.U.asTypeOf(Valid(new DcacheMetaReq))
    val replayMetaWrite = meta.io.replayWrite
    replayMetaWrite.req := 0.U.asTypeOf(Valid(new DcacheMetaReq))

    val fenceMetaRead = meta.io.fenceRead
    fenceMetaRead.req := 0.U.asTypeOf(Valid(new DcacheMetaReq))

    val fenceMetaWrite = meta.io.fenceWrite
    fenceMetaWrite.req := 0.U.asTypeOf(Valid(new DcacheMetaReq))

    val cacopMetaRead = meta.io.cacopRead
    cacopMetaRead.req := 0.U.asTypeOf(Valid(new DcacheMetaReq))

    val cacopMetaWrite = meta.io.cacopWrite
    cacopMetaWrite.req := 0.U.asTypeOf(Valid(new DcacheMetaReq))

    // 存储data信息
    val data = Module(new DcacheDataLogic)
    // 端口设置
    val lsuDataRead = data.io.lsuRead
    lsuDataRead(0).req := 0.U.asTypeOf(Valid(new DcacheDataReq))
    lsuDataRead(1).req := 0.U.asTypeOf(Valid(new DcacheDataReq))

    val lsuDataWrite = data.io.lsuWrite
    lsuDataWrite.req := 0.U.asTypeOf(Valid(new DcacheDataReq))

    val axiDataRead = data.io.axiRead
    axiDataRead.req := 0.U.asTypeOf(Valid(new DcacheDataReq))

    val axiDataWrite = data.io.axiWrite
    axiDataWrite.req := 0.U.asTypeOf(Valid(new DcacheDataReq))
    val replayDataRead = data.io.replayRead
    replayDataRead.req := 0.U.asTypeOf(Valid(new DcacheDataReq))
    val replayDataWrite = data.io.replayWrite
    replayDataWrite.req := 0.U.asTypeOf(Valid(new DcacheDataReq))
    val fenceDataRead = data.io.fenceRead
    fenceDataRead.req := 0.U.asTypeOf(Valid(new DcacheDataReq))

    val mshrReadValid = Wire(Bool())
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
    lsuMMIOValid := io.lsu.req.fire && lsuhasMMIO && axiReady
    lsuNormalValid := io.lsu.req.fire && !lsuhasMMIO && io.lsu.req.ready


    val lsuhasStore = io.lsu.req.bits.map( req =>
        req.valid && isStore(req.bits)
    ).reduce(_||_)

    // 存储mshr的信息
    val mshrs = Module(new MSHRFile)

    mshrReadValid := mshrs.io.newFetchreq.valid && axiReady

    mshrs.io.brupdate := io.lsu.brupdate
    mshrReplayValid := mshrs.io.replay.valid
    mshrs.io.fetchedBlockAddr := 0.U
    mshrs.io.fetchReady := false.B
    mshrs.io.fetchedpos := 0.U
    mshrs.io.req.valid := false.B
    mshrs.io.req.bits := 0.U.asTypeOf(new DCacheReq)

    // lsu还在发force_order并且dcache行里面还有dirty，就进行在总线空闲时进行fence操作
    fenceReadValid := false.B && (io.lsu.force_order && fenceMetaRead.resp.bits.hasDirty) && axiReady 
    //清掉里面所有的load指令(第一个周期清,之后别一直拉高)
    mshrs.io.fenceClear := fenceReadValid && RegNext(!fenceReadValid)

    // wfu做完之后去清除掉对应的meta行
    fenceClearValid := wfu.io.fenceClearReq.valid

    // 只要meta没有dirty，就可以回应fence，不需要管流水线和mshr状态（如果里面有没做完的指令，lsu肯定非空，unique仍然会停留在dispatch）
    io.lsu.ordered := true.B || !fenceMetaRead.resp.bits.hasDirty

    // TODO:   cacopValid := //

    // TODO prefetch

    prefetchValid := false.B

    // 检查全局，如果此时流水线的s0和s1阶段状态为lsu并且有store，就将其kill掉
    val s2StoreFailed = WireInit(false.B)

    // 对于普通lsu请求,如果当周期检测到有高于lsu优先级请求的话，就将ready置零，下周期lsu发送不过来，同时再去执行非lsu请求
    // 对于mmio的lsu请求,要看总线是否空闲,如果总线空闲,就可以发,如果总线不空闲,就不让发
    io.lsu.req.ready := !(wbValid   ||
                          refillValid ||
                          fenceClearValid  || 
                          mmioRespValid ||
                          mshrReplayValid ||
                          mshrReadValid ||
                        // 这个信号用于判断s2storeFailed的时候不去接当周期lsu的store请求
                          (lsuhasStore && s2StoreFailed) || 
                        // 如果lsu是mmo  
                          (/* io.lsu.req.valid &&  */lsuhasMMIO && !axiReady)
                          )

  
    // 总线相关请求是最高优先级,包括wb和refill这两个请求,他们互斥,只有一个会发生
    // lsuMMIOValid 和 mmioRespValid 也是总线请求
    // fenceClear 和 fenceRead也都属于总线请求
    // (同一时间,以上六个最多只有一个发生)
    
    // 然后是mshrrepplay,和mshrread
    // 然后lsu的请求
    // 然而fenceRead的时候其实是清除脏位,往往配合未完成的store指令一起做完才算完事,因此要给lsu和mshr,replay让步
    // 优先级很低,可以等着,但是fenceClear是要点名清除某一行,那个周期发了必须做,之后就没这个信号了,因此fenceClear优先级要在总线最高级那里

    val s0valid = Wire(Vec(memWidth, Bool()))

    for(w<- 0 until memWidth){
        when(w.U === 0.U){
            s0valid(w) := Mux(wbValid, true.B,
                        Mux( refillValid,         true.B,
                        Mux( fenceClearValid,     true.B,
                        Mux( lsuMMIOValid,   io.lsu.req.bits(w).valid,
                        Mux( mmioRespValid    , true.B,
                        Mux( mshrReplayValid, true.B,
                        Mux( mshrReadValid,   true.B,
                        Mux( lsuNormalValid,  io.lsu.req.bits(w).valid,
                        Mux( fenceReadValid,      true.B,
                        Mux( prefetchValid ,    true.B, false.B))))))))))
        }.otherwise{
            // 能用到这个else的只有lsu的请求,包括lsuMMIOValid/lsuNormalValid
            s0valid(w) := Mux( lsuMMIOValid || lsuNormalValid, io.lsu.req.bits(w).valid, false.B)
        }
    }

    val dontCareReq = 0.U.asTypeOf(new DCacheReq)

    val s0req = WireInit(0.U.asTypeOf(Vec(memWidth , new DCacheReq)))

    for(w <- 0 until memWidth){
        when(w.U === 0.U){
            s0req(w)  := Mux(wbValid, wfu.io.axiReadReq.bits,
                        Mux( refillValid,   wfu.io.axiWriteReq.bits, 
                        Mux( fenceClearValid,     wfu.io.fenceClearReq.bits,        
                        Mux( lsuMMIOValid,   io.lsu.req.bits(w).bits,
                        // 这里的mmioresp是DcacheReq作为载体,data是可能的rdata,uop是对应uop
                        Mux( mmioRespValid    , mmiou.io.mmioResp.bits,
                        Mux( mshrReplayValid, mshrs.io.replay.bits,
                        Mux( mshrReadValid,   mshrs.io.newFetchreq.bits,
                        Mux( lsuNormalValid,  io.lsu.req.bits(w).bits,
                        Mux( fenceReadValid,      dontCareReq,
                        Mux( prefetchValid ,    dontCareReq, dontCareReq))))))))))
        }otherwise{
            s0req(w) := Mux(lsuMMIOValid || lsuNormalValid, io.lsu.req.bits(w).bits, dontCareReq)
        }
        
    }



    val s0state =   Mux( wbValid, wb,
                    Mux( refillValid,   refill,
                    Mux( fenceClearValid, fence_clear,        
                    Mux( lsuMMIOValid,   mmioreq,
                    Mux( mmioRespValid    , mmioresp,
                    Mux( mshrReplayValid, replay,
                    Mux( mshrReadValid,   mshrread,
                    Mux( lsuNormalValid,  lsu,
                    Mux( fenceReadValid,      fence_read,
                    Mux( prefetchValid ,    prefetch, nil))))))))))

    // 做判断接replay请求
    mshrs.io.replay.ready := s0state === replay


    //wfu拿到的新的写回信息 
    val s0newMeta = wfu.io.newMeta
    val s0fetchReady = wfu.io.fetchReady

    // 需要s0pos的一定是单条流水线并且处理cache的请求类型
    val s0pos = WireInit(0.U(log2Ceil(nWays).W))
    s0pos := Mux( wbValid, wfu.io.pos,
            Mux( refillValid,   wfu.io.pos,         
            Mux( mshrReplayValid, mshrs.io.replaypos,
            Mux( fenceClearValid,     wfu.io.pos,
                                     0.U))))


    // mshrread 的时候传出来的去fetch的地址
    val s0fetchAddr = WireInit(0.U(vaddrBits.W)) 

    //最后一个refill进行到s2到告诉mshr去激活(将表1的waiting转成ready)
    val s0activateAddr = wfu.io.fetchedAddrOut


    // TODO prefetch

    
    // s0阶段接入mshr对meta的read请求,接入lsu(replay)对meta的read请求,接入axi对meta的write请求
    when(s0state === lsu){

        for(w <- 0 until memWidth){
                lsuMetaRead(w).req.valid := s0valid(w)
                lsuMetaRead(w).req.bits.idx := getIdx(s0req(w).addr)
                //这里用到TLB之后,需要将虚拟地址转换为物理地址,采用的是VIPT,因此可能要等下周期TLB的结果
                lsuMetaRead(w).req.bits.tag := getTag(s0req(w).addr)

                // 单纯通知meta是不是一个写指令，不会实际store
                lsuMetaRead(w).req.bits.isLsuStore := (isStore(s0req(w)))
        }

    }.elsewhen(s0state === replay){

        replayMetaRead.req.valid := s0valid(0)
        replayMetaRead.req.bits.idx := getIdx(s0req(0).addr)
        replayMetaRead.req.bits.tag := getTag(s0req(0).addr)

    }.elsewhen(s0state === mshrread){

        // 实际上是传入idx,返回的是对应metaSet被替换掉的那一行的信息
        mshrMetaRead.req.valid := s0valid(0)
        mshrMetaRead.req.bits.idx := getIdx(s0req(0).addr)
        // 想fetch的地址保存在s0fetchAddr
        s0fetchAddr := s0req(0).addr


    }.elsewhen(s0state === refill){


    }.elsewhen(s0state === wb){
        
    }.elsewhen(s0state === mmioresp || s0state === mmioreq){
        // mmio在s0不走cache,没什么做的
    }.elsewhen(s0state === fence_read){
        // 要告诉meta，fenceRead一行出来
        fenceMetaRead.req.valid := true.B
        fenceMetaRead.req.bits.isFence := true.B
    }.elsewhen(s0state === fence_clear){

    }.otherwise{
        // TODO prefetch cacop
    }


// ================================ s1 ==================================


    val s1valid = Wire(Vec(memWidth, Bool()))
    for(w <- 0 until memWidth){
        s1valid(w) := RegNext(
                        s0valid(w) &&
                        !(s0state === lsu && (isStore(s0req(w)) && s2StoreFailed)) && 
                        !(s0state === lsu && (!isStore(s0req(w)) && IsKilledByBranch(io.lsu.brupdate, s0req(w).uop))) &&
                        !(s0state === replay && (!isStore(s0req(w)) && IsKilledByBranch(io.lsu.brupdate, s0req(w).uop)))
                        ) &&
                        !io.lsu.s1_kill(w)
    }

    val s1state = RegNext(s0state)

    val s1req = RegNext(s0req)
    // 所有真正的lsu事务都需要在s1阶段进行brmask的更新(mmioreq,replay,lsu)
    // when(s1state === lsu || s1state === replay || s1state === mmioreq){
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
            when(lsuMetaRead(w).resp.valid){
                //在resp之前，meta内部判断是否是store,如果是store,就要判断是否是readOnly,如果是readOnly,就回传来miss
                when(lsuMetaRead(w).resp.bits.hit){
                    s1hit(w) := true.B
                    s1hitpos(w) := lsuMetaRead(w).resp.bits.pos
                    // 接下来要去读data
                    lsuDataRead(w).req.valid := s1valid(w)
                    lsuDataRead(w).req.bits.idx := getIdx(s1req(w).addr)
                    lsuDataRead(w).req.bits.pos := s1hitpos(w)
                    lsuDataRead(w).req.bits.offset := getWordOffset(s1req(w).addr)
                }.otherwise{
                    s1hit(w) := false.B
                }
            }
        }

    }.elsewhen(s1state === replay){
        // 只保存读出的meta，然后根据他自己的信息去读data
        when(replayMetaRead.resp.valid){
            // 接下来要去读data
            replayDataRead.req.valid := s1valid(0)
            replayDataRead.req.bits.idx := getIdx(s1req(0).addr)
            replayDataRead.req.bits.pos := s1pos
            replayDataRead.req.bits.offset := getWordOffset(s1req(0).addr)
        }
        
    }.elsewhen(s1state === mshrread){

        when(mshrMetaRead.resp.valid){
            // 直接把mshr的被替换的行的返回结果以及fetchAddr拉给wfu,激活wfu
            wfu.io.valid := s1valid(0)
            wfu.io.fetchAddr := s1fetchAddr
            wfu.io.metaresp := mshrMetaRead.resp.bits

        }

    }.elsewhen(s1state === refill){
        // 不用去读什么
    }.elsewhen(s1state === wb){
        // 去读data
        axiDataRead.req.valid := s1valid(0)
        axiDataRead.req.bits.idx := getIdx(s1req(0).addr)
        axiDataRead.req.bits.pos := s1pos
        axiDataRead.req.bits.offset := getWordOffset(s1req(0).addr)
        
    }.elsewhen(s1state === mmioresp || s1state === mmioreq){
        // mmioresp:s1不干活，等着后面s2交还给lsu
        // mmioreq:s1不干活，等着后面发请求给axi
    }.elsewhen(s1state === fence_read){
        when(!fenceMetaRead.resp.bits.hasDirty) {
            //没有Dirty就不做了
        }.otherwise{
            // 把fenceMeatRead的结果拉给wfu
            wfu.io.valid := s1valid(0)
            wfu.io.wbOnly := true.B
            wfu.io.metaresp := fenceMetaRead.resp.bits
        }
    }

    // ================================ s2 ==================================

    val s2state = RegNext(s1state)
    val s2req = RegNext(s1req)

    // when(s2state === lsu || s2state === replay || s2state === mmioreq){
    for (w <- 0 until memWidth){ 
        s2req(w).uop.brMask := GetNewBrMask(io.lsu.brupdate,s1req(w).uop) 
    }
    // }

    val s2valid = WireInit(0.U.asTypeOf(Vec(memWidth , Bool())))
    for(w <- 0 until memWidth){
                        // 上个周期没被kill
        s2valid(w) := RegNext(s1valid(w) &&
                            !(s1state === lsu && (isStore(s1req(w)) && s2StoreFailed)) && 
                            !(s1state === lsu && (!isStore(s1req(w)) && IsKilledByBranch(io.lsu.brupdate, s1req(w).uop))) &&
                            !(s1state === replay && (!isStore(s1req(w)) && IsKilledByBranch(io.lsu.brupdate, s1req(w).uop)))
                            )   &&
                        // s2周期没有被kill才行，s2周期被kill的只可能分支kill,s2storeFailed本身不会对自己kill
                        !(s2state === lsu && (!isStore(s2req(w)) && IsKilledByBranch(io.lsu.brupdate, s2req(w).uop))) &&
                        !(s2state === replay && (!isStore(s2req(w)) && IsKilledByBranch(io.lsu.brupdate, s2req(w).uop)))
    }

    val s2hit = RegNext(s1hit)
    // 其他状态的pos
    val s2pos = RegNext(s1pos)
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
                    when(mshrs.io.hasStore){
                        // 如果这个即将想要完成的store指令发现mshr里面还有store指令
                        // (重填结束的下一周期，store的replay先于其他内容
                        // 充填结束后的两个周期其他st都会被这个hasStore约束不会超前执行
                        // 自己不能先于其执行，因此按照storeFailed反馈
                        sendResp(w):= false.B
                        sendNack(w):= s2valid(w)

                        s2StoreFailed := s2valid(w)
                        io.lsu.resp(w).bits.data := DontCare
                        io.lsu.resp(w).bits.uop := s2req(w).uop
                    }.otherwise{
                        // 正常操作

                        // meta,data写操作
                        // meta拉高dirty位
                        lsuMetaWrite.req.valid := s2valid(w)
                        lsuMetaWrite.req.bits.idx := getIdx(s2req(w).addr)
                        lsuMetaWrite.req.bits.pos := s2hitpos(w)

                        lsuMetaWrite.req.bits.setdirty.valid := true.B
                        lsuMetaWrite.req.bits.setdirty.bits := true.B
                        
                        //data 执行写操作
                        val rdata = lsuDataRead(w).resp.bits.data
                        val wdata = WordWrite(s2req(w) , rdata)


                        lsuDataWrite.req.valid := s2valid(w)
                        lsuDataWrite.req.bits.idx := getIdx(s2req(w).addr)
                        lsuDataWrite.req.bits.pos := s2hitpos(w)
                        lsuDataWrite.req.bits.offset := getWordOffset(s2req(w).addr)
                        lsuDataWrite.req.bits.data := wdata

                        io.lsu.resp(w).bits.data := DontCare
                        io.lsu.resp(w).bits.uop := s2req(w).uop
                        }

                }.otherwise{
                    // load，现在的meta,data自带转发功能不用特别判断什么
                    
                    io.lsu.resp(w).bits.data := lsuDataRead(w).resp.bits.data
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
            replayMetaWrite.req.valid := s2valid(0)
            replayMetaWrite.req.bits.idx := getIdx(s2req(0).addr)
            replayMetaWrite.req.bits.pos := s2pos

            replayMetaWrite.req.bits.setdirty.valid := true.B
            replayMetaWrite.req.bits.setdirty.bits := true.B

            val replay_rdata = replayDataRead.resp.bits.data
            val replay_wdata = WordWrite(s2req(0), replay_rdata)
            // data执行写操作
            replayDataWrite.req.valid := s2valid(0)
            replayDataWrite.req.bits.idx := getIdx(s2req(0).addr)
            replayDataWrite.req.bits.pos := s2pos
            replayDataWrite.req.bits.offset := getWordOffset(s2req(0).addr)
            replayDataWrite.req.bits.data := replay_wdata

            io.lsu.resp(0).bits.data := DontCare
            io.lsu.resp(0).bits.uop := s2req(0).uop
        }.otherwise {
            // 准备resp
            io.lsu.resp(0).bits.data := replayDataRead.resp.bits.data
            io.lsu.resp(0).bits.uop := s2req(0).uop
        }

    }.elsewhen(s2state === mshrread){
        // 激活wfu在1阶段就做完了
    }.elsewhen(s2state ===fence_read){
        // 激活wfu在1阶段就做完了,这里可能之后做fenceWrite的清除对应meta行
    }.elsewhen(s2state === wb){
        // 将读到的data给wfu
        wfu.io.axiReadResp.valid := axiDataRead.resp.valid
        wfu.io.axiReadResp.bits.data := axiDataRead.resp.bits.data

        // wb的时候,判断addr的地址是不是那一行的第一个字,如果是,拉高那一行的只读位
        when(s2req(0).addr(nOffsetBits -1, 2) === 0.U){
            axiMetaWrite.req.valid := s2valid(0)
            axiMetaWrite.req.bits.idx := getIdx(s2req(0).addr)
            axiMetaWrite.req.bits.pos := s2pos

            axiMetaWrite.req.bits.setreadOnly.valid := true.B
            axiMetaWrite.req.bits.setreadOnly.bits := true.B
        }
        // resp和nack都不发
        for (w <- 0 until memWidth) {
            sendResp(w) := false.B
            sendNack(w) := false.B
        }

    }.elsewhen(s2state === refill){

        // 去写data
        axiDataWrite.req.valid := s2valid(0)
        axiDataWrite.req.bits.idx := getIdx(s2req(0).addr)
        axiDataWrite.req.bits.pos := s2pos
        axiDataWrite.req.bits.offset := getWordOffset(s2req(0).addr)
        axiDataWrite.req.bits.data := s2req(0).data

        // 两个关于meta的特殊情况

        // refill的时候,判断addr的地址是不是那一行的第一个字,如果是,废除掉对应那个pos的metaline
        when(s2req(0).addr(nOffsetBits -1, 2) === 0.U){
            axiMetaWrite.req.valid := s2valid(0)
            axiMetaWrite.req.bits.idx := getIdx(s2req(0).addr)
            axiMetaWrite.req.bits.pos := s2pos

            axiMetaWrite.req.bits.setvalid.valid := true.B
            axiMetaWrite.req.bits.setvalid.bits := false.B
        }
        // s2fetchReady 的时候,所有data将要写完了,这个时候可以将新的meta写入
        when(s2fetchReady){
            // 通告地址，以及refill到的行号
            mshrs.io.fetchReady := s2fetchReady
            mshrs.io.fetchedBlockAddr := getBlockAddr(s2activateAddr)
            mshrs.io.fetchedpos := s2pos
            // 告诉axiMetaWrite要写入的行号
            axiMetaWrite.req.valid := s2valid(0)
            axiMetaWrite.req.bits.idx := getIdx(s2req(0).addr)
            axiMetaWrite.req.bits.pos := s2pos

            axiMetaWrite.req.bits.setvalid.valid := true.B
            axiMetaWrite.req.bits.setvalid.bits := s2newMeta.valid

            axiMetaWrite.req.bits.setdirty.valid := true.B
            axiMetaWrite.req.bits.setdirty.bits := s2newMeta.dirty

            axiMetaWrite.req.bits.setreadOnly.valid := true.B
            axiMetaWrite.req.bits.setreadOnly.bits := s2newMeta.readOnly

            // 解除fixed
            axiMetaWrite.req.bits.setfixed.valid := true.B
            axiMetaWrite.req.bits.setfixed.bits := s2newMeta.fixed

            // 将新的tag写入
            axiMetaWrite.req.bits.setTag.valid := true.B
            axiMetaWrite.req.bits.setTag.bits := s2newMeta.tag
        }

    }.elsewhen(s2state === mmioreq){
        // 查pipeline，要求lsu发送的时候0号或1号是mmio请求，不会同时发两个

        val mmioreq = Mux(s2valid(0), s2req(0), s2req(1))
        // mmiou必须空闲
        assert(mmiou.io.ready , "mmiou must be idle")
        mmiou.io.mmioReq.valid := s2valid(0) || s2valid(1)
        // 存入请求本身
        mmiou.io.mmioReq.bits := mmioreq

    }.elsewhen(s2state === mmioresp){
        
        // 装载newDataLine的0号数据作为可能的读操作的resp的data
        for(w <- 0 until memWidth){
            // DcacheReq类作为载体
            io.lsu.resp(0).bits.data := s2req(0).data
            io.lsu.resp(0).bits.uop := s2req(0).uop
        }
        // 选择0号做回复
        sendResp(0) := s2valid(0)
        sendNack(0) := false.B
        sendResp(1) := false.B
        sendNack(1) := false.B
    }.elsewhen(s2state === fence_clear){
        // 清除对应的meta行的dirty位
        fenceMetaWrite.req.valid := s2valid(0)
        fenceMetaWrite.req.bits.isFence := true.B

        fenceMetaWrite.req.bits.idx := getIdx(s2req(0).addr)
        fenceMetaWrite.req.bits.pos := s2pos

        fenceMetaWrite.req.bits.setdirty.valid := true.B
        fenceMetaWrite.req.bits.setdirty.bits := false.B

        // 彻底清除这一行
        fenceMetaWrite.req.bits.setvalid.valid := true.B
        fenceMetaWrite.req.bits.setvalid.bits := false.B

        fenceMetaWrite.req.bits.setreadOnly.valid := true.B
        fenceMetaWrite.req.bits.setreadOnly.bits := false.B

        fenceMetaWrite.req.bits.setfixed.valid := true.B
        fenceMetaWrite.req.bits.setfixed.bits := false.B

        fenceMetaWrite.req.bits.setTag.valid := true.B
        fenceMetaWrite.req.bits.setTag.bits := 0.U

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

    // 当两个都ready并且流水线中没有fence,mmioreq,mshrread,mmioresp,wb,refill的时候，axiReady才会拉高
    axiReady := (wfu.io.ready && mmiou.io.ready) &&
                (s1state =/= fence_read && s1state =/= fence_clear && s1state =/= mmioresp && s1state =/= mmioreq && s1state =/= mshrread && s1state =/= wb && s1state =/= refill) &&
                (s1state =/= fence_read && s2state =/= fence_clear && s2state =/= mmioresp && s2state =/= mmioreq && s2state =/= mshrread && s2state =/= wb && s2state =/= refill)

    // TODO enable continuous hit store forwarding(DONE)
    // TODO simplify the IO channel of DCacheData and DCacheMeta(DONE)

    // TODO mmio(DONE)
    // TODO reconstrcut the DCache(DONE)
    // TODO lr/sc
}
