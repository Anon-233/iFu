package iFu.backend

import chisel3._
import chisel3.util._
import iFu.common._
import iFu.backend.CSRAddr._

object CSRAddr {
    val CRMD            = 0x0;
    val PRMD            = 0x1;
    val ECTL            = 0x4;
    val ESTAT           = 0x5;
    val ERA             = 0x6;
    val BADV            = 0x7;
    val EENTRY          = 0xc;
    val TLBIDX          = 0x10;
    val TLBEHI          = 0x11;
    val TLBELO0         = 0x12;
    val TLBELO1         = 0x13;
    val ASID            = 0x18;
    val PGDL            = 0x19;
    val PGDH            = 0x1a;
    val PGD             = 0x1b;
    val CPUID           = 0x20;
    val SAVE0           = 0x30;
    val SAVE1           = 0x31;
    val SAVE2           = 0x32;
    val SAVE3           = 0x33;
    val TID             = 0x40;
    val TCFG            = 0x41;
    val TVAL            = 0x42;
    val CNTC            = 0x43;
    val TICLR           = 0x44;
    val LLBCTL          = 0x60;
    val TLBRENTRY       = 0x88;
    val DMW0            = 0x180;
    val DMW1            = 0x181;
    val BRK             = 0x100;
    val DISABLE_CACHE   = 0x101;
}








object CauseCode{
    val ecodeBits = 6
    val subcodeBits = 9

    val causeCodeBits = ecodeBits + subcodeBits

    //中断：接收到外部硬件中断，核间中断，内部软中断，定时器中断
    val INT  =  Cat(0x0.U(ecodeBits.W),0x0.U(subcodeBits.W))

    //Load操作页无效：load指令访问的页表项无效
    val PIL  =  Cat(0x1.U(ecodeBits.W),0x0.U(subcodeBits.W))

    //store操作页无效:store指令访问的页表项无效
    val PIS  =  Cat(0x2.U(ecodeBits.W),0x0.U(subcodeBits.W))

    //取指操作页无效:取指操作访问的页表项无效
    val PIF  =  Cat(0x3.U(ecodeBits.W),0x0.U(subcodeBits.W))

    //页修改:store指令访问一个可写位和脏位不全为1的有效页表项
    val PME  =  Cat(0x4.U(ecodeBits.W),0x0.U(subcodeBits.W))

    //页特权等级不合规 :访问的有效页表项的PLV等级权限高于CPU当前的PLV等级
    val PPI  =  Cat(0x7.U(ecodeBits.W),0x0.U(subcodeBits.W))

    //取指地址错 :取指PC不对齐；映射地址模式下，CPU当前处于PLV3，PC第31位为1且不落在任何有效的直接映射窗口中
    val ADEF =  Cat(0x8.U(ecodeBits.W),0x0.U(subcodeBits.W))

    //访存指令地址错:映射地址模式下，CPU当前处于PLV3，访存指令虚地址的第31位为1,且不落在任何有效的直接映射窗口中
    val ADEM =  Cat(0x8.U(ecodeBits.W),0x1.U(subcodeBits.W))

    //地址非对齐 : 非字节访存指令的地址不是自然对齐的
    val ALE  =  Cat(0x9.U(ecodeBits.W),0x0.U(subcodeBits.W))

    //系统调用  : 执行syscall指令
    val SYS  =  Cat(0xb.U(ecodeBits.W),0x0.U(subcodeBits.W))

    //断点 :执行break指令
    val BRK  =  Cat(0xc.U(ecodeBits.W),0x0.U(subcodeBits.W))

    //指令不存在 : 当前指令是一条未定义（/未实现）指令
    val INE  =  Cat(0xd.U(ecodeBits.W),0x0.U(subcodeBits.W))

    // 指令特权等级错 :CPU当前处于PLV3，执行特权指令
    val IPE  =  Cat(0xe.U(ecodeBits.W),0x0.U(subcodeBits.W))

    //浮点指令未使能 :CPU实现了浮点指令前提下，当CSR.EUEN.FPE=0时执行浮点指令
    val FPD  =  Cat(0xf.U(ecodeBits.W),0x0.U(subcodeBits.W))

    //基础浮点运算异常:浮点运算过程中满足IEEE754规范中触发浮点运算异常的情况
    val FPE  =  Cat(0x12.U(ecodeBits.W),0x0.U(subcodeBits.W))

    //TLB重填 : 映射地址模式下，访存地址不落在任何有效的直接映射窗口中，且在TLB中找不到对应的TLB表项
    val TLBR =  Cat(0x3f.U(ecodeBits.W),0x0.U(subcodeBits.W))

}




