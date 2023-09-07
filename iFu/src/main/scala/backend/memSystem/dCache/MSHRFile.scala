package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._

class MSHRFile extends CoreModule {
    def widthMap[T <: Data](f: Int => T) = VecInit((0 until memWidth).map(f))

    val io = IO(new Bundle {
        val req  = Flipped(Vec(memWidth, Decoupled(new MSHRReq)))
        val resp = Decoupled(new DCacheResp)

        val secondary_miss = Output(Vec(memWidth, Bool()))

        val brupdate  = Input(new BrUpdateInfo)
        // val exception = Input(Bool())

        val wb_req  = Decoupled(new WritebackReq)
        val ref_req = Decoupled(new RefillReq)

        val wb_resp  = Input(Bool())
        val ref_resp = Input(Bool())

        val replay = Decoupled(new MSHRReq)

        val fence_rdy = Output(Bool())

        val cbusReq  = Output(new CBusReq)
        val cbusResp = Input(new CBusResp)
    })

    // ans: 00 -> 0, 01 -> 0, 10 -> 1, 11 -> 1
    // 也就是说，优先处理第一条流水线的请求
    val req_idx = OHToUInt(io.req.map(_.valid))   // 同时有两个请求发过来
    val req     = io.req(req_idx)

    for (w <- 0 until memWidth) {
        io.req(w).ready := false.B  // 默认不接受请求
    }

    val cacheable = !req.bits.uncacheable

    // 两条流水线是否匹配到了已有的mshr（不太确定）
    val idx_matches = Wire(Vec(memWidth, Vec(nMSHRs, Bool())))
    val tag_matches = Wire(Vec(memWidth, Vec(nMSHRs, Bool())))
    val way_matches = Wire(Vec(memWidth, Vec(nMSHRs, Bool())))

    val tag_match = widthMap(w => Mux1H(idx_matches(w), tag_matches(w))) // 依旧是one hot的
    val idx_match = widthMap(w => idx_matches(w).reduce(_||_))    // 有没有
    val way_match = widthMap(w => Mux1H(idx_matches(w), way_matches(w))) // one hot，是不是撞路了

    val wb_req_arb  = Module(new Arbiter(new WritebackReq, nMSHRs))
    val ref_req_arb = Module(new Arbiter(new L1DataWriteReq, nMSHRs))
    
    val replay_arb = Module(new Arbiter(new MSHRReq, nMSHRs))
    val resp_arb   = Module(new Arbiter(new DCacheResp, nIOMSHRs))

    io.fence_rdy := true.B

    val pri_rdy = WireInit(false.B)
    var sec_rdy = false.B

    val mshr_alloc_idx = Wire(UInt())  // 分配一个mshr

    // 请求有效、cacheable、没有撞路
    val pri_val = req.valid && cacheable && !idx_match(req_idx)
    // 接下来实例化mshr
    val mshrs = (0 until nMSHRs) map { i =>
        val mshr = Module(new MSHR)

        for (w <- 0 until memWidth) { // 开始匹配！
            idx_matches(w)(i) := mshr.io.idx.valid && mshr.io.idx.bits === io.req(w).bits.addr(untagBits - 1,blockOffBits)
            tag_matches(w)(i) := mshr.io.tag.valid && mshr.io.tag.bits === io.req(w).bits.addr >> untagBits
            way_matches(w)(i) := mshr.io.way.valid && mshr.io.way.bits === io.req(w).bits.wayMux
        }

        when (i.U === mshr_alloc_idx) {
            pri_rdy := mshr.io.req_pri_rdy  // 对应位给ready信号
        }
        // 是不是被分配了一个 priority 的mshr
        mshr.io.req_pri_val := (i.U === mshr_alloc_idx) && pri_val
        // 有匹配的话就分配到 secondary 的mshr（或者说是给一个 secondary 的请求）
        mshr.io.req_sec_val := req.valid && sdq_rdy && tag_match(req_idx) && idx_matches(req_idx)(i) && cacheable

        mshr.io.req       := req.bits
        mshr.io.brupdate  := io.brupdate
        // mshr.io.exception := io.exception
        mshr.io.wb_resp   := io.wb_resp
        mshr.io.ref_resp  := io.ref_resp

        // 接入到arbiter
        wb_req_arb.io.in(i)  <> mshr.io.wb_req
        ref_req_arb.io.in(i) <> mshr.io.ref_req
        replay_arb.io.in(i)  <> mshr.io.replay

        // 是不是已经有人接了这个请求（而且作为是 secondary 请求被接受）
        sec_rdy = sec_rdy || (mshr.io.req_sec_rdy && mshr.io.req_sec_val)

        // 有一个不是 pri_rdy 的话，就说明还有没做完的东西，就不能fence
        when (!mshr.io.req_pri_rdy) {
            io.fence_rdy := false.B
        }

        mshr
    }

    val mshr_head = RegInit(0.U(log2Ceil(nMSHRs).W))
    // 这个好像有 bug ... 每两个周期才能分配一个 mshr
    mshr_alloc_idx := RegNext(  // 选出 head 之后的第一个 pri_rdy 的 mshr
        AgePriorityEncoder(mshrs.map(m => m.io.req_pri_rdy), mshr_head)
    )
    when (pri_rdy && pri_val) {
        mshr_head := WrapInc(mshr_head, nMSHRs)
    }

    io.wb_req  <> wb_req_arb.io.out
    io.ref_req <> ref_req_arb.io.out
    io.replay  <> replay_arb.io.out

    val mmio_alloc_arb = Module(new Arbiter(Bool(), nIOMSHRs))
    mmio_alloc_arb.io.out.ready := req.valid && !cacheable

    var mmio_rdy = false.B

    val mmios = (0 until nIOMSHRs) map { i =>
        require(nIOMSHRs == 1)
        val mshr = Module(new IOMSHR)

        mmio_alloc_arb.io.in(i).valid := mshr.io.req.ready
        mmio_alloc_arb.io.in(i).bits  := DontCare

        mshr.io.req.valid := mmio_alloc_arb.io.in(i).ready
        mshr.io.req.bits  := req.bits

        mmio_rdy = mmio_rdy || mshr.io.req.ready

        resp_arb.io.in(i) <> mshr.io.resp

        when (!mshr.io.req.ready) {
            io.fence_rdy := false.B
        }

        mshr
    }
    io.cbusReq := mmios(0).io.cbusReq
    mmios(0).io.cbusResp := io.cbusResp

    val respq = Module(new BranchKillableQueue(new BoomDCacheResp, 4, u => u.uses_ldq, flow = false))
    respq.io.brupdate := io.brupdate
    // respq.io.flush    := io.exception
    respq.io.enq      <> resp_arb.io.out
    io.resp           <> respq.io.deq

    for (w <- 0 until memWidth) {   // 遍历两条流水线
        io.req(w).ready := (
            (w.U === req_idx) &&     // 所以只有一条的请求会被接受
            Mux(!cacheable, 
                mmio_rdy,
                Mux(idx_match(w), tag_match(w) && sec_rdy, pri_rdy)
            )
        )
        // 相同的位置却是不同的地址块，所有叫做 secondary miss
        io.secondary_miss(w) := idx_match(w) && way_match(w) && !tag_match(w)
    }
}
