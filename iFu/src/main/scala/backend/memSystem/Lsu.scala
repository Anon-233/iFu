package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.common.CauseCode._

import iFu.tlb._
import iFu.util._

import iFu.lsu.utils._

//TODO  memWidth为2，如果为1，需要wakeup不成功后增加一周期delay  Done
//TODO tlb_miss抛出异常。
//TODO 删除Hella Cache相关的代码  Done
//TODO 删除release，observed等代码，load可以乱序   Done
//TODO 增加TLB相关逻辑，包括异常检测，发送DCache请求时的地址,发送数据给tlb
//TODO LSU会将vaddr的idx位发给DCache，TLB_MISS在s1_kill掉请求
//TODO uncacheable:1.外设  2.地址转换
//load:当为rob要提交的指令，且store为空的时候，发送该条指令
//store:提交后发送，和正常store一致

object AgePriorityEncoder {
    def apply(in: Seq[Bool], head: UInt): UInt = {
        val n = in.size
        val width = log2Ceil(in.size)
        val n_padded = 1 << width
        val temp_vec = (0 until n_padded).map(i => if (i < n) in(i) && i.U >= head else false.B) ++ in
        val idx = PriorityEncoder(temp_vec)
        idx(width-1, 0) //discard msb
    }
}

class LSUExeIO extends CoreBundle {
    val req   = Flipped(new Valid(new FuncUnitResp))
    val iresp = new DecoupledIO(new ExeUnitResp)
}

class LSUTLBDataIO extends CoreBundle {
    val r_req  = Vec(memWidth, Output(new TLBDataRReq))
    val r_resp = Vec(memWidth, Flipped(Valid(new TLBDataRResp)))
}
/**
 * 输入dispatch阶段的uop，commit的信息，rob，brupdate
 * 输出ldq，stq的索引，是否full，给rob的clear信号
 */
// lsu <> core
class LSUCoreIO extends CoreBundle {
    /** *********************************** */
    val robAddrSz = robParameters.robAddrSz
    val ldqAddrSz = lsuParameters.ldqAddrSz
    val stqAddrSz = lsuParameters.stqAddrSz
    /** ************************************ */

    val exe = Vec(memWidth, new LSUExeIO)

    val dis_uops    = Flipped(Vec(coreWidth, Valid(new MicroOp)))
    val dis_ldq_idx = Output(Vec(coreWidth, UInt(ldqAddrSz.W)))
    val dis_stq_idx = Output(Vec(coreWidth, UInt(stqAddrSz.W)))

    val ldq_full    = Output(Vec(coreWidth,Bool()))
    val stq_full    = Output(Vec(coreWidth,Bool()))

    val commit      = Input(new CommitSignals)
    val commit_load_at_rob_head = Input(Bool())

    val clr_bsy     = Output(Vec(memWidth,Valid(UInt(robAddrSz.W))))    // TODO

    val fence_dmem  = Input(Bool())

    // Speculatively tell the IQs that we'll get load data back next cycle
    val spec_ld_wakeup = Output(Vec(memWidth, Valid(UInt(pregSz.W))))
    val ld_miss     = Output(Bool())

    val brupdate    = Input(new BrUpdateInfo)
    val rob_head_idx= Input(UInt(robAddrSz.W))
    val exception   = Input(Bool())

    val stq_empty   = Output(Bool())
    val dcache_ord  = Output(Bool())

    val lsu_xcpt    = Output(Valid(new Exception))

    val tlb_data    = new LSUTLBDataIO
}

class LSUCsrIO extends CoreBundle {
    val dtlb_csr_ctx = Input(new DTLBCsrContext)
    val llbit        = Input(Bool())
}

class LSUIO extends CoreBundle {
    val core  = new LSUCoreIO
    val dreq  = Output(new CBusReq)
    val dresp = Input(new CBusResp)
    val csr   = new LSUCsrIO
}

trait HasUop extends Bundle {
    val uop = new MicroOp
}

class LDQEntry extends CoreBundle with HasUop {
    /** *********************************** */
    val numStqEntries = lsuParameters.numSTQEntries
    val numLdqEntries = lsuParameters.numLDQEntries
    val stqAddrSz     = lsuParameters.stqAddrSz
    val ldqAddrSz     = lsuParameters.ldqAddrSz
    /** ************************************ */

    val addr             = Valid(UInt(xLen.W))
    val addr_is_virtual  = Bool()

    val executed         = Bool()
    val succeeded        = Bool() // dcache 返回结果
    val order_fail       = Bool() // raw 冒险

    val st_dep_mask      = UInt(numStqEntries.W)
    val youngest_stq_idx = UInt(stqAddrSz.W) // 第一条晚于该load的store指令

    val forward_std_val  = Bool()
    val forward_stq_idx  = UInt(stqAddrSz.W)

    val is_uncacheable   = Bool()
}

class STQEntry extends CoreBundle with HasUop {
    val addr            = Valid(UInt(xLen.W))
    val addr_is_virtual = Bool()
    val data            = Valid(UInt(xLen.W))
    val is_uncacheable  = Bool()

    val committed       = Bool()
    val succeeded       = Bool() // 访存成功
}

class Lsu extends CoreModule {
    //-------------------------------------------------------------
    val numStqEntries = lsuParameters.numSTQEntries
    val numLdqEntries = lsuParameters.numLDQEntries
    val stqAddrSz     = lsuParameters.stqAddrSz
    val ldqAddrSz     = lsuParameters.ldqAddrSz
    //-------------------------------------------------------------

    //-------------------------------------------------------------
    def widthMap[T <: Data](f: Int => T) = VecInit((0 until memWidth).map(f))
    //-------------------------------------------------------------

    //-------------------------------------------------------------
    val io = IO(new LSUIO)
    io.core.exe(0).iresp := DontCare
    io.core.exe(1).iresp := DontCare
    //-------------------------------------------------------------

    //-------------------------------------------------------------
    val dcache  = Module(new NonBlockingDcache)
    io.dreq            := dcache.io.cbusReq
    dcache.io.cbusResp := io.dresp
    //-------------------------------------------------------------

    //-------------------------------------------------------------
    val ldq = Reg(Vec(numLdqEntries, Valid(new LDQEntry)))
    val ldq_head = Reg(UInt(ldqAddrSz.W))
    val ldq_tail = Reg(UInt(ldqAddrSz.W))
    //-------------------------------------------------------------

    //-------------------------------------------------------------
    val stq = Reg(Vec(numStqEntries, Valid(new STQEntry)))
    val stq_head = Reg(UInt(stqAddrSz.W)) // will dequeue
    val stq_tail = Reg(UInt(stqAddrSz.W))
    val stq_commit_head  = Reg(UInt(stqAddrSz.W))   // point to next store to commit
    val stq_execute_head = Reg(UInt(stqAddrSz.W))   // point to next store to execute
    //-------------------------------------------------------------

    //-------------------------------------------------------------
    val finish_store = WireInit(false.B)    // we finish a store this cycle
    //-------------------------------------------------------------

