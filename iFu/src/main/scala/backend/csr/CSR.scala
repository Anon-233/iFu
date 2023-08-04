package iFu.backend

import chisel3._
import chisel3.util._
import iFu.common._
import iFu.backend.CSRAddr._

class CRMD extends CoreBundle{
    val r0 = UInt(23.W)
    val datm = UInt(2.W)
    val datf = UInt(2.W)
    val pg = UInt(1.W)
    val da = UInt(1.W)
    val ie = UInt(1.W)
    val plv = UInt(2.W)

    def init = {
        da := 1.U
    }
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

class ECFG extends CoreBundle{
    val r0 = UInt(19.W)
    val lie12_11 = UInt(2.W)
    val r1 = UInt(1.W)
    val lie9_0 = UInt(10.W)
}

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
    val r = UInt(csrParameters.TLBIDX_r)
    val index = UInt(csrParameters.TLBIDX_INDEX)
}

class TLBEHI extends CoreBundle{
    val vppn = UInt(19.W)
    val r0 = UInt(13.W)
}

class TLBELO extends CoreBundle{
    val r = UInt(csrParameters.TLBELO_r)
    val ppn = UInt(csrParameters.TLBELO_ppn)
    val r0 = UInt(1.W)
    val g = UInt(1.W)
    val mat = UInt(2.W)
    val plv = UInt(2.W)
    val d = UInt(1.W)
    val v = UInt(1.W)
}

class TCFG extends CoreBundle{
    val initval = UInt(csrParameters.TCFG_initval)
    val periodic = UInt(1.W)
    val en = UInt(1.W)
}

class TVAL extends CoreBundle{
    val timeval = UInt(csrParameters.TIMER_LENGTH)
}

class ASID extends CoreBundle{
    val r0 = UInt(8.W)
    val asidbits = UInt(8.W)
    val r1 = UInt(6.W)
    val asid = UInt(10.W)

    def init = {
        asidbits := 0xa.U
    }
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
    val ecfg = new ECFG
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
    val llbctl = UInt(32.W)
    val tlbrentry = UInt(32.W)
    val ctag = UInt(32.W)
    val dmw0 = new DMW
    val dmw1 = new DMW
}

class CSR extends CoreModule {
    val io = IO(new Bundle{
        val valid = Input(Bool())
        val read_addr = Input(UInt(14.W))
        val write_addr = Input(UInt(14.W))
        val write_data = Input(UInt(32.W))

        val read_data = Output(UInt(32.W))

        val interrupt = Input(UInt(8.W))

        val exception = Input(Bool())
        val com_xcpt = Input(new CommitExceptionSignals)
        val vaddr = Input(UInt(32.W))

        val is_ertn = Input(Bool())
        val is_llw = Input(Bool())
        val is_scw = Input(Bool())

        val in_pc = Input(UInt(32.W))
        val csr_pc = Output(UInt(32.W))

        val decode_interrupt = Output(Bool())

        val translate_mode_change = Output(Bool())
    })

    val csrReg = RegInit(0.U.asTypeOf(new CSRReg))
    val csrRegNxt = Wire(new CSRReg)
    val mode = RegInit(0.U(2.W))
    val modeNxt = Wire(UInt(2.W))
    val translateMode = RegInit(0.U(2.W))
    val translateModeNxt = Wire(UInt(2.W))

    csrReg := csrRegNxt
    mode := modeNxt
    translateMode := translateModeNxt

    val trint = Wire(Bool())
    val exint = Wire(Bool())
    val swint = Wire(Bool())

    trint := csrReg.estat.is_11 & csrReg.ecfg(11)
    exint := |(csrReg.estat.is9_2 & csrReg.ecfg(9,2))
    swint := |(csrReg.estat.is1_0 & csrReg.ecfg(1,0))

    decode_interrupt := (trint | exint | swint) & csrReg.crmd.ie

