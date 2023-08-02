package iFu.backend
import chisel3._
import chisel3.util._
import iFu.common._

class MSHRdata extends CoreBundle with HasDcacheParameters{
    //该项是否有效
    val valid = Bool()

    // 该项的id（用于一表里面某一项对应的fetch结束时向二表中搜索同id的表项）
    val id = UInt(log2Up(nFirstMSHRs).W)

    // 该项的请求
    val req = new DCacheReq

    // 该项将来充填，必然命中于replaceway，replay的时候不用再进行命中判断，而是直接去找那个路
    val way = UInt(log2Ceil(nWays).W)

    // 流水线号
    val pipeNumber = UInt(1.W)

    // 该项是否在等待fetch
    val waiting = Bool()

    // 该项是否在fetch
    val fetching = Bool()

    // 该项是否已经fetch完毕，这时候就等待被使用replay
    val ready = Bool()

    // 该项是否已发送
    val issued = Bool()

}


class MSHR extends CoreModule with HasDcacheParameters{
    val io = IO{new Bundle{
        // 写入请求111
        val req = Flipped(Decoupled(new DCacheReq))
        // 传进来时候的replacePos(missAllocWay)111
        val replacePos = Input(UInt(log2Ceil(nWays).W))
        // 流水线号111
        val pipeNumber = Input(UInt(1.W))

        // 传出请求111
        val replayReq = Decoupled(new DCacheReq)
        // 传出时候的hitpos111
        val hitPos = Output(UInt(log2Ceil(nWays).W)) 
        // 流水线号111
        val getPipeNumber = Output(UInt(1.W))
        // 这一项是否真正被replay执行完毕111
        val replayDone = Input(Bool())

        // 分支预测调整TODO
        val brupdate = Input(new BrUpdateInfo())

        // 之后发进来的每条新的miss请求的地址111
        val newBlockAddr = Input(UInt(nBlockAddrBits.W))
        // 是不是用的同一块111
        val newblockAddrMatch = Output(Bool())

        // reset信号111
        val reset = Input(Bool())
        
        // 发进来的每条fetch请求的地址111
        val fetchingBlockAddr = Input(UInt(nBlockAddrBits.W))
        // 判断是不是fetch的就是自己这一块11
        val fetchingBlockAddrMatch = Output(Bool())
        // fetch完毕的信号111
        val fetchReady = Input(Bool())


        // 该项是否有效并且已经fetch完毕（可以发出去replay）11
        val active = Output(Bool())

        // 该项是否在等待fetch111
        val waiting = Output(Bool())


        // 对于一表，这里是一表所在对应行的索引，对于二表，这里是一表中对应的id111
        val id = Input(UInt(log2Up(nFirstMSHRs).W))
        // 该项的id（用于一表里面某一项对应的fetch结束时向二表中搜索同id的表项）111
        val getID = Output(UInt(log2Up(nFirstMSHRs).W))
        //111
        val isStore = Output(Bool())
    }}

    //io<>DontCare
    // 数据存储
    val mshr = RegInit(0.U.asTypeOf(new MSHRdata))


    when(io.reset){
        mshr := 0.U.asTypeOf(new MSHRdata)
        mshr.valid := false.B

    }

    // 告诉外界是否存了一个store指令
    io.isStore := isStore(mshr.req) && mshr.valid

    // 该项是否有效并且已经fetch完毕（可以发出去replay）
    io.active := mshr.ready && mshr.valid
    // 该项是否在等待fetch
    io.waiting := mshr.waiting && mshr.valid
    // 传出时候的hitpos
    io.hitPos := mshr.way

    // 该项是否可以写入新的请求（如果无效就证明这里可以用）
    io.req.ready := !mshr.valid
    // 该项是否可以发出去replay（如果有效并且已经fetch完毕就可以发出去）
    io.replayReq.valid := mshr.valid && mshr.ready

