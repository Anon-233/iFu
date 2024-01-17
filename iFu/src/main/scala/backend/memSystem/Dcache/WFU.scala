package iFu.backend

import chisel3._
import chisel3.util._
import iFu.common.{DCacheReq, _}
import iFu.common.Consts._
import iFu.util._


class WriteFetchUnit extends Module  with HasDcacheParameters{
    val io = IO(new CoreBundle{
        // 告诉外界是否准备好新的cbus请求（mshr取好判断只需 ready&&!RegNext(ready)）
        val ready = Output(Bool())
        // 只有mshr才能负责来通知替换
        val valid = Input(Bool())
        // 要被替换的行的信息，用于写回总线(如果是fence状态下传过来的，会写回，但是不会进入fetch newline 的状态)
        val metaresp = Input(new DcacheMetaResp)

        // 要去总线fetch读，并且之后写回meta和data的地址(另拉一根线到这里)
        val fetchAddr = Input(UInt(32.W))

        // 是不是只需要写回数据行,不需要refill
        val wbOnly = Input(Bool())

        // 当fetch完毕的时候,数据一定已经齐了,只需要启动meta行写回就可以了
        val fetchReady = Output(Bool())
        val fetchedAddrOut = Output(UInt(32.W))
        val newMeta = Output(new MetaLine)

        // 单字读写的请求
        val axiReadReq = Output(Valid(new DCacheReq))
        val axiReadResp = Input(Valid(new DCacheResp))
        val axiWriteReq = Output(Valid(new DCacheReq))

        // 专线用于控制meta的一些行的信息
        val fenceClearReq = Output(Valid(new DCacheReq))

        // 这个pos在读写,处置meta,data以及fence的时候都会用到
        val pos = Output(UInt(log2Ceil(nWays).W))

        // c线
        val cbusResp = Input(new CBusResp)
        val cbusReq = Output(new CBusReq)

    })

    io.axiReadReq := 0.U.asTypeOf(Valid(new DCacheReq))
    io.axiWriteReq := 0.U.asTypeOf(Valid(new DCacheReq))
    io.fenceClearReq := 0.U.asTypeOf(Valid(new DCacheReq))
    io.pos := 0.U.asTypeOf(UInt(log2Ceil(nWays).W))
    io.newMeta := 0.U.asTypeOf(new MetaLine)

    val ready :: fetch :: wb :: Nil = Enum(3)
    val state = RegInit(ready)
    val receive_head = RegInit(0.U(log2Ceil(nRowWords).W))
    val execute_head = RegInit(0.U(log2Ceil(nRowWords).W))
    val tail = RegInit(0.U((log2Ceil(nRowWords)+1).W))//宽度加1位,不然根本无法增大到nRowWords
    val refillIdx = RegInit(0.U(log2Ceil(nRowWords).W))
    val dataLineBuffer = RegInit(0.U.asTypeOf(Vec(nRowWords,UInt(32.W))))
    val replaceAddr = RegInit(0.U(32.W))
    val fetchAddr = RegInit(0.U(32.W))
    val wbOnly = RegInit(false.B)
    val getfirstWord = RegInit(false.B)
    val reqCounter = RegInit(0.U((log2Ceil(nRowWords)+1).W))
    val replaceWay = RegInit(0.U(log2Ceil(nWays).W))




    io.cbusReq.valid := state === fetch || (state === wb && getfirstWord)
    io.cbusReq.isStore := state === wb
    io.cbusReq.mask := Mux(state === wb , 0xf.U , 0x0.U)
    io.cbusReq.axiLen := MLEN16
    io.cbusReq.axiBurstType := AXI_BURST_INCR
    io.cbusReq.size := MSIZE4
    io.cbusReq.addr := 0.U
    io.cbusReq.data := 0.U

    io.ready := state === ready

    io.fetchReady := false.B
    io.fetchedAddrOut := 0.U