    when(read_addr === CSR_CRMD) {read_data := csrReg.crmd.asUInt}
    .elsewhen(read_addr === CSR_PRMD) {read_data := csrReg.prmd.asUInt}
    .elsewhen(read_addr === CSR_EUEN) {read_data := csrReg.euen.asUInt}
    .elsewhen(read_addr === CSR_ECFG) {read_data := csrReg.ecfg.asUInt}
    .elsewhen(read_addr === CSR_ESTAT) {read_data := csrReg.estat.asUInt}
    .elsewhen(read_addr === CSR_ERA) {read_data := csrReg.era}
    .elsewhen(read_addr === CSR_BADV) {read_data := csrReg.badv}
    .elsewhen(read_addr === CSR_EENTRY) {read_data := csrReg.eentry}
    .elsewhen(read_addr === CSR_TLBIDX) {read_data := csrReg.tlbidx.asUInt}
    .elsewhen(read_addr === CSR_TLBEHI) {read_data := csrReg.tlbehi.asUInt}
    .elsewhen(read_addr === CSR_TLBELO0) {read_data := csrReg.tlbelo0.asUInt}
    .elsewhen(read_addr === CSR_TLBELO1) {read_data := csrReg.tlbelo1.asUInt}
    .elsewhen(read_addr === CSR_ASID) {read_data := csrReg.asid.asUInt}
    .elsewhen(read_addr === CSR_PGDL) {read_data := csrReg.pgdl}
    .elsewhen(read_addr === CSR_PGDH) {read_data := csrReg.pgdh}
    .elsewhen(read_addr === CSR_PGD) {
        when(csrReg.badv[31]){
            read_data := Cat(csrReg.pgdh(31,12),0.U(12.W))
        }.otherwise{
            read_data := Cat(csrReg.pgdl(31,12),0.U(12.W))
        }
    }
    .elsewhen(read_addr === CSR_CPUID) {read_data := csrReg.cpuid}
    .elsewhen(read_addr === CSR_SAVE0) {read_data := csrReg.save0}
    .elsewhen(read_addr === CSR_SAVE1) {read_data := csrReg.save1}
    .elsewhen(read_addr === CSR_SAVE2) {read_data := csrReg.save2}
    .elsewhen(read_addr === CSR_SAVE3) {read_data := csrReg.save3}
    .elsewhen(read_addr === CSR_TID) {read_data := csrReg.tid}
    .elsewhen(read_addr === CSR_TCFG) {read_data := csrReg.tcfg.asUInt}
    .elsewhen(read_addr === CSR_TVAL) {read_data := csrReg.tval.asUInt}
    .elsewhen(read_addr === CSR_TICLR) {read_data := 0.U(32.W)}
    .elsewhen(read_addr === CSR_LLBCTL) {read_data := csrReg.llbctl}
    .elsewhen(read_addr === CSR_TLBRENTRY) {read_data := Cat(csrReg.tlbrentry(31,2),0.U(1.W),csrReg.tlbrentry(0))}
    .elsewhen(read_addr === CSR_CTAG) {read_data := csrReg.ctag}
    .elsewhen(read_addr === CSR_DMW0) {read_data := csrReg.dmw0.asUInt}
    .elsewhen(read_addr === CSR_DMW1) {read_data := csrReg.dmw1.asUInt}
    .otherwise{read_data := 0.U(32.W)}

    translateModeNxt := Cat(csrRegNxt.crmd.da,csrRegNxt.crmd.pg)
    translate_mode_change := translateMode =/= translateModeNxt


    csrRegNxt := csrReg
    csr_pc := 0.U(32.W)
    csrRegNxt.estat.is9_2 := interrupt

