package iFu.tlb

import chisel3._
import chisel3.util._
import iFu.common._
import iFu.common.CauseCode._
import iFu.backend.DMW
import iFu.common.Consts.FPGAPlatform

class ITLBCsrContext extends CoreBundle {
    val crmd_da = Bool()
    val crmd_pg = Bool()
    val crmd_datm = UInt(2.W)
    val crmd_plv = UInt(2.W)

    val dmw0_plv0 = Bool()
    val dmw0_plv3 = Bool()
    val dmw0_mat = UInt(2.W)
    val dmw0_pseg = UInt(3.W)
    val dmw0_vseg = UInt(3.W)

    val dmw1_plv0 = Bool()
    val dmw1_plv3 = Bool()
    val dmw1_mat = UInt(2.W)
    val dmw1_pseg = UInt(3.W)
    val dmw1_vseg = UInt(3.W)
}

class ITLBReq extends CoreBundle {
    val vaddr = UInt(vaddrBits.W)
}

// PIF PPI ADEF TLBR
class ITLBException extends CoreBundle {
    val xcpt_cause = UInt(causeCodeBits.W)
}

class ITLBResp extends CoreBundle {
    val paddr      = UInt(32.W)
    val exception = Valid(new ITLBException)
}

class ITLBIO extends CoreBundle {
    val req     = Input(new ITLBReq)
    val resp    = Output(new ITLBResp)
    val r_req   = Output(new TLBDataRReq)
    val r_resp  = Flipped(Valid(new TLBDataRResp))
    val itlb_csr_cxt    = Input(new ITLBCsrContext)
}

class ITLB extends CoreModule {
    val io = IO(new ITLBIO)

    io.r_req.vaddr := io.req.vaddr
    val r_resp = RegNext(io.r_resp)

    val csr_regs = io.itlb_csr_cxt
    val da_mode  = csr_regs.crmd_da && !csr_regs.crmd_pg
    val pg_mode  = !csr_regs.crmd_da && csr_regs.crmd_pg

    io.resp := 0.U.asTypeOf(new DTLBResp)
    val vaddr = RegNext(io.req.vaddr)
    when (vaddr(1, 0) =/= 0.U) {
        io.resp.exception.valid := true.B
        io.resp.exception.bits.xcpt_cause := ADEF
    } .elsewhen (da_mode) {
        io.resp.paddr := vaddr
    } .elsewhen (pg_mode) {
        val dmw0_en = (
            (csr_regs.dmw0_plv0 && csr_regs.crmd_plv === 0.U) ||
                (csr_regs.dmw0_plv3 && csr_regs.crmd_plv === 3.U)
            ) &&
            (vaddr(31, 29) === csr_regs.dmw0_vseg) &&
            pg_mode
        val dmw1_en = (
            (csr_regs.dmw1_plv0 && csr_regs.crmd_plv === 0.U) ||
                (csr_regs.dmw1_plv3 && csr_regs.crmd_plv === 3.U)
            ) &&
            (vaddr(31, 29) === csr_regs.dmw1_vseg) &&
            pg_mode
        if (!FPGAPlatform) dontTouch(dmw0_en)
        if (!FPGAPlatform) dontTouch(dmw1_en)
        when (dmw0_en || dmw1_en) {
            io.resp.paddr := Cat(Mux(dmw0_en, csr_regs.dmw0_pseg, csr_regs.dmw1_pseg), vaddr(28, 0))
            io.resp.exception.valid := false.B
        } .otherwise {
            io.resp := 0.U.asTypeOf(new DTLBResp)
            val entry = r_resp.bits.entry
            val odd_even_page = Mux(entry.meta.ps === 12.U, vaddr(12), vaddr(21))
            val data = entry.data(odd_even_page)
            when (!r_resp.valid) {
                io.resp.exception.valid := true.B
                io.resp.exception.bits.xcpt_cause := TLBR
            } .otherwise {
                when (!data.v) {
                    io.resp.exception.valid := true.B
                    io.resp.exception.bits.xcpt_cause := PIF
                } .elsewhen(csr_regs.crmd_plv > data.plv) {
                    io.resp.exception.valid := true.B
                    io.resp.exception.bits.xcpt_cause := PPI
                }
            }
            io.resp.paddr := Mux(entry.meta.ps === 12.U,
                Cat(data.ppn, vaddr(11, 0)), Cat(data.ppn(paddrBits - 13, 9), vaddr(20, 0)))
        }
    }
}
