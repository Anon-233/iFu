package iFu.sma

import chisel3._
import chisel3.util._

import iFu.axi3._
import iFu.axi3.AXI3Parameters._

import iFu.common._

class SMAR_Request extends CoreBundle {
    val araddr  = Output(UInt(xLen.W))
    val arlen   = Output(UInt(MLEN16.getWidth.W))
    val arsize  = Output(UInt(MSIZE4.getWidth.W))
    val arburst = Output(UInt(BURST_INCR.getWidth.W))
    val arvalid = Output(Bool())
}
class SMAR_Response extends CoreBundle {
    val rdata   = Input(UInt(xLen.W))
    val rlast   = Input(Bool())
    val rvalid  = Input(Bool())
}
class SMAR extends CoreBundle { // SMAR: simple memory access read
    val req  = new SMAR_Request
    val resp = new SMAR_Response
}

class SMAW_Request extends CoreBundle {
    val awaddr  = Output(UInt(xLen.W))
    val awlen   = Output(UInt(MLEN16.getWidth.W))
    val awsize  = Output(UInt(MSIZE4.getWidth.W))
    val awburst = Output(UInt(BURST_INCR.getWidth.W))
    val awvalid = Output(Bool())

    val wdata   = Output(UInt(xLen.W))
    val wstrb   = Output(UInt(4.W))
    val wlast   = Output(Bool())
    val wvalid  = Output(Bool())
}
class SMAW_Response extends CoreBundle {
    val wready  = Input(Bool())
}
class SMAW extends CoreBundle { // SMAW: simple memory access write
    val req  = new SMAW_Request
    val resp = new SMAW_Response
}

class SMAR_Adapter extends CoreModule {
    val io = IO(new Bundle {
        val original = Flipped(new SMAR_Request)
        val adapted  = new SMAR_Request

        val arready = Input(Bool())
        val rlast   = Input(Bool())
    })

    // s_idle: there is no request
    // s_ar  : sending read request to memory
    // s_r   : waiting for read response
    val s_idle :: s_ar :: s_r :: Nil = Enum(3)
    val state = RegInit(s_idle)

    val req = Reg(new SMAR_Request)

    io.adapted         := req
    io.adapted.arvalid := req.arvalid && (state === s_ar)

    // ======= FSM =======
    switch (state) {
        is (s_idle) {
            when (io.original.arvalid) {
                state := s_ar
                req := io.original
            }
        }
        is (s_ar) {
            when (io.arready) {
                state := s_r
            }
        }
        is (s_r) {
            when (io.rlast) {
                state := s_idle
            }
        }
    }
}

class SMAW_Adapter extends CoreModule {
    val io = IO(new Bundle {
        val original = Flipped(new SMAW_Request)
        val adapted  = new SMAW_Request

        val awready = Input(Bool())
        val wlast   = Input(Bool())
    })

    val s_idle :: s_aw :: s_w :: Nil = Enum(3)
    val state = RegInit(s_idle)

    val req = Reg(new SMAW_Request)

    io.adapted         := req
    io.adapted.awvalid := req.awvalid && (state === s_aw)
    io.adapted.wvalid  := req.wvalid  && (state === s_w)

    switch (state) {
        is (s_idle) {
            when (io.original.awvalid) {
                state := s_aw
                req := io.original
            }
        }
        is (s_aw) {
            when (io.awready) {
                state := s_w
            }
        }
        is (s_w) {
            when (io.wlast) {
                state := s_idle
            }
        }
    }
}

class SMA_Arbiter(num_r_reqs: Int, num_w_reqs: Int) extends CoreModule {
    val io = IO(new Bundle {
        val smar = Vec(num_r_reqs, Flipped(new SMAR))
        val smaw = Vec(num_w_reqs, Flipped(new SMAW))
        val axi3 = new AXI3
    })

    val chosen_ar = RegInit(0.U)
    val in_r_reqs = VecInit(io.smar.zipWithIndex.map{
        case (r, i) => {
            val adapter = Module(new SMAR_Adapter)
            adapter.io.original := r.req
            adapter.io.arready  := io.axi3.ar.fire && (chosen_ar === i.U)
            adapter.io.rlast    := io.axi3.r.bits.last && io.axi3.r.valid && (chosen_ar === i.U)
            adapter.io.adapted
        }
    })

    when (!in_r_reqs(chosen_ar).arvalid || io.axi3.ar.fire) {
        chosen_ar := PriorityEncoder(in_r_reqs.map(_.arvalid))
    }
    io.axi3.ar.valid      := in_r_reqs(chosen_ar).arvalid
    io.axi3.ar.bits.id    := chosen_ar
    io.axi3.ar.bits.addr  := in_r_reqs(chosen_ar).araddr
    io.axi3.ar.bits.len   := in_r_reqs(chosen_ar).arlen
    io.axi3.ar.bits.size  := in_r_reqs(chosen_ar).arsize
    io.axi3.ar.bits.burst := in_r_reqs(chosen_ar).arburst
    io.axi3.ar.bits.lock  := false.B
    io.axi3.ar.bits.cache := 0.U
    io.axi3.ar.bits.prot  := 0.U

    io.axi3.r.ready := true.B
    for (i <- 0 until num_r_reqs) {
        io.smar(i).resp.rdata  := io.axi3.r.bits.data
        io.smar(i).resp.rvalid := io.axi3.r.valid && (io.axi3.r.bits.id === i.U)
        io.smar(i).resp.rlast  := io.axi3.r.bits.last && io.smar(i).resp.rvalid
    }

    val chosen_aw = RegInit(0.U)
    val in_w_reqs = VecInit((io.smaw.zipWithIndex.map {
        case (w, i) => {
            val adapter = Module(new SMAW_Adapter)
            adapter.io.original := w.req
            adapter.io.awready := io.axi3.aw.fire && (chosen_aw === i.U)
            adapter.io.wlast := io.axi3.w.bits.last && io.axi3.w.ready
            adapter.io.adapted
        }
    }))

    when (!in_w_reqs(chosen_aw).awvalid || io.axi3.aw.fire) {
        chosen_aw := PriorityEncoder(in_w_reqs.map(_.awvalid))
    }
    io.axi3.aw.valid      := in_w_reqs(chosen_aw).awvalid
    io.axi3.aw.bits.id    := chosen_aw
    io.axi3.aw.bits.addr  := in_w_reqs(chosen_aw).awaddr
    io.axi3.aw.bits.len   := in_w_reqs(chosen_aw).awlen
    io.axi3.aw.bits.size  := in_w_reqs(chosen_aw).awsize
    io.axi3.aw.bits.burst := in_w_reqs(chosen_aw).awburst
    io.axi3.aw.bits.lock  := false.B
    io.axi3.aw.bits.cache := 0.U
    io.axi3.aw.bits.prot  := 0.U

    val chosen_w = RegInit(0.U)
    when (!in_w_reqs(chosen_w).wvalid || io.axi3.w.fire) {
        chosen_w := PriorityEncoder(in_w_reqs.map(_.wvalid))
    }
    io.axi3.w.valid      := in_w_reqs(chosen_w).wvalid
    io.axi3.w.bits.id    := chosen_w
    io.axi3.w.bits.data  := in_w_reqs(chosen_w).wdata
    io.axi3.w.bits.strb  := in_w_reqs(chosen_w).wstrb
    io.axi3.w.bits.last  := in_w_reqs(chosen_w).wlast

    for (i <- 0 until num_w_reqs) {
        io.smaw(i).resp.wready := io.axi3.w.fire && (io.axi3.w.bits.id === i.U)
    }

    io.axi3.b.ready := true.B
}
