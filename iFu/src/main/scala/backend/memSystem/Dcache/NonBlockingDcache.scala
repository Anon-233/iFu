
/*
 * 各部件行为：
 * DcacheMeta：
 * 
 * s0传入的lsu请求信息会进行查找，
 * 
 * s1阶段，如果命中，反馈hit，hitPos，如果miss，传出miss后可以
 * 进行置换的replacePos，(特别的如果发生了store命中readonly，这也算miss)
 * 
 * s2阶段如果是命中的store指令，就将对应的metaline的dirty置为true后写回
 * 
 * s3写完
 * 
 * 
 * s1传入的mshr来的fetch请求读取metaline
 * 然后在s2阶段将读好的信息传给RPU
 * 
 * 对于RPU传好的新信息，s1阶段将这些信息发起写回，s2完成
 * 
 * 总结：双读写端口，一对读写端口用于lsu请求，
 *     一读端口用于mshr的fetch请求，一个写端口用于RPU的写回
 * 
 * 
 * DcacheData：
 * 
 * s1命中的lsu请求去读取对应的dataline，
 * s2读好dataline，load指令就读，store指令的话准备好wdata，最终于s3写回
 * 
 * 对于RPU传好的新信息，s1阶段将这些信息发起写回，s2完成
 * 
 * 总结：双读写端口，一对读写端口用于lsu请求，
 *     一读端口用于mshr的fetch请求，一个写端口用于RPU的写回
 * 
 * 
 * ReplaceUnit：
 * 
 * 负责替换行为，包括fetch和writeback，
 * 
 * mshr要求替换的时候，会先在s0发起请求，随着流水线按照所给地址，命中的路等信息去读metaline，dataline
 * 然后在s2阶段将将这些信息连同读好的metaline，dataline一并给RPU
 * RPU会在s3阶段启动替换行为
 * 
 * 当替换完成之后，RPU会将新的metaline，dataline，路号，写回地址等信息在s0随着流水线，
 * s1写回DcacheMeta，s2写回DcacheData，同时，将替换完成的信息通知mshr
 * 
 * MSHRFile：
 * 任何指令发生miss，都会传给mshr
 * mshr不满，就能接受任何load指令，同时mshr规定至多存一个store指令
 * 除了prefetch对Replace的请求之外， mshr负责调控所有miss指令的信号的fetch
 * 
 * mshr的replay会在s0阶段发起，重新随流水线做完这个任务
 * 
 * NonBlockingDcache：
 * 负责调控整个流水线的行为
 * s0阶段，在各种请求之间选择
 * 
 * 注：对所有的内部事务，最后不回传任何东西。
 *     对成功走到s2的lsu和replay回传resp。
 *     对miss的store，必然传回nack，对miss的load，如果mshr未满，什么都不穿，满了传nack
*/

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
    val nRowBits       = dcacheParameters.nRowBits
    val nRowBytes      = dcacheParameters.nRowBytes
    val nRowWords      = dcacheParameters.nRowWords
    val nSets          = dcacheParameters.nSets
    val nWays          = dcacheParameters.nWays
    val coreDataBits   = dcacheParameters.coreDataBits
    val nBlockAddrBits = dcacheParameters.nBlockAddrBits
    val nFirstMSHRs    = dcacheParameters.nFirstMSHRs
    val nSecondMSHRs   = dcacheParameters.nSecondMSHRs

    def getIdx(vaddr: UInt): UInt       = dcacheParameters.getIdx(vaddr)
    def getTag(vaddr: UInt): UInt       = dcacheParameters.getTag(vaddr)
    def getBlockAddr(vaddr: UInt): UInt = dcacheParameters.getBlockAddr(vaddr)
    def isStore(req : DCacheReq): Bool  = dcacheParameters.isStore(req)

    def isMMIO(req : DCacheReq): Bool  = dcacheParameters.isMMIO(req)

}


class DCacheErrors  extends CoreBundle with HasDcacheParameters{
    // TODO
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
    // wb : rpu的写回请求
    // lsu : lsu的请求
    // prefetch : prefetch的请求
    // mshrread : mshr的fetch请求(期间会读取meta,data最终送给RPU)
    // mshrwrite : 一条lsu指令在 s1 如果未命中，状态将变成mshrwrite，最终就会尝试写入到mshr中(现将其和lsu合并)
    // nil : 什么都不做
    // fence : 清空所有的dirty行

    io.lsu.req.ready := false.B
    for(w <- 0 until memWidth){
        io.lsu.resp(w) := 0.U.asTypeOf(new Valid(new DCacheResp))
    }

    for (w <- 0 until memWidth) {
        io.lsu.nack(w) := 0.U.asTypeOf(new Valid(new DCacheReq))
    }


    val replay :: wb ::  mshrread :: lsu  :: prefetch  :: fence  :: mmioreq :: mmioresp :: nil :: Nil = Enum(9)



    // 替换单元
    val RPU = Module(new ReplaceUnit)
    RPU.io.needReplace := false.B
    RPU.io.replaceMetaLine := 0.U.asTypeOf(new MetaLine)
    RPU.io.replaceDataLine := 0.U.asTypeOf(Vec(nRowWords, UInt(32.W)))
    RPU.io.replaceAddr := 0.U
    RPU.io.fetchAddr := 0.U
    RPU.io.replaceWay := 0.U
    RPU.io.isFence := false.B
    RPU.io.isMMIO := false.B
    RPU.io.mmioWrite := false.B

    io.cbusReq := RPU.io.cbusReq
    RPU.io.cbusResp := io.cbusResp

