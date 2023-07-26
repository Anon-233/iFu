package backend.memSystem

import chisel3._
import chisel3.util._

/*
各部件行为：
DcacheMeta：

s0传入的lsu请求信息会进行查找，

s1阶段，如果命中，反馈hit，hitPos，如果miss，传出miss后可以
进行置换的replacePos，(特别的如果发生了store命中readonly，这也算miss)

s2阶段如果是命中的store指令，就将对应的metaline的dirty置为true后写回

s3写完


s1传入的mshr来的fetch请求读取metaline
然后在s2阶段将读好的信息传给RPU

对于RPU传好的新信息，s1阶段将这些信息发起写回，s2完成

总结：双读写端口，一对读写端口用于lsu请求，
    一读端口用于mshr的fetch请求，一个写端口用于RPU的写回


DcacheData：

s1命中的lsu请求去读取对应的dataline，
s2读好dataline，load指令就读，store指令的话准备好wdata，最终于s3写回

对于RPU传好的新信息，s1阶段将这些信息发起写回，s2完成

总结：双读写端口，一对读写端口用于lsu请求，
    一读端口用于mshr的fetch请求，一个写端口用于RPU的写回


ReplaceUnit：

负责替换行为，包括fetch和writeback，

mshr要求替换的时候，会先在s0发起请求，随着流水线按照所给地址，命中的路等信息去读metaline，dataline
然后在s2阶段将将这些信息连同读好的metaline，dataline一并给RPU
RPU会在s3阶段启动替换行为

当替换完成之后，RPU会将新的metaline，dataline，路号，写回地址等信息在s0随着流水线，
s1写回DcacheMeta，s2写回DcacheData，同时，将替换完成的信息通知mshr

MSHRFile：
任何指令发生miss，都会传给mshr
mshr不满，就能接受任何load指令，同时mshr规定至多存一个store指令
除了prefetch对Replace的请求之外， mshr负责调控所有miss指令的信号的fetch

mshr的replay会在s0阶段发起，重新随流水线做完这个任务

NonBlockingDcache：
负责调控整个流水线的行为
s0阶段，在各种请求之间选择

注：对所有的内部事务，最后不回传任何东西。
    对成功走到s2的lsu和replay回传resp。
    对miss的store，必然传回nack，对miss的load，如果mshr未满，什么都不穿，满了传nack
*/


class CbusReq extends Bundle with HasDcacheParameters {
    val valid = Bool()
    val isStore = Bool()
    val size = UInt(2.W)
    val addr = UInt(32.W)
    val data = UInt(32.W)
    val mask = UInt((nRowBytes).W)
    val axiBurstType = UInt(2.W)
    val axiLen = UInt(8.W)
}

class CbusResp extends Bundle with HasDcacheParameters {
    val data = UInt(32.W)
    val isLast = Bool()
    val ready = Bool()
}


class DCacheReq extends Bundle with HasDcacheParameters
{
  val addr  = UInt(32.W)
  val data  = Bits(coreDataBits.W)
  val is_hella = Bool() // Is this the hellacache req? If so this is not tracked in LDQ or STQ
  val uop = new MicroOp()

}

class DCacheResp extends Bundle with HasDcacheParameters
{
  val data = Bits(coreDataBits.W)
  val is_hella = Bool()
  val uop = new MicroOp()
}








class MetaLine extends Bundle with HasDcacheParameters{
    val valid = Bool()
    val dirty = Bool()
    val tag = UInt(nTagBits.W)
    val age = UInt(10.W)
}


class MetaReq extends Bundle with HasDcacheParameters{
    val idx    = UInt(nIdxBits.W)
    val tag    = UInt(nTagBits.W)
    val wayMask = UInt(nWays.W)
    val wmeta = new MetaLine
    
    // mshr来读meta的时候所选择的路
    val replacePos = UInt(log2Ceil(nWays).W)

    // replay将命中的路
    val hitPos = UInt(log2Ceil(nWays).W)
}

class MetaResp extends Bundle with HasDcacheParameters{
    // 用valid来表示是否命中
    val rmeta  = new MetaLine
    // 如果一个store命中了一个readOnly，就认为是miss
    val hit = Bool()
    val hitPos = UInt(log2Ceil(nWays).W)
    // 如果没有命中的时候，可以进行替换的位置
    val replacePos = UInt(log2Ceil(nWays).W)
}

class DataReq extends Bundle with HasDcacheParameters{
    val wayMask = UInt(nWays.W)
    val wdata = Vec(nRowWords,UInt(32.W))
    val idx = UInt(nIdxBits.W)

