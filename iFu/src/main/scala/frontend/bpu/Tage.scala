package iFu.frontend.predictors

import chisel3._
import chisel3.util._
import iFu.frontend.predictors._

import scala.math.min

val vaddrBits = 32
val bankWidth = 4
val fetchWidth = 8
val nBanks = 2
val localHistoryLength = 16
val maxMetaLength = 16
val fetchBytes = 32
val globalHistoryLength = 16
val nSets = 16

val nWrBypassEntries = 2

val nWays = 4

val tageNTables = 6

def fetchIdx(addr: UInt) = addr >> log2Ceil(fetchBytes)

def WrapInc(x: UInt, max: UInt) = Mux(x === max, 0.U, x + 1.U)

object MaskLower
{
  def apply(in: UInt) = {
    val n = in.getWidth
    (0 until n).map(i => in >> i.U).reduce(_|_)
  }
}

class TageResp extends Bundle {
    val u = UInt(2.W)
    val ctr = UInt(3.W)
}

class TageEntry extends Bundle {
    val tag = UInt(tagSz.W)
    val ctr = UInt(3.W)
    val valid = Bool()
}



class TagePredictMeta extends Bundle {
    val provider      = Vec(bankWidth, Valid(UInt(log2Ceil(tageNTables).W)))
    val altDiffers   = Vec(bankWidth, Output(Bool()))
    val providerU    = Vec(bankWidth, Output(UInt(2.W)))
    val providerCtr  = Vec(bankWidth, Output(UInt(3.W)))
    val allocate      = Vec(bankWidth, Valid(UInt(log2Ceil(tageNTables).W)))
}

class TageTable(val nRows: Int, val tagSz: Int, val histLength: Int, val uBitPeriod: Int)
{
    val io = IO(new Bundle{
        val f1valid = Input(Bool())
        val f1PC = Input(UInt(vaddrBits.W))
        val f1gHist = Input(UInt(globalHistoryLength.W))

        val f3resp = Output(Vec(bankWidth, Valid(new TageResp)))

        val updateMask = Input(Vec(bankWidth, Bool()))
        val updateTaken = Input(Vec(bankWidth, Bool()))
        val updateAlloc = Input(Vec(bankWidth, Bool()))
        val updateOldCtr = Input(Vec(bankWidth, UInt(3.W)))

        val updatePC = Input(Uint)
        val updateHist = Input(UInt(globalHistoryLength.W))

        val updateUMask = Input(Vec(bankWidth, Bool()))
        val updateU = Input(Vec(bankWidth, UInt(2.W)))
    }) 

    def computeFoldedHist(hist: UInt, l: Int) = {
    val nChunks = (histLength + l - 1) / l
    val hist_chunks = (0 until nChunks) map {i =>
      hist(min((i+1)*l, histLength)-1, i*l)
    }
    hist_chunks.reduce(_^_)
    }

    def computeTagandHash(unhashed_idx: UInt, hist: UInt) = {
        val idx_history = compute_folded_hist(hist, log2Ceil(nRows))
        val idx = (unhashed_idx ^ idx_history)(log2Ceil(nRows)-1,0)
        val tag_history = compute_folded_hist(hist, tagSz)
        val tag = ((unhashed_idx >> log2Ceil(nRows)) ^ tag_history)(tagSz-1,0)
        (idx, tag)
    }

    def inc_ctr(ctr: UInt, taken: Bool): UInt = {
    Mux(!taken, Mux(ctr === 0.U, 0.U, ctr - 1.U),
                Mux(ctr === 7.U, 7.U, ctr + 1.U))
    }

    val reseting = RegInit(true.B)
    val resetIdx = RegInit(0.U(log2Ceil(nSets).W))
    when(reseting){
        resetIdx := resetIdx + 1.U
    }
    when(resetIdx === (nSets-1).U){
        reseting := false.B
    }

    val tageEntrySz = tagSz + 1 + 3

    val (s1HashIdx , s1tag) = computeTagandHash(fetchIdx(io.f1PC),io.f1gHist)

