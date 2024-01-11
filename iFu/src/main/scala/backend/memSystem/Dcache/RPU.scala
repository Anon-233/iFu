package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.util._


class ReplaceUnit extends Module  with HasDcacheParameters{
    val io = IO(new CoreBundle{
        // 告诉外界是否准备好新的cbus请求（mshr取好判断只需 ready&&!RegNext(ready)）
        val ready = Output(Bool())

        // 只有mshr才能负责来替换
        val needReplace = Input(Bool())
        // 要被替换的行的信息，用于写回总线(如果是fence状态下传过来的，会写回，但是不会进入fetch newline 的状态)
        val replaceMetaLine = Input(new MetaLine)
        val replaceDataLine = Input(Vec(nRowWords,UInt(32.W)))
        // 被替换的行的地址，在参与写回的时候要用
        val replaceAddr = Input(UInt(32.W))

        // 要去总线fetch读，并且之后写回meta和data的地址
        val fetchAddr = Input(UInt(32.W))
        // 被替换的行所属的路号，会保存起来，这也是fetch之后要写回meta和data的路号
        val replaceWay = Input(UInt(log2Ceil(nWays).W))

        // 11新的行的信息，用于传给外界
        val newMetaLine = Output(new MetaLine)
        val newDataLine = Output(Vec(nRowWords,UInt(32.W)))
        // 11新的行的地址，用于找对应的idx写回，以及通知mshr
        val newAddr = Output(UInt(32.W))
        // 11之前的路号
        val newWay = Output(UInt(log2Ceil(nWays).W))

        val isFence = Input(Bool())

        val isMMIO = Input(Bool())
        val mmioWrite = Input(Bool())
        val mmioPipeNumberIn = Input(UInt(1.W))
        val mmioReq = Input(new DCacheReq)

        val mmioDone = Output(Bool())
        val mmioPipeNumber = Output(UInt(1.W))
        val mmioDoneReq = Output(new DCacheReq)

        val fetchingAddr = Output(UInt(32.W))

        // c线
        val cbusResp = Input(new CBusResp)
        val cbusReq = Output(new CBusReq)

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
    val isFence = RegInit(false.B)
    val isMMIO = RegInit(false.B)
    // 这个是为了和rpujustDone信号周期同步，使用寄存器结构
    val mmioDone = RegInit(false.B)
    val mmioReq = RegInit(0.U.asTypeOf(Valid(new DCacheReq)))
    
    val mmioPipeNumber = RegInit(0.U(1.W))




    io.cbusReq.valid := state === fetch || state === wb
    io.cbusReq.isStore := state === wb
    io.cbusReq.mask := Mux(state === wb , 0xf.U , 0x0.U)
    io.cbusReq.axiLen := Mux(isMMIO , MLEN1 , MLEN16)
    io.cbusReq.axiBurstType := AXI_BURST_INCR
    io.cbusReq.size := MSIZE4
    io.cbusReq.addr := 0.U
    io.cbusReq.data := 0.U


    io.ready := state === ready
    io.newMetaLine := metaLineBuffer
    io.newDataLine := dataLineBuffer
    io.newAddr := newAddr
    io.newWay := newWay

    io.fetchingAddr := fetchAddr

    io.mmioDone := mmioDone

    io.mmioDoneReq := Mux(mmioDone , mmioReq , 0.U.asTypeOf(Valid(new DCacheReq)))
    

    io.mmioPipeNumber := mmioPipeNumber


    when(state === ready){
        when(io.needReplace){
            replaceAddr := io.replaceAddr
            fetchAddr := io.fetchAddr
            replaceWay := io.replaceWay
            isFence := io.isFence
            isMMIO := io.isMMIO
            when(io.isMMIO){
                state := mmio
                state := Mux(io.mmioWrite , wb , fetch)
                mmioReq := io.mmioReq
                
                // 以mmio的req内信息为准
                mmioPipeNumber := io.mmioPipeNumberIn

            }.elsewhen(io.replaceMetaLine.valid && io.replaceMetaLine.dirty){

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
                when(isMMIO){
                    // mmio不需要造meta
                    mmioDone := true.B
                    
                }.otherwise{
                    metaLineBuffer.valid := true.B
                    metaLineBuffer.dirty := false.B
                    metaLineBuffer.tag := getTag(fetchAddr)
                    metaLineBuffer.age := 0.U
                    newAddr := fetchAddr
                    newWay := replaceWay
                }
                
            }
        }

    }.elsewhen(state === wb){
        io.cbusReq.addr := replaceAddr
        io.cbusReq.data := dataLineBuffer(offsetIdx)
        when(io.cbusResp.ready){
            state := Mux(io.cbusResp.isLast, Mux( isFence && isMMIO , ready ,fetch), wb)//写回完成，正常指令去fetch，是fence指令就直接回到ready
            offsetIdx := Mux(io.cbusResp.isLast, 0.U, offsetIdx + 1.U)

            if(io.cbusResp.isLast){
                when(isMMIO){
                    mmioDone := true.B
                }
            }


        }
    }

}