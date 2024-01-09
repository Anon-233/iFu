
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
        val exception = Input(Bool())
        val xcpt_uop = Input(new MicroOp())
        val debug_csr_reg = Input(new CSRReg)
        val debug_event = Output(new debugEvent)
    })

    io.debug_event := 0.U.asTypeOf(new debugEvent)

    when (io.exception) {
        io.debug_event.excpvalid  := true.B
        io.debug_event.isEret := !io.xcpt_uop.exception && io.xcpt_uop.uopc === uopERET
        io.debug_event.intrNo := io.debug_csr_reg.estat.asUInt(12, 2)
        io.debug_event.ecode  := Cat(io.debug_csr_reg.estat.ecode, io.debug_csr_reg.estat.esubcode)
        io.debug_event.epc    := io.xcpt_uop.debug_pc
        io.debug_event.einst  := io.xcpt_uop.debug_inst
    }
}
