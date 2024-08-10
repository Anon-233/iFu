package SoC

import chisel3._
import chisel3.experimental.Analog
import chisel3.util.Cat
import common._
import ip._

class iFuSoC extends RawModule {
    val io = IO(new Bundle {
        val clk = Input(Bool())
        val resetn = Input(Bool())
        val gpio = new GPIO
        val ddr3 = new DDR3
        val mac = new MAC
        val phy_rstn = Output(Bool())
        val ejtag = new EJTAG
        val uart = new UART
        val nand = new NAND
        val spi = new SPI
        val lcd = new LCD
        val ps2 = new PS2
        val tft = new TFT
    })
    val aclk = Wire(Bool())
    val aresetn = Wire(Bool())
    val interconnect_aresetn = Wire(Bool())
    val cpu_clk = Wire(Bool())
    val cpu_aresetn = Wire(Bool())
    val uncore_clk = Wire(Bool())
    val clk_locked = Wire(Bool())
    val ps2_int = Wire(Bool())
    val clk_100 = Wire(Bool())
    val clk_25 = Wire(Bool())
    val c1_clk_0 = Wire(Bool())
    val cpu_reset_p = Wire(Bool())
    cpu_aresetn := !cpu_reset_p
    aclk := uncore_clk
    
    val ps2_int_cpu = Wire(Bool())
    val dma_int = Wire(Bool())
    val nand_int = Wire(Bool())
    val spi_inta_o = Wire(Bool())
    val uart0_int = Wire(Bool())
    val mac_int = Wire(Bool())
    val int_out = Wire(UInt(8.W))
    int_out := Cat(0.U(2.W), ps2_int_cpu, dma_int, nand_int, spi_inta_o, uart0_int, mac_int)
    
    val xpm_cdc_single_int = Module(new xpm_cdc_single)
    ps2_int_cpu := xpm_cdc_single_int.io.dest_out
    xpm_cdc_single_int.io.dest_clk := cpu_clk
    xpm_cdc_single_int.io.src_clk := clk_100
    xpm_cdc_single_int.io.src_in := ps2_int
    
    val core = Module(new core_top)
    core.io.aclk := cpu_clk
    core.io.aresetn := cpu_aresetn
    core.io.intrpt := int_out
    
    val axi_clock_converter = Module(new axi_clock_converter_0)
    axi_clock_converter.io.s_axi_aclk := cpu_clk
    axi_clock_converter.io.s_axi_aresetn := cpu_aresetn
    axi_clock_converter.io.m_axi_aclk := aclk
    axi_clock_converter.io.m_axi_aresetn := aresetn
    
    val axi_slave_mux2 = Module(new axi_slave_mux2)
    axi_slave_mux2.io.axi_s_aclk := aclk
    axi_slave_mux2.io.axi_s_aresetn := interconnect_aresetn
    axi_slave_mux2.io.spi_boot := true.B
    
    val axi_slave_mux = Module(new axi_slave_mux)
    axi_slave_mux.io.axi_s_aclk := aclk
    axi_slave_mux.io.axi_s_aresetn := interconnect_aresetn
    axi_slave_mux.io.spi_boot := true.B
    
    val spi = Module(new spi_flash_ctrl)
    spi.io.aclk := aclk
    spi.io.aresetn := aresetn
    spi.io.spi_addr := 0x1fe8.asUInt
    spi.io.fast_startup := false.B
    spi_inta_o := spi.io.inta_o
    spi.io.power_down_req := false.B
    BulkConnect(spi.io, io.spi, new SPI)
    
    val confreg = Module(new confreg)
    confreg.io.aclk := aclk
    confreg.io.aresetn := aresetn
    BulkConnect(confreg.io, io.gpio, new GPIO)
    
    val ethernet = Module(new ethernet_top)
    ethernet.io.hclk := aclk
    ethernet.io.hrst_ := aresetn
    BulkConnect(ethernet.io, io.mac, new MAC)
    mac_int := ethernet.io.interrupt_0
    
