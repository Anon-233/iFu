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
    val r0_0 = UInt(1.W)
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
    val com_xcpt  = Input(Valid(new CommitExceptionSignals))

    val err_pc      = Input(UInt(32.W))
    val redirect_pc = Output(UInt(32.W))

    // val is_llw    = Input(Bool())
    // val is_scw    = Input(Bool())

    val exevalid = Input(Bool())
    val cmd      = Input(UInt(CSR_SZ.W))
    val addr     = Input(UInt(12.W))
    val rdata    = Output(UInt(32.W))
    val rd       = Input(UInt(32.W))
    val rj       = Input(UInt(32.W))

    val debug_csr_reg = Output(new CSRReg)
}

class CSRFile extends CoreModule {
    val io = IO(new CSRFileIO)

    val csrRst = WireInit(0.U.asTypeOf(new CSRReg))
    csrRst.crmd.da := 1.U(1.W);
    csrRst.asid.asidbits := 0xa.U(8.W)

    val csrRegNxt = Wire(new CSRReg)
    val csrReg    = RegNext(csrRegNxt, init = csrRst)

// --------------------------------------------------------
// below code is for read
    io.rdata := MuxLookup(io.addr, 0.U)(Seq(
        CSR_CRMD      -> csrReg.crmd.asUInt,
        CSR_PRMD      -> csrReg.prmd.asUInt,
        CSR_EUEN      -> csrReg.euen.asUInt,
        CSR_ECFG      -> csrReg.ecfg.asUInt,
        CSR_ESTAT     -> csrReg.estat.asUInt,
        CSR_ERA       -> csrReg.era.asUInt,
        CSR_BADV      -> csrReg.badv.asUInt,
        CSR_EENTRY    -> csrReg.eentry.asUInt,
        CSR_TLBIDX    -> csrReg.tlbidx.asUInt,
        CSR_TLBEHI    -> csrReg.tlbehi.asUInt,
        CSR_TLBELO0   -> csrReg.tlbelo0.asUInt,
        CSR_TLBELO1   -> csrReg.tlbelo1.asUInt,
        CSR_ASID      -> csrReg.asid.asUInt,
        CSR_PGDL      -> csrReg.pgdl.asUInt,
        CSR_PGDH      -> csrReg.pgdh.asUInt,
        CSR_PGD       -> Mux(csrReg.badv(31),
                         Cat(csrReg.pgdh(31, 12), 0.U(12.W)).asUInt,
                         Cat(csrReg.pgdl(31, 12), 0.U(12.W)).asUInt),
        CSR_CPUID     -> csrReg.cpuid.asUInt,
        CSR_SAVE0     -> csrReg.save0.asUInt,
        CSR_SAVE1     -> csrReg.save1.asUInt,
        CSR_SAVE2     -> csrReg.save2.asUInt,
        CSR_SAVE3     -> csrReg.save3.asUInt,
        CSR_TID       -> csrReg.tid.asUInt,
        CSR_TCFG      -> csrReg.tcfg.asUInt,
        CSR_TVAL      -> csrReg.tval.asUInt,
        CSR_TICLR     -> csrReg.ticlr.asUInt,
        CSR_LLBCTL    -> csrReg.llbctl.asUInt,
        CSR_TLBRENTRY -> csrReg.tlbrentry.asUInt,
        CSR_CTAG      -> csrReg.ctag.asUInt,
        CSR_DMW0      -> csrReg.dmw0.asUInt,
        CSR_DMW1      -> csrReg.dmw1.asUInt
    ))
// --------------------------------------------------------

// --------------------------------------------------------
// below code is for write
    val wen = io.exevalid && (io.cmd === CSR_W || io.cmd === CSR_M)
    val write_data = Mux(io.cmd === CSR_W,
        io.rd,
        (io.rd & io.rj) | (io.rdata & (~io.rj).asUInt)
    )

    csrRegNxt := csrReg
    csrRegNxt.estat.is9_2 := io.ext_int

