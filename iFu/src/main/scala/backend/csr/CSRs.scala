package iFu.backend

import chisel3._
import chisel3.util._

object CSRs {
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
    //中断：接收到外部硬件中断，核间中断，内部软中断，定时器中断
    val INT  =  Cat(0x0.U(6.W),0x0.U(9.W))

    //Load操作页无效：load指令访问的页表项无效
    val PIL  =  Cat(0x1.U(6.W),0x0.U(9.W))

    //store操作页无效:store指令访问的页表项无效
    val PIS  =  Cat(0x2.U(6.W),0x0.U(9.W))

    //取指操作页无效:取指操作访问的页表项无效
    val PIF  =  Cat(0x3.U(6.W),0x0.U(9.W))

    //页修改:store指令访问一个可写位和脏位不全为1的有效页表项
    val PME  =  Cat(0x4.U(6.W),0x0.U(9.W))

    //页特权等级不合规 :访问的有效页表项的PLV等级权限高于CPU当前的PLV等级
    val PPI  =  Cat(0x7.U(6.W),0x0.U(9.W))

    //取指地址错 :取指PC不对齐；映射地址模式下，CPU当前处于PLV3，PC第31位为1且不落在任何有效的直接映射窗口中
    val ADEF =  Cat(0x8.U(6.W),0x0.U(9.W))

    //访存指令地址错:映射地址模式下，CPU当前处于PLV3，访存指令虚地址的第31位为1,且不落在任何有效的直接映射窗口中
    val ADEM =  Cat(0x8.U(6.W),0x1.U(9.W))

    //地址非对齐 : 非字节访存指令的地址不是自然对齐的
    val ALE  =  Cat(0x9.U(6.W),0x0.U(9.W))

    //系统调用  : 执行syscall指令
    val SYS  =  Cat(0xb.U(6.W),0x0.U(9.W))

    //断点 :执行break指令
    val BRK  =  Cat(0xc.U(6.W),0x0.U(9.W))

    //指令不存在 : 当前指令是一条未定义（/未实现）指令
    val INE  =  Cat(0xd.U(6.W),0x0.U(9.W))

    // 指令特权等级错 :CPU当前处于PLV3，执行特权指令
    val IPE  =  Cat(0xe.U(6.W),0x0.U(9.W))

    //浮点指令未使能 :CPU实现了浮点指令前提下，当CSR.EUEN.FPE=0时执行浮点指令
    val FPD  =  Cat(0xf.U(6.W),0x0.U(9.W))

    //基础浮点运算异常:浮点运算过程中满足IEEE754规范中触发浮点运算异常的情况
    val FPE  =  Cat(0x12.U(6.W),0x0.U(9.W))

    //TLB重填 : 映射地址模式下，访存地址不落在任何有效的直接映射窗口中，且在TLB中找不到对应的TLB表项
    val TLBR =  Cat(0x3f.U(6.W),0x0.U(9.W))

}