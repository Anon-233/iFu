
(重构dcache之后)
1.15
关于转发的问题：
对于syncReadMem，在verilator同周期读写可以内部转发，reg不自带内部转发
因此在wordData和Meta类中都加了转发检查机制
在wordData中，当周期判断，下周期转发
```scala
  // bypass
    val bypass = Wire(Vec(memWidth, Bool()))
    for (w <- 0 until memWidth) {
        // 当周期判断，下周期转发
        bypass(w) := rvalid(w) && wvalid && (ridx1v(w) === widx1v)
        when (RegNext(bypass(w))) {
            io.read(w).resp.bits.data := RegNext(wreq.data)
        }
    }

```

在meta中
```scala
// bypass
    val bypass = Wire(Vec(memWidth, Bool()))
    for (w <- 0 until memWidth) {
        // 当周期判断，下周期转发
        bypass(w) := rvalid(w) && wvalid && (ridx(w) === widx)
        when (RegNext(bypass(w))) {
            // 看看write操作对应位有修改吗，如果有，用写的值，没有的话，还是保留原来读到的rmetaSet的值
            io.read(w).resp.bits.rmetaSet(wpos).valid := Mux(RegNext(wreq.setvalid.valid), RegNext(wreq.setvalid.bits), rmetaSet(w)(wpos).valid)
            io.read(w).resp.bits.rmetaSet(wpos).dirty := Mux(RegNext(wreq.setdirty.valid), RegNext(wreq.setdirty.bits), rmetaSet(w)(wpos).dirty)
            io.read(w).resp.bits.rmetaSet(wpos).readOnly := Mux(RegNext(wreq.setreadOnly.valid), RegNext(wreq.setreadOnly.bits), rmetaSet(w)(wpos).readOnly)
            io.read(w).resp.bits.rmetaSet(wpos).tag := Mux(RegNext(wreq.setTag.valid), RegNext(wreq.setTag.bits), rmetaSet(w)(wpos).tag)
        }
    }
```

这里的RegNext是为当周期判断下周期用设置的


2. 关于mshr的FakefirstMiss

当一个refill进行到最后一个，进行到s2的时候，会
- 写回newmeta
- 并且通告mshr对应的一表项，一表项当周期给对应二表项激活一次，下周期就被清掉了
直到被清掉，这个表项还是waiting状态

在这个周期之前运行到s2的二次miss都可以正常匹配，正常工作，正常被激活
在这个时候由于设置了meta内部转发，s0的同地址快读已经可以命中了

唯独此时的s1被判断成了miss，
一个周期后，当他s2进表的时候对应的表一项早就没了，因此他以为自己是首次miss
导致了fakefirstmiss的出现，这会导致重新refill，破坏缓存一致性

解决方法：做一个一周期之前信息的转发，如果发现一周期之前有一个fetchReady，
并且那时对应的块地址和当前的地址一样，就视为一个secondMiss，存入即激活(fastWakeUp机制)


3.brmask , kill 的检查

s1，s2 都要检查是不是kill了,目前s2valid是
```scala
for(w <- 0 until memWidth){
        s2valid(w) := RegNext(s1valid(w) &&
                            !(s1state === lsu && (isStore(s1req(w)) && s2StoreFailed)) && 
                            !(s1state === lsu && (!isStore(s1req(w)) && IsKilledByBranch(io.lsu.brupdate, s1req(w).uop))) &&
                            !(s1state === replay && (!isStore(s1req(w)) && IsKilledByBranch(io.lsu.brupdate, s1req(w).uop)))
                            )
}
```
这只考虑了s1的kill情况，在s2的时候也要当周期更新brmask之后检查一下



4. 有关指令miss之后的行为
- miss之后在s2经过mshr判断能不能存进来，是firstmiss还是secondmiss，需不需要快启动

- 之后总线空闲的时候会发出mshrread请求，这个请求在s0传入地址，s1从meta中返回可被替换的行号，（替换前后idx肯定相同，不用专门传）



5. 对于mshrreplay可能导致的乱序
在refill的最后一个周期，由于内部转发，此时s0的一个用到该meta的指令会认为自己命中，这可以多做一个乱序ld

问题：在一个storemiss ， 进了mshr，lsu会从下一个st指令一直重发，这里应该不允许做完（保证顺序！）

解决此问题需要利用的机制是，s1判断，如果mshr里面有store，就判为miss，然后再以s2的时候hasStore接不了而引起重发


然而，如果refill最后一个到第二周期，是一个曾经miss的store指令发起的，就会导致这个store在下个周期才能被replay

然而下个周期：
replay到s0的时候，s2的storemiss发现没有hasStore，就可以存进去，s1上个周期被meta内部转发判为命中，如果s1此时是后面重发的st指令，这会导致s1乱序



作出改动：首先一个一表项直到fetchReady后的两周期才会被清掉，多留两个周期的"影子"，然后，所有s1判断到mshr.io.hasStore的st会被判为miss

1. refill，fetchReady，s1的miss，一周期之后进去，一表项还在，根据影子判断是secondMiss
2. refill，fetchReady，s0的超前命中st，一周期之后，一表项还在，hasStore还是为高，自己被判为miss，两周期之后，一表项还在，自己装不进去，会发回nack，导致重发

这两个特殊的周期由此解决、

从某种意义上讲，这里当且仅当两周期之后第一个真正的st的replay才被算做完，那时候才算一表项被清，也正常

移除fakeFirstMiss，保留快速唤醒，将hasStore转变为一二表项共同的判断逻辑
并且这两个特殊的存活周期中该表项会变成ready，并且记录下replay的pos，
如果在特殊周期有二次命中，肯定不能从头开始等（那一个一表项马上消失，等不来的），必须快速唤醒，并且从那个一表项拿replaypos
