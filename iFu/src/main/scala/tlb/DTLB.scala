package iFu.tlb

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.common.CauseCode._
//
//第一步，

class DTLBCSRContext extends CoreBundle(){
    val plv = UInt(2.W)
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
    val paddr = UInt(paddrBits.W)
    val exception = Valid(new DTLBException())
}
class DTLBIO extends CoreBundle(){
    val req = Flipped(Vec(memWidth, Decoupled(new DTLBReq)))
    val resp = Output(Vec(memWidth, new DTLBResp))
//    val r_req = Output(Vec(memWidth, Valid(new RReq)))
//    val r_resp = Input(Vec(memWidth, Valid(new RResp)))
//    val w_req = Output(Valid(new WReq))
//    val w_resp = Input(Valid(new WResp))
    val csr_context = Input(new DTLBCSRContext)
    val kill = Input(Bool())

}

class DTLB extends CoreModule(){
    val io = IO(new DTLBIO)
//    when(io.req(0).bits.is_tlb_inst){
//        io.w_req.valid      := true.B
//        io.w_req.bits.vaddr := io.req(0).bits.vaddr
//        io.w_req.bits.cmd   := io.req(0).bits.cmd
//    }
    for(w <- 0 until memWidth){
        io.resp(w) := 0.U.asTypeOf(new DTLBResp)
        io.req(w).ready := true.B
        when(io.req(w).bits.vaddr(0) && io.req(w).bits.size === 1.U ||
            io.req(w).bits.vaddr(1, 0) =/= 0.U && io.req(w).bits.size === 2.U
        )
        {
            io.resp(w).exception.valid              := true.B
            io.resp(w).exception.bits.xcpt_cause    := ALE
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
}