    // mshr来读data的时候所选择的路
    val replacePos = UInt(log2Ceil(nWays).W)

    // replay将命中的路
    val hitPos = UInt(log2Ceil(nWays).W)
}

class DataResp extends Bundle with HasDcacheParameters{
    val rdata = Vec(nRowWords,UInt(32.W))
}

class DcacheMetaIO extends Bundle with HasDcacheParameters{
    val req = Input(Valid(new MetaReq))
    val resp = Output(Valid(new MetaResp))
}


class DcacheMeta extends Module with HasDcacheParameters{
    val io = IO(new Bundle{
        val lsuRead = new DcacheMetaIO
        val lsuWrite = new DcacheMetaIO
        val mshrRead = new DcacheMetaIO
        val rpuWrite = new DcacheMetaIO
        val replayRead = new DcacheMetaIO
        val reset = Input(Bool())

        val readOnlyBlockAddr = Input(Valid(UInt(32.W)))
    })

    def getYoungestPos = {
        var age = 1023.U(10.W)
        var pos = 0.U(log2Ceil(nWays).W)
        for(i <- 0 until nWays){
            when(rmetaSet(i).valid && rmetaSet(i).age < age){
                age = rmetaSet(i).age
                pos = i.U
            }
        }
        pos
    }

    // 数据结构
    val meta = SyncReadMem(nSets, Vec(nWays, new MetaLine))

    // reset
    val reseting = RegInit(true.B)
    reseting := io.reset
    val resetIdx =  RegInit(0.U(nIdxBits.W))

    when(reseting){
        when(resetIdx === (nSets-1).U){
            reseting := false.B
        }.otherwise{
            resetIdx := resetIdx + 1.U
        }
    }

    when(reseting){
        meta.write(resetIdx, VecInit(Seq.fill(nWays)(0.U.asTypeOf(new MetaLine))), (~0.U(nWays.W)).asBools)
    }
    
    
    // lsuRead
    val rmetaSet = meta.read(io.lsuRead.req.bits.idx, io.lsuRead.req.valid)
        // 特别注意，在lsuRead里面的waymask如果有1，是用来传入通知这个指令是store类型（不会实际写什么）
    val wantWrite = io.lsuRead.req.bits.wayMask.orR
    val blockAddr = Cat(io.lsuRead.req.bits.tag, io.lsuRead.req.bits.idx)
    val hitoh = VecInit(rmetaSet.map((x: MetaLine) => (x.tag === RegNext(io.lsuRead.req.bits.tag)) &&
                                        !(io.readOnlyBlockAddr.valid &&  (RegNext(blockAddr) === io.readOnlyBlockAddr.bits) && RegNext(wantWrite))
                                        // tag 要匹配，并且传进来的如果是一个试图访问只读块的store指令，就认为是miss
                                    )).asUInt 
                     
    val isfull = rmetaSet.map(_.valid).reduce(_ && _)
    val invalidPos = PriorityEncoder(VecInit(rmetaSet.map((x: MetaLine) => !(x.valid))).asUInt) 
    val youngestPos = getYoungestPos
    

    io.lsuRead.resp.valid := RegNext(io.lsuRead.req.valid)
    io.lsuRead.resp.bits.hit := hitoh.orR
    io.lsuRead.resp.bits.hitPos := PriorityEncoder(hitoh)
    io.lsuRead.resp.bits.rmeta := rmetaSet(PriorityEncoder(hitoh))
    io.lsuRead.resp.bits.replacePos := Mux(isfull, youngestPos, invalidPos)


    // lsuWrite
    when(!reseting && io.lsuWrite.req.valid){
        meta.write(io.lsuWrite.req.bits.idx, VecInit(Seq.fill(nWays)(io.lsuWrite.req.bits.wmeta)), io.lsuWrite.req.bits.wayMask.asBools)
    }

    io.lsuWrite.resp.valid := RegNext(io.lsuWrite.req.valid)
    io.lsuWrite.resp.bits := DontCare


    // mshrRead
    val replacePos = RegNext(io.mshrRead.req.bits.replacePos)
    val replaceMetaSet = meta.read(io.mshrRead.req.bits.idx, io.mshrRead.req.valid)
    io.mshrRead.resp.valid := RegNext(io.mshrRead.req.valid)
    io.mshrRead.resp.bits.rmeta := replaceMetaSet(replacePos)
    io.mshrRead.resp.bits.hit := DontCare
    io.mshrRead.resp.bits.hitPos := DontCare
    io.mshrRead.resp.bits.replacePos := DontCare

