package iFu.util

import chisel3._
import chisel3.util._
import scala.language.implicitConversions

import iFu.backend.HasUop
import iFu.common._
import iFu.common.Consts._

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

object maskMatch {
    def apply(msk1: UInt, msk2: UInt): Bool = (msk1 & msk2) =/= 0.U
}

object IsKilledByBranch{
    def apply(brupdate: BrUpdateInfo, uop: MicroOp): Bool = {
        return maskMatch(brupdate.b1.mispredictMask, uop.brMask)
    }

    def apply(brupdate: BrUpdateInfo, uop_mask: UInt): Bool = {
        return maskMatch(brupdate.b1.mispredictMask, uop_mask)
    }
}

object GetNewBrMask {
    def apply(brupdate: BrUpdateInfo, uop: MicroOp): UInt = {
        return uop.brMask & ~brupdate.b1.resolveMask
    }

    def apply(brupdate: BrUpdateInfo, br_mask: UInt): UInt = {
        return br_mask & ~brupdate.b1.resolveMask
    }
}

object UpdateBrMask {
    def apply(brupdate: BrUpdateInfo, uop: MicroOp): MicroOp = {
        val out = WireInit(uop)
        out.brMask := GetNewBrMask(brupdate, uop)
        out
    }
    def apply[T <: HasUop](brupdate: BrUpdateInfo, bundle: T): T = {
        val out = WireInit(bundle)
        out.uop.brMask := GetNewBrMask(brupdate, bundle.uop.brMask)
        out
    }
    def apply[T <: HasUop](brupdate: BrUpdateInfo, bundle: Valid[T]): Valid[T] = {
        val out = WireInit(bundle)
        out.bits.uop.brMask := GetNewBrMask(brupdate, bundle.bits.uop.brMask)
        out.valid := bundle.valid && !IsKilledByBranch(brupdate, bundle.bits.uop.brMask)
        out
    }
}

object AlignPCToBoundary
{
    def apply(pc: UInt, b: Int): UInt = {
        // Invert for scenario where pc longer than b
        //   (which would clear all bits above size(b)).
        ~(~pc | (b-1).U)
    }
}

object Sext
{
    def apply(x: UInt, length: Int): UInt = {
        if (x.getWidth == length) return x
        else return Cat(Fill(length-x.getWidth, x(x.getWidth-1)), x)
    }
}
object immGen
{
    def apply(immPacked: UInt, immType: UInt): SInt = {
        val imm = WireInit(0.U(32.W))
        imm := MuxLookup(immType, 0.U)(Seq(
            immU5   -> Cat(0.U(27.W),immPacked(14,10)),
            immU12  -> Cat(0.U(20.W),immPacked(21,10)),
            immS12  -> Cat(Fill(20,immPacked(21)),immPacked(21,10)),
            immS14  -> Cat(Fill(16,immPacked(23)),immPacked(23,10),0.U(2.W)),
            immS16  -> Cat(Fill(14,immPacked(25)),immPacked(25,10),0.U(2.W)),
            immU20  -> Cat(immPacked(24,5),0.U(12.W)),
            immS20  -> Cat(Fill(10,immPacked(24)),immPacked(24,5),0.U(2.W)),
            immS26  -> Cat(Fill(4,immPacked(9)),immPacked(9,0),immPacked(25,10),0.U(2.W)),
            immCSR  -> Cat(0.U(18.W),immPacked(23,10)),
            immCID  -> Cat(0.U(18.W), CSR_TID)
        ))
        imm.asSInt
    }
}

object ImplicitCast {
    implicit def uintToBitPat(x: UInt): BitPat = BitPat(x)
}

object FindMin {
    def apply(in: Vec[UInt], valid: Vec[Bool]): UInt = {
        val bits = in.head.getWidth
        if (in.size == 1) {
            return Mux(valid.head, in.head.asUInt, -1.S(bits.W).asUInt)
        } else if (in.size == 2) {
            return Mux(valid(0), Mux(valid(1), 
                    Mux(in(0) < in(1), in(0), in(1)), in(0)),
                    Mux(valid(1), in(1), -1.S(bits.W).asUInt
            ))
        } else {
            val half = in.size / 2
            val left = VecInit((0 until half).map(i => in(i)))
            val right = VecInit((half until in.size).map(i => in(i)))
            val leftValid = VecInit((0 until half).map(i => valid(i)))
            val rightValid = VecInit((half until in.size).map(i => valid(i)))
            return Mux(
                FindMin(left, leftValid) < FindMin(right, rightValid),
                    FindMin(left, leftValid),
                    FindMin(right, rightValid)
            )
        }
    }
}

object FindMinPos {
    def apply(in: Vec[UInt], valid: Vec[Bool]): UInt = {
        val size = in.size
        val min = FindMin(in, valid)
        val pos_oh = VecInit((0 until size).map(i => Mux(in(i) === min, true.B, false.B))).asUInt
        return PriorityEncoder(pos_oh)
    }
}
