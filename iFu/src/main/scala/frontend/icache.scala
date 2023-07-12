package iFu.frontend

import chisel3._
import chisel3.util._
import iFu.common._


//ICache的输出
class ICacheResp extends Bundle
{
    val data = UInt((frontendParams.iCacheParams.fetchBytes*8).W)
    val replay = Bool()
}


//ICahe的输入
trait HasL1ICacheParameters extends HasL1CacheParameters with HasCoreParameters {
  val cacheParams = tileParams.icache.get
}

class ICacheReq(implicit p: Parameters) extends CoreBundle()(p) with HasL1ICacheParameters {
  val addr = UInt(vaddrBits.W)
}




class ICache(val iParams : frontendParams.iCacheParams
    //val staticIdForMetadataUseOnly: Int
) extends LazyModule
with HasCoreParameters
{
    val enableICacheDelay = tileParams.core.asInstanceOf[BoomCoreParams].enableICacheDelay
    val io = IO(new CoreBundle{
        val req = Flipped(Decoupled(new ICacheReq))
        val s1_paddr = Input(UInt(paddrBits.W))

        val s1_kill = Input(Bool())
        val s2_kill = Input(Bool())
        val s2_prefetch = Input(Bool())

        val resp = Valid(new ICacheResp)
        val invalidate = Input(Bool())

        val pref = Output(new Bundle{
            val acquire = Bool()
        })

    })

    val (tl_out, edge_out) = outer.masterNode.out(0)
    val wordBits = frontendParams.iCacheParams.fetchBytes * 8

    val refillsToOneBank = (2*tl_out.d.bits.data.getWidth == wordBits)


    val s0Valid = io.req.fire
    val s0Vaddr = io.req.bits.addr

    val s1Valid = RegNext(s0Valid)
    val s1TagHit = Wire(Vec(nWays,Bool()))
    val s1Hit = s1TagHit.reduce(_||_)
    
    val s2Valid = RegNext(s1Valid && !io.s1_kill)
    val s2Hit = RegNext(s1Hit)

    val invalidated = Reg(Bool())
    val refillValid = RegInit(false.B)
    val refillFire = tl_out.a.fire
    val s2Miss = s2_valid && !s2Hit && !RegNext(refillValid)
    val refillPaddr = RegEnable(io.s1_paddr , s1Valid && !(refillValid || s2Miss))
    val refillTag = refillPaddr(tagBits + untagBits-1,untagBits)
    val refillIdx = refillPaddr(untagBits-1,blockOffBits)
    val refillOneBeat = tl_out.d.fire && edge_out.hasData(tl_out.d.bits)

    io.req.ready := !refillOneBeat

    val (_, _, dDone, refillCnt) = edge_out.count(tl_out.d)
    val refillDone = refillOneBeat && dDone
    ti_out.d.ready := true.B

    val replWay = if(isDM) 0.U else LFSR(16,refillFire)

    val tagArray = SyncReadMem(nSets,Vec(nWays,Uint(tagBits.W)))
    val tagRData = tagArray.read(s0Vaddr(untagBits-1,blockOffBits),!refillDone && s0Valid)
    when(refillDone){
        tagArray.write(refillIdx,Vec(Seq.fill(nWays)(refillTag),Seq.tabulate(nWays)(replWay === _.U)))
    }

    val vbArray = RegInit(0.U((nSets*nWays).W))
    when(refillOneBeat){
        vbArray := vbArray.bitSet(Cat(replWay,refillIdx),refillDone && !invalidated)

    }

    when(io.invalidate) {
        vbArray := 0.U
        invalidated := true.B
    }

    val s2Dout = Wire(Vec(nWays,UInt(wordBits.W)))
    val s1Bankid = Wire(Bool())

    for(i <- 0 until nWays){
        val s1Idx = io.s1_paddr(untagBits-1,blockOffBits)
        val s1Tag = io.s1_paddr(tagBits + untagBits -1,untagBits)
        val s1Vb = vbArray(Cat(i.U,s1Idx))
        val tag = tagRData(i)
        s1TagHit(i) := s1Vb && tag == s1Tag
    }
    
    val ramDepth = if(refillsToOneBank){
        nSets * refillCycles /2
    }else{
        nSets * refillCycles
    }

    //nBanks == 2 
    val dataArrays = 
        (0 until nWays).map{
            x=>DescribedSRAM(
                name = s"dataArrayB0Way_${x}",
                desc = "ICache Data Array",
                size = ramDepth,
                data = UInt((wordBits/nBanks).W)
            )
        } 
        ++
        (0 until nWays).map{
            x=>DescribedSRAM(
                name = s"dataArrayB1Way_${x}",
                desc = "ICache Data Array",
                size = ramDepth,
                data = UInt((wordBits/nBanks).W)
            )
        } 

    //nBanks == 2 

    val dataArrayB0 = dataArrays.take(nWays)
    val dataArrayB1 = dataArrays.drop(nWays)

    def b0Row(addr: UInt) =
        if (refillsToOneBank){
            addr(untagBits-1,blockOffBits - log2Ceil(refillCycles)+1) + bank(addr)
        } else {
            addr(untagBits-1, blockOffBits-log2Ceil(refillCycles)) + bank(addr)
        }

    def b1Row(addr: UInt) =
        if (refillsToOneBank) {
            addr(untagBits-1, blockOffBits-log2Ceil(refillCycles)+1)
        } else {
            addr(untagBits-1, blockOffBits-log2Ceil(refillCycles))
        }
    
    s1Bankid := RegNext(bank(s0Vaddr))

    for(i <- 0 until nWays){
        val s0Ren = s0Valid
        val wen = (refillOneBeat && !invalidated) && replWay ===i.U

        var memIdx0: UInt = null
        var memIdx1: UInt = null

        if(refillsToOneBank){
            //只写一个bank
            memIdx0 = Mux(refillOneBeat,(refillIdx << (log2Ceil(refillCycles)-1)) | (refillCnt >> 1.U),
                b0Row(s0Vaddr))
            memIdx1 =Mux(refill_one_beat, (refill_idx << (log2Ceil(refillCycles)-1)) | (refill_cnt >> 1.U),
                b1Row(s0_vaddr))

            when (wen && refill_cnt(0) === 0.U){
                dataArrayB0(i).write(memIdx0,tl_out.d.bits.data)
            }
            when (wen && refill_cnt(0) === 1.U){
                dataArrayB1(i).write(memIdx1,tl_out.d.bits.data)
            }
        } else {
            //写两个bank
            memIdx0 = Mux(refillOneBeat,(refillIdx << log2Ceil(refillCycles)) | refillCnt,
                b0Row(s0Vaddr))
            memIdx1 = Mux(refill_one_beat, (refill_idx << log2Ceil(refillCycles)) | refill_cnt,
                b1Row(s0_vaddr))

            when (wen) {
                val data = tl_out.d.bits.data
                dataArrayB0(i).write(memIdx0,data(wordBits/2-1, 0))
                dataArrayB1(i).write(memIdx1,data(wordBits-1,wordBits/2))
            }
        }
    
        if(enableICacheDelay){
            s2Dout(i) := Cat(dataArrayB1(i).read(RegNext(memIdx1), RegNext(!wen && s0Ren)),
                            dataArrayB0(i).read(RegNext(memIdx0), RegNext(!wen && s0Ren)))
        } else {
            s2Dout(i) := RegNext(Cat(dataArrayB1(i).read(memIdx1,!wen && s0Ren),
                                    dataArrayB0(i).read(memIdx0, !wen && s0Ren)))
        }
    }

    //
    val s2TagHit = RegNext(s1TagHit)
    val s2HitWay = OHToUInt(s2TagHit)
    val s2Bankid = RegNext(s1Bankid)
    val s2WayMux = Mux1H(s2TagHit,s2Dout)

    val s2UnbankedData = s2WayMux
    val sz = s2WayMux.getWidth
    val s2Bank0Data = s2WayMux(sz/2-1, 0)
    val s2Bank1Data = s2WayMux(sz-1,sz/2)

    
    val s2Data = Mux(s2Bankid,
        Cat(s2Bank0Data,s2Bank1Data),
        Cat(s2Bank1Data,s2Bank0Data))

    io.resp.bits.data := s2Data
    io.resp.valid := s2Valid && s2Hit

    tl_out.a.valid := s2_miss && !refill_valid && !io.s2_kill
    tl_out.a.bits := edge_out.Get(
    fromSource = 0.U,
    toAddress = (refill_paddr >> blockOffBits) << blockOffBits,
    lgSize = lgCacheBlockBytes.U)._2
    tl_out.b.ready := true.B
    tl_out.c.valid := false.B
    tl_out.e.valid := false.B

    io.pref.acquire := tl_out.a.fire

    when (!refill_valid) { invalidated := false.B }
    when (refill_fire) { refill_valid := true.B }
    when (refill_done) { refill_valid := false.B }

}