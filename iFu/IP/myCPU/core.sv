`ifndef __CORE_SV
`define __CORE_SV
`ifdef VERILATOR
`include "common.sv"
`include "CBusArbiter.sv"
`include "iFuCore.sv"

`else

`endif



module core 
	import common::*;(
	input logic clk, reset,
	output cbus_req_t  creq,
	input  cbus_resp_t cresp,
	input logic [7:0] ext_int
);

    // for DiffTestInstrCommit
	logic[31:0] pc [3:0];
    logic[31:0] instr [3:0];
    logic[31:0] wdata [3:0];
    logic[4:0]  ldst [3:0];
    logic valid [3:0];
	logic wen [3:0];
    logic[31:0] register[31:0];

    // TODO:
    logic tlbFillEn [3:0];//tlbfill指令使能，当前指令为tlbfill指令时，该信号拉高
    logic [7:0] tlbFillIdx [3:0];//tlbfill指令对应的tlb表项索引
    logic isCnt [3:0];//与计时器相关的指令，提交指令为rdcntv{l/h}.w 或 rdcntid 时该位拉高
    logic [63:0] timer64 [3:0];//当前指令读出的64位计数器值(StableCounter)
    logic isCsrStat [3:0];//当提交指令为csrrd、csrwr、csrxchg，同时该指令对应的csr寄存器为estat寄存器时该位拉高
    logic [31:0] csrdata [3:0];//当csr_rstat == 1时，当前指令读取到的csr寄存器(estat)的值

    // for DiffTestExcpEvent
    // TODO:
    logic excpvalid;//当前指令如果有例外(包括外部中断)要处理，该位为1
    logic isEret;//当前指令为eret指令时，该位为1
    logic [10:0] intrNo;//csr寄存器中csr_estat[12:2]
    logic [14:0] ecode;//estat.ecode
    logic [31:0] epc;//出现异常的pc
    logic [31:0] einst;//出现异常的指令

    // for DiffTestStoreEvent
    // TODO:
    logic [7:0] stvalid [3:0];//store有效信号， 接法可参照 {4'b0, llbit && sc_w, st_w, st_h, st_b}
    logic [31:0] stpaddr [3:0];//store指令对应的物理地址
    logic [31:0] stvaddr [3:0];//store指令对应的虚拟地址
    logic [31:0] stdata [3:0];//store指令对应的数据

    // for DiffTestLoadEvent
    // TODO:
    logic [7:0] ldvalid [3:0];//load有效信号， 接法可参照 {2'b0, ll_w, ld_w, ld_hu, ld_h, ld_bu, ld_b}
    logic [31:0] ldpaddr [3:0];//load指令对应的物理地址
    logic [31:0] ldvaddr [3:0];//load指令对应的虚拟地址

    // TODO csr 寄存器信息
    logic [31:0] crmd;
    logic [31:0] prmd;
    logic [31:0] ecfg;
    logic [31:0] estat;
    logic [31:0] era;
    logic [31:0] badv;
    logic [31:0] eentry;
    logic [31:0] tlbidx;
    logic [31:0] tlbehi;
    logic [31:0] tlbelo0;
    logic [31:0] tlbelo1;
    logic [31:0] asid;
    logic [31:0] pgdl;
    logic [31:0] pgdh;
    logic [31:0] save0;
    logic [31:0] save1;
    logic [31:0] save2;
    logic [31:0] save3;
    logic [31:0] tid;
    logic [31:0] tcfg;
    logic [31:0] tval;
    logic [31:0] ticlr;
    logic [31:0] llbctl;
    logic [31:0] tlbrentry;
    logic [31:0] dmw0;
    logic [31:0] dmw1;

    cbus_req_t  icreq;
    cbus_resp_t icresp;
    cbus_req_t  dcreq;
    cbus_resp_t dcresp;


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


        .io_commit_debug_insts_0 (instr[0]),
        .io_commit_debug_insts_1 (instr[1]),
        .io_commit_debug_insts_2 (instr[2]),
        .io_commit_debug_insts_3 (instr[3]),

        .io_commit_debug_wdata_0 (wdata[0]),
        .io_commit_debug_wdata_1 (wdata[1]),
        .io_commit_debug_wdata_2 (wdata[2]),
        .io_commit_debug_wdata_3 (wdata[3]),

        .io_commit_debug_ldst_0 (ldst[0]),
        .io_commit_debug_ldst_1 (ldst[1]),
        .io_commit_debug_ldst_2 (ldst[2]),
        .io_commit_debug_ldst_3 (ldst[3]),

        .io_commit_debug_pc_0 (pc[0]),
        .io_commit_debug_pc_1 (pc[1]),
        .io_commit_debug_pc_2 (pc[2]),
        .io_commit_debug_pc_3 (pc[3]),

		.io_commit_debug_wen_0 (wen[0]),
		.io_commit_debug_wen_1 (wen[1]),
		.io_commit_debug_wen_2 (wen[2]),
		.io_commit_debug_wen_3 (wen[3]),

        .io_commit_arch_valids_0 (valid[0]),
        .io_commit_arch_valids_1 (valid[1]),
        .io_commit_arch_valids_2 (valid[2]),
        .io_commit_arch_valids_3 (valid[3]),

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

    CbusArbiter carib(
        .clk (clk),
        .reset(reset),
        .ireqs ({icreq, dcreq}),
        .iresps ({icresp, dcresp}),
        .oreq (creq),
        .oresp (cresp)
    );






