package ram

import chisel3._
import chisel3.util.log2Ceil
import iFu.common.Consts.FPGAPlatform

class SDPRam[T <: Data](size: Int, t: T, lineSize: Int = 1) extends Module {
    val addrBits = log2Ceil(size)
    val io = IO(new Bundle {
        val raddr = Input(UInt(addrBits.W))
        val rdata = Output(t)
        val wen = Input(Bool())
        val waddr = Input(UInt(addrBits.W))
        val wstrobe = Input(UInt(lineSize.W))
        val wdata = Input(t)
    })
    require(lineSize == 1 || t.getWidth % 8 == 0 || t.getWidth % 9 == 0)
    if (FPGAPlatform) {
        val mem = Module(new xpm_memory_sdpram(log2Ceil(size), t.getWidth * lineSize, t.getWidth))
        mem.io.clka := clock.asBool
        mem.io.clkb := clock.asBool
        mem.io.ena := io.wen
        mem.io.enb := true.B
        mem.io.addra := io.waddr
        mem.io.addrb := io.raddr
        mem.io.wea := io.wstrobe
        mem.io.dina := io.wdata.asUInt
        io.rdata := mem.io.doutb.asTypeOf(t)
        mem.io.regceb := true.B
        mem.io.rstb := false.B
        mem.io.sleep := false.B
        mem.io.injectdbiterra := false.B
        mem.io.injectsbiterra := false.B
    } else {
        val mem = SyncReadMem(size, t)
        io.rdata := mem.read(io.raddr)
        when (io.wen) {
            mem.write(io.waddr, io.wdata)
        }
    }
}