    val live_store_mask = RegInit(0.U(numStqEntries.W)) // 当前哪些位置有store指令 // diff with valid?
    var next_live_store_mask = Mux(finish_store, 
        live_store_mask & (~(1.U << stq_head)).asUInt, // -> 如果store指令提交了，那么该位置零
        live_store_mask
    )

/*=============================================================================*/
    //-------------------------------------------------------------
    // Dequeue store entries
    //-------------------------------------------------------------
    for (i <- 0 until numLdqEntries) { // store指令提交后，修改ldq中与该条指令有关的位
        when(finish_store) {
            ldq(i).bits.st_dep_mask := ldq(i).bits.st_dep_mask & (~(1.U << stq_head)).asUInt
        }
    }

/*=============================================================================*/
    //-------------------------------------------------------------
    // Enqueue new entries
    //-------------------------------------------------------------
    // var ld_enq_idx = ldq_tail
    // var st_enq_idx = stq_tail
    // var ldq_full = Bool() // 过程中出现ldq已满
    // var stq_full = Bool() // 过程中出现stq已满
    val padded_ldq_head = ldq_head.pad(ldq_head.getWidth + 1)
    val padded_ldq_tail = ldq_tail.pad(ldq_tail.getWidth + 1)
    val padded_stq_head = stq_head.pad(stq_head.getWidth + 1)
    val padded_stq_tail = stq_tail.pad(stq_tail.getWidth + 1)

    val ldq_full = Mux(padded_ldq_tail >= padded_ldq_head, padded_ldq_tail + coreWidth.U >= padded_ldq_head + numLdqEntries.U,
                                                                padded_ldq_tail + coreWidth.U >= padded_ldq_head)

    val stq_full = Mux(padded_stq_tail >= padded_stq_head, padded_stq_tail + coreWidth.U >= padded_stq_head + numStqEntries.U,
                                                                padded_stq_tail + coreWidth.U >= padded_stq_head)

    val idxAllocator = Module(new IndexAllocator)
    idxAllocator.io.dis_uops := io.core.dis_uops
    idxAllocator.io.old_ldq_tail := ldq_tail
    idxAllocator.io.old_stq_tail := stq_tail
    for (w <- 0 until coreWidth) {
        // ldq_full = WrapInc(ld_enq_idx, numLdqEntries) === ldq_head
        io.core.ldq_full(w) := ldq_full
        
        val ld_enq_idx = idxAllocator.io.ldq_enq_idxs(w)
        io.core.dis_ldq_idx(w) := ld_enq_idx

        // stq_full = WrapInc(st_enq_idx, numStqEntries) === stq_head
        io.core.stq_full(w) := stq_full

        val st_enq_idx = idxAllocator.io.stq_enq_idxs(w)
        io.core.dis_stq_idx(w) := st_enq_idx

        // enq
        val dis_ld_val = io.core.dis_uops(w).valid && io.core.dis_uops(w).bits.use_ldq && !io.core.dis_uops(w).bits.xcpt_valid
        val dis_st_val = io.core.dis_uops(w).valid && io.core.dis_uops(w).bits.use_stq && !io.core.dis_uops(w).bits.xcpt_valid
        when(dis_ld_val) {
            ldq(ld_enq_idx).valid := true.B
            ldq(ld_enq_idx).bits.uop := io.core.dis_uops(w).bits
            ldq(ld_enq_idx).bits.youngest_stq_idx := st_enq_idx
            ldq(ld_enq_idx).bits.st_dep_mask := next_live_store_mask

            ldq(ld_enq_idx).bits.addr.valid := false.B
            ldq(ld_enq_idx).bits.executed := false.B
            ldq(ld_enq_idx).bits.succeeded := false.B
            ldq(ld_enq_idx).bits.order_fail := false.B
            ldq(ld_enq_idx).bits.forward_std_val := false.B

            assert(ld_enq_idx === io.core.dis_uops(w).bits.ldqIdx, "[lsu] mismatch enq load tag.")
            assert(!ldq(ld_enq_idx).valid, "[lsu] Enqueuing uop is overwriting ldq entries")
        } .elsewhen(dis_st_val) {
            stq(st_enq_idx).valid := true.B
            stq(st_enq_idx).bits.uop := io.core.dis_uops(w).bits

            stq(st_enq_idx).bits.addr.valid := false.B
            stq(st_enq_idx).bits.data.valid := false.B
            stq(st_enq_idx).bits.committed := false.B
            stq(st_enq_idx).bits.succeeded := false.B

            assert(st_enq_idx === io.core.dis_uops(w).bits.stqIdx, "[lsu] mismatch enq store tag.")
            // assert(!stq(st_enq_idx).valid, "[lsu] Enqueuing uop is overwriting stq entries")
        }

        // ld_enq_idx = Mux(dis_ld_val, WrapInc(ld_enq_idx, numLdqEntries), ld_enq_idx)

        next_live_store_mask = Mux(dis_st_val,      // 新增store指令
            next_live_store_mask | (1.U << st_enq_idx).asUInt,
            next_live_store_mask
        )

        // st_enq_idx = Mux(dis_st_val, WrapInc(st_enq_idx, numStqEntries), st_enq_idx)

        assert(!(dis_ld_val && dis_st_val), "A UOP is trying to go into both the LDQ and the STQ")
    }

    // ldq_tail := ld_enq_idx
    // stq_tail := st_enq_idx
    ldq_tail := idxAllocator.io.new_ldq_tail
    stq_tail := idxAllocator.io.new_stq_tail

    val stqEmpty = (0 until numStqEntries).map{ i => stq(i).valid }.reduce(_||_) === 0.U
    dcache.io.lsu.fence_dmem := io.core.fence_dmem
    io.core.stq_empty  := stqEmpty
    io.core.dcache_ord := dcache.io.lsu.ordered

/*=============================================================================*/
    //-------------------------------------------------------------
    // Execute stage (access TLB, send requests to Memory)
    //-------------------------------------------------------------

    // TODO: which instruction should we select?
    val tlb_xcpt_valid = Wire(Bool())
    val tlb_xcpt_cause = Wire(UInt())
    val tlb_xcpt_uop   = Wire(new MicroOp)
    val tlb_xcpt_vaddr = Wire(UInt())

    //---------------------------------------
    // Can-fire logic and wakeup
    // These are the "can_fire"/"will_fire" signals

    val will_fire_load_incoming = Wire(Vec(memWidth, Bool()))
    val will_fire_stad_incoming = Wire(Vec(memWidth, Bool()))
    val will_fire_sta_incoming = Wire(Vec(memWidth, Bool()))
    val will_fire_std_incoming = Wire(Vec(memWidth, Bool()))
    val will_fire_store_commit = Wire(Vec(memWidth, Bool()))
    val will_fire_load_wakeup = Wire(Vec(memWidth, Bool()))

    val exe_req = WireInit(VecInit(io.core.exe.map(_.req)))

    // -------------------------------
    // Assorted signals for scheduling

    // Don't wakeup a load if we just sent it last cycle or two cycles ago
    // The p0_block_load_mask may be wrong, but the executing_load mask must be accurate
    val p0_block_load_mask = WireInit(VecInit(IndexedSeq.fill(numLdqEntries){ false.B }))
    val p1_block_load_mask = RegNext(p0_block_load_mask)
    val p2_block_load_mask = RegNext(p1_block_load_mask)

    // The store at the commit head needs the DCache to appear ordered
    // Delay firing load wakeups and retries now
    val store_needs_order = WireInit(false.B)   // fence指令
    // 将要到来的ldq和stq里的元素
    val ldq_incoming_idx = widthMap(i => exe_req(i).bits.uop.ldqIdx)
    val ldq_incoming_e = widthMap(i => ldq(ldq_incoming_idx(i)))

    val stq_incoming_idx = widthMap(i => exe_req(i).bits.uop.stqIdx)
    val stq_incoming_e = widthMap(i => stq(stq_incoming_idx(i)))

