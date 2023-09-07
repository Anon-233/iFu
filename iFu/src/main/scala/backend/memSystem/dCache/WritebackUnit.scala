package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._

class WritebackReq extends CoreBundle {
    val tag = Bits(tagBits.W)
    val idx = Bits(idxBits.W)
    val wayMux = Bits(nWays.W)
}

class WritebackUnit extends CoreModule {
    val io = IO(new Bundle {
        val req = Flipped(Decoupled(new WritebackReq))
        val resp = Output(Bool())

        val idx  = Output(Valid(UInt()))

        val meta_read = Decoupled(new MetaReadReq)
        val data_req  = Decoupled(new DataReadReq)
        val data_resp = Input(UInt(xLen.W))

        val cbusReq  = Output(new CBusReq)
        val cbusResp = Input(new CBusResp)
    })

    val s_idle :: s_writeBack :: Nil = Enum(2)
    val state = RegInit(s_idle)

    val req = Reg(new WritebackReq)
    val wb_buffer = Reg(Vec(refillCycles, UInt(xLen.W)))
    val enq_ptr = RegInit(0.U(log2Up(refillCycles + 1).W))
    val deq_ptr = RegInit(0.U(log2Up(refillCycles + 1).W))

    // cbus default
    io.cbusReq.valid        := false.B
    io.cbusReq.isStore      := false.B
    io.cbusReq.mask         := 0x0.U
    io.cbusReq.axiLen       := MLEN16
    io.cbusReq.axiBurstType := AXI_BURST_INCR
    io.cbusReq.size         := MSIZE4
    io.cbusReq.addr         := 0xbad.U
    io.cbusReq.data         := 0xbad.U

    // ----------------------------------------------
    io.idx.valid       := state =/= s_idle
    io.idx.bits        := req.idx
    // ---------------------------------------------- 
    io.req.ready       := state === s_idle
    io.resp            := false.B
    // ----------------------------------------------
    io.meta_read.valid := false.B
    io.meta_read.bits  := DontCare
    io.data_req.valid  := false.B
    io.data_req.bits   := DontCare
    // ----------------------------------------------
    when (state === s_idle && io.req.fire) {  // io.req.fire 表示接受到写回请求
        state   := s_writeBack
        req     := io.req.bits
        enq_ptr := 0.U
        deq_ptr := 0.U
    } .elsewhen (state === s_writeBack) {
        io.meta_read.valid      := enq_ptr < refillCycles.U
        io.meta_read.bits.idx   := req.idx
        io.meta_read.bits.tag   := req.tag

        io.data_req.valid       := enq_ptr < refillCycles.U
        io.data_req.bits.wayMux := req.wayMux
        io.data_req.bits.addr   := Cat(req.idx, enq_ptr) << 2

        when (io.meta_read.fire && io.data_req.fire) {
            enq_ptr := enq_ptr + 1.U
        }

        io.cbusReq.valid   := deq_ptr < enq_ptr
        io.cbusReq.isStore := true.B
        io.cbusReq.mask    := 0xff.U
        io.cbusReq.addr    := Cat(req.tag, req.idx)
        io.cbusReq.data    := wb_buffer(deq_ptr)

        when (io.cbusResp.ready) {
            deq_ptr := deq_ptr + 1.U
        }

        when (deq_ptr === (refillCycles - 1).U && io.cbusResp.isLast) {
            state := s_idle
            io.resp := true.B
        }
    }
}