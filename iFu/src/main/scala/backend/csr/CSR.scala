package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.common.CauseCode._

class CRMD extends CoreBundle {
    val r0 = UInt(23.W)
    val datm = UInt(2.W)
    val datf = UInt(2.W)
    val pg = UInt(1.W)
    val da = UInt(1.W)
    val ie = UInt(1.W)
    val plv = UInt(2.W)
}

class PRMD extends CoreBundle{
    val r0 = UInt(29.W)
    val pie = UInt(1.W)
    val pplv = UInt(2.W)
}

class EUEN extends CoreBundle{
    val r0 = UInt(31.W)
    val fpe = UInt(1.W)
}

// class ECFG extends CoreBundle{
//     val r0 = UInt(19.W)
//     val lie12_11 = UInt(2.W)
//     val r1 = UInt(1.W)
//     val lie9_0 = UInt(10.W)
// }

class ESTAT extends CoreBundle{
    val r0 = UInt(1.W)
    val esubcode = UInt(9.W)
    val ecode = UInt(6.W)
    val r1 = UInt(3.W)
    val is_12 = UInt(1.W)
    val is_11 = UInt(1.W)
    val r2 = UInt(1.W)
    val is9_2 = UInt(8.W)
    val is1_0 = UInt(2.W)
}

class TLBIDX extends CoreBundle{
    val ne = UInt(1.W)
    val r0 = UInt(1.W)
    val ps = UInt(6.W)
    val r1 = UInt(8.W)
    val r = UInt(TLBIDX_r.W)
    val index = UInt(TLBIDX_INDEX.W)
}

class TLBEHI extends CoreBundle{
    val vppn = UInt(19.W)
    val r0 = UInt(13.W)
}

class TLBELO extends CoreBundle{
    val r = UInt(TLBELO_r.W)
    val ppn = UInt(TLBELO_ppn.W)
    val r0 = UInt(1.W)
    val g = UInt(1.W)
    val mat = UInt(2.W)
    val plv = UInt(2.W)
    val d = UInt(1.W)
    val v = UInt(1.W)
}

class TCFG extends CoreBundle{
    val initval = UInt(TCFG_initval.W)
    val periodic = UInt(1.W)
    val en = UInt(1.W)
}

class TVAL extends CoreBundle{
    val timeval = UInt(TIMER_LENGTH.W)
}

class ASID extends CoreBundle{
    val r0 = UInt(8.W)
    val asidbits = UInt(8.W)
    val r1 = UInt(6.W)
    val asid = UInt(10.W)
}

class DMW extends CoreBundle{
    val vseg = UInt(3.W)
    val r0 = UInt(1.W)
    val pseg = UInt(3.W)
    val r1 = UInt(19.W)
    val mat = UInt(2.W)
    val plv3 = UInt(1.W)
    val r2 = UInt(2.W)
    val plv0 = UInt(1.W)
}


class CSRReg extends CoreBundle{
    val crmd = new CRMD
    val prmd = new PRMD
    val euen = new EUEN
    val ecfg = UInt(32.W)
    val estat = new ESTAT
    val era = UInt(32.W)
    val badv = UInt(32.W)
    val eentry = UInt(32.W)
    val tlbidx = new TLBIDX
    val tlbehi = new TLBEHI
    val tlbelo0 = new TLBELO
    val tlbelo1 = new TLBELO
    val asid = new ASID
    val pgdl = UInt(32.W)
    val pgdh = UInt(32.W)
    val pgd = UInt(32.W)
    val cpuid = UInt(32.W)
    val save0 = UInt(32.W)
    val save1 = UInt(32.W)
    val save2 = UInt(32.W)
    val save3 = UInt(32.W)
    val tid = UInt(32.W)
    val tcfg = new TCFG
    val tval = new TVAL
    val ticlr = UInt(32.W)
    val llbctl = Vec(32, Bool())
    val tlbrentry = UInt(32.W)
    val ctag = UInt(32.W)
    val dmw0 = new DMW
    val dmw1 = new DMW
}

class CSRFile extends CoreModule {
    val io = IO(new Bundle{
        val ext_int = Input(UInt(8.W))

        val addr  = Input(UInt(14.W))
        val read_data  = Output(UInt(xLen.W))

        val rd = Input(UInt(xLen.W))
        val rj = Input(UInt(xLen.W))

        val exception = Input(Bool())   // from rob -> valid
        val com_xcpt  = Input(Valid(new CommitExceptionSignals)) // from rob -> bits
        // val vaddr     = Input(UInt(vaddrBits.W))  //vaddr == badvaddr?
        // val is_llw  = Input(Bool())
        // val is_scw  = Input(Bool())

        val in_pc  = Input(UInt(32.W))
        val csr_pc = Output(UInt(32.W))

        val interrupt = Output(Bool())

        val cmd = Input(UInt(CSR_SZ.W))
        val exevalid = Input(Bool())

        val reg = Output(new CSRReg)
    })

