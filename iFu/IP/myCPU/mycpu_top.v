`ifndef __CORE_TOP
`define __CORE_TOP
`ifdef VERILATOR
`include "common.sv"
`include "CBusToAXI.sv"
`include "core.sv"
`else

`endif

module core_top
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
    clk        (aclk),
    reset      (reset),
    ext_int    (intrpt),
    //AXI
    creq       (creq),
    cresp      (cresp)
);

CBusToAXI CBusToAXI(
    aclk       (aclk),
    areset     (reset),
    // CBus
    creq       (creq),
    cresp      (cresp),
    // AXI
    arid       (arid),
    araddr     (araddr),
    arlen      (arlen),
    arsize     (arsize),
    arburst    (arburst),
    arlock     (arlock),
    arcache    (arcache),
    arprot     (arprot),
    arvalid    (arvalid),
    arready    (arready),
    rid        (rid),
    rdata      (rdata),
    rresp      (rresp),
    rlast      (rlast),
    rvalid     (rvalid),
    rready     (rready),
    awid       (awid),
    awaddr     (awaddr),
    awlen      (awlen),
    awsize     (awsize),
    awburst    (awburst),
    awlock     (awlock),
    awcache    (awcache),
    awprot     (awprot),
    awvalid    (awvalid),
    awready    (awready),
    wdata      (wdata),
    wstrb      (wstrb),
    wlast      (wlast),
    wvalid     (wvalid),
    wready     (wready),
    bid        (bid),
    bresp      (bresp),
    bvalid     (bvalid),
    bready     (bready)

);