    val stq_commit_e = stq(stq_execute_head)
    //推测： s1选中，s2激活，以此改善时序
    val ldq_wakeup_idx = RegNext(
        AgePriorityEncoder((0 until numLdqEntries).map(
            i => {
                val e = ldq(i).bits
                val block = p0_block_load_mask(i) || p1_block_load_mask(i)
                e.addr.valid && !e.executed && !e.succeeded && !e.addr_is_virtual && !block
            }
        ), ldq_head))
    val ldq_wakeup_e = ldq(ldq_wakeup_idx)
    // Can we wakeup a load that was nack'd
    val block_load_wakeup = WireInit(false.B)
    val can_fire_load_wakeup = widthMap(w => (
        (w == memWidth - 1).B && // load wakeup只会发射到第1条流水线
        ldq_wakeup_e.valid &&
        ldq_wakeup_e.bits.addr.valid &&
        !ldq_wakeup_e.bits.succeeded && // load指令没有访存成功
        !ldq_wakeup_e.bits.addr_is_virtual &&
        !ldq_wakeup_e.bits.executed && // 未进行访存
        !ldq_wakeup_e.bits.order_fail &&
        !p1_block_load_mask(ldq_wakeup_idx) &&
        !p2_block_load_mask(ldq_wakeup_idx) &&
        !store_needs_order &&
        !block_load_wakeup &&
        (!ldq_wakeup_e.bits.is_uncacheable ||
        (io.core.commit_load_at_rob_head && //
        ldq_head === ldq_wakeup_idx &&
        ldq_wakeup_e.bits.st_dep_mask.asUInt === 0.U))
    ))
    // -----------------------
    // Determine what can fire

    // Can we fire a incoming load
    val can_fire_load_incoming = widthMap(
        w => exe_req(w).valid && exe_req(w).bits.uop.ctrl.is_load
    )
    // Can we fire an incoming store addrgen + store datagen
    val can_fire_stad_incoming = widthMap(
        w => exe_req(w).valid && exe_req(w).bits.uop.ctrl.is_sta && exe_req(w).bits.uop.ctrl.is_std
    )
    // Can we fire an incoming store addrgen
    val can_fire_sta_incoming = widthMap(
        w => exe_req(w).valid && exe_req(w).bits.uop.ctrl.is_sta && !exe_req(w).bits.uop.ctrl.is_std
    )
    // Can we fire an incoming store datagen
    val can_fire_std_incoming = widthMap(
        w => exe_req(w).valid && exe_req(w).bits.uop.ctrl.is_std && !exe_req(w).bits.uop.ctrl.is_sta
    )

    // Can we commit a store
    val can_fire_store_commit = widthMap(w => (
        (w == 0).B &&   // store只会发射到第0条流水线
        stq_commit_e.valid &&   // 该store指令有效
        !tlb_xcpt_valid &&  //  TODO
        !stq_commit_e.bits.uop.xcpt_valid && // TODO
        !stq_commit_e.bits.succeeded &&
        (
            stq_commit_e.bits.committed ||     // 被 ROB 提交

            (stq_commit_e.bits.uop.is_sc &&
             stq_commit_e.bits.addr.valid && // 地址准备好了
            !stq_commit_e.bits.addr_is_virtual &&   // TLB 没有miss
             stq_commit_e.bits.data.valid)
        )   // 数据准备好了
    ))
    //---------------------------------------------------------
    // Controller logic. Arbitrate which request actually fires

    val exe_tlb_valid = Wire(Vec(memWidth, Bool()))
    for (w <- 0 until memWidth) {
        // var变量表示需要被抢占的资源
        var tlb_avail = true.B
        var dc_avail = true.B // dc -> dcache
        var lcam_avail = true.B // TODO
        var rob_avail = true.B

        def lsu_sched(can_fire: Bool, uses_tlb: Boolean, uses_dc: Boolean, uses_lcam: Boolean, uses_rob: Boolean): Bool = {
            val will_fire = can_fire && 
                !(uses_tlb.B && !tlb_avail) &&
                !(uses_lcam.B && !lcam_avail) &&
                !(uses_dc.B && !dc_avail) &&
                !(uses_rob.B && !rob_avail)

            tlb_avail = tlb_avail && !(will_fire && uses_tlb.B)
            lcam_avail = lcam_avail && !(will_fire && uses_lcam.B)
            dc_avail = dc_avail && !(will_fire && uses_dc.B)
            rob_avail = rob_avail && !(will_fire && uses_rob.B)
            if(!FPGAPlatform)dontTouch(will_fire) // if(!FPGAPlatform)dontTouch these so we can inspect the will_fire signals
            will_fire
        }

        // will开头表示经过了排序
        will_fire_load_incoming(w) := lsu_sched(can_fire_load_incoming(w), true , true , true , false) // TLB , DC , LCAM ,
        will_fire_stad_incoming(w) := lsu_sched(can_fire_stad_incoming(w), true , false, true , true ) // TLB ,    , LCAM , ROB
        will_fire_sta_incoming(w)  := lsu_sched(can_fire_sta_incoming(w) , true , false, true , true ) // TLB ,    , LCAM , ROB
        will_fire_std_incoming(w)  := lsu_sched(can_fire_std_incoming(w) , false, false, false, true ) //     ,    ,      , ROB
        will_fire_load_wakeup(w)   := lsu_sched(can_fire_load_wakeup(w)  , false, true , true , false) //     , DC , LCAM1,
        will_fire_store_commit(w)  := lsu_sched(can_fire_store_commit(w) , false, true , false, false) //     , DC ,      ,

        when (will_fire_load_wakeup(w)) {
            p0_block_load_mask(ldq_wakeup_idx) := true.B
        } .elsewhen(will_fire_load_incoming(w)) {
            p0_block_load_mask(exe_req(w).bits.uop.ldqIdx) := true.B
        }
        exe_tlb_valid(w) := !tlb_avail
    }

    //--------------------------------------------
    // TLB Access
    val exe_tlb_uop = widthMap(w =>
        Mux(will_fire_load_incoming(w) || will_fire_stad_incoming(w) ||
            will_fire_sta_incoming(w),
            exe_req(w).bits.uop, NullMicroOp)
    )
    val exe_tlb_vaddr = widthMap(w =>
        Mux(will_fire_load_incoming(w) || will_fire_stad_incoming(w) || will_fire_sta_incoming(w),
            exe_req(w).bits.addr,
            0.U
        )
    )

    val exe_size = widthMap(w =>
        Mux(will_fire_load_incoming(w) || will_fire_stad_incoming(w) ||
            will_fire_sta_incoming(w),
            exe_tlb_uop(w).mem_size, 0.U)
    )

    val dtlb = Module(new DTLB)
    dtlb.io <> DontCare
    for (w <- 0 until memWidth) {
        dtlb.io.req(w).vaddr := exe_tlb_vaddr(w)
        dtlb.io.req(w).size := exe_size(w)
        dtlb.io.req(w).use_stq := exe_req(w).bits.uop.use_stq
        dtlb.io.req(w).use_ldq := exe_req(w).bits.uop.use_ldq
    }
    // exceptions