/*
define PLV       1:0
`define IE        2
`define DA        3
`define PG        4
`define DATF      6:5
`define DATM      8:7
//PRMD
`define PPLV      1:0
`define PIE       2
//ECTL
`define LIE       12:0
`define LIE_1     9:0
`define LIE_2     12:11
//ESTAT
`define IS        12:0
`define ECODE     21:16
`define ESUBCODE  30:22
//TLBIDX
`define INDEX     4:0
`define PS        29:24
`define NE        31
//TLBEHI
`define VPPN      31:13
//TLBELO
`define TLB_V      0
`define TLB_D      1
`define TLB_PLV    3:2
`define TLB_MAT    5:4
`define TLB_G      6
`define TLB_PPN    31:8
`define TLB_PPN_EN 27:8   //todo
//ASID
`define TLB_ASID  9:0
//CPUID
`define COREID    8:0
//LLBCTL
`define ROLLB     0
`define WCLLB     1
`define KLO       2
//TCFG
`define EN        0
`define PERIODIC  1
`define INITVAL   31:2
//TICLR
`define CLR       0
//TLBRENTRY
`define TLBRENTRY_PA 31:6
//DMW
`define PLV0      0
`define PLV3      3 
`define DMW_MAT   5:4
`define PSEG      27:25
`define VSEG      31:29
//PGDL PGDH PGD
`define BASE      31:12

`define ECODE_INT  6'h0
`define ECODE_PIL  6'h1
`define ECODE_PIS  6'h2
`define ECODE_PIF  6'h3
`define ECODE_PME  6'h4
`define ECODE_PPI  6'h7
`define ECODE_ADEF 6'h8
`define ECODE_ALE  6'h9
`define ECODE_SYS  6'hb
`define ECODE_BRK  6'hc
`define ECODE_INE  6'hd
`define ECODE_IPE  6'he
`define ECODE_FPD  6'hf
`define ECODE_TLBR 6'h3f

`define ESUBCODE_ADEF  9'h0







module csr 
#(
	parameter TLBNUM = 32
)
(
    input                           clk          ,
    input                           reset        ,
    //from to ds 
    input  [13:0]                   rd_addr      ,
    output [31:0]                   rd_data      ,
    //timer 64
    output [63:0]                   timer_64_out ,
    output [31:0]                   tid_out      ,
    //from ws
    input                           csr_wr_en    ,
    input  [13:0]                   wr_addr      ,
    input  [31:0]                   wr_data      ,
    //interrupt
    input  [ 7:0]                   interrupt    ,
    output                          has_int      ,
    //from ws
    input                           excp_flush   ,
    input                           ertn_flush   ,
    input  [31:0]                   era_in       ,
    input  [ 8:0]                   esubcode_in  ,
    input  [ 5:0]                   ecode_in     ,
    input                           va_error_in  ,
    input  [31:0]                   bad_va_in    ,
    input                           tlbsrch_en    ,
    input                           tlbsrch_found ,
    input  [ 4:0]                   tlbsrch_index ,
    input                           excp_tlbrefill,
    input                           excp_tlb     ,
    input  [18:0]                   excp_tlb_vppn,
    //from ws llbit
    input                           llbit_in     ,
    input                           llbit_set_in ,
    //to es
    output                          llbit_out    ,
    output [18:0]                   vppn_out     ,
    //to fs
    output [31:0]                   eentry_out   ,
    output [31:0]                   era_out      ,
    output [31:0]                   tlbrentry_out,
    output                          disable_cache_out,
    //to addr trans
    output [ 9:0]                   asid_out     ,
    output [ 4:0]                   rand_index   ,
    output [31:0]                   tlbehi_out   ,
    output [31:0]                   tlbelo0_out  ,
    output [31:0]                   tlbelo1_out  ,
    output [31:0]                   tlbidx_out   ,
    output                          pg_out       ,
    output                          da_out       ,
    output [31:0]                   dmw0_out     ,
    output [31:0]                   dmw1_out     ,
    output [ 1:0]                   datf_out     ,
    output [ 1:0]                   datm_out     ,
    output [ 5:0]                   ecode_out    ,
    //from addr trans 
    input                           tlbrd_en     ,
    input  [31:0]                   tlbehi_in    ,
    input  [31:0]                   tlbelo0_in   ,
    input  [31:0]                   tlbelo1_in   ,
    input  [31:0]                   tlbidx_in    ,
    input  [ 9:0]                   asid_in      ,
    //general use
    output [ 1:0]                   plv_out      ,
    // csr regs for diff
    output [31:0]                   csr_crmd_diff,
    output [31:0]                   csr_prmd_diff,
    output [31:0]                   csr_ectl_diff,
    output [31:0]                   csr_estat_diff,
    output [31:0]                   csr_era_diff,
    output [31:0]                   csr_badv_diff,
    output [31:0]                   csr_eentry_diff,
    output [31:0]                   csr_tlbidx_diff,
    output [31:0]                   csr_tlbehi_diff,
    output [31:0]                   csr_tlbelo0_diff,
    output [31:0]                   csr_tlbelo1_diff,
    output [31:0]                   csr_asid_diff,
    output [31:0]                   csr_save0_diff,
    output [31:0]                   csr_save1_diff,
    output [31:0]                   csr_save2_diff,
    output [31:0]                   csr_save3_diff,
    output [31:0]                   csr_tid_diff,
    output [31:0]                   csr_tcfg_diff,
    output [31:0]                   csr_tval_diff,
    output [31:0]                   csr_ticlr_diff,
    output [31:0]                   csr_llbctl_diff,
    output [31:0]                   csr_tlbrentry_diff,
    output [31:0]                   csr_dmw0_diff,
    output [31:0]                   csr_dmw1_diff,
    output [31:0]                   csr_pgdl_diff,
    output [31:0]                   csr_pgdh_diff
);

localparam CRMD  = 14'h0;
localparam PRMD  = 14'h1;
localparam ECTL  = 14'h4;
localparam ESTAT = 14'h5;
localparam ERA   = 14'h6;
localparam BADV  = 14'h7;
localparam EENTRY = 14'hc;
localparam TLBIDX= 14'h10;
localparam TLBEHI= 14'h11;
localparam TLBELO0=14'h12;
localparam TLBELO1=14'h13;
localparam ASID  = 14'h18;
localparam PGDL  = 14'h19;
localparam PGDH  = 14'h1a;
localparam PGD   = 14'h1b;
localparam CPUID = 14'h20;
localparam SAVE0 = 14'h30;
localparam SAVE1 = 14'h31;
localparam SAVE2 = 14'h32;
localparam SAVE3 = 14'h33;
localparam TID   = 14'h40;
localparam TCFG  = 14'h41;
localparam TVAL  = 14'h42;
localparam CNTC  = 14'h43;
localparam TICLR = 14'h44;
localparam LLBCTL= 14'h60;
localparam TLBRENTRY = 14'h88;
localparam DMW0  = 14'h180;
localparam DMW1  = 14'h181;
localparam BRK = 14'h100;
localparam DISABLE_CACHE = 14'h101;

wire crmd_wen   = csr_wr_en & (wr_addr == CRMD);
wire prmd_wen   = csr_wr_en & (wr_addr == PRMD);
wire ectl_wen   = csr_wr_en & (wr_addr == ECTL);
wire estat_wen  = csr_wr_en & (wr_addr == ESTAT);
wire era_wen    = csr_wr_en & (wr_addr == ERA);
wire badv_wen   = csr_wr_en & (wr_addr == BADV);
wire eentry_wen = csr_wr_en & (wr_addr == EENTRY);
wire tlbidx_wen = csr_wr_en & (wr_addr == TLBIDX);
wire tlbehi_wen = csr_wr_en & (wr_addr == TLBEHI);
wire tlbelo0_wen= csr_wr_en & (wr_addr == TLBELO0);
wire tlbelo1_wen= csr_wr_en & (wr_addr == TLBELO1);
wire asid_wen   = csr_wr_en & (wr_addr == ASID);
wire pgdl_wen   = csr_wr_en & (wr_addr == PGDL);
wire pgdh_wen   = csr_wr_en & (wr_addr == PGDH);
wire pgd_wen    = csr_wr_en & (wr_addr == PGD);
wire cpuid_wen  = csr_wr_en & (wr_addr == CPUID);
wire save0_wen  = csr_wr_en & (wr_addr == SAVE0);
wire save1_wen  = csr_wr_en & (wr_addr == SAVE1);
wire save2_wen  = csr_wr_en & (wr_addr == SAVE2);
wire save3_wen  = csr_wr_en & (wr_addr == SAVE3);
wire tid_wen    = csr_wr_en & (wr_addr == TID);
wire tcfg_wen   = csr_wr_en & (wr_addr == TCFG);
wire tval_wen   = csr_wr_en & (wr_addr == TVAL);
wire cntc_wen   = csr_wr_en & (wr_addr == CNTC);
wire ticlr_wen  = csr_wr_en & (wr_addr == TICLR);
wire llbctl_wen = csr_wr_en & (wr_addr == LLBCTL);
wire tlbrentry_wen = csr_wr_en & (wr_addr == TLBRENTRY);
wire DMW0_wen   = csr_wr_en & (wr_addr == DMW0);
wire DMW1_wen   = csr_wr_en & (wr_addr == DMW1);
wire BRK_wen    = csr_wr_en & (wr_addr == BRK);
wire disable_cache_wen = csr_wr_en & (wr_addr == DISABLE_CACHE);

reg [31:0] csr_crmd;
reg [31:0] csr_prmd;
reg [31:0] csr_ectl;
reg [31:0] csr_estat;
reg [31:0] csr_era;
reg [31:0] csr_badv;
reg [31:0] csr_eentry;
reg [31:0] csr_tlbidx;
reg [31:0] csr_tlbehi;
reg [31:0] csr_tlbelo0;
reg [31:0] csr_tlbelo1;
reg [31:0] csr_asid;
reg [31:0] csr_cpuid;
reg [31:0] csr_save0;
reg [31:0] csr_save1;
reg [31:0] csr_save2;
reg [31:0] csr_save3;
reg [31:0] csr_tid;
reg [31:0] csr_tcfg;
reg [31:0] csr_tval;
reg [31:0] csr_cntc;
reg [31:0] csr_ticlr;
reg [31:0] csr_llbctl;
reg [31:0] csr_tlbrentry;
reg [31:0] csr_dmw0;
reg [31:0] csr_dmw1;
reg [31:0] csr_pgdl;
reg [31:0] csr_pgdh;
reg [31:0] csr_brk;
reg [31:0] csr_disable_cache;

wire [31:0] csr_pgd;

reg        timer_en;
reg [63:0] timer_64;

reg        llbit;

wire tlbrd_valid_wr_en;
wire tlbrd_invalid_wr_en;

wire eret_tlbrefill_excp;

wire no_forward;

assign csr_pgd = csr_badv[31] ? csr_pgdh : csr_pgdl;

assign eret_tlbrefill_excp = csr_estat[`ECODE] == 6'h3f;

assign tlbrd_valid_wr_en   = tlbrd_en && !tlbidx_in[`NE];
assign tlbrd_invalid_wr_en = tlbrd_en &&  tlbidx_in[`NE];

assign has_int = ((csr_ectl[`LIE] & csr_estat[`IS]) != 13'b0) & csr_crmd[`IE];

assign eentry_out   = csr_eentry;
assign era_out      = csr_era;
assign timer_64_out = timer_64 + {{32{csr_cntc[31]}}, csr_cntc};
assign tid_out      = csr_tid;
assign llbit_out    = llbit;
assign asid_out     = csr_asid[`TLB_ASID];
assign vppn_out     = (csr_wr_en && wr_addr == TLBEHI) ? wr_data[`VPPN] : csr_tlbehi[`VPPN];
assign tlbehi_out   = csr_tlbehi;
assign tlbelo0_out  = csr_tlbelo0;
assign tlbelo1_out  = csr_tlbelo1;
assign tlbidx_out   = csr_tlbidx;
assign rand_index   = timer_64[4:0];
assign disable_cache_out = csr_disable_cache[0];

//forward to if stage
assign no_forward   = !excp_tlbrefill && !(eret_tlbrefill_excp && ertn_flush) && !crmd_wen;

assign pg_out       = excp_tlbrefill & 1'b0                      |
                      (eret_tlbrefill_excp && ertn_flush) & 1'b1 |
                      crmd_wen       & wr_data[`PG]              |
                      no_forward     & csr_crmd[`PG];

assign da_out       = excp_tlbrefill & 1'b1                      |
                      (eret_tlbrefill_excp && ertn_flush) & 1'b0 |
                      crmd_wen       & wr_data[`DA]              |
                      no_forward     & csr_crmd[`DA];

assign dmw0_out     = DMW0_wen ? wr_data : csr_dmw0;
assign dmw1_out     = DMW1_wen ? wr_data : csr_dmw1;

assign plv_out      = {2{excp_flush}} & 2'b0            |
                      {2{ertn_flush}} & csr_prmd[`PPLV] |
                      {2{crmd_wen  }} & wr_data[`PLV]   |
                      {2{!excp_flush && !ertn_flush && !crmd_wen}} & csr_crmd[`PLV];

assign tlbrentry_out= csr_tlbrentry;
assign datf_out     = csr_crmd[`DATF];
assign datm_out     = csr_crmd[`DATM];

assign ecode_out    = csr_estat[`ECODE];

assign rd_data = {32{rd_addr == CRMD  }}  & csr_crmd    |
                 {32{rd_addr == PRMD  }}  & csr_prmd    |
                 {32{rd_addr == ECTL  }}  & csr_ectl    |
                 {32{rd_addr == ESTAT }}  & csr_estat   |
                 {32{rd_addr == ERA   }}  & csr_era	    |
                 {32{rd_addr == BADV  }}  & csr_badv    |
                 {32{rd_addr == EENTRY}}  & csr_eentry  |
                 {32{rd_addr == TLBIDX}}  & csr_tlbidx  |
                 {32{rd_addr == TLBEHI}}  & csr_tlbehi  |
                 {32{rd_addr == TLBELO0}} & csr_tlbelo0 |
                 {32{rd_addr == TLBELO1}} & csr_tlbelo1 |
                 {32{rd_addr == ASID  }}  & csr_asid    |
                 {32{rd_addr == PGDL  }}  & csr_pgdl    |
                 {32{rd_addr == PGDH  }}  & csr_pgdh    |
                 {32{rd_addr == PGD   }}  & csr_pgd     |
                 {32{rd_addr == CPUID }}  & csr_cpuid   |
                 {32{rd_addr == SAVE0 }}  & csr_save0   |
                 {32{rd_addr == SAVE1 }}  & csr_save1   |
                 {32{rd_addr == SAVE2 }}  & csr_save2   |
                 {32{rd_addr == SAVE3 }}  & csr_save3   |
                 {32{rd_addr == TID   }}  & csr_tid     |
                 {32{rd_addr == TCFG  }}  & csr_tcfg    |
                 {32{rd_addr == CNTC  }}  & csr_cntc    |
                 {32{rd_addr == TICLR }}  & csr_ticlr   |
                 {32{rd_addr == LLBCTL}}  & {csr_llbctl[31:1], llbit} |
                 {32{rd_addr == TVAL  }}  & csr_tval    |
                 {32{rd_addr == TLBRENTRY}} & csr_tlbrentry   |
                 {32{rd_addr == DMW0}}    & csr_dmw0    |
                 {32{rd_addr == DMW1}}    & csr_dmw1    ;

//crmd
always @(posedge clk) begin
    if (reset) begin
        csr_crmd[ `PLV] <=  2'b0;
        csr_crmd[  `IE] <=  1'b0;
        csr_crmd[  `DA] <=  1'b1;
        csr_crmd[  `PG] <=  1'b0;
        csr_crmd[`DATF] <=  2'b0;
        csr_crmd[`DATM] <=  2'b0;
        csr_crmd[31: 9] <= 23'b0;
    end
    else if (excp_flush) begin
        csr_crmd[ `PLV] <=  2'b0;
        csr_crmd[  `IE] <=  1'b0;
    if (excp_tlbrefill) begin
        csr_crmd [`DA] <= 1'b1;
        csr_crmd [`PG] <= 1'b0;
    end
    end
    else if (ertn_flush) begin
        csr_crmd[ `PLV] <= csr_prmd[`PPLV];
        csr_crmd[  `IE] <= csr_prmd[`PIE ];
        if (eret_tlbrefill_excp) begin
            csr_crmd[`DA] <= 1'b0;
            csr_crmd[`PG] <= 1'b1;
        end
    end 
    else if (crmd_wen) begin
        csr_crmd[ `PLV] <= wr_data[ `PLV];
        csr_crmd[  `IE] <= wr_data[	 `IE];
        csr_crmd[  `DA] <= wr_data[	 `DA];
        csr_crmd[  `PG] <= wr_data[  `PG];
        csr_crmd[`DATF] <= wr_data[`DATF];
        csr_crmd[`DATM] <= wr_data[`DATM];
    end
end

//prmd
always @(posedge clk) begin
    if (reset) begin
        csr_prmd[31:3] <= 29'b0;
    end
    else if (excp_flush) begin
        csr_prmd[`PPLV] <= csr_crmd[`PLV];
        csr_prmd[ `PIE] <= csr_crmd[`IE ];
    end
    else if (prmd_wen) begin
        csr_prmd[`PPLV] <= wr_data[`PPLV];
        csr_prmd[ `PIE] <= wr_data[ `PIE];
    end
end

//ectl
always @(posedge clk) begin
    if (reset) begin
        csr_ectl <= 32'b0;
    end
    else if (ectl_wen) begin
        csr_ectl[ `LIE_1] <= wr_data[ `LIE_1];
        csr_ectl[ `LIE_2] <= wr_data[ `LIE_2];
    end
end

//estat
always @(posedge clk) begin
    if (reset) begin
        csr_estat[ 1: 0] <= 2'b0; 
		csr_estat[10]    <= 1'b0;
		csr_estat[12]    <= 1'b0;
        csr_estat[15:13] <= 3'b0;
        csr_estat[31]    <= 1'b0;
        
        timer_en <= 1'b0;
    end
    else begin
        if (ticlr_wen && wr_data[`CLR]) begin
            csr_estat[11] <= 1'b0;
        end
        else if (tcfg_wen) begin
            timer_en <= wr_data[`EN];
        end
        else if (timer_en && (csr_tval == 32'b0)) begin
            csr_estat[11] <= 1'b1;
            timer_en      <= csr_tcfg[`PERIODIC];
        end
        csr_estat[9:2] <= interrupt;
        if (excp_flush) begin
            csr_estat[   `ECODE] <= ecode_in;
            csr_estat[`ESUBCODE] <= esubcode_in;
        end
        else if (estat_wen) begin
            csr_estat[      1:0] <= wr_data[      1:0];
        end
    end
end

//era
always @(posedge clk) begin
    if (excp_flush) begin
        csr_era <= era_in;
    end
    else if (era_wen) begin
        csr_era <= wr_data;
    end
end

//badv
always @(posedge clk) begin
    if (badv_wen) begin
        csr_badv <= wr_data;
    end
    else if (va_error_in) begin
        csr_badv <= bad_va_in;
    end
end

//eentry
always @(posedge clk) begin
    if (reset) begin
        csr_eentry[5:0] <= 6'b0;
    end
    else if (eentry_wen) begin
        csr_eentry[31:6] <= wr_data[31:6];
    end
end

//tlbidx
always @(posedge clk) begin
    if (reset) begin
        csr_tlbidx[23: 5] <= 19'b0;
        csr_tlbidx[30]    <= 1'b0;
		csr_tlbidx[`INDEX]<= 5'b0;
    end
    else if (tlbidx_wen) begin
		csr_tlbidx[$clog2(TLBNUM)-1:0] <= wr_data[$clog2(TLBNUM)-1:0];
        csr_tlbidx[`PS]    <= wr_data[`PS];
        csr_tlbidx[`NE]    <= wr_data[`NE];
    end
    else if (tlbsrch_en) begin
        if (tlbsrch_found) begin
            csr_tlbidx[`INDEX] <= tlbsrch_index;
            csr_tlbidx[`NE]    <= 1'b0;
        end
        else begin
            csr_tlbidx[`NE] <= 1'b1;
        end
    end
    else if (tlbrd_valid_wr_en) begin
        csr_tlbidx[`PS] <= tlbidx_in[`PS];
        csr_tlbidx[`NE] <= tlbidx_in[`NE];
    end
    else if (tlbrd_invalid_wr_en) begin
        csr_tlbidx[`PS] <= 6'b0;
        csr_tlbidx[`NE] <= tlbidx_in[`NE];
    end
end

//tlbehi
always @(posedge clk) begin
    if (reset) begin
        csr_tlbehi[12:0] <= 13'b0;
    end
    else if (tlbehi_wen) begin
        csr_tlbehi[`VPPN] <= wr_data[`VPPN];
    end
    else if (tlbrd_valid_wr_en) begin
        csr_tlbehi[`VPPN] <= tlbehi_in[`VPPN];
    end
    else if (tlbrd_invalid_wr_en) begin
        csr_tlbehi[`VPPN] <= 19'b0;
    end
    else if (excp_tlb) begin
        csr_tlbehi[`VPPN] <= excp_tlb_vppn;
    end
end

//tlbelo0
always @(posedge clk) begin
    if (reset) begin
        csr_tlbelo0[7] <= 1'b0;
    end
    else if (tlbelo0_wen) begin
        csr_tlbelo0[`TLB_V]   <= wr_data[`TLB_V];
        csr_tlbelo0[`TLB_D]   <= wr_data[`TLB_D];
        csr_tlbelo0[`TLB_PLV] <= wr_data[`TLB_PLV];
        csr_tlbelo0[`TLB_MAT] <= wr_data[`TLB_MAT];
        csr_tlbelo0[`TLB_G]   <= wr_data[`TLB_G];
        csr_tlbelo0[`TLB_PPN] <= wr_data[`TLB_PPN];
    end
    else if (tlbrd_valid_wr_en) begin
        csr_tlbelo0[`TLB_V]   <= tlbelo0_in[`TLB_V];
        csr_tlbelo0[`TLB_D]   <= tlbelo0_in[`TLB_D];
        csr_tlbelo0[`TLB_PLV] <= tlbelo0_in[`TLB_PLV];
        csr_tlbelo0[`TLB_MAT] <= tlbelo0_in[`TLB_MAT];
        csr_tlbelo0[`TLB_G]   <= tlbelo0_in[`TLB_G];
        csr_tlbelo0[`TLB_PPN] <= tlbelo0_in[`TLB_PPN];
    end
    else if (tlbrd_invalid_wr_en) begin
        csr_tlbelo0[`TLB_V]   <= 1'b0;
        csr_tlbelo0[`TLB_D]   <= 1'b0;
        csr_tlbelo0[`TLB_PLV] <= 2'b0;
        csr_tlbelo0[`TLB_MAT] <= 2'b0;
        csr_tlbelo0[`TLB_G]   <= 1'b0;
        csr_tlbelo0[`TLB_PPN] <= 24'b0;
    end
end

//tlbelo1
always @(posedge clk) begin
    if (reset) begin
        csr_tlbelo1[7] <= 1'b0;
    end
    else if (tlbelo1_wen) begin
        csr_tlbelo1[`TLB_V]   <= wr_data[`TLB_V];
        csr_tlbelo1[`TLB_D]   <= wr_data[`TLB_D];
        csr_tlbelo1[`TLB_PLV] <= wr_data[`TLB_PLV];
        csr_tlbelo1[`TLB_MAT] <= wr_data[`TLB_MAT];
        csr_tlbelo1[`TLB_G]   <= wr_data[`TLB_G];
        csr_tlbelo1[`TLB_PPN] <= wr_data[`TLB_PPN];
    end
    else if (tlbrd_valid_wr_en) begin
        csr_tlbelo1[`TLB_V]   <= tlbelo1_in[`TLB_V];
        csr_tlbelo1[`TLB_D]   <= tlbelo1_in[`TLB_D];
        csr_tlbelo1[`TLB_PLV] <= tlbelo1_in[`TLB_PLV];
        csr_tlbelo1[`TLB_MAT] <= tlbelo1_in[`TLB_MAT];
        csr_tlbelo1[`TLB_G]   <= tlbelo1_in[`TLB_G];
        csr_tlbelo1[`TLB_PPN] <= tlbelo1_in[`TLB_PPN];
    end
    else if (tlbrd_invalid_wr_en) begin
        csr_tlbelo1[`TLB_V]   <= 1'b0;
        csr_tlbelo1[`TLB_D]   <= 1'b0;
        csr_tlbelo1[`TLB_PLV] <= 2'b0;
        csr_tlbelo1[`TLB_MAT] <= 2'b0;
        csr_tlbelo1[`TLB_G]   <= 1'b0;
        csr_tlbelo1[`TLB_PPN] <= 24'b0;
    end
end

//asid
always @(posedge clk) begin
    if (reset) begin
        csr_asid[31:10] <= 22'h280; //ASIDBITS = 10
    end
    else if (asid_wen) begin
        csr_asid[`TLB_ASID] <= wr_data[`TLB_ASID];
    end
    else if (tlbrd_valid_wr_en) begin
        csr_asid[`TLB_ASID] <= asid_in;
    end
    else if (tlbrd_invalid_wr_en) begin
        csr_asid[`TLB_ASID] <= 10'b0;
    end
end

//TLBRENTRY
always @(posedge clk) begin
    if (reset) begin
        csr_tlbrentry[5:0] <= 6'b0;
    end
    else if (tlbrentry_wen) begin
        csr_tlbrentry[`TLBRENTRY_PA] <= wr_data[`TLBRENTRY_PA];
    end
end

//dmw0
always @(posedge clk) begin
    if (reset) begin
        csr_dmw0[ 2:1] <= 2'b0;
        csr_dmw0[24:6] <= 19'b0;
        csr_dmw0[28]   <= 1'b0;
    end
    else if (DMW0_wen) begin
        csr_dmw0[`PLV0]    <= wr_data[`PLV0];
        csr_dmw0[`PLV3]    <= wr_data[`PLV3];
        csr_dmw0[`DMW_MAT] <= wr_data[`DMW_MAT];
        csr_dmw0[`PSEG]    <= wr_data[`PSEG];
        csr_dmw0[`VSEG]    <= wr_data[`VSEG];
    end
end

//dmw1
always @(posedge clk) begin
    if (reset) begin
        csr_dmw1[ 2:1] <= 2'b0;
        csr_dmw1[24:6] <= 19'b0;
        csr_dmw1[28]   <= 1'b0;
    end
    else if (DMW1_wen) begin
        csr_dmw1[`PLV0]    <= wr_data[`PLV0];
        csr_dmw1[`PLV3]    <= wr_data[`PLV3];
        csr_dmw1[`DMW_MAT] <= wr_data[`DMW_MAT];
        csr_dmw1[`PSEG]    <= wr_data[`PSEG];
        csr_dmw1[`VSEG]    <= wr_data[`VSEG];
    end
end

//cpuid
always @(posedge clk) begin
    if (reset) begin
        csr_cpuid <= 32'b0;
    end 
end

//save0
always @(posedge clk) begin
    if (save0_wen) begin
        csr_save0 <= wr_data;
    end 
end

//save1
always @(posedge clk) begin
    if (save1_wen) begin
        csr_save1 <= wr_data;
    end 
end

//save2
always @(posedge clk) begin
    if (save2_wen) begin
        csr_save2 <= wr_data;
    end 
end

//save3
always @(posedge clk) begin
    if (save3_wen) begin
        csr_save3 <= wr_data;
    end 
end

//tid
always @(posedge clk) begin
    if (reset) begin
        csr_tid <= 32'b0;
    end
    else if (tid_wen) begin
        csr_tid <= wr_data;
    end
end

//tcfg
always @(posedge clk) begin
    if (reset) begin
        csr_tcfg[`EN] <= 1'b0;
    end
    else if (tcfg_wen) begin
        csr_tcfg[      `EN] <= wr_data[      `EN];
        csr_tcfg[`PERIODIC] <= wr_data[`PERIODIC];
        csr_tcfg[ `INITVAL] <= wr_data[ `INITVAL];
    end
end

//cntc
always @(posedge clk) begin
    if (reset) begin
        csr_cntc <= 32'b0;
    end
    else if (cntc_wen) begin
        csr_cntc <= wr_data;
    end
end

//tval
always @(posedge clk) begin
    if (tcfg_wen) begin
        csr_tval <= {wr_data[ `INITVAL], 2'b0};
    end
    else if (timer_en) begin
        if (csr_tval != 32'b0) begin
            csr_tval <= csr_tval - 32'b1;
        end
        else if (csr_tval == 32'b0) begin
            csr_tval <= csr_tcfg[`PERIODIC] ? {csr_tcfg[`INITVAL], 2'b0} : 32'hffffffff;
        end
    end
end

//ticlr
always @(posedge clk) begin
    if (reset) begin
        csr_ticlr <= 32'b0;
    end
end

//llbctl
always @(posedge clk) begin
    if (reset) begin
        csr_llbctl[`KLO]   <= 1'b0;
        csr_llbctl[31:3]   <= 29'b0;
		csr_llbctl[`WCLLB] <= 1'b0;
        llbit <= 1'b0;
    end 
    else if (ertn_flush) begin
        if (csr_llbctl[`KLO]) begin
            csr_llbctl[`KLO] <= 1'b0;
        end
        else begin
            llbit <= 1'b0;
        end
    end
    else if (llbctl_wen) begin 
        csr_llbctl[  `KLO] <= wr_data[  `KLO];
        if (wr_data[`WCLLB] == 1'b1) begin
            llbit <= 1'b0;
        end
    end
    else if (llbit_set_in) begin
        llbit <= llbit_in;
    end
end

//timer_64
always @(posedge clk) begin
    if (reset) begin
        timer_64 <= 64'b0;
    end
    else begin
        timer_64 <= timer_64 + 1'b1;
    end
end

//pgdl
always @(posedge clk) begin
    if (pgdl_wen) begin
        csr_pgdl[`BASE] <= wr_data[`BASE];
    end
end

//pgdh
always @(posedge clk) begin
    if (pgdh_wen) begin
        csr_pgdh[`BASE] <= wr_data[`BASE];
    end
end

//use for break in chipscope in software
always @(posedge clk) begin
    if (reset) begin
        csr_brk <= 32'b0;
    end
    if (BRK_wen) begin
        csr_brk <= wr_data;
    end
end

//use for disable cache or enable cache
always @(posedge clk) begin
    if (reset) begin
        csr_disable_cache <= 32'b0;
    end
    if (disable_cache_wen) begin
        csr_disable_cache <= wr_data;
    end
end

// difftest
assign csr_crmd_diff        = csr_crmd;
assign csr_prmd_diff        = csr_prmd;
assign csr_ectl_diff        = csr_ectl;
assign csr_estat_diff       = csr_estat;
assign csr_era_diff         = csr_era;
assign csr_badv_diff        = csr_badv;
assign csr_eentry_diff      = csr_eentry;
assign csr_tlbidx_diff      = csr_tlbidx;
assign csr_tlbehi_diff      = csr_tlbehi;
assign csr_tlbelo0_diff     = csr_tlbelo0;
assign csr_tlbelo1_diff     = csr_tlbelo1;
assign csr_asid_diff        = csr_asid;
assign csr_save0_diff       = csr_save0;
assign csr_save1_diff       = csr_save1;
assign csr_save2_diff       = csr_save2;
assign csr_save3_diff       = csr_save3;
assign csr_tid_diff         = csr_tid;
assign csr_tcfg_diff        = csr_tcfg;
assign csr_tval_diff        = csr_tval;
assign csr_ticlr_diff       = csr_ticlr;
assign csr_llbctl_diff      = {csr_llbctl[31:1], llbit};
assign csr_tlbrentry_diff   = csr_tlbrentry;
assign csr_dmw0_diff        = csr_dmw0;
assign csr_dmw1_diff        = csr_dmw1;
assign csr_pgdl_diff        = csr_pgdl;
assign csr_pgdh_diff        = csr_pgdh;

endmodule*/