    RPU.io.mmioReq := 0.U.asTypeOf(new DCacheReq)
    RPU.io.mmioPipeNumberIn := 0.U


    // 存储meta信息
    val meta = Module(new DcacheMeta)

    // 端口设置
    val lsuMetaRead = meta.io.lsuRead
    lsuMetaRead(0).req := 0.U.asTypeOf(Valid(new MetaReq))
    lsuMetaRead(1).req := 0.U.asTypeOf(Valid(new MetaReq))


    val lsuMetaWrite = meta.io.lsuWrite
    lsuMetaWrite(0).req := 0.U.asTypeOf(Valid(new MetaReq))
    lsuMetaWrite(1).req := 0.U.asTypeOf(Valid(new MetaReq))


    val mshrMetaRead = meta.io.mshrRead
    mshrMetaRead.req := 0.U.asTypeOf(Valid(new MetaReq))
    val rpuMetaWrite = meta.io.rpuWrite
    rpuMetaWrite.req := 0.U.asTypeOf(Valid(new MetaReq))

    val replayMetaRead = meta.io.replayRead
    replayMetaRead.req := 0.U.asTypeOf(Valid(new MetaReq))
    val replayMetaWrite = meta.io.replayWrite
    replayMetaWrite.req := 0.U.asTypeOf(Valid(new MetaReq))

    val fenceMetaRead = meta.io.fenceRead
    fenceMetaRead.req := 0.U.asTypeOf(Valid(new MetaReq))

    val fenceMetaClean = meta.io.fenceClean
    fenceMetaClean.req := 0.U.asTypeOf(Valid(new MetaReq))

    //只读设置
    meta.io.readOnlyBlockAddr.valid := !RPU.io.ready
    meta.io.readOnlyBlockAddr.bits  := RPU.io.fetchingAddr

//    meta.io.fenceTakeDirtyMeta := false.B
    fenceMetaClean.req.valid := false.B

    // 存储data信息
    val data = Module(new DcacheData)

    // 端口设置
    val lsuDataRead = data.io.lsuRead
    lsuDataRead(0).req := 0.U.asTypeOf(Valid(new DataReq))
    lsuDataRead(1).req := 0.U.asTypeOf(Valid(new DataReq))

    val lsuDataWrite = data.io.lsuWrite
    lsuDataWrite(0).req := 0.U.asTypeOf(Valid(new DataReq))
    lsuDataWrite(1).req := 0.U.asTypeOf(Valid(new DataReq))

    val mshrDataRead = data.io.mshrRead
    mshrDataRead.req := 0.U.asTypeOf(Valid(new DataReq))
    val rpuDataWrite = data.io.rpuWrite
    rpuDataWrite.req := 0.U.asTypeOf(Valid(new DataReq))

    val replayDataRead = data.io.replayRead
    replayDataRead.req := 0.U.asTypeOf(Valid(new DataReq))
    val replayDataWrite = data.io.replayWrite
    replayDataWrite.req := 0.U.asTypeOf(Valid(new DataReq))

    val fenceDataRead = data.io.fenceRead
    fenceDataRead.req := 0.U.asTypeOf(Valid(new DataReq))
    val fenceDataClean = data.io.fenceClean
    fenceDataClean.req := 0.U.asTypeOf(Valid(new DataReq))


    val rpuJustDone = Wire(Bool())

    val mshrReadValid = Wire(Bool())
    val mshrReplayValid =Wire(Bool())

    val fenceValid = Wire(Bool())

    val prefetchValid = Wire(Bool())

    // val cacopValid = Wire(Bool())

    val lsuNormalValid = Wire(Bool())
    val lsuMMIOValid = Wire(Bool())

    val rpuWBsuccess = WireInit(false.B)

    // 判断输入的有没有mmio请求
    val hasMMIO = io.lsu.req.bits.map( req =>
        req.valid && isMMIO(req.bits)
    ).reduce(_||_)

    val doingmmioResp = WireInit(false.B)
    
    lsuNormalValid := io.lsu.req.valid && !hasMMIO
    

    rpuJustDone := RPU.io.ready && RegNext(!RPU.io.ready)

    val rpuMMIODone = RPU.io.mmioDone
    val rpuNormalDone = rpuJustDone && !doingmmioResp
                    
    // 存储mshr的信息
    val mshrs = Module(new MSHRFile)
    mshrs.io.req.valid := false.B
    mshrs.io.req.bits := 0.U.asTypeOf(new DCacheReq)
    mshrs.io.replacePos := 0.U
    mshrs.io.pipeNumberIn := 0.U
    mshrs.io.RPUnotBusy := RPU.io.ready
    mshrs.io.replayDone := false.B
    mshrs.io.fetchingBlockAddr := 0.U

    

    // 只有流水线里面没有正在执行的fetch请求,才能发起新的fetch请求

    mshrs.io.replay.ready := true.B//有就接
    mshrs.io.brupdate := io.lsu.brupdate

    mshrReplayValid := mshrs.io.replay.valid

    // lsu还在发force_order并且dcache行里面还有dirty，就进行fence操作
    fenceValid := (io.lsu.force_order && fenceMetaRead.resp.bits.hasDirty) /* || (!io.lsu.force_order && io.lsu.req(?).is_cacop) */
    //清掉里面所有的load指令
    mshrs.io.fenceClear := fenceValid
    // 只要meta没有dirty，就可以回应fence，不需要管流水线和mshr状态（如果里面有没做完的指令，lsu肯定非空，unique仍然会停留在dispatch）
    io.lsu.ordered := !fenceMetaRead.resp.bits.hasDirty /* true.B */

