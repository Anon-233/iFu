package iFu.frontend

import chisel3._
import chisel3.util.BitPat
import chisel3.util.experimental.decode._

object DecodeLogic {
    private def checkWidth(bp: BitPat, width: Int): BitPat = {
        require(bp.width == width)
        bp
    }

    def apply(instr: UInt, default: BitPat, mapping: Iterable[(BitPat, BitPat)]): UInt =
        chisel3.util.experimental.decode.decoder(QMCMinimizer, instr, TruthTable(mapping, default))

    def apply(instr: UInt, default: Seq[BitPat], mapping: Iterable[(BitPat, Seq[BitPat])]): Seq[UInt] = {
        val nSignals = default.size
        require(mapping.forall(_._2.size == nSignals),
            s"The number of signals doesn't match. default = $nSignals , mappingIn =  ${mapping.find(_._2.size != nSignals).get}"
        )
        val signalWidths = default.map(i => i.getWidth)
        val totalWidth = signalWidths.sum
        val signalIdxs = signalWidths.scan(totalWidth-1){
            case(l,r) => l-r
        }
        val decoded = apply(instr, default.reduce(_ ## _), mapping.map { case (in, out) => (in, out.reduce(_ ## _)) })
        //返回译码结果
        signalIdxs.zip(signalIdxs.tail).map { case (lidx, ridx) => decoded(lidx, ridx + 1) }.toList
    }
}