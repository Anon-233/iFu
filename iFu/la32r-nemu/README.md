# **基于NEMU实现的LoongArch32-Reduced模拟器**
## **介绍与概况**
本项目基于南京大学的 [NEMU](https://github.com/NJU-ProjectN/nemu) 项目，向其中移植了龙芯架构32位精简版的支持，即 `LoongArch32-Reduced`(以下简称为 `LA32R`)。

为了向 `LA32R` 的开发者、学习者、爱好者以及“龙芯杯”大赛提供一个类似于一生一芯项目中的 `difftest` 环境，我产生了向 `NEMU` 中移植 `LA32R` ，之后基于 `difftest` 框架实现 `LA32R difftest` 的想法。于是该项目诞生了。

 `NEMU` 模拟器是一个轻量级的指令集模拟器，运行效果相当于一个单周期CPU。

参照一生一芯项目，目前可以用于difftest的 `NEMU` 有两个organizations：
```
git clone https://github.com/OpenXiangShan/NEMU.git
git clone https://github.com/OSCPU/nemu.git
```
前者是上游，但本项目目前是基于后者来进行移植的。

## **实现规模**
本项目按照《龙芯架构32位精简版参考手册》实现，目前已经实现了：
* 除浮点指令之外的全部指令
* 除时钟中断、硬件中断、浮点例外之外的全部中断例外支持
* 全部的 `CSR` 寄存器
* 项数可配置的 `TLB MMU`
* 向 `difftest` 框架提供的各 `API`

目前尚未实现、无法实现以及不打算实现的内容：
* `Cache`：不打算实现
* 计时器和定时器：`NEMU` 无法模拟时钟周期，故无法实现
* 各种外设（包括串口）：尚未实现。本项目的最终目的是为了实现 `difftest` ，故外设支持的优先级靠后
* 配套的 `AM` （裸机运行时环境）：尚未实现。理由同上

### **一些特殊实现的说明**
* 由于没有实现缓存，故与缓存相关的指令：`IBAR DBAR PRELD CACOP` 均实现为了 `NOP`，但是 `CACOP` 指令会触发与之相关的指令特权等级错例外（`IPE`）和 `TLB` 例外。
* 与计时器和定时器相关的指令 `RDCNTV{L/H}.W、RDCNTID` 以及读 `TVAL` 寄存器的 `CSR` 指令，是需要从CPU端获取数据的。在单独运行 `NEMU` 的时候，都会读到 0 或者不确定的值。
* `IDLE` 指令实现为了自己跳转到自己，单独运行 `NEMU` 的时候不会产生时钟中断和硬件中断，所以会陷入死循环。
* 实现了两条只对 NEMU 可见的指令：`nemu_trap: 0x80000000`， `print_led: 0xc0000000`。前一条指令用于让 `NEMU` 停止执行，在没有运行时环境支持进程正常退出的情况下，需要在运行的程序中手动编入这条指令来让 `NEMU` 停止工作；后一条指令在运行 `chiplab` 中提供的测试 func 时有用，效果是打印寄存器 `R12` 中的值，即模仿龙芯杯比赛中，试验箱上数码管显示的结果，形如 `XX0000XX`，最左边一字节显示当前的测试点编号，最右边一字节显示当前通过的测试点数目，最左一字节和最右一字节不同的时候就意味着有测试点没有通过。
* 时钟中断、硬件中断信号均需要从CPU端获取，单独运行 `NEMU` 的时候，都不会触发。
* 对于软中断(`Soft Int`)，目前 `NEMU` 的实现是，中断例外标志会携带在导致软中断信号拉高的指令(一般是写入 `CSR` 寄存器的指令)的下一条指令上，也就是说，软中断信号一旦拉高， `NEMU` 就会立即进入例外处理。实际上 `LA32R` 手册中是没有要求必须要在软中断信号拉高时立即进入中断处理的，但由于 `NEMU` 并没有流水线结构，所以会立即进入中断处理。
* `CSR` 寄存器 `CPUID` 不能写入，读出永远为 0 。

## **编译运行**
1、首先需要安装依赖。在编译的过程中手动安装缺失的库（如libreadline，sdl2等）即可。

2、完成依赖安装之后，需要设置环境变量：`export NEMU_HOME=...`，设置为 `NEMU` 主目录。

3、进入 `NEMU` 主目录之后，可以进行编译，输入以下命令完成一次编译：
```shell
make la32-reduced-ref_defconfig   // 导入配置文件
make
```
（当然也可以使用 `make menuconfig` 进入图形化界面手动配置，但是不推荐，一方面是不好用，一方面是已经准备好了配置文件，一方面是很多配置组合并没有测试过）

如果你没有再看到其他报错，生成的动态链接库文件 `la32r-nemu-interpreter-so` 就在 `./build` 之中了。

如果你想将NEMU编译为可执行文件，那么将配置文件换为 `la32-reduced_defconfig`，编译出的可执行文件 `la32r-nemu-interpreter` 就在`./build` 之中了。

## **加载程序并运行**
`NEMU` 有两种方法加载程序，第一种，是将程序的 `.bin` 文件作为参数，在运行程序时传入，如：
```
./la32r-nemu-interpreter ../../../coremark.bin
```
第二种方式是运行程序时不附带任何参数，这时候 `NEMU` 会将 `NEMU/src/isa/la32r/init.c` 中的 `img` 数组中的内容拷贝到 `RESET_PC` 开始执行。可以手动将一些指令编入 `img` 数组中，这在调试的时候非常方便。

### **NEMU部分命令的使用说明**

运行了程序之后就会进入 `NEMU` 命令行，输入 `help` 即可查看可使用的命令。注意 `attach detach save load` 这四个命令没有测试过。

`tlb` 命令和 `b` 命令是我自己加的（没错， `NEMU` 甚至没有自带断点功能），使用说明如下：

* 指令：`tlb`
* 效果：打印当前一共支持多少个 TLB 表项，即 `CONFIG_TLB_ENTRIES`
* 指令：`tlb NUM`
* 效果：`NUM` 范围为 `[0,CONFIG_TLB_ENTRIES]`，当 `NUM` 不等于 `CONFIG_TLB_ENTRIES` 时，`NUM` 作为 `index` ，打印 `tlb[NUM]`；当 `NUM` 等于 `CONFIG_TLB_ENTRIES` 时，会依次打印所有 `TLB` 表项。
* 指令：`b PC`
* 效果：在 `PC` 处设置一个**一次性**的断点，之后 `NEMU` 会自动开始执行，直到下一条指令在 `PC` 时暂停，期间会打印执行过的指令。

还有一个奇怪的 `watchpoint` 命令：
* 指令： `w expression`
* 注意一定是跟一个表达式，可以用来观察每个寄存器的值何时变化，寄存器名称前要加 `$`，如 `$pc==0x1c000000 $sp!=0x0` 在**表达式的值**变化的时候，`NEMU` 会打印变化处的 `PC`,按理说应该在变化处暂停下来，但是很多时候并不能准确地暂停在表达式值变化处。
* <s>ysyx 那边负责维护 `NEMU` 的学长表示他也没怎么用过这个功能。</s>

如果你想实现更多的 `NEMU` 命令，可以在 `NEMU/src/monitor/ui.c` 中自行修改。

### **关于自制workload的说明**

如果你想在 `NEMU` 上运行自己编写的程序，需要注意以下几点：
* 没有输出。`NEMU` 尚未实现配套的 `AM` 以及串口支持。
* 数据段一定要放在代码段后面，这一点可能需要自行修改链接脚本。

我使用的 `workload` 都来自于龙芯的 `chiplab` 仓库：https://gitee.com/loongson-edu/chiplab

如果你也想利用龙芯的 `chiplab` 仓库里的 `func`，这里做出如下说明：
* 请使用最新的仓库。
* `chiplab/software/func` 中的 `lab16` 测试实现为 `nop` 的指令，没有在 `NEMU` 上运行的必要。建议运行 `lab16` 及之前的功能测试。
* `chiplab/software/func` 中的功能测试都是用汇编写的，不存在数据段。但是要注意，`NEMU` 来模拟 `IDLE_1s` 会很慢，请注释掉。另外，涉及到 `NEMU` 没有实现的功能的测试项，也建议注释掉（如 `IDLE` 指令测试，时钟中断测试等）
* 对于其他C程序，如 `coremark`，为了将数据段放在代码段后面，请将 `chiplab/toolchains/system_newlib/pmon.ld` 的第81行   `. = 0x1000;`    注释掉，并且在产生 `.bin` 文件时, `objcopy` 所有的 `section`。

### **“对Hit xxx Trap”的说明** 
在执行了 `nemu_trap: 0x80000000` 这条指令或者 `syscall 0x11` 之后，`NEMU` 会停止执行并判断当前保存返回值的 `a0` 寄存器内容是否为 0 ，是则显示 `HIT GOOD TRAP` 否则显示 `HIT BAD TRAP`。显示 `HIT BAD TRAP`不代表一定错误地执行了程序。

## **对配置文件的说明**
与 `LA32R` 相关的配置文件有两个：`la32-reduced_defconfig` 和 `la32-reduced-ref_defconfig`， 位于 `NEMU/configs` 中。前者用于编译产生可执行文件，后者用于编译产生动态链接库。由于并未对配置文件中的所有设置进行组合测试，所以建议尽量不要尝试任意的配置。

如果你需要配置 `TLB` 表项的数目，可以在配置文件中找到并修改 `CONFIG_TLB_ENTRIES` 一项。如果超过32项，就需要再修改 `CSR` 寄存器 `TLBIDX` 的 `index` 位域的宽度(`src/isa/la32r/local-include/csr.h`)以及 `TLBIDX_W_MASK` (`src/isa/la32r/system/csr_mask.h`)了。

手册中允许物理地址宽度为32至36的实现，在配置文件中你也可以修改 `CONFIG_PALEN` 一项，但实际上本模拟器目前只支持32位的物理地址（`paddr`是`uint_32`类型），修改 `CONFIG_PALEN` 一项只会影响 `tlbelo0` 和 `tlbelo1` 的 `PPN` 域的位宽。

## 其他
* 《龙芯架构32位精简版参考手册》可以从龙芯官网下载。https://www.loongson.cn/FileShow
* `LA32R` 相关工具链请前往龙芯官方的 Chiplab 仓库下载 https://gitee.com/loongson-edu/chiplab
* `LA32R` 的 `difftest` 框架会在龙芯官方的 Chiplab 仓库中公布，详见 Chiplab 仓库的 `chiplab_diff` 分支。
* 目前 `NEMU` 在打印指令的操作数时会有一些不准确、操作数顺序与汇编文件不一样的情况，这是打印的问题，暂时懒得改。
* 目前 `NEMU` 打印的 `PC` 有一些是 “下一条待执行的指令的 `PC`”，有一些是 “本条已执行的指令的 `PC`”，相信聪明的你一定可以辨别。
* 目前 `NEMU` 的基本功能正确，在不实现 `RDCNTV{L/H}.W、RDCNTID` 指令的情况下可以正确执行 `coremark` 。但 `NEMU` 尚未经过充分的随机指令测试，如果你发现了 bug 或者其他问题，请提出 Issue 或者联系我： wangweitong18@mails.ucas.ac.cn
* 在与 `NEMU` 原作者余子濠师兄交流后，本项目正式添加了木兰宽松许可证第二版作为开源许可证。
* 目前本项目和开源仓库仅由我一个人开发管理，这也是我正式开源并管理的第一个仓库，不当之处还请各位不吝赐教，谢谢大家看到这里。
