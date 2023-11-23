`ifndef __CORE_TOP
`define __CORE_TOP
`ifdef VERILATOR
`include "common.sv"
`include "CBusToAXI.sv"
`include "core.sv"
`include "config.sv"
`else

`endif

module core_top
import common::*;
#(
	parameter TLBNUM = 32
)
(
    input           aclk,
    input           aresetn,
    input    [ 7:0] intrpt, 
    //AXI interface 
    //read reqest
    output   [ 3:0] arid,
    output   [31:0] araddr,
    output   [ 7:0] arlen,
    output   [ 2:0] arsize,
    output   [ 1:0] arburst,
    output   [ 1:0] arlock,
    output   [ 3:0] arcache,
    output   [ 2:0] arprot,
    output          arvalid,
    input           arready,
    //read back
    input    [ 3:0] rid,
    input    [31:0] rdata,
    input    [ 1:0] rresp,
    input           rlast,
    input           rvalid,
    output          rready,
    //write request
    output   [ 3:0] awid,
    output   [31:0] awaddr,
    output   [ 7:0] awlen,
    output   [ 2:0] awsize,
    output   [ 1:0] awburst,
    output   [ 1:0] awlock,
    output   [ 3:0] awcache,
    output   [ 2:0] awprot,
    output          awvalid,
    input           awready,
    //write data
    output   [ 3:0] wid,
    output   [31:0] wdata,
    output   [ 3:0] wstrb,
    output          wlast,
    output          wvalid,
    input           wready,
    //write back
    input    [ 3:0] bid,
    input    [ 1:0] bresp,
    input           bvalid,
    output          bready,

    //debug
    input           break_point,
    input           infor_flag,
    input  [ 4:0]   reg_num,
    output          ws_valid,
    output [31:0]   rf_rdata,

    output [31:0] debug0_wb_pc,
    output [ 3:0] debug0_wb_rf_wen,
    output [ 4:0] debug0_wb_rf_wnum,
    output [31:0] debug0_wb_rf_wdata,
    output [31:0] debug0_wb_inst
);
reg         reset;
always @(posedge aclk) reset <= ~aresetn; 

cbus_req_t creq;
cbus_resp_t cresp;

core core(
    .clk        (aclk),
    .reset      (reset),
    .ext_int    (intrpt),
    //AXI
    .creq       (creq),
    .cresp      (cresp)
);

CBusToAXI CBusToAXI(
    .aclk       (aclk),
    .areset     (reset),
    // CBus
    .creq       (creq),
    .cresp      (cresp),
    // AXI
    .arid       (arid),
    .araddr     (araddr),
    .arlen      (arlen),
    .arsize     (arsize),
    .arburst    (arburst),
    .arlock     (arlock),
    .arcache    (arcache),
    .arprot     (arprot),
    .arvalid    (arvalid),
    .arready    (arready),
    .rid        (rid),
    .rdata      (rdata),
    .rresp      (rresp),
    .rlast      (rlast),
    .rvalid     (rvalid),
    .rready     (rready),
    .awid       (awid),
    .awaddr     (awaddr),
    .awlen      (awlen),
    .awsize     (awsize),
    .awburst    (awburst),
    .awlock     (awlock),
    .awcache    (awcache),
    .awprot     (awprot),
    .awvalid    (awvalid),
    .awready    (awready),
    .wdata      (wdata),
    .wstrb      (wstrb),
    .wlast      (wlast),
    .wvalid     (wvalid),
    .wready     (wready),
    .bid        (bid),
    .bresp      (bresp),
    .bvalid     (bvalid),
    .bready     (bready)

);


`ifdef DIFFTEST_EN

`endif
endmodule
`endif