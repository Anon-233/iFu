package iFu.frontend

import chisel3._
import chisel3.util._
import chisel3.util.random.LFSR

import iFu.common._
import iFu.frontend.FrontendUtils._

class CbusReq extends Bundle {
    val isWrite = Bool()
    val size = UInt(2.W)
    val addr = UInt(32.W)
    val data = UInt(32.W)
    val mask = UInt(16.W)
    val axiBurstType = UInt(2.W)
    val axiLen = UInt(8.W)
}

class CbusResp extends Bundle {
    val data = UInt(32.W)
    val isLast = Bool()
    val ready = Bool()
}

//ICache的输出
class ICacheResp extends CoreBundle {
    val data = UInt((frontendParams.fetchBytes*8).W)
}


class ICacheReq extends CoreBundle {
  val addr = UInt(vaddrBits.W)
}


class ICache(val iParams : ICacheParameters) extends CoreModule {
    val io = IO(new Bundle{
        val req = Flipped(Decoupled(new ICacheReq))
        val s1_paddr = Input(UInt(paddrBits.W))

        val s1_kill = Input(Bool())
        val s2_kill = Input(Bool())

        val resp = Valid(new ICacheResp)
        val invalidate = Input(Bool())

        val cbusResp = Input(new CbusResp)
        val cbusReq = Decoupled(new CbusReq)
    })
/*---------------------------------------------------------------------*/
    val refillCycles = iParams.lineBytes / io.cbusResp.data.getWidth
    require(
        iParams.lineBytes % io.cbusResp.data.getWidth == 0,
        "LineBytes must be divisible by data width."
    )
    val packetBits = frontendParams.fetchBytes * 8
    require((2 * (io.cbusResp.data.getWidth) == packetBits))
/*---------------------------------------------------------------------*/
    def b0Row(addr: UInt) =
        addr(iParams.untagBits - 1, log2Ceil(iParams.bankBytes)) + bank(addr)
    def b1Row(addr: UInt) =
        addr(iParams.untagBits - 1, log2Ceil(iParams.bankBytes))
/*---------------------------------------------------------------------*/
    val replWay = LFSR(16, refillFire)(log2Ceil(iParams.nWays) - 1, 0)
    val validArray = RegInit(0.U((iParams.nSets * iParams.nWays).W))
    val tagArray = SyncReadMem(
        iParams.nSets,
        Vec(iParams.nWays, UInt(iParams.tagBits.W))
    )
    val dataArrays =
        (0 until iParams.nWays).map{
            x => SyncReadMem(
                size = iParams.nSets,
                data = UInt((packetBits / iParams.nBanks).W)
            )
        } ++
        (0 until iParams.nWays).map{
            x => SyncReadMem(
                size = iParams.nSets,
                data = UInt((packetBits / iParams.nBanks).W)
            )
        }
    val dataArrayB0 = dataArrays.take(iParams.nWays)
    val dataArrayB1 = dataArrays.drop(iParams.nWays)
/*---------------------------------------------------------------------*/
//========== ----S0 Stage---- ==========
    val s0_valid = io.req.fire
    val s0_vaddr = io.req.bits.addr

    val s0_tagReadEn = s0_valid
//========== ----S0 Stage---- ==========
/*---------------------------------------------------------------------*/
//========== S0 - S1 Register ==========
    val tagReadData = tagArray.read(
        s0_vaddr(iParams.untagBits - 1, iParams.offsetBits),
        s0_tagReadEn
    )

    val s1_valid = RegNext(s0_valid)
    val s1_bankid = RegNext(bank(s0_vaddr))
//========== S0 - S1 Register ==========
/*---------------------------------------------------------------------*/
//========== ----S1 Stage---- ==========
    val s1_tagHit = Wire(Vec(iParams.nWays, Bool()))

    for (i <- 0 until iParams.nWays) {
        val s1_idx = io.s1_paddr(iParams.untagBits - 1, iParams.offsetBits)
        val s1_tag = io.s1_paddr(iParams.tagBits + iParams.untagBits -1, iParams.untagBits)
        val s1_validBit = validArray(Cat(i.U, s1_idx))
        val tag = tagReadData(i)

        s1_tagHit(i) := s1_validBit && tag === s1_tag
    }
    val s1_hit = s1_tagHit.reduce(_||_)
//========== ----S1 Stage---- ==========
/*---------------------------------------------------------------------*/
//========== S0 - S1 Register ==========
    val s2_valid = RegNext(s1_valid && !io.s1_kill)
    val s2_tagHit = RegNext(s1_tagHit)
    val s2_hit = RegNext(s1_hit)
    val s2_bankid = RegNext(s1_bankid)
    val s1_dataOut = Wire(Vec(iParams.nWays, UInt(packetBits.W)))
//========== S0 - S1 Register ==========
/*---------------------------------------------------------------------*/
//========== ----S2 Stage---- ==========
    val s2_dataOut = RegNext(s1_dataOut)
    val s2_wayMux = Mux1H(s2_tagHit, s2_dataOut)

