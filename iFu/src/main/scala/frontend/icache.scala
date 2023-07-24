package iFu.frontend

import chisel3._
import chisel3.util._
import chisel3.util.random.LFSR
import iFu.common._
import iFu.common.HasCoreParameters

import scala.collection.mutable.{ListBuffer}


object DescribedSRAM {
    def apply[T <: Data](
                          name: String,
                          desc: String,
                          size: BigInt, // depth
                          data: T
                        ): SyncReadMem[T] = {

        val mem = SyncReadMem(size, data)
        mem.suggestName(name)
        val granWidth = data match {
            case v: Vec[_] => v.head.getWidth
            case d => d.getWidth
        }
        val uid = 0
        mem
    }
}
class CbusReq extends Bundle{
    val valid = Bool()
    val isWrite = Bool()
    val size = UInt(2.W)
    val addr = UInt(32.W)
    val data = UInt(32.W)
    val mask = UInt(16.W)
    val axiBurstType = UInt(2.W)
    val axiLen = UInt(8.W)
}

class CbusResp extends Bundle{
    val data = UInt(32.W)
    val isLast = Bool()
    val ready = Bool()
}

//ICache的输出
class ICacheResp extends CoreBundle
{
    val data = UInt((frontendParams.fetchBytes*8).W)
    val replay = Bool()
}


class ICacheReq extends CoreBundle{
  val addr = UInt(vaddrBits.W)
}


