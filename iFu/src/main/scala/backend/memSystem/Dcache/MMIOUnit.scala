package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.util._
import scala.collection.View.Fill


class MMIOUnit extends Module  with HasDcacheParameters{
    val io = IO(new CoreBundle{
        val ready = Output(Bool())

        val mmioReq = Input(Valid(new DCacheReq))

        val mmioResp = Output(Valid(new DCacheReq))

        // c线
        val cbusResp = Input(new CBusResp)
        val cbusReq = Output(new CBusReq)
    })

    if(!FPGAPlatform)dontTouch(io)


    val ready :: fetch :: wb :: Nil = Enum(3)
    val state = RegInit(ready)
    //
    val mmioReq = RegInit(0.U.asTypeOf(new DCacheReq))

    val fetchAddr = RegInit(0.U(vaddrBits.W))
    val wbAddr = RegInit(0.U(vaddrBits.W))

    io.mmioResp := 0.U.asTypeOf(Valid(new DCacheReq))

    io.cbusReq.valid := state === fetch || state === wb
    io.cbusReq.isStore := state === wb
    io.cbusReq.mask := Mux(state === fetch, 0.U, mmioReq.mask)
    io.cbusReq.axiLen := MLEN1
    io.cbusReq.axiBurstType := AXI_BURST_INCR
    io.cbusReq.size := MSIZE4
    io.cbusReq.addr := 0.U
    io.cbusReq.data := 0.U
    
    io.ready := state === ready

    if(!FPGAPlatform)dontTouch(mmioReq)

    when(state === ready){
        when(io.mmioReq.valid){
            wbAddr := io.mmioReq.bits.addr
            fetchAddr := io.mmioReq.bits.addr
            state := Mux(isStore(io.mmioReq.bits), wb, fetch)
            mmioReq := io.mmioReq.bits
        }

    }.elsewhen(state === fetch){

        io.cbusReq.addr := fetchAddr
        io.cbusReq.data := DontCare
        io.cbusReq.size := mmioReq.uop.mem_size
        when(io.cbusResp.ready){
            assert(io.cbusResp.isLast, "mmio fetch must be single word")
            io.mmioResp.valid := true.B
            io.mmioResp.bits.data := io.cbusResp.data
            io.mmioResp.bits.uop := mmioReq.uop
            io.mmioResp.bits.addr := mmioReq.addr
            state := Mux(io.cbusResp.isLast, ready, fetch)
            
        }

    }.elsewhen(state === wb){
        io.cbusReq.addr := mmioReq.addr
        // 设置size
        io.cbusReq.size := mmioReq.uop.mem_size
        // 根据粒度, 造写入的数据,例如写入字节,始终要写入的是低8位,但是mask的不同决定写入位置不一样
        // 因此,如果st.b就是四份最低字节
        // 如果st.h就是两份低半字,st.w才是一份字
        // 然后根据mask让axi那边对应写
                                        // byte
        io.cbusReq.data := Mux(mmioReq.uop.mem_size === 0.U, Fill(4, mmioReq.data(7, 0)),
                                        // half
                            Mux(mmioReq.uop.mem_size === 1.U, Fill(2, mmioReq.data(15, 0)), 
                                        // word
                                                                    mmioReq.data))
        val debug_lo_byte = mmioReq.data(7, 0)
        val debug_lo_half = mmioReq.data(15, 0)

        dontTouch(debug_lo_byte)
        dontTouch(debug_lo_half)

        when(io.cbusResp.ready){
            assert(io.cbusResp.isLast, "mmio write must be single word")
            io.mmioResp.valid := true.B
            io.mmioResp.bits := mmioReq
            state := Mux(io.cbusResp.isLast, ready, fetch)
        }
    }

}