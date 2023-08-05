package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._

class DCacheReqInternal extends DCacheReq {
  // miss info
  val tag_match = Bool()
  val old_meta  = new L1Metadata
  val way_en    = UInt(nWays.W)
  // Used in the MSHRs
  val sdq_id    = UInt(log2Ceil(nSDQ).W)
}

class IOMSHR(id: Int) extends CoreModule {
    val io = IO(new Bundle {
        val req  = Flipped(Decoupled(new DCacheReq))
        val resp = Decoupled(new DCacheResp)
    })

    def beatOffset(addr: UInt) = addr(beatOffBits - 1, wordOffBits)

    def wordFromBeat(addr: UInt, dat: UInt) = {
        val shift = Cat(beatOffset(addr), 0.U((wordOffBits+log2Ceil(wordBytes)).W))
        (dat >> shift)(wordBits-1, 0)
    }

    val req = Reg(new BoomDCacheReq)
    val grant_word = Reg(UInt(wordBits.W))    // 下一级存储器响应req

    val s_idle :: /*一个新的中间状态*/ :: s_resp :: Nil = Enum(4)

    val state = RegInit(s_idle)
    io.req.ready := state === s_idle

    val send_resp = isRead(req.uop.mem_cmd)
    val loadgen = new LoadGen(
        req.uop.mem_size, req.uop.mem_signed, req.addr, grant_word, false.B, wordBytes
    )

    io.resp.valid     := (state === s_resp) && send_resp
    io.resp.bits.uop  := req.uop
    io.resp.bits.data := loadgen.data

    when (io.req.fire) {
        req   := io.req.bits
        state := s_mem_access
    }
    // 什么时候进入resp呢
    when (state === s_resp) {
        when (!send_resp || io.resp.fire) {
            state := s_idle
        }
    }
}

class LineBufferReadReq extends CoreBundle {
    val id      = UInt(log2Ceil(nLBEntries).W)
    val offset  = UInt(log2Ceil(cacheDataBeats).W)
    def lb_addr = Cat(id, offset) // id是什么，lb又是什么
}

class LineBufferWriteReq extends LineBufferReadReq {
    val data   = UInt(encRowBits.W)   // 要写入的data
    // line buffer是干什么的，要向里面写入什么东西？？？
}

class LineBufferMetaWriteReq extends CoreBundle {
    val id   = UInt(log2Ceil(nLBEntries).W)     // line buffer也有一个可配置的项数？
    val coh  = new ClientMetadata // 又是用于维护一致性的东西，但是还有一些valid的信息
    val addr = UInt(coreMaxAddrBits.W)
}

class LineBufferMeta extends CoreBundle {
  val coh  = new ClientMetadata // meta 信息
  val addr = UInt(coreMaxAddrBits.W)    // 什么的地址呢？
}

class MSHRFile extends CoreModule {
  val io = IO(new Bundle {
        val req  = Flipped(Vec(memWidth, Decoupled(new DCacheReqInternal)))
        val resp = Decoupled(new DCacheResp)
        val secondary_miss = Output(Vec(memWidth, Bool()))
        val block_hit = Output(Vec(memWidth, Bool()))

        val brupdate     = Input(new BrUpdateInfo)
        val exception    = Input(Bool())

        val refill     = Decoupled(new L1DataWriteReq)
        val meta_write = Decoupled(new L1MetaWriteReq)
        val meta_read  = Decoupled(new L1MetaReadReq)
        val meta_resp  = Input(Valid(new L1Metadata))
        val replay     = Decoupled(new DCacheReqInternal)
        val prefetch   = Decoupled(new DCacheReq)
        val wb_req     = Decoupled(new WritebackReq)

        val clear_all = Input(Bool()) // Clears all uncommitted MSHRs to prepare for fence

        val wb_resp   = Input(Bool())

        val fence_rdy = Output(Bool())
    })

