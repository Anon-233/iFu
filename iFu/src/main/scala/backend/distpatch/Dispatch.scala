package backend.distpatch

import chisel3._
import chisel3.util._
import common.Consts
import iFu.common.{CoreBundle, CoreModule, MicroOp}



class DispatchIO extends CoreBundle
{
    // incoming microops from rename2
    val ren_uops = Vec(coreWidth, Flipped(DecoupledIO(new MicroOp)))

    // outgoing microops to issue queues
    // N issues each accept up to dispatchWidth uops
    // dispatchWidth may vary between issue queues
    val dis_uops = MixedVec(issueParams.map(ip=>Vec(ip.dispatchWidth, DecoupledIO(new MicroOp))))
}

abstract class Dispatcher extends CoreModule
{
    val io = IO(new DispatchIO)
}

/**
 * This Dispatcher assumes worst case, all dispatched uops go to 1 issue queue
 * This is equivalent to BOOMv2 behavior
 */
class BasicDispatcher extends Consts with Dispatcher
{
    issueParams.map(ip=>require(ip.dispatchWidth == coreWidth))

    val ren_readys = io.dis_uops.map(d=>VecInit(d.map(_.ready)).asUInt).reduce(_&_)

    for (w <- 0 until coreWidth) {
        io.ren_uops(w).ready := ren_readys(w)
    }

    for {i <- 0 until issueParams.size
         w <- 0 until coreWidth} {
        val issueParam = issueParams(i)
        val dis        = io.dis_uops(i)

        dis(w).valid := io.ren_uops(w).valid && ((io.ren_uops(w).bits.iqType & issueParam.iqType.U) =/= 0.U)
        dis(w).bits  := io.ren_uops(w).bits
    }
}
