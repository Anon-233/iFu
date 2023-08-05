package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._

class MSHRReq extends DCacheReq {
  val old_meta  = new MetaData
  val wayMux    = UInt(nWays.W)
}

class MSHR extends CoreModule {
    val io = IO(new Bundle {
        val req_pri_val = Input(Bool())     // 首个（怎么知道是首个的？）请求有效
        val req_pri_rdy = Output(Bool())    // 能否接受该block的首个miss
        val req_sec_val = Input(Bool())
        val req_sec_rdy = Output(Bool())    // 能否接受该block的次级miss

        val brupdate       = Input(new BrUpdateInfo)
        val exception      = Input(Bool())

        val req = Input(new MSHRReq)

        val idx = Output(Valid(UInt(idxBits.W)))
        val way = Output(Valid(UInt(nWays.W)))
        val tag = Output(Valid(UInt(tagBits.W)))

        val wb_req   = Decoupled(new WritebackReq)
        val wb_resp  = Input(Bool())
        val ref_req  = Decoupled(new RefillReq)
        val ref_resp = Input(Bool())

        val replay      = Decoupled(new DCacheReq)    // 正常指令重新发到流水线

        val resp        = Decoupled(new DCacheResp) // 给 mmio 用的
    })
    io <> DontCare

    val s_idle :: s_wb :: s_wb_wait :: s_refill :: s_refill_wait :: s_drain :: Nil = Enum(6)
    val state = RegInit(s_idle)

    val req     = Reg(new MSHRReq)  // 存储申请（可是东西不是都存在 lb sdq 里了吗？）
    val req_idx = req.addr(untagBits - 1, lineOffBits)
    val req_tag = req.addr >> untagBits

    val rpq = Module(new BranchKillableQueue(
        new DCacheReq, nRPQ, u => u.use_ldq, false
    ))
    rpq.io.brupdate := io.brupdate
    rpq.io.flush  := io.exception
    assert(!(state === s_invalid && !rpq.io.empty))

    val sec_rdy = !rpq.io.full

    // 将每次的请求压入rpq中（暂时不打算考虑prefetch）
    rpq.io.enq.valid := ((io.req_pri_val && io.req_pri_rdy) || (io.req_sec_val && io.req_sec_rdy))
    rpq.io.enq.bits  := io.req
    rpq.io.deq.ready := false.B

    val grantack = Reg(Valid(new TLBundleE(edge.bundle)))
    val refill_ctr  = Reg(UInt(log2Ceil(cacheDataBeats).W))
    val commit_line = Reg(Bool())
    val grant_had_data = Reg(Bool())
    val finish_to_prefetch = Reg(Bool())

    io.idx.valid := state =/= s_idle
    io.tag.valid := state =/= s_idle
    io.way.valid := state =/= s_idle
    io.idx.bits  := req_idx
    io.tag.bits  := req_tag
    io.way.bits  := req.wayMux

    io.req_pri_rdy   := false.B
    io.req_sec_rdy   := sec_rdy && rpq.io.enq.ready    
    io.wb_req.valid  := false.B
    io.ref_req.valid := false.B
    io.replay.valid  := false.B
    io.resp.valid    := false.B

    def handle_pri_req: UInt = { // 返回新的state
        refill_ctr := 0.U
        req := io.req
        val need_wb  = io.req.old_meta.valid && io.req.old_meta.dirty
        val new_state = Mux(need_wb, s_wb, s_refill)
        new_state
    }

    when (state === s_idle) {
        io.req_pri_rdy := true.B
        when (io.req_pri_val && io.req_pri_rdy) {
            state := handle_pri_req
        }
    } .elsewhen (state === s_wb) {
        io.wb_req.valid := true.B
        io.wb_req.bits.tag    := req.old_meta.tag  // 写回老的 meta 行
        io.wb_req.bits.idx    := req_idx
        io.wb_req.bits.wayMux := req.wayMux
        when (io.wb_req.fire) {
            state := s_wb_wait
        }
    } .elsewhen (state === s_wb_wait) {
        when (io.wb_resp) {
            state := s_refill
        }
    } .elsewhen (state === s_refill) {
        io.ref_req.valid := true.B
        io.ref_req.bits.tag := req_tag
        io.ref_req.bits.idx := req_idx
        io.ref_req.bits.wayMux := req.wayMux
        when (io.ref_req.fire) {
            state := s_refill_wait
        }
    } .elsewhen (state === s_refill_wait) {
        when (io.ref_resp) {
            state := s_drain
        }
    } .elsewhen (state === s_drain_rpq) {
        io.replay := DontCare
        io.replay.valid      := rpq.io.deq.valid
        io.replay.bits.uop   := rpq.io.deq.bits.uop
        io.replay.bits.addr  := rpq.io.deq.bits.addr
        io.replay.bits.data  := rpq.io.deq.bits.data
        io.replay.bits.wmask := rpq.io.deq.bits.wmask
        when (io.replay.fire) {
            rpq.io.deq.ready := true.B
        }
        when (rpq.io.empty && !rpq.io.enq.valid) {
            state := s_idle
        } .elsewhen (rpq.io.empty && rpq.io.enq.valid) {
            state := s_drain_rpq
        }
    }
}