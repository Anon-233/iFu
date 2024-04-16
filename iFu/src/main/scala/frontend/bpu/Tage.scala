package iFu.frontend

import chisel3._
import chisel3.util._
import iFu.frontend.FrontendUtils._
import iFu.util._
import scala.math.min



// 传出去的Meta
class TagePredictMeta extends Bundle with HasTageParameters{
    val provider      = Valid(UInt(log2Ceil(tageNTables).W))
    val altDiffers   = Output(Bool())
    val providerU    = Output(UInt(2.W))
    val providerCtr  = Output(UInt(3.W))
    val allocate      = Valid(UInt(log2Ceil(tageNTables).W))
}

// 单个表的定义
class TageTable(val nRows: Int, val tagSz: Int, val histLength: Int, val uBitPeriod: Int) 
        extends Module with HasTageParameters 
{

    val io = IO(new Bundle{
        val f1valid = Input(Bool())
        val f1pc = Input(UInt(vaddrBits.W))
        val f1gHist = Input(UInt(globalHistoryLength.W))

        val f3resp = Output(Vec(bankWidth, Valid(new TageResp)))

        val updateMask = Input(Vec(bankWidth, Bool()))
        val updateTaken = Input(Vec(bankWidth, Bool()))
        val updateAlloc = Input(Vec(bankWidth, Bool()))
        val updateOldCtr = Input(Vec(bankWidth, UInt(3.W)))

        val updatepc = Input(UInt(vaddrBits.W))
        val updateHist = Input(UInt(globalHistoryLength.W))

        val updateUMask = Input(Vec(bankWidth, Bool()))
        val updateU = Input(Vec(bankWidth, UInt(2.W)))
    }) 

    // 单个表返回类型
    class TageResp extends Bundle {
    val u = UInt(2.W)
    val ctr = UInt(3.W)
    }

    // 单个表的行的定义
    class TageEntry extends Bundle {
        val tag = UInt(tagSz.W)
        val ctr = UInt(3.W)
        val valid = Bool()
    }

    val tageEntrySz = tagSz + 1 + 3

    // 通过全局历史和表的行数，计算出折叠后的历史
    def computeFoldedHist(hist: UInt, l: Int): UInt = {
        val nChunks = (globalHistoryLength + l - 1) / l
        val hist_chunks = (0 until nChunks) map { i =>
            hist(min((i + 1) * l, globalHistoryLength) - 1, i * l)
        }
        hist_chunks.reduce(_ ^ _)
    }

    // 通过pc和全局历史计算出行号和tag
    def computeTagandHash(unhashed_idx: UInt, hist: UInt): (UInt, UInt) = {
        val idx_history = computeFoldedHist(hist, log2Ceil(nRows))
        val idx = (unhashed_idx ^ idx_history)(log2Ceil(nRows) - 1, 0)
        val tag_history = computeFoldedHist(hist, tagSz)
        val tag = ((unhashed_idx >> log2Ceil(nRows)).asUInt ^ tag_history)(tagSz - 1, 0)
        (idx, tag)
    }

// ctr的更新
    def inc_ctr(ctr: UInt, taken: Bool): UInt = {
    Mux(!taken, Mux(ctr === 0.U, 0.U, ctr - 1.U),
                Mux(ctr === 7.U, 7.U, ctr + 1.U))
    }

// 初始化
    val reseting = RegInit(true.B)
    val resetIdx = RegInit(0.U(log2Ceil(nRows).W))
    when(reseting){
        resetIdx := resetIdx + 1.U
    }
    when(resetIdx === (nRows-1).U){
        reseting := false.B
    }

    val (s1HashIdx , s1tag) = computeTagandHash(fetchIdx(io.f1pc).asUInt,io.f1gHist)


// 存储结构
    // 存储高位和低位的u位
    val HIU = SyncReadMem(nRows,Vec(bankWidth, Bool()))
    val LOU  = SyncReadMem(nRows, Vec(bankWidth, Bool()))

    // 存储表项的行
    val table  = SyncReadMem(nRows, Vec(bankWidth, UInt(tageEntrySz.W)))

    val s2tag = RegNext(s1tag)


    // 根据s1的信息,在s2读出各信息,同时判断命中情况
    val s2rtage = VecInit( table.read(s1HashIdx,io.f1valid).map(_.asTypeOf(new TageEntry)) )
    val s2rHIU = HIU.read(s1HashIdx,io.f1valid)
    val s2rLOU = LOU.read(s1HashIdx,io.f1valid)
    val s2rhits = VecInit(s2rtage.map(t => t.valid && t.tag === s2tag))

// f3阶段返回给外面预测结果
    for (w <- 0 until bankWidth){
        io.f3resp(w).valid := RegNext(s2rhits(w))
        io.f3resp(w).bits.ctr := RegNext(s2rtage(w).ctr)
        io.f3resp(w).bits.u := RegNext(Cat(s2rHIU(w),s2rLOU(w)))
    }

// 清除u位的计数器
    val clearUCnt = RegInit(0.U((log2Ceil(uBitPeriod) + log2Ceil(nRows) +1).W))
    when (reseting){
        clearUCnt := 1.U
    }.otherwise{
        clearUCnt := clearUCnt + 1.U
    }

// 这里用到的uBitPeriod是一个全局参数，表示多少个周期清除一次u位
    val clearingU = clearUCnt(log2Ceil(uBitPeriod) - 1 , 0 ) === 0.U
    val clearingHIU = clearingU && clearUCnt(log2Ceil(uBitPeriod) + log2Ceil(nRows)) === 1.U
    val clearingLOU = clearingU && clearUCnt(log2Ceil(uBitPeriod) + log2Ceil(nRows)) === 0.U
    val clearingUIdx = clearUCnt >> log2Ceil(uBitPeriod)

    val ( updateIdx , upDatetag ) = computeTagandHash(fetchIdx(io.updatepc).asUInt,io.updateHist)

    val updatewData = Wire(Vec(bankWidth, new TageEntry()))
    val updateHIwData = Wire(Vec(bankWidth, Bool()))
    val updateLOwData = Wire(Vec(bankWidth, Bool()))

    table.write(
        Mux(reseting, resetIdx, updateIdx),
        Mux(reseting, VecInit(Seq.fill(bankWidth)(0.U(tageEntrySz.W))), VecInit(updatewData.map(_.asUInt))),
        Mux(reseting, VecInit(Seq.fill(bankWidth)(true.B)), io.updateMask)
    )
    HIU.write(
        Mux(reseting,   resetIdx, 
        Mux(clearingHIU,clearingUIdx.asUInt,
                        updateIdx)),

        Mux(reseting,   VecInit(Seq.fill(bankWidth)(false.B)),
        Mux(clearingHIU,VecInit(Seq.fill(bankWidth)(false.B)),
                        updateHIwData)),
        
        Mux(reseting,   VecInit(Seq.fill(bankWidth)(true.B)),
        Mux(clearingHIU,VecInit(Seq.fill(bankWidth)(true.B)),
                        io.updateUMask))
    )

    LOU.write(
        Mux(reseting,   resetIdx, 
        Mux(clearingLOU,clearingUIdx.asUInt,
                        updateIdx)),

        Mux(reseting,   VecInit(Seq.fill(bankWidth)(false.B)),
        Mux(clearingLOU,VecInit(Seq.fill(bankWidth)(false.B)),
                        updateLOwData)),
        
        Mux(reseting,   VecInit(Seq.fill(bankWidth)(true.B)),
        Mux(clearingLOU,VecInit(Seq.fill(bankWidth)(true.B)),
                        io.updateUMask))
    )

    //此外设置wrBypass,由于表里面信息以mem存储,主要用于解决WAR冲突

    val wrBypassTag = Reg(Vec(nWrBypassEntries, UInt(tagSz.W)))
    val wrBypassIdx = Reg(Vec(nWrBypassEntries, UInt(log2Ceil(nRows).W)))
    val wrBypass = Reg(Vec(nWrBypassEntries, Vec(bankWidth, UInt(3.W))))
    val wrBypassEnqIdx = RegInit(0.U(log2Ceil(nWrBypassEntries).W))

    val wrBypassHits = VecInit((0 until nWrBypassEntries) map {i =>
        !reseting &&
        wrBypassIdx(i) === updateIdx &&
        wrBypassTag(i) === upDatetag
    })

    val wrBypassHit = wrBypassHits.reduce(_||_)
    val wrBypassHitIdx = PriorityEncoder(wrBypassHits)

    for(w <- 0 until bankWidth){
        updatewData(w).ctr := Mux(io.updateAlloc(w),
            // 如果它是被分配要写入的,ctr需要初始化
            Mux(io.updateTaken(w), 4.U, 3.U),

            // 否则进行更新
            // 这里涉及到了u位的更新,是要基于最新的u信息,如果本周期更新信号前面有什么update的信息改变了u,这时
            // 由于读写延迟1周期,此时可以获取到的最新的信息一定存在于wrBypass里面,所以要从wrBypass里面读取
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
        // 更新信息传来,如果有命中,把wrbypass中他那一项一起更新了
        when (wrBypassHit){
            wrBypass(wrBypassHitIdx) := VecInit(updatewData.map(_.ctr))

        // 如果没有命中,就把它放到wrBypass里面以备之后的冲突使用
        }.otherwise{
            wrBypass(wrBypassEnqIdx) := VecInit(updatewData.map(_.ctr))
            wrBypassTag(wrBypassEnqIdx) := upDatetag
            wrBypassIdx(wrBypassEnqIdx) := updateIdx
            wrBypassEnqIdx := WrapInc(wrBypassEnqIdx, nWrBypassEntries)
        }
    }

}


case class TageParams(
    //                                           nRows, tagSz, histLength
    // tableInfo: Seq[Tuple3[Int,Int,Int]] = Seq(  ( 128,    7,        2),
    //                                             ( 128,    7,        4),
    //                                             ( 256,    8,        8),
    //                                             ( 256,    8,        16),
    //                                             ( 128,    9,        32),
    //                                             ( 128,    9,        64))
    tableInfo: Seq[Tuple3[Int,Int,Int]] = Seq(  ( 32,    7,        2),
                                                ( 32,    7,        4),
                                                ( 64,    8,        8),
                                                /* ( 64,    8,        16), */
                                                ( 32,    9,        32)
                                                /* ( 32,    9,        64) */)
)


class TagePredictor(params: TageParams = TageParams())extends Module with HasTageParameters{
    
    val io = IO(new Bundle{
        val f1valid = Input(Bool())
        val f1pc = Input(UInt(vaddrBits.W))
        val f1gHist = Input(UInt(globalHistoryLength.W))

        val f1update = Input(Valid(new BankedUpdateInfo))

        val f3meta = Output(Vec (bankWidth , new TagePredictMeta))
        val f3taken = Output(Vec(bankWidth, Bool()))

        val previousf3Taken = Input(Vec(bankWidth, Bool()))
    })

    def inc_u(u: UInt, alt_differs: Bool, mispredict: Bool): UInt = {
    Mux(!alt_differs, u,
    Mux(mispredict, Mux(u === 0.U, 0.U, u - 1.U),
                    Mux(u === 3.U, 3.U, u + 1.U)))
    }

    val clockcnt = RegInit((0.U)(10.W))
    clockcnt := clockcnt + 1.U

// 多个表,越往后的表信息越完善置信度越高
    val tageTables = params.tableInfo.map{
        case (nRows, tagSz, histLength) => {
            val t = Module(new TageTable(nRows, tagSz, histLength, tageUBitPeriod))
            t.io.f1valid := io.f1valid
            t.io.f1pc := io.f1pc
            t.io.f1gHist := io.f1gHist
            t
        }
    }

    val tableResps = VecInit(tageTables.map(_.io.f3resp))

    val s1updateMeta = VecInit(io.f1update.bits.meta.map(_.tageMeta))
    val s1updateMispredictMask = UIntToOH(io.f1update.bits.cfiIdx.bits)&
        Fill(bankWidth,io.f1update.bits.cfiMispredicted)

    val s1updateMask = WireInit(0.U.asTypeOf(Vec(tageNTables, Vec(bankWidth, Bool()))))
    val s1updateUMask = WireInit(0.U.asTypeOf(Vec(tageNTables, Vec(bankWidth, Bool()))))

    val s1updateTaken = Wire(Vec(tageNTables, Vec(bankWidth, Bool())))
    val s1updateOldCtr = Wire(Vec(tageNTables, Vec(bankWidth, UInt(3.W))))
    val s1updateAlloc = Wire(Vec(tageNTables, Vec(bankWidth, Bool())))
    val s1updateU = Wire(Vec(tageNTables, Vec(bankWidth, UInt(2.W))))

    s1updateTaken := DontCare
    s1updateOldCtr := DontCare
    s1updateAlloc := DontCare
    s1updateU := DontCare

    val f3meta = Wire(Vec(bankWidth , new TagePredictMeta))

    for (w <- 0 until bankWidth){

        // 可供选择的预测信息
        var altPred = io.previousf3Taken(w)
        // 如果有表命中,最后面那个表预测时,给他提供的一个可选择的预测信息
        var final_altpred = WireInit(io.previousf3Taken(w))
        var provided =false.B
        var provider = 0.U

        io.f3taken(w) := io.previousf3Taken(w)

        for (i <- 0 until tageNTables) {
            val hit = tableResps(i)(w).valid
            val ctr = tableResps(i)(w).bits.ctr
            when(hit){
                // 3或4太过中间值,置信度不高,故采取备选项altPred , 其他情况的话就使用ctr(2)作为预测(567和012)
                io.f3taken(w) := Mux( ctr === 3.U || ctr === 4.U, altPred , ctr(2))
                final_altpred := altPred
            }
            // 记录是否有表项命中
            provided = provided || hit
            // 记录最后一个命中表项的表号,
            provider = Mux(hit, i.U, provider)
            // 作为备选项,如果有命中他每次提供的都是最近的前一个命中表号,如果没有就是previousf3Taken,也即预测前的值
            altPred = Mux(hit, ctr(2), altPred)
        }

        
        // 完善meta信息
        f3meta(w).provider.valid := provided
        f3meta(w).provider.bits := provider
        f3meta(w).altDiffers := final_altpred =/= io.f3taken(w)
        f3meta(w).providerU := tableResps(provider)(w).bits.u
        f3meta(w).providerCtr := tableResps(provider)(w).bits.ctr

        // 如果有表找到作为最终的provider，那么同时意味着这个表之后的更大的表都没有命中，所以这个表之后的表都可以被分配
        // 分配位置的条件是：1.表没有命中 2.表的u位为0 3.表不是provider
        val allocatableSlots = (
            VecInit(tableResps.map(r => !r(w).valid && r(w).bits.u === 0.U)).asUInt &
              (~(MaskLower(UIntToOH(provider))& Fill(tageNTables, provided))).asUInt
        )

        // 可分配位置的方式是：
        //  1.如果有多个位置可供选择，那么优先选择被分配过的位置
        //  2.如果没有被分配过的位置，那么随机选择一个位置
        val allocLFSR = random.LFSR(tageNTables max 2)

        val firstEntry = PriorityEncoder(allocatableSlots)
        val maskedEntry = PriorityEncoder(allocatableSlots & allocLFSR)
        val allocEntry = Mux(allocatableSlots(maskedEntry),
            maskedEntry,
            firstEntry
        )

        f3meta(w).allocate.valid := allocatableSlots.orR
        f3meta(w).allocate.bits := allocEntry

        // 更新所使用的wasTaken信号
        val updateWasTaken = (
            io.f1update.bits.cfiIdx.valid &&
            ( io.f1update.bits.cfiIdx.bits === w.U )&&
            io.f1update.bits.cfiTaken
        )

    // 对包里面的跳转指令并且是发生了commit的指令进行有关信息更新
        when (io.f1update.bits.brMask(w) && io.f1update.valid && io.f1update.bits.isCommitUpdate){

            // 如果当时确实找到了一个provider表,那么就更新这个表对应的信息
            when (s1updateMeta(w).provider.valid){
                val provider = s1updateMeta(w).provider.bits

                s1updateMask(provider)(w) := true.B
                s1updateUMask(provider)(w) := true.B
                // 更新u位
                val new_u = inc_u(  s1updateMeta(w).providerU, 
                                    s1updateMeta(w).altDiffers,
                                    updateWasTaken)
                
                s1updateU(provider)(w) := new_u
                // 更新Taken信息,ctr
                s1updateTaken(provider)(w) := updateWasTaken
                s1updateOldCtr(provider)(w) := s1updateMeta(w).providerCtr
                // 这一个表既然当时作为provider,那么就不会被分配
                s1updateAlloc(provider)(w) := false.B
            }
        }
    }

    val s1update = io.f1update
    // commit的有效更新
    when (s1update.valid && s1update.bits.isCommitUpdate && s1update.bits.cfiIdx.valid){


        val idx = s1update.bits.cfiIdx.bits
        val allocate = s1updateMeta(idx).allocate
        // 如果存在分配的表,那么就更新这个表的信息
        when (allocate.valid){
            s1updateMask(allocate.bits)(idx) := true.B
            s1updateUMask(allocate.bits)(idx) := true.B
            s1updateU(allocate.bits)(idx) := 0.U
            s1updateTaken(allocate.bits)(idx) := s1update.bits.cfiTaken
            s1updateAlloc(allocate.bits)(idx) := true.B
        } .otherwise{
            val provider = s1updateMeta(idx).provider
            val decrMask = Mux(provider.valid, ~MaskLower(UIntToOH(provider.bits)), 0.U)

            for (i <- 0 until tageNTables){
                when (decrMask(i)){
                    s1updateUMask(i)(idx) := true.B
                    s1updateU (i)(idx) := 0.U
                }
            }
        }
    }

    // 将汇总好的更新信息传给对应的表
    for (i <- 0 until tageNTables){
        for ( w <- 0 until bankWidth){
            tageTables(i).io.updateMask(w) := RegNext(s1updateMask(i)(w))
            
            tageTables(i).io.updateTaken(w) := RegNext(s1updateTaken(i)(w))
            tageTables(i).io.updateOldCtr(w) := RegNext(s1updateOldCtr(i)(w))
            tageTables(i).io.updateAlloc(w) := RegNext(s1updateAlloc(i)(w))

            tageTables(i).io.updateU(w) := RegNext(s1updateU(i)(w))
            tageTables(i).io.updateUMask(w) := RegNext(s1updateUMask(i)(w))
        }

        tageTables(i).io.updatepc := RegNext(io.f1update.bits.pc)
        tageTables(i).io.updateHist := RegNext(io.f1update.bits.gHist.asUInt)
        // globalhistoty的类里面除了history外还有几位其他的变量，真正用的是前GlobalHistoryLength位的Uint
    }   

    io.f3meta := f3meta

}



