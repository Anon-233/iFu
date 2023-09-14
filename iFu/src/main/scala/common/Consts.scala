package iFu.common

import chisel3._
import chisel3.util._

object CauseCode{
    val ecodeBits = 6
    val subcodeBits = 9

    val causeCodeBits = ecodeBits + subcodeBits

    //中断：接收到外部硬件中断，核间中断，内部软中断，定时器中断
    def INT  =  Cat(0x0.U(ecodeBits.W), 0x0.U(subcodeBits.W))

    //Load操作页无效：load指令访问的页表项无效
    def PIL  =  Cat(0x1.U(ecodeBits.W), 0x0.U(subcodeBits.W))

    //store操作页无效:store指令访问的页表项无效
    def PIS  = Cat(0x2.U(ecodeBits.W), 0x0.U(subcodeBits.W))

    //取指操作页无效:取指操作访问的页表项无效
    def PIF  = Cat(0x3.U(ecodeBits.W),0x0.U(subcodeBits.W))

    //页修改:store指令访问一个可写位和脏位不全为1的有效页表项
    def PME  = Cat(0x4.U(ecodeBits.W), 0x0.U(subcodeBits.W))

    //页特权等级不合规 :访问的有效页表项的PLV等级权限高于CPU当前的PLV等级
    def PPI  =  Cat(0x7.U(ecodeBits.W), 0x0.U(subcodeBits.W))

    //取指地址错 :取指PC不对齐；映射地址模式下，CPU当前处于PLV3，PC第31位为1且不落在任何有效的直接映射窗口中
    def ADEF = Cat(0x8.U(ecodeBits.W), 0x0.U(subcodeBits.W))

    //访存指令地址错:映射地址模式下，CPU当前处于PLV3，访存指令虚地址的第31位为1,且不落在任何有效的直接映射窗口中
    def ADEM =  Cat(0x8.U(ecodeBits.W), 0x1.U(subcodeBits.W))

    //地址非对齐 : 非字节访存指令的地址不是自然对齐的
    def ALE  =  Cat(0x9.U(ecodeBits.W), 0x0.U(subcodeBits.W))

    //系统调用  : 执行syscall指令
    def SYS  =  Cat(0xb.U(ecodeBits.W), 0x0.U(subcodeBits.W))

    //断点 :执行break指令
    def BRK  =  Cat(0xc.U(ecodeBits.W), 0x0.U(subcodeBits.W))

    //指令不存在 : 当前指令是一条未定义（/未实现）指令
    def INE  =  Cat(0xd.U(ecodeBits.W), 0x0.U(subcodeBits.W))

    // 指令特权等级错 :CPU当前处于PLV3，执行特权指令
    def IPE  =  Cat(0xe.U(ecodeBits.W), 0x0.U(subcodeBits.W))

    //浮点指令未使能 :CPU实现了浮点指令前提下，当CSR.EUEN.FPE=0时执行浮点指令
    def FPD  =  Cat(0xf.U(ecodeBits.W), 0x0.U(subcodeBits.W))

    //基础浮点运算异常:浮点运算过程中满足IEEE754规范中触发浮点运算异常的情况
    def FPE  =  Cat(0x12.U(ecodeBits.W), 0x0.U(subcodeBits.W))

    //TLB重填 : 映射地址模式下，访存地址不落在任何有效的直接映射窗口中，且在TLB中找不到对应的TLB表项
    def TLBR =  Cat(0x3f.U(ecodeBits.W), 0x0.U(subcodeBits.W))

    def MINI_EXCEPTION_MEM_ORDERING = Cat(0x13.U(ecodeBits.W),0x0.U(subcodeBits.W))

}

object Consts {
    val X = BitPat("b?")
    val Y = BitPat("b1")
    val N = BitPat("b0")

    val CSR_SZ = 2
    val CSR_N  = 0.U(CSR_SZ.W)
    val CSR_R  = 1.U(CSR_SZ.W)
    val CSR_W  = 2.U(CSR_SZ.W)
    val CSR_M  = 3.U(CSR_SZ.W)

    val BSRC_SZ = 2
    val BSRC_1  = 0.U(BSRC_SZ.W) // 1-cycle branch pred
    val BSRC_2  = 1.U(BSRC_SZ.W) // 2-cycle branch pred
    val BSRC_3  = 2.U(BSRC_SZ.W) // 3-cycle branch pred
    val BSRC_C  = 3.U(BSRC_SZ.W) // core branch resolution

