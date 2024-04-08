### NonBlockingDcache
非阻塞cache在这里负责处理lsu的请求，以及一些对于cache，总线资源的维护。


#### 1. 内部模块组件
- meta : 用于存储cache的meta信息，包括valid，tag，dirty等信息

- data : 用于存储cache的数据信息，一维展平,可以优化时序

- mshr :用于存储cache指令的miss信息，包括miss的地址，miss的状态等信息

- wfu : Write&Fetch Unit，连接着总线，用于处理对脏cache行写回内存，以及从内存中取新的行到cache中

- mmiou : 同样连接着总线，用于处理lsu发进来的mmio请求，包括读写

以及几个辅助模块
- wordWrite:用于处理粒度写
- MissArbiter:两个流水线发生了miss请求，仲裁谁放进mshr

#### 2. 内部流水线
流水线有状态对应的任务是
- lsu ：普通的lsu访存请求(无mmio)，包括读写。
s0:接到请求，将idx送入meta进行命中的判断
s1:接到hit与否，如果hit，就将命中后的pos送入data
s2:
    若命中，此时data会返回那个字，进行处理
        如果是ld指令，就将数据resp回lsu
        如果是st指令
            如果mshr没有正在等待的st指令，就正常做，将数据按粒度处理之后写回data，然后将那一行meta的dirty标记为true
            如果mshr有st指令，那就说明前面的st指令还在等待自己完成，后面的不要去做，按照storefailed的方式返回
    若miss经过missAribiter的处理，将miss的请求存入mshr中，等待有机会发出replay

- mshrread : 处理mshr指令的第一步，向wfu发请求
s0:按miss的地址去meta里面寻一个可替换的行
s1:meta将这个寻得的pos以及其他有关信息(要去fetch的自己的地址，以及可能写回内存的脏行的地址)送入wfu
s2:无

- wb : wfu不存一整条cache行，而是"现用现取",wb代表wfu要从向内存写回的行那里拿一个字——因此一次对cache行的写回是需要16，32等周期数的
s0:由于wfu里面已经得知了要写回内存的行以及具体想要的哪一个字，s0不需要进meta再寻地址，不做任何操作
s1:将位置信息送入data
s2：data读取到这个字，送给wfu
    一个小机制：
    如果这个字的偏移是那一行的第一个字，说明这个时候要正式开始写回了，将这个行对应meta的readOnly标记为true，此时可以服务ld，但是不可以服务st（标志是st指令即使命中也返回miss）。

- refill: wfu执行fetch状态从内存中拿出的新行的某个字，写入cache
s0:由于wfu已经得知了要写入的行的位置，s0不需要进meta再寻地址，不做任何操作
s1:只需要按照指定的位置写回就好，因此也不需要读取data
s2:将那个字写入data
    两个特殊情况
    如果refill了第一个字进去,说明这个行既有老的字,又有新的字,这个时候要直接作废掉这个meta行
    如果是fetchReady的时候,也就是写好了最后一个字,这个时候将新的meta行写回meta,同时通告mshr取好的地址以及pos信息,使其可以激活对应的可能等待的请求

- replay: mshr中的miss请求被激活,重新发出来执行
s0:由于已经知道对应的全部位置信息,因此不需要meta参与
s1:将位置信息送入data
s2:读或写操作,将返回的resp通过0号返回lsu即可.


- mmioreq:mmio请求,lsu发送mmio的时候,保证两条流水线里面只有一条在处理mmio,另一条什么都不做
s0:无
s1:无
s2:将mmio请求送入mmiou,mmiou开始处理

- mmioresp:mmio回复,mmiou处理完毕,回复lsu
s0:会从mmiou发出一条req,这条req里面的data和uop就是最后要送给resp的,这里以"req"的形式出现只是载体
s1:无
s2:将resp通过0号流水线送回给lsu

#### 3. 一些细节
- 和lsu的ready交流
3.1 io.lsu.req.ready的意思lsu一定会认为发送进来了,因此当一些情况不想让lsu发送进来的时候,要将ready置为false,这些主要包括一些内部事务,以及不满足条件的情况:1.lsu想发st指令,但刚刚发生了storeFailed,需要lsu的st队列调整之后重发.2.lsu想发送mmio.但是当前的axi总线繁忙.


- 状态优先级
    wb和refill最高,因为wb一旦开始,必须保证从cache行读字的速度,比axi总线向内存写回要快,否则会出现数据混乱的情况.
    然后是mmio的req和resp
    再之后是replay,因为replay信号等了很久了,优先处理
    再之后是mshrread,因为mshrread是为了给replay提供激活wfu功能的
    再之后,在所有总线相关和处理miss指令之后,是普通的lsu请求

- axi线的互斥
由于只有一条axi线,而可能用到axi的有wfu和mmiou,因此要记录axi的状态,如果其中一个单元在忙,或者流水线中s1s2有即将动用两个单元的请求,那么就标记为忙,不允许其他axi请求来.


- kill机制
iskilledbyBranch,会在s0,s1,s2来检查
storeFailed,会在s0,s1检查
lsu的s1_kill,会kill掉当前s1的请求

- 分支预测处理
在每级流水线处理分支预测错误,随时准备判断kill的信号.
在每级流水线及时更新,GetNewBrMask

---
接下来是meta和data相关内容
### MetaLogic
处理meta逻辑,首先约定所有状态,都需要在s0发起读,s2和data一起发起写,否则会有复杂的冲突
读的case
- lsu_R: lsu普通的读指令,拿着s1返回的metaSet来对tag比较,判断命中与否,特别地对于readOnly的行,如果是st指令,也会返回miss
- replay_R:无具体工作
- mshr_R: 替换算法找到路号,已经对应的被换掉的行,送给wfu自行判断需不需要藏位写回

写的case
全部都是将写的请求传递给meta数据即可

### Meta
meta的数据,以Set存储,接收读写,实现了内部转发
存在一个写的机制:每一个字段(valid,dirty,tag等)都有valid和bits,只有对应位的valid为高,才能将bits的数值写进去.

### DataLogic
逻辑比较简单,无论读写都是直接将请求传递给data数据即可

### WordData
这里的data是一维的,会将idx,pos,和字偏移算出一个一维的idx,进行读或者写,单次读或写都是一个字
同样地也实现了内部转发.

### MSHR