    val clk_pll_33 = Module(new clk_pll_33)
    clk_pll_33.io.clk_in1 := io.clk
    clk_pll_33.io.resetn := io.resetn
    clk_locked := clk_pll_33.io.locked
    cpu_clk := clk_pll_33.io.clk_out1
    uncore_clk := clk_pll_33.io.clk_out2
    clk_100 := clk_pll_33.io.clk_100
    clk_25 := clk_pll_33.io.clk_25
    
    val clk_pll_1 = Module(new clk_wiz_0)
    clk_pll_1.io.clk_in1 := io.clk
    
    val mig_axi_interconnect = Module(new axi_interconnect_0)
    mig_axi_interconnect.io.INTERCONNECT_ARESETN := interconnect_aresetn
    mig_axi_interconnect.io.INTERCONNECT_ACLK := c1_clk_0
    mig_axi_interconnect.io.S00_AXI_ACLK := aclk
    mig_axi_interconnect.io.S01_AXI_ACLK := aclk
    mig_axi_interconnect.io.S02_AXI_ACLK := aclk
    mig_axi_interconnect.io.S03_AXI_ACLK := aclk
    mig_axi_interconnect.io.S04_AXI_ACLK := clk_100
    mig_axi_interconnect.io.S05_AXI_ACLK := clk_100
    mig_axi_interconnect.io.S06_AXI_ACLK := clk_100
    mig_axi_interconnect.io.M00_AXI_ACLK := c1_clk_0
    
    val mig_axi = Module(new mig_axi_32)
    c1_clk_0 := mig_axi.io.ui_clk
    mig_axi.io.clk_ref_i := clk_pll_1.io.clk_out1
    mig_axi.io.sys_clk_i := io.clk
    mig_axi.io.sys_rst := clk_locked
    mig_axi.io.app_sr_req := false.B
    mig_axi.io.app_ref_req := false.B
    mig_axi.io.app_zq_req := false.B
    mig_axi.io.aresetn := mig_axi_interconnect.io.M00_AXI_ARESET_OUT_N
    mig_axi.io.ddr3 <> io.ddr3
    
    val dma_master0 = Module(new dma_master)
    dma_master0.io.clk := aclk
    dma_master0.io.rst_n := aresetn
    dma_int := dma_master0.io.dma_int
    
    val apb_dev = Module(new axi2apb_misc)
    apb_dev.io.clk := aclk
    apb_dev.io.rst_n := aresetn
    apb_dev.io.uart0 <> io.uart
    apb_dev.io.nand_type := 2.U(2.W)
    apb_dev.io.nand <> io.nand
    uart0_int := apb_dev.io.uart0_int
    nand_int := apb_dev.io.nand_int
    
    val main_xbar = Module(new main_xbar)
    main_xbar.io.aclk := aclk
    main_xbar.io.aresetn := interconnect_aresetn
    
    val axi_clk_converter_apb = Module(new axi_clock_converter_0)
    axi_clk_converter_apb.io.s_axi_aclk := aclk
    axi_clk_converter_apb.io.s_axi_aresetn := aresetn
    axi_clk_converter_apb.io.m_axi_aclk := clk_100
    axi_clk_converter_apb.io.m_axi_aresetn := aresetn
    
    val apb_axi4lite_to_axi3 = Module(new axi_protocol_converter_0)
    apb_axi4lite_to_axi3.io.aclk := clk_100
    apb_axi4lite_to_axi3.io.aresetn := aresetn
    
    val apb_bridge = Module(new axi_apb_bridge_connect)
    apb_bridge.io.s_axi_aclk := clk_100
    apb_bridge.io.s_axi_aresetn := aresetn
    
    val lcd_controller = Module(new nt35510)
    lcd_controller.io.clk := clk_100
    lcd_controller.io.nrst := aresetn
    lcd_controller.io.LCD <> io.lcd
    
    val ps2 = Module(new ps2)
    ps2.io.clk := clk_100
    ps2.io.reset_n := aresetn
    ps2.io.PS2 <> io.ps2
    ps2_int := ps2.io.irq
    
