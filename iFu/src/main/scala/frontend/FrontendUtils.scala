package iFu.frontend

import chisel3._
import chisel3.util._

import iFu.common.FrontendParameters

object FrontendUtils extends FrontendParameters {
    // How many "chunks"/interleavings make up a cache line?
    val numChunks = iCacheParams.lineBytes / iCacheParams.bankBytes

    val nBanks    = iCacheParams.nBanks
    val bankBytes = iCacheParams.bankBytes
    val blockOffBits = iCacheParams.offsetBits
    // Which bank is the address pointing to?
    def bank(addr: UInt):UInt = addr(log2Ceil(iCacheParams.bankBytes))

    def isLastBankInBlock(addr: UInt):Bool = {
        addr(iCacheParams.offsetBits - 1, log2Ceil(iCacheParams.bankBytes)) === (numChunks - 1).U
    }

    def blockAlign(addr: UInt): UInt = ~(~addr | (iCacheParams.lineBytes - 1).U)

    def bankAlign(addr: UInt):UInt = ~(~addr | (iCacheParams.bankBytes - 1).U)

    def packetBasePC(addr: UInt):UInt = addr >> log2Ceil(fetchBytes)

    def nextBank(addr: UInt):UInt = bankAlign(addr) + iCacheParams.bankBytes.U

    def nextFetch(addr: UInt):UInt = {
        bankAlign(addr) + Mux(isLastBankInBlock(addr), iCacheParams.bankBytes.U, fetchBytes.U)
    }

    def fetchMask(addr: UInt):UInt = {
        val idx = addr(log2Ceil(fetchWidth) + log2Ceil(instrBytes) - 1, log2Ceil(instrBytes))
        val shamt = idx(log2Ceil(fetchWidth) - 2, 0)
        val end_mask = Mux(isLastBankInBlock(addr), Fill(fetchWidth / 2, 1.U), Fill(fetchWidth, 1.U))
        ((1 << fetchWidth) - 1).U << shamt & end_mask
    }

    def bankMask(addr: UInt):UInt = {
        Mux(isLastBankInBlock(addr), "b01".U(2.W), "b11".U(2.W))
    }

    def bank(addr: UInt) = if (nBanks == 2) addr(log2Ceil(bankBytes)) else 0.U

    def isLastBankInBlock(addr: UInt) = {
        (nBanks == 2).B && addr(blockOffBits - 1, log2Ceil(bankBytes)) === (numChunks - 1).U
    }

    def mayNotBeDualBanked(addr: UInt) = {
        require(nBanks == 2)
        isLastBankInBlock(addr)
    }

    def bankAlign(addr: UInt) = ~(~addr | (bankBytes - 1).U)

    def fetchIdx(addr: UInt) = addr >> log2Ceil(fetchBytes)


}