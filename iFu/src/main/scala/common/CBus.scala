package iFu.common

import chisel3._
import chisel3.util._

import iFu.common.Consts._

class CBusReq(val s: Int = MSIZE4, val ml: Int = MLEN16) extends CoreBundle {
    val dataWidth = s match {
        case MSIZE1   => 8
        case MSIZE2   => 16
        case MSIZE4   => 32
        case MSIZE8   => 64
        case MSIZE16  => 128
        case MSIZE32  => 256
        case MSIZE64  => 512
        case MSIZE128 => 1024
    }
    val mlen = ml match {
        case MLEN1   => 1
        case MLEN2   => 2
        case MLEN4   => 4
        case MLEN8   => 8
        case MLEN16  => 16
        case MLEN32  => 32
        case MLEN64  => 64
        case MLEN128 => 128
        case MLEN256 => 256
    }

    val valid = Bool()
    val isStore = Bool()
    val size = UInt(MSIZE1.getWidth.W)
    val addr = UInt(paddrBits.W)
    val data = UInt(dataWidth.W)
    val mask = UInt((mlen * dataWidth / 8).W)
    val axiBurstType = UInt(AXI_BURST_INCR.getWidth.W)
    val axiLen = UInt(MLEN1.getWidth.W)
}

class CBusResp(val s: Int = MSIZE4) extends CoreBundle{
    val dataWidth = s match {
        case MSIZE1   => 8
        case MSIZE2   => 16
        case MSIZE4   => 32
        case MSIZE8   => 64
        case MSIZE16  => 128
        case MSIZE32  => 256
        case MSIZE64  => 512
        case MSIZE128 => 1024
    }
    val data = UInt(dataWidth.W)
    val isLast = Bool()
    val ready = Bool()
}