class CSRs extends CoreModule{
    val io = IO(new Bundle{

        val reset = Input(Bool())
        // from to ds
        val rd_addr = Input(UInt(14.W))
        val rd_data = Output(UInt(32.W))

        // timer 64 
        val timer_64_out = Output(UInt(64.W))
        val tid_out = Output(UInt(32.W))

        // from ws
        val wr_addr = Input(UInt(14.W))
        val wr_data = Input(UInt(32.W))
        val csr_wr_en = Input(Bool())

        // interrupt
        val has_int = Output(Bool())
        val interrupt = Input(UInt(8.W))

        // from ws
        val excp_flush = Input(Bool())
        val era_in = Input(UInt(32.W))
        val esubcode_in = Input(UInt(9.W))
        val ecode_in = Input(UInt(6.W))
        val va_error_in = Input(Bool())
        val bad_va_in = Input(UInt(32.W))
        val tlbsrch_en = Input(Bool())
        val tlbsrch_found = Input(Bool())
        val tlbsrch_index = Input(UInt(5.W))
        val excp_tlbrefill = Input(Bool())
        val excp_tlb = Input(Bool())
        val excp_tlb_vppn = Input(UInt(19.W))

        // from ws llbit
        val llbit_set_in = Input(Bool())
        val llbit_in = Input(Bool())

        // to es
        val llbit_out = Output(Bool())
        val vppn_out = Output(UInt(19.W))

        // to fs
        val eentry_out = Output(UInt(32.W))
        val era_out = Output(UInt(32.W))
        val tlbrentry_out = Output(UInt(32.W))
        val disable_cache_out = Output(Bool())


        // to addr trans
        val asid_out = Output(UInt(10.W))
        val rand_index = Output(UInt(5.W))
        val tlbehi_out = Output(UInt(32.W))
        val tlbelo0_out = Output(UInt(32.W))
        val tlbelo1_out = Output(UInt(32.W))
        val tlbidx_out = Output(UInt(32.W))
        val pg_out = Output(Bool())
        val da_out = Output(Bool())
        val dmw0_out = Output(UInt(32.W))
        val dmw1_out = Output(UInt(32.W))
        val datf_out = Output(UInt(2.W))
        val datm_out = Output(UInt(2.W))
        val ecode_out = Output(UInt(6.W))

        //from addr trans
        val tlbrd_en = Input(Bool())
        val tlbehi_in = Input(UInt(32.W))
        val tlbelo0_in = Input(UInt(32.W))
        val tlbelo1_in = Input(UInt(32.W))
        val tlbidx_in = Input(UInt(32.W))
        val asid_in = Input(UInt(10.W))

        // general use
        val plv_out = Output(UInt(2.W))
        val csr_crmd_diff = Output(UInt(32.W))
        val csr_prmd_diff = Output(UInt(32.W))
        val csr_ectl_diff = Output(UInt(32.W))
        val csr_estat_diff = Output(UInt(32.W))
        val csr_era_diff = Output(UInt(32.W))
        val csr_badv_diff = Output(UInt(32.W))
        val csr_eentry_diff = Output(UInt(32.W))
        val csr_tlbidx_diff = Output(UInt(32.W))
        val csr_tlbehi_diff = Output(UInt(32.W))
        val csr_tlbelo0_diff = Output(UInt(32.W))
        val csr_tlbelo1_diff = Output(UInt(32.W))
        val csr_asid_diff = Output(UInt(32.W))
        val csr_save0_diff = Output(UInt(32.W))
        val csr_save1_diff = Output(UInt(32.W))
        val csr_save2_diff = Output(UInt(32.W))
        val csr_save3_diff = Output(UInt(32.W))
        val csr_tid_diff = Output(UInt(32.W))
        val csr_tcfg_diff = Output(UInt(32.W))
        val csr_tval_diff = Output(UInt(32.W))
        val csr_ticlr_diff = Output(UInt(32.W))
        val csr_llbctl_diff = Output(UInt(32.W))
        val csr_tlbrentry_diff = Output(UInt(32.W))
        val csr_dmw0_diff = Output(UInt(32.W))
        val csr_dmw1_diff = Output(UInt(32.W))
        val csr_pgdl_diff = Output(UInt(32.W))
        val csr_pgdh_diff = Output(UInt(32.W))


    })

