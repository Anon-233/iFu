
package iFu
import chisel3._
import chisel3.util._

import iFu.common._
import iFu.backend._
import iFu.util._
import iFu.common.Consts._
import iFu.common.CauseCode._
import chisel3._
import chisel3.util._


class eventDetector extends CoreModule {
    val io = IO(new Bundle{
       val commit = Input(new CommitSignals)
       val debug_csr_reg = Input(new CSRReg)
       val debug_event = Output(new debugEvent)
    })

    val xcpt_valids = Wire(Vec(coreWidth, Bool()))
    for (i <- 0 until coreWidth) {
        xcpt_valids(i) :=
            /* io.commit.arch_valids(i) && */
            (io.commit.uops(i).exception || io.commit.uops(i).uopc === uopERET)
    }
    val xcpt_idx = PriorityEncoder(xcpt_valids)
    val xcpt_uop = io.commit.uops(xcpt_idx)

    io.debug_event := 0.U.asTypeOf(new debugEvent)

    when (xcpt_valids.reduce(_|_)) {
        io.debug_event.excpvalid  := true.B
        io.debug_event.isEret := !xcpt_uop.exception && xcpt_uop.uopc === uopERET
        io.debug_event.intrNo := io.debug_csr_reg.asUInt(12, 2)
        io.debug_event.ecode  := Cat(io.debug_csr_reg.estat.ecode, io.debug_csr_reg.estat.esubcode)
        io.debug_event.epc    := xcpt_uop.debug_pc
        io.debug_event.einst  := xcpt_uop.debug_inst
    }
}
