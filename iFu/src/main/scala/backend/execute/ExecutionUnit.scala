package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.frontend.GetPCFromFtqIO

import scala.collection.mutable.ArrayBuffer

abstract class ExecutionUnit (
    val readsIrf         : Boolean       = false,
    val writesIrf        : Boolean       = false,
    val writesMemIrf     : Boolean       = false,
    val bypassable       : Boolean       = false,
    val alwaysBypassable : Boolean       = false,
    val hasMem           : Boolean       = false,
    val hasCSR           : Boolean       = false,
    val hasJmpUnit       : Boolean       = false,
    val hasAlu           : Boolean       = false,
    val hasMul           : Boolean       = false,
    val hasDiv           : Boolean       = false,
    val numStages        : Int
) extends CoreModule {
    val io = IO(new Bundle {
        val fu_types = Output(Bits(FUC_SZ.W))

        val req      = Flipped(new DecoupledIO(new FuncUnitReq))

        val iresp    = if (writesIrf)   new DecoupledIO(new ExeUnitResp) else null
        val mem_iresp = if (writesMemIrf) new DecoupledIO(new ExeUnitResp) else null

        val bypass   = Output(Vec(numStages, Valid(new ExeUnitResp)))
        val brupdate = Input(new BrUpdateInfo)

        val brinfo     = if (hasAlu) Output(new BrResolutionInfo) else null
        val getFtqPc = if (hasJmpUnit) Flipped(new GetPCFromFtqIO) else null
        // val status     = Input(new freechips.rocketchip.rocket.MStatus())

        // only used by the mem unit
        val lsu_io = if (hasMem) Flipped(new LSUExeIO) else null
        // val bp = if (hasMem) Input(Vec(nBreakpoints, new BP)) else null
        // val mcontext = if (hasMem) Input(UInt(coreParams.mcontextWidth.W)) else null
        // val scontext = if (hasMem) Input(UInt(coreParams.scontextWidth.W)) else null
    })
    io <> DontCare
    if (writesIrf) {
        io.iresp.bits.predicated := false.B
        assert(io.iresp.ready)
    }
    if (writesMemIrf) {
        io.mem_iresp.bits.predicated := false.B
    }
    require (bypassable || !alwaysBypassable, "[execute] an execution unit must be bypassable if it is always bypassable")

    def supportedFuncUnits = {
        new SupportedFuncs(
            alu    = hasAlu,
            jmp    = hasJmpUnit,
            mem    = hasMem,
            muldiv = hasMul || hasDiv,
            csr    = hasCSR
            // val cnt: Boolean    = false
            // val tlb: Boolean    = false
        )
    }
}

