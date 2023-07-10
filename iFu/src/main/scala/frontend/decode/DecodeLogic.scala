package iFu.frontend

import chisel3._
import chisel3.util.BitPat
import chisel3.util.experimental.decode._

object DecodeLogic {
    private def checkWidth(bp: BitPat, width: Int): BitPat = {
        if (bp.width == width) bp
        else {
            require(bp.width == width, s"Not aligned bp = '$bp',width = '$width'")
            val diff = width - bp.width
            require(diff > 0, s"Cannot pad '$bp' to '$width' because it is already '${bp.width}' bits wide!")
            BitPat(0.U(diff.W)) ## bp
        }
    }

    def apply(addr: UInt, default: BitPat, mapping: Iterable[(BitPat, BitPat)]): UInt =
      chisel3.util.experimental.decode.decoder(QMCMinimizer, addr, TruthTable(mapping, default))

    def apply(addr: UInt, default: Seq[BitPat], mappingIn: Iterable[(BitPat, Seq[BitPat])]): Seq[UInt] = {
        val nElts = default.size
        require(mappingIn.forall(_._2.size == nElts),
            s"All Seq[BitPat] must be of the same length, got $nElts vs. ${mappingIn.find(_._2.size != nElts).get}"
        )

        val elementsGrouped = mappingIn.map(_._2).transpose
        val elementWidths = elementsGrouped.zip(default).map { case (elts, default) =>
            (default :: elts.toList).map(_.getWidth).max //将default添加到列表的开头，最终得到一行元素中最大宽度，即每一个信号对应的宽度
        }
        val resultWidth = elementWidths.sum

        val elementIndices = elementWidths.scan(resultWidth - 1) { case (l, r) => l - r }

        val defaultsPadded = default.zip(elementWidths).map { case (bp, w) => checkWidth(bp, w) }
        val mappingInPadded = mappingIn.map { case (in, elts) =>
            in -> elts.zip(elementWidths).map { case (bp, w) => checkWidth(bp, w) }
        }
        val decoded = apply(addr, defaultsPadded.reduce(_ ## _), mappingInPadded.map { case (in, out) => (in, out.reduce(_ ## _)) })
        //返回译码结果
        elementIndices.zip(elementIndices.tail).map { case (msb, lsb) => decoded(msb, lsb + 1) }.toList
    }
}