`ifdef DIFFTEST_EN
// difftest
// // from wb_stage
// wire            ws_valid_diff       ;
// wire            cnt_inst_diff       ;
// wire    [63:0]  timer_64_diff       ;
// wire    [ 7:0]  inst_ld_en_diff     ;
// wire    [31:0]  ld_paddr_diff       ;
// wire    [31:0]  ld_vaddr_diff       ;
// wire    [ 7:0]  inst_st_en_diff     ;
// wire    [31:0]  st_paddr_diff       ;
// wire    [31:0]  st_vaddr_diff       ;
// wire    [31:0]  st_data_diff        ;
// wire            csr_rstat_en_diff   ;
// wire    [31:0]  csr_data_diff       ;

// wire inst_valid_diff = ws_valid_diff;
// reg             cmt_valid           ;
// reg             cmt_cnt_inst        ;
// reg     [63:0]  cmt_timer_64        ;
// reg     [ 7:0]  cmt_inst_ld_en      ;
// reg     [31:0]  cmt_ld_paddr        ;
// reg     [31:0]  cmt_ld_vaddr        ;
// reg     [ 7:0]  cmt_inst_st_en      ;
// reg     [31:0]  cmt_st_paddr        ;
// reg     [31:0]  cmt_st_vaddr        ;
// reg     [31:0]  cmt_st_data         ;
// reg             cmt_csr_rstat_en    ;
// reg     [31:0]  cmt_csr_data        ;

// reg             cmt_wen             ;
// reg     [ 7:0]  cmt_wdest           ;
// reg     [31:0]  cmt_wdata           ;
// reg     [31:0]  cmt_pc              ;
// reg     [31:0]  cmt_inst            ;

// reg             cmt_excp_flush      ;
// reg             cmt_ertn            ;
// reg     [5:0]   cmt_csr_ecode       ;
// reg             cmt_tlbfill_en      ;
// reg     [4:0]   cmt_rand_index      ;

// // to difftest debug
// reg             trap                ;
// reg     [ 7:0]  trap_code           ;
// reg     [63:0]  cycleCnt            ;
// reg     [63:0]  instrCnt            ;

// // from regfile
// wire    [31:0]  regs[31:0]          ;

// // from csr
// wire    [31:0]  csr_crmd_diff_0     ;
// wire    [31:0]  csr_prmd_diff_0     ;
// wire    [31:0]  csr_ectl_diff_0     ;
// wire    [31:0]  csr_estat_diff_0    ;
// wire    [31:0]  csr_era_diff_0      ;
// wire    [31:0]  csr_badv_diff_0     ;
// wire	[31:0]  csr_eentry_diff_0   ;
// wire 	[31:0]  csr_tlbidx_diff_0   ;
// wire 	[31:0]  csr_tlbehi_diff_0   ;
// wire 	[31:0]  csr_tlbelo0_diff_0  ;
// wire 	[31:0]  csr_tlbelo1_diff_0  ;
// wire 	[31:0]  csr_asid_diff_0     ;
// wire 	[31:0]  csr_save0_diff_0    ;
// wire 	[31:0]  csr_save1_diff_0    ;
// wire 	[31:0]  csr_save2_diff_0    ;
// wire 	[31:0]  csr_save3_diff_0    ;
// wire 	[31:0]  csr_tid_diff_0      ;
// wire 	[31:0]  csr_tcfg_diff_0     ;
// wire 	[31:0]  csr_tval_diff_0     ;
// wire 	[31:0]  csr_ticlr_diff_0    ;
// wire 	[31:0]  csr_llbctl_diff_0   ;
// wire 	[31:0]  csr_tlbrentry_diff_0;
// wire 	[31:0]  csr_dmw0_diff_0     ;
// wire 	[31:0]  csr_dmw1_diff_0     ;
// wire 	[31:0]  csr_pgdl_diff_0     ;
// wire 	[31:0]  csr_pgdh_diff_0     ;




// always @(posedge aclk) begin
//     if (reset) begin
//         {cmt_valid, cmt_cnt_inst, cmt_timer_64, cmt_inst_ld_en, cmt_ld_paddr, cmt_ld_vaddr, cmt_inst_st_en, cmt_st_paddr, cmt_st_vaddr, cmt_st_data, cmt_csr_rstat_en, cmt_csr_data} <= 0;
//         {cmt_wen, cmt_wdest, cmt_wdata, cmt_pc, cmt_inst} <= 0;
//         {trap, trap_code, cycleCnt, instrCnt} <= 0;
//     end else if (~trap) begin
//         cmt_valid       <= inst_valid_diff          ;
//         cmt_cnt_inst    <= cnt_inst_diff            ;
//         cmt_timer_64    <= timer_64_diff            ;
//         cmt_inst_ld_en  <= inst_ld_en_diff          ;
//         cmt_ld_paddr    <= ld_paddr_diff            ;
//         cmt_ld_vaddr    <= ld_vaddr_diff            ;
//         cmt_inst_st_en  <= inst_st_en_diff          ;
//         cmt_st_paddr    <= st_paddr_diff            ;
//         cmt_st_vaddr    <= st_vaddr_diff            ;
//         cmt_st_data     <= st_data_diff             ;
//         cmt_csr_rstat_en<= csr_rstat_en_diff        ;
//         cmt_csr_data    <= csr_data_diff            ;

//         cmt_wen     <=  debug0_wb_rf_wen            ;
//         cmt_wdest   <=  {3'd0, debug0_wb_rf_wnum}   ;
//         cmt_wdata   <=  debug0_wb_rf_wdata          ;
//         cmt_pc      <=  debug0_wb_pc                ;
//         cmt_inst    <=  debug0_wb_inst              ;

//         cmt_excp_flush  <= excp_flush               ;
//         cmt_ertn        <= ertn_flush               ;
//         cmt_csr_ecode   <= ws_csr_ecode             ;
//         cmt_tlbfill_en  <= tlbfill_en               ;
//         cmt_rand_index  <= rand_index               ;

//         trap            <= 0                        ;
//         trap_code       <= regs[10][7:0]            ;
//         cycleCnt        <= cycleCnt + 1             ;
//         instrCnt        <= instrCnt + inst_valid_diff;
//     end
// end

`endif
endmodule
`endif