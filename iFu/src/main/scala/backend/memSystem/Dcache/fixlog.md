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

TIPS：此处可以实现衔接 ， 如果既有未完成的store指令，又有别的脏行，会写回所有脏行之后，ordered置低，但是lsu的stqEmpty还是false，流水线还处于fence状态中，紧接着当执行完这个store指令之后，stqEmpty变为true，但是因为有dirty位了，ordered又变成了false，因此正好衔接fence状态，直到该做完的都做完。


1.8
1. TIPS: MissArbiter 并不是直接连接到mshrs的req.valid，只负责产生一些信号bits，当且仅当s2state == lsu ，他出来的mshrs.valid才具有参考意义 

2. 在NonBlockingDcache里面，550-554行
```scala
val writebackPos = WireInit(0.U.asTypeOf(Vec(memWidth , UInt(log2Ceil(nWays).W))))
    for(w <- 0 until memWidth){
        writebackPos(w) :=  Mux(s2state === lsu, s2hitPos(w),
                            Mux(s2state === replay, s2replayHitPos(w),
                                        0.U(log2Ceil(nWays).W)))
    }
```

由于
```scala
val s2replayHitPos = RegNext(s1replayHitPos)

val s2hitPos = RegNext(s1hitPos)
```
把他们混淆成都可以(w)索引，但是实际上s2hitpos是Vec，而s2replayHitPos是UInt，因此如果向上面那样取s2replayHitPos(w)，
实际上是取s2replayHitPos的第w位，只可能是0或者1，这样就会导致writebackPos(w)，0和1可能不一样，replay要求的是此处一样，因此会导致replay失败
iFuCore.sv逻辑中实际上对s2state === replay的情况下，取得writebackpos_1，即s2replayHitPos的第1位
因此如果要写入的是b'001 ， 那么s2replayHitPos(0) = 1，s2replayHitPos(1) = 0，本来要写001的写成了0 ，就会写歪！！！

因此需要将s2replayHitpos(w)，直接改成s2replayHitpos即可

3. 完善了fence，之前meta对于fenceRead实际上只向外resp一个hasDirty，这个fenceRead实际上并没有成功执行，此处在s0state === fence 的时候加入了fenceMetaRead.req.valid = true,使得可以取到脏行信息，另外之前s2replacedDataLine只会是是mshrDataread.resp的数据，
    
    - TIPS :
    fenceMetaRead 传入一个valid，meta找出一个脏行，将信息通过resp传出来
    fenceMetaClean 传入一个Valid ， meta将对应的脏行清空

    对于s2replacedDataLine加入了选择机制，s2state === fence的时候，取的是fenceRead的数据，
    s2state === mshrread 的时候，取的是mshrDataread的数据 , 其他时候为0

- 当前fence只是脏行写回 清空，因此fence之后，会完成前面所有的store指令，写回并清空所有的脏行，此时一些一直不脏的行不会被清空。



可能的TODO ： 外设的uncachable
当一条被检测为外设的访存指令传入dcache，实际上是不经过dcache的，直接和总线交互，那么会选一个周期进RPU单元进行总线交互，此时需要总线申请的不同任务之间的协调，如：
- 如果一条外设指令进来的时候，RPU正忙，需要怎么处理这个请求？
- 进一步的，RPU忙的时候，其他任务要如何处理这个RPU忙的事件？
