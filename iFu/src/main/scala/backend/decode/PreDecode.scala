package iFu.backend

import chisel3._
import chisel3.util._

import iFu.isa.Instructions._
import iFu.common._   
import iFu.common.Consts._

//TODO 增加PCADDIW等与PC有关的指令

trait PreDecodeTable {
    val default = List[BitPat](N,N,N,N,X)
    val table:Array[(BitPat,List[BitPat])] = Array[(BitPat,List[BitPat])](
        ////                      is br?
        ////                      |  is jal?
        ////                      |  |  is jalr?
        ////                      |  |  |
        ////                      |  |  |  shadowable
        ////                      |  |  |  |  has_rs2
        ////                      |  |  |  |  |
        JIRL               ->List(N, N, Y, N, X),
        B                  ->List(N, Y, N, N, X),
        BL                 ->List(N, Y, N, N, X),
        BEQ                ->List(Y, N, N, N, X),
        BNE                ->List(Y, N, N, N, X),
        BLT                ->List(Y, N, N, N, X),
        BLTU               ->List(Y, N, N, N, X),
        BGE                ->List(Y, N, N, N, X),
        BGEU               ->List(Y, N, N, N, X),

        ADDW               ->List(N, N, N, Y, Y),
        SUBW               ->List(N, N, N, Y, Y),
        ADDIW              ->List(N, N, N, Y, N),
        LU12IW             ->List(N, N, N, Y, N),
        SLT                ->List(N, N, N, Y, Y),
        SLTU               ->List(N, N, N, Y, Y),
        SLTI               ->List(N, N, N, Y, N),
        SLTUI              ->List(N, N, N, Y, N),
        
        AND                ->List(N, N, N, Y, Y),
        OR                 ->List(N, N, N, Y, Y),
        XOR                ->List(N, N, N, Y, Y),
        NOR                ->List(N, N, N, Y, Y),
        ANDI               ->List(N, N, N, Y, N),
        ORI                ->List(N, N, N, Y, N),
        XORI               ->List(N, N, N, Y, N),
        ANDN               ->List(N, N, N, Y, Y),
        ORN                ->List(N, N, N, Y, Y),

        SLLW               ->List(N, N, N, Y, Y),
        SRLW               ->List(N, N, N, Y, Y),
        SRAW               ->List(N, N, N, Y, Y),
        SLLIW              ->List(N, N, N, Y, N),
        SRLIW              ->List(N, N, N, Y, N),
        SRAIW              ->List(N, N, N, Y, N)
    )
}

class PreDecodeSignals extends CoreBundle {
    val isRet       = Bool()
    val isCall      = Bool()
    val target      = UInt(vaddrBits.W)
    val cfiType     = UInt(CFI_SZ.W)
    val sfbOffset   = Valid(UInt(log2Ceil(frontendParams.iCacheParams.lineBytes).W))   // do we need this?
    val shadowable  = Bool()
}

class PreDecode extends CoreModule with PreDecodeTable {
    val io = IO(new Bundle{
        val instr   = Input(UInt(coreInstrBits.W))
        val pc      = Input(UInt(vaddrBits.W))
        val out     = Output(new PreDecodeSignals)
    })

    //TODO 换成asBool
    val bpdSignals = DecodeLogic(io.instr, default, table)

    val isBr          = bpdSignals(0)(0)
    val isJal         = bpdSignals(1)(0)
    val isJalr        = bpdSignals(2)(0)
    val isShadowable  = bpdSignals(3)(0)
    val hasRs2        = bpdSignals(4)(0)

    /**
     * isRet的情况：
     *      1. 为JIRL指令
     *      2. rd=0 rj=1
     *      3. 立即数值为0
     */
    io.out.isRet := (isJalr && io.instr(4,0) === 0.U && io.instr(9,5) === 1.U && io.instr(25,10) === 0.U)
    /**
     * isCall的情况：为BL指令
     */
    io.out.isCall := isJal && io.instr(26)

    // target输出一个32位的地址
    io.out.target := ((
        Mux(isBr, 
            Cat(Fill(14, io.instr(25)), io.instr(25,10), 0.U(2.W)),
            Cat(Fill(4, io.instr(9)), io.instr(9,0), io.instr(25,10), 0.U(2.W))
        ).asSInt + io.pc.asSInt).asSInt & (-4).S).asUInt

    io.out.cfiType := Mux(isBr,   CFI_BR,
                      Mux(isJal,  CFI_JAL,
                      Mux(isJalr, CFI_JALR,
                                  CFI_X)))

    val brOffset = Cat(io.instr(25,10), 0.U(2.W))

    /**
     *  是否是sfb:
     *      1. 是条件分支指令
     *      2. 偏移量为正值
     *      3. 偏移量不为0
     *      4. 偏移量在一个Cacheline内
     */
    io.out.sfbOffset.valid := isBr &&
            !io.instr(25) &&
            brOffset =/= 0.U &&
            brOffset(17, log2Ceil(frontendParams.iCacheParams.lineBytes)) === 0.U

    io.out.sfbOffset.bits := brOffset

    /**
     *  shadowable的条件：
     *      1. 指令本身是可以shadowable的
     *      2. 没有 RS2 或者 RD == RS1
     */
    io.out.shadowable   := isShadowable && (!hasRs2 || (io.instr(9,5) === io.instr(4,0)))
}