    val axi_clk_converter_fb_wr = Module(new axi_clock_converter_0)
    axi_clk_converter_fb_wr.io.s_axi_aclk := aclk
    axi_clk_converter_fb_wr.io.s_axi_aresetn := aresetn
    axi_clk_converter_fb_wr.io.m_axi_aclk := clk_100
    axi_clk_converter_fb_wr.io.m_axi_aresetn := aresetn
    
    val axi_clk_converter_fd_rd = Module(new axi_clock_converter_0)
    axi_clk_converter_fd_rd.io.s_axi_aclk := aclk
    axi_clk_converter_fd_rd.io.s_axi_aresetn := aresetn
    axi_clk_converter_fd_rd.io.m_axi_aclk := clk_100
    axi_clk_converter_fd_rd.io.m_axi_aresetn := aresetn
    
    val axi_clk_converter_tft = Module(new axi_clock_converter_0)
    axi_clk_converter_tft.io.s_axi_aclk := aclk
    axi_clk_converter_tft.io.s_axi_aresetn := aresetn
    axi_clk_converter_tft.io.m_axi_aclk := clk_100
    axi_clk_converter_tft.io.m_axi_aresetn := aresetn
    
    val fb_read_converter = Module(new axi_protocol_converter_0)
    fb_read_converter.io.aclk := clk_100
    fb_read_converter.io.aresetn := aresetn
    
    val fb_write_converter = Module(new axi_protocol_converter_0)
    fb_write_converter.io.aclk := clk_100
    fb_write_converter.io.aresetn := aresetn
    
    val tft_protocol_converter = Module(new axi_protocol_converter_0)
    tft_protocol_converter.io.aclk := clk_100
    tft_protocol_converter.io.aresetn := aresetn
    
    val fb_write = Module(new v_frmbuf_wr_0)
    fb_write.io.ap_clk := clk_100
    fb_write.io.ap_rst_n := aresetn
    
    val fb_read = Module(new v_frmbuf_rd_0)
    fb_read.io.ap_clk := clk_100
    fb_read.io.ap_rst_n := aresetn
    
    val tft = Module(new axi_tft_0)
    tft.io.s_axi_aclk := clk_100
    tft.io.s_axi_aresetn := aresetn
    tft.io.m_axi_aclk := clk_100
    tft.io.m_axi_aresetn := aresetn
    tft.io.sys_tft_clk := clk_25
    tft.io.tft <> io.tft
    
    val stream_ctl = Module(new stream_ctl_0)
    stream_ctl.io.aclk := clk_100
    stream_ctl.io.aresetn := aresetn
    
    val main_reset = Module(new proc_sys_reset_0)
    main_reset.io.slowest_sync_clk := aclk
    main_reset.io.ext_reset_in := true.B
    main_reset.io.aux_reset_in := mig_axi.io.init_calib_complete
    main_reset.io.mb_debug_sys_rst := false.B
    main_reset.io.dcm_locked := clk_locked
    cpu_reset_p := main_reset.io.mb_reset
    interconnect_aresetn := main_reset.io.interconnect_aresetn
    aresetn := main_reset.io.peripheral_aresetn
    
