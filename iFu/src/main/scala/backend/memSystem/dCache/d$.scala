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

        val meta_read = Decoupled(new MetaReadReq)    // 为什么要同时发请求呢
        
        val idx  = Output(Valid(UInt()))
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

    val data_req_cnt = RegInit(0.U(log2Up(refillCycles + 1).W))

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
        io.cbusReq.addr    := req.pc >> untagBits << untagBits
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

class MetaData extends CoreBundle {
    val valid = Bool()
    val dirty = Bool()
    val tag = UInt(tagBits.W)
    val age = UInt(dCacheAgeBits.W)
}

class MetaReadReq extends CoreBundle {
    val idx   = UInt(idxBits.W)
    val tag   = UInt(tagBits.W)
    val wayMux = UInt(nWays.W)
}

class MeatWriteReq extends MetaReadReq {
    val data = new MetaData
}

class DualMetaReadReq extends CoreBundle {
    val req    = Vec(memWidth, new MetaReadReq)
}

class MetaArray extends CoreModule {
    val io = IO(new Bundle {
        val read  = Vec(memWidth, Flipped(Decoupled(new MetaReadReq)))
        val write = Flipped(Decoupled(new MeatWriteReq))
        val resp  = Output(Vec(memWidth, Vec(nWays, new MetaData)))
    })

    val array = SyncReadMem(nSets, Vec(nWays, new MetaData))

    val rstEn = RegInit(true.B)
    val rstCnt = RegInit(0.U(log2Ceil(nSets).W))
    when (rstCnt === (nSets - 1).U) { rstEn := false.B }
    rstCnt := WrapInc(rstCnt, nSets)

    val wEn   = rstEn || io.write.fire
    val waddr = Mux(rstEn, rstCnt, io.write.bits.idx)
    val wdata = Mux(rstEn, 0.U.asTypeOf(new MetaData), io.write.bits.data)
    val wmask = Mux(rstEn, -1.S, io.write.bits.wayMux).asBools

    when (wEn) {
        array.write(waddr, VecInit.fill(nWays)(wdata), wmask)
    }
    for (i <- 0 until memWidth) {
        io.read(i).ready := !rstEn || !wEn
        io.resp(i) := array.read(io.read(i).bits.idx, io.read(i).valid)
    }

    io.write.ready := !rstEn
}

class DataReadReq extends CoreBundle {
    val wayMUx = UInt(nWays.W)
    val addr   = UInt(untagBits.W)
}

class DataWriteReq extends DataReadReq {
    val wmask  = Vec(rowWords, Bool())
    val data   = UInt(128.W)
}

class DualDataReadReq extends CoreBundle {
    val valid = Vec(memWidth, Bool())
    val req   = Vec(memWidth, new DataReadReq)
}

class DataArray extends CoreModule {
    val io = IO(new CoreBundle {
        val read  = Vec(memWidth, Flipped(Valid(new DataReadReq)))
        val write = Flipped(Valid(new DataWriteReq))
        val nacks = Output(Vec(memWidth, Bool()))
        val resp  = Output(Vec(memWidth, Vec(nWays, UInt(xLen.W))))
    })

    val waddr  = io.write.bits.addr >> 2 // 4 bytes per word
    val raddr1 = io.read(0).bits.addr >> 2
    val raddr2 = io.read(1).bits.addr >> 2

    for (w <- 0 until nWays) {
        val depth = nSets * rowWords
        val array = SyncReadMem(depth, Vec(4, UInt(8.W)))

        when (io.write.valid && io.write.bits.wayMux(w)) {
            array.write(waddr, io.write.data, io.write.bits.wmask)
        }
        io.resp(0)(w) := RegNext(
            array.read(raddr1, io.read(0).wayMux(w) && io.read(0).valid).asUInt
        )
        io.resp(1)(w) := RegNext(
            array.read(raddr2, io.read(1).wayMux(w) && io.read(1).valid).asUInt
        )
        io.nacks(0) := false.B
        io.nacks(1) := false.B
    }
}

