package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._

class CBusArb extends CoreModule {
    val io = IO(new Bundle {
        val mmio_req = Input(new CBusReq)
        val wb_req   = Input(new CBusReq)
        val ref_req  = Input(new CBusReq)

        val mmio_resp = Output(new CBusResp)
        val wb_resp   = Output(new CBusResp)
        val ref_resp  = Output(new CBusResp)

        val cbus_req  = Output(new CBusReq)
        val cbus_resp = Input(new CBusResp)
    })
    
    // 实现 wb_req, ref_req的轮流发送，但是 mmio_req 优先级最高
    val cnt = RegInit(Bool(), init = true.B)

    val select = WireInit(0.U(2.W))

    when (io.mmio_req.valid) {
        select := 0.U
    } .otherwise {
        when (io.wb_req.valid && io.ref_req.valid) {
            select := Mux(cnt, 1.U, 2.U)
            cnt := !cnt
        } .elsewhen (io.wb_req.valid) {
            select := 1.U
        } .elsewhen (io.ref_req.valid) {
            select := 2.U
        }
    }

    val bus_req_default = Wire(new CBusReq)
    bus_req_default.valid        := false.B
    bus_req_default.isStore      := false.B
    bus_req_default.mask         := 0x0.U
    bus_req_default.axiLen       := MLEN16
    bus_req_default.axiBurstType := AXI_BURST_INCR
    bus_req_default.size         := MSIZE4
    bus_req_default.addr         := 0xbad.U
    bus_req_default.data         := 0xbad.U
    
    io.cbus_req := MuxCase(bus_req_default, Array(
        (select === 0.U) -> io.mmio_req,
        (select === 1.U) -> io.wb_req,
        (select === 2.U) -> io.ref_req
    ))

    mmio.resp.ready  := io.cbus_resp.ready && select === 0.U
    mmio.resp.isLast := io.cbus_resp.isLast && select === 0.U
    mmio.resp.data   := io.cbus_resp.data

    wb_resp.ready := io.cbus_resp.ready && select === 1.U
    wb_resp.isLast := io.cbus_resp.isLast && select === 1.U
    wb_resp.data   := io.cbus_resp.data

    ref_resp.ready := io.cbus_resp.ready && select === 2.U
    ref_resp.isLast := io.cbus_resp.isLast && select === 2.U
    ref_resp.data   := io.cbus_resp.data
}