    // TODO:   cacopValid := //

    // TODO prefetch

    prefetchValid := false.B

    // 如果当周期检测到有非lsu请求的话，就将它置零，下周期lsu发送不过来，同时再去执行非lsu请求
    io.lsu.req.ready := !(rpuNormalDone || 
                          mshrReplayValid ||
                          mshrReadValid || 
                          prefetchValid ||
                          (hasMMIO && doingmmioResp) ||//lsu准备进mmio，但是里面有mmioresp状态
                          RPU.io.mmioDone//一个mmio刚做完，下周期归它
                          )

    // 检查全局，如果此时流水线的s0和s1阶段状态为lsu并且有store，就将其kill掉变成nil
    val s2StoreFailed = WireInit(false.B)
//    val s2StoreReplay = WireInit(false.B)
//    val s2StoreDone   = WireInit(false.B)

    // 当mshrread的开始的时候，就将其valid为1并且给地址，当wb开始的时候，就将其valid置为0
    val readOnly1BlockAddr = Reg(Valid(UInt(nBlockAddrBits.W)))


    // TODO:prefetch
    // 优先级: rpu的写回(成功了只会做一次,必须一次成功) > mshr的replay >  mshr的fetch > lsu的请求 > prefetch
    // 事实上,rpu写回和mshr的replay不会同时发生
    // (RPU写回至少8周期,mshr里面最多不超过8项连发,而且mshr每次replay必须等一次写回之后一周期才开始)

    val s0valid = Mux((rpuNormalDone), true.B,
        Mux( rpuMMIODone    , true.B,
        Mux((mshrReplayValid), true.B,
            Mux((mshrReadValid), true.B,
                Mux(io.lsu.req.valid, true.B,
                    Mux((fenceValid), true.B,
                        Mux( prefetchValid ,true.B, false.B)))))))

    val dontCareReq = 0.U.asTypeOf(new DCacheReq)

    val s0req = WireInit(0.U.asTypeOf(Vec(memWidth , new DCacheReq)))
    val s0replayPipeNumber = mshrs.io.pipeNumberOut

    for(w <- 0 until memWidth){
        s0req(w)  := Mux(rpuNormalDone,       dontCareReq,
                     Mux(rpuMMIODone,        RPU.io.mmioDoneReq,
                     Mux(mshrReplayValid , (mshrs.io.replay.bits),
                     Mux(mshrReadValid,     dontCareReq,
                     Mux(io.lsu.req.valid,  io.lsu.req.bits(w).bits,//两个bits
                     Mux(prefetchValid,     dontCareReq, dontCareReq))))))
    }



    var s0state =   Mux(rpuNormalDone,        wb,
                    Mux(rpuMMIODone,         mmioresp,
                    Mux(mshrReplayValid,    replay,
                    Mux(mshrReadValid,      mshrread,
                    Mux(lsuNormalValid,     lsu,
                    Mux(fenceValid ,        fence,
                    Mux(lsuMMIOValid,       mmioreq,
                    Mux(prefetchValid,      prefetch,
                                            nil))))))))


    val s0kill = WireInit(VecInit(Seq.fill(memWidth)(false.B)))
    


    //rpu拿到的新的写回信息 
    val s0newMetaLine = (RPU.io.newMetaLine)
    val s0newDataLine = (RPU.io.newDataLine)
    val s0newwbIdx = (getIdx(RPU.io.newAddr))
    val s0newBolckAddr = getBlockAddr(RPU.io.newAddr)
    val s0newAlloceWay = (RPU.io.newWay)
    val s0mmioPipeNumber = (RPU.io.mmioPipeNumber)

    //告诉mshr去激活(将表1的fetching转成ready)
    mshrs.io.fetchingBlockAddr := s0newBolckAddr
    
    // wb成功，告诉mshr
    mshrs.io.fetchReady := rpuWBsuccess

    // mshr的read请求所需信息
    // 这个地址是所需的地址是要给RPU,但是通过它可以找到要被替换的行所在的idx
    val s0fetchAddr = ((mshrs.io.newFetchAddr.bits) >> nOffsetBits.asUInt) << nOffsetBits.asUInt
    val s0replaceIdx = getIdx(s0fetchAddr.asUInt)
    val s0replacePos = (mshrs.io.readPos)

    // mshr的replay请求所需信息
    val s0replayHitPos = (mshrs.io.hitPos)
    val s0replayIdx = (getIdx(mshrs.io.replay.bits.addr))

    // TODO prefetch
    

    // s0阶段接入mshr对meta的read请求,接入lsu(replay)对meta的read请求,接入rpu对meta的write请求

