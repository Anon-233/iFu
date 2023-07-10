package iFu.frontend

import chisel3._
import chisel3.util.BitPat
import chisel3.util.experimental.decode._

object DecodeLogic {
    // TODO
    def apply(addr: UInt, default: BitPat, mapping: Iterable[(BitPat, BitPat)]): UInt =
      chisel3.util.experimental.decode.decoder(QMCMinimizer, addr, TruthTable(mapping, default))
}