class DCacheIO extends CoreBundle {
    val lsu      = Flipped(new LSUDMemIO)
    // val error    = new DCacheErrors
    val cbusReq  = Output(new CBusReq)
    val cbusResp = Input(new CBusResp)
}

class NonBlockingDCache extends CoreModules {
    val io = IO(new DCacheIO)

    def widthMap[T <: Data](f: Int => T) = VecInit((0 until memWidth).map(f))
    def wayMap[T <: Data](f: Int => T) = VecInit((0 until nWays).map(f))

    // 不太懂mshr的读请求是干嘛的
    val t_replay :: t_wb :: t_mshr_meta_read :: t_lsu :: t_prefetch :: Nil = Enum(5)

    val mshrs = Module(new MSHRFile)
    mshrs.io.clear_all    := io.lsu.force_order // 会杀掉load指令
    mshrs.io.brupdate     := io.lsu.brupdate
    // mshrs.io.exception    := io.lsu.exception   // 先不做
    mshrs.io.rob_head_idx := io.lsu.rob_head_idx

    val meta = Module(new MetaArray)
    val metaWriteArb = Module(new Arbiter(new MeatWriteReq, 1))   // 0 -> MSHR refills
    val metaReadArb = Module(new Arbiter(new DualMetaReadReq, 6))
    // 0 -> wb, 2 -> MSHR replays, 3 -> MSHR meta read, 4 -> pipeline, 5 -> prefetcher
    metaReadArb.io.in := DontCare

    for (i <- 0 until memWidth) {
        meta.io.write.valid    := metaWriteArb.io.out.fire
        meta.io.write.bits     := metaWriteArb.io.out.bits
        meta.io.read(i).valid  := metaReadArb.io.out.valid
        meta.io.read(i).bits   := metaReadArb.io.out.bits.req(i)
    }

    // 因为有的地方（实际上是大部分地方）只用到了第一个口，所以这里或一下
    metaReadArb.io.out.ready  := meta.map(_.io.read.ready).reduce(_||_)
    metaWriteArb.io.out.ready := meta.io.write.ready

    // data
    val data = Module(new DataArray)
    val dataWriteArb = Module(new Arbiter(new DataWriteReq, 2))
    // 0 goes to pipeline, 1 goes to MSHR refills
    val dataReadArb = Module(new Arbiter(new DualDataReadReq, 3))
    // 0 goes to wb, 1 goes to MSHR replays, 2 goes to pipeline
    dataReadArb.io.in := DontCare

    for (w <- 0 until memWidth) {
        data.io.read(w).valid := dataReadArb.io.out.bits.valid(w) && dataReadArb.io.out.valid
        data.io.read(w).bits  := dataReadArb.io.out.bits.req(w)
    }
    dataReadArb.io.out.ready := true.B

    data.io.write.valid       := dataWriteArb.io.out.fire
    data.io.write.bits        := dataWriteArb.io.out.bits
    dataWriteArb.io.out.ready := true.B

// -------------------------------------------------------------------------------
    // ------------
    // New requests <- 来自lsu

    // 当周期要能去读数据，才能是ready的，才能握手，s0_req才能变成lsu的req
    io.lsu.req.ready := metaReadArb.io.in(4).ready && dataReadArb.io.in(2).ready
    metaReadArb.io.in(4).valid := io.lsu.req.valid
    dataReadArb.io.in(2).valid := io.lsu.req.valid
    for (w <- 0 until memWidth) {
        // Tag read for new requests
        metaReadArb.io.in(4).bits.req(w).idx    := io.lsu.req.bits(w).bits.addr >> lineOffBits
        metaReadArb.io.in(4).bits.req(w).wayMux := DontCare
        metaReadArb.io.in(4).bits.req(w).tag    := DontCare // 读出来再判断是不是hit 或许是VIPT
        // Data read for new requests
        dataReadArb.io.in(2).bits.valid(w)      := io.lsu.req.bits(w).valid
        dataReadArb.io.in(2).bits.req(w).addr   := io.lsu.req.bits(w).bits.addr >> 2
        dataReadArb.io.in(2).bits.req(w).wayMux := ~0.U(nWays.W)    // 全读出来再比较
    }