    val wen = io.exevalid && (io.cmd === CSR_W || io.cmd === CSR_M)
    val write_data = Mux(io.cmd === CSR_W,
        io.rd,
        (io.rd & io.rj) | (io.read_data & ~io.rj)
    )

    val csrRst = WireInit(0.U.asTypeOf(new CSRReg))
    csrRst.crmd.da := 1.U(1.W);
    csrRst.asid.asidbits := 0xa.U(8.W)

    val csrRegNxt = Wire(new CSRReg)
    val csrReg    = RegNext(csrRegNxt, init = csrRst)

    io.reg := csrReg
    
    // a?
    val trint = csrReg.estat.is_11 & csrReg.ecfg(11)
    val exint = (csrReg.estat.is9_2 & csrReg.ecfg(9,2)).asUInt.orR
    val swint = (csrReg.estat.is1_0 & csrReg.ecfg(1,0)).asUInt.orR

    io.interrupt := (trint | exint | swint) & csrReg.crmd.ie

    when      (io.addr === CSR_CRMD)         {io.read_data := csrReg.crmd.asUInt}
    .elsewhen (io.addr === CSR_PRMD)    {io.read_data := csrReg.prmd.asUInt}
    .elsewhen (io.addr === CSR_EUEN)    {io.read_data := csrReg.euen.asUInt}
    .elsewhen (io.addr === CSR_ECFG)    {io.read_data := csrReg.ecfg}
    .elsewhen (io.addr === CSR_ESTAT)   {io.read_data := csrReg.estat.asUInt}
    .elsewhen (io.addr === CSR_ERA)     {io.read_data := csrReg.era}
    .elsewhen (io.addr === CSR_BADV)    {io.read_data := csrReg.badv}
    .elsewhen (io.addr === CSR_EENTRY)  {io.read_data := csrReg.eentry}
    .elsewhen (io.addr === CSR_TLBIDX)  {io.read_data := csrReg.tlbidx.asUInt}
    .elsewhen (io.addr === CSR_TLBEHI)  {io.read_data := csrReg.tlbehi.asUInt}
    .elsewhen (io.addr === CSR_TLBELO0) {io.read_data := csrReg.tlbelo0.asUInt}
    .elsewhen (io.addr === CSR_TLBELO1) {io.read_data := csrReg.tlbelo1.asUInt}
    .elsewhen (io.addr === CSR_ASID)    {io.read_data := csrReg.asid.asUInt}
    .elsewhen (io.addr === CSR_PGDL)    {io.read_data := csrReg.pgdl}
    .elsewhen (io.addr === CSR_PGDH)    {io.read_data := csrReg.pgdh}
    .elsewhen (io.addr === CSR_PGD) {
        when (csrReg.badv(31)) {
            io.read_data := Cat(csrReg.pgdh(31, 12), 0.U(12.W))
        } .otherwise {
            io.read_data := Cat(csrReg.pgdl(31, 12), 0.U(12.W))
        }
    }
    .elsewhen (io.addr === CSR_CPUID)     {io.read_data := csrReg.cpuid}
    .elsewhen (io.addr === CSR_SAVE0)     {io.read_data := csrReg.save0}
    .elsewhen (io.addr === CSR_SAVE1)     {io.read_data := csrReg.save1}
    .elsewhen (io.addr === CSR_SAVE2)     {io.read_data := csrReg.save2}
    .elsewhen (io.addr === CSR_SAVE3)     {io.read_data := csrReg.save3}
    .elsewhen (io.addr === CSR_TID)       {io.read_data := csrReg.tid}
    .elsewhen (io.addr === CSR_TCFG)      {io.read_data := csrReg.tcfg.asUInt}
    .elsewhen (io.addr === CSR_TVAL)      {io.read_data := csrReg.tval.asUInt}
    .elsewhen (io.addr === CSR_TICLR)     {io.read_data := 0.U(32.W)}
    .elsewhen (io.addr === CSR_LLBCTL)    {io.read_data := csrReg.llbctl.asUInt}
    .elsewhen (io.addr === CSR_TLBRENTRY) {io.read_data := Cat(csrReg.tlbrentry(31, 2), 0.U(1.W), csrReg.tlbrentry(0))}
    .elsewhen (io.addr === CSR_CTAG)      {io.read_data := csrReg.ctag}
    .elsewhen (io.addr === CSR_DMW0)      {io.read_data := csrReg.dmw0.asUInt}
    .elsewhen (io.addr === CSR_DMW1)      {io.read_data := csrReg.dmw1.asUInt}
    .otherwise                            {io.read_data := 0.U(32.W)}

