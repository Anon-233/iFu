package iFu.backend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.common.CauseCode._

class CRMD extends CoreBundle {
    val r0_0 = UInt(23.W)
    val datm = UInt(2.W)
    val datf = UInt(2.W)
    val pg   = UInt(1.W)
    val da   = UInt(1.W)
    val ie   = UInt(1.W)
    val plv  = UInt(2.W)
}

class PRMD extends CoreBundle {
    val r0_0 = UInt(29.W)
    val pie  = UInt(1.W)
    val pplv = UInt(2.W)
}

class EUEN extends CoreBundle {
    val r0  = UInt(31.W)
    val fpe = UInt(1.W)
}

class ESTAT extends CoreBundle {
    val r0_0     = UInt(1.W)
    val esubcode = UInt(9.W)
    val ecode    = UInt(6.W)
    val r0_1     = UInt(3.W)
    val is_12    = UInt(1.W)
    val is_11    = UInt(1.W)
    val r0_2     = UInt(1.W)
    val is9_2    = UInt(8.W)
    val is1_0    = UInt(2.W)
}

class TLBIDX extends CoreBundle {
    val ne    = UInt(1.W)
    val r0_0  = UInt(1.W)
    val ps    = UInt(6.W)
    val r0_1  = UInt(8.W)
    val r     = UInt((16 - TLB_INDEX_LENGTH).W)
    val index = UInt(TLB_INDEX_LENGTH.W)
}

class TLBEHI extends CoreBundle {
    val vppn = UInt(19.W)
    val r0_0 = UInt(13.W)
}

class TLBELO extends CoreBundle {
    val r   = UInt((16 - TLB_INDEX_LENGTH).W)
    val ppn = UInt(TLBELO_ppn.W)
    val r0  = UInt(1.W)
    val g   = UInt(1.W)
    val mat = UInt(2.W)
    val plv = UInt(2.W)
    val d   = UInt(1.W)
    val v   = UInt(1.W)
}

class ASID extends CoreBundle {
    val r0_0     = UInt(8.W)
    val asidbits = UInt(8.W)
    val r0_1     = UInt(6.W)
    val asid     = UInt(10.W)
}

class TCFG extends CoreBundle {
    val initval  = UInt(30.W)
    val periodic = UInt(1.W)
    val en       = UInt(1.W)
}

class LLBCTL extends CoreBundle {
    val r0_0  = UInt(29.W)
    val klo   = UInt(1.W)
    val wcllb = UInt(1.W)
    val rollb = UInt(1.W)
}

class DMW extends CoreBundle{
    val vseg = UInt(3.W)
    val r0_1 = UInt(1.W)
    val pseg = UInt(3.W)
    val r0_1 = UInt(19.W)
    val mat  = UInt(2.W)
    val plv3 = UInt(1.W)
    val r0_2 = UInt(2.W)
    val plv0 = UInt(1.W)
}

class CSRReg extends CoreBundle {
    val crmd      = new CRMD
    val prmd      = new PRMD
    val euen      = new EUEN
    val ecfg      = UInt(32.W)
    val estat     = new ESTAT
    val era       = UInt(32.W)
    val badv      = UInt(32.W)
    val eentry    = UInt(32.W)
    val tlbidx    = new TLBIDX
    val tlbehi    = new TLBEHI
    val tlbelo0   = new TLBELO
    val tlbelo1   = new TLBELO
    val asid      = new ASID
    val pgdl      = UInt(32.W)
    val pgdh      = UInt(32.W)
    val pgd       = UInt(32.W)
    val cpuid     = UInt(32.W)
    val save0     = UInt(32.W)
    val save1     = UInt(32.W)
    val save2     = UInt(32.W)
    val save3     = UInt(32.W)
    val tid       = UInt(32.W)
    val tcfg      = new TCFG
    val tval      = UInt(32.W)
    val ticlr     = UInt(32.W)
    val llbctl    = new LLBCTL
    val tlbrentry = UInt(32.W)
    val ctag      = UInt(32.W)
    val dmw0      = new DMW
    val dmw1      = new DMW
}

class CSRFileIO extends CoreBundle {
    val ext_int   = Input(UInt(8.W))
    val interrupt = Output(Bool())

    val exception = Input(Bool())
    val com_xcpt  = Input(new CommitExceptionSignals)

    val in_pc  = Input(UInt(32.W))
    val csr_pc = Output(UInt(32.W))

    // val is_llw    = Input(Bool())
    // val is_scw    = Input(Bool())

    val exevalid = Input(Bool())
    val cmd      = Input(UInt(CSR_SZ.W))
    val addr     = Input(UInt(12.W))
    val rdata    = Output(UInt(32.W))
    val rd       = Input(UInt(32.W))
    val rj       = Input(UInt(32.W))
}

class CSRFile extends CoreModule {
    val io = IO(new CSRFileIO)

    val wen = io.cmd(1)
    val wdata = Wire(UInt(32.W))
    when (io.cmd === CSR_W) {
        wdata := io.rd
    } .otherwise {
        wdata := (io.rd & io.rj) | (io.rdata & ~io.rj)
    }

    // reset value
    val csrRst = WireInit(0.U.asTypeOf(new CSRReg))
    csrRst.crmd.da := 1.U(1.W)
    csrRst.asid.asidbits := 0xa.U(8.W)

    val csrRegNxt = Wire(new CSRReg)
    val csrReg = RegNext(csrRegNxt, init = csrRst)

    io.interrupt := (csrReg.estat.asUInt(12, 0) & csrReg.ecfg(12, 0)).orR && csrReg.crmd.ie

    io.rdata := MuxLookup(io.addr, 0.U, Seq(
        CSR_CRMD      -> csrReg.crmd.asUInt
        CSR_PRMD      -> csrReg.prmd.asUInt
        CSR_EUEN      -> csrReg.euen.asUInt
        CSR_ECFG      -> csrReg.ecfg
        CSR_ESTAT     -> csrReg.estat.asUInt
        CSR_ERA       -> csrReg.era
        CSR_BADV      -> csrReg.badv
        CSR_EENTRY    -> csrReg.eentry
        CSR_TLBIDX    -> csrReg.tlbidx.asUInt
        CSR_TLBEHI    -> csrReg.tlbehi.asUInt
        CSR_TLBELO0   -> csrReg.tlbelo0.asUInt
        CSR_TLBELO1   -> csrReg.tlbelo1.asUInt
        CSR_ASID      -> csrReg.asid.asUInt
        CSR_PGDL      -> csrReg.pgdl
        CSR_PGDH      -> csrReg.pgdh
        CSR_PGD       -> (
            csrReg.badv(31) ?
                Cat(csrReg.pgdh(31,12),0.U(12.W)) :
                Cat(csrReg.pgdl(31,12),0.U(12.W))
        )
        CSR_CPUID     -> csrReg.cpuid
        CSR_SAVE0     -> csrReg.save0
        CSR_SAVE1     -> csrReg.save1
        CSR_SAVE2     -> csrReg.save2
        CSR_SAVE3     -> csrReg.save3
        CSR_TID       -> csrReg.tid
        CSR_TCFG      -> csrReg.tcfg.asUInt
        CSR_TVAL      -> csrReg.tval
        CSR_TICLR     -> csrReg.ticlr
        CSR_LLBCTL    -> csrReg.llbctl.asUInt
        CSR_TLBRENTRY -> csrReg.tlbrentry
        CSR_CTAG      -> csrReg.ctag
        CSR_DMW0      -> csrReg.dmw0.asUInt
        CSR_DMW1      -> csrReg.dmw1.asUInt
    ))
}
