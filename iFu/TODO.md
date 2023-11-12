#<center>iFuCore待做</center>


由于谭大爷的difftest框架只改版到csr之前的测试，因此必须要进行一波转型，选择龙芯的chiplab，以下大概是从接入框架到开发板跑linux内核
的所有待做事项

# 1. 接入新的框架chiplab，其中待接的信号 
以下是可能需要从iFuCore里面接出来的信号，需要手动创个wire从对应的module一直传到iFucore的Output出来（或者塞到uop里面随着uop传出来？）

```verilog
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
```

```verilog

```

在这个框架下调试的编译和maketest两个阶段都已经写好了新的makefile，指令压缩也已经完成，因此，只要拉出来以上信号之后，就可以正常的在chiplab框架下面进行调试了

需要去调试完成的包括以下几个方面：

# 2. 待完善调试的module（2个）
    1. CSR
    2. TLB

# 3. 待完成调试的指令
    1. csr的一些异常指令
    2. tlb指令
    3. 读取timer64计数器指令
    4. 原子访存指令（lr/sc）
    5. 栅障指令（ibar，dbar）


完成这些任务之后，肯定就可以通过初赛测试的上板了。


再之后，看情况补一下操作系统有关的指令（如果完成好了上面的指令，操作系统也自然而然地启动了（希望如此）），然后就可以悠闲地炼丹+linux内核配环境了......