    when(exception){
        csrRegNxt.prmd.pplv := csrReg.crmd.plv
        csrRegNxt.prmd.pie := csrReg.crmd.ie
        csrRegNxt.crmd.plv := 0.U(2.W)
        csrRegNxt.crmd.ie := 0.U(1.W)
        csrRegNxt.era = in_pc
        csrRegNxt.estat.ecode := com_xcpt.ecode
        csrRegNxt.estat.esubcode := com_xcpt.esubcode
        when(com_xcpt.ecode === 0x3f.U
          || com_xcpt.ecode === 0x1.U
          || com_xcpt.ecode === 0x2.U
          || com_xcpt.ecode === 0x3.U
          || com_xcpt.ecode === 0x4.U
          || com_xcpt.ecode === 0x7.U){
            csrRegNxt.tlbehi.vppn = vaddr(31,13)
        }

        when(com_xcpt.ecode === 0x3f.U){
            csrRegNxt.crmd.da := 1.U(1.W)
            csrRegNxt.crmd.pg := 0.U(1.W)
            csr_pc := csrReg.tlbrentry
        }.otherwise{
            csr_pc := csrReg.eentry
        }

        modeNxt := 0.U(2.W)

        when(com_xcpt.vaddrWriteEnable){
            csrRegNxt.badv := vaddr
        }
    }.elsewhen(is_ertn){
        csrRegNxt.crmd.ie := csrReg.prmd.pie
        csrRegNxt.crmd.plv := csrReg.prmd.pplv
        when(csrReg.estat.ecode === 0x3f.U){
            csrRegNxt.crmd.da := 0.U(1.W)
            csrRegNxt.crmd.pg := 1.U(1.W)
        }
        when(~csrReg.llbctl(2)){
            csrRegNxt.llbctl(0) := 0.U(1.W)
        }
        csrRegNxt.llbctl(2) := 1.U(1.W)
        csr_pc := csrReg.era
        modeNxt := 3.U(2.W)
    }.elsewhen(is_llw){
        csrRegNxt.llbctl(0) := 1.U(1.W)
        csr_pc := csrReg.era   //暂时一直输出csrReg.era
    }.elsewhen(is_scw){
        csrRegNxt.llbctl(0) := 0.U(1.W)
        csr_pc := csrReg.era
    }.otherwise{
        modeNxt := mode
        csr_pc := csrReg.era
    }

    when(csrReg.tcfg.en){
        when(csrReg.tval.timeval != 0) {
            csrRegNxt.tval.timeval := csrReg.tval.timeval - 1
        }.otherwise{
            when(csrReg.tcfg.periodic){
                csrRegNxt.tval.timeval := Cat(csrReg.tcfg.initval,0.U(2.W))
            }.otherwise{
                csrRegNxt.tcfg.en := -1.S(csrParameters.TIMER_LENGTH.W)  //TODO:is '1==11111111?
            }
            csrRegNxt.estat.is_11 := 1.U(1.W)
        }
    }