    io.replayReq.bits := mshr.req
    
    
    when(io.req.fire){
        // 满足则写入新的请求
        mshr.valid := true.B
        mshr.id := io.id
        mshr.req := io.req.bits
        mshr.waiting := true.B
        mshr.fetching := false.B
        mshr.ready := false.B
        mshr.issued := false.B
        mshr.way := io.replacePos
        mshr.pipeNumber := io.pipeNumber
    }

    // 传出id
    io.getID := mshr.id
    // 传出流水线号
    io.getPipeNumber := mshr.pipeNumber

    //分支预测调整
    when(isKilledByBranch(io.brupdate,mshr.req.uop)){
        mshr.valid := false.B
    }

    // 给外界返回match判断
    io.newblockAddrMatch := mshr.valid && mshr.req.addr === io.newBlockAddr
    io.fetchingBlockAddrMatch := mshr.valid && mshr.fetching && mshr.req.addr === io.fetchingBlockAddr

    // 状态机
    when(mshr.valid){
        when(mshr.waiting){
            // 正在取，则转为fetching,这里没有fire判断,而是直接感知RPU的fetchingBlockAddr信号
            when(io.fetchingBlockAddr === mshr.req.addr){
                mshr.waiting := false.B
                mshr.fetching := true.B
            }
        }

        when(mshr.fetching){
            // 取完了，则转为ready
            when(io.fetchReady){
                mshr.fetching := false.B
                mshr.ready := true.B
            }
        }

        when(mshr.ready && io.replayReq.fire){
            // 成功发出replay信号，则转为issued
            mshr.ready := false.B
            mshr.issued := true.B
        }

        //发送出去的两周期之后,检查是否传回了执行完毕的信号
        when(RegNext(RegNext(mshr.issued))){
            when(io.replayDone){
                // replay执行完毕，则转为无效
                mshr.valid := false.B
            }.otherwise{
                // replay没有执行完毕，回退到ready状态(还是直接清空?会有导致replay执行失败的情况吗)
                mshr.issued := false.B
                mshr.ready := true.B
            }
        }

    }

}


class MSHRFile extends CoreModule with HasDcacheParameters{
    val io = IO(new Bundle {

        // miss指令写回MSHR
            // 发生miss的请求
            val req  = Flipped(Decoupled(new DCacheReq))
            // 发生miss的请求的replacePos，用于之后读取被替换的行以及发给RPU去使用,以及replace的时候用
            val replacePos = Input(UInt(log2Ceil(nWays).W)) 
            // 流水线号
            val pipeNumberIn = Input(UInt(1.W))

        // 发起新的fetch请求
            // RPU是否空闲
            val RPUnotBusy = Input(Bool())
            // 传出所需的fetch地址111
            val newFetchAddr = Output(Valid(UInt(vaddrBits.W)))
            val readPos = Output(UInt(log2Ceil(nWays).W))
        
            
        // 发出去的replay请求
            // 发出去的replay请求信息 111
            val replay = Decoupled(new DCacheReq) 
            // replay对应的路111
            val hitPos = Output(UInt(log2Ceil(nWays).W)) 
            // 流水线号111
            val pipeNumberOut = Output(UInt(1.W))
            // replay是否执行完毕
            val replayDone = Input(Bool())

        // RPU的激活信号 
            // RPU传入的fetch地址
            val fetchingBlockAddr = Input(UInt(nBlockAddrBits.W))
            // fetchReady，当RPU成功拿到了一行，就会发出这个信号，通知mshr根据这个地址，
            // 去进行激活操作111
            val fetchReady = Input(Bool())


        // 告诉外界已满111
            val full = Output(Bool())

        // 传入的更新信息，这回逐一检测每一个LOAD指令是不是分支错误，如果是，就把它删掉
        // 对于STORE来说，由于LSU传来的STORE一定是分支预测正确的，所以不用管111
            val brupdate = Input(new BrUpdateInfo())
        
        // fence指令会清空所有的mshr111
            val fenceClear = Input(Bool())
            
        })

    //io := DontCare
    val firstMSHRs = VecInit((Seq.fill(nFirstMSHRs)(Module(new MSHR))).map(_.io))
    val secondMSHRs = VecInit((Seq.fill(nSecondMSHRs)(Module(new MSHR))).map(_.io))

