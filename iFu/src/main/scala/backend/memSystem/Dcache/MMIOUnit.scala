package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.util._


class MMIOUnit extends Module  with HasDcacheParameters{
    val io = IO(new CoreBundle{
        val ready = Output(Bool())

        val mmioReq = Input(Valid(new DCacheReq))

        val mmioResp = Output(Valid(new DCacheReq))

        // c线
        val cbusResp = Input(new CBusResp)
        val cbusReq = Output(new CBusReq)
    })

    val ready :: fetch :: wb :: Nil = Enum(3)
    val state = RegInit(ready)
    //
    val mmioReq = RegInit(0.U.asTypeOf(new DCacheReq))

    val fetchAddr = RegInit(0.U(vaddrBits.W))
    val wbAddr = RegInit(0.U(vaddrBits.W))

    io.mmioResp := 0.U.asTypeOf(Valid(new DCacheReq))


    io.cbusReq.valid := state === fetch || state === wb
    io.cbusReq.isStore := state === wb
    io.cbusReq.mask := Mux(state === wb , 0xf.U , 0x0.U)
    io.cbusReq.axiLen := MLEN1
    io.cbusReq.axiBurstType := AXI_BURST_INCR
    io.cbusReq.size := MSIZE4
    io.cbusReq.addr := 0.U
    io.cbusReq.data := 0.U
    
    io.ready := state === ready


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
        when(io.cbusResp.ready){
            assert(io.cbusResp.isLast, "mmio fetch must be single word")
            io.mmioResp.valid := true.B
            io.mmioResp.bits.data := io.cbusResp.data
            io.mmioResp.bits.uop := mmioReq.uop
            state := Mux(io.cbusResp.isLast, ready, fetch)
            
        }

    }.elsewhen(state === wb){
        io.cbusReq.addr := mmioReq.addr
        io.cbusReq.data := mmioReq.data

        when(io.cbusResp.ready){
            assert(io.cbusResp.isLast, "mmio write must be single word")
            io.mmioResp.valid := true.B
            io.mmioResp.bits.uop := mmioReq.uop
            state := Mux(io.cbusResp.isLast, ready, fetch)
        }
    }

}