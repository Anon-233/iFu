package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.util._
import iFu.common.Consts._

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
        val iss_valids = Input(Vec(issueWidth,Bool()))
        val iss_uops = Input(Vec(issueWidth,new MicroOp()))

        val rf_read_ports = Flipped(Vec(numTotalReadPorts,new RegisterFileReadPortIO(pregSz,registerWidth)))
        val prf_read_ports = Flipped(Vec(issueWidth,new RegisterFileReadPortIO(log2Ceil(frontendParams.numFTQEntries), 1)))

        val bypass = Input(Vec(numTotalBypassPorts,Valid(new ExeUnitResp(registerWidth))))
        val pred_bypass = Input(Vec(numTotalPredBypassPorts,Valid(new ExeUnitResp(1))))

        val exe_reqs = Vec(issueWidth,(new DecoupledIO(new FuncUnitReq)))

        val kill = Input(Bool())
        val brupdate = Input(new BrUpdateInfo())
    })
    io <> DontCare

    val rrdValid = Wire(Vec(issueWidth,Bool()))
    val rrdUops = Wire(Vec(issueWidth,new MicroOp()))

    val exeRegValids   = RegInit(VecInit(Seq.fill(issueWidth){false.B}))
    val exeRegUops     = Reg(Vec(issueWidth, new MicroOp()))
    val exeRegPredData = Reg(Vec(issueWidth, Bool()))
    val exeRegRs1Data  = Reg(Vec(issueWidth, Bits(registerWidth.W)))
    val exeRegRs2Data  = Reg(Vec(issueWidth, Bits(registerWidth.W)))

    for (w <- 0 until issueWidth) {
        val rrdDecodeUnit = Module(new RegisterReadDecode(supportedUnitsArray(w)))
        rrdDecodeUnit.io.iss_valid := io.iss_valids(w)
        rrdDecodeUnit.io.iss_uop   := io.iss_uops(w)

        rrdValid(w) := RegNext(
            rrdDecodeUnit.io.rrd_valid &&
            !IsKilledByBranch(io.brupdate,rrdDecodeUnit.io.rrd_uop)
        )
        rrdUops(w) := RegNext(
            GetNewUopAndBrMask(rrdDecodeUnit.io.rrd_uop,io.brupdate)
        )
    }

    val rrdPredData = Wire(Vec(issueWidth,Bool()))
    val rrdRs1Data  = Wire(Vec(issueWidth,Bits(registerWidth.W)))
    val rrdRs2Data  = Wire(Vec(issueWidth,Bits(registerWidth.W)))

    rrdPredData := DontCare
    rrdRs1Data  := DontCare
    rrdRs2Data  := DontCare

    io.prf_read_ports := DontCare

    var idx = 0
    for (w <-0 until issueWidth) {
        val numReadPorts = numReadPortsArray(w)

        val predAddr = io.iss_uops(w).ppred
        val rs1Addr = io.iss_uops(w).prs1
        val rs2Addr = io.iss_uops(w).prs2

        if(enableSFBOpt)     io.prf_read_ports(w).addr := predAddr
        if(numReadPorts > 0) io.rf_read_ports(idx + 0).addr := rs1Addr
        if(numReadPorts > 1) io.rf_read_ports(idx + 1).addr := rs2Addr

        if (enableSFBOpt) rrdPredData(w) := Mux(
            RegNext(io.iss_uops(w).is_sfb_shadow), io.prf_read_ports(w).data, false.B
        )
        if (numReadPorts > 0) rrdRs1Data(w) := Mux(
            RegNext(rs1Addr === 0.U), 0.U, io.rf_read_ports(idx+0).data
        )
        if (numReadPorts > 1) rrdRs2Data(w) := Mux(
            RegNext(rs2Addr === 0.U), 0.U, io.rf_read_ports(idx+1).data
        )

        val rrdKill = io.kill || IsKilledByBranch(io.brupdate, rrdUops(w))

        exeRegValids(w)      := Mux(rrdKill, false.B, rrdValid(w))
        exeRegUops(w)        := Mux(rrdKill, NullMicroOp, rrdUops(w))
        exeRegUops(w).brMask := GetNewBrMask(io.brupdate, rrdUops(w))

        idx += numReadPorts
    }

    val bypassedPredData = Wire(Vec(issueWidth, Bool()))
    val bypassedRs1Data  = Wire(Vec(issueWidth, Bits(registerWidth.W)))
    val bypassedRs2Data  = Wire(Vec(issueWidth, Bits(registerWidth.W)))

    bypassedPredData := DontCare

    for (w <- 0 until issueWidth) {
        val numReadPorts = numReadPortsArray(w)

        var predCases = Seq((false.B, 0.U(1.W)))
        var rs1Cases  = Seq((false.B, 0.U(registerWidth.W)))
        var rs2Cases  = Seq((false.B, 0.U(registerWidth.W)))
        
        val ppred = rrdUops(w).ppred
        val prs1 = rrdUops(w).prs1
        val lrs1Rtype = rrdUops(w).lrs1_rtype
        val prs2 = rrdUops(w).prs2
        val lrs2Rtype = rrdUops(w).lrs2_rtype

        for (b <- 0 until numTotalPredBypassPorts) {
            val bypass = io.pred_bypass(b)

            predCases ++= Seq((
                bypass.valid && (ppred === bypass.bits.uop.pdst) && bypass.bits.uop.is_sfb_br,
                bypass.bits.data
            ))
        }

        for (b <- 0 until numTotalBypassPorts) {
            val bypass = io.bypass(b)

            rs1Cases ++= Seq((
                bypass.valid && (prs1 === bypass.bits.uop.pdst) && bypass.bits.uop.rf_wen
                && bypass.bits.uop.dst_rtype === RT_FIX && lrs1Rtype === RT_FIX && (prs1 =/= 0.U),
                bypass.bits.data
            ))
            rs2Cases ++= Seq((
                bypass.valid && (prs2 === bypass.bits.uop.pdst) && bypass.bits.uop.rf_wen 
                && bypass.bits.uop.dst_rtype === RT_FIX && lrs2Rtype === RT_FIX && (prs2 =/= 0.U),
                bypass.bits.data
            ))
        }

        if (enableSFBOpt)     bypassedPredData(w) := MuxCase(rrdPredData(w), predCases) 
        if (numReadPorts > 0) bypassedRs1Data(w)  := MuxCase(rrdRs1Data(w), rs1Cases)
        if (numReadPorts > 1) bypassedRs2Data(w)  := MuxCase(rrdRs2Data(w), rs2Cases)
    }

    for (w <- 0 until issueWidth) {
        val numReadPorts = numReadPortsArray(w)

        if (enableSFBOpt)     exeRegPredData(w) := bypassedPredData(w)
        if (numReadPorts > 0) exeRegRs1Data(w)  := bypassedRs1Data(w)
        if (numReadPorts > 1) exeRegRs2Data(w)  := bypassedRs2Data(w)
    }

    for (w <- 0 until issueWidth) {
        val numReadPorts = numReadPortsArray(w)

        io.exe_reqs(w).valid    := exeRegValids(w)
        io.exe_reqs(w).bits.uop := exeRegUops(w)

        if(enableSFBOpt) io.exe_reqs(w).bits.predData := exeRegPredData(w)
        if (numReadPorts > 0) io.exe_reqs(w).bits.rs1Data := exeRegRs1Data(w)
        if (numReadPorts > 1) io.exe_reqs(w).bits.rs2Data := exeRegRs2Data(w)
    }
}