module soc_top (
    input         resetn, 
    input         clk,

    //------gpio----------------
    output [15:0] led,
    output [1 :0] led_rg0,
    output [1 :0] led_rg1,
    output [7 :0] num_csn,
    output [6 :0] num_a_g,
    input  [7 :0] switch, 
    output [3 :0] btn_key_col,
    input  [3 :0] btn_key_row,
    input  [1 :0] btn_step,

    //------DDR3 interface------
    inout  [15:0] ddr3_dq,
    output [12:0] ddr3_addr,
    output [2 :0] ddr3_ba,
    output        ddr3_ras_n,
    output        ddr3_cas_n,
    output        ddr3_we_n,
    output        ddr3_odt,
    output        ddr3_reset_n,
    output        ddr3_cke,
    output [1:0]  ddr3_dm,
    inout  [1:0]  ddr3_dqs_p,
    inout  [1:0]  ddr3_dqs_n,
    output        ddr3_ck_p,
    output        ddr3_ck_n,

    //------mac controller-------
    //TX
    input         mtxclk_0,     
    output        mtxen_0,      
    output [3:0]  mtxd_0,       
    output        mtxerr_0,
    //RX
    input         mrxclk_0,      
    input         mrxdv_0,     
    input  [3:0]  mrxd_0,        
    input         mrxerr_0,
    input         mcoll_0,
    input         mcrs_0,
    // MIIM
    output        mdc_0,
    inout         mdio_0,
    
    output        phy_rstn,
 
    //------EJTAG-------
    input         EJTAG_TRST,
    input         EJTAG_TCK,
    input         EJTAG_TDI,
    input         EJTAG_TMS,
    output        EJTAG_TDO,

    //------uart-------
    inout         UART_RX,
    inout         UART_TX,

    //------debug-uart------
    input         UART_RX2,
    output        UART_TX2,

    //------nand-------
    output        NAND_CLE ,
    output        NAND_ALE ,
    input         NAND_RDY ,
    inout [7:0]   NAND_DATA,
    output        NAND_RD  ,
    output        NAND_CE  ,  //low active
    output        NAND_WR  ,  
       
    //------spi flash-------
    output        SPI_CLK,
    output        SPI_CS,
    inout         SPI_MISO,
    inout         SPI_MOSI,

    // ----- LCD -----
    output wire LCD_csel,
    inout wire [15:0] LCD_data_tri_io,
    output wire LCD_nrst,
    output wire LCD_rd,
    output wire LCD_rs,
    output wire LCD_wr,
    output wire LCD_lighton,


    // ----- PS2 -----
    inout wire PS2_clk_tri_io,
    inout wire PS2_dat_tri_io,

    // ----- VGA -----
    inout wire [3:0] VGA_r,
    inout wire [3:0] VGA_g,
    inout wire [3:0] VGA_b,
    output wire VGA_hsync,
    output wire VGA_vsync
);

logic io_mac_md_i_0;
logic io_mac_md_o_0;
logic io_mac_md_oe_0;
IOBUF mac_iobuf (
    .IO(mdio_0),
    .I(io_mac_md_o_0),
    .O(io_mac_md_i_0),
    .T(io_mac_md_oe_0)
);

logic io_uart_txd_i;
logic io_uart_txd_o;
logic io_uart_txd_oe;
logic io_uart_rxd_i;
logic io_uart_rxd_o;
logic io_uart_rxd_oe;
logic io_uart_rts_o;
logic io_uart_dtr_o;
logic io_uart_cts_i;
logic io_uart_dsr_i;
logic io_uart_dcd_i;
logic io_uart_ri_i;
assign UART_RX = io_uart_rxd_oe ? 1'bz : io_uart_rxd_o;
assign UART_TX = io_uart_txd_oe ? 1'bz : io_uart_txd_o;
assign UART_RTS = io_uart_rts_o;
assign UART_DTR = io_uart_dtr_o;
assign io_uart_txd_i = UART_TX;
assign io_uart_rxd_i = UART_RX;
assign io_uart_cts_i = '0;
assign io_uart_dcd_i = '0;
assign io_uart_dsr_i = '0;
assign io_uart_ri_i = '0;

logic [7:0] io_nand_dat_i;
logic [7:0] io_nand_dat_o;
logic io_nand_dat_oe;
generate;
    for (genvar i = 0; i < 8; i++) begin: NANDBLK
        IOBUF nand_iobuf(
            .IO(NAND_DATA[i]),
            .I(io_nand_dat_o[i]),
            .O(io_nand_dat_i[i]),
            .T(io_nand_dat_oe)
        );
    end
endgenerate
logic [3:0] io_nand_ce;
assign NAND_CE = io_nand_ce[0];

logic [3:0] io_spi_csn_o;
logic [3:0] io_spi_csn_en;
logic io_spi_sdo_o;
logic io_spi_sdo_en;
logic io_spi_sdi_o;
logic io_spi_sdi_en;
assign SPI_CS = ~io_spi_csn_en[0] & io_spi_csn_o[0];
assign SPI_MOSI = io_spi_sdo_en ? 1'bz : io_spi_sdo_o;
assign SPI_MISO = io_spi_sdi_en ? 1'bz : io_spi_sdi_o;

logic [15:0] io_lcd_data_in;
logic [15:0] io_lcd_data_out;
logic [15:0] io_lcd_data_z;
generate;
    for (genvar i = 0; i < 16; i++) begin: LCDBLK
        IOBUF lcd_iobuf(
            .IO(LCD_data_tri_io[i]),
            .I(io_lcd_data_out[i]),
            .O(io_lcd_data_in[i]),
            .T(io_lcd_data_z[i])
        );
    end
endgenerate
assign LCD_lighton = 1'b1;

