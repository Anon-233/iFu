package iFu.frontend

import chisel3._
import chisel3.util._
import chisel3.util.random.LFSR

import iFu.common._
import iFu.frontend.FrontendUtils._
import iFu.common.Consts._

class ICacheReq extends CoreBundle {
  val addr = UInt(vaddrBits.W)
}

class ICacheResp extends CoreBundle {
    val data = UInt((frontendParams.fetchBytes*8).W)
}

class ICache(val iParams : ICacheParameters) extends CoreModule {
    val io = IO(new Bundle{
        val req = Flipped(Decoupled(new ICacheReq))
        val s1_paddr = Input(UInt(paddrBits.W))

        val s1_kill = Input(Bool())
        val s2_kill = Input(Bool())

        val resp = Valid(new ICacheResp)
        val invalidate = Input(Bool())

        val cbusResp = Input(new CBusResp)
        val cbusReq = Output(new CBusReq)
    })
/*---------------------------------------------------------------------*/
//========== ----i$ params--- ==========
    val banksPerLine = iParams.banksPerLine
    val lineBytes = iParams.lineBytes
    val refillCycles = iParams.lineBytes * 8 / io.cbusResp.data.getWidth
    require(
        iParams.lineBytes % io.cbusResp.data.getWidth == 0,
        "LineBytes must be divisible by data width."
    )
    require(
        refillCycles >= nBanks,
        "Refill cycles must be greater than or equal to the number of banks."
    )
    require(
        isPow2(refillCycles),
        "Refill cycles must be a power of 2."
    )

    val packetBits = frontendParams.fetchBytes * 8
    val refillToOneBank = refillCycles == iParams.banksPerLine
    require(fetchBytes / nBanks == bankBytes)
//========== ----i$ params--- ==========
/*---------------------------------------------------------------------*/
//========== ----i$ funcs---- ==========
    def b0Row(addr: UInt) =
        addr(iParams.untagBits - 1, log2Ceil(iParams.bankBytes)) + bank(addr)
    def b1Row(addr: UInt) =
        addr(iParams.untagBits - 1, log2Ceil(iParams.bankBytes))
//========== ----i$ funcs---- ==========
/*---------------------------------------------------------------------*/
//========== ----i$ body----- ==========
    val s2_miss = Wire(Bool())
    val s_Normal :: s_Fetch :: Nil = Enum(2)
    val iCacheState = RegInit(s_Normal)
    val replWay = LFSR(16, s2_miss)(log2Ceil(iParams.nWays) - 1, 0)
    val validArray = RegInit(0.U((iParams.nSets * iParams.nWays).W))
    val tagArray = SyncReadMem(
        iParams.nSets,
        Vec(iParams.nWays, UInt(iParams.tagBits.W))
    )
    val dataArrays =
        (0 until iParams.nWays).map{
            x => SyncReadMem(
                iParams.nSets,
                UInt((packetBits / nBanks).W)
            )
        } ++
        (0 until iParams.nWays).map{
            x => SyncReadMem(
                iParams.nSets,
                UInt((packetBits / nBanks).W)
            )
        }
    val dataArrayB0 = dataArrays.take(iParams.nWays)
    val dataArrayB1 = dataArrays.drop(iParams.nWays)
//========== ----i$ body----- ==========
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
        val s1_validBit = validArray(Cat(i.U(log2Ceil(iParams.nWays).W), s1_idx))
        val tag = tagReadData(i)

        s1_tagHit(i) := s1_validBit && tag === s1_tag
    }
    val s1_hit = s1_tagHit.reduce(_||_)
    val s1_dataOut = Wire(Vec(iParams.nWays, UInt(packetBits.W)))
//========== ----S1 Stage---- ==========
/*---------------------------------------------------------------------*/
//========== S1 - S2 Register ==========
    val s2_valid = RegNext(s1_valid && !io.s1_kill)
    val s2_tagHit = RegNext(s1_tagHit)
    val s2_hit = RegNext(s1_hit)
    val s2_bankid = RegNext(s1_bankid)
    val s2_dataOut = RegNext(s1_dataOut)
//========== S1 - S2 Register ==========
/*---------------------------------------------------------------------*/
//========== ----S2 Stage---- ==========
    s2_miss := s2_valid && !s2_hit && (iCacheState === s_Normal)

    val s2_wayMux = Mux1H(s2_tagHit, s2_dataOut)
    val sz = s2_wayMux.getWidth
    val s2_bank0Data = s2_wayMux(sz / 2 - 1, 0)
    val s2_bank1Data = s2_wayMux(sz - 1, sz / 2)
    val s2_data = Mux(s2_bankid.asBool,
        Cat(s2_bank0Data, s2_bank1Data),
        Cat(s2_bank1Data, s2_bank0Data)
    )
//========== ----S2 Stage---- ==========
/*---------------------------------------------------------------------*/
//========== --inv i$ logic-- ==========
    val invalidated = Reg(Bool())
    when(io.invalidate) {
        validArray := 0.U
        invalidated := true.B
    }
    when (iCacheState =/= s_Fetch) {
        invalidated := false.B
    }