    val CFI_SZ   = 2
    val CFI_X    = 0.U(CFI_SZ.W) // Not a CFI instruction
    val CFI_BR   = 1.U(CFI_SZ.W) // Branch
    val CFI_JAL  = 2.U(CFI_SZ.W) // JAL
    val CFI_JALR = 3.U(CFI_SZ.W) // JALR

    val IQT_SZ  = 2
    val IQT_X   = BitPat.dontCare(IQT_SZ)
    val IQT_INT = 1.U(IQT_SZ.W)
    val IQT_MEM = 2.U(IQT_SZ.W)

    val FUC_SZ = 8 // TODO
    val FU_X = BitPat.dontCare(FUC_SZ)
    val FU_ALU = 1.U(FUC_SZ.W)
    val FU_JMP = 2.U(FUC_SZ.W)
    val FU_MEM = 4.U(FUC_SZ.W)
    val FU_MUL = 8.U(FUC_SZ.W)
    val FU_DIV = 16.U(FUC_SZ.W)
    val FU_CSR = 32.U(FUC_SZ.W)
    val FN_CNT = 64.U(FUC_SZ.W)
    // val FN_TLB = 128.U(FUC_SZ.W)

    val RT_X   = 0.U(1.W)
    val RT_FIX = 1.U(1.W)

    val immSz  = 4
    val immX   = BitPat("b????")
    val immU5  = 0.U(immSz.W)  // Cat(Fill(27,0.U),inst(14,10))
    val immU12 = 1.U(immSz.W) // Cat(Fill(20,0.U),inst(21,10))
    val immS12 = 2.U(immSz.W) //Cat(Fill(20,inst(21)),inst(21,10))
    val immS14 = 3.U(immSz.W) // Cat(Fill(16,inst(23)),inst(23,10),Fill(2,0.U))
    val immS16 = 4.U(immSz.W) // Cat(Fill(14,inst(25)),inst(25,10),Fill(2,0.U))
    val immU20 = 5.U(immSz.W) //Cat(inst(24,5),Fill(12,0.U))
    val immS20 = 6.U(immSz.W) //Cat(Fill(10,inst(24)),inst(24,5),Fill(2,0.U))
    val immS26 = 7.U(immSz.W) // Cat(Fill(4,inst(9)),inst(9,0),inst(25,10),Fill(2,0.U))
    val immCSR = 8.U(immSz.W)

    val BR_N   = 0.U(4.W) // Next
    val BR_NE  = 1.U(4.W) // Branch on NotEqual
    val BR_EQ  = 2.U(4.W) // Branch on Equal
    val BR_GE  = 3.U(4.W) // Branch on Greater/Equal
    val BR_GEU = 4.U(4.W) // Branch on Greater/Equal Unsigned
    val BR_LT  = 5.U(4.W) // Branch on Less Than
    val BR_LTU = 6.U(4.W) // Branch on Less Than Unsigned
    val BR_J   = 7.U(4.W) // Jump
    val BR_JR  = 8.U(4.W) // Jump Register

    val PC_PLUS4 = 0.U(2.W)
    val PC_BRJMP = 1.U(2.W)
    val PC_JALR  = 2.U(2.W)

    val OP1_X    = BitPat("b??")
    val OP1_RS1  = 0.U(2.W) // Register Source #1
    val OP1_ZERO = 1.U(2.W)
    val OP1_PC   = 2.U(2.W)

    val OP2_X    = BitPat("b???")
    val OP2_RS2  = 0.U(3.W) // Register Source #2
    val OP2_IMM  = 1.U(3.W) // immediate
    val OP2_ZERO = 2.U(3.W) // constant 0
    val OP2_NEXT = 3.U(3.W) // constant 4 (for PC + 4)

    val REN_0 = false.B
    val REN_1 = true.B

    val MEN_X = false.B
    val MEN_0 = false.B
    val MEN_1 = true.B


    val AXI_BURST_FIXED    = 0.U(2.W)
    val AXI_BURST_INCR     = 1.U(2.W)
    val AXI_BURST_WRAP     = 2.U(2.W)
    val AXI_BURST_RESERVED = 3.U(2.W)

    val MLEN1   = 0x0.U(8.W)
    val MLEN2   = 0x1.U(8.W)
    val MLEN4   = 0x3.U(8.W)
    val MLEN8   = 0x7.U(8.W)
    val MLEN16  = 0xf.U(8.W)  // 最大是16拍???
    val MLEN32  = 0x1f.U(8.W)
    val MLEN64  = 0x3f.U(8.W)
    val MLEN128 = 0x7f.U(8.W)
    val MLEN256 = 0xff.U(8.W)