    when(state === ready){
        when(io.valid){
            replaceWay := io.metaresp.pos
            // 一进来的时候要块对齐（一次AXI请求的cache行为单位对齐）
            replaceAddr := Cat(io.metaresp.rmeta.tag, io.metaresp.idx, 0.U(nOffsetBits.W))
            fetchAddr := io.fetchAddr >> nOffsetBits.U << nOffsetBits.U
            
            wbOnly := io.wbOnly
            reqCounter := nRowWords.U

            // 初始化
            execute_head := 0.U
            receive_head := 0.U
            tail := 0.U
            refillIdx := 0.U

            when(io.metaresp.rmeta.valid && io.metaresp.rmeta.dirty){
                state := wb
            }.otherwise{
                state := fetch
            }
        }

    }.elsewhen(state === fetch){
        // 不同于写回,这里一进fetch就可以启动了
        io.cbusReq.addr := fetchAddr
        io.cbusReq.data := DontCare
        when(io.cbusResp.ready){
            state := Mux(io.cbusResp.isLast, ready, fetch)
            // 不需要buffer,cache里面写单字总是比总线取快
            refillIdx := Mux(io.cbusResp.isLast, 0.U, refillIdx + 1.U)

            // 在这个周期造一个单字写请求，写入cache对应行(同时作废掉对应行的meta信息)
            io.axiWriteReq.valid := true.B
            io.axiWriteReq.bits.addr := fetchAddr | (refillIdx << 2.U).asUInt
            io.axiWriteReq.bits.data := io.cbusResp.data

            io.pos := replaceWay

            when(io.cbusResp.isLast){
                {
                    // 发出信号通告流水线,下周期变refill
                    // 同时告诉mshr对应地址fetch完毕了
                    io.fetchReady := true.B
                    io.fetchedAddrOut := fetchAddr

                    io.newMeta.valid := true.B
                    io.newMeta.tag := getTag(fetchAddr)
                    io.newMeta.dirty := false.B
                    io.newMeta.readOnly := false.B
                    io.newMeta.fixed := false.B

                    fetchAddr := 0.U 
                    replaceWay := 0.U

                }
                
            }
        }

    }.elsewhen(state === wb){

        when(tail < nRowWords.U){
            // 发送一系列单字读请求,流水线保证连续nRowWords个周期执行完
            io.axiReadReq.valid := true.B
            io.axiReadReq.bits.addr := replaceAddr | (tail << 2.U).asUInt
            io.axiReadReq.bits.data := DontCare
            io.pos := replaceWay

            tail := tail + 1.U
        }

        when(io.axiReadResp.valid){
            // 从接到的第一个单字读请求开始，每个周期接收一个单字读请求的数据，
            // 用receive_head来记录接收位置，同时启动写回总线的请求
            getfirstWord := true.B
            dataLineBuffer(receive_head) := io.axiReadResp.bits.data
            receive_head := receive_head + 1.U
        }



        // 填充至一行满肯定比写回总线快，因此这里完全可以看作对一整行完好数据的处理
        io.cbusReq.addr := replaceAddr
        io.cbusReq.data := dataLineBuffer(execute_head)
        when(io.cbusResp.ready){
            state := Mux(!io.cbusResp.isLast,   wb , 
                     Mux( wbOnly            ,   ready ,//写回完成，正常指令去fetch，是fence指令则直接结束
                                                fetch))
            
            execute_head := execute_head + 1.U

            when(io.cbusResp.isLast){
                // 写回总线完毕,wbOnly的话可以造一个meta写请求,清除脏行
                when(wbOnly){
                    // 这是即将转为ready，可以将replaceWay和replaceAddr清空

                    // 做一个清除对应行的操作
                    io.fenceClearReq.valid := true.B
                    io.fenceClearReq.bits.addr := replaceAddr
                    io.fenceClearReq.bits.data := DontCare

                    io.pos := replaceWay

                    // 做完了恢复初始状态再退出
                    replaceAddr := 0.U
                    replaceWay := 0.U
                    wbOnly := false.B
                    tail := 0.U
                    execute_head := 0.U
                }
            }


        }
    }

}
