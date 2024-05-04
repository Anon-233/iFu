# iFu

你说得对，但是《 **iFu** 》是由 **???** 自主编写的一款全新超标量乱序CPU。CPU运行在一个被称作「 **FPGA** 」的物理世界，在这里被 **SBT** 选中的 **Chisel Codes** 将被授予「 **编译运行** 」，引导 **仿真与综合** 之力。你将扮演一位名为「 **/\*TODO\*/** 」的神秘角色，在自由的 **LoongArch32** 中邂逅性格各异、能力独特的 **Instructions** ，和它们一起击败 **CoreMark** ，找回 **性能** 的同时，逐步发掘「 **B+ = 3.3** 」的真相 。

## 项目结构
```shell
.
|-- README.md
`-- iFu
    |-- Makefile
    |-- README.md
    |-- build.sbt
    |-- doc
    |-- mem.conf
    `-- src
        |-- main
        `-- test
```

## 环境配置
1. 参考`https://www.chisel-lang.org/docs/installation`安装`SBT`

## 编译运行
1. 修改`iFu/Makfile`中的`gen_dir`为`system verilog`代码生成目录
2. 运行`make`命令，即可在`gen_dir`目录下生成`iFuCore.sv`文件

## 仿真环境
1. 本项目仿真依赖于[chiplab](https://gitee.com/loongson-edu/chiplab)
2. 将`gen_dir`设置为`chiplab/IP/myCPU`
3. 目前采用的总线协议为计算机组成与体系结构实验中使用的`CBus`，需要在`chiplab/IP/myCPU/iFuCore.sv`下添加部分文件用以将`CBus`转换为`AXI`总线协议
    - TODO: 修改为`AXI`总线协议
4. 将`iFuCore.sv`接入到`chiplab/IP/myCPU/mycpu_top.v`中
5. 完成上述步骤后，即可使用`chiplab`提供的仿真环境进行仿真