    // ------------
    // MSHR Replays
    val replay_req = Wire(Vec(memWidth, new BoomDCacheReq))   // 重发，之前已经重填完了
    replay_req               := DontCare
    replay_req(0).uop        := mshrs.io.replay.bits.uop
    replay_req(0).addr       := mshrs.io.replay.bits.addr
    replay_req(0).data       := mshrs.io.replay.bits.data   // store也可以replay
    mshrs.io.replay.ready    := metaReadArb.io.in(0).ready && dataReadArb.io.in(0).ready    // 能不能申请到资源
    // 这里还是一个请求占两个端口
    // Tag read for MSHR replays
    // We don't actually need to read the metadata, for replays we already know our way
    metaReadArb.io.in(0).valid              := mshrs.io.replay.valid
    metaReadArb.io.in(0).bits.req(0).idx    := mshrs.io.replay.bits.addr >> lineOffBits
    metaReadArb.io.in(0).bits.req(0).wayMux := DontCare
    metaReadArb.io.in(0).bits.req(0).tag    := DontCare
    // Data read for MSHR replays
    dataReadArb.io.in(0).valid              := mshrs.io.replay.valid
    dataReadArb.io.in(0).bits.req(0).addr   := mshrs.io.replay.bits.addr
    dataReadArb.io.in(0).bits.req(0).wayMux := mshrs.io.replay.bits.wayMux
    dataReadArb.io.in(0).bits.valid         := widthMap(w => (w == 0).B)    // 只读第一个口

    // -----------
    // MSHR Meta read
    val mshr_read_req = Wire(Vec(memWidth, new BoomDCacheReq))
    mshr_read_req                    := DontCare
    mshr_read_req(0).uop             := NullMicroOp
    mshr_read_req(0).addr            := Cat(mshrs.io.meta_read.bits.tag, mshrs.io.meta_read.bits.idx) << lineOffBits
    mshr_read_req(0).data            := DontCare
    metaReadArb.io.in(3).valid       := mshrs.io.meta_read.valid
    metaReadArb.io.in(3).bits.req(0) := mshrs.io.meta_read.bits
    mshrs.io.meta_read.ready         := metaReadArb.io.in(3).ready

    // -----------
    // Write-backs
    val wb = Module(new WritebackUnit)
    val wb_fire = wb.io.meta_read.fire && wb.io.data_req.fire
    val wb_req = Wire(Vec(memWidth, new DCacheReq))
    wb_req             := DontCare
    wb_req(0).uop      := NullMicroOp
    wb_req(0).addr     := Cat(wb.io.meta_read.bits.tag, wb.io.data_req.bits.addr)
    wb_req(0).data     := DontCare
    // Couple the two decoupled interfaces of the WBUnit's meta_read and data_read
    // Tag read for write-back
    metaReadArb.io.in(2).valid        := wb.io.meta_read.valid
    metaReadArb.io.in(2).bits.req(0)  := wb.io.meta_read.bits
    // 只用一个端口，所以前面用了dont care
    wb.io.meta_read.ready := metaReadArb.io.in(2).ready && dataReadArb.io.in(1).ready
    // Data read for write-back
    dataReadArb.io.in(1).valid        := wb.io.data_req.valid
    dataReadArb.io.in(1).bits.req(0)  := wb.io.data_req.bits
    dataReadArb.io.in(1).bits.valid   := widthMap(w => (w == 0).B)
    wb.io.data_req.ready  := metaReadArb.io.in(2).ready && dataReadArb.io.in(1).ready
    assert(!(wb.io.meta_read.fire ^ wb.io.data_req.fire)) // 必须相同