    // replayRead
    val hitPos = RegNext(io.replayRead.req.bits.hitPos)
    val hitMetaSet = meta.read(io.replayRead.req.bits.idx, io.replayRead.req.valid)
    io.replayRead.resp.valid := RegNext(io.replayRead.req.valid)
    io.replayRead.resp.bits.rmeta := hitMetaSet(hitPos)
    io.replayRead.resp.bits.hit := true.B
    io.replayRead.resp.bits.hitPos := hitPos
    io.replayRead.resp.bits.replacePos := DontCare


    // rpuWrite

    when(!reseting && io.rpuWrite.req.valid){
        meta.write(io.rpuWrite.req.bits.idx, VecInit(Seq.fill(nWays)(io.rpuWrite.req.bits.wmeta)), io.rpuWrite.req.bits.wayMask.asBools)
    }
    io.rpuWrite.resp.valid := RegNext(io.rpuWrite.req.valid)
    io.rpuWrite.resp.bits := DontCare

}


class DcacheDataIO extends Bundle with HasDcacheParameters{
    val req = Input(Valid(new DataReq))
    val resp = Output(Valid(new DataResp))
}


class DcacheData extends Module with HasDcacheParameters{
    val io = IO(new Bundle{
        val lsuRead = new DcacheDataIO
        val lsuWrite = new DcacheDataIO
        val mshrRead = new DcacheDataIO
        val rpuWrite = new DcacheDataIO
        val replayRead = new DcacheDataIO
        val reset = Input(Bool())
    })

    // 数据结构
    val data = SyncReadMem(nSets, Vec(nWays,Vec(nRowWords, UInt(32.W))))

    // reset
    val reseting = RegInit(true.B)  
    reseting := io.reset
    val resetIdx =  RegInit(0.U(nIdxBits.W))

    when(reseting){
        when(resetIdx === (nSets-1).U){
            reseting := false.B
        }.otherwise{
            resetIdx := resetIdx + 1.U
        }
    }

    when(reseting){
        val resetData = VecInit(Seq.fill(nWays){
            VecInit(Seq.fill(nRowWords)(0.U(32.W)))
        })
        data.write(resetIdx, resetData, (-1.S(nWays.W)).asBools)
    }

    // lsuRead
    val rdataSet = data.read(io.lsuRead.req.bits.idx, io.lsuRead.req.valid)
    io.lsuRead.resp.valid := RegNext(io.lsuRead.req.valid)
    io.lsuRead.resp.bits.rdata := rdataSet(RegNext(io.lsuRead.req.bits.hitPos))

    // lsuWrite
    when(!reseting && io.lsuWrite.req.valid){
        
        data.write(io.lsuWrite.req.bits.idx, VecInit(Seq.fill(nWays)(io.lsuWrite.req.bits.wdata)), io.lsuWrite.req.bits.wayMask.asBools)
    }
    io.lsuWrite.resp.valid := RegNext(io.lsuWrite.req.valid)
    io.lsuWrite.resp.bits := DontCare

    // mshrRead
    val replacePos = RegNext(io.mshrRead.req.bits.replacePos)
    val replaceDataSet = data.read(io.mshrRead.req.bits.idx, io.mshrRead.req.valid)
    io.mshrRead.resp.valid := RegNext(io.mshrRead.req.valid)
    io.mshrRead.resp.bits.rdata := replaceDataSet(replacePos)

    // rpuWrite
    when(!reseting && io.rpuWrite.req.valid){
        data.write(io.rpuWrite.req.bits.idx, VecInit(Seq.fill(nWays)(io.rpuWrite.req.bits.wdata)), io.rpuWrite.req.bits.wayMask.asBools)
    }
    io.rpuWrite.resp.valid := RegNext(io.rpuWrite.req.valid)
    io.rpuWrite.resp.bits := DontCare

    // replayRead
    val hitPos = RegNext(io.replayRead.req.bits.hitPos)
    val hitDataSet = data.read(io.replayRead.req.bits.idx, io.replayRead.req.valid)
    io.replayRead.resp.valid := RegNext(io.replayRead.req.valid)
    io.replayRead.resp.bits.rdata := hitDataSet(hitPos)

}


class DCacheErrors  extends Bundle with HasDcacheParameters{

}

class DCacheBundle  extends Bundle with HasDcacheParameters{
    val error = new DCacheErrors
    val lsu = Flipped(new lsuDMemIO)
}

