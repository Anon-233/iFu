package common

import chisel3._
import chisel3.util._

trait BSRC {
    val BSRC_SZ = 2
    val BSRC_1  = 0.U(BSRC_SZ.W) // 1-cycle branch pred
    val BSRC_2  = 1.U(BSRC_SZ.W) // 2-cycle branch pred
    val BSRC_3  = 2.U(BSRC_SZ.W) // 3-cycle branch pred
    val BSRC_C  = 3.U(BSRC_SZ.W) // core branch resolution
}

trait CFIType {
    val CFI_SZ   = 2
    val CFI_X    = 0.U(CFI_SZ.W) // Not a CFI instruction
    val CFI_BR   = 1.U(CFI_SZ.W) // Branch
    val CFI_JAL  = 2.U(CFI_SZ.W) // JAL
    val CFI_JALR = 3.U(CFI_SZ.W) // JALR
}

trait IQType {
    val IQT_SZ  = 2
    val IQT_INT = 1.U(IQT_SZ.W)
    val IQT_MEM = 2.U(IQT_SZ.W)
}

object Consts with BSRC with CFIType with IQType {}