    when(s0state === lsu && s0valid){
        // 清掉store
        for(w <- 0 until memWidth){
            when((s2StoreFailed && isStore(s0req(w)))|| IsKilledByBranch(io.lsu.brupdate, s0req(w).uop)){
                s0kill(w) := true.B
            }.otherwise{
                lsuMetaRead(w).req.valid := s0valid
                lsuMetaRead(w).req.bits.idx := getIdx(s0req(w).addr)
                //这里用到TLB之后,需要将虚拟地址转换为物理地址,采用的是VIPT,因此可能要等下周期TLB的结果
                lsuMetaRead(w).req.bits.tag := getTag(s0req(w).addr)

                // 单纯通知meta是不是一个写指令，不会实际store
                lsuMetaRead(w).req.bits.isWrite := (isStore(s0req(w)))

                lsuMetaRead(w).req.bits.wmeta := DontCare
                lsuMetaRead(w).req.bits.readPos := DontCare
            }
        }


    }.elsewhen(s0state === replay && s0valid){
        // 因为mshr的机制原因，里面至多会存一条store，这条一定要最先被做的，不用管后面的storefailed
        for(w <- 0 until memWidth){
            when(IsKilledByBranch(io.lsu.brupdate, s0req(w).uop)) {
                s0kill(w) := true.B
            }.otherwise {
                replayMetaRead.req.valid := s0valid
                replayMetaRead.req.bits.idx := s0replayIdx
                // replayMetaRead.req.bits.wayMask := DontCare
                // replayMetaRead.req.bits.wmeta := DontCare
                // replayMetaRead.req.bits.replacePos := DontCare
                replayMetaRead.req.bits.readPos := s0replayHitPos
            }
        }



    }.elsewhen(s0state === mshrread && s0valid){

        mshrMetaRead.req.valid := s0valid
        mshrMetaRead.req.bits.idx := s0replaceIdx
        // mshrMetaRead.req.bits.tag := DontCare
        // mshrMetaRead.req.bits.wayMask := DontCare
        // mshrMetaRead.req.bits.wmeta := DontCare
        mshrMetaRead.req.bits.readPos := s0replacePos

    }.elsewhen(s0state === wb){
        // wb是kill不掉的,因为要已提交，要写回
        
        // rpuMetaWrite.req.bits.replacePos := DontCare
        // rpuDataWrite.req.bits.tag := DontCare 

    }.elsewhen(s0state === mmioresp || s0state === mmioreq){
        // mmioresp:s0不干活，等着后面s2交还给lsu
        // 
    }.elsewhen(s0state === fence){
        for( w<- 0 until memWidth){
            lsuMetaRead(w).req.valid := false.B
        }

        // 要告诉meta，fenceRead一行出来
        fenceMetaRead.req.valid := true.B

        mshrMetaRead.req.valid := false.B
        rpuMetaWrite.req.valid := false.B
    }.otherwise{
        for( w<- 0 until memWidth){
            lsuMetaRead(w).req.valid := false.B
        }

        mshrMetaRead.req.valid := false.B
        rpuMetaWrite.req.valid := false.B
    }


    val s1valid = RegNext(s0valid               &&
      !(io.lsu.exception && s0req(0).uop.use_ldq),
        init=false.B)
    val s1req = RegNext(s0req)
    for (w <- 0 until memWidth) { s1req(w).uop.brMask := GetNewBrMask(io.lsu.brupdate,s1req(w).uop) }

    val s1replayPipeNumber = RegNext(s0replayPipeNumber)
    var s1state = RegNext(s0state)

    // RPU带来的的newdata的写回
    val s1newMetaLine = RegNext(s0newMetaLine)
    val s1newDataLine = RegNext(s0newDataLine)
    val s1newwbIdx = RegNext(s0newwbIdx)
    val s1newBlockAddr = RegNext(s0newBolckAddr)
    val s1newAlloceWay = RegNext(s0newAlloceWay)
    val s1mmioPipeNumber = RegNext(s0mmioPipeNumber)

    // mshr的read请求所需信息
    val s1fetchAddr = RegNext(s0fetchAddr)
    val s1replaceIdx = RegNext(s0replaceIdx)
    val s1replacePos = RegNext(s0replacePos)
    // 这个地址是用来给RPU的，dirty写回的时候要用
    val s1replaceAddr = WireInit(0.U(32.W))

    // mshr的replay请求所需信息
    val s1replayHitPos = RegNext(s0replayHitPos)
    val s1replayIdx = RegNext(s0replayIdx)

    val s1kill = Wire(Vec(memWidth, Bool()))

    for(w <- 0 until memWidth){    //lsu的s1kill指的就是s1
        s1kill(w) := io.lsu.s1_kill(w) ||   //store失败，发回nack返回当前流水线， //store replay成功，告诉lsu一个nack去找下一个位置 //mshr里面有store，就不要让下一条进来
                    RegNext(s0kill(w)  ||
                    ( isStore(s0req(w)) && s2StoreFailed)
                    ) 
    }
    // 如果miss，记录下将要去替换的Pos
    val s1missAllocPos = WireInit(0.U.asTypeOf(Vec(memWidth , UInt(log2Ceil(nWays).W))))
    // 如果hit,记录下hit的Pos
    val s1hitPos = WireInit(0.U.asTypeOf(Vec(memWidth , UInt(log2Ceil(nWays).W))))
    val s1hit = WireInit(0.U.asTypeOf(Vec(memWidth , Bool())))

    // s1阶段,对于meta,接收两个resp,一个是lsu或repaly读出的,是要处理的,叫handleMetaline
    // 另一个是rpu写回的,是要写回的,叫replacedMetaline
    val s1handleMetaLine = WireInit(0.U.asTypeOf(Vec(memWidth , new MetaLine)))
    val s1replacedMetaLine = WireInit(0.U.asTypeOf(new MetaLine))