class ReplaceUnit extends Module  with HasDcacheParameters{
    val io = IO(new Bundle{
        // 告诉外界是否准备好新的cbus请求（mshr取好判断只需 ！ready&&RegNext(ready)）
        val ready = Output(Bool())

        // 只有mshr才能负责来替换
        val needReplace = Input(Bool())
        // 要被替换的行的信息，用于写回
        val replaceMetaLine = Input(new MetaLine)
        val replaceDataLine = Input(Vec(nRowWords,UInt(32.W)))
        // 被替换的行的地址，在参与写回的时候要用
        val replaceAddr = Input(UInt(32.W))
        val fetchAddr = Input(UInt(32.W))
        // 被替换的行所属的路号，会保存起来，这也是fetch之后要写回的路号
        val replaceWay = Input(UInt(log2Ceil(nWays).W))

        // 新的行的信息，用于传给外界
        val newMetaLine = Output(new MetaLine)
        val newDataLine = Output(Vec(nRowWords,UInt(32.W)))
        // 新的行的地址，用于找对应的idx写回，以及通知mshr
        val newAddr = Output(UInt(32.W))
        // 之前的路号
        val newWay = Output(UInt(log2Ceil(nWays).W))

        // c线
        val cbusResp = Input(new CbusResp)
        val cbusReq = Output(new CbusReq)

    })

    val ready :: fetch :: wb :: Nil = Enum(3)
    val state = RegInit(ready)
    val offsetIdx = RegInit(0.U(log2Ceil(nRowBits/32).W))
    val dataLineBuffer = RegInit(VecInit(Seq.fill(nRowWords)(0.U(32.W))))
    val metaLineBuffer = RegInit(0.U.asTypeOf(new MetaLine))
    val replaceAddr = RegInit(0.U(32.W))
    val fetchAddr = RegInit(0.U(32.W))
    val replaceWay = RegInit(0.U(log2Ceil(nWays).W))
    val newAddr = RegInit(0.U(32.W))
    val newWay = RegInit(0.U(log2Ceil(nWays).W))
    
    io.cbusReq.valid := state === fetch || state === wb
    io.cbusReq.isStore := state === wb
    io.cbusReq.mask := 0xff.U
    // io.cbusReq.axiLen := 0xf.U
    // io.cbusReq.axiBurstType := 1.U

    io.ready := state === ready
    io.newMetaLine := metaLineBuffer
    io.newDataLine := dataLineBuffer
    io.newAddr := newAddr
    io.newWay := newWay


    when(state === ready){
        when(io.needReplace){
            replaceAddr := io.replaceAddr
            fetchAddr := io.fetchAddr
            replaceWay := io.replaceWay
            when(io.replaceMetaLine.valid && io.replaceMetaLine.dirty){

                state := wb
                dataLineBuffer := io.replaceDataLine
                
            }.otherwise{

                state := fetch
                
            }
        }

    }.elsewhen(state === fetch){

        io.cbusReq.addr := fetchAddr
        io.cbusReq.data := DontCare
        dataLineBuffer(offsetIdx) := io.cbusResp.data
        when(io.cbusResp.ready){
            state := Mux(io.cbusResp.isLast, ready, fetch)
            offsetIdx := Mux(io.cbusResp.isLast, 0.U, offsetIdx + 1.U)

            when(io.cbusResp.isLast){
                metaLineBuffer.valid := true.B
                metaLineBuffer.dirty := false.B
                metaLineBuffer.tag := fetchAddr(31, 12)
                metaLineBuffer.age := 0.U 
                newAddr := fetchAddr
                newWay := replaceWay
            }
        }

    }.elsewhen(state === wb){
        io.cbusReq.addr := replaceAddr
        io.cbusReq.data := dataLineBuffer(offsetIdx)
        when(io.cbusResp.ready){
            state := Mux(io.cbusResp.isLast, fetch, wb)
            offsetIdx := Mux(io.cbusResp.isLast, 0.U, offsetIdx + 1.U)
        }
    }

}


class lsuDMemIO extends Bundle with HasDcacheParameters
{
  // In lsu's dmem stage, send the request
  val req         = new DecoupledIO(Valid(new DCacheReq))
  // In lsu's LCAM search stage, kill if order fail (or forwarding possible)
  val s1kill     = Output(Bool())
  // Get a request any cycle
  val resp        = Flipped(new ValidIO(new DCacheResp))
  // In our response stage, if we get a nack, we need to reexecute
    //   拿不到数据，需要重复执行,用这个可以实现重复执行
  val nack        = Flipped(new ValidIO(new DCacheReq))

  val brupdate       = Output(new BrUpdateInfo)
  val exception    = Output(Bool())

//   这两个好像没用
//   val rob_pnr_idx  = Output(UInt(robAddrSz.W))
//   val rob_head_idx = Output(UInt(robAddrSz.W))

