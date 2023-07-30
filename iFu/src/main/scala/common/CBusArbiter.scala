package iFu.common

import chisel3._
import chisel3.util._

/*module CBusArbiter
	import common::*;#(
    parameter int NUM_INPUTS = 2,  // NOTE: NUM_INPUTS >= 1

    localparam int MAX_INDEX = NUM_INPUTS - 1
) (
    input logic clk, reset,

    input  cbus_req_t  [MAX_INDEX:0] ireqs,
    output cbus_resp_t [MAX_INDEX:0] iresps,
    output cbus_req_t  oreq,
    input  cbus_resp_t oresp
);
    logic busy;
    int index, select;
    cbus_req_t saved_req, selected_req;

    // assign oreq = ireqs[index];
    assign oreq = busy ? ireqs[index] : '0;  // prevent early issue
    assign selected_req = ireqs[select];

    // select a preferred request
    always_comb begin
        select = 0;

        for (int i = 0; i < NUM_INPUTS; i++) begin
            if (ireqs[i].valid) begin
                select = i;
                break;
            end
        end
    end

    // feedback to selected request
    always_comb begin
        iresps = '0;

        if (busy) begin
            for (int i = 0; i < NUM_INPUTS; i++) begin
                if (index == i)
                    iresps[i] = oresp;
            end
        end
    end

    always_ff @(posedge clk)
    if (~reset) begin
        if (busy) begin
            if (oresp.last)
                {busy, saved_req} <= '0;
        end else begin
            // if not valid, busy <= 0
            busy <= selected_req.valid;
            index <= select;
            saved_req <= selected_req;
        end
    end else begin
        {busy, index, saved_req} <= '0;
    end

    `UNUSED_OK({saved_req});
endmodule

*/


class CBusArbiter extends CoreModule{
    val io = IO(new Bundle{
        val ireqs = Input(Vec(2, new CBusReq))    // from i$
        val iresps = Output(Vec(2, new CBusResp))
        val oreq = Output(new CBusReq)    // to AXI
        val oresp = Input(new CBusResp)
    })

    val busy = RegInit(false.B)
    val index = RegInit(0.U(log2Ceil(ireqs.size).W)) 

    val select = Mux(io.ireqs(0).valid, 0.U(log2Ceil(ireqs.size).W), 
                 Mux(io.ireqs(1).valid, 1.U(log2Ceil(ireqs.size).W),
                                        0.U(log2Ceil(ireqs.size).W)))
    val selectedReq = io.ireqs(select)

    io.oreq := Mux(busy, io.ireqs(index), 0.U.asTypeOf(new CBusReq))
    io.iresps := 0.U.asTypeOf(Vec(2, new CBusResp))
    io.iresps(index) := io.oresp

    when (busy) {
        when (io.oresp.isLast) { busy := false.B }
    } .otherwise {  // busy = false
        busy  := selectedReq.valid
        index := select
    }
}