//========== --inv i$ logic-- ==========
//-----------------------------------------------------------------------
//========== --Refill Logic-- ==========
    val refillPaddr = RegEnable(
        io.s1_paddr,
        s1_valid && !(s2_miss || iCacheState === s_Fetch)
    )
    val refillTag = refillPaddr(iParams.tagBits + iParams.untagBits - 1, iParams.untagBits)
    val refillIdx = refillPaddr(iParams.untagBits-1, iParams.offsetBits)

    var refillOneBankEn: Bool = null
    var refillOneBankData: UInt = null
    var refillLastBank: Bool = null
    if (refillToOneBank) {
        refillOneBankEn = io.cbusReq.valid && io.cbusResp.ready
        refillOneBankData = io.cbusResp.data
        refillLastBank = io.cbusResp.ready && io.cbusResp.isLast
    } else {
        val refillBufCnt = RegInit(0.U(log2Ceil(refillCycles / banksPerLine).W))
        val refillBuf = RegInit(
            VecInit(Seq.fill(refillCycles / banksPerLine)(0.U((lineBytes * 8 / refillCycles).W)))
        )
        val refillBufWriteEn = io.cbusReq.valid && io.cbusResp.ready
        when (refillBufWriteEn) {
            refillBufCnt := refillBufCnt + 1.U
            refillBuf(refillBufCnt) := io.cbusResp.data
        }

        refillOneBankEn = RegNext(refillBufWriteEn) && refillBufCnt === 0.U
        refillOneBankData = refillBuf.asUInt
        refillLastBank = RegNext(io.cbusResp.ready && io.cbusResp.isLast)
    }

    val refillCnt = RegInit(0.U(log2Ceil(iParams.banksPerLine).W))
    when (refillOneBankEn) {
        refillCnt := refillCnt + 1.U
    }
    
    for (i <- 0 until iParams.nWays) {
        val dataArray0Idx = Mux(
            refillOneBankEn,
            ((refillIdx << (log2Ceil(iParams.banksPerLine) - 1)) | (refillCnt >> 1.U)),
            b0Row(s0_vaddr)
        )
        val dataArray1Idx = Mux(
            refillOneBankEn,
            ((refillIdx << (log2Ceil(iParams.banksPerLine) - 1)) | (refillCnt >> 1.U)),
            b1Row(s0_vaddr)
        )
        // read data
        s1_dataOut(i) := Cat(
            dataArrayB1(i).read(dataArray0Idx, s0_valid),
            dataArrayB0(i).read(dataArray1Idx, s0_valid)
        )
        // write data
        val writeEn = (refillOneBankEn && !invalidated) && replWay === i.U
        when (writeEn && refillCnt(0) === 0.U) {
            dataArrayB0(i).write(dataArray0Idx, refillOneBankData)
        }
        when (writeEn && refillCnt(0) === 1.U) {
            dataArrayB1(i).write(dataArray1Idx, refillOneBankData)
        }
    }
    when(refillLastBank){
        tagArray.write(
            refillIdx,
            VecInit(Seq.fill(iParams.nWays)(refillTag)),
            Seq.tabulate(iParams.nWays)(replWay === _.U)
        )
        validArray := validArray.bitSet(
            Cat(replWay, refillIdx), refillLastBank && !invalidated
        )
    }


//========== --Refill Logic-- ==========
/*---------------------------------------------------------------------*/
//========== ----- FSM  ----- ==========
    when (iCacheState === s_Normal) {
        iCacheState := Mux(s2_miss && !io.s2_kill, s_Fetch, s_Normal)
    } .elsewhen (iCacheState === s_Fetch) {
        iCacheState := Mux(refillLastBank, s_Normal, s_Fetch)
    } .otherwise {
        iCacheState := iCacheState
    }
//========== ----- FSM  ----- ==========
/*---------------------------------------------------------------------*/
//========== ------ IO ------ ==========
    io.req.ready := iCacheState === s_Normal
    io.resp.valid := s2_valid && s2_hit
    io.resp.bits.data := s2_data

    io.cbusReq.valid := ((s2_miss && !io.s2_kill) || (iCacheState === s_Fetch)) && !RegNext(io.cbusResp.isLast)
    io.cbusReq.isStore := false.B
    io.cbusReq.size := MSIZE4
    io.cbusReq.addr := (refillPaddr >> iParams.offsetBits) << iParams.offsetBits
    io.cbusReq.mask := 0.U
    io.cbusReq.axiBurstType := AXI_BURST_INCR
    io.cbusReq.axiLen := MLEN16
    io.cbusReq.data := DontCare
    require(iParams.lineBytes == 64)
//========== ------ IO ------ ==========
/*---------------------------------------------------------------------*/
//========== ----for debug--- ==========
    // val clk = RegInit(0.U(64.W))
    // printf(p"=>=>=>=>=>=>=welcom to iCache=<=<=<=<=<=<=\n")
    // printf(p"\tnow state: ${iCacheState}\n")
    // printf(p"\ts0_valid: ${s0_valid}, s0_vaddr: ${s0_vaddr}\n")
    // printf(p"\ts1_valid: ${s1_valid}, s1_paddr: ${io.s1_paddr}\n")
    // printf(p"\ts1_kill: ${io.s1_kill}, s2_kill: ${io.s2_kill}\n")
    // printf(p"\tibusreq: ${io.cbusReq}\n")
    // when (io.cbusResp.ready) {
    //     printf(p"\tibusresp: ${io.cbusResp}\n")
    // }
    // printf(p"\trefillbuf: ${refillBuf}, refillbufcnt: ${refillBufCnt}\n")
//========== ----for debug--- ==========
/*---------------------------------------------------------------------*/
}