  // Clears prefetching MSHRs
  val forceOrder  = Output(Bool())
  val ordered     = Input(Bool())

  val perf = Input(new Bundle {
    val acquire = Bool()
    val release = Bool()
  })

}


class NonBlockingDcache extends Module with HasDcacheParameters{
    val io = IO(new DCacheBundle)

    // 解释:
        // replay : mshr的replay请求
        // wb : rpu的写回请求
        // lsu : lsu的请求
        // prefetch : prefetch的请求
        // mshrread : mshr的fetch请求(期间会读取meta,data最终送给RPU)
        // mshrwrite : 一条lsu指令在 s1 如果未命中，状态将变成mshrwrite，最终就会尝试写入到mshr中
        // nil : 什么都不做
    val replay :: wb ::  mshrread :: lsu  :: mshrwrite :: prefetch :: nil :: Nil = Enum(7)


    // 存储meta信息
    val meta = Module(new DcacheMeta)
    
    // 端口设置
    val lsuMetaRead = meta.io.lsuRead
    val lsuMetaWrite = meta.io.lsuWrite
    val mshrMetaRead = meta.io.mshrRead
    val rpuMetaWrite = meta.io.rpuWrite
    val replayMetaRead = meta.io.replayRead

    // 存储data信息
    val data = Module(new DcacheData)

    // 端口设置
    val lsuDataRead = data.io.lsuRead
    val lsuDataWrite = data.io.lsuWrite
    val mshrDataRead = data.io.mshrRead
    val rpuDataWrite = data.io.rpuWrite
    val replayDataRead = data.io.replayRead
    
    // 替换单元
    val RPU = Module(new ReplaceUnit)
    val rpuJustDone = Wire(Bool())
    val mshrReadValid = Wire(Bool())
    val mshrReplayValid =Wire(Bool())
    val prefetchValid = Wire(Bool())

    rpuJustDone := RPU.io.ready && RegNext(!RPU.io.ready)
    // 存储mshr的信息
    val mshrs = Module(new MSHRFile)
    

    // 只有流水线里面没有正在执行的fetch请求,才能发起新的fetch请求
    
    mshrs.io.replay.ready := true.B//有就接
    
    mshrReplayValid := mshrs.io.replay.valid 
    // TODO prefetch
    
    prefetchValid := false.B

    // 如果当周期检测到有非lsu请求的话，就将它置零，下周期lsu发送不过来，同时再去执行非lsu请求
    io.lsu.req.ready := !(rpuJustDone || mshrReplayValid || mshrReadValid || prefetchValid)

    // 检查全局，如果此时流水线的s0和s1阶段状态为lsu并且有store，就将其kill掉变成nil
    val s2StoreFailed = Wire(Bool())

    // 当mshrread的开始的时候，就将其valid为1并且给地址，当wb开始的时候，就将其valid置为0
    val readOnly1BlockAddr = Reg(Valid(UInt(nBlockAddrBits.W)))


    // TODO:prefetch
    // 优先级: rpu的写回(成功了只会做一次,必须一次成功) > mshr的replay >  mshr的fetch > lsu的请求 > prefetch 
    // 事实上,rpu写回和mshr的replay不会同时发生
    // (RPU写回至少8周期,mshr里面最多不超过8项连发,而且mshr每次replay必须等一次写回之后一周期才开始)



    val s0valid = Mux((rpuJustDone), true.B,
                    Mux((mshrReplayValid), true.B,
                    Mux((mshrReadValid), true.B,
                    Mux(io.lsu.req.valid, true.B,
                    Mux((prefetchValid), true.B, false.B)))))

    val dontCareReq = 0.U.asTypeOf(new DCacheReq)
    val s0req  = Mux(rpuJustDone, dontCareReq,
                    Mux(mshrReplayValid, (mshrs.io.replay.bits),
                    Mux(mshrReadValid, dontCareReq,
                    Mux(io.lsu.req.valid, io.lsu.req.bits.bits,//两个bits?
                    Mux(prefetchValid, dontCareReq, dontCareReq)))))
    

    var s0state =   Mux(rpuJustDone,        wb,
                    Mux(mshrReplayValid,    replay,
                    Mux(mshrReadValid,      mshrread,
                    Mux(io.lsu.req.valid,   lsu,
                    Mux(prefetchValid,      prefetch, 
                                            nil)))))
    
