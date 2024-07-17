package iFu.frontend

import chisel3._
import chisel3.util._
import iFu.axi3._
import iFu.common._
import iFu.frontend.FrontendUtils._
import iFu.sma._
import ram.SDPRam

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

        val smar = new SMAR
    })
/*---------------------------------------------------------------------*/
//========== ----i$ params--- ==========
    val fetchesPerLine = iParams.fetchesPerLine
    val lineBytes      = iParams.lineBytes
    val smaBytes       = io.smar.resp.rdata.getWidth / 8
    require(
        iParams.lineBytes % smaBytes == 0,
        "LineBytes must be divisible by data width."
    )

    val packetBits = frontendParams.fetchBytes * 8
//========== ----i$ params--- ==========
/*---------------------------------------------------------------------*/
//========== ----i$ funcs---- ==========
    def getTag(addr: UInt) = addr(iParams.tagBits + iParams.untagBits - 1, iParams.untagBits)
    def getSet(addr: UInt) = addr(iParams.untagBits - 1, iParams.untagBits - iParams.indexBits)
//========== ----i$ funcs---- ==========
/*---------------------------------------------------------------------*/
//========== ----i$ body----- ==========
    val s_Normal :: s_Fetch :: Nil = Enum(2)
    val iCacheState = RegInit(s_Normal)

    val s2_miss     = Wire(Bool())
    /* val replWay     = LFSR(16, s2_miss)(log2Ceil(iParams.nWays) - 1, 0) */
    val repls       = (0 until iParams.nSets) map { i =>
        val repl = Module(new PseudoLRU(iParams.nWays))
        repl.io
    }
    val replWays    = VecInit(repls map { _.repl_way })

    val validArray  = RegInit(0.U((iParams.nSets * iParams.nWays).W))
    val tagArray    = Module(new SDPRam(iParams.nSets, UInt(iParams.tagBits.W), iParams.nWays))
    val dataArray   = Module(new SDPRam(iParams.nSets * fetchesPerLine, UInt(packetBits.W), iParams.nWays))
//========== ----i$ body----- ==========
/*---------------------------------------------------------------------*/
//========== ----S0 Stage---- ==========
    val s0_valid = io.req.fire
    val s0_vaddr = io.req.bits.addr
//========== ----S0 Stage---- ==========
/*---------------------------------------------------------------------*/
//========== S0 - S1 Register ==========
    val s1_valid    = RegNext(s0_valid)
    val s1_idx      = RegNext(getSet(s0_vaddr))
    val s1_fetchIdx = RegNext(s0_vaddr(iParams.offsetBits - 1, log2Ceil(fetchBytes)))
//========== S0 - S1 Register ==========
/*---------------------------------------------------------------------*/
//========== ----S1 Stage---- ==========
    // do nothing for now
//========== ----S1 Stage---- ==========
/*---------------------------------------------------------------------*/
//========== S1 - S2 Register ==========
    val s2_valid   = RegNext(s1_valid && !io.s1_kill)
    val s2_idx = RegNext(s1_idx)
    tagArray.io.raddr := s1_idx
    val tagReadData = tagArray.io.rdata
    dataArray.io.raddr := Cat(s1_idx, s1_fetchIdx)