    //记录一表match的信息
        // 一表中的每一项是否match
    val newblockAddrMatches = WireInit(0.U.asTypeOf(Vec(nFirstMSHRs, Bool())))
    val firstNewMatchway = WireInit(0.U(log2Up(nFirstMSHRs).W))
        // 一表中的每一项是否是fetch对应的地址
    val fetchingBlockAddrMatches = WireInit(0.U.asTypeOf((Vec(nFirstMSHRs, Bool()))))
    val firstFetchMatchway = WireInit((0.U(log2Up(nFirstMSHRs).W)))
    // 一表中的每一项是否可以写入新的请求
    val firstAllocatable = WireInit(0.U.asTypeOf(Vec(nFirstMSHRs, Bool())))
    // 一表是否已满
    val firstFull = WireInit(false.B)


    // 搜索是否有等待fetch的项
    val waitinglist = WireInit(0.U.asTypeOf(Vec(nFirstMSHRs, Bool())))
    val haswait = waitinglist.reduce(_ || _)
    val waitingpos = PriorityEncoder(waitinglist)

    
    
        
        for(i <- 0 until nFirstMSHRs){
        // firstMSHRs(i) := DontCare
        firstMSHRs(i).req.valid := false.B
        firstMSHRs(i).req.bits := io.req.bits
        firstMSHRs(i).replacePos := io.replacePos
        firstMSHRs(i).pipeNumber := io.pipeNumberIn

        // 一表的id是定好的行号
        firstMSHRs(i).id := i.U(log2Up(nFirstMSHRs).W)

        // 进行匹配，找空位等操作

        firstAllocatable(i) := firstMSHRs(i).req.ready

        firstMSHRs(i).newBlockAddr := getBlockAddr(io.req.bits.addr)
        newblockAddrMatches(i) := firstMSHRs(i).newblockAddrMatch

        firstMSHRs(i).brupdate := io.brupdate
        firstMSHRs(i).reset := !firstMSHRs(i).isStore && io.fenceClear

        firstMSHRs(i).fetchingBlockAddr := io.fetchingBlockAddr
        fetchingBlockAddrMatches(i) := firstMSHRs(i).fetchingBlockAddrMatch

        firstMSHRs(i).replayReq.ready := false.B
        firstMSHRs(i).replayDone := false.B
        firstMSHRs(i).fetchReady := false.B

        // 查看1表有没有正在等候的
        waitinglist(i) := firstMSHRs(i).waiting

    }

    


    // 找一表中的match项
    firstFetchMatchway := PriorityEncoder(fetchingBlockAddrMatches.asUInt)
    firstNewMatchway := PriorityEncoder(newblockAddrMatches.asUInt)

    firstFull := !(firstAllocatable.reduce(_ || _))

    // 传入的请求是不是首次miss
    val firstMiss = !(newblockAddrMatches.reduce(_ || _))
    val allocFirstMSHR = PriorityEncoder(firstAllocatable.asUInt)

    
    // 二表中的每一项是否可以写入新的请求
    val secondAllocatable = WireInit(0.U.asTypeOf(Vec(nSecondMSHRs, Bool())))
    val allocSecondMSHR = PriorityEncoder(secondAllocatable.asUInt)
    // 二表是否已满
    val secondFull = !(secondAllocatable.reduce(_ || _))


    val hasStores = WireInit(0.U.asTypeOf(Vec(nSecondMSHRs, Bool())))
    val hasStore = hasStores.reduce(_ || _)