    csrRegNxt := csrReg
    io.csr_pc := 0.U(32.W)
    csrRegNxt.estat.is9_2 := io.ext_int

    when (io.exception) {
        csrRegNxt.prmd.pplv      := csrReg.crmd.plv
        csrRegNxt.prmd.pie       := csrReg.crmd.ie
        csrRegNxt.crmd.plv       := 0.U(2.W)
        csrRegNxt.crmd.ie        := 0.U(1.W)
        csrRegNxt.era            := io.in_pc
        csrRegNxt.estat.ecode    := io.com_xcpt.bits.cause(14,9)
        csrRegNxt.estat.esubcode := io.com_xcpt.bits.cause(8,0)
        when (
            io.com_xcpt.bits.cause === TLBR ||
            io.com_xcpt.bits.cause === PIL  ||
            io.com_xcpt.bits.cause === PIS  ||
            io.com_xcpt.bits.cause === PIF  ||
            io.com_xcpt.bits.cause === PME  ||
            io.com_xcpt.bits.cause === PPI
        ) {
            csrRegNxt.tlbehi.vppn := io.com_xcpt.bits.badvaddr(31, 13)
        }

        when(io.com_xcpt.bits.cause === TLBR){
            csrRegNxt.crmd.da := 1.U(1.W)
            csrRegNxt.crmd.pg := 0.U(1.W)
            io.csr_pc := csrReg.tlbrentry
        }.otherwise{
            io.csr_pc := csrReg.eentry
        }

        when(io.com_xcpt.bits.vaddrWriteEnable){
            csrRegNxt.badv := io.com_xcpt.bits.badvaddr
        }
    }.elsewhen(io.cmd === CSR_E){
        csrRegNxt.crmd.ie := csrReg.prmd.pie
        csrRegNxt.crmd.plv := csrReg.prmd.pplv
        when(csrReg.estat.ecode === 0x3f.U(ecodeBits.W)){
            csrRegNxt.crmd.da := 0.U(1.W)
            csrRegNxt.crmd.pg := 1.U(1.W)
        }
        when(~csrReg.llbctl(2)){
            csrRegNxt.llbctl(0) := 0.U(1.W)
        }
        csrRegNxt.llbctl(2) := 0.U(1.W)
        io.csr_pc := csrReg.era
    } /* .elsewhen(is_llw){
        csrRegNxt.llbctl(0) := 1.U(1.W)
        io.csr_pc := csrReg.era   //暂时一直输出csrReg.era
    }.elsewhen(is_scw){
        csrRegNxt.llbctl(0) := 0.U(1.W)
        io.csr_pc := csrReg.era
    } */ .otherwise {
        io.csr_pc := csrReg.era
    }

    when (csrReg.tcfg.en.asBool) {
        when(csrReg.tval.timeval =/= 0.U) {
            csrRegNxt.tval.timeval := csrReg.tval.timeval - 1.U
        } .otherwise {
            when (csrReg.tcfg.periodic.asBool) {
                csrRegNxt.tval.timeval := Cat(csrReg.tcfg.initval,0.U(2.W))
            } .otherwise {
                csrRegNxt.tcfg.en := -1.S(TIMER_LENGTH.W).asUInt  //TODO:is '1==11111111?
            }
            csrRegNxt.estat.is_11 := 1.U(1.W)
        }
    }

