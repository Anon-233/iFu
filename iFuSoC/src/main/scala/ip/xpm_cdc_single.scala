package ip

import chisel3.{BlackBox, Bool, Bundle, Input, Output}

class xpm_cdc_single extends BlackBox(Map(
    "DEST_SYNC_FF" -> 2,
    "INIT_SYNC_FF" -> 0,
    "SIM_ASSERT_CHK" -> 0,
    "SRC_INPUT_REG" -> 1
)){
    val io = IO(new Bundle {
        val dest_out = Output(Bool())
        val dest_clk = Input(Bool())
        val src_clk = Input(Bool())
        val src_in = Input(Bool())
    })
}