    for(i <- 0 until nSecondMSHRs) {
        // 二表相对于一表，只用来写入，和brupdate调整
        // secondMSHRs(i):= DontCare
        secondMSHRs(i).req.valid := false.B
        secondMSHRs(i).req.bits := io.req.bits
        secondMSHRs(i).replacePos := io.replacePos
        secondMSHRs(i).pipeNumber := io.pipeNumberIn

        secondMSHRs(i).id := 0.U
        
        secondAllocatable(i) := secondMSHRs(i).req.ready

        secondMSHRs(i).fetchingBlockAddr := io.fetchingBlockAddr
        
        secondMSHRs(i).brupdate := io.brupdate
        secondMSHRs(i).reset := !secondMSHRs(i).isStore && io.fenceClear

        // 检查replay是否执行完毕
        secondMSHRs(i).replayDone := io.replayDone

        secondMSHRs(i).replayReq.ready := false.B
        secondMSHRs(i).fetchReady := false.B

        // 搜索存储store的信息
        hasStores(i) := secondMSHRs(i).isStore

        secondMSHRs(i).newBlockAddr :=  getBlockAddr(io.req.bits.addr)

    }

    // 任意一个满了，外界都不能再往里面写入新的请求
    val mshrFull = firstFull || secondFull
    io.full := mshrFull


    // 不满，并且不会再已有store的时候再存入新的store，才接收外界信号
    
    when( !mshrFull && !(hasStore && isStore(io.req.bits)) ){
        io.req.ready := true.B
        // 首次miss，一表二表都要写入
        when(firstMiss){
            firstMSHRs(allocFirstMSHR).req.valid := io.req.valid
            // 二表的id是一表中的行号id
            secondMSHRs(allocSecondMSHR).id := allocFirstMSHR
            secondMSHRs(allocSecondMSHR).req.valid := io.req.valid
        }.otherwise{
        // 非首次miss，只写入二表，id是一表它对应的那一项的id
            secondMSHRs(allocSecondMSHR).id := firstNewMatchway
            secondMSHRs(allocSecondMSHR).req.valid := io.req.valid
        }

    }.otherwise{
        // 一表二表都满了，不接收外界信号
        io.req.ready := false.B
    }


    // 如果一个fetch取好了，就把它从一表中删掉，然后激活二表中的对应项，等待之后用到它的时候一项一项的拿
    when(io.fetchReady){
        // 删除first表中的fetch地址项
        firstMSHRs(firstFetchMatchway).reset := true.B
        // 激活second表中的fetch地址项
        for(i <- 0 until nSecondMSHRs) {
            when(secondMSHRs(i).getID === firstFetchMatchway){
                secondMSHRs(i).fetchReady := true.B
            }
        }

        
    }



    // 只要RPU空闲,就可以传出新的fetch地址(如果有的话)
    val fetchable = haswait && io.RPUnotBusy

    // 向外发出需要fetch的信号
    when(fetchable){
        io.newFetchAddr.valid := true.B
        io.newFetchAddr.bits := (firstMSHRs(waitingpos).replayReq.bits.addr)
        io.readPos := firstMSHRs(waitingpos).hitPos
    }.otherwise{
        io.newFetchAddr.valid := false.B
        io.newFetchAddr.bits := 0.U(vaddrBits.W)
        io.readPos := 0.U
    }


    // 记录被激活的二表项
    val actives = WireInit(0.U.asTypeOf(Vec(nSecondMSHRs, Bool())))
    for(i <- 0 until nSecondMSHRs) {
        actives(i) := secondMSHRs(i).active
    }

    // 选取replay阶段
    // 是否真的有被激活的二表项
    val repalyactive = actives.reduce(_ || _)
    // 选一个被激活的二表项，发出去replay
    val replaypos = PriorityEncoder(actives)

    io.replay.bits  := 0.U.asTypeOf(new DCacheReq)
    io.hitPos := 0.U
    io.pipeNumberOut := 0.U
    when(repalyactive){
        io.replay.valid := true.B
        io.replay.bits := secondMSHRs(replaypos).replayReq.bits
        io.hitPos := secondMSHRs(replaypos).hitPos
        io.pipeNumberOut := secondMSHRs(replaypos).getPipeNumber
        // 如果外面接了，就告诉二表项，我已经取走了你的请求，可以准备清空了
        secondMSHRs(replaypos).replayReq.ready := io.replay.ready
    }.otherwise{
        io.replay.valid := false.B
    }



}