    when(s1state === lsu  && s1valid ){
        for(w <- 0 until memWidth){
            when((s2StoreFailed && isStore(s1req(w))) || IsKilledByBranch(io.lsu.brupdate, s1req(w).uop)){
                s1kill(w) := true.B
            }.otherwise{
                when(lsuMetaRead(w).resp.valid){
                    s1handleMetaLine(w) := lsuMetaRead(w).resp.bits.rmeta
                    //在resp之前，meta内部判断是否是store,如果是store,就要判断是否是readOnly,如果是readOnly,就回传来miss
                    when(lsuMetaRead(w).resp.bits.hit){
                        s1hit(w) := true.B

                        // 这个处理是用于防止后面的Store先于存在mshr的store执行，hasStore为1因此把他处理成miss,它之后s2的hasStore也为1，也不会存进mshr
                        // 由于mshr里面对于replay的store的处理，他前面如果有replay的store，他一定能在这里准确的感知到hasStore被变成0，s2当然也是0
                        // 换言之，任何lsu的请求到s1和s2他们感受到的hasStore的信息一定是一致的
                        when(isStore(s1req(0)) && mshrs.io.hasStore){s1hit(0) := false.B}
                        

                        s1hitPos(w) := lsuMetaRead(w).resp.bits.pos
                        // 接下来要去读data
                        lsuDataRead(w).req.valid := s1valid
                        lsuDataRead(w).req.bits.idx := getIdx(s1req(w).addr)
                        lsuDataRead(w).req.bits.readPos := s1hitPos(w)
                    }.otherwise{
                        // miss的时候,需要将要替换的位置记录下来,同时将mshr的状态转换为mshrwrite,不用再读data
                        s1hit(w) := false.B
                        s1missAllocPos(w) := lsuMetaRead(w).resp.bits.pos
                    }
                }
            }
        }

    }.elsewhen(s1state === replay && s1valid){
        // 只保存读出的meta，然后根据他自己的信息去读data
        for(w <- 0 until memWidth){
            when(IsKilledByBranch(io.lsu.brupdate, s1req(w).uop)){
                s1kill(w) := true.B
            }.otherwise{
                when(replayMetaRead.resp.valid){
                    s1handleMetaLine(w) := replayMetaRead.resp.bits.rmeta
                    s1replayHitPos := replayMetaRead.resp.bits.pos

                    // 接下来要去读data
                    replayDataRead.req.valid := s1valid
                    replayDataRead.req.bits.idx := s1replayIdx
                    replayDataRead.req.bits.readPos := s1replayHitPos
                }
            }
        }


    }.elsewhen(s1state === mshrread && s1valid){

        when(mshrMetaRead.resp.valid){
            // 保存读的meta，再去读data
            s1replacedMetaLine := mshrMetaRead.resp.bits.rmeta
            // 拼装出要被替换的行的地址(最后的offset位待定)
            s1replaceAddr := Cat(mshrMetaRead.resp.bits.rmeta.tag, s1replaceIdx, 0.U(nOffsetBits.W))
            // 接下来要去读data
            mshrDataRead.req.valid := s1valid
            mshrDataRead.req.bits.idx := s1replaceIdx
            mshrDataRead.req.bits.readPos := s1replacePos

        }
    }.elsewhen(s1state === wb){
        // wb是kill不掉的,因为要提交，要写回
        // 不用管读出什么meta,只要写回data就行
        
    }.elsewhen(s1state === mmioresp || s1state === mmioreq){
        // mmioresp:s1不干活，等着后面s2交还给lsu
        // mmioreq:s1不干活，等着后面发请求给RPU
    }.elsewhen(s1state === fence){
        when(!fenceMetaRead.resp.bits.hasDirty) {
            //没有Dirty就不做了
            s1state := nil 
        }.otherwise{
            s1replacedMetaLine := fenceMetaRead.resp.bits.rmeta
            s1replaceAddr := Cat(fenceMetaRead.resp.bits.rmeta.tag, fenceMetaRead.resp.bits.idx, 0.U(nOffsetBits.W))
            // 接下来要去读data
            fenceDataRead.req.valid := s1valid 
            fenceDataRead.req.bits.idx := fenceMetaRead.resp.bits.idx
            fenceDataRead.req.bits.readPos := fenceMetaRead.resp.bits.pos
        }
         
    }




    val s2state = RegNext(s1state)
    val s2valid = RegNext(s1valid &&
      !(io.lsu.exception && s1req(0).uop.use_ldq),
        init=false.B)

    val s2kill = Wire(Vec(memWidth , Bool()))
    for(w <- 0 until memWidth){
        s2kill(w) := RegNext(s1kill(w) ||
                            ( isStore(s1req(w)) && s2StoreFailed)
                            )
    }
    val s2hit = RegNext(s1hit)


    val s2req = RegNext(s1req)

    for (w <- 0 until memWidth) { s2req(w).uop.brMask := GetNewBrMask(io.lsu.brupdate,s2req(w).uop) }

    val s2replayPipeNumber = RegNext(s1replayPipeNumber)
    val s2replayHitPos = RegNext(s1replayHitPos)

    val s2hitPos = RegNext(s1hitPos)

    val writebackPos = WireInit(0.U.asTypeOf(Vec(memWidth , UInt(log2Ceil(nWays).W))))
    for(w <- 0 until memWidth){
        writebackPos(w) :=  Mux(s2state === lsu, s2hitPos(w),
                            Mux(s2state === replay, s2replayHitPos,
                                        0.U(log2Ceil(nWays).W)))
    }

    val s2newMetaLine = RegNext(s1newMetaLine)
    val s2newDataLine = RegNext(s1newDataLine)
    val s2newwbIdx = RegNext(s1newwbIdx)
    val s2newBlockAddr = RegNext(s1newBlockAddr)
    val s2newAlloceWay = RegNext(s1newAlloceWay)
    val s2mmioPipeNumber = RegNext(s1mmioPipeNumber)




    val s2handleMetaLine = RegNext(s1handleMetaLine)

