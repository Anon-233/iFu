package iFu.backend

import chisel3._
import chisel3.util._
import iFu.common._

class MaptableReq(val lregSz:Int) extends Bundle
{
    val lrs1 = UInt(lregSz.W)
    val lrs2 = UInt(lregSz.W)
    val ldst = UInt(lregSz.W)
}

class MaptableResp(val pregSz:Int) extends Bundle
{
    val prs1 = UInt(pregSz.W)
    val prs2 = UInt(pregSz.W)
    val stale_pdst = UInt(pregSz.W)
}

class ReMapReq(val lregSz:Int,val pregSz:Int) extends Bundle
{
    val ldst = UInt(lregSz.W)
    val pdst = UInt(pregSz.W)
    val valid = Bool()
}

class RenameMapTable(
    val plWidth:Int,
    val numLregs:Int,
    val numPregs:Int)extends CoreModule
{
    val pregSize = log2Ceil(numPregs)

    val io = IO(new CoreBundle{
        val map_reqs = Input(Vec(plWidth,new MaptableReq(lregSz)))
        val map_resps = Output(Vec(plWidth,new MaptableResp(pregSz)))

        val remap_reqs = Input(Vec(plWidth,new ReMapReq(lregSz,pregSz)))

        val ren_br_tags = Input(Vec(plWidth,Valid(UInt(brTagSz.W))))

        val brupdate = Input(new BrUpdateInfo)
        val rollback = Input(Bool())
    })

    val mapTable = RegInit(VecInit(Seq.fill(numLregs){0.U(pregSize.W)}))
    val brShotMap = Reg(Vec(maxBrCount, Vec(numLregs, UInt(pregSize.W))))

    val remapTable = Wire(Vec(plWidth+1,Vec(numLregs,UInt(pregSize.W))))

    val remapPdsts = io.remap_reqs map (_.pdst)
    val remap_ldsts_oh = io.remap_reqs (req => UIntToOH(req.ldst) & Fill(numLregs,req.valid.asUInt))

    //更新映射关系
    for(i <- 0 until numLregs){ //遍历每一个寄存器
        if(i == 0){
            for(j <- 0 until plWidth+1){
                remapTable(j)(i) := 0.U //寄存器x0固定为0
            }
        }else{
            val row = (remap_ldsts_oh.map(ldst => ldst(i)) zip remapPdsts)
                .scanLeft(mapTable(i)){case (pdst,(ldst,new_pdst)) => Mux(ldst,new_pdst,pdst)}

            for(j <- 0 until plWidth+1){
                remapTable(j)(i) := row(j)
            }
        }
    }

    //保存分支的map关系（分支预测错误需要回滚)
    for(i <- 0 until plWidth){
        when(io.ren_br_tags(i).valid){
            brShotMap(io.ren_br_tags(i).bits) := remapTable(i+1) //i+1是因为scanleft函数
        }
    }

    //更新maptable
    when(io.brupdate.b2.mispredict){
        mapTable := brShotMap(io.brupdate.b2.uop.br_tag)
    } .otherwise {
        mapTable := remapTable(plWidth)
    }

    //输出,对于转发在顶层模块判断和进行
      for (i <- 0 until plWidth) {
        io.map_resps(i).prs1       := mapTable(io.map_reqs(i).lrs1)
        io.map_resps(i).prs2       := mapTable(io.map_reqs(i).lrs2)
        io.map_resps(i).stale_pdst := mapTable(io.map_reqs(i).ldst)
  }
}