    // bytes per beat
    val MSIZE1   = 0.U(3.W)
    val MSIZE2   = 1.U(3.W)
    val MSIZE4   = 2.U(3.W) // 最大是一拍4个bytes（32位)??????
    val MSIZE8   = 3.U(3.W)
    val MSIZE16  = 4.U(3.W)
    val MSIZE32  = 5.U(3.W)
    val MSIZE64  = 6.U(3.W)
    val MSIZE128 = 7.U(3.W)

    val BUBBLE = 0.U(32.W)

    val UOPC_SZ = 7
    val uopX = BitPat.dontCare(UOPC_SZ)

    val uopNOP = 0.U(UOPC_SZ.W)
    val uopADD = 1.U(UOPC_SZ.W)
    val uopSUB = 2.U(UOPC_SZ.W)
    val uopSLT = 3.U(UOPC_SZ.W)
    val uopSLTU = 4.U(UOPC_SZ.W)
    val uopNOR = 5.U(UOPC_SZ.W)
    val uopAND = 6.U(UOPC_SZ.W)
    val uopOR = 7.U(UOPC_SZ.W)
    val uopXOR = 8.U(UOPC_SZ.W)
    val uopLU12IW = 9.U(UOPC_SZ.W)
    val uopADDIW = 10.U(UOPC_SZ.W)
    val uopSLTI = 11.U(UOPC_SZ.W)
    val uopSLTUI = 12.U(UOPC_SZ.W)
    val uopPCADDI = 13.U(UOPC_SZ.W)
    val uopPCADDU12I = 14.U(UOPC_SZ.W)
    val uopANDN = 15.U(UOPC_SZ.W) // TODO: should alu do this?
    val uopORN = 16.U(UOPC_SZ.W) // TODO: should alu do this?
    val uopANDI = 17.U(UOPC_SZ.W)
    val uopORI = 18.U(UOPC_SZ.W)
    val uopXORI = 19.U(UOPC_SZ.W)
    val uopMULW = 20.U(UOPC_SZ.W)
    val uopMULHW = 21.U(UOPC_SZ.W)
    val uopMULHWU = 22.U(UOPC_SZ.W)
    val uopDIVW = 23.U(UOPC_SZ.W)
    val uopMODW = 24.U(UOPC_SZ.W)
    val uopDIVWU = 25.U(UOPC_SZ.W)
    val uopMODWU = 26.U(UOPC_SZ.W)
    val uopSLLIW = 27.U(UOPC_SZ.W)
    val uopSRLIW = 28.U(UOPC_SZ.W)
    val uopSRAIW = 29.U(UOPC_SZ.W)
    val uopSLLW = 30.U(UOPC_SZ.W)
    val uopSRLW = 31.U(UOPC_SZ.W)
    val uopSRAW = 32.U(UOPC_SZ.W)

    val uopJIRL = 33.U(UOPC_SZ.W)
    val uopJAL = 34.U(UOPC_SZ.W)
    // val uopBL           = 35.U(UOPC_SZ.W)
    val uopSYSC = 35.U(UOPC_SZ.W)
    val uopBEQ = 36.U(UOPC_SZ.W)
    val uopBNE = 37.U(UOPC_SZ.W)
    val uopBLT = 38.U(UOPC_SZ.W)
    val uopBGE = 39.U(UOPC_SZ.W)
    val uopBLTU = 40.U(UOPC_SZ.W)
    val uopBGEU = 41.U(UOPC_SZ.W)

    val uopERET = 42.U(UOPC_SZ.W)

    val uopCSRRD = 43.U(UOPC_SZ.W)
    val uopCSRWR = 44.U(UOPC_SZ.W)
    val uopCSRXCHG = 45.U(UOPC_SZ.W)

    val uopIDLE = 46.U(UOPC_SZ.W)

    val uopTLBSRCH = 47.U(UOPC_SZ.W)
    val uopTLBRD = 48.U(UOPC_SZ.W)
    val uopTLBWR = 49.U(UOPC_SZ.W)
    val uopTLBFILL = 50.U(UOPC_SZ.W)
    val uopINVTLB = 51.U(UOPC_SZ.W)