    val TLBNUM = 32

    class CSR_crmd extends CoreBundle{
        val PLV = UInt(2.W)
        val IE = Bool()
        val DA = Bool()
        val PG = Bool()
        val DATF = UInt(2.W)
        val DATM = UInt(2.W)
        val RESERVE = UInt(23.W)
    } 

    class CSR_prmd extends CoreBundle{
        val PPLV = UInt(2.W)
        val PIE = Bool()
        val RESERVE = UInt(29.W)
    }

    class CSR_ectl extends CoreBundle{
        val LIE_1 = UInt(10.W)
        val LIE_2 = UInt(2.W)
        val RESERVE = UInt(20.W)
        def LIE = Cat(LIE_2, LIE_1)
    }

    class CSR_estat extends CoreBundle{
        val IS = UInt(13.W)
        val ECODE = UInt(6.W)
        val ESUBCODE = UInt(9.W)
        val RESERVE = UInt(1.W)
    }

    class CSR_era extends CoreBundle{
        val ERA = UInt(32.W)
    }

    class CSR_badv extends CoreBundle{
        val BADV = UInt(32.W)
    }

    class CSR_eentry extends CoreBundle{
        val EENTRY = UInt(32.W)
    }

    class CSR_tlbidx extends CoreBundle{
        val INDEX = UInt(5.W)
        val RESERVE = UInt(20.W)
        val PS = UInt(6.W)
        val NE = Bool()
    }