    // 用于repaly或者lsu的一组handledataline，以及metaread或者fence的一个replacedataline
    val s2handleDataLine = WireInit(0.U.asTypeOf(Vec(memWidth ,Vec(nRowWords,UInt(32.W)))))
    for (w <- 0 until memWidth) {
        // lsu用lsuDataRead通道读出的data，replay用replayDataRead通道读出的data，其他情况用不到，置零
        s2handleDataLine(w) := Mux(s2state === lsu, lsuDataRead(w).resp.bits.rdata,
            Mux(s2state === replay, replayDataRead.resp.bits.rdata,
                0.U.asTypeOf(Vec(nRowWords, UInt(32.W)))))
    }

    val storeInfoGenerator = Module(new StoreInfogen)
    storeInfoGenerator.io.req := s2req
    storeInfoGenerator.io.writebackPos := writebackPos
    storeInfoGenerator.io.handleMetaLine := s2handleMetaLine
    storeInfoGenerator.io.handleDataLine := s2handleDataLine

    // lsu阶段，如果发生了miss，将由missArbiter来决定写入mshr行为
    val s2missAllocPos = RegNext(s1missAllocPos)
    val missArbiter = Module(new Missarbiter)
    missArbiter.io.req := s2req
    missArbiter.io.miss := s2hit.map(x => ~x)
    missArbiter.io.alive := s2kill.map(x => ~x)
    missArbiter.io.mshrisFull := mshrs.io.full
    missArbiter.io.missAllocPos := s2missAllocPos
    missArbiter.io.mshrstqIdx := mshrs.io.recentStqIdx
    missArbiter.io.mshrhasStore := mshrs.io.hasStore

    val s2replacedMetaLine = RegNext(s1replacedMetaLine)
    // val s2replacedDataLine = mshrDataRead.resp.bits.rdata
    val s2replacedDataLine = Mux(s2state === mshrread, mshrDataRead.resp.bits.rdata,
                             Mux(s2state === fence,    fenceDataRead.resp.bits.rdata,
                                0.U.asTypeOf(Vec(nRowWords, UInt(32.W)))))



    // fetchAddr成功送给RPU之后,就可以将告诉mshr去fetching状态转换
    val s2fetchAddr = RegNext(s1fetchAddr)
    // 要被替换的地址，用于写回，以及拿到新信息的时候用于找到对应的way
    val s2replaceAddr = RegNext(s1replaceAddr)
    val s2replacePos = RegNext(s1replacePos)

    var sendResp = WireInit(0.U.asTypeOf(Vec(memWidth,Bool())))
    var sendNack = WireInit(0.U.asTypeOf(Vec(memWidth,Bool())))

    // bypass (这里做一个s3向s2转就行)
    val s3state = RegNext(s2state)
    val s3req = RegNext(s2req)
    val s3valid = RegNext(s2valid)
    val s3hit = RegNext(s2hit)

    val s3bypass = WireInit(0.U.asTypeOf(Vec(memWidth , Bool())))

    val s2rdata = WireInit(0.U.asTypeOf(Vec(memWidth , UInt(32.W))))
    // store load bypassing

    val s3kill = RegNext(s2kill)

    for(w <- 0 until memWidth){
        // 只有0号流水线Store执行成功才可能发生bypass
        s3bypass(w) :=  s3valid && !s3kill(0) &&
          ((s3state === lsu && s3hit(0)) || (s3state === replay)) &&
          isStore(s3req(0)) &&
          ((s2req(w).addr >> 2.U ).asUInt === (s3req(0).addr >> 2.U).asUInt)
    }



