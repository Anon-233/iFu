package iFu.lsu.utils

import chisel3._
import chisel3.util._

import iFu.common._
import iFu.common.Consts._

object GenByteMask {
    def apply(addr: UInt, size: UInt): UInt = {
        val mask = MuxCase(0.U(4.W), Seq(
            (size === 0.U) -> (1.U << addr(1, 0)),
            (size === 1.U) -> (3.U << (addr(1) << 1)),
            (size === 2.U) -> 15.U(4.W)
        ))
        mask
    }
}

class ForwardingAgeLogic(num_entries: Int) extends CoreModule{
    /** *********************************** */
    val numStqEntries = lsuParameters.numSTQEntries
    val numLdqEntries = lsuParameters.numLDQEntries
    val stqAddrSz = lsuParameters.stqAddrSz
    val ldqAddrSz = lsuParameters.ldqAddrSz
    /** ************************************ */
    val io = IO(new Bundle {
        val addr_matches = Input(UInt(num_entries.W)) // bit vector of addresses that match
        // between the load and the SAQ
        val youngest_st_idx = Input(UInt(stqAddrSz.W)) // needed to get "age"

        val forwarding_val = Output(Bool())
        val forwarding_idx = Output(UInt(stqAddrSz.W))
    })

    // generating mask that zeroes out anything younger than tail
    val age_mask = Wire(Vec(num_entries, Bool()))
    for (i <- 0 until num_entries) {
        age_mask(i) := true.B
        when(i.U >= io.youngest_st_idx) // currently the tail points PAST last store, so use >=
        {
            age_mask(i) := false.B
        }
    }

    // Priority encoder with moving tail: double length
    val matches = Wire(UInt((2 * num_entries).W))
    matches := Cat(io.addr_matches & age_mask.asUInt,
        io.addr_matches)

    val found_match = Wire(Bool())
    found_match := false.B
    io.forwarding_idx := 0.U

    // look for youngest, approach from the oldest side, let the last one found stick
    for (i <- 0 until (2 * num_entries)) {
        when(matches(i)) {
            found_match := true.B
            io.forwarding_idx := (i % num_entries).U
        }
    }

    io.forwarding_val := found_match
}
object storeMaskGen{
    def apply(addr: UInt, memSize: UInt): UInt = {
        val mask = WireInit(0.U(4.W))
        when(memSize === 0.U){
            when(addr === 0.U){mask := "b0001".U}
                    .elsewhen(addr === 1.U){mask := "b0010".U}
                    .elsewhen(addr === 2.U){mask := "b0100".U}
                    .elsewhen(addr === 3.U){mask := "b1000".U}
        }.elsewhen(memSize === 1.U){
            when(addr(1) === 0.U){mask := "b0011".U}
                    .elsewhen(addr(1) === 1.U){mask := "b1100".U}
        }.elsewhen(memSize === 2.U){
            mask := "b1111".U
        }
        mask
    }

}

object loadDataGen{
    def apply(addr: UInt, data:UInt, memSize:UInt,memSigned: Bool): UInt = {
        val loadData = WireInit(0.U(32.W))
        when(memSize === 0.U){
            when(addr === 0.U){
                when(memSigned) {
                    loadData := Cat(Fill(24, data(7)), data(7, 0))
                } .otherwise{
                    loadData := data(7,0)
                }
            }.elsewhen(addr === 1.U) {
                when(memSigned) {
                    loadData := Cat(Fill(24, data(15)), data(15, 8))
                }.otherwise {
                    loadData := data(15, 8)
                }
            }.elsewhen(addr === 2.U){
                when(memSigned) {
                    loadData := Cat(Fill(24, data(23)), data(23, 16))
                }.otherwise {
                    loadData := data(23, 16)
                }
            }.elsewhen(addr === 3.U){
                when(memSigned) {
                    loadData := Cat(Fill(24, data(31)), data(31, 24))
                }.otherwise {
                    loadData := data(31, 24)
                }
            }
        }.elsewhen(memSize === 1.U){
            when(addr(1) === 0.U){
                when(memSigned){
                    loadData := Cat(Fill(16,data(15)),data(15,0))
                }.otherwise{
                    loadData := data(15,0)
                }
            }.elsewhen(addr(1) === 1.U){
                when(memSigned) {
                    loadData := Cat(Fill(16, data(31)), data(31, 16))
                }.otherwise {
                    loadData := data(31, 16)
                }
            }
        }.elsewhen(memSize === 2.U){
            loadData := data(31,0)
        }
        loadData
    }
}
object storeDataGen{
    def apply(addr: UInt, data:UInt, memSize:UInt): UInt = {
        val storeData = WireInit(0.U.asTypeOf(Vec(4,UInt(8.W))))
        when(memSize === 0.U){
            when(addr === 0.U){ 
                storeData(0) := data(7,0)}
                    .elsewhen(addr === 1.U){storeData(1) := data(7,0)}
                    .elsewhen(addr === 2.U){storeData(2) := data(7,0)}
                    .elsewhen(addr === 3.U){storeData(3) := data(7,0)}
        }.elsewhen(memSize === 1.U){
            when(addr(1) === 0.U){
                storeData(0) := data(7,0)
                storeData(1) := data(15,8)}
            .elsewhen(addr(1) === 1.U){
                storeData(2) := data(7,0)
                storeData(3) := data(15,8)}
        }.elsewhen(memSize === 2.U){
            storeData(0) := data(7,0)
            storeData(1) := data(15,8)
            storeData(2) := data(23,16)
            storeData(3) := data(31,24)
        }
        storeData.asUInt
    }
}