    // TODO check for xcpt_if and verify that never happens on non-speculative instructions.
    val tlb_xcpt_valids = RegNext(widthMap(w =>
            exe_tlb_valid(w) &&
            dtlb.io.resp(w).exception.valid &&
            !io.core.exception &&
            !IsKilledByBranch(io.core.brupdate, exe_tlb_uop(w))))
    val tlb_xcpt_uops = RegNext(widthMap(w => UpdateBrMask(io.core.brupdate, exe_tlb_uop(w))))
    val tlb_xcpt_causes = RegNext(widthMap(w =>
        dtlb.io.resp(w).exception.bits.xcpt_cause
    ))          //TODO causes需要改变
    val tlb_xcpt_vaddrs = RegNext(exe_tlb_vaddr)

    tlb_xcpt_valid := tlb_xcpt_valids.reduce(_ || _)
    tlb_xcpt_cause := tlb_xcpt_causes(0)
    tlb_xcpt_uop := tlb_xcpt_uops(0)
    tlb_xcpt_vaddr := tlb_xcpt_vaddrs(0)
    var xcpt_found = tlb_xcpt_valids(0)
    var oldest_xcpt_rob_idx = tlb_xcpt_uops(0).robIdx
    for (w <- 1 until memWidth) {
        val is_older = WireInit(false.B)
        when (
            tlb_xcpt_valids(w) &&
            (IsOlder(tlb_xcpt_uops(w).robIdx, oldest_xcpt_rob_idx, io.core.rob_head_idx) || !xcpt_found)
        ) {
            is_older := true.B
            tlb_xcpt_cause := tlb_xcpt_causes(w)
            tlb_xcpt_uop := tlb_xcpt_uops(w)
            tlb_xcpt_vaddr := tlb_xcpt_vaddrs(w)
        }
        xcpt_found = xcpt_found || tlb_xcpt_valids(w)
        oldest_xcpt_rob_idx = Mux(is_older, tlb_xcpt_uops(w).robIdx, oldest_xcpt_rob_idx)
    }
    //TODO:可能不需要这里的miss,
    val exe_tlb_xcpt = widthMap(w => exe_tlb_valid(w) && dtlb.io.resp(w).exception.valid)
    val exe_tlb_paddr = widthMap(w => dtlb.io.resp(w).paddr)
    val exe_tlb_uncacheable = widthMap(w => dtlb.io.resp(w).is_uncacheable)
    for (w <- 0 until memWidth) {
        when(tlb_xcpt_valids(w)) {
            assert(RegNext(will_fire_load_incoming(w) || will_fire_stad_incoming(w) || will_fire_sta_incoming(w)))
            // Technically only faulting AMOs need this
            assert(tlb_xcpt_uops(w).use_ldq ^ tlb_xcpt_uops(w).use_stq)
            when(tlb_xcpt_uops(w).use_ldq) {
                ldq(tlb_xcpt_uops(w).ldqIdx).bits.uop.xcpt_valid := true.B
            } .otherwise {
                stq(tlb_xcpt_uops(w).stqIdx).bits.uop.xcpt_valid := true.B
            }
        }
    }

    //------------------------------
    // Issue Someting to Memory
    //
    // A memory op can come from many different places
    // The address either was freshly translated, or we are
    // reading a physical address from the LDQ, STQ

    // defaults
    dcache.io.lsu.brupdate := io.core.brupdate
    dcache.io.lsu.exception := io.core.exception
    dcache.io.lsu.rob_head_idx := io.core.rob_head_idx

    val dmem_req = Wire(Vec(memWidth, Valid(new DCacheReq)))
    dcache.io.lsu.req.valid := dmem_req.map(_.valid).reduce(_||_)
    dcache.io.lsu.req.bits := dmem_req
    val dmem_req_fire = widthMap(w => dmem_req(w).valid && dcache.io.lsu.req.fire)

    val s0_executing_loads = WireInit(VecInit((0 until numLdqEntries).map(x => false.B)))

    for (w <- 0 until memWidth) {
        dmem_req(w).valid := false.B
        dmem_req(w).bits.uop := NullMicroOp
        dmem_req(w).bits.addr := 0.U
        dmem_req(w).bits.data := 0.U
        dmem_req(w).bits.mask := 0.U
        dmem_req(w).bits.is_uncacheable := false.B
        dcache.io.lsu.s1_kill(w) := false.B

        when (will_fire_load_incoming(w)) {
            dmem_req(w).valid := !exe_tlb_xcpt(w) && !dtlb.io.resp(w).is_uncacheable
            dmem_req(w).bits.addr := exe_tlb_paddr(w)
            dmem_req(w).bits.uop := exe_tlb_uop(w)
            s0_executing_loads(ldq_incoming_idx(w)) := dmem_req_fire(w)
            assert(!ldq_incoming_e(w).bits.executed)
        } .elsewhen(will_fire_store_commit(w)) {
            dmem_req(w).valid               := true.B
            dmem_req(w).bits.addr           := stq_commit_e.bits.addr.bits
            dmem_req(w).bits.data           := stq_commit_e.bits.data.bits
            dmem_req(w).bits.mask           := storeMaskGen(stq_commit_e.bits.addr.bits(1,0),
                stq_commit_e.bits.uop.mem_size)
            dmem_req(w).bits.uop            := stq_commit_e.bits.uop
            dmem_req(w).bits.is_uncacheable := stq_commit_e.bits.is_uncacheable

            stq_execute_head := Mux(dmem_req_fire(w),
                WrapInc(stq_execute_head, numStqEntries),
                stq_execute_head
            )
            stq(stq_execute_head).bits.succeeded := false.B // TODO: do we need this?

        } .elsewhen(will_fire_load_wakeup(w)) {
            dmem_req(w).valid := true.B
            dmem_req(w).bits.addr := ldq_wakeup_e.bits.addr.bits
            dmem_req(w).bits.uop := ldq_wakeup_e.bits.uop
            dmem_req(w).bits.is_uncacheable := ldq_wakeup_e.bits.is_uncacheable
            s0_executing_loads(ldq_wakeup_idx) := dmem_req_fire(w)
            assert(!ldq_wakeup_e.bits.executed && !ldq_wakeup_e.bits.addr_is_virtual)
        }
        //-------------------------------------------------------------
        // Write Addr into the LAQ/SAQ
        when(will_fire_load_incoming(w)) {
            val ldq_idx = ldq_incoming_idx(w)
            ldq(ldq_idx).bits.addr.valid := true.B
            ldq(ldq_idx).bits.addr.bits := exe_tlb_paddr(w)
            ldq(ldq_idx).bits.uop.pdst := exe_tlb_uop(w).pdst
            ldq(ldq_idx).bits.addr_is_virtual := exe_tlb_xcpt(w)
            ldq(ldq_idx).bits.is_uncacheable := exe_tlb_uncacheable(w)

            assert(!(will_fire_load_incoming(w) && ldq_incoming_e(w).bits.addr.valid),
                "[lsu] Incoming load is overwriting a valid address")
        }

        when(will_fire_sta_incoming(w) || will_fire_stad_incoming(w)) {
            val stq_idx = stq_incoming_idx(w)
            stq(stq_idx).bits.addr.valid := true.B
            stq(stq_idx).bits.addr.bits  := exe_tlb_paddr(w)
            stq(stq_idx).bits.uop.pdst := exe_tlb_uop(w).pdst
            stq(stq_idx).bits.addr_is_virtual := exe_tlb_xcpt(w)
            stq(stq_idx).bits.is_uncacheable := exe_tlb_uncacheable(w)

            assert(!(will_fire_sta_incoming(w) && stq_incoming_e(w).bits.addr.valid),
                "[lsu] Incoming store is overwriting a valid address")
        }

        //-------------------------------------------------------------
        // Write data into the STQ
        when(will_fire_std_incoming(w) || will_fire_stad_incoming(w)) {
            val sidx = stq_incoming_idx(w)
            stq(sidx).bits.data.valid := true.B
            stq(sidx).bits.data.bits := exe_req(w).bits.data

            assert(!(stq(sidx).bits.data.valid),
                "[lsu] Incoming store is overwriting a valid data entry")
        }
    }
    // 优先级：store的uncachebale请求 > load的uncacheable请求
    when(dmem_req(0).bits.is_uncacheable) {
        // 当store指令的线有uncacheable请求时，独占所有线
        for (w <- 1 until memWidth) {
            dmem_req(w).valid := false.B
        }
    }.elsewhen(dmem_req(memWidth - 1).bits.is_uncacheable) {
        // 当load的uncacheable的线有uncacheable请求时，独占所有线
        for (w <- 0 until memWidth - 1) {
            dmem_req(w).valid := false.B
        }
    }
    //-------------------------------------------------------------
    //-------------------------------------------------------------
    // Cache Access Cycle (Mem)
    //-------------------------------------------------------------
    //-------------------------------------------------------------
    // Note the DCache may not have accepted our request

