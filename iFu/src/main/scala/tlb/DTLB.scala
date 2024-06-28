package iFu.tlb

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.common.CauseCode._

class DTLBCsrContext extends CoreBundle {
    val crmd_da     = Bool()
    val crmd_pg     = Bool()
    val crmd_datm   = UInt(2.W)
    val crmd_plv    = UInt(2.W)

    val dmw0_plv0   = Bool()
    val dmw0_plv3   = Bool()
    val dmw0_mat    = UInt(2.W)
    val dmw0_pseg   = UInt(3.W)
    val dmw0_vseg   = UInt(3.W)

    val dmw1_plv0   = Bool()
    val dmw1_plv3   = Bool()
    val dmw1_mat    = UInt(2.W)
    val dmw1_pseg   = UInt(3.W)
    val dmw1_vseg   = UInt(3.W)
}

class DTLBException extends CoreBundle {
    val xcpt_cause = UInt(15.W)
}

class DTLBReq extends CoreBundle {
    val vaddr   = UInt(vaddrBits.W)
    val size    = UInt(2.W)
    val use_ldq = Bool()
    val use_stq = Bool()
}

class DTLBResp extends CoreBundle {
    val paddr          = UInt(paddrBits.W)
    val exception      = Valid(new DTLBException())
    val is_uncacheable = Bool()
}

class DTLBIO extends CoreBundle {
    val req              = Vec(memWidth, Input(new DTLBReq))
    val resp             = Vec(memWidth, Output(new DTLBResp))
    val r_req            = Vec(memWidth, Output(new TLBDataRReq))
    val r_resp           = Vec(memWidth, Flipped(Valid(new TLBDataRResp)))
    val dtlb_csr_context = Input(new DTLBCsrContext)
}

class DTLB extends CoreModule() {
    val io = IO(new DTLBIO)
    io.r_req := DontCare

    val csr_regs = io.dtlb_csr_context
    val da_mode = csr_regs.crmd_da && !csr_regs.crmd_pg
    val pg_mode = !csr_regs.crmd_da && csr_regs.crmd_pg
    if (!FPGAPlatform) dontTouch(da_mode)
    if (!FPGAPlatform) dontTouch(pg_mode)

    for (w <- 0 until memWidth) {
        val trans_resp = WireInit(0.U.asTypeOf(new DTLBResp))
        val vaddr = io.req(w).vaddr
        when(
            (vaddr(0) && io.req(w).size === 1.U) ||
                (vaddr(1, 0) =/= 0.U && io.req(w).size === 2.U)
        ) {
            trans_resp.exception.valid           := true.B
            trans_resp.exception.bits.xcpt_cause := ALE
        } .elsewhen(da_mode) {
            trans_resp.paddr          := io.req(w).vaddr
            trans_resp.is_uncacheable := csr_regs.crmd_datm === 0.U
        }.elsewhen(pg_mode) {
            val dmw0_en =
                ((csr_regs.dmw0_plv0 && csr_regs.crmd_plv === 0.U) ||
                 (csr_regs.dmw0_plv3 && csr_regs.crmd_plv === 3.U))    &&
                io.req(w).vaddr(31, 29) === csr_regs.dmw0_vseg         &&
                pg_mode
            val dmw1_en =
                ((csr_regs.dmw1_plv0 && csr_regs.crmd_plv === 0.U) ||
                 (csr_regs.dmw1_plv3 && csr_regs.crmd_plv === 3.U))    &&
                io.req(w).vaddr(31, 29) === csr_regs.dmw1_vseg         &&
                pg_mode
            if (!FPGAPlatform) dontTouch(dmw0_en)
            if (!FPGAPlatform) dontTouch(dmw1_en)

            when (dmw0_en || dmw1_en) {
                trans_resp.exception.valid := false.B
                trans_resp.paddr           := Cat(
                    Mux(dmw0_en, csr_regs.dmw0_pseg, csr_regs.dmw1_pseg),
                    io.req(w).vaddr(28, 0)
                )
                trans_resp.is_uncacheable  := (
                    (dmw0_en && (csr_regs.dmw0_mat === 0.U)) ||
                    (dmw1_en && (csr_regs.dmw1_mat === 0.U))
                )
            } .otherwise {
                io.r_req(w).vaddr := vaddr

                val entry = io.r_resp(w).bits.entry
                val odd_even_page = Mux(entry.meta.ps === 12.U, vaddr(12), vaddr(21))
                val data = entry.data(odd_even_page)

                when (!io.r_resp(w).valid) {
                    trans_resp.exception.valid           := true.B
                    trans_resp.exception.bits.xcpt_cause := TLBR
                } .otherwise {
                    when (!data.v) {
                        trans_resp.exception.valid           := true.B
                        trans_resp.exception.bits.xcpt_cause := Mux(io.req(w).use_ldq, PIL, PIS)
                    } .elsewhen (io.dtlb_csr_context.crmd_plv > data.plv) {
                        trans_resp.exception.valid           := true.B
                        trans_resp.exception.bits.xcpt_cause := PPI
                    } .elsewhen (io.req(w).use_stq && !data.d) {
                        trans_resp.exception.valid           := true.B
                        trans_resp.exception.bits.xcpt_cause := PME
                    }
                }
                trans_resp.paddr := Mux(
                    entry.meta.ps === 12.U,
                    Cat(data.ppn, io.req(w).vaddr(11, 0)),
                    Cat(data.ppn(paddrBits - 13, 9), vaddr(20, 0))
                )
                trans_resp.is_uncacheable := data.mat === 0.U
            }
        }
        io.resp(w) := RegNext(trans_resp)
    }
}