    // -------
    // Prefetcher
    val prefetch_fire = mshrs.io.prefetch.fire
    val prefetch_req = Wire(Vec(memWidth, new DCacheReq))
    prefetch_req    := DontCare
    prefetch_req(0) := mshrs.io.prefetch.bits
    // Tag read for prefetch
    metaReadArb.io.in(5).valid              := mshrs.io.prefetch.valid
    metaReadArb.io.in(5).bits.req(0).idx    := mshrs.io.prefetch.bits.addr >> lineOffBits
    metaReadArb.io.in(5).bits.req(0).wayMux := DontCare
    metaReadArb.io.in(5).bits.req(0).tag    := DontCare
    mshrs.io.prefetch.ready := metaReadArb.io.in(5).ready
    // Prefetch does not need to read data array
// -------------------------------------------------------------------------------

    val s0_valid = Mux(io.lsu.req.fire,
                        VecInit(io.lsu.req.bits.map(_.valid)),
                   Mux(mshrs.io.replay.fire || wb_fire || prefetch_fire || mshrs.io.meta_read.fire,
                        VecInit(1.U(memWidth.W).asBools),
                        VecInit(0.U(memWidth.W).asBools)
                ))
    // TODO: 改成one hot的选取（应该是对的吧）
    val s0_req   = Mux(io.lsu.req.fire         , VecInit(io.lsu.req.bits.map(_.bits)),
                   Mux(wb_fire                 , wb_req,  // 为什么你的优先级比新请求低啊
                   Mux(prefetch_fire           , prefetch_req,
                   Mux(mshrs.io.meta_read.fire , mshr_read_req
                                               , replay_req))))
    val s0_type  = Mux(io.lsu.req.fire         , t_lsu,
                   Mux(wb_fire                 , t_wb,
                   Mux(prefetch_fire           , t_prefetch,
                   Mux(mshrs.io.meta_read.fire , t_mshr_meta_read
                                               , t_replay))))

    // Does this request need to send a response or nack
    val s0_send_resp_or_nack = Mux( // 更多的是表示能不能
        io.lsu.req.fire,
        s0_valid,
        VecInit(Mux(
            mshrs.io.replay.fire && isRead(mshrs.io.replay.bits.uop.mem_cmd),
            1.U(memWidth.W),    // 作为resp返回
            0.U(memWidth.W)
        ).asBools)
    )

    val s2_store_failed = Wire(Bool())  // 在什么情况下呢

    val s1_req = RegNext(s0_req)
    for (w <- 0 until memWidth) {   // 更新分支信息
        s1_req(w).uop.br_mask := GetNewBrMask(io.lsu.brupdate, s0_req(w).uop)
    }
    val s1_valid = widthMap(w => RegNext(
        s0_valid(w) &&
        !IsKilledByBranch(io.lsu.brupdate, s0_req(w).uop) &&
        // !(io.lsu.exception && s0_req(w).uop.uses_ldq)   &&   // 异常一定是rob来的，此时的load是非法的
        !(s2_store_failed && io.lsu.req.fire && s0_req(w).uop.uses_stq),    // 保证store的顺序性
        init = false.B  // <- s1 valid 的初始值
    ))
    for (w <- 0 until memWidth) {   // 只有有效指令才会被kill
        assert(!(io.lsu.s1_kill(w) && !RegNext(io.lsu.req.fire) && !RegNext(io.lsu.req.bits(w).valid)))
    }
    val s1_addr              = s1_req.map(_.addr)
    val s1_send_resp_or_nack = RegNext(s0_send_resp_or_nack)
    val s1_type              = RegNext(s0_type)

