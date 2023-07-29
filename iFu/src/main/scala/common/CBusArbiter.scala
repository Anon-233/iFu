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
        val reset = Input(Bool())
        val ireqs = Input(Vec(2, new CbusReq()))
        val iresps = Output(Vec(2, new CbusResp()))
        val oreq = Output(new CbusReq())
        val oresp = Input(new CbusResp())
    })
    
    val busy = RegInit(false.B)
    val index = RegInit(0.U(32.W))
    var select = Wire(0.U(32.W)) 
    val saved_req = RegInit(CbusReq())
    val selected_req = Wire(CbusReq())

    // assign oreq = ireqs[index];
    io.oreq := Mux(busy, io.ireqs(index), 0.U.asTypeOf(new CbusReq())) // prevent early issue
    selected_req := io.ireqs(select)

    // select a preferred request
    select = 0.U(32.W)

    select := Mux(io.ireqs(0).valid, 0.U(32.W), 
                Mux(io.ireqs(1).valid, 1.U(32.W), 0.U(32.W))).

    // feedback to selected request
    io.iresps := 0.U.asTypeOf(Vec(2, new CbusResp()))

    when(busy){
        for(i <- 0 until 2){
            when(index === i.U(32.W)){
                io.iresps(i) := io.oresp
            }
        }
    }

    when(!reset){
        when(busy){
            when(io.oresp.isLast){
                busy := false.B
                saved_req := 0.U.asTypeOf(new CbusReq())
            }
        }.otherwise{
            // if not valid, busy <= 0
            busy := selected_req.valid
            index := select
            saved_req := selected_req
        }
    }.otherwise{
        busy := false.B
        index := 0.U(32.W)
        saved_req := 0.U.asTypeOf(new CbusReq())
    }

}
