package iFu.common

import chisel3._
import chisel3.util._

import iFu.common.Consts._

class CBusReq(val s: Int) extends CoreBundle {
    val valid = Bool()
    val isStore = Bool()
    val size = UInt(MSIZE1.getWidth.W)
    val addr = UInt(paddrBits.W)
    val data = UInt((1 << (s + 3)).W)
    val mask = UInt((nRowBytes).W)//两个cache这里的AXI可以不同
    val axiBurstType = UInt(AXI_BURST_INCR.getWidth.W)
    val axiLen = UInt(MLEN1.getWidth.W)
}

class CBusResp(val s: Int) extends CoreBundle{
    val data = UInt((1 << (s + 3)).W)
    val isLast = Bool()
    val ready = Bool()
}

class iCBusReq extends CBusReq(2) {
    val size = MSIZE4
    val axiBurstType = AXI_BURST_INCR
    val axiLen = MLEN16
}

class dCBusReq extends CBusReq(2) {
    val size = MSIZE4
    val axiBurstType = AXI_BURST_INCR
    val axiLen = MLEN16
}

class iCBusResp extends CBusResp(2)
class dCBusResp extends CBusResp(2)