    // 好像是三个都存了所选的way，除了普通的lsu请求和预取请求
    val s1_mshr_meta_read_wayMux = RegNext(mshrs.io.meta_read.bits.wayMux)  // 为什么这个单独拎出来了？？？
    val s1_replay_wayMux         = RegNext(mshrs.io.replay.bits.wayMux) // For replays, the metadata isn't written yet 啊？？？
    val s1_wb_wayMux             = RegNext(wb.io.data_req.bits.wayMux)

    // tag check    // 就是来比较tag的
    val s1_tag_eq_way = widthMap(i => wayMap(
            (w: Int) => meta(i).io.resp(w).tag === (s1_addr(i) >> untagBits)
    ).asUInt)
    // s1_tag_match_way 应该是one hot的
    val s1_tag_match_way = widthMap(i =>    // 命中的那条路，显然有的是已经选好了的
        Mux(s1_type === t_replay,         s1_replay_way_en,
        Mux(s1_type === t_wb,             s1_wb_way_en,
        Mux(s1_type === t_mshr_meta_read, s1_mshr_meta_read_way_en,
        wayMap((w: Int) => s1_tag_eq_way(i)(w)).asUInt)))
    )
    // 用于产生 写回型的nack 要读的是正在写回的
    val s1_wb_idx_matches = widthMap(
        i => (s1_addr(i)(untagBits - 1,lineOffBits) === wb.io.idx.bits) && wb.io.idx.valid
    )

    val s2_req   = RegNext(s1_req)
    val s2_type  = RegNext(s1_type)
    val s2_valid = widthMap(w => RegNext(
        s1_valid(w) &&
        !io.lsu.s1_kill(w) &&   // 指令被转发就会被kill，或者之前有fence，或者前面有amo
        !IsKilledByBranch(io.lsu.brupdate, s1_req(w).uop) &&
        // !(io.lsu.exception && s1_req(w).uop.uses_ldq) &&
        !(s2_store_failed && (s1_type === t_lsu) && s1_req(w).uop.uses_stq)
    ))
    for (w <- 0 until memWidth) {
        s2_req(w).uop.br_mask := GetNewBrMask(io.lsu.brupdate, s1_req(w).uop)
    }

    val s2_tag_match_way = RegNext(s1_tag_match_way)
    val s2_tag_match     = s2_tag_match_way.map(_.orR)

    val s2_hit = widthMap(w => 
        (s2_tag_match(w)  && !mshrs.io.block_hit(w)) || s2_type.isOneOf(t_replay, t_wb)
    )
    assert(!(s2_type === t_replay && !s2_hit(0)), "Replays should always hit")
    assert(!(s2_type === t_wb && !s2_hit(0)), "Writeback should always see data hit")

    val s2_wb_idx_matches = RegNext(s1_wb_idx_matches)

// -------------------------------------------------------------------------------
    // // lr/sc  // 先不看吧
    // val debug_sc_fail_addr = RegInit(0.U)
    // val debug_sc_fail_cnt  = RegInit(0.U(8.W))

