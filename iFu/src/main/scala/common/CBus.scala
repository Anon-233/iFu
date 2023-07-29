package iFu.common

import chisel3._
import chisel3.util._




class CbusReq extends CoreBundle{
    val valid = Bool()
    val isStore = Bool()
    val size = UInt(3.W)
    val addr = UInt(32.W)
    val data = UInt(32.W)
    val mask = UInt((nRowBytes).W)//两个cache这里的AXI可以不同
    val axiBurstType = UInt(2.W)
    val axiLen = UInt(8.W)
}

class CbusResp extends CoreBundle{
    val data = UInt(32.W)
    val isLast = Bool()
    val ready = Bool()
}