`ifdef DIFFTEST_EN
DifftestInstrCommit DifftestInstrCommit0(
    .clock              (clk           ),
    .coreid             (0              ),
    .index              (0              ),
    .valid              (valid[0]      ),
    .pc                 (pc0         ),
    .instr              (instr[0]       ),
    .skip               (0              ),
    .is_TLBFILL         (tlbFillEn[0] ),//tlbfill指令使能，当前指令为tlbfill指令时，该信号拉高
    .TLBFILL_index      (tlbFillIdx[0] ),//tlbfill指令对应的tlb表项索引
    .is_CNTinst         (isCnt[0]   ),//与计时器相关的指令，提交指令为rdcntv{l/h}.w 或 rdcntid 时该位拉高
    .timer_64_value     (timer64[0]   ),//当前指令读出的64位计数器值(StableCounter)
    .wen                (wen[0]        ),
    .wdest              (ldst[0]      ),
    .wdata              (wdata[0]      ),
    .csr_rstat          (isCsrStat[0]),//当提交指令为csrrd、csrwr、csrxchg，同时该指令对应的csr寄存器为estat寄存器时该位拉高
    .csr_data           (csrdata[0]   )//当csr_rstat == 1时，当前指令读取到的csr寄存器(estat)的值
);

DifftestInstrCommit DifftestInstrCommit1(
    .clock              (clk           ),
    .coreid             (0              ),
    .index              (1              ),
    .valid              (valid[1]      ),
    .pc                 (pc[1]         ),
    .instr              (instr[1]       ),
    .skip               (0              ),
    .is_TLBFILL         (tlbFillEn[1] ),//
    .TLBFILL_index      (tlbFillIdx[1] ),//
    .is_CNTinst         (isCnt[1]   ),//
    .timer_64_value     (timer64[1]   ),//
    .wen                (wen[1]        ),
    .wdest              (ldst[1]      ),
    .wdata              (wdata[1]      ),
    .csr_rstat          (isCsrStat[1]),//
    .csr_data           (csrdata[1]   )//
);

DifftestInstrCommit DifftestInstrCommit2(
    .clock              (clk           ),
    .coreid             (0              ),
    .index              (2              ),
    .valid              (valid[2]      ),
    .pc                 (pc[2]         ),
    .instr              (instr[2]       ),
    .skip               (0              ),
    .is_TLBFILL         (tlbFillEn[2] ),//
    .TLBFILL_index      (tlbFillIdx[2] ),//
    .is_CNTinst         (isCnt[2]   ),//
    .timer_64_value     (timer64[2]   ),//
    .wen                (wen[2]        ),
    .wdest              (ldst[2]      ),
    .wdata              (wdata[2]      ),
    .csr_rstat          (isCsrStat[2]),//
    .csr_data           (csrdata[2]   )//
);

DifftestInstrCommit DifftestInstrCommit3(
    .clock              (clk           ),
    .coreid             (0              ),
    .index              (3              ),
    .valid              (valid[3]      ),
    .pc                 (pc[3]         ),
    .instr              (instr[3]       ),
    .skip               (0              ),
    .is_TLBFILL         (tlbFillEn[3] ),//
    .TLBFILL_index      (tlbFillIdx[3] ),//
    .is_CNTinst         (isCnt[3]   ),//
    .timer_64_value     (timer64[3]   ),//
    .wen                (wen[3]        ),
    .wdest              (ldst[3]      ),
    .wdata              (wdata[3]      ),
    .csr_rstat          (isCsrStat[3]),//
    .csr_data           (csrdata[3]   )//
);

DifftestExcpEvent DifftestExcpEvent(
    .clock              (clk           ),
    .coreid             (0              ),
    .excp_valid         (excpvalid ),//当前指令如果有例外(包括外部中断)要处理，该位为1
    .eret               (isEret       ),//当前指令为eret指令时，该位为1
    .intrNo             (intrNo),//csr寄存器中csr_estat[12:2]
    .cause              (ecode  ),//estat.ecode
    .exceptionPC        (epc         ),
    .exceptionInst      (einst       )
);

// 该模块目前并未使用
DifftestTrapEvent DifftestTrapEvent(
    .clock              (clk           ),
    .coreid             (0              ),
    .valid              (0           ),//
    .code               (0      ),//
    .pc                 (0         ),
    .cycleCnt           (0       ),//
    .instrCnt           (0       )//
);

DifftestStoreEvent DifftestStoreEvent0(
    .clock              (clk           ),
    .coreid             (0              ),
    .index              (0              ),
    .valid              (stvalid[0] ),//store有效信号， 接法可参照 {4'b0, llbit && sc_w, st_w, st_h, st_b}
    .storePAddr         (stpaddr[0]   ),//store指令对应的物理地址
    .storeVAddr         (stvaddr[0]   ),//store指令对应的虚拟地址
    .storeData          (stdata[0]    )//store指令对应的数据
);

DifftestStoreEvent DifftestStoreEvent1(
    .clock              (clk           ),
    .coreid             (0              ),
    .index              (1              ),
    .valid              (stvalid[1] ),//store有效信号， 接法可参照 {4'b0, llbit && sc_w, st_w, st_h, st_b}
    .storePAddr         (stpaddr[1]   ),//store指令对应的物理地址
    .storeVAddr         (stvaddr[1]   ),//store指令对应的虚拟地址
    .storeData          (stdata[1]    )//store指令对应的数据
);


DifftestStoreEvent DifftestStoreEvent2(
    .clock              (clk           ),
    .coreid             (0              ),
    .index              (2              ),
    .valid              (stvalid[2] ),//store有效信号， 接法可参照 {4'b0, llbit && sc_w, st_w, st_h, st_b}
    .storePAddr         (stpaddr[2]   ),//store指令对应的物理地址
    .storeVAddr         (stvaddr[2]   ),//store指令对应的虚拟地址
    .storeData          (stdata[2]    )//store指令对应的数据
);


DifftestStoreEvent DifftestStoreEvent3(
    .clock              (clk           ),
    .coreid             (0              ),
    .index              (3              ),
    .valid              (stvalid[3] ),//store有效信号， 接法可参照 {4'b0, llbit && sc_w, st_w, st_h, st_b}
    .storePAddr         (stpaddr[3]   ),//store指令对应的物理地址
    .storeVAddr         (stvaddr[3]   ),//store指令对应的虚拟地址
    .storeData          (stdata[3]    )//store指令对应的数据
);




DifftestLoadEvent DifftestLoadEvent0(
    .clock              (clk           ),
    .coreid             (0              ),
    .index              (0              ),
    .valid              (ldvalid[0] ),//load有效信号， 接法可参照 {2'b0, ll_w, ld_w, ld_hu, ld_h, ld_bu, ld_b}
    .paddr              (ldpaddr[0]   ),//load指令对应的物理地址
    .vaddr              (ldvaddr[0]   )//load指令对应的虚拟地址
);

DifftestLoadEvent DifftestLoadEvent1(
    .clock              (clk           ),
    .coreid             (0              ),
    .index              (1              ),
    .valid              (ldvalid[1] ),//load有效信号， 接法可参照 {2'b0, ll_w, ld_w, ld_hu, ld_h, ld_bu, ld_b}
    .paddr              (ldpaddr[1]   ),//load指令对应的物理地址
    .vaddr              (ldvaddr[1]   )//load指令对应的虚拟地址
);

DifftestLoadEvent DifftestLoadEvent2(
    .clock              (clk           ),
    .coreid             (0              ),
    .index              (2              ),
    .valid              (ldvalid[2] ),//load有效信号， 接法可参照 {2'b0, ll_w, ld_w, ld_hu, ld_h, ld_bu, ld_b}
    .paddr              (ldpaddr[2]   ),//load指令对应的物理地址
    .vaddr              (ldvaddr[2]   )//load指令对应的虚拟地址
);

DifftestLoadEvent DifftestLoadEvent3(
    .clock              (clk           ),
    .coreid             (0              ),
    .index              (3              ),
    .valid              (ldvalid[3] ),//load有效信号， 接法可参照 {2'b0, ll_w, ld_w, ld_hu, ld_h, ld_bu, ld_b}
    .paddr              (ldpaddr[3]   ),//load指令对应的物理地址
    .vaddr              (ldvaddr[3]   )//load指令对应的虚拟地址
);


//csr寄存器信息
DifftestCSRRegState DifftestCSRRegState(
    .clock              (clk     ),
    .coreid             (0       ),
    .crmd               (crmd    ),
    .prmd               (prmd    ),
    .euen               (0       ),
    .ecfg               (ectl    ),
    .estat              (estat   ),
    .era                (era     ),
    .badv               (badv    ),
    .eentry             (eentry  ),
    .tlbidx             (tlbidx  ),
    .tlbehi             (tlbehi  ),
    .tlbelo0            (tlbelo0 ),
    .tlbelo1            (tlbelo1 ),
    .asid               (asid    ),
    .pgdl               (pgdl    ),
    .pgdh               (pgdh    ),
    .save0              (save0   ),
    .save1              (save1   ),
    .save2              (save2   ),
    .save3              (save3   ),
    .tid                (tid     ),
    .tcfg               (tcfg    ),
    .tval               (tval    ),
    .ticlr              (ticlr   ),
    .llbctl             (llbctl  ),
    .tlbrentry          (tlbrentry),
    .dmw0               (dmw0    ),
    .dmw1               (dmw1    )
);

//通用寄存器的堆值
DifftestGRegState DifftestGRegState(
    .clock              (clk       ),
    .coreid             (0          ),
    .gpr_0              (0          ),
    .gpr_1              (register[1]    ),
    .gpr_2              (register[2]    ),
    .gpr_3              (register[3]    ),
    .gpr_4              (register[4]    ),
    .gpr_5              (register[5]    ),
    .gpr_6              (register[6]    ),
    .gpr_7              (register[7]    ),
    .gpr_8              (register[8]    ),
    .gpr_9              (register[9]    ),
    .gpr_10             (register[10]   ),
    .gpr_11             (register[11]   ),
    .gpr_12             (register[12]   ),
    .gpr_13             (register[13]   ),
    .gpr_14             (register[14]   ),
    .gpr_15             (register[15]   ),
    .gpr_16             (register[16]   ),
    .gpr_17             (register[17]   ),
    .gpr_18             (register[18]   ),
    .gpr_19             (register[19]   ),
    .gpr_20             (register[20]   ),
    .gpr_21             (register[21]   ),
    .gpr_22             (register[22]   ),
    .gpr_23             (register[23]   ),
    .gpr_24             (register[24]   ),
    .gpr_25             (register[25]   ),
    .gpr_26             (register[26]   ),
    .gpr_27             (register[27]   ),
    .gpr_28             (register[28]   ),
    .gpr_29             (register[29]   ),
    .gpr_30             (register[30]   ),
    .gpr_31             (register[31]   )
);
`endif
endmodule
`endif
