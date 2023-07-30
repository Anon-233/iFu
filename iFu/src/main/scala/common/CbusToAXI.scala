package iFu.common

import chisel3._
import chisel3.util._

/*
`ifndef __CBUSTOAXI_SV
`define __CBUSTOAXI_SV

 typedef enum i8 {
     MLEN1  = 8'h00,
     MLEN2  = 8'h01,
     MLEN4  = 8'h03,
     MLEN8  = 8'h07,
     MLEN16 = 8'h0f,
     MLEN32 = 8'h1f,
     MLEN64 = 8'h3f,
     MLEN128 = 8'h7f,
     MLEN256 = 8'hff

 } mlen_t;

`ifdef VERILATOR
`include "include/common.sv"
`endif
/**
 * interconnect with cache bus & AXI.
 *
 * this implementation is not efficient, since
 * it adds one cycle lantency to all requests.
 *
 * this implementation also serves as a spec for cache bus,
 * which shows the corresponding constructs in AXI.
 *
 * NOTE: assume the widths of cache Bus & AXI are 32 bits.
 */
module CBusToAXI
    import common::*;(
    input logic aclk, areset,

    output logic [3 :0] arid,
    output logic [31:0] araddr,
    output logic [3 :0] arlen,
    output logic [2 :0] arsize,
    output logic [1 :0] arburst,
    output logic arlock,
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
    output logic awlock,
    output logic [3 :0] awcache,
    output logic [2 :0] awprot,
    output logic        awvalid,

    input  logic        awready,

    output logic [31:0] wdata,
    output logic [3 :0] wstrb,
    output logic        wlast,
    output logic        wvalid,

    input  logic        wready,
    input  logic [3 :0] bid,
    input  logic [1 :0] bresp,
    input  logic        bvalid,

    output logic        bready,

    input  cbus_req_t  creq,
    output cbus_resp_t cresp
);
    localparam int ar = 4;
    localparam int r  = 3;
    localparam int aw = 2;
    localparam int W  = 1;
    localparam int b  = 0;
    typedef logic [4:0] busy_t;

    // process pending request
    busy_t in_issue, next_issue;
    assign next_issue = creq.is_write ? 5'b00111 : 5'b11000;

    // check ongoing request
    cbus_req_t saved_req;
    mlen_t count;
    logic is_last;
    assign is_last = count == 0;

    // interactions with AXI
    logic  busy;
    busy_t handshake, ended, remain;

    assign busy = |in_issue;
    assign handshake = {
        in_issue[ar] && arready,
        in_issue[r ] && rvalid,
        in_issue[aw] && awready,
        in_issue[W ] && wready,
        in_issue[b ] && bvalid
    };
    assign ended = handshake & {1'b1, rlast, 1'b1, wlast, 1'b1};
    assign remain = in_issue ^ ended;

    // cache bus driver
    logic ready;
    assign ready = handshake[W] || handshake[r];
    assign cresp.ready = ready;
    assign cresp.last  = ready && (!in_issue[r] || rlast) && is_last;
    assign cresp.data  = rdata;

    // AXI driver
    always_comb begin
        {
            arid, araddr, arlen, arsize,
            arburst, arlock, arcache, arprot,
            arvalid, /*arready,*/
            /*rid, rdata, rresp, rlast,*/
            /*rvalid,*/ rready,
            awid, awaddr, awlen, awsize,
            awburst, awlock, awcache, awprot,
            awvalid, /*awready,*/
            wdata, wstrb, wlast,
            wvalid, /*wready,*/
            /*bid, bresp, bvalid,*/ bready
        } = 0;

        if (in_issue[ar]) begin
            arvalid = 1;
            araddr  = saved_req.addr;
            arlen   = saved_req.len;
            arsize  = saved_req.size;
            arburst = AXI_BURST_WRAP;
        end

        if (in_issue[r]) begin
            rready = 1;
        end

        if (in_issue[aw]) begin
            awvalid = 1;
            awaddr  = saved_req.addr;
            awlen   = saved_req.len;
            awsize  = saved_req.size;
            awburst = AXI_BURST_WRAP;
        end

        if (in_issue[W]) begin
            wvalid = 1;
            wdata  = creq.data;
            wstrb  = creq.strobe;
            wlast  = is_last;
        end

        if (in_issue[b]) begin
            bready = 1;
        end
    end

    always_ff @(posedge aclk)
    if (~areset) begin
        if (busy) begin
            if (cresp.ready && !cresp.last)
                count <= mlen_t'(count - mlen_t'(1));

            in_issue <= remain;
        end else begin
            if (creq.valid)
                in_issue <= next_issue;

            saved_req <= creq;
            count     <= creq.len;
        end
    end else begin
        in_issue <= 0;
    end

    `UNUSED_OK({
        saved_req.valid, saved_req.is_write,
        saved_req.data, saved_req.strobe,
        rid, rresp, bid, bresp
    });
endmodule



`endif