    // 为什么这里一定是one hot的？
    // ans: 00 -> 0, 01 -> 0, 10 -> 1, 11 -> 1
    // 也就是说，优先处理第一条流水线的请求
    val req_idx = OHToUInt(io.req.map(_.valid))   // 同时有两个请求发过来
    val req     = io.req(req_idx)

    for (w <- 0 until memWidth)
        io.req(w).ready := false.B

    val prefetcher: DataPrefetcher = if (enablePrefetching) {
        Module(new NLPrefetcher)
    } else {
        Module(new NullPrefetcher)
    }

    io.prefetch <> prefetcher.io.prefetch   // 也就是说prefetcher是属于mshr的

    // 感觉应该是说能不能cache
    // 所以我们应该修改成
    val cacheable = AddrCacheable(req.bits.addr)
    // val cacheable = edge.manager.supportsAcquireBFast(req.bits.addr, lgCacheBlockBytes.U)

    // --------------------
    // The MSHR SDQ
    // 如何保证顺序写？
    val sdq_val      = RegInit(0.U(nSDQ.W))
    // 见缝插针如何保证写请求的顺序？？？
    val sdq_alloc_id = PriorityEncoder(~sdq_val(nSDQ - 1,0))
    val sdq_rdy      = !sdq_val.andR    // 有空间就可以写入
    // 可以入队的store请求一定是cacheable的
    val sdq_enq      = req.fire && cacheable && isWrite(req.bits.uop.mem_cmd)
    // sdq 里存的是meta吧
    val sdq          = Mem(nSDQ, UInt(coreDataBits.W)) // 异步读，同步写

    when (sdq_enq) {
        sdq(sdq_alloc_id) := req.bits.data
    }

    // --------------------
    // The LineBuffer Data
    // Holds refilling lines, prefetched lines
    // cachedataBeats 是什么？？？
    val lb = Mem(nLBEntries * cacheDataBeats, UInt(encRowBits.W))
    // 所有mshr竞争lb的读写
    val lb_read_arb  = Module(new Arbiter(new LineBufferReadReq,  nMSHRs))
    val lb_write_arb = Module(new Arbiter(new LineBufferWriteReq, nMSHRs))

    lb_read_arb.io.out.ready  := false.B    // 为什么可以写入但不让读
    lb_write_arb.io.out.ready := true.B

    val lb_read_data = WireInit(0.U(encRowBits.W))
    when (lb_write_arb.io.out.fire) {   // 响应了一个写请求
        lb.write(lb_write_arb.io.out.bits.lb_addr, lb_write_arb.io.out.bits.data)
    } .otherwise {  // 所以说，没有被写的时候，才可以读
        lb_read_arb.io.out.ready := true.B
        when (lb_read_arb.io.out.fire) {
            lb_read_data := lb.read(lb_read_arb.io.out.bits.lb_addr)
        }
    }
    def widthMap[T <: Data](f: Int => T) = VecInit((0 until memWidth).map(f))

    // 两条流水线是否匹配到了已有的mshr（不太确定）
    val idx_matches = Wire(Vec(memWidth, Vec(nMSHRs, Bool())))
    val tag_matches = Wire(Vec(memWidth, Vec(nMSHRs, Bool())))
    val way_matches = Wire(Vec(memWidth, Vec(nMSHRs, Bool())))

    val tag_match = widthMap(w => Mux1H(idx_matches(w), tag_matches(w))) // 依旧是one hot的
    val idx_match = widthMap(w => idx_matches(w).reduce(_||_))    // 有没有
    val way_match = widthMap(w => Mux1H(idx_matches(w), way_matches(w))) // one hot，是不是撞路了
    // 看不太懂
    val wb_tag_list = Wire(Vec(nMSHRs, UInt(tagBits.W)))
    // 全是arbiter...
    val meta_write_arb = Module(new Arbiter(new L1MetaWriteReq           , nMSHRs))
    val meta_read_arb  = Module(new Arbiter(new L1MetaReadReq            , nMSHRs))
    val wb_req_arb     = Module(new Arbiter(new WritebackReq(edge.bundle), nMSHRs))
    val replay_arb     = Module(new Arbiter(new DCacheReqInternal        , nMSHRs))
    val resp_arb       = Module(new Arbiter(new DCacheResp               , nMSHRs + nIOMSHRs))
    val refill_arb     = Module(new Arbiter(new L1DataWriteReq           , nMSHRs))