    val HIU = SyncReadMem(nRows,Vec(bankWidth, Bool()))
    val LOU  = SyncReadMem(nRows, Vec(bankWidth, Bool()))
    val table  = SyncReadMem(nRows, Vec(bankWidth, TageEntry()))

    val s2tag = RegNext(s1tag)

    val s2rtage = VecInit(table.read(s1HashIdx,f1valid))
    val s2rHIU = VecInit(HIU.read(s1HashIdx,f1valid))
    val s2rLOU = VecInit(LOU.read(s1HashIdx,f1valid))
    val s2rhits = VecInit(s2rtage.map(t => t.valid && t.tag === s2tag))

    for (w <- 0 until bankWidth){
        io.f3resp(w).valid := RegNext(s2rhits(w))
        io.f3resp(w).ctr := RegNext(s2rtage(w).ctr)
        io.f3resp(w).u := RegNext(Cat(s2rHIU(w),s2rLOU(w)))
    }

    val clearUCnt = RegInit(0.U((log2Ceil(uBitPeriod) + log2Ceil(nRows) +1).W))
    when (reseting){
        clearUCnt := 1.U
    }.otherwise{
        clearUCnt := clearUCnt + 1.U
    }

    val ClearingU = clearUCnt(log2Ceil(uBitPeriod) - 1 , 0 ) === 0.U
    val ClearingHIU = ClearingU && clearUCnt(log2Ceil(uBitPeriod) + log2Ceil(nRows)) === 1.U
    val ClearingLOU = ClearingU && clearUCnt(log2Ceil(uBitPeriod) + log2Ceil(nRows)) === 0.U
    val ClearingUIdx = ClearUCnt >> log2Ceil(uBitPeriod)

    val ( updateIdx , upDatetag ) = computeTagandHash(fetchIdx(io.updatePC),io.updateHist)

    val updatewData = Wire(Vec(bankWidth, new TageEntry()))
    val updateHIwData = Wire(Vec(bankWidth, Bool()))
    val updateLOwData = Wire(Vec(bankWidth, Bool()))

    when(reseting){
        table.write(
        resetIdx,
        VecInit(Seq.fill(bankWidth)(0.U.asTypeOf(new TageEntry()))),
        VecInit(Seq.fill(bankWidth)(true.B))
        )  
        HIU.write(
        resetIdx,
        VecInit(Seq.fill(bankWidth)(false.B)),
        VecInit(Seq.fill(bankWidth)(true.B))
        )
        LOU.write(
        resetIdx,
        VecInit(Seq.fill(bankWidth)(false.B)),
        VecInit(Seq.fill(bankWidth)(true.B))
        )
    }.elsewhen(ClearingHIU||ClearingLOU){
        when(ClearingHIU){
            HIU.write(
            ClearingUIdx,
            VecInit(Seq.fill(bankWidth)(false.B)),
            VecInit(Seq.fill(bankWidth)(true.B))
            )
        }
        when(ClearingLOU){
            LOU.write(
            ClearingUIdx,
            VecInit(Seq.fill(bankWidth)(false.B)),
            VecInit(Seq.fill(bankWidth)(true.B))
            )
        }
    }.otherwise{
        table.write(
        updateIdx,
        updatewData,
        io.updateMask
        )
        HIU.write(
        updateIdx,
        updateHIwData,
        io.updateUMask
        )
        LOU.write(
        updateIdx,
        updateLOwData,
        io.updateUMask
        )
    }

    wrBypassTag = Reg(Vec(nWrBypassEntries, UInt(tagSz.W)))
    wrBypassIdx = Reg(Vec(nWrBypassEntries, UInt(log2Ceil(nRows).W)))
    wrBypass = Reg(Vec(nWrBypassEntries, Vec(bankWidth, UInt(3.W))))
    wrBypassEnqIdx = RegInit(0.U(log2Ceil(nWrBypassEntries).W))

    val wrBypassHits = VecInit((0 until nWrBypassEntries) map {i =>
        !reseting &&
        wrBypassIdx(i) === updateIdx &&
        wrBypassTag(i) === upDatetag
    })

    val wrBypassHit = wrBypassHits.reduce(_||_)
    val wrBypassHitIdx = PriorityEncoder(wrBypassHits)