    val sz = s2_wayMux.getWidth
    val s2_bank0Data = s2_wayMux(sz / 2 - 1, 0)
    val s2_bank1Data = s2_wayMux(sz - 1, sz / 2)
    val s2_data = Mux(s2_bankid,
        Cat(s2_bank0Data, s2_bank1Data),
        Cat(s2_bank1Data, s2_bank0Data)
    )
//========== ----S2 Stage---- ==========
/*---------------------------------------------------------------------*/
//========== ----- Resp ----- ==========
    io.resp.valid := s2_valid && s2_hit
    io.resp.bits.data := s2_data
//========== ----- Resp ----- ==========


    val invalidated = Reg(Bool()) //清空整个icache
    val refillValid = RegInit(false.B)
    val refillFire = io.cbusReq.fire
    val s2Miss = s2Valid && !s2Hit && !RegNext(refillValid)
    val refillPaddr = RegEnable(io.s1_paddr , s1Valid && !(refillValid || s2Miss))
    val refillTag = refillPaddr(iParams.tagBits + iParams.untagBits-1,iParams.untagBits)
    val refillIdx = refillPaddr(iParams.untagBits-1,iParams.offsetBits)
    val refillOneBeat = io.cbusReq.valid && io.cbusResp.ready

    io.req.ready := !refillOneBeat  // ????

    val dDone = io.cbusResp.ready && io.cbusResp.isLast
    val refillCnt = RegInit(0.U(4.W)) //和refillCycles
    when(refillOneBeat){
        refillCnt := refillCnt + 1.U
    }
    when(dDone){
        refillCnt := 0.U
    }
    val refillDone = refillOneBeat && dDone
    
    when(refillDone){
        tagArray.write(refillIdx,VecInit(Seq.fill(iParams.nWays)(refillTag)),Seq.tabulate(iParams.nWays)(replWay === _.U))
    }

    when(refillOneBeat){
        vbArray := vbArray.bitSet(Cat(replWay, refillIdx), refillDone && !invalidated)
    }

    when(io.invalidate) {
        vbArray := 0.U
        invalidated := true.B
    }

//-----------------------------------------------------------------------
    for(i <- 0 until iParams.nWays){
        val s0_readEn = s0_valid
        val wEn = (refillOneBeat && !invalidated) && replWay === i.U

        val memIdx0 = Mux(refillOneBeat,
            ((refillIdx << (log2Ceil(iParams.refillCycles) - 1)) | (refillCnt >> 1.U)),
            b0Row(s0Vaddr)
        )
        val memIdx1 = Mux(refillOneBeat,
            ((refillIdx << (log2Ceil(iParams.refillCycles) - 1)) | (refillCnt >> 1.U)),
            b1Row(s0Vaddr)
        )

        when (wEn && refillCnt(0) === 0.U){
            dataArrayB0(i).write(memIdx0,io.cbusResp.data)
        }
        when (wEn && refillCnt(0) === 1.U){
            dataArrayB1(i).write(memIdx1,io.cbusResp.data)
        }

        s1_dataOut(i) := Cat(
            dataArrayB1(i).read(memIdx1, !wEn && s0Ren),
            dataArrayB0(i).read(memIdx0, !wEn && s0Ren)
        )
    }

    io.cbusReq.valid := s2Miss && !refillValid && !io.s2_kill
    io.cbusReq.bits.isWrite := false.B
    io.cbusReq.bits.size := 1.U(2.W)
    io.cbusReq.bits.addr := (refillPaddr >> iParams.offsetBits) << iParams.offsetBits
    io.cbusReq.bits.mask := 0.U
    io.cbusReq.bits.axiBurstType := 1.U
    io.cbusReq.bits.axiLen := iParams.refillCycles.U

    when (!refillValid) { invalidated := false.B }
    when (refillFire) { refillValid := true.B }
    when (refillDone) { refillValid := false.B }
}