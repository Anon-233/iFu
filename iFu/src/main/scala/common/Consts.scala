package iFu.common

import chisel3._
import chisel3.util._

object Consts {
    val X = BitPat("b?")
    val Y = BitPat("b1")
    val N = BitPat("b0")

    val BSRC_SZ = 2
    val BSRC_1  = 0.U(BSRC_SZ.W) // 1-cycle branch pred
    val BSRC_2  = 1.U(BSRC_SZ.W) // 2-cycle branch pred
    val BSRC_3  = 2.U(BSRC_SZ.W) // 3-cycle branch pred
    val BSRC_C  = 3.U(BSRC_SZ.W) // core branch resolution

    val CFI_SZ   = 2
    val CFI_X    = 0.U(CFI_SZ.W) // Not a CFI instruction
    val CFI_BR   = 1.U(CFI_SZ.W) // Branch
    val CFI_JAL  = 2.U(CFI_SZ.W) // JAL
    val CFI_JALR = 3.U(CFI_SZ.W) // JALR

    val IQT_SZ  = 2
    val IQT_INT = 1.U(IQT_SZ.W)
    val IQT_MEM = 2.U(IQT_SZ.W)

    val RT_X   = 0.U(1.W)
    val RT_FIX = 1.U(1.W)

    val immX   = BitPat("b???")
    val immU5  = 0.U(3.W)  // Cat(Fill(27,0.U),inst(14,10))
    val immU12 = 1.U(3.W) // Cat(Fill(20,0.U),inst(21,10))
    val immS12 = 2.U(3.W) //Cat(Fill(20,inst(21)),inst(21,10))
    val immS14 = 3.U(3.W) // Cat(Fill(16,inst(23)),inst(23,10),Fill(2,0.U))
    val immS16 = 4.U(3.W) // Cat(Fill(14,inst(25)),inst(25,10),Fill(2,0.U))
    val immU20 = 5.U(3.W) //Cat(inst(24,5),Fill(12,0.U))
    val immS20 = 6.U(3.W) //Cat(Fill(10,inst(24)),inst(24,5),Fill(2,0.U))
    val immS26 = 7.U(3.W) // Cat(Fill(4,inst(9)),inst(9,0),inst(25,10),Fill(2,0.U))

    val BR_N = 0.U(4.W)   // Next
    val BR_NE = 1.U(4.W)  // Branch on NotEqual
    val BR_EQ = 2.U(4.W)  // Branch on Equal
    val BR_GE = 3.U(4.W)  // Branch on Greater/Equal
    val BR_GEU = 4.U(4.W) // Branch on Greater/Equal Unsigned
    val BR_LT = 5.U(4.W)  // Branch on Less Than
    val BR_LTU = 6.U(4.W) // Branch on Less Than Unsigned
    val BR_J = 7.U(4.W)   // Jump
    val BR_JR = 8.U(4.W)  // Jump Register
}