    // val lrsc_count = RegInit(0.U(log2Ceil(lrscCycles).W))
    // val lrsc_valid = lrsc_count > lrscBackoff.U
    // val lrsc_addr  = Reg(UInt())
    // val s2_lr = s2_req(0).uop.mem_cmd === M_XLR && (!RegNext(s1_nack(0)) || s2_type === t_replay)
    // val s2_sc = s2_req(0).uop.mem_cmd === M_XSC && (!RegNext(s1_nack(0)) || s2_type === t_replay)
    // val s2_lrsc_addr_match = widthMap(w => lrsc_valid && lrsc_addr === (s2_req(w).addr >> lineOffBits))
    // val s2_sc_fail = s2_sc && !s2_lrsc_addr_match(0)
    // when (lrsc_count > 0.U) { lrsc_count := lrsc_count - 1.U }
    // when (
    //     s2_valid(0) && ((s2_type === t_lsu && s2_hit(0) && !s2_nack(0)) ||
    //     (s2_type === t_replay && s2_req(0).uop.mem_cmd =/= M_FLUSH_ALL))
    // ) {
    //     when (s2_lr) {
    //         lrsc_count := (lrscCycles - 1).U
    //         lrsc_addr := s2_req(0).addr >> lineOffBits
    //     }
    //     when (lrsc_count > 0.U) {
    //         lrsc_count := 0.U
    //     }
    // }
    // for (w <- 0 until memWidth) {
    //     when (  // 此处tag match 和 hit 的关系？？？
    //         s2_valid(w) && s2_type === t_lsu && !s2_hit(w) &&
    //         !s2_tag_match(w) && s2_lrsc_addr_match(w) && !s2_nack(w)
    //     ) {
    //     lrsc_count := 0.U
    //     }
    // }
    // when (s2_valid(0)) {
    //     when (s2_req(0).addr === debug_sc_fail_addr) {
    //         when (s2_sc_fail) {
    //             debug_sc_fail_cnt := debug_sc_fail_cnt + 1.U
    //         } .elsewhen (s2_sc) {
    //             debug_sc_fail_cnt := 0.U
    //         }
    //     } .otherwise {
    //     when (s2_sc_fail) {
    //         debug_sc_fail_addr := s2_req(0).addr
    //         debug_sc_fail_cnt  := 1.U
    //     }
    //     }
    // }
    // assert(debug_sc_fail_cnt < 100.U, "L1DCache failed too many SCs in a row")
// -------------------------------------------------------------------------------

    val s2_data = Wire(Vec(memWidth, Vec(nWays, UInt(encRowBits.W))))
    for (i <- 0 until memWidth) {
        for (w <- 0 until nWays) {
            s2_data(i)(w) := data.io.resp(i)(w)
        }
    }
    val s2_data_muxed = widthMap(w =>   // w 指的是哪条流水线
        Mux1H(s2_tag_match_way(w), s2_data(w))
    )

    // replacement policy   // 好像在s1阶段选出替换的行
    val replacer = cacheParams.replacement  // 写一个替换策略
    val s2_replaced_way_en = UIntToOH(RegNext(replacer.way))
    val s2_repl_meta = widthMap(i => Mux1H(
        s2_replaced_way_en,
        wayMap((w: Int) => RegNext(meta(i).io.resp(w))).toSeq
    ))

    val s2_nack = Wire(Vec(memWidth, Bool()))
    // MSHRs not ready for request
    val s2_nack_miss   = widthMap(
        w => s2_valid(w) && !s2_hit(w) && !mshrs.io.req(w).ready
    )
    // Can't allocate MSHR for same set currently being written back
    val s2_nack_wb = widthMap(
        w => s2_valid(w) && !s2_hit(w) && s2_wb_idx_matches(w)
    )

    s2_nack := widthMap(w => (s2_nack_miss(w) || s2_nack_wb(w)) && s2_type =/= t_replay)    // 我觉得重发也不会nack啊
    val s2_send_resp = widthMap(w => (RegNext(
        s1_send_resp_or_nack(w)) && !s2_nack(w) &&
        (s2_hit(w) || (mshrs.io.req(w).fire && isWrite(s2_req(w).uop.mem_cmd) && !isRead(s2_req(w).uop.mem_cmd))
    ))) // store 类型的指令给到mshr就算完成了，此处类型指的是只用写不用读（也就是不需要返回数据）
    val s2_send_nack = widthMap(w => (RegNext(s1_send_resp_or_nack(w)) && s2_nack(w)))
    for (w <- 0 until memWidth) {
        assert(!(s2_send_resp(w) && s2_send_nack(w)))
    }

    // hits always send a response
    // If MSHR is not available, LSU has to replay this request later
    // If MSHR is available and this is only a store(not a amo), we don't need to wait for resp later
    s2_store_failed := s2_valid(0) && s2_nack(0) && s2_send_nack(0) && s2_req(0).uop.uses_stq