    for(w <- 0 until bankWidth){
        updatewData(w).ctr := Mux(io.updateAlloc(w),

            Mux(io.updateTaken(w), 4.U, 3.U),

            Mux(wrBypassHit,
            inc_ctr(wrBypass(wrBypassHitIdx)(w), io.updateTaken(w)),
            inc_ctr(io.updateOldCtr(w), io.updateTaken(w)))
            )

        updatewData(w).valid := true.B
        updatewData(w).tag := upDatetag
        updateHIwData(w) := io.updateU(w)(1)
        updateLOwData(w) := io.updateU(w)(0)
    }

    when(io.updateMask.reduce(_||_)){
        when (wrBypassHit){
            wrBypass(wrBypassHitIdx) := VecInit(updatewData.map(_.ctr))
        }.otherwise{
            wrBypass(wrBypassEnqIdx) := VecInit(updatewData.map(_.ctr))
            wrBypassTag(wrBypassEnqIdx) := upDatetag
            wrBypassIdx(wrBypassEnqIdx) := updateIdx
            wrBypassEnqIdx := WrapInc(wrBypassEnqIdx, nWrBypassEntries.U)
        }
    }

}


case class TageParams(
    //                                           nSets, tagSz, histLength
    tableInfo: Seq[Tuple3[Int,Int,Int]] = Seq(  ( 128,    7,        2),
                                                ( 128,    7,        4),
                                                ( 256,    8,        8),
                                                ( 256,    8,        16),
                                                ( 128,    9,        32),
                                                ( 128,    9,        64)),
    uBitPeriod: Int = 2048
)


class TagePredictor(params: BoomTageParams = BoomTageParams()){
    
    val io = IO(new Bundle{
        val f1valid = Input(Bool())
        val f1PC = Input(UInt(vaddrBits.W))
        val f1gHist = Input(UInt(globalHistoryLength.W))

        val f1update = Input(Valid(new UpdateInfo))

        val f3meta = Output(new TagePredictMeta)
        val f3taken = Output(Vec(bankWidth, Bool()))

        val previousf3Taken = Input(Vec(bankWidth, Bool()))
    })


    val tageUBitPeriod = params.uBitPeriod
    val tageNTables = params.tableInfo.size

    val tageTables = params.tableInfo.map{
        case (nRows, tagSz, histLength) => {
            val t = Module(new TageTable(nRows, tagSz, histLength, tageUBitPeriod))
            t.io.f1valid := io.f1valid
            t.io.f1PC := io.f1PC
            t.io.f1gHist := io.f1gHist

            t
        }
    }

    val tableResps = VecInit(tageTables.map(_.io.f3resp))

    val s1updateMeta = io.f1update.bits.meta.tageMeta
    val s1updateMispredictMask = UIntToOH(io.f1update.bits.cfiIdx.bits)&
        Fill(bankWidth,io.f1update.bits.cfiMispredicted)

    val s1updateMask = WireInit(0.U.asTypeOf(Vec(tageNTables, Vec(bankWidth, Bool()))))
    val s1updateUMask = WireInit(0.U.asTypeOf(Vec(tageNTables, Vec(bankWidth, true.B))))

    val s1updateTaken = Wire(Vec(tageNTables, Vec(bankWidth, Bool())))
    val s1updateOldCtr = Wire(Vec(tageNTables, Vec(bankWidth, UInt(3.W))))
    val s1updateAlloc = Wire(Vec(tageNTables, Vec(bankWidth, Bool())))
    val s1updateU = Wire(Vec(tageNTables, Vec(bankWidth, UInt(2.W))))

    s1updateTaken := DontCare
    s1updateOldCtr := DontCare
    s1updateAlloc := DontCare
    s1updateU := DontCare

