package iFu.frontend

import chisel3._
import chisel3.util._

import iFu.common.FrontendParameters

trait FrontendUtils{
    this: FrontendParameters =>
    // How many "chunks"/interleavings make up a cache line?
    val numChunks = iCacheParams.lineBytes / iCacheParams.bankBytes

    // Which bank is the address pointing to?
    def bank(addr: UInt) = addr(log2Ceil(iCacheParams.bankBytes))

    def isLastBankInBlock(addr: UInt) = {
        addr(iCacheParams.offsetBits - 1, log2Ceil(iCacheParams.bankBytes)) === (numChunks - 1).U
    }

    def blockAlign(addr: UInt) = ~(~addr | (iCacheParams.lineBytes - 1).U)

    def bankAlign(addr: UInt) = ~(~addr | (iCacheParams.bankBytes - 1).U)

    def packetBasePC(addr: UInt) = addr >> log2Ceil(fetchBytes)

    def nextBank(addr: UInt) = bankAlign(addr) + iCacheParams.bankBytes.U

    def nextFetch(addr: UInt) = {
        bankAlign(addr) + Mux(isLastBankInBlock(addr), iCacheParams.bankBytes.U, fetchBytes.U)
    }

    def fetchMask(addr: UInt): UInt = {
        val idx = addr(log2Ceil(fetchWidth) + log2Ceil(instrBytes) - 1, log2Ceil(instrBytes))
        val shamt = idx(log2Ceil(fetchWidth) - 2, 0)
        val end_mask = Mux(isLastBankInBlock(addr), Fill(fetchWidth / 2, 1.U), Fill(fetchWidth, 1.U))
        ((1 << fetchWidth) - 1).U << shamt & end_mask

    }

    def bankMask(addr: UInt) = {
        val idx = addr(log2Ceil(fetchWidth) + log2Ceil(instrBytes) - 1, log2Ceil(instrBytes))
        Mux(isLastBankInBlock(addr), 1.U(2.W), 3.U(2.W))

    }
}