    val s0kill = io.lsu.s1kill


    
    //rpu拿到的新的写回信息 
    val s0newMetaLine = (RPU.io.newMetaLine)
    val s0newDataLine = (RPU.io.newDataLine)
    val s0newwbIdx = (getIdx(RPU.io.newAddr))
    val s0newAlloceWay = (RPU.io.newWay)

    // mshr的read请求所需信息
        // 这个地址是所需的地址是要给RPU,但是通过它可以找到要被替换的行所在的idx
    val s0fetchAddr = (mshrs.io.newFetchAddr.bits)
    val s0replaceIdx = (getIdx(s0fetchAddr))
    val s0replacePos = (mshrs.io.readPos)

    // mshr的replay请求所需信息
    val s0replayHitPos = (mshrs.io.hitPos)
    val s0replayIdx = (getIdx(mshrs.io.replay.bits.addr))

    // TODO prefetch

    
    // s0阶段接入mshr对meta的read请求,接入lsu(replay)对meta的read请求,接入rpu对meta的write请求

    when(s0state === lsu && s0valid){
        // 清掉store
        when((s2StoreFailed && isStore(s0req))|| IsKilledByBranch(io.lsu.brupdate, s0req.uop)){
            s0state = nil
        }.otherwise{
            lsuMetaRead.req.valid := s0valid
            lsuMetaRead.req.bits.idx := getIdx(s0req.addr)
            // 这里用到TLB之后,需要将虚拟地址转换为物理地址,采用的是VIPT,因此可能要等下周期TLB的结果
            // lsuMetaRead.req.bits.tag := s0req.addr(31, 12)

            // 单纯通知meta是不是一个写指令，不会实际store
            lsuMetaRead.req.bits.wayMask := Mux(isStore(s0req), 1.U(nWays.W), 0.U(nWays.W))

            // lsuMetaRead.req.bits.wmeta := DontCare
            // lsuMetaRead.req.bits.replacePos := DontCare
        }

    }.elsewhen(s0state === replay && s0valid){
        // 因为mshr的机制原因，里面至多会存一条store，这条一定要最先被做的，不用管后面的storefailed
        when(IsKilledByBranch(io.lsu.brupdate, s0req.uop)){
            s0state = nil
        }.otherwise{
            replayMetaRead.req.valid := s0valid
            replayMetaRead.req.bits.idx := s0replayIdx
            // replayMetaRead.req.bits.wayMask := DontCare
            // replayMetaRead.req.bits.wmeta := DontCare
            // replayMetaRead.req.bits.replacePos := DontCare
            replayMetaRead.req.bits.hitPos := s0replayHitPos
        }
        
        
    }.elsewhen(s0state === mshrread && s0valid){

        mshrMetaRead.req.valid := s0valid
        mshrMetaRead.req.bits.idx := s0replaceIdx
        // mshrMetaRead.req.bits.tag := DontCare
        // mshrMetaRead.req.bits.wayMask := DontCare
        // mshrMetaRead.req.bits.wmeta := DontCare
        mshrMetaRead.req.bits.replacePos := s0replacePos

    }.elsewhen(s0state === wb){
        // wb是kill不掉的,因为要已提交，要写回
        rpuMetaWrite.req.valid := true.B
        rpuMetaWrite.req.bits.idx := s0newwbIdx
        rpuMetaWrite.req.bits.wmeta := s0newMetaLine
        rpuMetaWrite.req.bits.wayMask := 1.U << s0newAlloceWay
        // rpuMetaWrite.req.bits.replacePos := DontCare
        // rpuDataWrite.req.bits.tag := DontCare 

    }.otherwise{
        lsuMetaRead.req.valid := false.B
        mshrMetaRead.req.valid := false.B
        rpuMetaWrite.req.valid := false.B
    }

    
    val s1valid = RegNext(s0valid                                     &&
                            !IsKilledByBranch(io.lsu.brupdate, s0req.uop) &&
                            !(io.lsu.exception && s0req.uop.usesLdq),
                            init=false.B)
    val s1req = RegNext(s0req)
    var s1state = RegNext(s0state)

    // RPU带来的的newdata的写回
    val s1newDataLine = RegNext(s0newDataLine)
    val s1newwbIdx = RegNext(s0newwbIdx)
    val s1newAlloceWay = RegNext(s0newAlloceWay)

    // mshr的read请求所需信息
    val s1fetchAddr = RegNext(s0fetchAddr)
    val s1replaceIdx = RegNext(s0replaceIdx)
    val s1replacePos = RegNext(s0replacePos)
        // 这个地址是用来给RPU的，dirty写回的时候要用
    val s1replaceAddr = Wire(UInt(32.W))