class ALUExeUnit(
    hasJmpUnit : Boolean = false,
    hasCSR     : Boolean = false,
    hasAlu     : Boolean = true,
    hasMul     : Boolean = false,
    hasDiv     : Boolean = false,
    hasIfpu    : Boolean = false,
    hasMem     : Boolean = false,
    hasRocc    : Boolean = false
) extends ExecutionUnit(
    readsIrf         = true,
    writesIrf        = hasAlu || hasMul || hasDiv,
    writesMemIrf     = hasMem,
    bypassable       = hasAlu,
    alwaysBypassable = hasAlu && !(hasMem || hasJmpUnit || hasMul || hasDiv || hasCSR),
    hasMem           = hasMem,
    hasCSR           = hasCSR,
    hasJmpUnit       = hasJmpUnit,
    hasAlu           = hasAlu,
    hasMul           = hasMul,
    hasDiv           = hasDiv,
    numStages        = if (hasAlu && hasMul) 3 else if (hasAlu) 1 else 0
) {

    val div_busy  = WireInit(false.B)

    val iresp_fu_units = ArrayBuffer[FuncUnit]()

    io.fu_types := Mux(hasAlu.B, FU_ALU, 0.U)              |
                   Mux(hasMul.B, FU_MUL, 0.U)              |
                   Mux(!div_busy && hasDiv.B, FU_DIV, 0.U) |
                   Mux(hasCSR.B, FU_CSR, 0.U)              |
                   Mux(hasJmpUnit.B, FU_JMP, 0.U)          |
                   Mux(hasMem.B, FU_MEM, 0.U)

    // ALU Unit -------------------------------
    var alu: ALUUnit = null
    if (hasAlu) {
        alu = Module(new ALUUnit(
            isJmpUnit = hasJmpUnit,
            numStages = numStages,
        ))
        alu.io.req.valid := (io.req.valid && (
            io.req.bits.uop.fuCode === FU_ALU ||
            io.req.bits.uop.fuCode === FU_JMP ||
            io.req.bits.uop.fuCode === FU_CSR
        ))
        alu.io.req.bits.uop      := io.req.bits.uop
        alu.io.req.bits.kill     := io.req.bits.kill
        alu.io.req.bits.rs1Data  := io.req.bits.rs1Data
        alu.io.req.bits.rs2Data  := io.req.bits.rs2Data
        alu.io.req.bits.predData := io.req.bits.predData
        alu.io.brUpdate          := io.brupdate
        alu.io.resp.ready        := true.B
        io.bypass                := alu.io.bypass
        io.brinfo                := alu.io.brInfo   
        if (hasJmpUnit) { alu.io.getFtqPC <> io.getFtqPc }

        iresp_fu_units += alu
    }

    // Pipelined, IMul Unit ------------------
    var imul: PipelinedMulUnit = null
    if (hasMul) {
        imul = Module(new PipelinedMulUnit)
        imul.io.req <> DontCare
        imul.io.req.valid        := io.req.valid && io.req.bits.uop.fu_code_is(FU_MUL)
        imul.io.req.bits.uop     := io.req.bits.uop
        imul.io.req.bits.rs1Data := io.req.bits.rs1Data
        imul.io.req.bits.rs2Data := io.req.bits.rs2Data
        imul.io.req.bits.kill    := io.req.bits.kill
        imul.io.brUpdate         := io.brupdate
        imul.io.resp.ready       := true.B

        iresp_fu_units += imul
    }

    // Div/Rem Unit -----------------------
    var div: DivUnit = null
    val div_resp_val = WireInit(false.B)
    if (hasDiv) {
        div = Module(new DivUnit)
        div.io.req <> DontCare
        div.io.req.valid        := io.req.valid && io.req.bits.uop.fu_code_is(FU_DIV)
        div.io.req.bits.uop     := io.req.bits.uop
        div.io.req.bits.rs1Data := io.req.bits.rs1Data
        div.io.req.bits.rs2Data := io.req.bits.rs2Data
        div.io.brUpdate         := io.brupdate
        div.io.req.bits.kill    := io.req.bits.kill
        // 不知道会不会死锁...
        div.io.resp.ready := !(iresp_fu_units.map(_.io.resp.valid).reduce(_|_))

        div_resp_val := div.io.resp.valid
        div_busy     := !div.io.req.ready || (io.req.valid && io.req.bits.uop.fu_code_is(FU_DIV))

        iresp_fu_units += div
    }

    // Mem Unit --------------------------
    if (hasMem) {
        require(!hasAlu)
        require(numStages == 0)
        val maddrcalc = Module(new MemAddrCalcUnit)
        maddrcalc.io.req <> DontCare
        maddrcalc.io.req.valid  := io.req.valid && io.req.bits.uop.fu_code_is(FU_MEM)
        maddrcalc.io.req.bits   := io.req.bits
        maddrcalc.io.brUpdate     <> io.brupdate
        // maddrcalc.io.status     := io.status
        // maddrcalc.io.bp         := io.bp
        // maddrcalc.io.mcontext   := io.mcontext
        // maddrcalc.io.scontext   := io.scontext
        maddrcalc.io.resp.ready := true.B

        io.lsu_io.req := maddrcalc.io.resp
        io.mem_iresp <> io.lsu_io.iresp
    }

    // Outputs (Write Port #0)  ---------------
    if (writesIrf) {
        io.iresp.valid     := iresp_fu_units.map(_.io.resp.valid).reduce(_|_)
        io.iresp.bits.uop  := PriorityMux(iresp_fu_units.map(f =>
            (f.io.resp.valid, f.io.resp.bits.uop)).toSeq
        )
        io.iresp.bits.data := PriorityMux(iresp_fu_units.map(f =>
            (f.io.resp.valid, f.io.resp.bits.data)).toSeq
        )
        io.iresp.bits.predicated := PriorityMux(iresp_fu_units.map(f =>
            (f.io.resp.valid, f.io.resp.bits.predicated)).toSeq
        )

         if (hasAlu) {
             io.iresp.bits.uop.csrAddr := ImmGen(alu.io.resp.bits.uop.imm_packed, IS_I).asUInt
             io.iresp.bits.uop.ctrl.csr_cmd := alu.io.resp.bits.uop.ctrl.csr_cmd
             io.iresp.bits.rj := alu.io.resp.bits.rj
             io.iresp.bits.rd := alu.io.resp.bits.rd
         }
    }
    assert ((PopCount(iresp_fu_units.map(_.io.resp.valid)) <= 1.U && !div_resp_val) ||
            (PopCount(iresp_fu_units.map(_.io.resp.valid)) <= 2.U && (div_resp_val)),
        "Multiple functional units are fighting over the write port.")
}
