package iFu.frontend

import chisel3._
import chisel3.util._

import iFu.util._

class LHCacheIO extends Bundle {
    val s1_lh    = Input(Vec(4, UInt(13.W)))
    val s2_taken = Output(Vec(4, Valid(Bool())))
    val s3_cnt   = Input(Vec(4, UInt(2.W)))
}

class LHCache extends Module {
    val io = IO(new LHCacheIO)

    val cnts = Seq.fill(4) { SyncReadMem(64, UInt(2.W)) }

// ---------------------------------------------
//      Predict Logic
    def hash(hist: UInt): UInt = {
        hist(5, 0)
    }
    io.s2_taken := io.s1_lh zip cnts map { case (hist, cnt) =>
        val idx = hash(hist)
        val cnt_val = cnt.read(idx)
        val taken = Wire(Valid(Bool()))
        taken.valid := !(cnt_val(0) ^ cnt_val(1))
        taken.bits := cnt_val(1)
        taken
    }
// ---------------------------------------------

// ---------------------------------------------
    val s3_lh = RegNext(RegNext(io.s1_lh))
    s3_lh zip cnts zip io.s3_cnt foreach { case ((hist, cnt), cnt_val) =>
        val idx = hash(hist)
        cnt.write(idx, cnt_val)
    }
// ---------------------------------------------

// ---------------------------------------------
//      Performance Counter
    // TODO
// ---------------------------------------------
}