    BulkConnect(core.io, axi_clock_converter.io.s_axi, new AXI3)
    axi_clock_converter.io.m_axi <> main_xbar.io.s_axi
    main_xbar.io.m_axi <> axi_slave_mux.io.axi_s.zip(mig_axi_interconnect.io.S00_AXI.toLowerAXI3)
    axi_slave_mux.io.s0 <> axi_slave_mux2.io.axi_s
    axi_slave_mux.io.s1 <> spi.io.s
    axi_slave_mux.io.s2 <> apb_dev.io.axi_s
    axi_slave_mux.io.s3 <> confreg.io.s
    axi_slave_mux.io.s4 <> ethernet.io.s
    axi_slave_mux2.io.s0 <> mig_axi_interconnect.io.S03_AXI.toLowerAXI3
    axi_slave_mux2.io.s1 <> axi_clk_converter_apb.io.s_axi
    axi_slave_mux2.io.s2 <> axi_clk_converter_fb_wr.io.s_axi
    axi_slave_mux2.io.s3 <> axi_clk_converter_fd_rd.io.s_axi
    axi_slave_mux2.io.s4 <> axi_clk_converter_tft.io.s_axi
    mig_axi_interconnect.io.M00_AXI.toLower <> mig_axi.io.s_axi
    ethernet.io.m <> mig_axi_interconnect.io.S01_AXI.toLowerAXI3
    BulkConnect(dma_master0.io, mig_axi_interconnect.io.S02_AXI.toLowerAXI3, new AXI3())
    tft.io.m_axi <> mig_axi_interconnect.io.S04_AXI.toLower
    fb_write.io.m_axi_mm_video <> mig_axi_interconnect.io.S05_AXI
    fb_read.io.m_axi_mm_video <> mig_axi_interconnect.io.S06_AXI
    axi_clk_converter_apb.io.m_axi <> apb_axi4lite_to_axi3.io.s_axi
    apb_axi4lite_to_axi3.io.m_axi <> apb_bridge.io.s_axi
    axi_clk_converter_fb_wr.io.m_axi <> fb_write_converter.io.s_axi
    axi_clk_converter_fd_rd.io.m_axi <> fb_read_converter.io.s_axi
    axi_clk_converter_tft.io.m_axi <> tft_protocol_converter.io.s_axi
    fb_read_converter.io.m_axi <> fb_read.io.s_axi_CTRL.toLower
    fb_write_converter.io.m_axi <> fb_write.io.s_axi_CTRL.toLower
    tft_protocol_converter.io.m_axi <> tft.io.s_axi
    stream_ctl.io.m_axis_video <> fb_write.io.s_axis_video
    fb_read.io.m_axis_video <> stream_ctl.io.s_axis_video
    
    dma_master0.io.order_addr_in := confreg.io.order_addr_reg
    confreg.io.write_dma_end := dma_master0.io.write_dma_end
    confreg.io.finish_read_order := dma_master0.io.finish_read_order
    
    apb_dev.io.apb_psel_dma := dma_master0.io.apb_psel
    apb_dev.io.apb_valid_dma := dma_master0.io.apb_valid_req
    apb_dev.io.apb_enab_dma := dma_master0.io.apb_penable
    apb_dev.io.apb_rw_dma := dma_master0.io.apb_rw
    apb_dev.io.apb_addr_dma := dma_master0.io.apb_addr
    dma_master0.io.apb_rdata := apb_dev.io.apb_rdata_dma
    apb_dev.io.apb_wdata_dma := dma_master0.io.apb_wdata
    dma_master0.io.dma_gnt := apb_dev.io.dma_grant
    apb_dev.io.dma_ack_i := dma_master0.io.dma_ack_out
    dma_master0.io.dma_req_in := apb_dev.io.dma_req_o
    
    val m_apb = apb_bridge.io.m_apb
    val s0_apb = lcd_controller.io.APB
    val s1_apb = ps2.io
    s0_apb.paddr := m_apb.paddr
    s0_apb.psel := m_apb.psel(0)
    s0_apb.penable := m_apb.penable
    s0_apb.pwrite := m_apb.pwrite
    s0_apb.pwdata := m_apb.pwdata
    s1_apb.paddr := m_apb.paddr
    s1_apb.psel := m_apb.psel(1)
    s1_apb.penable := m_apb.penable
    s1_apb.write := m_apb.pwrite
    s1_apb.writedata := m_apb.pwdata
    s1_apb.byteenable := m_apb.pstrb
    m_apb.pready := Cat(s1_apb.waitrequest_n, s0_apb.pready)
    m_apb.prdata := s0_apb.prdata
    m_apb.prdata2 := s1_apb.readdata
    m_apb.pslverr := Cat(s1_apb.perr, s0_apb.pslverr)
    
    stream_ctl.io.ctl_reg1 := confreg.io.vga_reg
    
    io.phy_rstn := aresetn
    io.ejtag.TDO := false.B
}