    // 下面是s2执行的内容
    when(s2state === lsu && s2valid){
        // 先处理miss，传给mshr有关信息
        mshrs.io.req.valid := missArbiter.io.mshrReq.valid
        mshrs.io.req.bits := missArbiter.io.mshrReq.bits
        mshrs.io.replacePos := missArbiter.io.replacePos
        mshrs.io.pipeNumberIn := missArbiter.io.pipeNumber

        // 生成初处理过的send，nack信号，用于返回给lsu，同时生成StoreFailed,用来清空后面可能有的store
        s2StoreFailed := missArbiter.io.storeFailed
        sendNack := missArbiter.io.sendNack
        sendResp := missArbiter.io.sendResp

        // 再讨论命中的问题，根据hit,kill来分类讨论
        for(w <- 0 until memWidth){
            when(s2kill(w)){
                // kill掉的指令，不返回
                sendResp(w) := false.B
                sendNack(w) := false.B
            }.elsewhen(s2hit(w)){
                // hit的指令，返回数据
                sendResp(w) := true.B
                sendNack(w) := false.B

                        when(isStore(s2req(w))){
                            // meta,data写操作

                            lsuMetaWrite(w).req := storeInfoGenerator.io.metaWriteReq(w)
                            lsuDataWrite(w).req := storeInfoGenerator.io.dataWriteReq(w)

                            io.lsu.resp(w).bits.data := DontCare
                            io.lsu.resp(w).bits.uop := s2req(w).uop

                            /*s2StoreDone := true.B*/

                        }.otherwise{
                            // load，注意这里可能有一个旁路转发的判断，需不需要使用s3的数据
                            s2rdata(w) := s2handleDataLine(w)(s2req(w).addr(log2Ceil(nRowWords)+1,2))
                            // store load bypassing
                            val s2loaddata = Wire(UInt(32.W))
                            s2loaddata := Mux(s3bypass(w) , s3req(w).data , s2rdata(w))

                            // 准备resp
                            io.lsu.resp(w).bits.data := s2loaddata
                            io.lsu.resp(w).bits.uop := s2req(w).uop
                }
            }
        }





    }.elsewhen(s2state === replay && s2valid){
        // 特别的，如果是replay，给mshr一个信号，告诉他这个fetchAddr已经被处理过了
        mshrs.io.replayDone := true.B
        // 然后根据replayPipeNumber来准备对应流水线返回的内容
        when(s2replayPipeNumber === 0.U(1.W)){
            sendResp(0) := Mux(IsKilledByBranch(io.lsu.brupdate, s2req(0).uop) || s2kill(0), false.B , true.B )
            sendNack(0) := false.B
            sendResp(1) := false.B
            sendNack(1) := false.B
            
        }.elsewhen(s2replayPipeNumber === 1.U(1.W)){
            sendResp(0) := false.B
            sendNack(0) := false.B
            sendResp(1) := Mux(IsKilledByBranch(io.lsu.brupdate, s2req(1).uop) || s2kill(1), false.B , true.B )
            sendNack(1) := false.B
        }


        
        for(w <- 0 until memWidth){
            //对hadleMetaLine处理
            
            // 准备resp
                        when(isStore(s2req(w))) {
                            // store
                            // data,meta写操作
                            replayMetaWrite.req := storeInfoGenerator.io.metaWriteReq(w)
                            replayDataWrite.req := storeInfoGenerator.io.dataWriteReq(w)
                            
                            io.lsu.resp(w).bits.data := DontCare
                            io.lsu.resp(w).bits.uop := s2req(w).uop
                            

                        }.otherwise {
                            // load，注意这里可能有一个旁路转发的判断，需不需要使用s3的数据
                            s2rdata(w) := s2handleDataLine(w)(s2req(w).addr(log2Ceil(nRowWords) + 1, 2))
                            // store load bypassing
                            val s2loaddata = Wire(UInt(32.W))
                            s2loaddata := Mux(s3bypass(w), s3req(w).data, s2rdata(w))

                            // 准备resp
                            io.lsu.resp(w).bits.data := s2loaddata
                            io.lsu.resp(w).bits.uop := s2req(w).uop
                            
                        }

        }
    }.elsewhen(s2state === mshrread && s2valid && RPU.io.ready){
        //一条指令的fetch和dirty写回主存，都需要RPU请求
        // 此时已经收集好了所需的replaceMetaline和replaceDataLine
        // 将他们连同fetchaddr一并交给RPU
        RPU.io.needReplace := s2state === mshrread && s2valid
        RPU.io.replaceMetaLine := s2replacedMetaLine
        RPU.io.replaceDataLine := s2replacedDataLine
        RPU.io.replaceAddr := s2replaceAddr
        RPU.io.fetchAddr := s2fetchAddr
        RPU.io.replaceWay := s2replacePos

        RPU.io.isFence := false.B

        //同时告诉mshr这个fetchaddr,用于感知fetching状态转换
        mshrs.io.fetchingBlockAddr := getBlockAddr(s2fetchAddr.asUInt)


        // resp和nack都不发
        for(w <- 0 until memWidth){
            sendResp(w) := false.B
            sendNack(w) := false.B
        }

    }.elsewhen(s2state ===fence && s2valid && RPU.io.ready){
        RPU.io.needReplace := true.B
        RPU.io.replaceMetaLine := s2replacedMetaLine
        RPU.io.replaceDataLine := s2replacedDataLine
        RPU.io.replaceAddr := s2replaceAddr

        // fence 不需要告诉RPU这个fetchaddr,因为他不会去fetch
        // RPU.io.fetchAddr := s2fetchAddr
        
        // 这个是用于RPU，fecth完了想要写回的路，不会fetch，不会写回fetch到的什么meta和data，因此也不需要 
        // RPU.io.replaceWay := s2replacePos

        RPU.io.isFence := true.B
        //成功进入s2state fence并且RPU空闲的话，告诉metaRPU已经拿到了这个dirty，让他清空
        fenceMetaClean.req.valid := true.B
        fenceDataClean.req.valid := true.B
        
        // fence 不需要告诉mshr这个fetchaddr,因为他不会去fetch
        // // 同时告诉mshr这个fetchaddr,用于感知fetching状态转换
        // mshrs.io.fetchingBlockAddr := getBlockAddr(s2fetchAddr.asUInt)
        
        // resp和nack都不发
        for (w <- 0 until memWidth) {
            sendResp(w) := false.B
            sendNack(w) := false.B
        }

    }.elsewhen(s2state === wb && s2valid){
        // wb到此已经做好了

        // data,meta写操作

        rpuMetaWrite.req.valid := true.B
        rpuMetaWrite.req.bits.idx := s1newwbIdx
        rpuMetaWrite.req.bits.wmeta := s1newMetaLine
        rpuMetaWrite.req.bits.isWrite := true.B
        rpuMetaWrite.req.bits.writePos := s1newAlloceWay

        rpuDataWrite.req.valid := true.B
        rpuDataWrite.req.bits.idx := s1newwbIdx
        rpuDataWrite.req.bits.wdata := s1newDataLine
        rpuDataWrite.req.bits.isWrite := true.B
        rpuDataWrite.req.bits.writePos := s1newAlloceWay

        rpuWBsuccess := true.B


        // resp和nack都不发
        for (w <- 0 until memWidth) {
            sendResp(w) := false.B
            sendNack(w) := false.B
        }


    }.elsewhen(s2state === mmioreq && s2valid){
        // 
        val pipeline = Mux(s2req(1).is_uncacheable , 1.U(1.W) , 0.U(1.W))
        val mmioreq = s2req(pipeline)

        when(s2kill(pipeline)){
            // kill掉的指令，不返回
            sendResp(pipeline) := false.B
            sendNack(pipeline) := false.B

            // 没kill的话，根据总线busy判断
        }.elsewhen(RPU.io.ready){
            // RPU空闲的话，传入本次mmio的信息
            RPU.io.needReplace := true.B
            RPU.io.isMMIO := true.B
            RPU.io.mmioWrite := isStore(mmioreq)
            RPU.io.replaceMetaLine := DontCare
            RPU.io.replaceDataLine := VecInit(Seq.fill(nRowWords)(mmioreq.data))
            // 读和写是同一个地址,一次MMIO只会有一种操作
            RPU.io.replaceAddr := mmioreq.addr
            RPU.io.fetchAddr := mmioreq.addr

            // 存入请求本身和对应的流水线号
            RPU.io.mmioReq := mmioreq
            RPU.io.mmioPipeNumberIn := pipeline

            RPU.io.replaceWay := DontCare
            RPU.io.isFence := false.B

            // 什么都不往回发
            // 对于store指令，拉高storeFailed清掉接下来所有可能的store
            // 因为重发一定还是这个mmio，它失败了，后面的一定不执行，当前传入的mmio请求不做完，RPUbusy，
            // 它一定失败，因此看这个总线繁忙就可以限制掉这件事情。
            // MMload一定前后无连着什么MMIO操作，因此不用特别判断。
            when (isStore(mmioreq)) {
                
                sendResp(pipeline) := false.B
                // 自己一定能写入，不用发nack
                // s2StoreFailed := true.B 自己一定能写入,不用发StoreFailed
                sendNack(pipeline) := false.B
            }.otherwise {
                sendResp(pipeline) := false.B
                sendNack(pipeline) := false.B
            }


        }.otherwise{
            // RPU不空闲的话，一定找对应的流水线号重发,另一个肯定什么都不往回发
            when(pipeline === 0.U(1.W)){
                sendResp(0) := false.B
                sendNack(0) := true.B
                sendResp(1) := false.B
                sendNack(1) := false.B
            
            }.elsewhen(pipeline === 1.U(1.W)){
                sendResp(0) := false.B
                sendNack(0) := false.B
                sendResp(1) := false.B
                sendNack(1) := true.B
            }
            
            // 特别的，mmio指令是store，拉高storeFailed清掉接下来所有可能的store
            // 并且要特别看一下里面是不是正在执行的是自己的store，如果是就不要发nack！
            // 否则会导致execute_head掉的太后面
            when (isStore(mmioreq)) {
                s2StoreFailed := true.B
                when(RPU.io.doingMMIO && RPU.io.mmiostqIdx === mmioreq.uop.stqIdx){
                    sendNack(0) := false.B
                }
            }

        }

    }.elsewhen(s2state === mmioresp && s2valid){
        
        // 装载newDataLine的0号数据作为可能的读操作的resp的data
        for(w <- 0 until memWidth){
            io.lsu.resp(w).bits.data := s2newDataLine(0)
            io.lsu.resp(w).bits.uop := s2req(w).uop
        }



        // 选择路号做回复
        when(s2mmioPipeNumber === 0.U(1.W)){
            sendResp(0) := true.B
            sendNack(0) := false.B
            sendResp(1) := false.B
            sendNack(1) := false.B
            
        }.elsewhen(s2mmioPipeNumber === 1.U(1.W)){
            sendResp(0) := false.B
            sendNack(0) := false.B
            sendResp(1) := true.B
            sendNack(1) := false.B
        }

            
    }.elsewhen(s2state === prefetch){
        // TODO
        for (w <- 0 until memWidth) {
            sendResp(w) := false.B
            sendNack(w) := false.B
        }
    }.elsewhen(s2state === nil){
        // 什么都不返回
        for (w <- 0 until memWidth) {
            sendResp(w) := false.B
            sendNack(w) := false.B
        }
    }

