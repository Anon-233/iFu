package iFu.util

import chisel3._
import chisel3.util._
import iFu.common._

object MaskLower {
    def apply(in: UInt): UInt = {
        val n = in.getWidth
        (0 until n).map(i => in >> i.U).reduce(_ | _)
    }
}

object WrapInc {
    def apply(value: UInt, n: Int): UInt = {
        if (isPow2(n)) {
            (value + 1.U)(log2Ceil(n) - 1, 0)
        } else {
            val wrap = (value === (n - 1).U)
            Mux(wrap, 0.U, value + 1.U)
        }
    }
}

object WrapDec {
    // "n" is the number of increments, so we wrap at n-1.
    def apply(value: UInt, n: Int): UInt = {
        if (isPow2(n)) {
            (value - 1.U)(log2Ceil(n)-1,0)
        } else {
            val wrap = (value === 0.U)
            Mux(wrap, (n-1).U, value - 1.U)
        }
    }
}

object MaskUpper {
    def apply(in: UInt):UInt = { //假设第i位初次为1，则(n-1,i)为1
        val n = in.getWidth
        (0 until n).map(i => (in << i.U)(n-1,0)).reduce(_|_)
    }
}

object GetNewUopAndBrMask {
    def apply(uop: MicroOp, brupdate: BrUpdateInfo): MicroOp = {
        val newuop = WireInit(uop)
        newuop.brMask := uop.brMask & ~brupdate.b1.resolveMask
        newuop
    }
}

object SelectFirstN {
    def apply(in: UInt, n: Int) = {
        val sels = Wire(Vec(n, UInt(in.getWidth.W)))
        var mask = in

        for (i <- 0 until n) {
            sels(i) := PriorityEncoderOH(mask)
            mask = mask & ~sels(i)
        }

        sels
    }
}

object IsOlder
{
    def apply(i0: UInt, i1: UInt, head: UInt) = ((i0 < i1) ^ (i0 < head) ^ (i1 < head))
}