    class CSR_tlbehi extends CoreBundle{
        val VPPN = UInt(19.W)
        val RESERVE = UInt(13.W)
    }

    class CSR_tlbelo0 extends CoreBundle{
        val TLB_V = Bool()
        val TLB_D = Bool()
        val TLB_PLV = UInt(2.W)
        val TLB_MAT = UInt(2.W)
        val TLB_G = Bool()
        val TLB_PPN = UInt(24.W)
        def TLB_PPN_EN = TLB_PPN(19, 0)
    }

    class CSR_tlbelo1 extends CoreBundle{
        val TLB_V = Bool()
        val TLB_D = Bool()
        val TLB_PLV = UInt(2.W)
        val TLB_MAT = UInt(2.W)
        val TLB_G = Bool()
        val TLB_PPN = UInt(24.W)
        def TLB_PPN_EN = TLB_PPN(19, 0)
    }

    class CSR_cpuid{
        val RESERVE = UInt(23.W)
        val COREID = UInt(9.W)
    }

    class CSR_asid extends CoreBundle{
        val TLB_ASID = UInt(10.W)
        val RESERVE = UInt(22.W)
    }

    class CSR_save0 extends CoreBundle{
        val SAVE0 = UInt(32.W)
    }

    class CSR_save1 extends CoreBundle{
        val SAVE1 = UInt(32.W)
    }