    //特判对于0号流水线store miss 的nack
    io.lsu.nack(0).bits := s2req(0)
    io.lsu.nack(1).bits := s2req(1)

    // when(isStore(s2req(0)) && (s2state === replay || (s2state === lsu && s2hit(0)) ) ){
    //     //如果有replay的话，或者lsu成功的话，让后面的store刷掉 这种情况必然发回的stqidx的下一个
    //     sendNack(0) := true.B
    //     io.lsu.nack(0).bits.uop.stqIdx := s2req(0).uop.stqIdx + 1.U
    // }

    // 按情况返回resp或nack(replay不用看kill，lsukiil自然为假)
    for(w <- 0 until memWidth){
        io.lsu.nack(w).valid := sendNack(w)
        io.lsu.resp(w).valid := sendResp(w)
    }
    

    // 检查流水线里面是不是至多有一条mshrread 
    mshrReadValid := mshrs.io.newFetchAddr.valid &&
      !(s1state === mshrread && s1valid)     &&
      !(s2state === mshrread && s2valid)


    // 流水线里面有mmioresp的时候，下一个请求不要进来(可能是重的)
    lsuMMIOValid := (io.lsu.req.valid && hasMMIO) &&
      !(s1state === mmioresp && s1valid) &&
      !(s2state === mmioresp && s2valid) 

    
    doingmmioResp := (s2state === mmioresp && s2valid) ||
                    (s1state === mmioresp && s1valid)

    
    


    // TODO enable continuous hit store forwarding(DONE)
    // TODO simplify the IO channel of DCacheData and DCacheMeta(DONE)

    // TODO mmio
    // TODO lr/sc
}
