24.1.6
暂时将Dcache里面的ordered信号恒置为真，不然来不及fence


24.1.7 
将MSHR里面第reset逻辑现在放到了写入请求之前，现在位于第116行

```scala
//分支预测调整 或reset
    when (io.reset || IsKilledByBranch(io.brupdate, mshr.req.uop)) {
        mshr.valid := false.B
        mshr := 0.U.asTypeOf(new MSHRdata)
    }
    
    
    when(io.req.fire){
        // 满足则写入新的请求
        mshr.valid := true.B
        mshr.id := io.id
        mshr.req := io.req.bits
        mshr.waiting := true.B
        mshr.fetching := false.B
        mshr.ready := false.B
        mshr.issued := false.B
        mshr.way := io.replacePos
        mshr.pipeNumber := io.pipeNumber
    }
```
原因：
当外界isunique一路到这里dacache的时候，dcache需要(清除dirty行？？ 以及做完所有未完成的lsu_stq任务)当denceValid已经置为高位，而lsu传进来一个req
未命中会导致mshrs.io.valid为true

根据之前的判断逻辑由于lsuforceorder导致fenceClear持续拉高使得reset判断为1，会先进行写入对应mshr，然后马上执行下面的reset删除操作，导致mshr被清空，相当于没写进去

因此需要调换顺序，先判断reset，再写入mshr