class ICache(val iParams : ICacheParameters
    //val staticIdForMetadataUseOnly: Int
) extends CoreModule
with HasCoreParameters
{

    val io = IO(new CoreBundle{
        val req = Flipped(Decoupled(new ICacheReq))
        val s1_paddr = Input(UInt(paddrBits.W))

        val s1_kill = Input(Bool())
        val s2_kill = Input(Bool())

        val resp = Valid(new ICacheResp)
        val invalidate = Input(Bool())

        val cbusResp = Input(new CbusResp)
        val cbusReq = Output(new CbusReq)

        val perf = Output(new Bundle{
            val acquire = Bool()
        })

    })

    def bank(addr: UInt) =  addr(log2Ceil(iParams.bankBytes))

    val wordBits = frontendParams.fetchBytes * 8

    val refillsToOneBank = (2*(io.cbusResp.data.getWidth) == wordBits) //false


    val s0Valid = io.req.fire  //发射
    val s0Vaddr = io.req.bits.addr //虚拟地址

    val s1Valid = RegNext(s0Valid) //s1有效
    val s1TagHit = Wire(Vec(iParams.nWays,Bool())) //s1每一路的命中情况
    val s1Hit = s1TagHit.reduce(_||_) //出现命中
    
    val s2Valid = RegNext(s1Valid && !io.s1_kill) //s2有效当且仅当s1有效且没有被kill
    val s2Hit = RegNext(s1Hit) 

    val invalidated = Reg(Bool()) //清空整个icache
    val refillValid = RegInit(false.B) 
    val refillFire = io.cbusReq.valid //&& cbusReq.ready
    val s2Miss = s2Valid && !s2Hit && !RegNext(refillValid)
    val refillPaddr = RegEnable(io.s1_paddr , s1Valid && !(refillValid || s2Miss))
    val refillTag = refillPaddr(iParams.tagBits + iParams.untagBits-1,iParams.untagBits)
    val refillIdx = refillPaddr(iParams.untagBits-1,iParams.blockOffBits)
    val refillOneBeat = io.cbusReq.valid && io.cbusResp.ready
        //tl_out.d.fire && edge_out.hasData(tl_out.d.bits)

    io.req.ready := !refillOneBeat

    val dDone = io.cbusResp.ready && io.cbusResp.isLast
    val refillCnt = RegInit(0.U(4.W)) //和refillCycles
    when(refillOneBeat){
        refillCnt := refillCnt + 1.U
    }
    when(dDone){
        refillCnt := 0.U
    }
    //val (_, _, dDone, refillCnt) = edge_out.count(tl_out.d)
    val refillDone = refillOneBeat && dDone

    val replWay = LFSR(16,refillFire)(log2Ceil(iParams.nWays)-1,0)

    val tagArray = SyncReadMem(iParams.nSets,Vec(iParams.nWays,UInt(iParams.tagBits.W)))
    val tagRData = tagArray.read(s0Vaddr(iParams.untagBits-1,iParams.blockOffBits),!refillDone && s0Valid)
    when(refillDone){
        tagArray.write(refillIdx,VecInit(Seq.fill(iParams.nWays)(refillTag)),Seq.tabulate(iParams.nWays)(replWay === _.U))
    }

    val vbArray = RegInit(0.U((iParams.nSets*iParams.nWays).W))
    when(refillOneBeat){
        vbArray := vbArray.bitSet(Cat(replWay,refillIdx),refillDone && !invalidated)

    }

    when(io.invalidate) {
        vbArray := 0.U
        invalidated := true.B
    }

    val s2Dout = Wire(Vec(iParams.nWays,UInt(wordBits.W)))
    val s1Bankid = Wire(Bool())

    for(i <- 0 until iParams.nWays){
        val s1Idx = io.s1_paddr(iParams.untagBits-1,iParams.blockOffBits)
        val s1Tag = io.s1_paddr(iParams.tagBits + iParams.untagBits -1,iParams.untagBits)
        val s1Vb = vbArray(Cat(i.U,s1Idx))
        val tag = tagRData(i)
        s1TagHit(i) := s1Vb && tag === s1Tag
    }
    
    val ramDepth = if(refillsToOneBank){
        iParams.nSets * iParams.refillCycles /2
    }else{
        iParams.nSets * iParams.refillCycles
    }

    //nBanks == 2 
    val dataArrays =
        (0 until iParams.nWays).map{
            x=>DescribedSRAM(
                name = s"dataArrayB0Way_${x}",
                desc = "ICache Data Array",
                size = ramDepth,
                data = UInt((wordBits/nBanks).W)
            )
        } ++
        (0 until iParams.nWays).map{
            x=>DescribedSRAM(
                name = s"dataArrayB1Way_${x}",
                desc = "ICache Data Array",
                size = ramDepth,
                data = UInt((wordBits/nBanks).W)
            )
        }

    //nBanks == 2 

    val dataArrayB0 = dataArrays.take(iParams.nWays)
    val dataArrayB1 = dataArrays.drop(iParams.nWays)

    def b0Row(addr: UInt) =
        if (refillsToOneBank){
            addr(iParams.untagBits-1,iParams.blockOffBits - log2Ceil(iParams.refillCycles)+1) + bank(addr)
        } else {
            addr(iParams.untagBits-1, iParams.blockOffBits-log2Ceil(iParams.refillCycles)) + bank(addr)
        }

    def b1Row(addr: UInt) =
        if (refillsToOneBank) {
            addr(iParams.untagBits-1, iParams.blockOffBits-log2Ceil(iParams.refillCycles)+1)
        } else {
            addr(iParams.untagBits-1, iParams.blockOffBits-log2Ceil(iParams.refillCycles))
        }
    
    s1Bankid := RegNext(bank(s0Vaddr))

    for(i <- 0 until iParams.nWays){
        val s0Ren = s0Valid
        val wen = (refillOneBeat && !invalidated) && replWay ===i.U

        var memIdx0: UInt = null
        var memIdx1: UInt = null

        if(refillsToOneBank){
            //只写一个bank；
            memIdx0 = Mux(refillOneBeat,((refillIdx << (log2Ceil(iParams.refillCycles)-1)) | (refillCnt >> 1.U)),
                b0Row(s0Vaddr))
            memIdx1 =Mux(refillOneBeat, ((refillIdx << (log2Ceil(iParams.refillCycles)-1)) | (refillCnt >> 1.U)),
                b1Row(s0Vaddr))

            when (wen && refillCnt(0) === 0.U){
                dataArrayB0(i).write(memIdx0,io.cbusResp.data)
            }
            when (wen && refillCnt(0) === 1.U){
                dataArrayB1(i).write(memIdx1,io.cbusResp.data)
            }
        } else {
            //写两个bank
            memIdx0 = Mux(refillOneBeat,(refillIdx << log2Ceil(iParams.refillCycles)) | refillCnt,
                b0Row(s0Vaddr))
            memIdx1 = Mux(refillOneBeat, (refillIdx << log2Ceil(iParams.refillCycles)) | refillCnt,
                b1Row(s0Vaddr))

            when (wen) {
                val data = io.cbusResp.data
                dataArrayB0(i).write(memIdx0,data(wordBits/2-1, 0))
                dataArrayB1(i).write(memIdx1,data(wordBits-1,wordBits/2))
            }
        }
    

        s2Dout(i) := RegNext(Cat(dataArrayB1(i).read(memIdx1,!wen && s0Ren),
                                    dataArrayB0(i).read(memIdx0, !wen && s0Ren)))
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


    //tl_out.a.valid := s2_miss && !refill_valid && !io.s2_kill
    //tl_out.a.bits := edge_out.Get(
    //fromSource = 0.U,
    //toAddress = (refill_paddr >> blockOffBits) << blockOffBits,
    //lgSize = lgCacheBlockBytes.U)._2
    //tl_out.b.ready := true.B
    //tl_out.c.valid := false.B
    //tl_out.e.valid := false.B

    io.cbusReq.valid := s2Miss && !refillValid && !io.s2_kill
    io.cbusReq.isWrite := false.B
    io.cbusReq.size := 1.U(2.W)
    io.cbusReq.addr := (refillPaddr >> iParams.blockOffBits) << iParams.blockOffBits
    io.cbusReq.mask := 0.U
    io.cbusReq.axiBurstType := 1.U
    io.cbusReq.axiLen := iParams.refillCycles.U
    
    //io.perf.acquire := tl_out.a.fire

    when (!refillValid) { invalidated := false.B }
    when (refillFire) { refillValid := true.B }
    when (refillDone) { refillValid := false.B }

}