    class CSR_save2 extends CoreBundle{
        val SAVE2 = UInt(32.W)
    }

    class CSR_save3 extends CoreBundle{
        val SAVE3 = UInt(32.W)
    }

    class CSR_tid extends CoreBundle{
        val TID = UInt(32.W)
    }

    class CSR_tcfg extends CoreBundle{
        val EN = Bool()
        val PERIODIC = Bool()
        val INITVAL = UInt(30.W)
    }

    class CSR_tval extends CoreBundle{
        val TVAL = UInt(32.W)
    }

    class CSR_cntc extends CoreBundle{
        val CNTC = UInt(32.W)
    }

    class CSR_ticlr extends CoreBundle{
        val CLR = Bool()
        val RESERVE = UInt(31.W)
    }

    class CSR_llbctl extends CoreBundle{
        val ROLLB = Bool()
        val WCLLB = Bool()
        val KLO = Bool()
        val RESERVE = UInt(29.W)
    }

    class CSR_tlbrentry extends CoreBundle{
        val RESERVE = UInt(6.W)
        val TLBRENTRY_PA = UInt(26.W)
    }

    class CSR_dmw0 extends CoreBundle{
        val PLV0 = UInt(1.W)
        val RESERVE1 = UInt(2.W)
        val PLV3 = UInt(1.W)
        val DMW_MAT = UInt(2.W)
        val RESERVE2 = UInt(19.W)
        val PSEG = UInt(3.W)
        val RESERVE3 = UInt(1.W)
        val VSEG = UInt(3.W)
    }

    class CSR_dmw1 extends CoreBundle{
        val PLV0 = UInt(1.W)
        val RESERVE1 = UInt(2.W)
        val PLV3 = UInt(1.W)
        val DMW_MAT = UInt(2.W)
        val RESERVE2 = UInt(19.W)
        val PSEG = UInt(3.W)
        val RESERVE3 = UInt(1.W)
        val VSEG = UInt(3.W)
    }

    class CSR_pgdl extends CoreBundle{
        val RESERVE = UInt(12.W)
        val BASE = UInt(20.W)
    }

    class CSR_pgdh extends CoreBundle{
        val RESERVE = UInt(12.W)
        val BASE = UInt(20.W)
    }

    
    class CSR_brk extends CoreBundle{
        val BRK = UInt(32.W)
    }

