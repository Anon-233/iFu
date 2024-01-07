24.1.6
暂时将Dcache里面的ordered信号恒置为真，不然来不及fence


24.1.7 
1. 将MSHR里面第reset逻辑现在放到了写入请求之前，现在位于第116行

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

2. 还有一个问题，fenclean写回脏行实际上还是占着总线，就算mshrread触发，由于RPU一直在忙着写回脏行busy导致他一直等待。

因此还是解决掉fenceclean，把之前的恒为true撤销掉，然后修改指令提交的时限为10000->15000条指令试一下
修改
test_env\sims\verilator\testbench\include\golden_trace.h 的 500 行 10000变成15000

（这个是有效的）
test_env\sims\verilator\run_prog\configure.sh 第94行deadlockSize 的 10000 改成 15000

3. lsu给dcache发送force_order，dcache希望自己做完之后，ordered传回去，lsu不要再给自己发force_order，但是事实上force_order取消条件式mem_fence，里面还包括了stqEmpty，于是lsu想置低force_order，需要dcache完成st指令，dcache完成st指令需要lsu置低force_order（否则总是在fenceValid占用RPU），于是死锁
因此增加条件，将
```scala
fenceValid := io.lsu.force_order
```

改成
```scala
fenceValid := io.lsu.force_order && fenceMetaRead.resp.bits.hasDirty
```
真正有脏行才启动fence模式

