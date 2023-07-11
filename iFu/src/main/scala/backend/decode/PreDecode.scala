package iFu.backend

import iFu.common.{CoreBundle, CoreModule}
import chisel3._
import chisel3.util._
import frontend.isa.Instructions._
//TODO 合并常量

trait PreDecodeConsts {
    val CFI_SZ = 3
    val CFI_X = 0.U(CFI_SZ.W) // Not a CFI instruction
    val CFI_BR = 1.U(CFI_SZ.W) // Branch
    val CFI_JAL = 2.U(CFI_SZ.W) // JAL
    val CFI_JALR = 3.U(CFI_SZ.W) // JALR
    val blockBytes = 256
    val X = BitPat("b?")
    val Y = BitPat("b1")
    val N = BitPat("b0")
    val default = List[BitPat](N,N,N,N,X)
    val table:Array[(BitPat,List[BitPat])] = Array[(BitPat,List[BitPat])](
        ////                               is br?
        ////                               |  is jal?
        ////                               |  |  is jalr?
        ////                               |  |  |
        ////                               |  |  |  shadowable
        ////                               |  |  |  |  has_rs2
        ////                               |  |  |  |  |
        JIRL                        ->List(N, N, Y, N, X),
        B                           ->List(N, Y, N, N, X),
        BL                          ->List(N, N, Y, N, X),
        BEQ                         ->List(Y, N, N, N, X),
        BNE                         ->List(Y, N, N, N, X),
        BLT                         ->List(Y, N, N, N, X),
        BLTU                        ->List(Y, N, N, N, X),
        BGE                         ->List(Y, N, N, N, X),
        BGEU                        ->List(Y, N, N, N, X),


        ADDW                        ->List(N, N, N, Y, Y),
        SUBW                        ->List(N, N, N, Y, Y),
        ADDIW                       ->List(N, N, N, Y, N),
        LU12IW                      ->List(N, N, N, Y, N),
        SLT                         ->List(N, N, N, Y, Y),
        SLTU                        ->List(N, N, N, Y, Y),
        SLTI                        ->List(N, N, N, Y, N),
        SLTUI                       ->List(N, N, N, Y, N),

//        PCADDI                      ->List(N, N, N, Y, N),
//        PCADDU12I                   ->List(N, N, N, Y, N),

        AND                         ->List(N, N, N, Y, Y),
        OR                          ->List(N, N, N, Y, Y),
        XOR                         ->List(N, N, N, Y, Y),
        NOR                         ->List(N, N, N, Y, Y),

        ANDI                        ->List(N, N, N, Y, N),
        ORI                         ->List(N, N, N, Y, N),
        XORI                        ->List(N, N, N, Y, N),

        ANDN                        ->List(N, N, N, Y, Y),
        ORN                         ->List(N, N, N, Y, Y),

        SLLW                        ->List(N, N, N, Y, Y),
        SRLW                        ->List(N, N, N, Y, Y),
        SRAW                        ->List(N, N, N, Y, Y),
        SLLIW                       ->List(N, N, N, Y, N),
        SRLIW                       ->List(N, N, N, Y, N),
        SRAIW                       ->List(N, N, N, Y, N)


    )
}

class PreDecodeSignals extends CoreBundle with PreDecodeConsts{
    val isRet       = Bool()
    val isCall      = Bool()
    val target      = UInt(vaddrBits.W)
    val cfiType     = UInt(CFI_SZ.W)
    val sfbOffset   = Valid(UInt(log2Ceil(blockBytes).W))
    val shadowable  = Bool()
}
class PreDecode extends CoreModule with PreDecodeConsts {
    val io = IO(new Bundle{
        val inst    = Input(UInt(32.W))
        val pc      = Input(UInt(vaddrBits.W))
        val out     = Output(new PreDecodeSignals)
    })
    //TODO 换成asBool
    val bpdSignals  = DecodeLogic(io.inst,default,table)
    val isBr        = bpdSignals(0)(0)
    val isJal       = bpdSignals(1)(0)
    val isJalr      = bpdSignals(2)(0)
    val isShadowable  = bpdSignals(3)(0)
    val hasRs2      = bpdSignals(4)(0)

    /**
     * isRet的情况：
     *      1.为JIRL指令
     *      2.rd=0，rj=1
     *      3立即数值为0
     */
    io.out.isRet := isJalr && io.inst(28) === BitPat("b0") && //BL和JIRL指令都是isJalr的，需要区分两者
            io.inst(4,0) === BitPat("b00000") &&
            io.inst(9,5) === BitPat("b00001") &&
            io.inst(25,10) === 0.U

    /**
     * isCall的情况：为BL指令
     */
    io.out.isCall := isJalr && io.inst(28) === BitPat("b1")
    //target输出一个32位的地址，结果要进行对齐
    io.out.target := ((Mux(isBr,
        Cat(Fill(14,io.inst(25)),io.inst(25,10),0.U(2.W)),
        Cat(Fill(4,io.inst(9)),io.inst(9,0),io.inst(25,10),0.U(2.W))).asSInt + io.pc.asSInt).asSInt & (-4).S).asUInt
    io.out.cfiType := Mux(isBr,CFI_BR,
            Mux(isJal,CFI_JAL,
            Mux(isJalr,CFI_JALR,CFI_X)))
    val brOffset = Cat(io.inst(25,10),0.U(2.W))
    /**
        是否是sfb:
            1.是条件分支指令
            2.偏移量为正值
            3.偏移量不为0
            4.偏移量在一个Cacheline内
     */
    io.out.sfbOffset.valid := isBr &&
            !io.inst(25) &&
            brOffset =/= 0.U &&
            brOffset(17,log2Ceil(blockBytes)) === 0.U
//            (brOffset >> log2Ceil(blockBytes)) === 0.U
    io.out.sfbOffset.bits   := brOffset

    /**
        shadowable的条件：
            1.指令本身是可以shadowable的
            2.没有RS2或者（RD==RS1）或者（为ADDW指令并且RS2=0）
     */
    io.out.shadowable   := isShadowable &&
            (!hasRs2 ||
            (io.inst(9,5) === io.inst(4,0)))
}