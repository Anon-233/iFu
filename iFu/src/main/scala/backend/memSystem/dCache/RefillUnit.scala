package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._

class RefillReq extends CoreBundle {
    val tag = Bits(tagBits.W)
    val idx = Bits(idxBits.W)
    val wayMux = Bits(nWays.W)
}

class RefillUnit extends CoreModule {
    val io = IO(new Bundle {
        val req = Flipped(Decoupled(new RefillReq))
        val resp = Output(Bool())

        val idx  = Output(Valid(UInt()))

        val meta_write = Decoupled(new MeatWriteReq)
        val data_write = Decoupled(new DataWriteReq)

        val cbusReq  = Output(new CBusReq)
        val cbusResp = Input(new CBusResp)
    })

    val s_idle :: s_refill :: Nil = Enum(2)
    val state = RegInit(s_idle)

    val req = Reg(new RefillReq)
    val ref_buffer = Reg(Vec(refillCycles, UInt(xLen.W)))
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
    when (state === s_idle && io.req.fire) {
        state   := s_refill
        req     := io.req.bits
        enq_ptr := 0.U
        deq_ptr := 0.U
    } .elsewhen (state === s_refill) {
        io.cbusReq.valid   := enq_ptr < refillCycles.U
        io.cbusReq.addr    := Cat(req.tag, req.idx)
        when (io.cbusResp.ready) {
            ref_buffer(enq_ptr) := io.cbusResp.data
            enq_ptr := enq_ptr + 1.U
        }

        io.meta_write.valid       := deq_ptr === (refillCycles - 1).U
        io.meta_write.bits.idx    := req.idx
        io.meta_write.bits.tag    := req.tag

        io.data_write.valid       := deq_ptr < enq_ptr
        io.data_write.bits.wayMux := req.wayMux
        io.data_write.bits.addr   := ref_buffer(deq_ptr)

        when (io.data_write.fire) {
            deq_ptr := deq_ptr + 1.U
        }

        when (deq_ptr === (refillCycles - 1).U && io.data_write.fire) {
            state := s_idle
            io.resp := true.B
        }
    }
}