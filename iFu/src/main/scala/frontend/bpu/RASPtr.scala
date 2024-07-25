package iFu.frontend

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.util._

class RASPtr extends CoreBundle {
    /*--------------------------*/
    val numRasEntries = frontendParams.bpdParams.numRasEntries
    /*--------------------------*/
    val bits = UInt(log2Ceil(numRasEntries).W)

    def update(
        en: Bool, is_call: Bool, is_ret: Bool
    ): RASPtr = {
        val new_ptr = Wire(new RASPtr)
        new_ptr.bits :=
            Mux(en && is_call, WrapInc(bits, numRasEntries),
            Mux(en && is_ret , WrapDec(bits, numRasEntries),
                                             bits))
        new_ptr
    }
}
