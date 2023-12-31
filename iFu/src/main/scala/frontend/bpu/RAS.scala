package iFu.frontend

import chisel3._
import chisel3.util._

import iFu.common._

class Ras extends CoreModule {
    val numRasEntries = frontendParams.bpdParams.numRasEntries

    val io = IO(new Bundle {
        val read_idx    = Input(UInt(log2Ceil(numRasEntries).W))
        val read_addr   = Output(UInt(vaddrBits.W))

        val write_valid = Input(Bool())
        val write_idx   = Input(UInt(log2Ceil(numRasEntries).W))
        val write_addr  = Input(UInt(vaddrBits.W))
    })

    val ras = Reg(Vec(numRasEntries, UInt(vaddrBits.W)))

    io.read_addr := Mux(
        RegNext(io.write_valid && io.write_idx === io.read_idx), RegNext(io.write_addr),
        RegNext(ras(io.read_idx))
    )

    when (io.write_valid) {
        ras(io.write_idx) := io.write_addr
    }
}