    // Miss handling
    for (w <- 0 until memWidth) {
        mshrs.io.req(w).valid := (
            s2_valid(w) &&
            !s2_hit(w) &&
            !s2_nack_wb(w) &&   // nack 不进 mshr，mshr那边逻辑简单
            s2_type.isOneOf(t_lsu, t_prefetch) &&
            !IsKilledByBranch(io.lsu.brupdate, s2_req(w).uop) &&
            // !(io.lsu.exception && s2_req(w).uop.uses_ldq) &&
            (isPrefetch(s2_req(w).uop.mem_cmd) ||
             isRead(s2_req(w).uop.mem_cmd)     ||
             isWrite(s2_req(w).uop.mem_cmd))
        )
        assert(!(mshrs.io.req(w).valid && s2_type === t_replay), "Replays should not need to go back into MSHRs")
        mshrs.io.req(w).bits             := DontCare
        mshrs.io.req(w).bits.uop         := s2_req(w).uop
        mshrs.io.req(w).bits.uop.br_mask := GetNewBrMask(io.lsu.brupdate, s2_req(w).uop)
        mshrs.io.req(w).bits.addr        := s2_req(w).addr
        mshrs.io.req(w).bits.tag_match   := s2_tag_match(w)
        mshrs.io.req(w).bits.old_meta    := Mux(s2_tag_match(w), Metadata(s2_repl_meta(w).tag), s2_repl_meta(w))    // meta 其他的dont care
        mshrs.io.req(w).bits.wayMux      := Mux(s2_tag_match(w), s2_tag_match_way(w), s2_replaced_wayMux)
        mshrs.io.req(w).bits.data        := s2_req(w).data
    }

    mshrs.io.meta_resp.valid      := true.B // 其实不太确定，可能要改改
    mshrs.io.meta_resp.bits       := Mux1H(s2_tag_match_way(0), RegNext(meta(0).io.resp))
    when (mshrs.io.req.map(_.fire).reduce(_||_)) { replacer.miss }  // TODO

    // refills 
    tl_out.d.ready := true.B    // 应该是一直等吧---
    dataWriteArb.io.in(1) <> mshrs.io.refill    // 重填接口
    metaWriteArb.io.in(0) <> mshrs.io.meta_write

    tl_out.e <> mshrs.io.mem_finish

    // writebacks
    wb.io.req <> mshrs.io.wb_req
    wb.io.data_resp  := s2_data_muxed(0) // 还要再看看
    mshrs.io.wb_resp := wb.io.resp

    // load data gen
    val s2_data_word_prebypass = widthMap(w => s2_data_muxed(w))
    val s2_data_word = Wire(Vec(memWidth, UInt()))

    val loadgen = (0 until memWidth).map { w => new LoadGen(
        s2_req(w).uop.mem_size, s2_req(w).uop.mem_signed, s2_req(w).addr,
        s2_data_word(w), s2_sc && (w == 0).B, wordBytes
    )}

    // Mux between cache responses and uncache responses
    val cache_resp = Wire(Vec(memWidth, Valid(new DCacheResp)))
    for (w <- 0 until memWidth) {
        cache_resp(w).valid         := s2_valid(w) && s2_send_resp(w)
        cache_resp(w).bits.uop      := s2_req(w).uop
        cache_resp(w).bits.data     := loadgen(w).data /* | s2_sc_fail */
    }
    val uncache_resp = Wire(Valid(new BoomDCacheResp))
    uncache_resp.bits   := mshrs.io.resp.bits
    uncache_resp.valid  := mshrs.io.resp.valid
    mshrs.io.resp.ready := !(cache_resp.map(_.valid).reduce(_&&_)) // We can backpressure the MSHRs, but not cache hits

    val resp = WireInit(cache_resp)
    var uncache_responding = false.B
    for (w <- 0 until memWidth) {   // uncache的一定只有一个
        val uncache_respond = !cache_resp(w).valid && !uncache_responding
        when (uncache_respond) {
            resp(w) := uncache_resp
        }
        uncache_responding = uncache_responding || uncache_respond
    }

