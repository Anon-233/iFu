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

    val BR_N   = 0.U(4.W) // Next
    val BR_NE  = 1.U(4.W) // Branch on NotEqual
    val BR_EQ  = 2.U(4.W) // Branch on Equal
    val BR_GE  = 3.U(4.W) // Branch on Greater/Equal
    val BR_GEU = 4.U(4.W) // Branch on Greater/Equal Unsigned
    val BR_LT  = 5.U(4.W) // Branch on Less Than
    val BR_LTU = 6.U(4.W) // Branch on Less Than Unsigned
    val BR_J   = 7.U(4.W) // Jump
    val BR_JR  = 8.U(4.W) // Jump Register

    val OP1_X    = BitPat("b??")
    val OP1_RS1  = 0.U(2.W) // Register Source #1
    val OP1_ZERO = 1.U(2.W)
    val OP1_PC   = 2.U(2.W)

    val OP2_X    = BitPat("b???")
    val OP2_RS2  = 0.U(3.W) // Register Source #2
    val OP2_IMM  = 1.U(3.W) // immediate
    val OP2_ZERO = 2.U(3.W) // constant 0
    val OP2_NEXT = 3.U(3.W) // constant 4 (for PC + 4)

    val REN_0 = false.B
    val REN_1 = true.B

    val MEN_X = false.B
    val MEN_0 = false.B
    val MEN_1 = true.B

    val AXI_BURST_FIXED = 0.U(2.W)
    val AXI_BURST_INCR = 1.U(2.W)
    val AXI_BURST_WRAP = 2.U(2.W)
    val AXI_BURST_RESERVED = 3.U(2.W)

    
    val MLEN1 = 0x0.U(8.W)
    val MLEN2 = 0x1.U(8.W)
    val MLEN4 = 0x3.U(8.W)
    val MLEN8 = 0x7.U(8.W)
    val MLEN16 = 0xf.U(8.W)//最大是16拍???
    val MLEN32 = 0x1f.U(8.W)
    val MLEN64 = 0x3f.U(8.W)
    val MLEN128 = 0x7f.U(8.W)
    val MLEN256 = 0xff.U(8.W)

    val AXI_BURST_NUM = 16.U //待确定??????

    //可以取Len的长度是1 2 4 8 16 (能扩展？？？？)
    val AXI_BURST_LEN = Mux(AXI_BURST_NUM === 16.U, MLEN16, MLEN1)

    
    val MSIZE1 = 0.U(3.W)
    val MSIZE2 = 1.U(3.W)
    val MSIZE4 = 2.U(3.W)//最大是一拍4个bytes（32位)??????
    val MSIZE8 = 3.U(3.W)
    val MSIZE16 = 4.U(3.W)
    val MSIZE32 = 5.U(3.W)
    val MSIZE64 = 6.U(3.W)
    val MSIZE128 = 7.U(3.W)
    
}