    when(wen && !io.exception && io.cmd =/= CSR_E){
        when(io.addr === CSR_CRMD) {csrRegNxt.crmd := Cat(0.U(23.W),write_data(8,0)).asTypeOf(new CRMD)}
        .elsewhen(io.addr === CSR_PRMD) {csrRegNxt.prmd := Cat(0.U(29.W),write_data(2,0)).asTypeOf(new PRMD)}
        .elsewhen(io.addr === CSR_EUEN) {csrRegNxt.euen := Cat(0.U(31.W),write_data(0)).asTypeOf(new EUEN)}
        .elsewhen(io.addr === CSR_ECFG) {csrRegNxt.ecfg := Cat(0.U(19.W),write_data(12,11),0.U(1.W),write_data(9,0)).asUInt}
        .elsewhen(io.addr === CSR_ESTAT) {csrRegNxt.estat := Cat(0.U(1.W),csrReg.estat.asUInt(30,16),0.U(3.W),csrReg.estat.asUInt(12,11),0.U(1.W),csrReg.estat.asUInt(9,2),write_data(1,0)).asTypeOf(new ESTAT)}
        .elsewhen(io.addr === CSR_ERA) {csrRegNxt.era:= write_data}
        .elsewhen(io.addr === CSR_BADV) {csrRegNxt.badv:= write_data}
        .elsewhen(io.addr === CSR_EENTRY) {csrRegNxt.eentry:= Cat(write_data(31,6),csrReg.eentry(5,0))}
        .elsewhen(io.addr === CSR_TLBIDX) {csrRegNxt.tlbidx:= Cat(write_data(31),0.U(1.W),write_data(29,24),0.U(8.W),0.U((16-TLB_INDEX_LENGTH).W),write_data(TLB_INDEX_LENGTH-1,0)).asTypeOf(new TLBIDX)}
        .elsewhen(io.addr === CSR_TLBEHI) {csrRegNxt.tlbehi:= Cat(write_data(31,13),csrReg.tlbehi.asUInt(12,0)).asTypeOf(new TLBEHI)}
        .elsewhen(io.addr === CSR_TLBELO0) {csrRegNxt.tlbelo0:= Cat(csrReg.tlbelo0.asUInt(31,PALEN-4),write_data(PALEN-5,8),csrReg.tlbelo0.asUInt(7),write_data(6,0)).asTypeOf(new TLBELO)}
        .elsewhen(io.addr === CSR_TLBELO1) {csrRegNxt.tlbelo1:= Cat(csrReg.tlbelo1.asUInt(31,PALEN-4),write_data(PALEN-5,8),csrReg.tlbelo1.asUInt(7),write_data(6,0)).asTypeOf(new TLBELO)}
        .elsewhen(io.addr === CSR_ASID) {csrRegNxt.asid:= Cat(0.U(8.W),csrReg.asid.asUInt(23,10),write_data(9,0)).asTypeOf(new ASID)}
        .elsewhen(io.addr === CSR_PGDL) {csrRegNxt.pgdl:= Cat(write_data(31,12),csrReg.pgdl(11,0))}
        .elsewhen(io.addr === CSR_PGDH) {csrRegNxt.pgdh:= Cat(write_data(31,12),csrReg.pgdh(11,0))}
        .elsewhen(io.addr === CSR_PGD){csrRegNxt.pgd := csrReg.pgd}
        .elsewhen(io.addr === CSR_CPUID) {csrRegNxt.cpuid:= write_data}
        .elsewhen(io.addr === CSR_SAVE0) {csrRegNxt.save0:= write_data}
        .elsewhen(io.addr === CSR_SAVE1) {csrRegNxt.save1:= write_data}
        .elsewhen(io.addr === CSR_SAVE2) {csrRegNxt.save2:= write_data}
        .elsewhen(io.addr === CSR_SAVE3) {csrRegNxt.save3:= write_data}
        .elsewhen(io.addr === CSR_TID) {csrRegNxt.tid:= write_data}
        .elsewhen(io.addr === CSR_TCFG){
            csrRegNxt.tcfg:= Cat(0.U((32-TIMER_LENGTH).W),write_data(TIMER_LENGTH-1,0)).asTypeOf(new TCFG)
            csrRegNxt.tval.timeval:= Cat(write_data(TIMER_LENGTH-1,2),0.U(2.W))
        }
        .elsewhen(io.addr === CSR_TVAL) {csrRegNxt.tval:= csrReg.tval}
        .elsewhen(io.addr === CSR_TICLR) {
            csrRegNxt.ticlr:= 1.U & write_data(0) | csrReg.ticlr(0)
            when(write_data(0)){
                csrRegNxt.estat.is_11:= 0.U
            }
        }
        .elsewhen(io.addr === CSR_LLBCTL){
            csrRegNxt.llbctl:= Cat(
                0.U(29.W), write_data(2) & (~write_data(1)), 0.U(1.W), csrReg.llbctl(0) & (~write_data(1))
            ).asTypeOf(Vec(32, Bool()))
        }
        .elsewhen(io.addr === CSR_TLBRENTRY) {csrRegNxt.tlbrentry:= Cat(write_data(31,6),csrReg.tlbrentry(5,0))}
        .elsewhen(io.addr === CSR_CTAG) {csrRegNxt.ctag:= write_data}
        .elsewhen(io.addr === CSR_DMW0) {csrRegNxt.dmw0:= Cat(write_data(31,19),0.U(1.W),write_data(27,25),0.U(19.W),write_data(5,3),0.U(2.W),write_data(0)).asTypeOf(new DMW)}
        .elsewhen(io.addr === CSR_DMW1) {csrRegNxt.dmw1:= Cat(write_data(31,19),0.U(1.W),write_data(27,25),0.U(19.W),write_data(5,3),0.U(2.W),write_data(0)).asTypeOf(new DMW)}
    }
}