    val commit_vals    = Wire(Vec(nMSHRs, Bool()))
    val commit_addrs   = Wire(Vec(nMSHRs, UInt(paddrBits.W)))
    val commit_cohs    = Wire(Vec(nMSHRs, new ClientMetadata)) // 修改

    var sec_rdy   = false.B

    io.fence_rdy := true.B

    val mshr_alloc_idx = Wire(UInt())  // 是来分配一个mshr吗
    val pri_rdy = WireInit(false.B)
    // 请求有效、sdq有空间、cacheable、没有撞路
    val pri_val = req.valid && sdq_rdy && cacheable && !idx_match(req_idx)
    // 接下来实例化mshr
    val mshrs = (0 until nMSHRs) map { i =>
        val mshr = Module(new MSHR(i)) // 改成构造时给定id
        // mshr.io.id := i.U(log2Ceil(cfg.nMSHRs).W)   // 这好像是固定分配的id

        for (w <- 0 until memWidth) {
            // 开始匹配！
            idx_matches(w)(i) := mshr.io.idx.valid && mshr.io.idx.bits === io.req(w).bits.addr(untagBits - 1,blockOffBits)
            tag_matches(w)(i) := mshr.io.tag.valid && mshr.io.tag.bits === io.req(w).bits.addr >> untagBits
            way_matches(w)(i) := mshr.io.way.valid && mshr.io.way.bits === io.req(w).bits.wayMux
        }
        wb_tag_list(i) := mshr.io.wb_req.bits.tag   // 请求写回的tag

        when (i.U === mshr_alloc_idx) {
            pri_rdy := mshr.io.req_pri_rdy  // 对应位给ready信号
        }
        // 是不是被分配了一个 priority 的mshr
        mshr.io.req_pri_val := (i.U === mshr_alloc_idx) && pri_val
        // 有匹配的话就分配到 secondary 的mshr（或者说是给一个 secondary 的请求）
        mshr.io.req_sec_val  := req.valid && sdq_rdy && tag_match(req_idx) && idx_matches(req_idx)(i) && cacheable

        mshr.io.req          := req.bits
        mshr.io.req.sdq_id   := sdq_alloc_id

        // Clear because of a FENCE, a request to the same idx as a prefetched line,
        // all mshrs are in use
        // 这段注释看不太懂
        mshr.io.clear_prefetch := (
            (io.clear_all && !req.valid) ||
            (req.valid && idx_matches(req_idx)(i) && cacheable && !tag_match(req_idx))
        )

        mshr.io.brupdate  := io.brupdate
        mshr.io.exception := io.exception

        mshr.io.wb_resp := io.wb_resp

        // 接入到arbiter
        meta_write_arb.io.in(i) <> mshr.io.meta_write
        meta_read_arb.io.in(i)  <> mshr.io.meta_read
        wb_req_arb.io.in(i)     <> mshr.io.wb_req
        replay_arb.io.in(i)     <> mshr.io.replay
        refill_arb.io.in(i)     <> mshr.io.refill
        lb_read_arb.io.in(i)    <> mshr.io.lb_read
        lb_write_arb.io.in(i)   <> mshr.io.lb_write
        resp_arb.io.in(i)       <> mshr.io.resp

        mshr.io.lb_resp   := lb_read_data
        mshr.io.meta_resp := io.meta_resp

        // 什么叫做commit？
        commit_vals(i)  := mshr.io.commit_val
        commit_addrs(i) := mshr.io.commit_addr
        commit_cohs(i)  := mshr.io.commit_coh

        // 是不是已经有人接了这个请求（而且作为是 secondary 请求被接受）
        sec_rdy = sec_rdy || (mshr.io.req_sec_rdy && mshr.io.req_sec_val)

        // 有一个不是 pri_rdy 的话，就说明还有没做完的东西，就不能fence
        when (!mshr.io.req_pri_rdy) {
            io.fence_rdy := false.B
        }

        mshr
    }