//========== S1 - S2 Register ==========
/*---------------------------------------------------------------------*/
//========== ----S2 Stage---- ==========
    val s2_tagHit = Wire(Vec(iParams.nWays, Bool()))
    for (i <- 0 until iParams.nWays) {
        val s2_tag      = RegNext(getTag(io.s1_paddr))
        val s2_validBit = validArray(Cat(i.U(log2Ceil(iParams.nWays).W), s2_idx))
        val tag         = tagReadData(i)

        s2_tagHit(i) := s2_validBit && tag === s2_tag
    }
    val s2_hit     = s2_tagHit.asUInt.orR
    val s2_hit_pos = OHToUInt(s2_tagHit)
    val s2_data    = Mux1H(s2_tagHit, dataArray.io.rdata)
    s2_miss := s2_valid && !s2_hit && (iCacheState === s_Normal)

    repls.zipWithIndex.foreach { case (repl, i) =>
        repl.access.valid := (
            (iCacheState === s_Normal) &&
            (i.U === s2_idx)           &&
            s2_valid                   &&
            s2_hit
        )
        repl.access.bits  := s2_hit_pos
    }
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
    val refillTag = getTag(refillPaddr)
    val refillIdx = getSet(refillPaddr)

    var refillEn: Bool = null
    var refillData: UInt = null
    var refillLast: Bool = null
    val needBuffer = smaBytes != fetchBytes
    if (!needBuffer) {
        refillEn   = io.smar.req.arvalid && io.smar.resp.rvalid
        refillData = io.smar.resp.rdata
        refillLast = io.smar.resp.rvalid && io.smar.resp.rlast
    } else {
        val refillBufWidth = fetchBytes / smaBytes
        val refillBufCnt   = RegInit(0.U(log2Ceil(refillBufWidth).W))
        val refillBuf      = RegInit(
            VecInit(Seq.fill(refillBufWidth)(0.U((smaBytes * 8).W)))
        )

        val refillBufWriteEn = io.smar.req.arvalid && io.smar.resp.rvalid
        when (refillBufWriteEn) {
            refillBufCnt            := refillBufCnt + 1.U
            refillBuf(refillBufCnt) := io.smar.resp.rdata
        }

        refillEn   = RegNext(refillBufWriteEn) && refillBufCnt === 0.U
        refillData = refillBuf.asUInt
        refillLast = RegNext(io.smar.resp.rvalid && io.smar.resp.rlast)
    }

    val refillCnt = RegInit(0.U(log2Ceil(fetchesPerLine).W))
    when (refillEn) {
        refillCnt := refillCnt + 1.U
    }

    val writeEn = refillEn
    val writeIdx = Cat(refillIdx, refillCnt)
    dataArray.io.wen := writeEn
    dataArray.io.waddr := writeIdx
    dataArray.io.wdata := VecInit(Seq.fill(iParams.nWays)(refillData))
    dataArray.io.wstrobe := VecInit(Seq.tabulate(iParams.nWays)(replWays(refillIdx) === _.U)).asUInt

    when (refillLast) {
        validArray := validArray.bitSet(
            Cat(replWays(refillIdx), refillIdx), refillLast && !invalidated
        )
    }
    tagArray.io.wen := refillLast
    tagArray.io.waddr := refillIdx
    tagArray.io.wdata := VecInit(Seq.fill(iParams.nWays)(refillTag))
    tagArray.io.wstrobe := VecInit(Seq.tabulate(iParams.nWays)(replWays(refillIdx) === _.U)).asUInt

//========== --Refill Logic-- ==========
/*---------------------------------------------------------------------*/
//========== ----- FSM  ----- ==========
    when (iCacheState === s_Normal) {
        iCacheState := Mux(s2_miss && !io.s2_kill, s_Fetch, s_Normal)
    } .elsewhen (iCacheState === s_Fetch) {
        iCacheState := Mux(refillLast, s_Normal, s_Fetch)
    } .otherwise {
        iCacheState := iCacheState
    }
//========== ----- FSM  ----- ==========
/*---------------------------------------------------------------------*/
//========== ------ IO ------ ==========
    io.req.ready := iCacheState === s_Normal
    io.resp.valid := s2_valid && s2_hit
    io.resp.bits.data := s2_data

    io.smar.req.arvalid := ((s2_miss && !io.s2_kill) || (iCacheState === s_Fetch)) && !RegNext(io.smar.resp.rlast)
    io.smar.req.arsize := AXI3Parameters.MSIZE4
    io.smar.req.araddr := (refillPaddr >> iParams.offsetBits) << iParams.offsetBits
    io.smar.req.arburst := AXI3Parameters.BURST_WRAP
    io.smar.req.arlen := AXI3Parameters.MLEN16
    require(iParams.lineBytes == 64)
//========== ------ IO ------ ==========
}