    // 产生resp
    for (w <- 0 until memWidth) {
        io.lsu.resp(w).valid := (
            resp(w).valid && /* !(io.lsu.exception && resp(w).bits.uop.uses_ldq) && */
            !IsKilledByBranch(io.lsu.brupdate, resp(w).bits.uop)
        )
        // 有待商榷
        io.lsu.resp(w).bits := UpdateBrMask(io.lsu.brupdate, resp(w).bits)

        io.lsu.nack(w).valid := (
            s2_valid(w) && s2_send_nack(w) &&
            /*  !(io.lsu.exception && s2_req(w).uop.uses_ldq) && */
            !IsKilledByBranch(io.lsu.brupdate, s2_req(w).uop)
        )
        io.lsu.nack(w).bits  := UpdateBrMask(io.lsu.brupdate, s2_req(w))
        assert(!(io.lsu.nack(w).valid && s2_type =/= t_lsu))
    }

    // Store/amo hits
    val s3_req   = RegNext(s2_req(0))
    val s3_valid = RegNext(     // 正常的store指令
        s2_valid(0) && s2_hit(0) && isWrite(s2_req(0).uop.mem_cmd) &&
        /* !s2_sc_fail && */ !(s2_send_nack(0) && s2_nack(0))
    )
    for (w <- 1 until memWidth) {
        assert(
            !(s2_valid(w) && s2_hit(w) && isWrite(s2_req(w).uop.mem_cmd) &&
            !s2_sc_fail && !(s2_send_nack(w) && s2_nack(w))),
        "Store must go through 0th pipe in L1D")
    }

    // For bypassing
    val s4_req   = RegNext(s3_req)
    val s4_valid = RegNext(s3_valid)
    val s5_req   = RegNext(s4_req)
    val s5_valid = RegNext(s4_valid)

    // 为什么整这么多
    val s3_bypass = widthMap(w =>
        s3_valid && ((s2_req(w).addr >> wordOffBits) === (s3_req.addr >> wordOffBits))
    )
    val s4_bypass = widthMap(w =>
        s4_valid && ((s2_req(w).addr >> wordOffBits) === (s4_req.addr >> wordOffBits))
    )
    val s5_bypass = widthMap(w =>
        s5_valid && ((s2_req(w).addr >> wordOffBits) === (s5_req.addr >> wordOffBits))
    )

    // Store -> Load bypassing
    for (w <- 0 until memWidth) {
        s2_data_word(w) :=  Mux(s3_bypass(w), s3_req.data,
                            Mux(s4_bypass(w), s4_req.data,
                            Mux(s5_bypass(w), s5_req.data,
                            s2_data_word_prebypass(w))))
    }

    // val amoalu   = Module(new AMOALU(xLen))
    // amoalu.io.mask := new StoreGen(s2_req(0).uop.mem_size, s2_req(0).addr, 0.U, xLen/8).mask
    // amoalu.io.cmd  := s2_req(0).uop.mem_cmd
    // amoalu.io.lhs  := s2_data_word(0)
    // amoalu.io.rhs  := s2_req(0).data
    // s3_req.data := amoalu.io.out // amo 在s3做？？？
    
    // store 也在 s3 做
    val s3_way   = RegNext(s2_tag_match_way(0))
    dataWriteArb.io.in(0).valid       := s3_valid
    dataWriteArb.io.in(0).bits.addr   := s3_req.addr
    dataWriteArb.io.in(0).bits.wmask  := UIntToOH(s3_req.addr.extract(rowOffBits - 1, offsetlsb))
    dataWriteArb.io.in(0).bits.data   := Fill(rowWords, s3_req.data)
    dataWriteArb.io.in(0).bits.way_en := s3_way

    io.lsu.ordered := mshrs.io.fence_rdy && !s1_valid.reduce(_||_) && !s2_valid.reduce(_||_)
}
