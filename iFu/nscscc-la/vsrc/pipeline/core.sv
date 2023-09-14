`ifndef __CORE_SV
`define __CORE_SV
`ifdef VERILATOR
`include "include/common.sv"
// `include "pipeline/regfile/regfile.sv"
// `include "pipeline/regfile/regfile.sv"
`include "pipeline/iFuCore.sv"

`else

`endif

module core 
	import common::*;(
	input logic clk, reset,
	output cbus_req_t  icreq,
	input  cbus_resp_t icresp,
	output cbus_req_t  dcreq,
	input  cbus_resp_t dcresp,
	input logic [7:0] ext_int
);
	/* TODO: Add your pipeline here. */
	logic[31:0] pc0, pc1, pc2, pc3;
    logic[31:0] instr0, instr1, instr2, instr3;
    logic[31:0] wdata0, wdata1, wdata2, wdata3;
    logic[4:0]  ldst0 , ldst1 , ldst2 , ldst3 ;
    logic valid0 , valid1 , valid2 , valid3 ;
	logic wen0, wen1, wen2, wen3;

    logic[31:0] register[31:0];


    iFuCore iFuCore(
        .clock (clk),
        .reset(reset),
		.io_ext_int (ext_int),
        .io_ireq_valid (icreq.valid),
        .io_ireq_isStore(icreq.is_write),
        .io_ireq_size   (icreq.size),
        .io_ireq_addr   (icreq.addr),
        .io_ireq_data  (icreq.data),
        .io_ireq_mask (icreq.strobe),
        .io_ireq_axiLen (icreq.len),
        .io_ireq_axiBurstType (icreq.burst),

        .io_iresp_ready (icresp.ready),
        .io_iresp_data  (icresp.data),
        .io_iresp_isLast(icresp.last),

        .io_dreq_valid (dcreq.valid),
        .io_dreq_isStore(dcreq.is_write),
        .io_dreq_size   (dcreq.size),
        .io_dreq_addr   (dcreq.addr),
        .io_dreq_data  (dcreq.data),
        .io_dreq_mask (dcreq.strobe),
        .io_dreq_axiLen (dcreq.len),
        .io_dreq_axiBurstType (dcreq.burst),

        .io_dresp_ready (dcresp.ready),
        .io_dresp_data  (dcresp.data),
        .io_dresp_isLast(dcresp.last),


        .io_commit_debug_insts_0 (instr0),
        .io_commit_debug_insts_1 (instr1),
        .io_commit_debug_insts_2 (instr2),
        .io_commit_debug_insts_3 (instr3),

        .io_commit_debug_wdata_0 (wdata0),
        .io_commit_debug_wdata_1 (wdata1),
        .io_commit_debug_wdata_2 (wdata2),
        .io_commit_debug_wdata_3 (wdata3),

        .io_commit_debug_ldst_0 (ldst0),
        .io_commit_debug_ldst_1 (ldst1),
        .io_commit_debug_ldst_2 (ldst2),
        .io_commit_debug_ldst_3 (ldst3),

        .io_commit_debug_pc_0 (pc0),
        .io_commit_debug_pc_1 (pc1),
        .io_commit_debug_pc_2 (pc2),
        .io_commit_debug_pc_3 (pc3),

		.io_commit_debug_wen_0 (wen0),
		.io_commit_debug_wen_1 (wen1),
		.io_commit_debug_wen_2 (wen2),
		.io_commit_debug_wen_3 (wen3),

        .io_commit_arch_valids_0 (valid0),
        .io_commit_arch_valids_1 (valid1),
        .io_commit_arch_valids_2 (valid2),
        .io_commit_arch_valids_3 (valid3),

        .io_register_0 (register[0]),
        .io_register_1 (register[1]),
        .io_register_2 (register[2]),
        .io_register_3 (register[3]),
        .io_register_4 (register[4]),
        .io_register_5 (register[5]),
        .io_register_6 (register[6]),
        .io_register_7 (register[7]),
        .io_register_8 (register[8]),
        .io_register_9 (register[9]),
        .io_register_10 (register[10]),
        .io_register_11 (register[11]),
        .io_register_12 (register[12]),
        .io_register_13 (register[13]),
        .io_register_14 (register[14]),
        .io_register_15 (register[15]),
        .io_register_16 (register[16]),
        .io_register_17 (register[17]),
        .io_register_18 (register[18]),
        .io_register_19 (register[19]),
        .io_register_20 (register[20]),
        .io_register_21 (register[21]),
        .io_register_22 (register[22]),
        .io_register_23 (register[23]),
        .io_register_24 (register[24]),
        .io_register_25 (register[25]),
        .io_register_26 (register[26]),
        .io_register_27 (register[27]),
        .io_register_28 (register[28]),
        .io_register_29 (register[29]),
        .io_register_30 (register[30]),
        .io_register_31 (register[31])

    );


`ifdef VERILATOR
	DifftestInstrCommit DifftestInstrCommit0(	
		.clock              (clk),
		.coreid             (0),
		.index              (0),
		.valid              (valid0),
		.pc                 (pc0),
		.instr              (instr0),
		.skip               (0),
		.wen                (wen0),
		.wdest              ({3'b0,ldst0}),
		.wdata              (wdata0)
	);
    

    DifftestInstrCommit DifftestInstrCommit1(
		.clock              (clk),
		.coreid             (0),
		.index              (1),
		.valid              (valid1),
		.pc                 (pc1),
		.instr              (instr1),
		.skip               (0),
		.wen                (wen1),
		.wdest              ({3'b0,ldst1}),
		.wdata              (wdata1)
	);

    DifftestInstrCommit DifftestInstrCommit2(
		.clock              (clk),
		.coreid             (0),
		.index              (2),
		.valid              (valid2),
		.pc                 (pc2),
		.instr              (instr2),
		.skip               (0),
		.wen                (wen2),
		.wdest              ({3'b0,ldst2}),
		.wdata              (wdata2)
	);

    DifftestInstrCommit DifftestInstrCommit3(
		.clock              (clk),
		.coreid             (0),
		.index              (3),
		.valid              (valid3),
		.pc                 (pc3),
		.instr              (instr3),
		.skip               (0),
		.wen                (wen3),
		.wdest              ({3'b0,ldst3}),
		.wdata              (wdata3)
	);
	      
	DifftestArchIntRegState DifftestArchIntRegState (
		.clock              (clk),
		.coreid             (0),
		.gpr_0              (register[0]),
		.gpr_1              (register[1]),
		.gpr_2              (register[2]),
		.gpr_3              (register[3]),
		.gpr_4              (register[4]),
		.gpr_5              (register[5]),
		.gpr_6              (register[6]),
		.gpr_7              (register[7]),
		.gpr_8              (register[8]),
		.gpr_9              (register[9]),
		.gpr_10             (register[10]),
		.gpr_11             (register[11]),
		.gpr_12             (register[12]),
		.gpr_13             (register[13]),
		.gpr_14             (register[14]),
		.gpr_15             (register[15]),
		.gpr_16             (register[16]),
		.gpr_17             (register[17]),
		.gpr_18             (register[18]),
		.gpr_19             (register[19]),
		.gpr_20             (register[20]),
		.gpr_21             (register[21]),
		.gpr_22             (register[22]),
		.gpr_23             (register[23]),
		.gpr_24             (register[24]),
		.gpr_25             (register[25]),
		.gpr_26             (register[26]),
		.gpr_27             (register[27]),
		.gpr_28             (register[28]),
		.gpr_29             (register[29]),
		.gpr_30             (register[30]),
		.gpr_31             (register[31])
    );

`endif
endmodule
`endif
