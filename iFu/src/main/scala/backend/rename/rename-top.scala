package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.util._

//TODO: move指令优化

abstract class AbsRenameStage (
    plWidth: Int,
    numPhysRegs: Int,
    numWbPorts: Int
) extends CoreModule {
    val io = IO(new Bundle{
        val ren_stalls = Output(Vec(plWidth, Bool())) //流水线暂停

        val kill = Input(Bool())  //中止信号 
        //从decode输入的信息
        val dec_fire = Input(Vec(plWidth, Bool())) // will commit state updates
        val dec_uops = Input(Vec(plWidth, new MicroOp))  //译码级输出的微指令
        //rename阶段输出的信息
        val ren2_mask = Output(Vec(plWidth, Bool())) // mask of valid instructions
        val ren2_uops = Output(Vec(plWidth, new MicroOp))  //输出的微指令
        //从execute阶段输入的分支指令信息
        val brupdate = Input(new BrUpdateInfo)
        //从dispatch阶段输入的信息
        val dis_fire  = Input(Vec(coreWidth, Bool())) //派遣级各支完成指令派遣的信号
        val dis_ready = Input(Bool())  //派遣级可以接收数据的ready信号

        val wakeups = Flipped(Vec(numWbPorts, Valid(new ExeUnitResp)))
        //从commit阶段输入的信息
        val com_valids = Input(Vec(plWidth, Bool()))
        val com_uops   = Input(Vec(plWidth, new MicroOp))
        val rbk_valids = Input(Vec(plWidth, Bool()))
        val rollback   = Input(Bool())
    })

    //as we said in maptable and busytable,we will solve bypass promblem in this file
    def DoBypass(uop:MicroOp,older:Seq[MicroOp],allocReqs:Seq[Bool]): MicroOp

    val ren1Fire = Wire(Vec(plWidth, Bool()))
    val ren1Uops = Wire(Vec(plWidth, new MicroOp))

    val ren2Fire = io.dis_fire
    val ren2Ready = io.dis_ready
    val ren2Valids = Wire(Vec(plWidth, Bool()))
    val ren2Uops = Wire(Vec(plWidth, new MicroOp))
    val ren2AllocReqs = Wire(Vec(plWidth, Bool()))

    for (w <-0 until plWidth) {
        ren1Fire(w) := io.dec_fire(w)
        ren1Uops(w) := io.dec_uops(w)
    }

    for (w <- 0 until plWidth) {
        val rValid = RegInit(false.B)
        val rUop = Reg(new MicroOp)
        val nextUop = Wire(new MicroOp)

        nextUop := rUop
        //if kill
        when(io.kill){
            rValid := false.B
        } .elsewhen (ren2Ready) {
            rValid := ren1Fire(w)
            //kill 信号无效，派遣级准备好接受新的微指令时，r_valid 与译码级的输入的指令有效信号(ren1_fire) 保持一致，并将 next_uop 置为 decode 阶段输入的微指令 (ren1_uop)
            nextUop := ren1Uops(w)
        } .otherwise { ////派遣级没准备好接受新的微指令，若前一条指令已经完成派遣，r_valid信号置0，next_uop保持
            rValid  := rValid && !ren2Fire(w)
            nextUop := rUop
        }

        rUop := GetNewUopAndBrMask(DoBypass(nextUop, ren2Uops, ren2AllocReqs), io.brupdate)

        ren2Valids(w) := rValid
        ren2Uops(w) := rUop
    }
    io.ren2_mask := ren2Valids
}