    val exe_req_killed = widthMap(w => IsKilledByBranch(io.core.brupdate, exe_req(w).bits.uop))
    //***********************stdf_killed 预测错误
    val fired_load_incoming = widthMap(w => RegNext(will_fire_load_incoming(w) && !exe_req_killed(w)))
    val fired_stad_incoming = widthMap(w => RegNext(will_fire_stad_incoming(w) && !exe_req_killed(w)))
    val fired_sta_incoming = widthMap(w => RegNext(will_fire_sta_incoming(w) && !exe_req_killed(w)))
    val fired_std_incoming = widthMap(w => RegNext(will_fire_std_incoming(w) && !exe_req_killed(w)))
    val fired_store_commit = RegNext(will_fire_store_commit)
    val fired_load_wakeup = widthMap(w => RegNext(will_fire_load_wakeup(w) && !IsKilledByBranch(io.core.brupdate, ldq_wakeup_e.bits.uop)))

    val mem_incoming_uop = RegNext(widthMap(w => UpdateBrMask(io.core.brupdate, exe_req(w).bits.uop)))
    val mem_ldq_incoming_e = RegNext(widthMap(w => UpdateBrMask(io.core.brupdate, ldq_incoming_e(w))))
    val mem_stq_incoming_e = RegNext(widthMap(w => UpdateBrMask(io.core.brupdate, stq_incoming_e(w))))
    val mem_ldq_wakeup_e = RegNext(UpdateBrMask(io.core.brupdate, ldq_wakeup_e))
    val mem_ldq_e = widthMap(w =>
        Mux(fired_load_incoming(w), mem_ldq_incoming_e(w),
        Mux(fired_load_wakeup(w), mem_ldq_wakeup_e,
        (0.U).asTypeOf(Valid(new LDQEntry))))
    )
    val mem_stq_e = widthMap(w =>
        Mux(fired_stad_incoming(w) || fired_sta_incoming(w),
        mem_stq_incoming_e(w), (0.U).asTypeOf(Valid(new STQEntry)))
    )
    val mem_tlb_xcpt             = RegNext(exe_tlb_xcpt)
    val mem_paddr = RegNext(widthMap(w => dmem_req(w).bits.addr))
    val mem_tlb_uncacheable      = RegNext(exe_tlb_uncacheable)
    // Task 1: Clr ROB busy bit
    val clr_bsy_valid = RegInit(widthMap(w => false.B))
    val clr_bsy_rob_idx = Reg(Vec(memWidth, UInt(robParameters.robAddrSz.W)))
    val clr_bsy_brmask = Reg(Vec(memWidth, UInt(maxBrCount.W)))

    for (w <- 0 until memWidth) {
        clr_bsy_valid(w) := false.B
        clr_bsy_rob_idx(w) := 0.U
        clr_bsy_brmask(w) := 0.U

        when(fired_stad_incoming(w)) {
            clr_bsy_valid(w) := mem_stq_incoming_e(w).valid &&
                                !mem_tlb_xcpt(w)                      &&
                                !mem_stq_incoming_e(w).bits.uop.is_sc &&
                                !IsKilledByBranch(io.core.brupdate, mem_stq_incoming_e(w).bits.uop)
            clr_bsy_rob_idx(w) := mem_stq_incoming_e(w).bits.uop.robIdx
            clr_bsy_brmask(w) := GetNewBrMask(io.core.brupdate, mem_stq_incoming_e(w).bits.uop)
        }.elsewhen(fired_sta_incoming(w)) {
            clr_bsy_valid(w) := mem_stq_incoming_e(w).valid &&
                mem_stq_incoming_e(w).bits.data.valid &&
                !mem_tlb_xcpt(w) &&
                !mem_stq_incoming_e(w).bits.uop.is_sc &&
                !IsKilledByBranch(io.core.brupdate, mem_stq_incoming_e(w).bits.uop)
            clr_bsy_rob_idx(w) := mem_stq_incoming_e(w).bits.uop.robIdx
            clr_bsy_brmask(w) := GetNewBrMask(io.core.brupdate, mem_stq_incoming_e(w).bits.uop)
        }.elsewhen(fired_std_incoming(w)) {
            clr_bsy_valid(w) := mem_stq_incoming_e(w).valid &&
                mem_stq_incoming_e(w).bits.addr.valid &&
                !mem_stq_incoming_e(w).bits.addr_is_virtual &&
                !mem_stq_incoming_e(w).bits.uop.is_sc &&
                !IsKilledByBranch(io.core.brupdate, mem_stq_incoming_e(w).bits.uop)
            clr_bsy_rob_idx(w) := mem_stq_incoming_e(w).bits.uop.robIdx
            clr_bsy_brmask(w) := GetNewBrMask(io.core.brupdate, mem_stq_incoming_e(w).bits.uop)
        }

        io.core.clr_bsy(w).valid := clr_bsy_valid(w) &&
            !IsKilledByBranch(io.core.brupdate, clr_bsy_brmask(w)) &&
            !io.core.exception && !RegNext(io.core.exception) &&
            !RegNext(RegNext(io.core.exception))
        io.core.clr_bsy(w).bits := clr_bsy_rob_idx(w)
    }

    // Task 2: Do LD-LD. ST-LD searches for ordering failures
    //         Do LD-ST search for forwarding opportunities
    // We have the opportunity to kill a request we sent last cycle. Use it wisely!

    // We translated a store last cycle
    val do_st_search = widthMap(w => (fired_stad_incoming(w) || fired_sta_incoming(w)) && !mem_tlb_xcpt(w))
    // We translated a load last cycle
    val do_ld_search = widthMap(w => ((fired_load_incoming(w) && !mem_tlb_xcpt(w)) || fired_load_wakeup(w)))
    // We are making a local line visible to other harts

    // Store addrs don't go to memory yet, get it from the TLB response
    // Load wakeups don't go through TLB, get it through memory
    // Load incoming and load retries go through both

    val lcam_addr = widthMap(w =>
        Mux(fired_stad_incoming(w) || fired_sta_incoming(w),
            RegNext(exe_tlb_paddr(w)), mem_paddr(w))
    )
    val lcam_uop = widthMap(w => 
        Mux(do_st_search(w), mem_stq_e(w).bits.uop,
        Mux(do_ld_search(w), mem_ldq_e(w).bits.uop,
            NullMicroOp))
    )

