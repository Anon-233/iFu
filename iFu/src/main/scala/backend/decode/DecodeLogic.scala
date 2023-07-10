package iFu.frontend

import chisel3._
import chisel3.util.BitPat
import chisel3.util.experimental.decode._

object DecodeLogic {

    def apply(instr: UInt, default: BitPat, mapping: Iterable[(BitPat, BitPat)]): UInt =
        chisel3.util.experimental.decode.decoder(QMCMinimizer, instr, TruthTable(mapping, default))

    def apply(instr: UInt, default: Seq[BitPat], mapping: Iterable[(BitPat, Seq[BitPat])]): Seq[UInt] = {
        val nSignals = default.size     //default中控制信号的数量
        require(mapping.forall(_._2.size == nSignals),
            s"The number of signals doesn't match. default = $nSignals , mapping =  ${mapping.find(_._2.size != nSignals).get}"
        )
        val signalWidths = default.map(i => i.getWidth)     //每个控制信号的长度
        val totalWidth = signalWidths.sum                   //控制信号的总长度
        //每个控制信号的索引
        val signalIdxs = signalWidths.scan(totalWidth-1){ (l,r) => l-r}
        //返回译码结果
        val decoded = apply(instr, default.reduce(_ ## _), mapping.map { case (inst, signals) => (inst, signals.reduce(_ ## _)) })
            //将译码结果转换为Seq[BitPat]
        signalIdxs.zip(signalIdxs.tail).map { case (lidx, ridx) => decoded(lidx, ridx + 1) }.toList
    }
}