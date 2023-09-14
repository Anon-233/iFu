`include "access.svh"
`ifdef VERILATOR
`include "include/common.sv"
/* You should not add any additional includes in this file */
`endif


module VCacheTop 
    import common::*;
    (
    input logic clk, reset_,

    input  dbus_req_t  dreq,
    output dbus_resp_t dresp,
    output cbus_req_t  creq,
    input  cbus_resp_t cresp
);
    `include "bus_decl"

    // cbus_req_t  dcreq;
    // cbus_resp_t dcresp;

    // assign creq = dcreq;
    // assign dcresp = cresp;
	wire reset = reset_;
    DCache top(.*);
`ifdef REFERENCE_CACHE
	word_t  mem [15:0]/* verilator public_flat_rd */;
	for (genvar i = 0; i < 16; i++)
    	assign mem[i] = top.ram_inst.mem[i];
`else
    /**
     * TODO (Lab3, optional) expose internal memory to simulator
     *
     * NOTE: it will slow down FST tracing significantly, especially
     *       if your cache is large, you may want to speed up by adding
     *       "// verilator tracing_off" before the declaration of
     *       the variable mem.
     */

    /**
     * the following is an example. Suppose that you used LUTRAM and
     * your cache contains only four cache lines, each of which consists of
     * 16 consecutive words in memory.
     *
     * later you can access the variable mem from C++ via VCacheTop->mem.
     * it will possibly become a 1d array of uint32_t.
     */
    // typedef word_t [15:0] cache_line_t;
    //
    // /* verilator tracing_off */
    // cache_line_t [3:0] mem /* verilator public_flat_rd */;
    // /* verilator tracing_on */
    //
    // for (genvar i = 0; i < 4; i++) begin
	// 	   for (genvar j = 0; j < 4; i++)
    //     		assign mem[i][j] = top.xxx.yyy.zzz.lutrams[i].ram_inst.mem[j];
    // end


`endif
endmodule