logic io_ps2_CLK_i;
logic io_ps2_CLK_o;
logic io_ps2_CLK_t;
logic io_ps2_DAT_i;
logic io_ps2_DAT_o;
logic io_ps2_DAT_t;
IOBUF ps2_clk_iobuf(
    .I(io_ps2_CLK_o),
    .IO(PS2_clk_tri_io),
    .O(io_ps2_CLK_i),
    .T(io_ps2_CLK_t)
);
IOBUF ps2_dat_iobuf(
    .I(io_ps2_DAT_o),
    .IO(PS2_dat_tri_io),
    .O(io_ps2_DAT_i),
    .T(io_ps2_DAT_t)
);

logic [5:0] io_tft_vga_r;
logic [5:0] io_tft_vga_g;
logic [5:0] io_tft_vga_b;
generate
    for (genvar i = 0; i < 4; i++) begin: VGABLK
        assign VGA_r[i] = io_tft_vga_r[i+2] ? 1'b1 : 1'bZ;
        assign VGA_g[i] = io_tft_vga_g[i+2] ? 1'b1 : 1'bZ;
        assign VGA_b[i] = io_tft_vga_b[i+2] ? 1'b1 : 1'bZ;
    end
endgenerate

iFuSoC soc (
    .io_clk(clk),
    .io_resetn(resetn),
    .io_gpio_led(led),
    .io_gpio_led_rg0(led_rg0),
    .io_gpio_led_rg1(led_rg1),
    .io_gpio_num_csn(num_csn),
    .io_gpio_num_a_g(num_a_g),
    .io_gpio_switch(switch),
    .io_gpio_btn_key_col(btn_key_col),
    .io_gpio_btn_key_row(btn_key_row),
    .io_gpio_btn_step(btn_step),
    .io_ddr3_dq(ddr3_dq),
    .io_ddr3_dqs_p(ddr3_dqs_p),
    .io_ddr3_dqs_n(ddr3_dqs_n),
    .io_ddr3_addr(ddr3_addr),
    .io_ddr3_ba(ddr3_ba),
    .io_ddr3_ras_n(ddr3_ras_n),
    .io_ddr3_cas_n(ddr3_cas_n),
    .io_ddr3_we_n(ddr3_we_n),
    .io_ddr3_reset_n(ddr3_reset_n),
    .io_ddr3_ck_p(ddr3_ck_p),
    .io_ddr3_ck_n(ddr3_ck_n),
    .io_ddr3_cke(ddr3_cke),
    .io_ddr3_dm(ddr3_dm),
    .io_ddr3_odt(ddr3_odt),
    .io_mac_mtxclk_0(mtxclk_0),
    .io_mac_mtxd_0(mtxd_0),
    .io_mac_mtxen_0(mtxen_0),
    .io_mac_mtxerr_0(mtxerr_0),
    .io_mac_mrxclk_0(mrxclk_0),
    .io_mac_mrxdv_0(mrxdv_0),
    .io_mac_mrxd_0(mrxd_0),
    .io_mac_mrxerr_0(mrxerr_0),
    .io_mac_mcoll_0(mcoll_0),
    .io_mac_mcrs_0(mcrs_0),
    .io_mac_mdc_0(mdc_0),
    .io_mac_md_i_0,
    .io_mac_md_o_0,
    .io_mac_md_oe_0,
    .io_phy_rstn(phy_rstn),
    .io_ejtag_TRST(EJTAG_TRST),
    .io_ejtag_TCK(EJTAG_TCK),
    .io_ejtag_TDI(EJTAG_TDI),
    .io_ejtag_TMS(EJTAG_TMS),
    .io_ejtag_TDO(EJTAG_TDO),
    .io_uart_txd_i,
    .io_uart_txd_o,
    .io_uart_txd_oe,
    .io_uart_rxd_i,
    .io_uart_rxd_o,
    .io_uart_rxd_oe,
    .io_uart_rts_o,
    .io_uart_dtr_o,
    .io_uart_cts_i,
    .io_uart_dsr_i,
    .io_uart_dcd_i,
    .io_uart_ri_i,
    .io_nand_cle(NAND_CLE),
    .io_nand_ale(NAND_ALE),
    .io_nand_rdy({3'b0, NAND_RDY}),
    .io_nand_rd(NAND_RD),
    .io_nand_ce,
    .io_nand_wr(NAND_WR),
    .io_nand_dat_i,
    .io_nand_dat_o,
    .io_nand_dat_oe,
    .io_spi_csn_o,
    .io_spi_csn_en,
    .io_spi_sck_o(SPI_CLK),
    .io_spi_sdo_i(SPI_MOSI),
    .io_spi_sdo_o,
    .io_spi_sdo_en,
    .io_spi_sdi_i(SPI_MISO),
    .io_spi_sdi_o,
    .io_spi_sdi_en,
    .io_lcd_nrst(LCD_nrst),
    .io_lcd_csel(LCD_csel),
    .io_lcd_rs(LCD_rs),
    .io_lcd_wr(LCD_wr),
    .io_lcd_rd(LCD_rd),
    .io_lcd_data_in,
    .io_lcd_data_out,
    .io_lcd_data_z,
    .io_ps2_CLK_i,
    .io_ps2_CLK_o,
    .io_ps2_CLK_t,
    .io_ps2_DAT_i,
    .io_ps2_DAT_o,
    .io_ps2_DAT_t,
    .io_tft_hsync(VGA_hsync),
    .io_tft_vsync(VGA_vsync),
    .io_tft_de(),
    .io_tft_dps(),
    .io_tft_vga_clk(),
    .io_tft_vga_r,
    .io_tft_vga_g,
    .io_tft_vga_b
);

endmodule