    // Try to round-robin the MSHRs
    val mshr_head = RegInit(0.U(log2Ceil(nMSHRs).W))
    mshr_alloc_idx := RegNext(  // 选出 head 之后的第一个 pri_rdy 的 mshr
        AgePriorityEncoder(mshrs.map(m=>m.io.req_pri_rdy), mshr_head)
    )
    when (pri_rdy && pri_val) { mshr_head := WrapInc(mshr_head, nMSHRs) }

    io.meta_write <> meta_write_arb.io.out
    io.meta_read  <> meta_read_arb.io.out
    io.wb_req     <> wb_req_arb.io.out

    val mmio_alloc_arb = Module(new Arbiter(Bool(), nIOMSHRs))

    var mmio_rdy = false.B

    val mmios = (0 until nIOMSHRs) map { i =>
        val id = nMSHRs + i
        val mshr = Module(new IOMSHR(id))

        mmio_alloc_arb.io.in(i).valid := mshr.io.req.ready
        mmio_alloc_arb.io.in(i).bits  := DontCare
        mshr.io.req.valid := mmio_alloc_arb.io.in(i).ready
        mshr.io.req.bits  := req.bits

        mmio_rdy = mmio_rdy || mshr.io.req.ready

        resp_arb.io.in(nMSHRs + i) <> mshr.io.resp

        when (!mshr.io.req.ready) {
            io.fence_rdy := false.B
        }

        mshr
    }

    mmio_alloc_arb.io.out.ready := req.valid && !cacheable

    val respq = Module(new BranchKillableQueue(new BoomDCacheResp, 4, u => u.uses_ldq, flow = false))
    respq.io.brupdate := io.brupdate
    respq.io.flush    := io.exception
    respq.io.enq      <> resp_arb.io.out
    io.resp           <> respq.io.deq

    for (w <- 0 until memWidth) {   // 遍历两条流水线
        io.req(w).ready := (w.U === req_idx) &&     // 所以只有一条的请求会被接受
            Mux(!cacheable, mmio_rdy, sdq_rdy && Mux(idx_match(w), tag_match(w) && sec_rdy, pri_rdy))
        // 相同的位置却是不同的地址块，所有叫做 secondary miss
        io.secondary_miss(w) := idx_match(w) && way_match(w) && !tag_match(w)
        io.block_hit(w)      := idx_match(w) && tag_match(w)
    }
    io.refill <> refill_arb.io.out  // 写回（数据还是meta呢）

    // 如果成功重发了一个store，释放对应的sdq
    val free_sdq = io.replay.fire && isWrite(io.replay.bits.uop.mem_cmd)

    io.replay <> replay_arb.io.out
    io.replay.bits.data := sdq(replay_arb.io.out.bits.sdq_id)

    when (io.replay.valid || sdq_enq) {
        sdq_val :=  sdq_val &   // 保持原来的作为默认
            ~(UIntToOH(replay_arb.io.out.bits.sdq_id) & Fill(cfg.nSDQ, free_sdq)) |
            (PriorityEncoderOH(~sdq_val(nSDQ - 1, 0)) & Fill(nSDQ, sdq_enq))
    }

    // 时序？？？为什么要reg next
    prefetcher.io.mshr_avail := RegNext(pri_rdy)
    prefetcher.io.req_val    := RegNext(commit_vals.reduce(_||_))
    prefetcher.io.req_addr   := RegNext(Mux1H(commit_vals, commit_addrs))
    prefetcher.io.req_coh    := RegNext(Mux1H(commit_vals, commit_cohs))
}
