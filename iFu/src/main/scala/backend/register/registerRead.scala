package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.util._

class RegisterRead (
    issueWidth: Int,
    supportedUnitsArray: Seq[SupportedFuncs],
    numTotalReadPorts: Int,
    numReadPortsArray: Seq[Int],
    numTotalBypassPorts: Int,
    numTotalPredBypassPorts: Int,
    registerWidth: Int
) extends CoreModule {
    val io = IO(new Bundle{
        val iss_valids = Input(Vec(issueWidth, Bool()))
        val iss_uops   = Input(Vec(issueWidth, new MicroOp))

        val rf_read_ports  = Flipped(Vec(numTotalReadPorts, new RegisterFileReadPortIO(pregSz, registerWidth)))
        val prf_read_ports = Flipped(Vec(issueWidth, new RegisterFileReadPortIO(log2Ceil(frontendParams.numFTQEntries), 1)))

        val bypass      = Input(Vec(numTotalBypassPorts, Valid(new ExeUnitResp(registerWidth))))
        val pred_bypass = Input(Vec(numTotalPredBypassPorts, Valid(new ExeUnitResp(1))))

        val exe_reqs = Vec(issueWidth, Decoupled(new FuncUnitReq))

        val kill     = Input(Bool())
        val brupdate = Input(new BrUpdateInfo())
    })
    io.exe_reqs.map(_.valid := DontCare)
    io.exe_reqs.map(_.bits  := DontCare)

    val rrd_valids = Reg(Vec(issueWidth, Bool()))
    val rrd_uops   = Reg(Vec(issueWidth, new MicroOp))

    for (w <- 0 until issueWidth) {
        val rrdDecodeUnit = Module(new RegisterReadDecode(supportedUnitsArray(w)))
        rrdDecodeUnit.io.iss_valid := io.iss_valids(w)
        rrdDecodeUnit.io.iss_uop   := io.iss_uops(w)

        rrd_valids(w) := (
            rrdDecodeUnit.io.rrd_valid &&
            !IsKilledByBranch(io.brupdate,rrdDecodeUnit.io.rrd_uop)
        )
        rrd_uops(w) := (
            GetNewUopAndBrMask(rrdDecodeUnit.io.rrd_uop, io.brupdate)
        )
    }

    val exe_req_valids = RegInit(VecInit(Seq.fill(issueWidth){ false.B }))
    val exe_req_uops   = Reg(Vec(issueWidth, new MicroOp))
    val exe_req_rs1    = Reg(Vec(issueWidth, Bits(registerWidth.W)))
    val exe_req_rs2    = Reg(Vec(issueWidth, Bits(registerWidth.W)))
    val exe_req_pred   = Reg(Vec(issueWidth, Bool()))

    val rrd_rs1  = Wire(Vec(issueWidth, Bits(registerWidth.W)))
    val rrd_rs2  = Wire(Vec(issueWidth, Bits(registerWidth.W)))
    val rrd_pred = Wire(Vec(issueWidth, Bool()))

    rrd_rs1  := DontCare
    rrd_rs2  := DontCare
    rrd_pred := DontCare

    io.prf_read_ports := DontCare

    var idx = 0
    for (w <- 0 until issueWidth) {
        val numReadPorts = numReadPortsArray(w)

        val rs1_addr  = io.iss_uops(w).prs1
        val rs2_addr  = io.iss_uops(w).prs2
        val pred_addr = io.iss_uops(w).ppred

        // clock 1: send read request to register file
        if (numReadPorts > 0) io.rf_read_ports(idx + 0).addr := rs1_addr
        if (numReadPorts > 1) io.rf_read_ports(idx + 1).addr := rs2_addr
        if (enableSFBOpt    ) io.prf_read_ports(w).addr      := pred_addr

        // clock 2: read data from register file
        if (numReadPorts > 0) rrd_rs1(w) := Mux(
            RegNext(rs1_addr === 0.U), 0.U, io.rf_read_ports(idx + 0).data
        )
        if (numReadPorts > 1) rrd_rs2(w) := Mux(
            RegNext(rs2_addr === 0.U), 0.U, io.rf_read_ports(idx + 1).data
        )
        if (enableSFBOpt) rrd_pred(w) := Mux(
            RegNext(io.iss_uops(w).is_sfb_shadow), io.prf_read_ports(w).data, false.B
        )

        val killed = io.kill || IsKilledByBranch(io.brupdate, rrd_uops(w))

        exe_req_valids(w)      := Mux(killed, false.B, rrd_valids(w))
        exe_req_uops(w)        := Mux(killed, NullMicroOp,  rrd_uops(w))
        exe_req_uops(w).brMask := GetNewBrMask(io.brupdate, rrd_uops(w))

        idx += numReadPorts
    }

    val bypassed_rs1  = Wire(Vec(issueWidth, Bits(registerWidth.W)))
    val bypassed_rs2  = Wire(Vec(issueWidth, Bits(registerWidth.W)))
    val bypassed_pred = Wire(Vec(issueWidth, Bool()))

    bypassed_pred := DontCare

    for (w <- 0 until issueWidth) {
        val numReadPorts = numReadPortsArray(w)

        var rs1_cases  = Seq((false.B, 0.U(registerWidth.W)))
        var rs2_cases  = Seq((false.B, 0.U(registerWidth.W)))
        var pred_cases = Seq((false.B, 0.U(1.W)))

        val prs1      = rrd_uops(w).prs1
        val lrs1Rtype = rrd_uops(w).lrs1_rtype
        val prs2      = rrd_uops(w).prs2
        val lrs2Rtype = rrd_uops(w).lrs2_rtype
        val ppred     = rrd_uops(w).ppred

        for (b <- 0 until numTotalBypassPorts) {
            val bypass = io.bypass(b)
            rs1_cases ++= Seq((
                bypass.valid && (prs1 === bypass.bits.uop.pdst) && bypass.bits.uop.rf_wen
                && bypass.bits.uop.dst_rtype === RT_FIX && lrs1Rtype === RT_FIX && (prs1 =/= 0.U),
                bypass.bits.data
            ))
            rs2_cases ++= Seq((
                bypass.valid && (prs2 === bypass.bits.uop.pdst) && bypass.bits.uop.rf_wen 
                && bypass.bits.uop.dst_rtype === RT_FIX && lrs2Rtype === RT_FIX && (prs2 =/= 0.U),
                bypass.bits.data
            ))
        }
        for (b <- 0 until numTotalPredBypassPorts) {
            val bypass = io.pred_bypass(b)
            pred_cases ++= Seq((
                bypass.valid && (ppred === bypass.bits.uop.pdst) && bypass.bits.uop.is_sfb_br,
                bypass.bits.data
            ))
        }

        if (numReadPorts > 0) bypassed_rs1(w)  := MuxCase(rrd_rs1(w) , rs1_cases)
        if (numReadPorts > 1) bypassed_rs2(w)  := MuxCase(rrd_rs2(w) , rs2_cases)
        if (enableSFBOpt    ) bypassed_pred(w) := MuxCase(rrd_pred(w), pred_cases)
    }

    for (w <- 0 until issueWidth) {
        val numReadPorts = numReadPortsArray(w)

        if (enableSFBOpt)     exe_req_pred(w) := bypassed_pred(w)
        if (numReadPorts > 0) exe_req_rs1(w)  := bypassed_rs1(w)
        if (numReadPorts > 1) exe_req_rs2(w)  := bypassed_rs2(w)
    }

    for (w <- 0 until issueWidth) {
        val numReadPorts = numReadPortsArray(w)

        io.exe_reqs(w).valid    := exe_req_valids(w)
        io.exe_reqs(w).bits.uop := exe_req_uops(w)
        if (numReadPorts > 0) io.exe_reqs(w).bits.rs1Data  := exe_req_rs1(w)
        if (numReadPorts > 1) io.exe_reqs(w).bits.rs2Data  := exe_req_rs2(w)
        if (enableSFBOpt    ) io.exe_reqs(w).bits.predData := exe_req_pred(w)
    }
}
