package iFu.frontend

import chisel3._
import chisel3.util._
import iFu.common.CoreBundle



//class BranchPredictionUpdate extends CoreBundle
//{
//    val fetchWidth = frontendParams.fetchWidth
//    val localHistoryLength = frontendParams.bpdParams.localHistoryLength
//    val nBanks      = frontendParams.iCacheParams.nBanks
//
//    // Indicates that this update is due to a speculated misprediction
//    // Local predictors typically update themselves with speculative info
//    // Global predictors only care about non-speculative updates
//    val is_mispredict_update = Bool()
//    val is_repair_update = Bool()
//    val btb_mispredicts = UInt(fetchWidth.W)
//    def is_btb_mispredict_update = btb_mispredicts =/= 0.U
//    def is_commit_update = !(is_mispredict_update || is_repair_update || is_btb_mispredict_update)
//
//    val pc            = UInt(vaddrBits.W)
//    // Mask of instructions which are branches.
//    // If these are not cfi_idx, then they were predicted not taken
//    val br_mask       = UInt(fetchWidth.W)
//    // Which CFI was taken/mispredicted (if any)
//    val cfi_idx       = Valid(UInt(log2Ceil(fetchWidth).W))
//    // Was the cfi taken?
//    val cfi_taken     = Bool()
//    // Was the cfi mispredicted from the original prediction?
//    val cfi_mispredicted = Bool()
//    // Was the cfi a br?
//    val cfi_is_br     = Bool()
//    // Was the cfi a jal/jalr?
//    val cfi_is_jal  = Bool()
//    // Was the cfi a jalr
//    val cfi_is_jalr = Bool()
//    //val cfi_is_ret  = Bool()
//
//    val ghist = new GlobalHistory
//    val lhist = Vec(nBanks, UInt(localHistoryLength.W))
//
//
//    // What did this CFI jump to?
//    val target        = UInt(vaddrBits.W)
//
//    val meta          = Vec(nBanks, UInt(bpdMaxMetaLength.W))
//}



class PredictionInfo extends Bundle with HasBPUParameters{
    val taken = Output(Bool())

    val isBranch = Output(Bool())

    val isJal = Output(Bool())

    val predictedpc = Valid(UInt(vaddrBits.W)) 

}

class PredictionMeta extends Bundle with HasBPUParameters{
    val bimMeta = Output(new BimPredictMeta)
    val btbMeta = Output(new BtbPredictMeta)
    val tageMeta = Output(new TagePredictMeta)
    val ubtbMeta = Output(new UbtbPredictMeta)
    val loopMeta = Output(new LoopPredictMeta)
}

class BranchPredictionBundle extends Bundle with HasBPUParameters{
    val pc = UInt(vaddrBits.W)
    val predInfos = (Vec(fetchWidth, new PredictionInfo))
    val meta = Vec(nBanks,Vec(bankWidth,new PredictionMeta))
}


// 这是全部的Bank的预测信息

class BranchPredictionUpdate extends Bundle with HasBPUParameters{
     // Indicates that this update is due to a speculated misprediction
    // Local predictors typically update themselves with speculative info
    // Global predictors only care about non-speculative updates
    val isMispredictUpdate = Bool()
    val isRepairUpdate = Bool()
    val btbMispredicts = UInt(fetchWidth.W)
    def isBtbMispredictUpdate = btbMispredicts =/= 0.U
    def isCommitUpdate = !(isMispredictUpdate || isRepairUpdate || isBtbMispredictUpdate)

    val pc            = UInt(vaddrBits.W)
    // Mask of instructions which are branches.
    // If these are not cfiIdx, then they were predicted not taken
    val brMask       = UInt(fetchWidth.W)
    // Which CFI was taken/mispredicted (if any)
    val cfiIdx       = Valid(UInt(log2Ceil(fetchWidth).W))
    // Was the cfi taken?
    val cfiTaken     = Bool()
    // Was the cfi mispredicted from the original prediction?
    val cfiMispredicted = Bool()
    // Was the cfi a br?
    val cfiIsBr     = Bool()
    // Was the cfi a jal/jalr?
    val cfiIsJal  = Bool()
    // Was the cfi a jalr
    val cfiIsJalr = Bool()
    //val cfi_is_ret  = Bool()

