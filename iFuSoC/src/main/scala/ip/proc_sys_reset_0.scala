package ip

import chisel3.{BlackBox, Bool, Bundle, Input, Output}

class proc_sys_reset_0 extends BlackBox {
    val io = IO(new Bundle {
        val slowest_sync_clk = Input(Bool())
        val ext_reset_in = Input(Bool())
        val aux_reset_in = Input(Bool())
        val mb_debug_sys_rst = Input(Bool())
        val dcm_locked = Input(Bool())
        val mb_reset = Output(Bool())
        val bus_struct_reset = Output(Bool())
        val peripheral_reset = Output(Bool())
        val interconnect_aresetn = Output(Bool())
        val peripheral_aresetn = Output(Bool())
    })
}
