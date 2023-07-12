package iFu.frontend.predictors

import chisel3._
import chisel3.util._
import iFu.frontend.predictors._
import iFu.common
import scala.math.min

val vaddrBits = 32
val bankWidth = 4
val fetchWidth = 8
val nBanks = 2
val localHistoryLength = 16
val maxMetaLength = 16
val fetchBytes = 32

val nSets = 16

val nWrBypassEntries = 2

val nWays = 4
val tagSz = 10
def fetchIdx(addr: UInt) = addr >> log2Ceil(fetchBytes)

def WrapInc(x: UInt, max: UInt) = Mux(x === max, 0.U, x + 1.U)


class LoopPredictMeta extends Bundle {
    val sCnt   = UInt(10.W)
}

class LoopEntry extends Bundle {
    val tag   = UInt(tagSz.W)
    val conf  = UInt(3.W)
    val age   = UInt(3.W)
    val pCnt = UInt(10.W)
    val sCnt = UInt(10.W)
}

class LoopPredictorColumn extends Module {
    val io = IO(new Bundle {
        val f2valid = Input(Bool())
        val f2idx  = Input(UInt())
        val f3fire = Input(Bool())

        val f3taken     = Output(Bool())
        val f3meta     = Output(new LoopPredictMeta)

        val updateMispredict = Input(Bool())
        val updateRepair     = Input(Bool())
        val updateIdx   = Input(UInt())
        val updateMeta  = Input(new LoopPredictMeta)
    })

    val doingReset = RegInit(true.B)
    val resetIdx = RegInit(0.U(log2Ceil(nSets).W))
    
    when(doingReset){
        resetIdx := resetIdx + 1.U
    }

    when(resetIdx === (nSets-1).U){ 
        doingReset := false.B
    }

    val entries = Reg(Vec(nSets, new LoopEntry))

    // f2读，f3比较输出预测结果，f4更新表项

  
    val f2entry = WireInit(entries(io.f2idx))
    // 避免读后写冲突，判断更新的表项是否是f2读的表项
    when (io.updateRepair && io.updateIdx === io.f2idx) {
        f2entry.sCnt := io.updateMeta.sCnt
    }.elsewhen(io.updateMispredict && io.updateIdx === io.f2idx) {
        f2entry.sCnt := 0.U
    }

    val f3entry = RegNext(f2entry)
    val f3idx = RegNext(io.f2idx)
    val f3sCnt = Mux(
        io.updateRepair && io.updateIdx === f3idx,
        io.updateMeta.sCnt,
        f3entry.sCnt
    )

    val f3tag = f3idx(tagSz+log2Ceil(nSets)-1,log2Ceil(nSets))

    io.f3meta.sCnt := f3sCnt
    // 匹配到表项，并且置信度最高，那么就是我们想要的，按照其规则，一到PCnt就不让它跳转
    when(f3entry.tag === f3tag){
        when (f3sCnt === f3entry.pCnt && f3entry.conf === 7.U){
            io.f3taken := false.B
        }
    }

    val f4fire = RegNext(io.f3fire)
    val f4tag = RegNext(f3tag)
    val f4idx = RegNext(f3idx)
    val f4entry = RegNext(f3entry)
    val f4sCnt = RegNext(f3sCnt)

    // 当下一个周期（也就是当前信息被成功的提交到后面的阶段时）
    when(f4fire){
        // 如果tagMatch命中
        when(f4entry.tag === f4tag){
            // 预测循环结束，那么把计数器sCnt清零,age必然拉满
            when(f4sCnt === f4entry.pCnt && f4entry.conf === 7.U){
                entries(f4idx).sCnt := 0.U
                entries(f4idx).age := 7.U
            
            //  预测循环没结束，每用到此这个表项，age+1，表项负责记录sCnt+1
            }.otherwise{
                entries(f4idx).sCnt := f4sCnt + 1.U
                entries(f4idx).age := Mux(f4entry.age === 7.U, 7.U, f4entry.age + 1.U)
            }
        }
    }

    val entry = entries(io.updateIdx)
    val tag = io.updateIdx(tagSz+log2Ceil(nSets)-1,log2Ceil(nSets))
    val tagMatch = entry.tag === tag
    val ctrMatch = entry.pCnt === io.updateMeta.sCnt
    val wentry = WireInit(entry)