    // mshr的replay请求所需信息
    val s1replayHitPos = RegNext(s0replayHitPos)
    val s1replayIdx = RegNext(s0replayIdx)

    val s1kill = RegNext(s0kill)
    // 如果miss，记录下将要去替换的Pos
    val s1missAllocPos = Wire(UInt(log2Ceil(nWays).W))
    // 如果hit,记录下hit的Pos
    val s1hitPos = Wire(UInt(log2Ceil(nWays).W))

    // s1阶段,对于meta,接收两个resp,一个是lsu或repaly读出的,是要处理的,叫handleMetaline
    // 另一个是rpu写回的,是要写回的,叫replacedMetaline
    val s1handleMetaLine = Wire(new MetaLine)
    val s1replacedMetaLine = Wire(new MetaLine)

    when(s1state === lsu  && s1valid){
        when(s1kill || (s2StoreFailed && isStore(s1req)) || IsKilledByBranch(io.lsu.brupdate, s1req.uop)){
            s1state := nil
        }.otherwise{
            when(lsuMetaRead.resp.valid){
                s1handleMetaLine := lsuMetaRead.resp.bits.rmeta
                //在resp之前，meta内部判断是否是store,如果是store,就要判断是否是readOnly,如果是readOnly,就回传来miss
                when(lsuMetaRead.resp.bits.hit){

                    s1hitPos := lsuMetaRead.resp.bits.hitPos

                    // 接下来要去读data
                    lsuDataRead.req.valid := s1valid
                    lsuDataRead.req.bits.idx := getIdx(s1req.addr)
                    lsuDataRead.req.bits.hitPos := s1hitPos
                }.otherwise{
                    // miss的时候,需要将要替换的位置记录下来,同时将mshr的状态转换为mshrwrite,不用再读data
                    s1state := mshrwrite
                    s1missAllocPos := lsuMetaRead.resp.bits.replacePos
                }
            }
        }
        
    }.elsewhen(s1state === replay && s1valid){
        // 只保存读出的meta，然后根据他自己的信息去读data
        when(IsKilledByBranch(io.lsu.brupdate, s0req.uop)){
            s1state = nil
        }.otherwise{
            when(replayMetaRead.resp.valid){
                s1handleMetaLine := replayMetaRead.resp.bits.rmeta
                s1replayHitPos := replayMetaRead.resp.bits.hitPos

                // 接下来要去读data
                replayDataRead.req.valid := s1valid
                replayDataRead.req.bits.idx := s1replayIdx
                replayDataRead.req.bits.hitPos := s1replayHitPos
            }
        }
        
    }.elsewhen(s1state === mshrread && s1valid){
            
        when(mshrMetaRead.resp.valid){
            // 保存读的meta，再去读data
            s1replacedMetaLine := mshrMetaRead.resp.bits.rmeta
            s1replacedMetaLine := mshrMetaRead.resp.bits.rmeta
                // 拼装出要被替换的行的地址(最后的offset位待定)
            s1replaceAddr := Cat(mshrMetaRead.resp.bits.rmeta.tag, s1replaceIdx, 0.U(nOffsetBits.W))
            // 接下来要去读data
            mshrDataRead.req.valid := s1valid
            mshrDataRead.req.bits.idx := s1replaceIdx
            mshrDataRead.req.bits.replacePos := s1replacePos

        }
    }.elsewhen(s1state === wb){
        // wb是kill不掉的,因为要提交，要写回
        // 不用管读出什么meta,只要写回data就行
        rpuDataWrite.req.valid := true.B 
        rpuDataWrite.req.bits.idx := s1newwbIdx
        rpuDataWrite.req.bits.wdata := s1newDataLine
        rpuDataWrite.req.bits.wayMask := 1.U << s1newAlloceWay
    }


    val s2req = RegNext(s1req)
    val s2state = RegNext(s1state)
    val s2valid = RegNext(s1valid                                      &&
                            !IsKilledByBranch(io.lsu.brupdate, s1req.uop) &&
                            !(io.lsu.exception && s1req.uop.usesLdq),
                            init=false.B)


    val s2handleMetaLine = RegNext(s1handleMetaLine)
    val s2replacedMetaLine = RegNext(s1replacedMetaLine)

    // 用于repaly或者lsu的一个handledataline，或者metaread的一个replacedataline
    val s2handleDataLine = Wire(Vec(nRowWords,UInt(32.W)))
    val s2replacedDataLine = Wire(Vec(nRowWords,UInt(32.W)))
    
    // 写回mshr所需的miss路号
    val s2missAllocPos = RegNext(s1missAllocPos)

