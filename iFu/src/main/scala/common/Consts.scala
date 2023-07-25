package common

import chisel3._
import chisel3.util._

trait IQType
{
    val IQT_SZ = 2
    val IQT_INT = 1.U(IQT_SZ.W)
    val IQT_MEM = 2.U(IQT_SZ.W)
}
trait Consts extends IQType{

}