    val lcam_mask = widthMap(w => GenByteMask(lcam_addr(w), lcam_uop(w).mem_size))
    val lcam_st_dep_mask = widthMap(w => mem_ldq_e(w).bits.st_dep_mask)
    val lcam_ldq_idx = widthMap(w =>
        Mux(fired_load_incoming(w), mem_incoming_uop(w).ldqIdx,
        Mux(fired_load_wakeup(w), RegNext(ldq_wakeup_idx),
        0.U))
    )
    val lcam_stq_idx = widthMap(w =>
        Mux(fired_stad_incoming(w) || fired_sta_incoming(w),
            mem_incoming_uop(w).stqIdx, 0.U)
    )

    val can_forward = WireInit(widthMap(w =>
        Mux(fired_load_incoming(w),!mem_tlb_uncacheable(w),
            !ldq(lcam_ldq_idx(w)).bits.is_uncacheable)
    ))

    // Mask of stores which we conflict on address with
    val ldst_addr_matches = WireInit(widthMap(w => VecInit((0 until numStqEntries).map(x => false.B))))
    // Mask of stores which we can forward from
    val ldst_forward_matches = WireInit(widthMap(w => VecInit((0 until numStqEntries).map(x => false.B))))

    val failed_loads = WireInit(VecInit((0 until numLdqEntries).map(x => false.B))) // Loads which we will report as failures (throws a mini-exception)
    val nacking_loads = WireInit(VecInit((0 until numLdqEntries).map(x => false.B))) // Loads which are being nacked by dcache in the next stage

    val s1_executing_loads = RegNext(s0_executing_loads)
    val s1_set_execute = WireInit(s1_executing_loads)

    val mem_forward_valid = Wire(Vec(memWidth, Bool()))
    val mem_forward_ldq_idx = lcam_ldq_idx
    val mem_forward_ld_addr = lcam_addr
    val mem_forward_stq_idx = Wire(Vec(memWidth, UInt(log2Ceil(numStqEntries).W)))

    val wb_forward_valid = RegNext(mem_forward_valid)
    val wb_forward_ldq_idx = RegNext(mem_forward_ldq_idx)
    val wb_forward_ld_addr = RegNext(mem_forward_ld_addr)
    val wb_forward_stq_idx = RegNext(mem_forward_stq_idx)

    for (i <- 0 until numLdqEntries) {
        val l_valid = ldq(i).valid
        val l_bits = ldq(i).bits
        val l_addr = ldq(i).bits.addr.bits
        val l_mask = GenByteMask(l_addr, l_bits.uop.mem_size)

        val l_forwarders = widthMap(w => wb_forward_valid(w) && wb_forward_ldq_idx(w) === i.U)
        val l_is_forwarding = l_forwarders.reduce(_||_)
        val l_forward_stq_idx = Mux(l_is_forwarding, Mux1H(l_forwarders, wb_forward_stq_idx), l_bits.forward_stq_idx)

        val offsetBits = dcacheParameters.nOffsetBits
        val block_addr_matches = widthMap(w => lcam_addr(w) >> offsetBits === l_addr >> offsetBits)
        val word_addr_matches = widthMap(w => block_addr_matches(w) && lcam_addr(w)(offsetBits - 1, 2) === l_addr(offsetBits - 1, 2))
        val mask_overlap = widthMap(w => (l_mask & lcam_mask(w)).orR)

        // Searcher is a store
        for (w <- 0 until memWidth) {
            //Victim Buffer
            when(
                do_st_search(w) && l_valid && l_bits.addr.valid &&
                (l_bits.executed || l_bits.succeeded || l_is_forwarding) &&
                !l_bits.addr_is_virtual && l_bits.st_dep_mask(lcam_stq_idx(w)) &&
                word_addr_matches(w) &&
                mask_overlap(w)
            ) { //有字节重叠
                val forwarded_is_older = IsOlder(l_forward_stq_idx, lcam_stq_idx(w), l_bits.youngest_stq_idx)
                // We are older than this load, which overlapped us.
                when(
                    !l_bits.forward_std_val || // If the load wasn't forwarded, it definitely failed，因为已经执行过了
                    ((l_forward_stq_idx =/= lcam_stq_idx(w)) && forwarded_is_older) // If the load forwarded from us, we might be ok
                ) {
                    ldq(i).bits.order_fail := true.B
                    failed_loads(i) := true.B
                }
            }
        }
    }

    for (i <- 0 until numStqEntries) {
        val s_addr = stq(i).bits.addr.bits
        val s_uop = stq(i).bits.uop
        val word_addr_matches = widthMap(w => (
            stq(i).bits.addr.valid &&
            !stq(i).bits.addr_is_virtual &&
            (s_addr(xLen - 1, 2) === lcam_addr(w)(xLen - 1, 2))
        ))
        val write_mask = GenByteMask(s_addr, s_uop.mem_size)
        for (w <- 0 until memWidth) {
            when (do_ld_search(w) && stq(i).valid && lcam_st_dep_mask(w)(i)) {
                when (((lcam_mask(w) & write_mask) === lcam_mask(w)) && word_addr_matches(w) && can_forward(w)) {
                    ldst_addr_matches(w)(i) := true.B
                    ldst_forward_matches(w)(i) := true.B
                    dcache.io.lsu.s1_kill(w) := RegNext(dmem_req_fire(w))
                    s1_set_execute(lcam_ldq_idx(w)) := false.B
                } .elsewhen(((lcam_mask(w) & write_mask) =/= 0.U) && word_addr_matches(w)) {
                    ldst_addr_matches(w)(i) := true.B
                    dcache.io.lsu.s1_kill(w) := RegNext(dmem_req_fire(w))
                    s1_set_execute(lcam_ldq_idx(w)) := false.B
                } .elsewhen(s_uop.is_sc) {
                    ldst_addr_matches(w)(i) := true.B
                    dcache.io.lsu.s1_kill(w) := RegNext(dmem_req_fire(w))
                    s1_set_execute(lcam_ldq_idx(w)) := false.B
                }
            }
        }
    }

    // Set execute bit in LDQ
    for (i <- 0 until numLdqEntries) {
        when(s1_set_execute(i)) {
            ldq(i).bits.executed := true.B
        }
    }

    // Find the youngest store which the load is dependent on
    val forwarding_age_logic = Seq.fill(memWidth) {
        Module(new ForwardingAgeLogic(numStqEntries))
    }
    for (w <- 0 until memWidth) {
        forwarding_age_logic(w).io.addr_matches := ldst_addr_matches(w).asUInt
        forwarding_age_logic(w).io.youngest_st_idx := lcam_uop(w).stqIdx
    }
    val forwarding_idx = widthMap(w => forwarding_age_logic(w).io.forwarding_idx)