    when(valid){
        when(write_addr === CSR_CRMD) {csrRegNxt.crmd := Cat(0.U(23.W),write_data(8,0))}
        .elsewhen(write_addr === CSR_PRMD) {csrRegNxt.prmd := Cat(0.U(29.W),write_data(2,0))}
        .elsewhen(write_addr === CSR_EUEN) {csrRegNxt.euen := Cat(0.U(31.W),write_data(0))}
        .elsewhen(write_addr === CSR_ECFG) {csrRegNxt.ecfg := Cat(0.U(19.W),write_data(12,11),0.U(1.W),write_data(9,0))}
        .elsewhen(write_addr === CSR_ESTAT) {csrRegNxt.estat := Cat(0.U(1.W),csrReg.estat(30,16),0.U(3.W),csrReg.estat(12,11),0.U(1.W),csrReg.estat(9,2),write_data(1,0))}
        .elsewhen(write_addr === CSR_ERA) {csrRegNxt.era := write_data}
        .elsewhen(write_addr === CSR_BADV) {csrRegNxt.badv := write_data}
        .elsewhen(write_addr === CSR_EENTRY) {csrRegNxt.eentry := Cat(write_data(31,6),csrReg.eentry(5,0))}
        .elsewhen(write_addr === CSR_TLBIDX) {csrRegNxt.tlbidx := Cat(write_data(31),0.U(1.W),write_data(29,24),0.U(8.W),0.U(16-TLB_INDEX_LENGTH),write_data(TLB_INDEX_LENGTH-1,0))}
        .elsewhen(write_addr === CSR_TLBEHI) {csrRegNxt.tlbehi := Cat(write_data(31,13),csrReg.tlbehi(12,0))}
        .elsewhen(write_addr === CSR_TLBELO0) {csrRegNxt.tlbelo0 := Cat(csrReg.tlbelo0(31,PALEN-4),write_data(PALEN-5,8),csrReg.tlbelo0(7),write_data(6,0))}
        .elsewhen(write_addr === CSR_TLBELO1) {csrRegNxt.tlbelo1 := Cat(csrReg.tlbelo1(31,PALEN-4),write_data(PALEN-5,8),csrReg.tlbelo1(7),write_data(6,0))}
        .elsewhen(write_addr === CSR_ASID) {csrRegNxt.asid := Cat(0.U(8.W),csrReg.asid(23,10),write_data(9,0))}
        .elsewhen(write_addr === CSR_PGDL) {csrRegNxt.pgdl := Cat(write_data(31,12),csrReg.pgdl(11,0))}
        .elsewhen(write_addr === CSR_PGDH) {csrRegNxt.pgdh := Cat(write_data(31,12),csrReg.pgdh(11,0))}
        .elsewhen(write_addr === CSR_PGD){csrRegNxt.pgd = csrReg.pgd}
        .elsewhen(write_addr === CSR_CPUID) {csrRegNxt.cpuid := write_data}
        .elsewhen(write_addr === CSR_SAVE0) {csrRegNxt.save0 := write_data}
        .elsewhen(write_addr === CSR_SAVE1) {csrRegNxt.save1 := write_data}
        .elsewhen(write_addr === CSR_SAVE2) {csrRegNxt.save2 := write_data}
        .elsewhen(write_addr === CSR_SAVE3) {csrRegNxt.save3 := write_data}
        .elsewhen(write_addr === CSR_TID) {csrRegNxt.tid := write_data}
        .elsewhen(write_addr === CSR_TCFG){
            csrRegNxt.tcfg := Cat(0.U(32-TIMER_LENGTH),write_data(TIMER_LENGTH-1,0))
            csrRegNxt.tval.timeval := Cat(write_data(TIMER_LENGTH-1,2),0.U(2.W))
        }
        .elsewhen(wriet_addr === CSR_TVAL) {csrRegNxt.tval := csrReg.tval}
        .elsewhen(write_addr === CSR_TICLR) {
            csrRegNxt.ticlr(31,1) := 0.U(31.W)
            csrRegNxt.ticlr(0) := write_data(0) | csrReg.ticlr(0)
            when(write_data(0)){
                csrRegNxt.estat.is_11 := 0
            }
        }
        .elsewhen(write_addr === CSR_LLBCTL){
            csrRegNxt.llbctl(31,3) := 0.U(29.W)
            csrRegNxt.llbctl(2) := write_data(2) & (~write_data(1))
            csrRegNxt.llbctl(1) := 0.U(1.W)
            csrRegNxt.llbctl(0) := csrReg.llbctl(0) & (~write_data(1))
        }
        .elsewhen(write_addr === CSR_TLBRENTRY) {csrRegNxt.tlbrentry := Cat(write_data(31,6),csrReg.tlbrentry(5,0))}
        .elsewhen(write_addr === CSR_CTAG) {csrRegNxt.ctag := write_data}
        .elsewhen(write_addr === CSR_DMW0) {csrRegNxt.dmw0 := Cat(write_data(31,19),0.U(1.W),write_data(27,25),0.U(19.W),write_data(5,3),0.U(2.W),write_data(0))}
        .elsewhen(write_addr === CSR_DMW1) {csrRegNxt.dmw1 := Cat(write_data(31,19),0.U(1.W),write_data(27,25),0.U(19.W),write_data(5,3),0.U(2.W),write_data(0))}
    }


}