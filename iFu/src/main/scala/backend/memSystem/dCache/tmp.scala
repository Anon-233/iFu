class BoomMSHR extends CoreModule {
    val io = IO(new Bundle {
        val req_pri_val = Input(Bool())     // 首个（怎么知道是首个的？）请求有效
        val req_pri_rdy = Output(Bool())    // 能否接受该block的首个miss
        val req_sec_val = Input(Bool())
        val req_sec_rdy = Output(Bool())    // 能否接受该block的次级miss

        val clear_prefetch = Input(Bool())
        val brupdate       = Input(new BrUpdateInfo)
        val exception    = Input(Bool())

        val req          = Input(new DCacheReqInternal)
        val req_is_probe = Input(Bool())

        val idx = Output(Valid(UInt()))
        val way = Output(Valid(UInt()))
        val tag = Output(Valid(UInt()))

        val mem_acquire = Decoupled(new TLBundleA(edge.bundle))

        val mem_grant   = Flipped(Decoupled(new TLBundleD(edge.bundle)))
        val mem_finish  = Decoupled(new TLBundleE(edge.bundle))

        val prober_state = Input(Valid(UInt(coreMaxAddrBits.W)))

        val refill      = Decoupled(new L1DataWriteReq)

        val meta_write  = Decoupled(new L1MetaWriteReq)
        val meta_read   = Decoupled(new L1MetaReadReq)
        val meta_resp   = Input(Valid(new L1Metadata))
        val wb_req      = Decoupled(new WritebackReq(edge.bundle))

        // To inform the prefetcher when we are commiting the fetch of this line
        val commit_val  = Output(Bool())
        val commit_addr = Output(UInt(coreMaxAddrBits.W))
        val commit_coh  = Output(new ClientMetadata)

        // Reading from the line buffer
        val lb_read  = Decoupled(new LineBufferReadReq)
        val lb_resp  = Input(UInt(encRowBits.W))
        val lb_write = Decoupled(new LineBufferWriteReq)

        // Replays go through the cache pipeline again
        val replay      = Decoupled(new DCacheReqInternal)
        // Resp go straight out to the core
        val resp        = Decoupled(new DCacheResp)

        // Writeback unit tells us when it is done processing our wb
        val wb_resp     = Input(Bool())

        val probe_rdy   = Output(Bool())
    })

    // TODO: Optimize this. We don't want to mess with cache during speculation
    // s_refill_req      : Make a request for a new cache line
    // s_refill_resp     : Store the refill response into our buffer
    // s_drain_rpq_loads : Drain out loads from the rpq
    //                   : If miss was misspeculated, go to s_invalid
    // s_wb_req          : Write back the evicted cache line
    // s_wb_resp         : Finish writing back the evicted cache line
    // s_meta_write_req  : Write the metadata for new cache lne
    // s_meta_write_resp :

    val s_invalid :: s_refill_req :: s_refill_resp :: s_drain_rpq_loads :: s_meta_read :: s_meta_resp_1 :: s_meta_resp_2 :: s_meta_clear :: s_wb_meta_read :: s_wb_req :: s_wb_resp :: s_commit_line :: s_drain_rpq :: s_meta_write_req :: s_mem_finish_1 :: s_mem_finish_2 :: s_prefetched :: s_prefetch :: Nil = Enum(18)
    val state = RegInit(s_invalid)

    val req     = Reg(new DCacheReqInternal)
    val req_idx = req.addr(untagBits-1, blockOffBits)
    val req_tag = req.addr >> untagBits
    val req_block_addr = (req.addr >> blockOffBits) << blockOffBits
    val req_needs_wb = RegInit(false.B)

  val new_coh = RegInit(ClientMetadata.onReset)
  val (_, shrink_param, coh_on_clear) = req.old_meta.coh.onCacheControl(M_FLUSH)
  val grow_param = new_coh.onAccess(req.uop.mem_cmd)._2
  val coh_on_grant = new_coh.onGrant(req.uop.mem_cmd, io.mem_grant.bits.param)

  // We only accept secondary misses if the original request had sufficient permissions
  val (cmd_requires_second_acquire, is_hit_again, _, dirtier_coh, dirtier_cmd) =
    new_coh.onSecondaryAccess(req.uop.mem_cmd, io.req.uop.mem_cmd)

  val (_, _, refill_done, refill_address_inc) = edge.addr_inc(io.mem_grant)
  val sec_rdy = (!cmd_requires_second_acquire && !io.req_is_probe &&
                 !state.isOneOf(s_invalid, s_meta_write_req, s_mem_finish_1, s_mem_finish_2))// Always accept secondary misses

  val rpq = Module(new BranchKillableQueue(new DCacheReqInternal, nRPQ, u => u.uses_ldq, false))    // 使用ldq会被杀掉？？？
  rpq.io.brupdate := io.brupdate
  rpq.io.flush  := io.exception
  assert(!(state === s_invalid && !rpq.io.empty))

  rpq.io.enq.valid := ((io.req_pri_val && io.req_pri_rdy) || (io.req_sec_val && io.req_sec_rdy)) && !isPrefetch(io.req.uop.mem_cmd)
  rpq.io.enq.bits  := io.req
  rpq.io.deq.ready := false.B

  val grantack = Reg(Valid(new TLBundleE(edge.bundle)))
  val refill_ctr  = Reg(UInt(log2Ceil(cacheDataBeats).W))
  val commit_line = Reg(Bool())
  val grant_had_data = Reg(Bool())
  val finish_to_prefetch = Reg(Bool())

  // Block probes if a tag write we started is still in the pipeline
  val meta_hazard = RegInit(0.U(2.W))
  when (meta_hazard =/= 0.U) { meta_hazard := meta_hazard + 1.U }
  when (io.meta_write.fire) { meta_hazard := 1.U }
  io.probe_rdy   := (meta_hazard === 0.U && (state.isOneOf(s_invalid, s_refill_req, s_refill_resp, s_drain_rpq_loads) || (state === s_meta_read && grantack.valid)))
  io.idx.valid := state =/= s_invalid
  io.tag.valid := state =/= s_invalid
  io.way.valid := !state.isOneOf(s_invalid, s_prefetch)
  io.idx.bits := req_idx
  io.tag.bits := req_tag
  io.way.bits := req.way_en

  io.meta_write.valid    := false.B
  io.req_pri_rdy         := false.B
  io.req_sec_rdy         := sec_rdy && rpq.io.enq.ready
  io.mem_acquire.valid   := false.B
  io.refill.valid        := false.B
  io.replay.valid        := false.B
  io.wb_req.valid        := false.B
  io.resp.valid          := false.B
  io.commit_val          := false.B
  io.commit_addr         := req.addr
  io.commit_coh          := coh_on_grant    // 一致性相关
  io.meta_read.valid     := false.B
  io.mem_finish.valid    := false.B
  io.lb_write.valid      := false.B
  io.lb_read.valid       := false.B

  when (io.req_sec_val && io.req_sec_rdy) {
    req.uop.mem_cmd := dirtier_cmd
    when (is_hit_again) {
      new_coh := dirtier_coh
    }
  }

    // 处理首个miss state有两个来源：s_invalid和s_prefetch
    def handle_pri_req: UInt = { // 返回新的state
        refill_ctr := 0.U
        req := io.req
        val need_wb  = /*TODO*/
        val new_state = Mux(need_wb, s_wb, s_refill)
        new_state
    }

    when (state === s_invalid) {
        io.req_pri_rdy := true.B

        when (io.req_pri_val && io.req_pri_rdy) {
            state := handle_pri_req
        }
    } .elsewhen (state === s_refill_req) {
        io./* TODO */ := true.B
        when (io./* TODO */) {    // 传递完毕
            state := /*TODO*/
        }
    } .elsewhen (state === s_refill_resp) {
        when (edge.hasData(io.mem_grant.bits)) {
            io.mem_grant.ready      := io.lb_write.ready
            io.lb_write.valid       := io.mem_grant.valid
            io.lb_write.bits.id     := io.id
            io.lb_write.bits.offset := refill_address_inc >> rowOffBits
            io.lb_write.bits.data   := io.mem_grant.bits.data
        } .otherwise {
            io.mem_grant.ready      := true.B
        }
        when (io.mem_grant.fire) {
            grant_had_data := edge.hasData(io.mem_grant.bits)
        }
        when (refill_done) {
            grantack.valid := edge.isRequest(io.mem_grant.bits)
            grantack.bits := edge.GrantAck(io.mem_grant.bits)
            state := Mux(grant_had_data, s_drain_rpq_loads, s_drain_rpq)
            assert(!(!grant_had_data && req_needs_wb))
            commit_line := false.B
            new_coh := coh_on_grant
        }
  } .elsewhen (state === s_drain_rpq_loads) {
    val drain_load = (isRead(rpq.io.deq.bits.uop.mem_cmd) &&
                     !isWrite(rpq.io.deq.bits.uop.mem_cmd) &&
                     (rpq.io.deq.bits.uop.mem_cmd =/= M_XLR)) // LR should go through replay
    // drain all loads for now
    val rp_addr = Cat(req_tag, req_idx, rpq.io.deq.bits.addr(blockOffBits-1,0))
    val word_idx  = if (rowWords == 1) 0.U else rp_addr(log2Up(rowWords*coreDataBytes)-1, log2Up(wordBytes))
    val data      = io.lb_resp
    val data_word = data >> Cat(word_idx, 0.U(log2Up(coreDataBits).W))
    val loadgen = new LoadGen(rpq.io.deq.bits.uop.mem_size, rpq.io.deq.bits.uop.mem_signed,
      Cat(req_tag, req_idx, rpq.io.deq.bits.addr(blockOffBits-1,0)),
      data_word, false.B, wordBytes)


    rpq.io.deq.ready       := io.resp.ready && io.lb_read.ready && drain_load
    io.lb_read.valid       := rpq.io.deq.valid && drain_load
    io.lb_read.bits.id     := io.id
    io.lb_read.bits.offset := rpq.io.deq.bits.addr >> rowOffBits

    io.resp.valid     := rpq.io.deq.valid && io.lb_read.fire && drain_load
    io.resp.bits.uop  := rpq.io.deq.bits.uop
    io.resp.bits.data := loadgen.data
    io.resp.bits.is_hella := rpq.io.deq.bits.is_hella
    when (rpq.io.deq.fire) {
      commit_line   := true.B
    }
      .elsewhen (rpq.io.empty && !commit_line)
    {
      when (!rpq.io.enq.fire) {
        state := s_mem_finish_1
        finish_to_prefetch := enablePrefetching.B
      }
    } .elsewhen (rpq.io.empty || (rpq.io.deq.valid && !drain_load)) {
      // io.commit_val is for the prefetcher. it tells the prefetcher that this line was correctly acquired
      // The prefetcher should consider fetching the next line
      io.commit_val := true.B
      state := s_meta_read
    }
  } .elsewhen (state === s_meta_read) {
    io.meta_read.valid := !io.prober_state.valid || !grantack.valid || (io.prober_state.bits(untagBits-1,blockOffBits) =/= req_idx)
    io.meta_read.bits.idx := req_idx
    io.meta_read.bits.tag := req_tag
    io.meta_read.bits.way_en := req.way_en
    when (io.meta_read.fire) {
      state := s_meta_resp_1
    }
  } .elsewhen (state === s_meta_resp_1) {
    state := s_meta_resp_2
  } .elsewhen (state === s_meta_resp_2) {
    val needs_wb = io.meta_resp.bits.coh.onCacheControl(M_FLUSH)._1
    state := Mux(!io.meta_resp.valid, s_meta_read, // Prober could have nack'd this read
             Mux(needs_wb, s_meta_clear, s_commit_line))
  } .elsewhen (state === s_meta_clear) {
    io.meta_write.valid         := true.B
    io.meta_write.bits.idx      := req_idx
    io.meta_write.bits.data.coh := coh_on_clear
    io.meta_write.bits.data.tag := req_tag
    io.meta_write.bits.way_en   := req.way_en

    when (io.meta_write.fire) {
      state      := s_wb_req
    }
  } .elsewhen (state === s_wb_req) {
    io.wb_req.valid          := true.B

    io.wb_req.bits.tag       := req.old_meta.tag
    io.wb_req.bits.idx       := req_idx
    io.wb_req.bits.param     := shrink_param
    io.wb_req.bits.way_en    := req.way_en
    io.wb_req.bits.source    := io.id
    io.wb_req.bits.voluntary := true.B
    when (io.wb_req.fire) {
      state := s_wb_resp
    }
  } .elsewhen (state === s_wb_resp) {
    when (io.wb_resp) {
      state := s_commit_line
    }
  } .elsewhen (state === s_commit_line) {
    io.lb_read.valid       := true.B
    io.lb_read.bits.id     := io.id
    io.lb_read.bits.offset := refill_ctr

    io.refill.valid       := io.lb_read.fire
    io.refill.bits.addr   := req_block_addr | (refill_ctr << rowOffBits)
    io.refill.bits.way_en := req.way_en
    io.refill.bits.wmask  := ~(0.U(rowWords.W))
    io.refill.bits.data   := io.lb_resp
    when (io.refill.fire) {
      refill_ctr := refill_ctr + 1.U
      when (refill_ctr === (cacheDataBeats - 1).U) {
        state := s_drain_rpq
      }
    }
  } .elsewhen (state === s_drain_rpq) {
    io.replay <> rpq.io.deq
    io.replay.bits.way_en    := req.way_en
    io.replay.bits.addr := Cat(req_tag, req_idx, rpq.io.deq.bits.addr(blockOffBits-1,0))
    when (io.replay.fire && isWrite(rpq.io.deq.bits.uop.mem_cmd)) {
      // Set dirty bit
      val (is_hit, _, coh_on_hit) = new_coh.onAccess(rpq.io.deq.bits.uop.mem_cmd)
      assert(is_hit, "We still don't have permissions for this store")
      new_coh := coh_on_hit
    }
    when (rpq.io.empty && !rpq.io.enq.valid) {
      state := s_meta_write_req
    }
  } .elsewhen (state === s_meta_write_req) {
    io.meta_write.valid         := true.B
    io.meta_write.bits.idx      := req_idx
    io.meta_write.bits.data.coh := new_coh
    io.meta_write.bits.data.tag := req_tag
    io.meta_write.bits.way_en   := req.way_en
    when (io.meta_write.fire) {
      state := s_mem_finish_1
      finish_to_prefetch := false.B
    }
  } .elsewhen (state === s_mem_finish_1) {
    io.mem_finish.valid := grantack.valid
    io.mem_finish.bits  := grantack.bits
    when (io.mem_finish.fire || !grantack.valid) {
      grantack.valid := false.B
      state := s_mem_finish_2
    }
  } .elsewhen (state === s_mem_finish_2) {
    state := Mux(finish_to_prefetch, s_prefetch, s_invalid)
  } .elsewhen (state === s_prefetch) {
    io.req_pri_rdy := true.B
    when ((io.req_sec_val && !io.req_sec_rdy) || io.clear_prefetch) {
      state := s_invalid
    } .elsewhen (io.req_sec_val && io.req_sec_rdy) {
      val (is_hit, _, coh_on_hit) = new_coh.onAccess(io.req.uop.mem_cmd)
      when (is_hit) { // Proceed with refill
        new_coh := coh_on_hit
        state := s_meta_read
      } .otherwise { // Reacquire this line
        new_coh := ClientMetadata.onReset
        state := s_refill_req
      }
    } .elsewhen (io.req_pri_val && io.req_pri_rdy) {
      grant_had_data := false.B
      state := handle_pri_req(state)
    }
  }
}