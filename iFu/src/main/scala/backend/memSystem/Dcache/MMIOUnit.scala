package iFu.backend

import scala.collection.View.Fill

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.util._

class MMIOUnit extends Module with HasDcacheParameters {
    val io = IO(new CoreBundle{
        val ready = Output(Bool())

        val mmioReq  = Input(Valid(new DCacheReq))
        // mmioResp is a replay request
        val mmioResp = Output(Valid(new DCacheReq))

        val cbusResp = Input(new CBusResp)
        val cbusReq = Output(new CBusReq)
    })
    if (!FPGAPlatform) dontTouch (io)

    val ready :: fetch :: wb :: Nil = Enum(3)
    val state = RegInit(ready)

    val mmioReq = RegInit(0.U.asTypeOf(new DCacheReq))
    if (!FPGAPlatform) dontTouch(mmioReq)

    io.ready := state === ready

    io.mmioResp := DontCare
    io.mmioResp.valid := false.B
    io.mmioResp.bits  := mmioReq

    io.cbusReq.valid        := state === fetch || state === wb
    io.cbusReq.isStore      := state === wb
    io.cbusReq.mask         := Mux(state === fetch, 0.U, mmioReq.mask)
    io.cbusReq.axiLen       := MLEN1
    io.cbusReq.axiBurstType := AXI_BURST_INCR
    io.cbusReq.size         := mmioReq.uop.mem_size
    io.cbusReq.addr         := mmioReq.addr
    io.cbusReq.data         :=
        Mux(mmioReq.uop.mem_size === 0.U, Fill(4, mmioReq.data( 7, 0)),
        Mux(mmioReq.uop.mem_size === 1.U, Fill(2, mmioReq.data(15, 0)),
                                          mmioReq.data))

    when (state === ready) {
        when (io.mmioReq.valid) {
            state := Mux(isStore(io.mmioReq.bits), wb, fetch)
            mmioReq := io.mmioReq.bits
        }
    } .elsewhen (state === fetch) {
        when (io.cbusResp.ready) {
            assert(io.cbusResp.isLast, "mmio fetch must be single word")

            state := Mux(io.cbusResp.isLast, ready, fetch)

            io.mmioResp.valid     := true.B
            io.mmioResp.bits.data := io.cbusResp.data
        }
    } .elsewhen (state === wb) {
        val debug_lo_byte = mmioReq.data(7, 0)
        val debug_lo_half = mmioReq.data(15, 0)
        dontTouch(debug_lo_byte)
        dontTouch(debug_lo_half)

        when (io.cbusResp.ready) {
            assert(io.cbusResp.isLast, "mmio write must be single word")

            state := Mux(io.cbusResp.isLast, ready, fetch)

            io.mmioResp.valid := true.B
        }
    }
}