    val uopCACOP = 52.U(UOPC_SZ.W)
    val uopPRELD = 53.U(UOPC_SZ.W)
    val uopDBAR = 54.U(UOPC_SZ.W)

    val uopLD = 55.U(UOPC_SZ.W)
    val uopSTA = 56.U(UOPC_SZ.W)
    val uopSTD = 57.U(UOPC_SZ.W)

    val uopLLW = 58.U(UOPC_SZ.W)
    val uopAMO_AG = 59.U(UOPC_SZ.W)

    val uopRDCNTIDW = 60.U(UOPC_SZ.W)
    val uopRDCNTVLW = 61.U(UOPC_SZ.W)
    val uopRDCNTVHW = 62.U(UOPC_SZ.W)

    val uopMOV = 63.U(UOPC_SZ.W)
    val uopBREA = 64.U(UOPC_SZ.W)
    def NullMicroOp: MicroOp = {
        val uop = Wire(new MicroOp)
        uop := DontCare // Overridden in the following lines
        uop.uopc := uopNOP // maybe not required, but helps on asserts that try to catch spurious behavior
        uop.bypassable := false.B
        uop.use_stq := false.B
        uop.use_ldq := false.B
        uop.pdst := 0.U
        uop.dst_rtype := RT_X

        val cs = Wire(new CtrlSignals())
        cs := DontCare // Overridden in the following lines
        cs.br_type := BR_N
        /*cs.csr_cmd := freechips.rocketchip.rocket.CSR.N*/
        cs.is_load := false.B
        cs.is_sta := false.B
        cs.is_std := false.B

        uop.ctrl := cs
        uop
    }

    val TLB_INDEX_LENGTH: Int = 5
    val TLBIDX_r: Int = 16 - TLB_INDEX_LENGTH
    val TLBIDX_INDEX:Int = TLB_INDEX_LENGTH

    val PALEN: Int = 32
    val TLBELO_r: Int = 36-PALEN
    val TLBELO_ppn: Int = PALEN-12

    val TIMER_LENGTH: Int = 32
    val TCFG_initval: Int = TIMER_LENGTH-2

    val CSR_CRMD = 0.U(14.W)
    val CSR_PRMD = 1.U(14.W)
    val CSR_EUEN = 2.U(14.W)
    val CSR_ECFG = 4.U(14.W)
    val CSR_ESTAT = 5.U(14.W)
    val CSR_ERA = 6.U(14.W)
    val CSR_BADV = 7.U(14.W)
    val CSR_EENTRY = 12.U(14.W)
    val CSR_TLBIDX = 16.U(14.W)
    val CSR_TLBEHI = 17.U(14.W)
    val CSR_TLBELO0 = 18.U(14.W)
    val CSR_TLBELO1 = 19.U(14.W)
    val CSR_ASID = 24.U(14.W)
    val CSR_PGDL = 25.U(14.W)
    val CSR_PGDH = 26.U(14.W)
    val CSR_PGD = 27.U(14.W)
    val CSR_CPUID = 32.U(14.W)
    val CSR_SAVE0 = 48.U(14.W)
    val CSR_SAVE1 = 49.U(14.W)
    val CSR_SAVE2 = 50.U(14.W)
    val CSR_SAVE3 = 51.U(14.W)
    val CSR_TID = 64.U(14.W)
    val CSR_TCFG = 65.U(14.W)
    val CSR_TVAL = 66.U(14.W)
    val CSR_TICLR = 68.U(14.W)
    val CSR_LLBCTL = 96.U(14.W)
    val CSR_TLBRENTRY = 136.U(14.W)
    val CSR_CTAG = 152.U(14.W)
    val CSR_DMW0 = 384.U(14.W)
    val CSR_DMW1 = 385.U(14.W)
}

object FlushTypes {
    def SZ =3
    def apply() = UInt(SZ.W)
    def none = 0.U
    def xcpt = 1.U
    def eret = (2+1).U
    def refetch = 2.U
    def next = 4.U

    def useCsrEvec(typ: UInt): Bool = typ === eret || typ === xcpt
    def useSamePC(typ: UInt): Bool  = typ === refetch
    def usePCplus4(typ: UInt): Bool = typ === next

    def getType(valid: Bool, i_xcpt: Bool, i_eret: Bool, i_refetch: Bool): UInt = {
        val ret = Mux(!valid, none,
                  Mux(i_eret, eret,
                  Mux(i_xcpt, xcpt,
                  Mux(i_refetch,refetch,
                  next))))
        ret
    }
}