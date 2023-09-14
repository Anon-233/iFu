`ifndef __MYCPU_TOP_SV
`define __MYCPU_TOP_SV

module mycpu_top
	import common::*;(
	input logic aclk, aresetn,

    output logic [3 :0] arid,
    output logic [31:0] araddr,
    output logic [3 :0] arlen,
    output logic [2 :0] arsize,
    output logic [1 :0] arburst,
    output logic [1 :0] arlock,
    output logic [3 :0] arcache,
    output logic [2 :0] arprot,
    output logic        arvalid,
    input  logic        arready,
    input  logic [3 :0] rid,
    input  logic [31:0] rdata,
    input  logic [1 :0] rresp,
    input  logic        rlast,
    input  logic        rvalid,
    output logic        rready,
    output logic [3 :0] awid,
    output logic [31:0] awaddr,
    output logic [3 :0] awlen,
    output logic [2 :0] awsize,
    output logic [1 :0] awburst,
    output logic [1 :0] awlock,
    output logic [3 :0] awcache,
    output logic [2 :0] awprot,
    output logic        awvalid,
    input  logic        awready,
    output logic [3 :0] wid,
    output logic [31:0] wdata,
    output logic [3 :0] wstrb,
    output logic        wlast,
    output logic        wvalid,
    input  logic        wready,
    input  logic [3 :0] bid,
    input  logic [1 :0] bresp,
    input  logic        bvalid,
    output logic        bready,

	output addr_t   debug_wb_pc,
    output strobe_t debug_wb_rf_wen,
    output regidx_t debug_wb_rf_wnum,
    output word_t   debug_wb_rf_wdata,

    input logic [7:0] ext_int
);

	cbus_req_t  oreq;
    cbus_resp_t oresp;

    VTop top(.clk(aclk), .resetn(aresetn), .*);
    CBusToAXI cvt(.creq(oreq), .cresp(oresp), .*);

endmodule


`endif
