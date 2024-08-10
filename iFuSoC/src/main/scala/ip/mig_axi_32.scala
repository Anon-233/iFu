package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input, Output}
import common.{AXI4Full, AXI4Len, DDR3}

class mig_axi_32 extends BlackBox {
    val sParams = new AXI4Len
    sParams.awid = 8
    sParams.awregion = 0
    sParams.bid = 8
    sParams.arid = 8
    sParams.arregion = 0
    sParams.rid = 8
    val io = IO(new Bundle {
        val ddr3 = new DDR3
        val init_calib_complete = Output(Bool())
        val ui_clk = Output(Bool())
        val ui_clk_sync_rst = Output(Bool())
        val sys_clk_i = Input(Bool())
        val clk_ref_i = Input(Bool())
        val sys_rst = Input(Bool())
        val mmcm_locked = Output(Bool())
        val app_sr_active = Output(Bool())
        val app_ref_ack = Output(Bool())
        val app_zq_ack = Output(Bool())
        val app_sr_req = Input(Bool())
        val app_ref_req = Input(Bool())
        val app_zq_req = Input(Bool())
        val aresetn = Input(Bool())
        val s_axi = Flipped(new AXI4Full(sParams))
    })
}