    val gHist = new GlobalHistory

    // What did this CFI jump to?
    val target        = UInt(vaddrBits.W)

    val meta          = Vec(nBanks, Vec(bankWidth , new  PredictionMeta))
}



// 这是一个Bank的预测信息,把上面的nBanks去掉了,并且fetchWidth改成了bankWidth

class BankedUpdateInfo extends Bundle with HasBPUParameters{
     // Indicates that this update is due to a speculated misprediction
    // Local predictors typically update themselves with speculative info
    // Global predictors only care about non-speculative updates
    val isMispredictUpdate = Bool()
    val isRepairUpdate = Bool()
    val btbMispredicts = UInt(bankWidth.W)
    def isBtbMispredictUpdate = btbMispredicts =/= 0.U
    def isCommitUpdate = !(isMispredictUpdate || isRepairUpdate || isBtbMispredictUpdate)

    val pc            = UInt(vaddrBits.W)
    // Mask of instructions which are branches.
    // If these are not cfiIdx, then they were predicted not taken
    val brMask       = UInt(bankWidth.W)
    // Which CFI was taken/mispredicted (if any)
    val cfiIdx       = Valid(UInt(log2Ceil(bankWidth).W))
    // Was the cfi taken?
    val cfiTaken     = Bool()
    // Was the cfi mispredicted from the original prediction?
    val cfiMispredicted = Bool()
    // Was the cfi a br?
    val cfiIsBr     = Bool()
    // Was the cfi a jal/jalr?
    val cfiIsJal  = Bool()
    // Was the cfi a jalr
    val cfiIsJalr = Bool()
    //val cfi_is_ret  = Bool()

    val gHist = new GlobalHistory


    // What did this CFI jump to?
    val target        = UInt(vaddrBits.W)

    val meta          = Vec(bankWidth , new  PredictionMeta)
}


class BankedPredictorRequest extends Bundle  with HasBPUParameters
{
    val pc = UInt(vaddrBits.W)

    val ghist = new GlobalHistory
}

class BankedPredictorResponse extends Bundle with HasBPUParameters
{
    val f1 = (Vec(bankWidth, new PredictionInfo))
    val f2 = (Vec(bankWidth, new PredictionInfo))
    val f3 = (Vec(bankWidth, new PredictionInfo))
}

class BankedPredictor extends Module with HasBPUParameters
{
    val io  = IO(new Bundle{
        val f0valid = Input(Bool())
        val f0pc = Input(UInt(vaddrBits.W))
        val f0mask = Input(UInt(bankWidth.W))
        
        val f1ghist = Input(UInt(globalHistoryLength.W))
        val f1lhist = Input(UInt(localHistoryLength.W))

        val resp = Output(new BankedPredictorResponse)
        
        val f3meta = Output (Vec(bankWidth, new PredictionMeta))
        val f3fire = Input(Bool())

        val update = Input(Valid(new BankedUpdateInfo))

    })

    val clockcnt = RegInit((0.U)(10.W))
    clockcnt := clockcnt + 1.U
    printf("\n\nBankedPredictor Clock %d :\n", clockcnt)

    io.resp := 0.U.asTypeOf ( new BankedPredictorResponse )
    io.f3meta := 0.U.asTypeOf ( Vec ( bankWidth, new PredictionMeta ) )

    val s0valid = io.f0valid
    val s1valid = RegNext(s0valid)
    val s2valid = RegNext(s1valid)
    val s3valid = RegNext(s2valid)

    val s0mask = io.f0mask
    val s1mask = RegNext(s0mask)
    val s2mask = RegNext(s1mask)
    val s3mask = RegNext(s2mask)

    val s0pc = io.f0pc
    val s1pc = RegNext(s0pc)
    val s2pc = RegNext(s1pc)
    val s3pc = RegNext(s2pc)

    val s0update = io.update
    val s1update = RegNext(s0update)

