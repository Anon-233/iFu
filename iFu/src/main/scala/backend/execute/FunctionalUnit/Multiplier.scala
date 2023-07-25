package iFu.backend

import chisel3._
import chisel3.util._

class MultFuncCode {
    val SZ_MUL_FN = 4
    def FN_X    = BitPat("b????")
    def FN_MUL  = 3.U(SZ_MUL_FN.W)  // 0b11
    def FN_MULH = 1.U(SZ_MUL_FN.W)  // 0b01
    def FN_MULHU= 0.U(SZ_MUL_FN.W)  // 0b00

    def LorH(cmd: UInt) = cmd(1)
    def SorU(cmd: UInt) = cmd(0)
}

object MultFuncCode {
    def apply() = new MultFuncCode()
}

class MultReq[T <: MultFuncCode](val mulFn: T) extends CoreBundle {
    val fn = UInt(mulFn.SZ_MUL_FN.W)
    val op1 = UInt(xLen.W)
    val op2 = UInt(xLen.W)
}

class MultResp extends CoreBundle {
    val data = UInt(xLen.W)
}

abstract class AbstractMult[T <: MultFuncCode](val mulFn: T) extends CoreModule {
    val io = IO(new Bundle {
        val req = Flipped(Valid(new MultReq(mulFn)))
        val resp = Valid(new MultResp())
    })
}

class MultStar(val debug: Boolean = false, val latency: Int = 3) extends AbstractMult(MultFuncCode()) {
    val req = Pipe(io.req)
    val lhs = Cat(mulFn.SorU(req.bits.fn) & req.bits.op1(xLen - 1), req.bits.op1).asSInt
    val rhs = Cat(mulFn.SorU(req.bits.fn) & req.bits.op2(xLen - 1), req.bits.op2).asSInt
    val prod = lhs * rhs
    val res = Mux(mulFn.LorH(req.bits.fn), prod(xLen - 1, 0), prod(2 * xLen - 1, xLen))
    val resp = Pipe(req, latency - 1)
    io.resp.valid := resp.valid
    io.resp.bits.data := Pipe(req.valid, res, latency - 1).bits

    if (debug) {
        val cnt = RegInit(0.U(32.W))
        cnt := cnt + 1.U
        printf(p"------------clock: ${cnt}------------\n")
        when (io.resp.valid) {
            printf(p"req: ${resp}\n")
            printf(p"resp: ${io.resp}\n")
            printf("\n")
        } .otherwise {
            printf("no response\n")
        }
    }
}

class MultWallace extends AbstractMult(MultFuncCode()) {
    // TODO: implement Wallace tree multiplier
}