class RenameStage (
    plWidth : Int,
    numPhysRegs: Int,
    numWbPorts: Int
) extends  AbsRenameStage(plWidth, numPhysRegs, numWbPorts) {
    val pregSize = log2Ceil(numPhysRegs)
    //转发逻辑，避免数据冒险
    def DoBypass(uop:MicroOp, older:Seq[MicroOp], allocReqs:Seq[Bool]): MicroOp = {
        val bypassedUop = Wire(new MicroOp)
        bypassedUop := uop

        //check if bypassing is possible
        val bypassHitRs1 = (older zip allocReqs) map {case (r,a) => a && r.ldst === uop.lrs1}
        val bypassHitRs2 = (older zip allocReqs) map {case (r,a) => a && r.ldst === uop.lrs2}
        val bypassHitDst = (older zip allocReqs) map {case (r,a) => a && r.ldst === uop.ldst}

        //select the data to bypass
        val bypassSelRs1 = PriorityEncoderOH(bypassHitRs1.reverse).reverse
        val bypassSelRs2 = PriorityEncoderOH(bypassHitRs2.reverse).reverse
        val bypassSelDst = PriorityEncoderOH(bypassHitDst.reverse).reverse

        //check if we need to bypass  
        val doBypassRs1 = bypassHitRs1.reduce(_||_)
        val doBypassRs2 = bypassHitRs2.reduce(_||_)
        val doBypassDst = bypassHitDst.reduce(_||_)

        val bypassPdsts = older.map(_.pdst)

        when (doBypassRs1) { bypassedUop.prs1 := Mux1H(bypassSelRs1, bypassPdsts) }
        when (doBypassRs2) { bypassedUop.prs2 := Mux1H(bypassSelRs2, bypassPdsts) }
        when (doBypassDst) { bypassedUop.stale_pdst := Mux1H(bypassSelDst, bypassPdsts) }

        bypassedUop.prs1_busy := uop.prs1_busy || doBypassRs1
        bypassedUop.prs2_busy := uop.prs2_busy || doBypassRs2

        bypassedUop
    }

    //实例化模块
    val maptable = Module(new RenameMapTable(
        plWidth,
        32,
        numPhysRegs
    ))

    val freelist = Module(new FreeList(
        plWidth,
        numPhysRegs,
        31
    ))

    val busytable = Module(new BusyTable(
        plWidth,
        numPhysRegs,
        numWbPorts
    ))

    val ren2BrTags = Wire(Vec(plWidth, Valid(UInt(brTagSz.W))))

    val comValids = Wire(Vec(plWidth,Bool()))
    val rbkValids = Wire(Vec(plWidth,Bool()))

    for (w <- 0 until plWidth) {
        ren2AllocReqs(w) := ren2Uops(w).ldst_val && ren2Uops(w).dst_rtype === RT_FIX && ren2Fire(w)
        ren2BrTags(w).valid := ren2Fire(w) && ren2Uops(w).allocate_brtag
        ren2BrTags(w).bits  := ren2Uops(w).brTag
        comValids(w) := io.com_uops(w).ldst_val && io.com_uops(w).dst_rtype === RT_FIX && io.com_valids(w)
        rbkValids(w) := io.com_uops(w).ldst_val && io.com_uops(w).dst_rtype === RT_FIX && io.rbk_valids(w)
    }

    //-------------------RenameTable-------------------

    //inputs
    val mapReqs = Wire(Vec(plWidth, new MaptableReq(lregSz)))
    val remapReqs = Wire(Vec(plWidth, new ReMapReq(lregSz, pregSize)))

    for ((((ren1, ren2), com), w) <- (ren1Uops zip ren2Uops zip io.com_uops.reverse).zipWithIndex) {
        mapReqs(w).lrs1 := ren1.lrs1
        mapReqs(w).lrs2 := ren1.lrs2
        mapReqs(w).ldst := ren1.ldst //读stale_pdst

        remapReqs(w).ldst := Mux(io.rollback, com.ldst, ren2.ldst)
        remapReqs(w).pdst := Mux(io.rollback, com.stale_pdst, ren2.pdst)
    }

    ren2AllocReqs zip rbkValids.reverse zip remapReqs map {
        case((a, r), rr) => rr.valid := a || r
    }

    maptable.io.map_reqs := mapReqs
    maptable.io.remap_reqs := remapReqs
    maptable.io.ren_br_tags := ren2BrTags
    maptable.io.brupdate := io.brupdate
    maptable.io.rollback := io.rollback

    //outputs
    for ((uop, w) <- ren1Uops.zipWithIndex) {
        val mappings = maptable.io.map_resps(w)

        uop.prs1 := mappings.prs1
        uop.prs2 := mappings.prs2
        uop.stale_pdst := mappings.stale_pdst
    }

    //---------------------------freelist------------------------------

    freelist.io.reqs := ren2AllocReqs
    freelist.io.dealloc_pregs zip comValids zip rbkValids map {
        case ((d, c), r) => d.valid := c || r
    }
    freelist.io.dealloc_pregs zip io.com_uops map {
        case(d, c) => d.bits := Mux(io.rollback, c.pdst, c.stale_pdst)
    }
    freelist.io.ren_br_tags := ren2BrTags
    freelist.io.brupdate := io.brupdate

    //outputs
    for ((uop, w) <- ren2Uops.zipWithIndex) {
        val preg = freelist.io.alloc_pregs(w).bits
        uop.pdst := Mux(uop.ldst =/= 0.U, preg, 0.U)
    }

    //---------------------------busytable------------------------------

    busytable.io.ren_uops := ren2Uops
    busytable.io.rebusy_reqs := ren2AllocReqs
    busytable.io.wakeup_valids := io.wakeups.map(_.valid)
    busytable.io.wakeup_pdsts := io.wakeups.map(_.bits.uop.pdst)

    //outputs
    for ((uop, w) <- ren2Uops.zipWithIndex) {
        val busy = busytable.io.busy_resps(w)

        uop.prs1_busy := uop.lrs1_rtype === RT_FIX && busy.prs1_busy
        uop.prs2_busy := uop.lrs2_rtype === RT_FIX && busy.prs2_busy
    }

    //---------------------------outputs------------------------------
    for (w <- 0 until plWidth) {
        val canAllocate = freelist.io.alloc_pregs(w).valid

        io.ren_stalls(w) := (ren2Uops(w).dst_rtype === RT_FIX) && !canAllocate

        val bypassedUop = Wire(new MicroOp)

        //当w为0时不需要转发 不会有冲突
        if (w > 0) {
            bypassedUop := DoBypass(ren2Uops(w), ren2Uops.slice(0,w), ren2AllocReqs.slice(0,w))
        } else {
            bypassedUop := ren2Uops(w)
        }

        io.ren2_uops(w) := GetNewUopAndBrMask(bypassedUop,io.brupdate)
    }
}

