package iFu.tlb

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.common.CauseCode._
//
//第一步，

class DTLBCsrContext extends CoreBundle(){
    val crmd_da     = Bool()
    val crmd_pg     = Bool()
    val crmd_datm   = UInt(2.W)
    val crmd_plv    = UInt(2.W)

    val dmw0_plv0   = Bool()
    val dmw0_plv3   = Bool()
    val dmw0_mat    = UInt(2.W)
    val dmw0_vseg   = UInt(3.W)

    val dmw1_plv0   = Bool()
    val dmw1_plv3   = Bool()
    val dmw1_mat    = UInt(2.W)
    val dmw1_vseg   = UInt(3.W)
}

class DTLBException extends CoreBundle(){
    val xcpt_cause = UInt(15.W)
}

class DTLBReq extends CoreBundle(){
    val vaddr = UInt(vaddrBits.W)
    val use_ldq = Bool()
    val use_stq = Bool()
    val passthrough = Bool()
    val size = UInt(2.W)

    val is_tlb_inst = Bool()
//    val cmd = Bits(TLB_CMD_SZ.W)
}
class DTLBResp extends CoreBundle(){
    val paddr               = UInt(paddrBits.W)
    val exception           = Valid(new DTLBException())
    val is_uncacheable      = Bool()
}
class DTLBIO extends CoreBundle(){
    val req         = Vec(memWidth, Flipped(Decoupled(new DTLBReq)))
    val resp        = Vec(memWidth, new DTLBResp)
    val r_req       = Vec(memWidth, Decoupled(new TLBDataRReq))
    val r_resp      = Vec(memWidth, Flipped(Valid(new TLBDataRResp)))
    val w_req       = Decoupled(new TLBDataWReq)
//    val w_resp = Input(Valid(new WResp))
    val dtlb_csr_context = Input(new DTLBCsrContext)
    val tlb_data_context = Input(new TLBDataCsrContext)
    val kill = Input(Bool())

}

class DTLB extends CoreModule(){
    val io = IO(new DTLBIO)
    io <> DontCare  //TODO 删除
//    when(io.req(0).bits.is_tlb_inst){
//        io.w_req.valid      := true.B
//        io.w_req.bits.vaddr := io.req(0).bits.vaddr
//        io.w_req.bits.cmd   := io.req(0).bits.cmd
//    }
    for(w <- 0 until memWidth){
        io.resp(w)          := 0.U.asTypeOf(new DTLBResp)
        io.resp(w).paddr    := io.req(w).bits.vaddr
        io.req(w).ready     := true.B
        when(io.req(w).valid) {
            when(
                (io.req(w).bits.vaddr(0) && io.req(w).bits.size === 1.U) ||
                        (io.req(w).bits.vaddr(1, 0) =/= 0.U && io.req(w).bits.size === 2.U)
            ) {
                io.resp(w).exception.valid := true.B
                io.resp(w).exception.bits.xcpt_cause := ALE
            }/*.elsewhen(*/
        }

//        io.r_req(w).valid := true.B
//        io.r_req(w).bits.addr := io.req(w).bits.vaddr

//        when(!io.r_resp(w).valid){
//            io.resp(w).exceptions.valid         := true.B
//            io.resp(w).exceptions.bits.is_tlbr  := true.B
//
//        } .elsewhen (io.r_resp(w).valid){
//            val meta = io.r_resp(w).bits.meta
//            when(meta.v){
//                when(io.req(w).bits.use_ldq === true.B) {
//                    io.resp(w).exceptions.bits.is_pil := true.B
//                }.elsewhen(io.req(w).bits.use_stq === true.B) {
//                    io.resp(w).exceptions.bits.is_pis := true.B
//                }
//            } .elsewhen(io.csr_context.plv < meta.plv) {
//                io.resp(w).exceptions.valid         := true.B
//                io.resp(w).exceptions.bits.is_ppi   := true.B
//            } .elsewhen(io.req(w).bits.use_stq && !meta.D) {
//                io.resp(w).exceptions.valid         := true.B
//                io.resp(w).exceptions.bits.is_pme   := true.B
//            }
//        }

    }
//    val data_uncache_en = Bool()
//    data_uncache_en := (da_mode && (csr_datm === 0.U)) ||
//        (dmw0_en && (csr_dmw0(`DMW_MAT) === 0.U)) ||
//        (dmw1_en && (csr_dmw1(`DMW_MAT) === 0.U)) ||
//        (data_addr_trans_en && (data_tlb_mat === 0.U))

//    for(w <- 0 until memWidth) {
//        io.r_req(w).valid := io.req(w).valid
//        io.r_req(w).bits.vaddr := io.req(w).bits.vaddr
//        io.r_req(w).bits.cmd :=
//    }

    //TODO disable_cache是一个寄存器,以及data_addr_trans_en的支持
    val csr_regs = io.dtlb_csr_context
    val da_mode = csr_regs.crmd_da && !csr_regs.crmd_pg
    val pg_mode = !csr_regs.crmd_da && csr_regs.crmd_pg
    for (w <- 0 until memWidth){

        val dmw0_en = ((csr_regs.dmw0_plv0 && csr_regs.crmd_plv === 0.U) ||
          (csr_regs.dmw0_plv3 && csr_regs.crmd_plv === 3.U)) &&
          (io.req(w).bits.vaddr(31, 29) === csr_regs.dmw0_vseg) &&
          pg_mode

        val dmw1_en = ((csr_regs.dmw1_mat(0) && csr_regs.crmd_plv === 0.U) ||
          (csr_regs.dmw1_plv3 && csr_regs.crmd_plv === 3.U)) &&
          (io.req(w).bits.vaddr(31, 29) === csr_regs.dmw1_vseg) &&
          pg_mode

        io.resp(w).is_uncacheable := (da_mode && csr_regs.crmd_datm === 0.U) ||
          (dmw0_en && (csr_regs.dmw0_mat === 0.U)) ||
          (dmw1_en && (csr_regs.dmw1_mat === 0.U))

        dontTouch(dmw0_en)
        dontTouch(dmw1_en)
    }
}