    // 5个预测器
    val faubtb = Module(new FaUBtbPredictior)
    val bim = Module(new BimPredictor)
    val btb = Module(new BtbPredictor)
    val tage = Module(new TagePredictor)
    val loop = Module(new LoopPredictor)

    // 预测器基本信息输入

    // 更新信息
    faubtb.io.s1update := s1update
    btb.io.s1update := s1update
    bim.io.s1update := s1update
    tage.io.f1update := s1update
    loop.io.f1update := s1update

    // 基本的pc和使能位
    faubtb.io.s1valid := s1valid
    faubtb.io.s1pc := s1pc

    btb.io.s0valid := s0valid
    btb.io.s0pc := s0pc

    bim.io.s0valid := s0valid
    bim.io.s0pc := s0pc

    tage.io.f1valid := s1valid
    tage.io.f1pc := s1pc

    loop.io.f2valid := s2valid
    loop.io.f2pc := s2pc

    // f1接收faubtb输出结果
    for(w <- 0 until bankWidth){
        io.resp.f1(w).taken := faubtb.io.s1taken(w)
        io.resp.f1(w).isBranch := faubtb.io.s1br(w)
        io.resp.f1(w).isJal := faubtb.io.s1jal(w)
        io.resp.f1(w).predictedpc := faubtb.io.s1targs(w)
    }



    // f2以f1为基础，接收btb，bim的输出结果
    io.resp.f2 := RegNext(io.resp.f1)

    for(w <- 0 until bankWidth){
        // bim预测taken（不存在命不命中的说法）覆盖f2的初值
        io.resp.f2(w).taken := btb.io.s2taken(w)

        // 对于btb，当且仅当命中，结果的valid有效，才会把对应的结果覆盖f2的初值
        when(btb.io.s2targs(w).valid){
            io.resp.f2(w).isBranch := btb.io.s2br(w)
            io.resp.f2(w).isJal := btb.io.s2jal(w)
            io.resp.f2(w).predictedpc := btb.io.s2targs(w)

            // btb推测为taken为真当且仅当检测到jal指令，这时bim置信度显然没有必然跳转的jal高，取btb的taken
            when(btb.io.s2taken(w)){
            io.resp.f2(w).taken := btb.io.s2taken(w)
            }

        }
    }

    // f3以f2为基础，接收tage，loop的输出结果
    io.resp.f3 := RegNext(io.resp.f2)

    // 对于tage，还需要全局历史，以及前面f3taken传入之前的预测值作为参考，一并传入
    tage.io.f1gHist := io.f1ghist
    tage.io.previousf3Taken := RegNext(VecInit(io.resp.f2.map(_.taken)))

    // tage可以根据传入的初值，在内部判断命中与否，在内部自行选择好是否覆盖f3的初值
    // 传出来的值不需要像btb一样再次判断，直接覆盖初值即可
    for(w <- 0 until bankWidth){
        io.resp.f3(w).taken := tage.io.f3taken(w)
    }


    // 对于loop，还需要传入f2targs，f2isBr,f3fire,f3mask

        // 接收f2的预测结果targs和br，loop会在内部筛出供f3的跳转指令
    loop.io.f2targs := VecInit(io.resp.f2.map(_.predictedpc))
    loop.io.f2isBr := VecInit(io.resp.f2.map(_.isBranch))

        // 以及f3fire和s3mask
    loop.io.f3fire := io.f3fire
    loop.io.f3mask := s3mask

    for(w <- 0 until bankWidth){
        // 这里只有valid的预测信息才是真正有效，针对命中的循环br指令的，才可以覆盖f3的初值
        when(loop.io.f3taken(w).valid){
            io.resp.f3(w).taken := loop.io.f3taken(w).bits
        }
    } 

    

    // 最后收集五个计数器预测过程中产生的meta信息
    for(w <- 0 until bankWidth ){
        io.f3meta(w).bimMeta := bim.io.s3meta(w)
        io.f3meta(w).btbMeta := btb.io.s3meta(w)
        io.f3meta(w).tageMeta := tage.io.f3meta(w)
        io.f3meta(w).ubtbMeta := faubtb.io.s3meta(w)
        io.f3meta(w).loopMeta := loop.io.f3meta(w)
    }


}