//-------------------SFB优化-------------------------

class PredRenameStage (
    plWidth : Int,
    numPhysRegs : Int,
    numWbPorts: Int
) extends AbsRenameStage(plWidth, numPhysRegs, numWbPorts) {

    val numFTQEntries = frontendParams.numFTQEntries
    def DoBypass(uop: MicroOp, older: Seq[MicroOp], allocReqs: Seq[Bool]): MicroOp = { uop }

    ren2AllocReqs := DontCare

    val busyTable = RegInit(VecInit(0.U(numFTQEntries.W).asBools))
    val toBusy = WireInit(VecInit(0.U(numFTQEntries.W).asBools))
    val unbusy = WireInit(VecInit(0.U(numFTQEntries.W).asBools))

    val currentFtqIdx = Reg(UInt(log2Ceil(numFTQEntries).W))
    var nextFtqIdx = currentFtqIdx

    for(w <- 0 until plWidth){
        io.ren2_uops(w) := ren2Uops(w)

        val isSfbBr = ren2Uops(w).is_sfb_br && ren2Fire(w)
        val isSfbShadow = ren2Uops(w).is_sfb_shadow && ren2Fire(w)

        val ftqIdx = ren2Uops(w).ftqIdx
        when(isSfbBr){
            io.ren2_uops(w).pdst := ftqIdx
            toBusy(ftqIdx) := true.B
        }
        nextFtqIdx = Mux(isSfbBr, ftqIdx, nextFtqIdx)

        when (isSfbShadow) {
            io.ren2_uops(w).ppred := nextFtqIdx
            io.ren2_uops(w).ppred_busy := (busyTable(nextFtqIdx) || toBusy(nextFtqIdx)) && !unbusy(nextFtqIdx)
        }
    }

    for(w <- 0 until numWbPorts){
        when(io.wakeups(w).valid){
            val pdst = io.wakeups(w).bits.uop.pdst
            unbusy(pdst) := true.B
        }
    }

    currentFtqIdx := nextFtqIdx

    busyTable := ((busyTable.asUInt | toBusy.asUInt) & ~unbusy.asUInt).asBools
}
