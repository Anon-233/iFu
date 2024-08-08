package SoC

import chisel3._
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
        val vga = new VGA
    })
    io := DontCare
    val aclk = Wire(Bool())
    val aresetn = Wire(Bool())
    val interconnect_aresetn = Wire(Bool())
    val cpu_clk = Wire(Bool())
    val cpu_aresetn = Wire(Bool())
    val uncore_clk = Wire(Bool())
    val clk_locked = Wire(Bool())
    interconnect_aresetn := DontCare
    cpu_aresetn := DontCare
    clk_locked := DontCare
    
    val int_out = Wire(UInt(8.W))
    int_out := DontCare
    
    val xpm_cdc_single_int = Module(new xpm_cdc_single)
    xpm_cdc_single_int.io := DontCare
    
    val core = Module(new core_top)
    core.io.aclk := cpu_clk
    core.io.aresetn := cpu_aresetn
    core.io.intrpt := int_out
    
    val axi_clock_converter = Module(new axi_clock_converter_0)
    axi_clock_converter.io := DontCare
    axi_clock_converter.io.s_axi_aclk := cpu_clk
    axi_clock_converter.io.s_axi_aresetn := cpu_aresetn
    aclk := axi_clock_converter.io.m_axi_aclk
    aresetn := axi_clock_converter.io.m_axi_aresetn
    
    val axi_slave_mux2 = Module(new axi_slave_mux2)
    axi_slave_mux2.io := DontCare
    axi_slave_mux2.io.axi_s_aclk := aclk
    axi_slave_mux2.io.axi_s_aresetn := interconnect_aresetn
    axi_slave_mux2.io.spi_boot := true.B
    
    val axi_slave_mux = Module(new axi_slave_mux)
    axi_slave_mux.io := DontCare
    axi_slave_mux.io.axi_s_aclk := aclk
    axi_slave_mux.io.axi_s_aresetn := interconnect_aresetn
    axi_slave_mux.io.spi_boot := true.B
    
    val spi = Module(new spi_flash_ctrl)
    spi.io := DontCare
    spi.io.aclk := aclk
    spi.io.aresetn := aresetn
    spi.io.spi_addr := 0x1fe8.asUInt
    spi.io.fast_wakeup := false.B
    
    val confreg = Module(new confreg)
    confreg.io := DontCare
    confreg.io.gpio <> io.gpio
    
    val ethernet = Module(new ethernet_top)
    ethernet.io := DontCare
    ethernet.io.mac <> io.mac
    
    val clk_pll_33 = Module(new clk_pll_33)
    clk_pll_33.io.clk_in1 := io.clk
    clk_pll_33.io.resetn := io.resetn
    clk_pll_33.io.locked := clk_locked
    cpu_clk := clk_pll_33.io.clk_out1
    uncore_clk := clk_pll_33.io.clk_out2
    
    val mig_axi_interconnect = Module(new axi_interconnect_0)
    mig_axi_interconnect.io := DontCare
    
    val mig_axi = Module(new mig_axi_32)
    mig_axi.io := DontCare
    mig_axi.io.ddr3 <> io.ddr3
    
    val dma_master0 = Module(new dma_master)
    dma_master0.io := DontCare
    
    val apb_dev = Module(new axi2apb_misc)
    apb_dev.io := DontCare
    
    val main_xbar = Module(new main_xbar)
    main_xbar.io := DontCare
    
    val axi_clk_converter_apb = Module(new axi_clock_converter_0)
    axi_clk_converter_apb.io := DontCare
    
    val apb_axi4lite_to_axi3 = Module(new axi_protocol_converter_0)
    apb_axi4lite_to_axi3.io := DontCare
    
    val apb_bridge = Module(new axi_apb_bridge_connect)
    apb_bridge.io <> DontCare
    
    val lcd_controller = Module(new nt35510)
    lcd_controller.io := DontCare
    
    val ps2 = Module(new ps2)
    ps2.io := DontCare
    
    val axi_clk_converter_fb_wr = Module(new axi_clock_converter_0)
    axi_clk_converter_fb_wr.io := DontCare
    
    val axi_clk_converter_fd_rd = Module(new axi_clock_converter_0)
    axi_clk_converter_fd_rd.io := DontCare
    
    val axi_clk_converter_tft = Module(new axi_clock_converter_0)
    axi_clk_converter_tft.io := DontCare
    
    val fb_read_converter = Module(new axi_protocol_converter_0)
    fb_read_converter.io := DontCare
    
    val fb_write_converter = Module(new axi_protocol_converter_0)
    fb_write_converter.io := DontCare
    
    val tft_protocol_converter = Module(new axi_protocol_converter_0)
    tft_protocol_converter.io := DontCare
    
    val fb_write = Module(new v_frmbuf_wr_0)
    fb_write.io := DontCare
    
    val fb_read = Module(new v_frmbuf_rd_0)
    fb_read.io := DontCare
    
    val tft = Module(new axi_tft_0)
    tft.io := DontCare
    
    val stream_ctl = Module(new stream_ctl_0)
    stream_ctl.io := DontCare
    
    val main_reset = Module(new proc_sys_reset_0)
    main_reset.io := DontCare
    
    core.io.axi <> axi_clock_converter.io.s_axi
    axi_slave_mux.io.s0 <> axi_slave_mux2.io.axi_s
    axi_slave_mux.io.s1 <> spi.io.s
    axi_slave_mux.io.s3 <> confreg.io.s
    axi_slave_mux.io.s4 <> ethernet.io.s
    mig_axi_interconnect.io.m00_axi <> mig_axi.io.s_axi
    dma_master0.io.axi <> mig_axi_interconnect.io.s02_axi
    
}