    class CSR_disable_cache extends CoreBundle{
        val RESERVE = UInt(31.W)
        val disable_cache_out = UInt(1.W)
    }
/*
define PLV       1:0
`define IE        2
`define DA        3
`define PG        4
`define DATF      6:5
`define DATM      8:7
//PRMD
`define PPLV      1:0
`define PIE       2
//ECTL
`define LIE       12:0
`define LIE_1     9:0
`define LIE_2     12:11
//ESTAT
`define IS        12:0
`define ECODE     21:16
`define ESUBCODE  30:22
//TLBIDX
`define INDEX     4:0
`define PS        29:24
`define NE        31
//TLBEHI
`define VPPN      31:13
//TLBELO
`define TLB_V      0
`define TLB_D      1
`define TLB_PLV    3:2
`define TLB_MAT    5:4
`define TLB_G      6
`define TLB_PPN    31:8
`define TLB_PPN_EN 27:8   //todo
//ASID
`define TLB_ASID  9:0
//CPUID
`define COREID    8:0
//LLBCTL
`define ROLLB     0
`define WCLLB     1
`define KLO       2
//TCFG
`define EN        0
`define PERIODIC  1
`define INITVAL   31:2
//TICLR
`define CLR       0
//TLBRENTRY
`define TLBRENTRY_PA 31:6
//DMW
`define PLV0      0
`define PLV3      3 
`define DMW_MAT   5:4
`define PSEG      27:25
`define VSEG      31:29
//PGDL PGDH PGD
`define BASE      31:12

`define ECODE_INT  6'h0
`define ECODE_PIL  6'h1
`define ECODE_PIS  6'h2
`define ECODE_PIF  6'h3
`define ECODE_PME  6'h4
`define ECODE_PPI  6'h7
`define ECODE_ADEF 6'h8
`define ECODE_ALE  6'h9
`define ECODE_SYS  6'hb
`define ECODE_BRK  6'hc
`define ECODE_INE  6'hd
`define ECODE_IPE  6'he
`define ECODE_FPD  6'hf
`define ECODE_TLBR 6'h3f

`define ESUBCODE_ADEF  9'h0

*/

/*
    wire crmd_wen   = csr_wr_en & (wr_addr == CRMD);
wire prmd_wen   = csr_wr_en & (wr_addr == PRMD);
wire ectl_wen   = csr_wr_en & (wr_addr == ECTL);
wire estat_wen  = csr_wr_en & (wr_addr == ESTAT);
wire era_wen    = csr_wr_en & (wr_addr == ERA);
wire badv_wen   = csr_wr_en & (wr_addr == BADV);
wire eentry_wen = csr_wr_en & (wr_addr == EENTRY);
wire tlbidx_wen = csr_wr_en & (wr_addr == TLBIDX);
wire tlbehi_wen = csr_wr_en & (wr_addr == TLBEHI);
wire tlbelo0_wen= csr_wr_en & (wr_addr == TLBELO0);
wire tlbelo1_wen= csr_wr_en & (wr_addr == TLBELO1);
wire asid_wen   = csr_wr_en & (wr_addr == ASID);
wire pgdl_wen   = csr_wr_en & (wr_addr == PGDL);
wire pgdh_wen   = csr_wr_en & (wr_addr == PGDH);
wire pgd_wen    = csr_wr_en & (wr_addr == PGD);
wire cpuid_wen  = csr_wr_en & (wr_addr == CPUID);
wire save0_wen  = csr_wr_en & (wr_addr == SAVE0);
wire save1_wen  = csr_wr_en & (wr_addr == SAVE1);
wire save2_wen  = csr_wr_en & (wr_addr == SAVE2);
wire save3_wen  = csr_wr_en & (wr_addr == SAVE3);
wire tid_wen    = csr_wr_en & (wr_addr == TID);
wire tcfg_wen   = csr_wr_en & (wr_addr == TCFG);
wire tval_wen   = csr_wr_en & (wr_addr == TVAL);
wire cntc_wen   = csr_wr_en & (wr_addr == CNTC);
wire ticlr_wen  = csr_wr_en & (wr_addr == TICLR);
wire llbctl_wen = csr_wr_en & (wr_addr == LLBCTL);
wire tlbrentry_wen = csr_wr_en & (wr_addr == TLBRENTRY);
wire DMW0_wen   = csr_wr_en & (wr_addr == DMW0);
wire DMW1_wen   = csr_wr_en & (wr_addr == DMW1);
wire BRK_wen    = csr_wr_en & (wr_addr == BRK);
wire disable_cache_wen = csr_wr_en & (wr_addr == DISABLE_CACHE);

reg [31:0] csr_crmd;
reg [31:0] csr_prmd;
reg [31:0] csr_ectl;
reg [31:0] csr_estat;
reg [31:0] csr_era;
reg [31:0] csr_badv;
reg [31:0] csr_eentry;
reg [31:0] csr_tlbidx;
reg [31:0] csr_tlbehi;
reg [31:0] csr_tlbelo0;
reg [31:0] csr_tlbelo1;
reg [31:0] csr_asid;
reg [31:0] csr_cpuid;
reg [31:0] csr_save0;
reg [31:0] csr_save1;
reg [31:0] csr_save2;
reg [31:0] csr_save3;
reg [31:0] csr_tid;
reg [31:0] csr_tcfg;
reg [31:0] csr_tval;
reg [31:0] csr_cntc;
reg [31:0] csr_ticlr;
reg [31:0] csr_llbctl;
reg [31:0] csr_tlbrentry;
reg [31:0] csr_dmw0;
reg [31:0] csr_dmw1;
reg [31:0] csr_pgdl;
reg [31:0] csr_pgdh;
reg [31:0] csr_brk;
reg [31:0] csr_disable_cache;

      
      */ 
val csr_crmd = new CSR_crmd
val csr_prmd = new CSR_prmd
val csr_ectl = new CSR_ectl
val csr_estat = new CSR_estat
val csr_era = new CSR_era
val csr_badv = new CSR_badv
val csr_eentry = new CSR_eentry
val csr_tlbidx = new CSR_tlbidx
val csr_tlbehi = new CSR_tlbehi
val csr_tlbelo0 = new CSR_tlbelo0
val csr_tlbelo1 = new CSR_tlbelo1
val csr_asid = new CSR_asid
val csr_cpuid = new CSR_cpuid
val csr_save0 = new CSR_save0
val csr_save1 = new CSR_save1
val csr_save2 = new CSR_save2
val csr_save3 = new CSR_save3
val csr_tid = new CSR_tid
val csr_tcfg = new CSR_tcfg
val csr_tval = new CSR_tval
val csr_cntc = new CSR_cntc
val csr_ticlr = new CSR_ticlr
val csr_llbctl = new CSR_llbctl
val csr_tlbrentry = new CSR_tlbrentry
val csr_dmw0 = new CSR_dmw0
val csr_dmw1 = new CSR_dmw1
val csr_pgdl = new CSR_pgdl
val csr_pgdh = new CSR_pgdh
val csr_brk = new CSR_brk
val csr_disable_cache = new CSR_disable_cache

val timer_en = RegInit(0.U(1.W))
val timer_64 = RegInit(0.U(64.W))

val llbit = RegInit(0.U(1.W))

val crmd_wen   = io.csr_wr_en & (io.wr_addr === CRMD.U)
val prmd_wen   = io.csr_wr_en & (io.wr_addr === PRMD.U)
val ectl_wen   = io.csr_wr_en & (io.wr_addr === ECTL.U)
val estat_wen  = io.csr_wr_en & (io.wr_addr === ESTAT.U)
val era_wen    = io.csr_wr_en & (io.wr_addr === ERA.U)
val badv_wen   = io.csr_wr_en & (io.wr_addr === BADV.U)
val eentry_wen = io.csr_wr_en & (io.wr_addr === EENTRY.U)
val tlbidx_wen = io.csr_wr_en & (io.wr_addr === TLBIDX.U)
val tlbehi_wen = io.csr_wr_en & (io.wr_addr === TLBEHI.U)
val tlbelo0_wen= io.csr_wr_en & (io.wr_addr === TLBELO0.U)
val tlbelo1_wen= io.csr_wr_en & (io.wr_addr === TLBELO1.U)
val asid_wen   = io.csr_wr_en & (io.wr_addr === ASID.U)
val pgdl_wen   = io.csr_wr_en & (io.wr_addr === PGDL.U)
val pgdh_wen   = io.csr_wr_en & (io.wr_addr === PGDH.U)
val pgd_wen    = io.csr_wr_en & (io.wr_addr === PGD.U)
val cpuid_wen  = io.csr_wr_en & (io.wr_addr === CPUID.U)
val save0_wen  = io.csr_wr_en & (io.wr_addr === SAVE0.U)
val save1_wen  = io.csr_wr_en & (io.wr_addr === SAVE1.U)
val save2_wen  = io.csr_wr_en & (io.wr_addr === SAVE2.U)
val save3_wen  = io.csr_wr_en & (io.wr_addr === SAVE3.U)
val tid_wen    = io.csr_wr_en & (io.wr_addr === TID.U)
val tcfg_wen   = io.csr_wr_en & (io.wr_addr === TCFG.U)
val tval_wen   = io.csr_wr_en & (io.wr_addr === TVAL.U)
val cntc_wen   = io.csr_wr_en & (io.wr_addr === CNTC.U)
val ticlr_wen  = io.csr_wr_en & (io.wr_addr === TICLR.U)
val llbctl_wen = io.csr_wr_en & (io.wr_addr === LLBCTL.U)
val tlbrentry_wen = io.csr_wr_en & (io.wr_addr === TLBRENTRY.U)
val DMW0_wen   = io.csr_wr_en & (io.wr_addr === DMW0.U)
val DMW1_wen   = io.csr_wr_en & (io.wr_addr === DMW1.U)
val BRK_wen    = io.csr_wr_en & (io.wr_addr === BRK.U)
val disable_cache_wen = io.csr_wr_en & (io.wr_addr === DISABLE_CACHE.U)
/*

wire eret_tlbrefill_excp;

wire no_forward;

assign csr_pgd = csr_badv[31] ? csr_pgdh : csr_pgdl;

assign eret_tlbrefill_excp = csr_estat[`ECODE] == 6'h3f;

assign tlbrd_valid_wr_en   = tlbrd_en && !tlbidx_in[`NE];
assign tlbrd_invalid_wr_en = tlbrd_en &&  tlbidx_in[`NE];

assign has_int = ((csr_ectl[`LIE] & csr_estat[`IS]) != 13'b0) & csr_crmd[`IE];

assign eentry_out   = csr_eentry;
assign era_out      = csr_era;
assign timer_64_out = timer_64 + {{32{csr_cntc[31]}}, csr_cntc};
assign tid_out      = csr_tid;
assign llbit_out    = llbit;
assign asid_out     = csr_asid[`TLB_ASID];
assign vppn_out     = (csr_wr_en && wr_addr == TLBEHI) ? wr_data[`VPPN] : csr_tlbehi[`VPPN];
assign tlbehi_out   = csr_tlbehi;
assign tlbelo0_out  = csr_tlbelo0;
assign tlbelo1_out  = csr_tlbelo1;
assign tlbidx_out   = csr_tlbidx;
assign rand_index   = timer_64[4:0];
assign disable_cache_out = csr_disable_cache[0];

//forward to if stage
assign no_forward   = !excp_tlbrefill && !(eret_tlbrefill_excp && ertn_flush) && !crmd_wen;

assign pg_out       = excp_tlbrefill & 1'b0                      |
                      (eret_tlbrefill_excp && ertn_flush) & 1'b1 |
                      crmd_wen       & wr_data[`PG]              |
                      no_forward     & csr_crmd[`PG];

assign da_out       = excp_tlbrefill & 1'b1                      |
                      (eret_tlbrefill_excp && ertn_flush) & 1'b0 |
                      crmd_wen       & wr_data[`DA]              |
                      no_forward     & csr_crmd[`DA];

assign dmw0_out     = DMW0_wen ? wr_data : csr_dmw0;
assign dmw1_out     = DMW1_wen ? wr_data : csr_dmw1;

assign plv_out      = {2{excp_flush}} & 2'b0            |
                      {2{ertn_flush}} & csr_prmd[`PPLV] |
                      {2{crmd_wen  }} & wr_data[`PLV]   |
                      {2{!excp_flush && !ertn_flush && !crmd_wen}} & csr_crmd[`PLV];

assign tlbrentry_out= csr_tlbrentry;
assign datf_out     = csr_crmd[`DATF];
assign datm_out     = csr_crmd[`DATM];

assign ecode_out    = csr_estat[`ECODE];

assign rd_data = {32{rd_addr == CRMD  }}  & csr_crmd    |
                 {32{rd_addr == PRMD  }}  & csr_prmd    |
                 {32{rd_addr == ECTL  }}  & csr_ectl    |
                 {32{rd_addr == ESTAT }}  & csr_estat   |
                 {32{rd_addr == ERA   }}  & csr_era	    |
                 {32{rd_addr == BADV  }}  & csr_badv    |
                 {32{rd_addr == EENTRY}}  & csr_eentry  |
                 {32{rd_addr == TLBIDX}}  & csr_tlbidx  |
                 {32{rd_addr == TLBEHI}}  & csr_tlbehi  |
                 {32{rd_addr == TLBELO0}} & csr_tlbelo0 |
                 {32{rd_addr == TLBELO1}} & csr_tlbelo1 |
                 {32{rd_addr == ASID  }}  & csr_asid    |
                 {32{rd_addr == PGDL  }}  & csr_pgdl    |
                 {32{rd_addr == PGDH  }}  & csr_pgdh    |
                 {32{rd_addr == PGD   }}  & csr_pgd     |
                 {32{rd_addr == CPUID }}  & csr_cpuid   |
                 {32{rd_addr == SAVE0 }}  & csr_save0   |
                 {32{rd_addr == SAVE1 }}  & csr_save1   |
                 {32{rd_addr == SAVE2 }}  & csr_save2   |
                 {32{rd_addr == SAVE3 }}  & csr_save3   |
                 {32{rd_addr == TID   }}  & csr_tid     |
                 {32{rd_addr == TCFG  }}  & csr_tcfg    |
                 {32{rd_addr == CNTC  }}  & csr_cntc    |
                 {32{rd_addr == TICLR }}  & csr_ticlr   |
                 {32{rd_addr == LLBCTL}}  & {csr_llbctl[31:1], llbit} |
                 {32{rd_addr == TVAL  }}  & csr_tval    |
                 {32{rd_addr == TLBRENTRY}} & csr_tlbrentry   |
                 {32{rd_addr == DMW0}}    & csr_dmw0    |
                 {32{rd_addr == DMW1}}    & csr_dmw1    ;

*/ 

val tlbrd_valid_wr_en   = WireInit(false.B)
val tlbrd_invalid_wr_en = WireInit(false.B)
val eret_tlbrefill_excp = WireInit(false.B)

val csr_pgd = WireInit(0.U(32.W))

csr_pgd := Mux(csr_badv.asUInt(31) === 1.U, csr_pgdh, csr_pgdl)

eret_tlbrefill_excp := csr_estat.ECODE === 0x3f.U

tlbrd_valid_wr_en   := io.tlbrd_en && !(io.tlbidx_in)(31)
tlbrd_invalid_wr_en := io.tlbrd_en &&  (io.tlbidx_in)(31)
//TODO :: 以下
//has_int := csr_ectl.LIE & csr_estat.IS =/= 0.U & csr_crmd.IE
//
//io.eentry_out   := csr_eentry
//io.era_out      := csr_era
//io.timer_64_out := timer_64 + Cat(Fill(32,csr_cntc(31)), csr_cntc)
//io.tid_out      := csr_tid
//io.llbit_out    := llbit
//io.asid_out     := getTLB_ASID(csr_asid)
//io.vppn_out     := Mux(io.csr_wr_en && io.wr_addr === TLBEHI, getVPPN(wr_data), getVPPN(csr_tlbehi))
//io.tlbehi_out   := csr_tlbehi
//io.tlbelo0_out  := csr_tlbelo0
//io.tlbelo1_out  := csr_tlbelo1
//io.tlbidx_out   := csr_tlbidx
//io.rand_index   := timer_64(4,0)
//io.disable_cache_out := csr_disable_cache(0)
//
////forward to if stage
//val no_forward   = WireInit(false.B)
//
//no_forward := !io.excp_tlbrefill && !(eret_tlbrefill_excp && io.ertn_flush) && !crmd_wen
//
//io.pg_out       := io.excp_tlbrefill & 0.U                      |
//                    (eret_tlbrefill_excp && io.ertn_flush) & 1.U |
//                    crmd_wen       & getPG(io.wr_data)              |
//                    no_forward     & getPG(csr_crmd)
//
//io.da_out       := io.excp_tlbrefill & 1.U                      |
//                    (eret_tlbrefill_excp && io.ertn_flush) & 0.U |
//                    crmd_wen       & getDA(io.wr_data)              |
//                    no_forward     & getDA(csr_crmd)
//
//io.dmw0_out     := Mux(DMW0_wen, io.wr_data, csr_dmw0)
//io.dmw1_out     := Mux(DMW1_wen, io.wr_data, csr_dmw1)
//
//io.plv_out      := Cat(Fill(2,io.excp_flush) & 0.U)            |
//                    Cat(Fill(2,io.ertn_flush)&getPLV(csr_prmd)) |
//                    Cat(Fill(2,crmd_wen  ) & getPLV(io.wr_data))   |
//                    Cat(Fill(2,!io.excp_flush && !io.ertn_flush && !crmd_wen), getPLV(csr_crmd))
//
//io.tlbrentry_out:= csr_tlbrentry
//io.datf_out     := getDATF(csr_crmd)
//io.datm_out     := getDATM(csr_crmd)
//io.ecode_out    := getECODE(csr_estat)
//
//io.rd_data := MuxLookup(io.rd_addr, 0.U(32.W),
//                        Array(
//                            CRMD -> csr_crmd,
//                            PRMD -> csr_prmd,
//                            ECTL -> csr_ectl,
//                            ESTAT -> csr_estat,
//                            ERA -> csr_era,
//                            BADV -> csr_badv,
//                            EENTRY -> csr_eentry,
//                            TLBIDX -> csr_tlbidx,
//                            TLBEHI -> csr_tlbehi,
//                            TLBELO0 -> csr_tlbelo0,
//                            TLBELO1 -> csr_tlbelo1,
//                            ASID -> csr_asid,
//                            PGDL -> csr_pgdl,
//                            PGDH -> csr_pgdh,
//                            PGD -> csr_pgd,
//                            CPUID -> csr_cpuid,
//                            SAVE0 -> csr_save0,
//                            SAVE1 -> csr_save1,
//                            SAVE2 -> csr_save2,
//                            SAVE3 -> csr_save3,
//                            TID -> csr_tid,
//                            TCFG -> csr_tcfg,
//                            CNTC -> csr_cntc,
//                            TICLR -> csr_ticlr,
//                            LLBCTL -> Cat(csr_llbctl(31,1), llbit),
//                            TVAL -> csr_tval,
//                            TLBRENTRY -> csr_tlbrentry,
//                            DMW0 -> csr_dmw0,
//                            DMW1 -> csr_dmw1
//            ))
//
//    if(io.reset){
//    }










}