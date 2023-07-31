package iFu.common

import chisel3._
import chisel3.util._

import iFu.common.Consts._

class CBusReq extends CoreBundle {
    val dataWidth = 32

    val valid = Bool()
    val isStore = Bool()
    val size = UInt(MSIZE1.getWidth.W)
    val addr = UInt(paddrBits.W)
    val data = UInt(dataWidth.W)
    val mask = UInt(4.W)
    val axiBurstType = UInt(AXI_BURST_INCR.getWidth.W)
    val axiLen = UInt(MLEN1.getWidth.W)
}

class CBusResp extends CoreBundle{
    val dataWidth = 32
    
    val data = UInt(dataWidth.W)
    val isLast = Bool()
    val ready = Bool()
}