*/

class CBusToAXIIO extends Bundle {
    val arid    = Output(UInt(4.W))
    val araddr  = Output(UInt(32.W))
    val arlen   = Output(UInt(4.W))
    val arsize  = Output(UInt(3.W))
    val arburst = Output(UInt(2.W))
    val arlock  = Output(Bool())
    val arcache = Output(UInt(4.W))
    val arprot  = Output(UInt(3.W))
    val arvalid = Output(Bool())

    val arready = Input(Bool())
    val rid     = Input(UInt(4.W))
    val rdata   = Input(UInt(32.W))
    val rresp   = Input(UInt(2.W))
    val rlast   = Input(Bool())
    val rvalid  = Input(Bool())

    val rready  = Output(Bool())
    val awid    = Output(UInt(4.W))
    val awaddr  = Output(UInt(32.W))
    val awlen   = Output(UInt(4.W))
    val awsize  = Output(UInt(3.W))
    val awburst = Output(UInt(2.W))
    val awlock  = Output(Bool())
    val awcache = Output(UInt(4.W))
    val awprot  = Output(UInt(3.W))
    val awvalid = Output(Bool())

    val awready = Input(Bool())

    val wdata  = Output(UInt(32.W))
    val wstrb  = Output(UInt(4.W))
    val wlast  = Output(Bool())
    val wvalid = Output(Bool())

    val wready = Input(Bool())
    val bid    = Input(UInt(4.W))
    val bresp  = Input(UInt(2.W))
    val bvalid = Input(Bool())

    val bready = Output(Bool())

    val creq  = Input(new CbusReq)
    val cresp = Output(new CbusResp)
}

class CBusToAXI extends CoreModule {
    val io = IO(new CBusToAXIIO)

    val b :: w :: aw :: r :: ar :: Nil = Enum(5)

    val in_issue = RegInit(0.U(5.W))
    val next_issue = Mux(io.creq.isStore 0x7.U(5.W), /*b00111*/
                                         0x18.U(5.W) /*b11000*/)

    // check ongoing request
    val saved_req = Reg(new CbusReq)
    val count = Reg(UInt(8.W))

    val is_last = count === 0.U

    // interactions with AXI
    val busy = in_issue.orR
    val handshake = Cat(
        in_issue(ar) && io.arready,
        in_issue(r)  && io.rvalid,
        in_issue(aw) && io.awready,
        in_issue(w)  && io.wready,
        in_issue(b)  && io.bvalid
    )
    val ended = handshake & Cat(1.U, io.rlast, 1.U, io.wlast, 1.U)
    val remain = in_issue ^ ended
    val ready = handshake(w) || handshake(r)

    // cache bus driver 
    io.cresp.ready  := ready
    io.cresp.isLast := ready && (!in_issue(r) || io.rlast) && is_last
    io.cresp.data   := io.rdata


    // AXI driver
    io.arid    := 0.U
    io.araddr  := 0.U
    io.arlen   := 0.U
    io.arsize  := 0.U
    io.arburst := 0.U
    io.arlock  := 0.U
    io.arcache := 0.U
    io.arprot  := 0.U
    io.arvalid := 0.U
    io.rready  := 0.U
    io.awid    := 0.U
    io.awaddr  := 0.U
    io.awlen   := 0.U
    io.awsize  := 0.U
    io.awburst := 0.U
    io.awlock  := 0.U
    io.awcache := 0.U
    io.awprot  := 0.U
    io.awvalid := 0.U
    io.wdata   := 0.U
    io.wstrb   := 0.U
    io.wlast   := 0.U
    io.wvalid  := 0.U
    io.bready  := 0.U

    when (in_issue(ar)) {
        io.arvalid := 1.U
        io.araddr  := saved_req.addr
        io.arlen   := saved_req.axiLen
        io.arsize  := saved_req.size
        io.arburst := saved_req.axiBurstType // AXIBURSTWRAP
    }

    when (in_issue(r)) {
        io.rready := 1.U
    }

    when (in_issue(aw)) {
        io.awvalid := 1.U
        io.awaddr  := saved_req.addr
        io.awlen   := saved_req.axiLen
        io.awsize  := saved_req.size
        io.awburst := saved_req.axiBurstType // AXIBURSTWRAP
    }

    when (in_issue(w)) {
        io.wvalid := 1.U
        io.wdata  := saved_req.data
        io.wstrb  := saved_req.mask
        io.wlast  := is_last
    }

    when (in_issue(b)) {
        io.bready := 1.U
    }


    when(busy) {
        when(io.cresp.ready && !io.cresp.isLast) {
            count := count - 1.U
        }
        in_issue := remain
    } .otherwise {
        when(io.creq.valid) {
            in_issue := next_issue
        }
        saved_req := io.creq
        count     := io.creq.axiLen
    }
}