    // Forward if st-ld forwarding is possible from the writemask and loadmask
    mem_forward_valid := widthMap(w => (
        ldst_forward_matches(w)(forwarding_idx(w)) &&
        !IsKilledByBranch(io.core.brupdate, lcam_uop(w)) &&
        !io.core.exception && !RegNext(io.core.exception)
    ))
    mem_forward_stq_idx := forwarding_idx
    //********?
    // Avoid deadlock with a 1-w LSU prioritizing load wakeups > store commits
    // On a 2W machine, load wakeups and store commits occupy separate pipelines,
    // so only add this logic for 1-w LSU
    if (memWidth == 1) {
        // Wakeups may repeatedly find a st->ld addr conflict and fail to forward,
        // repeated wakeups may block the store from ever committing
        // Disallow load wakeups 1 cycle after this happens to allow the stores to drain
        when(RegNext(ldst_addr_matches(0).reduce(_ || _) && !mem_forward_valid(0))) {
            block_load_wakeup := true.B
        }

        // If stores remain blocked for 15 cycles, block load wakeups to get a store through
        val store_blocked_counter = Reg(UInt(4.W))
        when(will_fire_store_commit(0) || !can_fire_store_commit(0)) {
            store_blocked_counter := 0.U
        }.elsewhen(can_fire_store_commit(0) && !will_fire_store_commit(0)) {
            store_blocked_counter := Mux(store_blocked_counter === 15.U, 15.U, store_blocked_counter + 1.U)
        }
        when(store_blocked_counter === 15.U) {
            block_load_wakeup := true.B
        }
    }

    // detect which loads get marked as failures, but broadcast to the ROB the oldest failing load
    // TODO encapsulate this in an age-based  priority-encoder
    //   val l_idx = AgePriorityEncoder((Vec(Vec.tabulate(numLdqEntries)(i => failed_loads(i) && i.U >= laq_head)
    //   ++ failed_loads)).asUInt)
    val temp_bits = (VecInit(VecInit.tabulate(numLdqEntries)(i =>
        failed_loads(i) && i.U >= ldq_head) ++ failed_loads)).asUInt
    val l_idx = PriorityEncoder(temp_bits)

    // one exception port, but multiple causes!
    // - 1) the incoming store-address finds a faulting load (it is by definition younger)
    // - 2) the incoming load or store address is excepting. It must be older and thus takes precedent.
    val r_xcpt_valid = RegInit(false.B)
    val r_xcpt = Reg(new Exception)

    val ld_xcpt_valid = failed_loads.reduce(_|_)
    val ld_xcpt_uop = ldq(Mux(l_idx >= numLdqEntries.U, l_idx - numLdqEntries.U, l_idx)(ldqAddrSz-1,0)).bits.uop


    val use_tlb_xcpt = (tlb_xcpt_valid && IsOlder(tlb_xcpt_uop.robIdx, ld_xcpt_uop.robIdx, io.core.rob_head_idx)) || !ld_xcpt_valid

    val xcpt_uop = Mux(use_tlb_xcpt, tlb_xcpt_uop, ld_xcpt_uop)

    r_xcpt_valid := (ld_xcpt_valid || tlb_xcpt_valid) &&
                    !io.core.exception &&
                    !IsKilledByBranch(io.core.brupdate, xcpt_uop)
    r_xcpt.uop := xcpt_uop
    r_xcpt.uop.brMask := GetNewBrMask(io.core.brupdate, xcpt_uop)
    r_xcpt.cause := Mux(use_tlb_xcpt, tlb_xcpt_cause, MINI_EXCEPTION_MEM_ORDERING)
    r_xcpt.badvaddr := tlb_xcpt_vaddr // TODO is there another register we can use instead?

    io.core.lsu_xcpt.valid := r_xcpt_valid && !io.core.exception && !IsKilledByBranch(io.core.brupdate, r_xcpt.uop)
    io.core.lsu_xcpt.bits := r_xcpt

    // Task 4: Speculatively wakeup loads 1 cycle before they come back
    for (w <- 0 until memWidth) {
        io.core.spec_ld_wakeup(w).valid := fired_load_incoming(w) && mem_incoming_uop(w).pdst =/= 0.U
        io.core.spec_ld_wakeup(w).bits := mem_incoming_uop(w).pdst
    }


    //-------------------------------------------------------------
    //-------------------------------------------------------------
    // Writeback Cycle (St->Ld Forwarding Path)
    //-------------------------------------------------------------
    //-------------------------------------------------------------

    // Handle Memory Responses and nacks
    //----------------------------------
    for (w <- 0 until memWidth) {
        io.core.exe(w).iresp.valid := false.B
    }

    val dmem_resp_fired = WireInit(widthMap(w => false.B))

    for (w <- 0 until memWidth) {
        // Handle nacks
        when(dcache.io.lsu.nack(w).valid) {
            // We have to re-execute this!
            when(dcache.io.lsu.nack(w).bits.uop.use_ldq) {
                assert(ldq(dcache.io.lsu.nack(w).bits.uop.ldqIdx).bits.executed)

                ldq(dcache.io.lsu.nack(w).bits.uop.ldqIdx).bits.executed := false.B
                nacking_loads(dcache.io.lsu.nack(w).bits.uop.ldqIdx) := true.B
            } .otherwise {
                assert(dcache.io.lsu.nack(w).bits.uop.use_stq)

                when(IsOlder(dcache.io.lsu.nack(w).bits.uop.stqIdx, stq_execute_head, stq_head)|| dcache.io.lsu.nack(w).bits.uop.stqIdx === stq_execute_head) {
                    stq_execute_head := dcache.io.lsu.nack(w).bits.uop.stqIdx
                }
            }
        }
        // Handle the response
        when(dcache.io.lsu.resp(w).valid) {
            when(dcache.io.lsu.resp(w).bits.uop.use_ldq) {
                val ldq_idx = dcache.io.lsu.resp(w).bits.uop.ldqIdx
                val send_iresp = ldq(ldq_idx).bits.uop.dst_rtype === RT_FIX

                io.core.exe(w).iresp.bits.uop := ldq(ldq_idx).bits.uop
                if (!FPGAPlatform)
                    io.core.exe(w).iresp.bits.uop.debug_load_uncacheable := ldq(ldq_idx).bits.is_uncacheable
                io.core.exe(w).iresp.valid := send_iresp
                io.core.exe(w).iresp.bits.data := loadDataGen(
                    ldq(ldq_idx).bits.addr.bits(1,0),
                    dcache.io.lsu.resp(w).bits.data,
                    dcache.io.lsu.resp(w).bits.uop.mem_size,
                    dcache.io.lsu.resp(w).bits.uop.mem_signed
                )

                dmem_resp_fired(w) := true.B

                ldq(ldq_idx).bits.succeeded := io.core.exe(w).iresp.valid
            } .elsewhen(dcache.io.lsu.resp(w).bits.uop.use_stq) {
                stq(dcache.io.lsu.resp(w).bits.uop.stqIdx).bits.succeeded := true.B
                when(dcache.io.lsu.resp(w).bits.uop.is_sc) {
                    dmem_resp_fired(w) := true.B
                    io.core.exe(w).iresp.valid := true.B
                    io.core.exe(w).iresp.bits.uop := stq(dcache.io.lsu.resp(w).bits.uop.stqIdx).bits.uop
                    io.core.exe(w).iresp.bits.data := dcache.io.lsu.resp(w).bits.data
                }
            }
        }


        when(dmem_resp_fired(w) && wb_forward_valid(w)) {
            // Twiddle thumbs. Can't forward because dcache response takes precedence
        } .elsewhen(!dmem_resp_fired(w) && wb_forward_valid(w)) {
            val f_idx = wb_forward_ldq_idx(w)
            val forward_uop = ldq(f_idx).bits.uop
            val stq_e = stq(wb_forward_stq_idx(w))
            val data_ready = stq_e.bits.data.valid
            val live = !IsKilledByBranch(io.core.brupdate, forward_uop)
            val storegen = storeDataGen(
                stq_e.bits.addr.bits(1,0),
                stq_e.bits.data.bits,
                stq_e.bits.uop.mem_size
            )
            val loadgen = loadDataGen(
                wb_forward_ld_addr(w)(1,0),
                storegen,
                forward_uop.mem_size,
                forward_uop.mem_signed
            )

            io.core.exe(w).iresp.valid := (forward_uop.dst_rtype === RT_FIX) && data_ready && live
            io.core.exe(w).iresp.bits.uop := forward_uop
            io.core.exe(w).iresp.bits.data := loadgen

            when(data_ready && live) {
                ldq(f_idx).bits.succeeded := data_ready
                ldq(f_idx).bits.forward_std_val := true.B
                ldq(f_idx).bits.forward_stq_idx := wb_forward_stq_idx(w)
            }
        }
    }