    when (io.updateMispredict && !doingReset) {
    // 当更新告诉我们，之前用的（也就是现在传进来的updateIdx）那一个表项，
    // 其提供的信息是我们产生了错误的预测，那么我们就要更新这个表项

    // 置信度最高的情况
      // tagMatch命中，那么把置信度和当前sCnt清0
      when (entry.conf === 7.U && tagMatch) {
        wentry.sCnt := 0.U
        wentry.conf  := 0.U

      // 如果tagMatch根本没命中，就不要改变
      } .elsewhen (entry.conf === 7.U && !tagMatch) {

    // 置信度不是最高，但也不为0，同时tagMatch的情况
      // ctrMatch，说明这一项还是可信的，当时没有听信，那么置信度加1，sCnt清零
      } .elsewhen (entry.conf =/= 0.U && tagMatch && ctrMatch) {
        wentry.conf  := entry.conf + 1.U
        wentry.sCnt := 0.U

      //ctr没match， 说明不可信，直接置信度置零，然后把我们真正执行到的sCnt更新为它的PCnt
      } .elsewhen (entry.conf =/= 0.U && tagMatch && !ctrMatch) {
        wentry.conf  := 0.U
        wentry.sCnt := 0.U
        wentry.pCnt := io.updateMeta.sCnt

    // 置信度不是最高也不为0，但是tagMatch没命中的情况 ，先不能直接换，需要权衡一下，此时用age来衡量
      // 它的age一旦减到为0，说明很少使用，直接替换我们现在很需要的update的这条信息，置信度从1起计
      } .elsewhen (entry.conf =/= 0.U && !tagMatch && entry.age === 0.U) {
        wentry.tag   := tag
        wentry.conf  := 1.U
        wentry.sCnt := 0.U
        wentry.pCnt := io.updateMeta.sCnt

      //它的age不为0，就对它减一，直到我们的想用的循环能够有充足理由替掉它
      } .elsewhen (entry.conf =/= 0.U && !tagMatch && entry.age =/= 0.U) {
        wentry.age := entry.age - 1.U

    // 以下是置信度为0的情况
        // tagMatch说明我们最近一直用它，直接age拉满
            // ctrMatch，说明这一项还是可信的，当时没有听信，那么置信度加1，sCnt清零   
      } .elsewhen (entry.conf === 0.U && tagMatch && ctrMatch) {
        wentry.conf  := 1.U
        wentry.age   := 7.U
        wentry.sCnt := 0.U

            // ctr没match，说明不可信，置信度还是0，sCnt清零，但是我们把它的PCnt更新为我们现在执行到的sCnt
      } .elsewhen (entry.conf === 0.U && tagMatch && !ctrMatch) {
        wentry.pCnt := io.updateMeta.sCnt
        wentry.age   := 7.U
        wentry.sCnt := 0.U

        // tagMatch也没有命中，这时候就不需要权衡了，直接把这个表项换掉，把新的信息放进去，age拉满
      } .elsewhen (entry.conf === 0.U && !tagMatch) {
        wentry.tag   := tag
        wentry.conf  := 1.U
        wentry.age   := 7.U
        wentry.sCnt := 0.U
        wentry.pCnt := io.updateMeta.sCnt
      }



    // 把更改结果写回   
      entries(io.updateIdx) := wentry
    
// 如果是updateRepair型的更新
    } .elsewhen (io.updateRepair && !reseting) {
        // 如果tagMatch，就把sCnt恢复为update时的更新
      when (tagMatch && !(f4fire && io.updateIdx === f4idx)) {
        wentry.sCnt := io.updateMeta.sCnt
        entries(io.updateIdx) := wentry
      }
    }
// reset置为0
    when (reseting) {
      entries(resetIdx) := (0.U).asTypeOf(new LoopEntry)
   }

}


class LoopPredictor extends CoreModule {
  val io = IO(new Bundle{
    val f2valid = Input(Bool())
    val f2PC = Input(UInt(vaddrBits.W))

    val f1update = Input(Vec(bankWidth, Valid(new UpdateInfo)))

    // 之前的分支预测后传过来的信息
    val f2targs = Input(Vec(bankWidth, Valid(UInt(vaddrBits.W))))
    val f2isBr = Input(Vec(bankWidth, Bool()))

    val f3fire = Input(Bool())
    val f3mask = Input(UInt(bankWidth.W))

    val f3taken = Output(Vec(bankWidth, Bool()))
    val f3meta = Output(Vec(bankWidth, new LoopPredictMeta))

  })

  val columns = Seq.fill(bankWidth){Module(new LoopPredictorColumn)}
  val s2idx = fetchIdx(io.f2PC)

  val f1updateIdx = fetchIdx(io.f1update.bits.PC)

  val f3valid = RegNext(io.f2valid)
  
  for(w <- 0 until bankWidth){
    // 只有跳转指令才会对loop预测产生影响
    val isValidBr = RegNext(io.f2targs(w).valid && io.f2isBr(w))
    columns(w).io.f3fire := io.f3fire && io.f3mask(w) && f3valid && isValidBr

    columns(w).io.f2valid := io.f2valid
    columns(w).io.f2idx := s2idx
    
    
    // 传入更新有关的信息
    columns(w).io.updateMispredict := (io.f1update.valid && 
                                      io.f1update.bits.brMask(w) &&
                                      io.f1update.bits.isMispredictUpdate&&
                                      io.f1update.bits.cfiMispredicted)
    
    columns(w).io.updateRepair := (io.f1update.valid &&
                                  io.f1update.bits.brMask(w) &&
                                  io.f1update.bits.isRepairUpdate)
    
    columns(w).io.updateIdx := f1updateIdx
    columns(w).io.updateMeta := io.f1update(w).bits.meta.loopMeta

    // 输出预测的信息
    io.f3taken(w) := columns(w).io.f3taken
    io.f3meta(w) := columns(w).io.f3meta
  }


}