    when(wen && !io.exception && io.cmd =/= CSR_E){
        switch (io.addr) {
            is (CSR_CRMD) {
                csrRegNxt.crmd := Cat(0.U(23.W), write_data(8, 0)).asTypeOf(new CRMD)
            }
            is (CSR_PRMD) {
                csrRegNxt.prmd := Cat(0.U(29.W), write_data(2, 0)).asTypeOf(new PRMD)
            }
            is (CSR_EUEN) {
                csrRegNxt.euen := Cat(0.U(31.W), write_data(0)).asTypeOf(new EUEN)
            }
            is (CSR_ECFG) {
                csrRegNxt.ecfg := Cat(0.U(19.W), write_data(12, 11), 0.U(1.W), write_data(9, 0)).asUInt
            }
            is (CSR_ESTAT) {
                csrRegNxt.estat := Cat(csrReg.estat.asUInt(31, 2), write_data(1, 0)).asTypeOf(new ESTAT)
            }
            is (CSR_ERA) {
                csrRegNxt.era := write_data
            }
            is (CSR_BADV) {
                csrRegNxt.badv := write_data
            }
            is (CSR_EENTRY) {
                csrRegNxt.eentry := Cat(write_data(31, 6), csrReg.eentry(5,0))
            }
            is (CSR_TLBIDX) {
                csrRegNxt.tlbidx := Cat(write_data(31), 0.U(1.W), write_data(29, 24), 0.U(8.W),0.U(TLBIDX_r.W), write_data(TLB_INDEX_LENGTH - 1,0)).asTypeOf(new TLBIDX)
            }
            is (CSR_TLBEHI) {
                csrRegNxt.tlbehi := Cat(write_data(31, 13), csrReg.tlbehi.asUInt(12, 0)).asTypeOf(new TLBEHI)
            }
            is (CSR_TLBELO0) {
                csrRegNxt.tlbelo0 := Cat(csrReg.tlbelo0.asUInt(31, PALEN - 4), write_data(PALEN - 5, 8), csrReg.tlbelo0.asUInt(7), write_data(6, 0)).asTypeOf(new TLBELO)
            }
            is (CSR_TLBELO1) {
                csrRegNxt.tlbelo1 := Cat(csrReg.tlbelo1.asUInt(31, PALEN - 4), write_data(PALEN - 5, 8), csrReg.tlbelo1.asUInt(7), write_data(6, 0)).asTypeOf(new TLBELO)
            }
            is (CSR_ASID) {
                csrRegNxt.asid := Cat(0.U(8.W), csrReg.asid.asUInt(23, 10), write_data(9, 0)).asTypeOf(new ASID)
            }
            is (CSR_PGDL) {
                csrRegNxt.pgdl := Cat(write_data(31, 12), 0.U(12.W))
            }
            is (CSR_PGDH) {
                csrRegNxt.pgdh := Cat(write_data(31, 12), 0.U(12.W))
            }
            is (CSR_PGD) {
                csrRegNxt.pgd := csrReg.pgd
            }
            is (CSR_CPUID) {
                csrRegNxt.cpuid := write_data
            }
            is (CSR_SAVE0) {
                csrRegNxt.save0 := write_data
            }
            is (CSR_SAVE1) {
                csrRegNxt.save1 := write_data
            }
            is (CSR_SAVE2) {
                csrRegNxt.save2 := write_data
            }
            is (CSR_SAVE3) {
                csrRegNxt.save3 := write_data
            }
            is (CSR_TID) {
                csrRegNxt.tid := write_data
            }
            is (CSR_TCFG) {
                csrRegNxt.tcfg := Cat(0.U((32 - TIMER_LENGTH).W), write_data(TIMER_LENGTH - 1, 0)).asTypeOf(new TCFG)
                csrRegNxt.tval := Cat(write_data(TIMER_LENGTH - 1, 2), 0.U(2.W))
            }
            is (CSR_TVAL) {
                csrRegNxt.tval := csrReg.tval
            }
            is (CSR_TICLR) {
                csrRegNxt.ticlr := 0.U
                when (write_data(0)) {
                    csrRegNxt.estat.is_11 := 0.U
                }
            }
            is (CSR_LLBCTL) {
                csrRegNxt.llbctl.klo := write_data(2)
                when (write_data(1) === 1.U(1.W)) {
                    csrRegNxt.llbctl.rollb := 0.U(1.W)
                }
            }
            is (CSR_TLBRENTRY) {
                csrRegNxt.tlbrentry := Cat(write_data(31, 6), 0.U(6.W))
            }
            is (CSR_CTAG) {
                csrRegNxt.ctag := write_data
            }
            is (CSR_DMW0) {
                csrRegNxt.dmw0 := Cat(write_data(31, 29), 0.U(1.W), write_data(27, 25), 0.U(19.W), write_data(5,3), 0.U(2.W), write_data(0)).asTypeOf(new DMW)
            }
            is (CSR_DMW1) {
                csrRegNxt.dmw1 := Cat(write_data(31, 29), 0.U(1.W), write_data(27, 25), 0.U(19.W), write_data(5,3), 0.U(2.W), write_data(0)).asTypeOf(new DMW)
            }
        }
    }
// --------------------------------------------------------

// --------------------------------------------------------
// below code is for pc redirect
    io.redirect_pc := csrReg.era
// --------------------------------------------------------

// --------------------------------------------------------
// below code is for exception
    when (io.exception) {
        csrRegNxt.prmd.pplv      := csrReg.crmd.plv
        csrRegNxt.prmd.pie       := csrReg.crmd.ie
        csrRegNxt.crmd.plv       := 0.U(2.W)
        csrRegNxt.crmd.ie        := 0.U(1.W)
        csrRegNxt.era            := io.err_pc
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

        when (io.com_xcpt.bits.cause === TLBR) {
            csrRegNxt.crmd.da := 1.U(1.W)
            csrRegNxt.crmd.pg := 0.U(1.W)
            io.redirect_pc    := csrReg.tlbrentry
        } .otherwise {
            io.redirect_pc    := csrReg.eentry
        }

        when (io.com_xcpt.bits.vaddrWriteEnable) {
            csrRegNxt.badv := io.com_xcpt.bits.badvaddr
        }
    } .elsewhen(io.cmd === CSR_E) {
        csrRegNxt.crmd.ie  := csrReg.prmd.pie
        csrRegNxt.crmd.plv := csrReg.prmd.pplv
        when (csrReg.estat.ecode === 0x3f.U(ecodeBits.W)) { // 这里的 0x3f 有点硬编码了
            csrRegNxt.crmd.da := 0.U(1.W)
            csrRegNxt.crmd.pg := 1.U(1.W)
        }

        when(csrReg.llbctl.klo === 0.U(1.W)){
            csrRegNxt.llbctl.rollb := 0.U(1.W)
        }
        csrRegNxt.llbctl.klo := 0.U(1.W)
    } /* .elsewhen(io.is_llw) {
        csrRegNxt.llbctl.rollb := 1.U(1.W)
    } .elsewhen(io.is_scw) {
        csrRegNxt.llbctl.rollb := 0.U(1.W)
    } */
// --------------------------------------------------------

// --------------------------------------------------------
// below code is for interrupt
    val trint = (csrReg.estat.is_11 & csrReg.ecfg(11)  )
    val exint = (csrReg.estat.is9_2 & csrReg.ecfg(9, 2)).asUInt.orR
    val swint = (csrReg.estat.is1_0 & csrReg.ecfg(1, 0)).asUInt.orR

    io.interrupt := (trint | exint | swint) & csrReg.crmd.ie
// --------------------------------------------------------

// --------------------------------------------------------
// below code is for timer interrupt
    when (csrReg.tcfg.en.asBool) {
        when (csrReg.tval =/= 0.U) {    // decrement timer if it is not zero
            csrRegNxt.tval := csrReg.tval - 1.U
        } .otherwise {  // set interrupt if timer is zero
            when (csrReg.tcfg.periodic.asBool) {
                csrRegNxt.tval := Cat(csrReg.tcfg.initval, 0.U(2.W))
            } .otherwise {
                csrRegNxt.tcfg.en := 1.U(1.W)
            }
            csrRegNxt.estat.is_11 := 1.U(1.W)   // set timer interrupt flag bit
        }
    }
// --------------------------------------------------------

// --------------------------------------------------------
// below code is for debug output
    io.debug_csr_reg := csrRegNxt
// --------------------------------------------------------
}
