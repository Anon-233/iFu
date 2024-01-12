package iFu.tlb

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._
import iFu.tlb.TLBConsts._
import iFu.backend._

object TLBConsts {
    val TLB_W_CMD_SZ    = 2
    val TLB_WR          = 0.U(TLB_W_CMD_SZ.W)
    val TLB_FILL        = 1.U(TLB_W_CMD_SZ.W)
    val TLB_INV         = 2.U(TLB_W_CMD_SZ.W)

    val TLB_R_CMD_SZ    = 2
    val TLB_X           = 0.U(TLB_R_CMD_SZ.W)
    val TLB_SRCH        = 1.U(TLB_R_CMD_SZ.W)
    val TLB_RD          = 2.U(TLB_R_CMD_SZ.W)

}

class TLBDataCsrContext extends CoreBundle {
    val asid_asid    = UInt(10.W)

    val tlbidx_index = UInt(5.W)
    val tlbidx_ps    = UInt(6.W)
    val tlbidx_ne    = Bool()

    val tlbehi_vppn  = UInt(19.W)

    val tlbelo0_v    = Bool()
    val tlbelo0_d    = Bool()
    val tlbelo0_plv  = UInt(2.W)
    val tlbelo0_mat  = UInt(2.W)
    val tlbelo0_g    = Bool()
    val tlbelo0_ppn  = UInt(20.W)

    val tlbelo1_v    = Bool()
    val tlbelo1_d    = Bool()
    val tlbelo1_plv  = UInt(2.W)
    val tlbelo1_mat  = UInt(2.W)
    val tlbelo1_g    = Bool()
    val tlbelo1_ppn  = UInt(20.W)


}

class TLBMeta extends CoreBundle {
    val vppn    = UInt((vaddrBits-13).W)
    val ps      = UInt(6.W)
    val g       = Bool()
    val asid    = UInt(10.W)
    val e       = Bool()
}

class TLBSingleData extends CoreBundle {
    val ppn     = UInt((vaddrBits-12).W)
    val plv     = UInt(2.W)
    val mat     = UInt(2.W)
    val d       = Bool()
    val v       = Bool()
}

class TLBData extends CoreBundle {
    val oddData  = new TLBSingleData
    val evenData = new TLBSingleData
}

class TLBEntry extends CoreBundle {
    val meta = new TLBMeta
    val data = new TLBData
}

class TLBRReq extends CoreBundle {
    val vaddr       = UInt(vaddrBits.W)
    val cmd         = UInt(TLB_R_CMD_SZ.W)
    val index       = UInt(log2Ceil(TLB_NUM).W) // 当is_tlb_rd为真时，需要index
}

class TLBRResp extends CoreBundle {
    val data = new TLBData
    val hit_idx = UInt(log2Ceil(TLB_NUM).W)
}

class TLBWReq extends CoreBundle {
    val rj_0_9  = UInt(10.W)    // 存放无效操作所需的ASID信息
    val rk      = UInt(32.W)    // 存放无效操作所需的虚拟地址信息
    val data    = new TLBSingleData
    val cmd     = UInt(TLB_W_CMD_SZ.W)
    val op_code = UInt(5.W)
}

class TLBDataManagerIO extends CoreBundle {
    val csr_context = Input(new TLBDataCsrContext)
    val r_req   = Flipped(Vec(memWidth + 1, Decoupled(new TLBRReq)))
    val r_resp  = Vec(memWidth + 1, Valid(new TLBRResp))
    val w_req   = Flipped(Decoupled(new TLBWReq))
}

class TLBDataManager extends CoreModule {
    val io = IO(new TLBDataManagerIO)

