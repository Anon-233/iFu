##MAKEFILE使用指南
在iFu/iFu目录下：

make (complie):一阶段，将chisel生成的scala文件编译成verilog文件，会生成在IP/myCPU/iFuCore.sv


make run TEST=x ：二阶段，verilog文件编译成仿真文件，运行仿真，x为测试编号