    // fetchAddr成功送给RPU之后,就可以将告诉mshr去fetching状态转换
    val s2fetchAddr = RegNext(s1fetchAddr)
    // 要被替换的地址，用于写回，以及拿到新信息的时候用于找到对应的way
    val s2replaceAddr = RegNext(s1replaceAddr)
    val s2replacePos = RegNext(s1replacePos)

    var sendResp = (Bool())
    var sendNack = (Bool())

    // bypass (这里做一个s3向s2转就行)
    val s3req = RegNext(s2req)
    val s3valid = RegNext(s2valid && s2state === lsu && isStore(s2req) &&
                         !s2StoreFailed)

    val s3bypass = s3valid && ((s2req.addr >> nOffsetBits) === (s3req.addr >> nOffsetBits))
    
    
    // 下面是s2执行的内容
    when((s2state === lsu || s2state === replay) && s2valid){
        // 能到s2的lsu和replay行为是一致的，只需根据s2req的要求，
        // 对handlemetaline和handledataline进行操作

        sendResp  = true.B
        sendNack  = false.B

        when(isStore(s2req)){
            // store
            s2handleMetaLine.dirty := true.B
            // TODO:data写操作

            // 处理resp

        }.otherwise{
            // load，注意这里可能有一个旁路转发的判断，需不需要使用s3的数据
            val s2rdata = 0.U  
            // store load bypassing
            val s2loaddata = Mux(s3bypass , s3req.data , s2rdata)
            
            // 准备resp
        }

        // 特别的，如果是replay，给mshr一个信号，告诉他这个fetchAddr已经被处理过了
        when(s2state === replay){
            mshrs.io.replayDone := true.B//不能一直是true，以后要改
        }

    }.elsewhen(s2state === mshrread && s2valid && RPU.io.ready){

        // 此时已经收集好了所需的replaceMetaline和replaceDataLine
        // 将他们连同fetchaddr一并交给RPU
        RPU.io.needReplace := s2state === mshrread && s2valid
        RPU.io.replaceMetaLine := s2replacedMetaLine
        RPU.io.replaceDataLine := s2replacedDataLine
        RPU.io.replaceAddr := s2replaceAddr
        RPU.io.fetchAddr := s2fetchAddr
        RPU.io.replaceWay := s2replacePos

        // 同时告诉mshr这个fetchaddr,用于感知fetching状态转换
        mshrs.io.fetchingBlockAddr := getBlockAddr(s2fetchAddr)
        
        
        // resp和nack都不发
        sendResp = false.B
        sendNack = false.B

       
    }.elsewhen(s2state === wb){
        // wb到此已经做好了

        // resp和nack都不发
        sendResp = false.B
        sendNack = false.B

    }.elsewhen(s2state === mshrwrite){

        when(!mshrs.io.full){
            // 将发生miss的项写入mshr(mshr里面会自行判断，如果有store，就不会写入新的store)
            mshrs.io.req.valid := s2valid
            mshrs.io.req.bits.addr := s2req.addr
            mshrs.io.req.bits.uop := s2req.uop
            mshrs.io.req.bits.data := s2req.data
            mshrs.io.replacePos := s2missAllocPos
        }.otherwise{
            // mshr满了，存不住,不写
        }

        when(isStore(s2req)){
            // 如果是成功到达s2的失败的store指令了，一定返回一个nack，并且s2StoreFailed置为1
            s2StoreFailed := true.B
            sendResp = false.B
            sendNack = true.B
        }.otherwise{
            // load指令分类讨论
            when(!mshrs.io.full){
            // 如果能写进去，就什么都不返回
                sendResp = false.B
                sendNack = false.B
            }.otherwise{
            // 如果写不进去，就返回一个nack,等待重发
                sendResp = false.B
                sendNack = true.B
            }
        }
        
        
    }.elsewhen(s2state === prefetch){
        // TODO
        sendResp = false.B
        sendNack = false.B
    }.elsewhen(s2state === nil){
        // 什么都不返回
        sendResp = false.B
        sendNack = false.B
    }

    mshrReadValid := mshrs.io.newFetchAddr.valid && 
                    !(s1state === mshrread && s1valid)     &&
                    !(s2state === mshrread && s2valid)

    io.lsu.resp.valid := sendResp
    io.lsu.resp.bits := 0.U.asTypeOf(new DCacheResp)
    io.lsu.nack.valid := sendNack
    io.lsu.nack.bits := 0.U.asTypeOf(new DCacheReq)

       

    // TODO lr/sc
    //


    // mmio


    

    


}