    val tlb_entries = Reg(Vec(TLB_NUM, Valid(new TLBEntry)))
    val random_counter = RegInit(0.U(log2Ceil(TLB_NUM).W))
    random_counter := random_counter + 1.U
    val is_full = !tlb_entries.exists(_.valid === false.B)
    val write_pos = Mux(is_full, random_counter, tlb_entries.indexWhere(_.valid === false.B))
    val csr_regs = io.csr_context
    for(i <- 0 until memWidth + 1) {
        io.r_resp(i) := 0.U
        for (j <- 0 until TLB_NUM) {
            when(tlb_entries(j).valid && io.r_req(i).valid){
                when((
                        io.r_req(i).bits.cmd === TLB_X &&
                        tlb_entries(j).bits.meta.vppn === io.r_req(i).bits.vaddr(vaddrBits - 1, 13)
                        ) ||
                        (
                                io.r_req(i).bits.cmd === TLB_SRCH &&
                                        tlb_entries(j).bits.meta.asid === csr_regs.asid_asid &&
                                        tlb_entries(j).bits.meta.vppn === csr_regs.tlbehi_vppn
                                ) ||
                        (
                                io.r_req(i).bits.cmd === TLB_RD &&
                                        tlb_entries(j).bits.meta.e &&
                                        io.csr_context.tlbidx_index === j.U
                        )

                ) {
                    io.r_resp(i).valid          := true.B
                    io.r_resp(i).bits.data      := tlb_entries(j).bits.data
                    io.r_resp(i).bits.hit_idx   := j.U
                }
            }

        }
    }
    when(io.w_req.valid){
        when(io.w_req.bits.cmd === TLB_WR || io.w_req.bits.cmd === TLB_FILL) {
            val write_meta = Wire(new TLBMeta)
            val write_index = csr_regs.tlbidx_index
            when(io.w_req.bits.cmd === TLB_FILL) {
                write_index := write_pos
            }
            val write_data = Wire(new TLBData)
            write_meta.vppn := csr_regs.tlbehi_vppn
            write_meta.ps := csr_regs.tlbidx_ps
            write_meta.g := csr_regs.tlbelo0_g && csr_regs.tlbelo1_g
            write_meta.asid := csr_regs.asid_asid
            write_meta.e := !csr_regs.tlbidx_ne

            write_data.evenData.ppn := csr_regs.tlbelo0_ppn
            write_data.evenData.plv := csr_regs.tlbelo0_plv
            write_data.evenData.mat := csr_regs.tlbelo0_mat
            write_data.evenData.d := csr_regs.tlbelo0_d
            write_data.evenData.v := csr_regs.tlbelo0_v

            write_data.oddData.ppn := csr_regs.tlbelo1_ppn
            write_data.oddData.plv := csr_regs.tlbelo1_plv
            write_data.oddData.mat := csr_regs.tlbelo1_mat
            write_data.oddData.d := csr_regs.tlbelo1_d
            write_data.oddData.v := csr_regs.tlbelo1_v

            tlb_entries(write_index).valid := true.B
            tlb_entries(write_index).bits.meta := write_meta
            tlb_entries(write_index).bits.data := write_data
        } .elsewhen(io.w_req.bits.cmd === TLB_INV) {
            when(io.w_req.bits.op_code === 0.U || io.w_req.bits.op_code === 1.U){
                for(i <- 0 until TLB_NUM) {
                    tlb_entries(i).valid := false.B
                }
            } .elsewhen(io.w_req.bits.op_code === 2.U) {
                for(i <- 0 until TLB_NUM) {
                    when(tlb_entries(i).bits.meta.g) {
                        tlb_entries(i).valid := false.B
                    }
                }
            } .elsewhen(io.w_req.bits.op_code === 3.U) {
                for (i <- 0 until TLB_NUM) {
                    when(!tlb_entries(i).bits.meta.g) {
                        tlb_entries(i).valid := false.B
                    }
                }
            } .elsewhen(io.w_req.bits.op_code === 4.U) {
                for (i <- 0 until TLB_NUM) {
                    when(!tlb_entries(i).bits.meta.g && tlb_entries(i).bits.meta.asid === io.w_req.bits.rj_0_9) {
                        tlb_entries(i).valid := false.B
                    }
                }
            } .elsewhen(io.w_req.bits.op_code === 5.U) {
                for (i <- 0 until TLB_NUM) {
                    when(!tlb_entries(i).bits.meta.g &&
                            tlb_entries(i).bits.meta.asid === io.w_req.bits.rj_0_9 &&
                            tlb_entries(i).bits.meta.vppn === io.w_req.bits.rk(vaddrBits - 1, 13)
                    ) {
                        tlb_entries(i).valid := false.B
                    }
                }
            } .elsewhen(io.w_req.bits.op_code === 6.U) {
                for (i <- 0 until TLB_NUM) {
                    when(tlb_entries(i).bits.meta.g &&
                            tlb_entries(i).bits.meta.asid === io.w_req.bits.rj_0_9 &&
                            tlb_entries(i).bits.meta.vppn === io.w_req.bits.rk(vaddrBits - 1, 13)
                    )
                    {
                        tlb_entries(i).valid := false.B
                    }
                }
            }
        }
    }
}