    // Initially assume the speculative load wakeup failed
    io.core.ld_miss := RegNext(io.core.spec_ld_wakeup.map(_.valid).reduce(_||_))
    val spec_ld_succeed = widthMap(w =>
        !RegNext(io.core.spec_ld_wakeup(w).valid) ||
        (io.core.exe(w).iresp.valid && io.core.exe(w).iresp.bits.uop.ldqIdx === RegNext(mem_incoming_uop(w).ldqIdx))
    ).reduce(_&&_)
    when(spec_ld_succeed) {
        io.core.ld_miss := false.B
    }


    //-------------------------------------------------------------
    // Kill speculated entries on branch mispredict
    //-------------------------------------------------------------
    //-------------------------------------------------------------

    // Kill stores
    val st_brkilled_mask = Wire(Vec(numStqEntries, Bool()))
    for (i <- 0 until numStqEntries) {
        st_brkilled_mask(i) := false.B

        when(stq(i).valid) {
            stq(i).bits.uop.brMask := GetNewBrMask(io.core.brupdate, stq(i).bits.uop.brMask) //下一周期才会更新

            when(IsKilledByBranch(io.core.brupdate, stq(i).bits.uop)) {
                stq(i).valid := false.B
                stq(i).bits.addr.valid := false.B
                stq(i).bits.data.valid := false.B
                st_brkilled_mask(i) := true.B
            }
        }

        assert(!(IsKilledByBranch(io.core.brupdate, stq(i).bits.uop) && stq(i).valid && stq(i).bits.committed),
            "Branch is trying to clear a committed store.")
    }

    // Kill loads
    for (i <- 0 until numLdqEntries) {
        when(ldq(i).valid) {
            ldq(i).bits.uop.brMask := GetNewBrMask(io.core.brupdate, ldq(i).bits.uop.brMask)
            when(IsKilledByBranch(io.core.brupdate, ldq(i).bits.uop)) {
                ldq(i).valid := false.B
                ldq(i).bits.addr.valid := false.B
            }
        }
    }

    //-------------------------------------------------------------
    when(io.core.brupdate.b2.mispredict && !io.core.exception) {
        stq_tail := io.core.brupdate.b2.uop.stqIdx
        ldq_tail := io.core.brupdate.b2.uop.ldqIdx
    }

    //-------------------------------------------------------------
    //-------------------------------------------------------------
    // dequeue old entries on commit
    //-------------------------------------------------------------
    //-------------------------------------------------------------

    var temp_stq_commit_head = stq_commit_head
    var temp_ldq_head = ldq_head
    for (w <- 0 until coreWidth) {
        val commit_store = io.core.commit.valids(w) && io.core.commit.uops(w).use_stq
        val commit_load = io.core.commit.valids(w) && io.core.commit.uops(w).use_ldq
        val idx = Mux(commit_store, temp_stq_commit_head, temp_ldq_head)
        when(commit_store) {
            stq(idx).bits.committed := true.B
        }.elsewhen(commit_load) {
            assert(ldq(idx).valid, "[lsu] trying to commit an un-allocated load entry.")
            assert((ldq(idx).bits.executed || ldq(idx).bits.forward_std_val) && ldq(idx).bits.succeeded,
                "[lsu] trying to commit an un-executed load entry.")
            ldq(idx).valid := false.B
            ldq(idx).bits.addr.valid := false.B
            ldq(idx).bits.executed := false.B
            ldq(idx).bits.succeeded := false.B
            ldq(idx).bits.order_fail := false.B
            ldq(idx).bits.forward_std_val := false.B
        }

        temp_stq_commit_head = Mux(commit_store, WrapInc(temp_stq_commit_head, numStqEntries),
                                                 temp_stq_commit_head
        )
        temp_ldq_head = Mux(commit_load, WrapInc(temp_ldq_head, numLdqEntries),
                                         temp_ldq_head
        )
    }
    stq_commit_head := temp_stq_commit_head
    ldq_head := temp_ldq_head

    // try to finish a store instruction
    when (stq(stq_head).valid && stq(stq_head).bits.committed) {
        finish_store := stq(stq_head).bits.succeeded
    }

    when (finish_store) {
        stq(stq_head).valid := false.B
        stq(stq_head).bits.addr.valid := false.B
        stq(stq_head).bits.data.valid := false.B
        stq(stq_head).bits.succeeded  := false.B
        stq(stq_head).bits.committed  := false.B

        stq_head := WrapInc(stq_head, numStqEntries)
    }

    //-------------------------------------------------------------
    // Exception / Reset

    // for the live_store_mask, need to kill stores that haven't been committed
    val st_exc_killed_mask = WireInit(VecInit((0 until numStqEntries).map(x => false.B)))

    when(reset.asBool || io.core.exception) {
        ldq_head := 0.U
        ldq_tail := 0.U

        when(reset.asBool) {
            stq_head := 0.U
            stq_tail := 0.U
            stq_commit_head := 0.U
            stq_execute_head := 0.U

            for (i <- 0 until numStqEntries) {
                stq(i).valid := false.B
                stq(i).bits.addr.valid := false.B
                stq(i).bits.data.valid := false.B
            }
        } .otherwise { // exception
            stq_tail := stq_commit_head

            for (i <- 0 until numStqEntries) {
                when(!stq(i).bits.committed && !stq(i).bits.succeeded) {
                    stq(i).valid := false.B
                    stq(i).bits.addr.valid := false.B
                    stq(i).bits.data.valid := false.B
                    st_exc_killed_mask(i) := true.B
                }
            }
        }

        for (i <- 0 until numLdqEntries) {
            ldq(i).valid := false.B
            ldq(i).bits.addr.valid := false.B
            ldq(i).bits.executed := false.B
        }
    }

    dtlb.io.dtlb_csr_context := io.csr.dtlb_csr_ctx
    dcache.io.lsu.llbit      := io.csr.llbit

    dtlb.io.r_resp           := io.core.tlb_data.r_resp
    io.core.tlb_data.r_req   <> dtlb.io.r_req

    //-------------------------------------------------------------
    // Live Store Mask
    // track a bit-array of stores that are alive
    // (could maybe be re-produced from the stq_head/stq_tail, but need to know include spec_killed entries)

    // TODO is this the most efficient way to compute the live store mask?
    live_store_mask := next_live_store_mask & ~(st_brkilled_mask.asUInt) & ~(st_exc_killed_mask.asUInt)
    val debug_signal = WireInit(0.U(1.W))
    if(!FPGAPlatform)dontTouch(debug_signal)
    when(next_live_store_mask(stq_tail)){
        debug_signal := 1.U
    }
}