    for (w <- 0 until bankWidth){
        var altPred = previousf3Taken(w)
        var final_altpred = WireInit(previousf3Taken(w))
        var provided =false.B
        var provider = 0.U

        io.f3taken(w) := previousf3Taken(w)

        for (i <- until tageNTables) {
            val hit = f3resp(i)(w).valid
            val ctr = f3resp(i)(w).ctr
            when(hit){
                io.f3taken(w) := Mux( ctr === 3.U || ctr === 4.U, altPred , ctr(2))
                final_altpred := altPred
            }

            provided = provided || hit
            provider = Mux(hit, i.U, provider)
            altPred = Mux(hit, ctr(2), altPred)
        }

        f3meta.provider(w).valid := provided
        f3meta.provider(w).bits := provider
        f3meta.altDiffers(w) := final_altpred =/= io.f3taken(w)
        f3meta.providerU(w) := f3resp(provider)(w).bits.u
        f3meta.providerCtr(w) := f3resp(provider)(w).bits.ctr

        // 如果有表找到，就标记比找到结果的最大的表还大的那些表，而且对应行的u位都是0
        val allocatableSlots = (
            VecInit(f3resp.map(r => !r(w).valid && r(w).bits.u === 0.U)).asUInt &
            ~(MaskLower(UIntToOH(provider))& Fill(tageNTables, provided.B))
        )

        val allocLFSR = random.LFSR(tageNTables max 2)

        val firstEntry = PriorityEncoder(allocatableSlots)
        val maskedEntry = PriorityEncoder(allocatableSlots & allocLFSR)
        val allocEntry = Mux(allocatableSlots(maskedEntry),
            maskedEntry,
            firstEntry
        )

        f3meta.allocate(w).valid := allocatableSlots.orR
        f3meta.allocate(w).bits := allocEntry

        val updateWasTaken = (
            io.f1update.bits.cfiIdx.valid &&
            ( io.f1update.bits.cfiIdx.bits === w.U )&&
            io.f1update.bits.cfiTaken
        )

        when (io.f1update.bits.brMask(w) && io.f1update.valid && io.f1update.bits.isCommitUpdate){
            when (s1updateMeta.provider(w).valid){
                val provider = s1updateMeta.provider(w).bits

                s1updateMask(provider)(w) := true.B
                s1updateUMask(provider)(w) := true.B

                val new_u = inc_u(  s1updateMeta.providerU(w), 
                                    s1updateMeta.altDiffers(w),
                                    updateWasTaken)
                
                s1updateU(provider)(w) := new_u
                s1updateTaken(provider)(w) := updateWasTaken
                s1updateOldCtr(provider)(w) := s1updateMeta.providerCtr(w)
                s1updateAlloc(provider)(w) := false.B
            }
        }
    }

    when (s1update.valid && s1update.bits.isCommitUpdate && s1update.bits.cfi_idx.valid){
        val idx = s1update.bits.cfi_idx.bits
        val allocate = s1updateMeta.allocate(idx)

        when (allocate.valid){
            s1updateMask(allocate.bits)(idx) := true.B
            s1updateUMask(allocate.bits)(idx) := true.B
            s1updateU(allocate.bits)(idx) := 0.U
            s1updateTaken(allocate.bits)(idx) := s1update.bits.cfi_taken
            s1updateAlloc(allocate.bits)(idx) := true.B
        } .otherwise{
            val provider = s1updateMeta.provider(idx)
            val decrMask = Mux(provider.valid, ~MaskLower(UIntToOH(provider.bits)), 0.U)

            for (i <- 0 until tageTables){
                when (decrMask){
                    s1updateUMask(i)(idx) := true.B
                    s1updateU (i)(idx) := 0.U
                }
            }
        }
    }


    for (i <- 0 until tageTables){
        for ( w <- 0 until bankWidth){
            tables(i).io.updateMask(w) := RegNext(s1updateMask(i)(w))
            
            tables(i).io.updateTaken(w) := RegNext(s1updateTaken(i)(w))
            tables(i).io.updateOldCtr(w) := RegNext(s1updateOldCtr(i)(w))
            tables(i).io.updateAlloc(w) := RegNext(s1updateAlloc(i)(w))

            tables(i).io.updateU(w) := RegNext(s1updateU(i)(w))
            tables(i).io.updateUMask(w) := RegNext(s1updateUMask(i)(w))
        }

        tables(i).io.updatePC := RegNext(io.f1update.bits.pc)
        tables(i).io.updateHist := RegNext(io.f1update.bits.gHist)
    }

    io.f3meta := f3meta

}



