# 汇编语言学习笔记

> 学习汇编语言的目的是为了理解计算机。

## 前言

尽管汇编语言也是一种计算机语言，但却是与众不同的，与它的同类们格格不入。处理器的工作是执行指令并获得结果，而为了驾驭处理器，汇编语言为每一种指令提供了简单好记、易于书写的符号化表示形式。

一直以来，人们对于汇编语言的认识和评价可以分为两种，一种是觉得它非常简单，另一种是觉得它学习起来非常困难。

说汇编语言难学，这没有道理。学习任何一门计算机语言，都需要一些数制和数制转换的知识，也需要大体上懂得计算机是怎么运作的。在这个前提下，汇编语言是最贴近硬件实体的，也是最自然和最朴素的。最朴素的东西反而最难掌握，这实在说不过去。因此，原因很可能出在我们的教科书上，那些一上来就搞一大堆寻址方式的书，往往以最快的速度打败了本来激情高昂的初学者。

但是，说汇编语言好学，也同样有些荒谬。据我的观察，很多人掌握了若干计算机指令，会编写一个从键盘输入数据，然后进行加减乘除或者归类排序的程序后，就认为自己掌握了汇编语言。

尽管汇编语言不适合用来编写大型程序，但它对于理解计算机原理很有帮助，特别是处理器的工作原理和运行机制。就算是为了这个目的，也应该让汇编语言回归它的本位，那就是访问和控制硬件（包括处理器），而不仅仅是编写程序，输入几个数字，找出正数有几个、负数有几个，大于30 的有几个。

## 目录

### 第1部分 预备知识

- [第1章_十六进制计数法](docs/第1部分_预备知识/第1章_十六进制计数法.md)
  - [二进制计数法回顾](docs/第1部分_预备知识/第1章_十六进制计数法.md#二进制计数法回顾)
  - [十六进制计数法](docs/第1部分_预备知识/第1章_十六进制计数法.md#十六进制计数法)
  - [为什么需要十六进制](docs/第1部分_预备知识/第1章_十六进制计数法.md#为什么需要十六进制)
- [第2章_处理器、内存和指令](docs/第1部分_预备知识/第2章_处理器、内存和指令.md)
  - [寄存器和算术逻辑部件](docs/第1部分_预备知识/第2章_处理器、内存和指令.md#寄存器和算术逻辑部件)
  - [内存储器](docs/第1部分_预备知识/第2章_处理器、内存和指令.md#内存储器)
  - [指令和指令集](docs/第1部分_预备知识/第2章_处理器、内存和指令.md#指令和指令集)
  - [古老的8086处理器](docs/第1部分_预备知识/第2章_处理器、内存和指令.md#古老的8086处理器)
    - [8086的内存分段机制](docs/第1部分_预备知识/第2章_处理器、内存和指令.md#8086的内存分段机制)
- [第3章_汇编语言和汇编软件](docs/第1部分_预备知识/第3章_汇编语言和汇编软件.md)
  - [NASM 编译器](docs/第1部分_预备知识/第3章_汇编语言和汇编软件.md#NASM%20编译器)
- [第4章_虚拟机的安装和使用](docs/第1部分_预备知识/第4章_虚拟机的安装和使用.md)
  - [计算机的启动过程](docs/第1部分_预备知识/第4章_虚拟机的安装和使用.md#计算机的启动过程)
    - [计算机的加电和复位](docs/第1部分_预备知识/第4章_虚拟机的安装和使用.md#计算机的加电和复位)
    - [基本输入输出系统](docs/第1部分_预备知识/第4章_虚拟机的安装和使用.md#基本输入输出系统)
    - [硬盘及其工作原理](docs/第1部分_预备知识/第4章_虚拟机的安装和使用.md#硬盘及其工作原理)
    - [一切从主引导扇区开始](docs/第1部分_预备知识/第4章_虚拟机的安装和使用.md#一切从主引导扇区开始)
  - [创建和使用虚拟机](docs/第1部分_预备知识/第4章_虚拟机的安装和使用.md#创建和使用虚拟机)

### 第2部分 实模式

- [第5章_编写主引导扇区代码](docs/第2部分_实模式/第5章_编写主引导扇区代码.md)
  - [主引导扇区](docs/第2部分_实模式/第5章_编写主引导扇区代码.md#主引导扇区)
  - [在屏幕上显示文字](docs/第2部分_实模式/第5章_编写主引导扇区代码.md#在屏幕上显示文字)
    - [初始化段寄存器](docs/第2部分_实模式/第5章_编写主引导扇区代码.md#初始化段寄存器)
    - [显存的访问和ASCII代码](docs/第2部分_实模式/第5章_编写主引导扇区代码.md#显存的访问和ASCII代码)
    - [显示字符](docs/第2部分_实模式/第5章_编写主引导扇区代码.md#显示字符)
    - [MOV指令的格式](docs/第2部分_实模式/第5章_编写主引导扇区代码.md#MOV指令的格式)
  - [显示标号的汇编地址](docs/第2部分_实模式/第5章_编写主引导扇区代码.md#显示标号的汇编地址)
    - [标号](docs/第2部分_实模式/第5章_编写主引导扇区代码.md#标号)
    - [如何显示十进制数字](docs/第2部分_实模式/第5章_编写主引导扇区代码.md#如何显示十进制数字)
    - [在程序中声明并初始化数据](docs/第2部分_实模式/第5章_编写主引导扇区代码.md#在程序中声明并初始化数据)
    - [分解数的各个数位](docs/第2部分_实模式/第5章_编写主引导扇区代码.md#分解数的各个数位)
    - [显示分解出来的各个数位](docs/第2部分_实模式/第5章_编写主引导扇区代码.md#显示分解出来的各个数位)
  - [使程序进入无限循环状态](docs/第2部分_实模式/第5章_编写主引导扇区代码.md#使程序进入无限循环状态)
  - [完成并编译主引导扇区代码](docs/第2部分_实模式/第5章_编写主引导扇区代码.md#完成并编译主引导扇区代码)
    - [主引导扇区有效标志](docs/第2部分_实模式/第5章_编写主引导扇区代码.md#主引导扇区有效标志)
  - [加载和运行主引导扇区代码](docs/第2部分_实模式/第5章_编写主引导扇区代码.md#加载和运行主引导扇区代码)
  - [程序的调试技术](docs/第2部分_实模式/第5章_编写主引导扇区代码.md#程序的调试技术)
    - [开源的Bochs虚拟机软件](docs/第2部分_实模式/第5章_编写主引导扇区代码.md#开源的Bochs虚拟机软件)
- [第6章_相同的功能，不同的代码](docs/第2部分_实模式/第6章_相同的功能，不同的代码.md)
  - [跳过非指令的数据区](docs/第2部分_实模式/第6章_相同的功能，不同的代码.md#跳过非指令的数据区)
  - [在数据声明中使用字面值](docs/第2部分_实模式/第6章_相同的功能，不同的代码.md#在数据声明中使用字面值)
  - [段地址的初始化](docs/第2部分_实模式/第6章_相同的功能，不同的代码.md#段地址的初始化)
  - [段之间的批量数据传送](docs/第2部分_实模式/第6章_相同的功能，不同的代码.md#段之间的批量数据传送)
  - [使用循环分解数位](docs/第2部分_实模式/第6章_相同的功能，不同的代码.md#使用循环分解数位)
  - [计算机中的负数](docs/第2部分_实模式/第6章_相同的功能，不同的代码.md#计算机中的负数)
    - [无符号数和有符号数](docs/第2部分_实模式/第6章_相同的功能，不同的代码.md#无符号数和有符号数)
    - [处理器视角中的数据类型](docs/第2部分_实模式/第6章_相同的功能，不同的代码.md#处理器视角中的数据类型)
    - [跳过非指令的数据区](docs/第2部分_实模式/第6章_相同的功能，不同的代码.md#跳过非指令的数据区)
  - [其他标志位和条件转移指令](docs/第2部分_实模式/第6章_相同的功能，不同的代码.md#其他标志位和条件转移指令)
    - [奇偶标志位PF](docs/第2部分_实模式/第6章_相同的功能，不同的代码.md#奇偶标志位PF)
    - [进位标志CF](docs/第2部分_实模式/第6章_相同的功能，不同的代码.md#进位标志CF)
    - [现有指令对标志位的影响](docs/第2部分_实模式/第6章_相同的功能，不同的代码.md#现有指令对标志位的影响)
    - [条件转移指令](docs/第2部分_实模式/第6章_相同的功能，不同的代码.md#条件转移指令)
    - [NASM编译器的$和$$标记](docs/第2部分_实模式/第6章_相同的功能，不同的代码.md#NASM编译器的$和$$标记)
- [第7章_比高斯更快的计算](docs/第2部分_实模式/第7章_比高斯更快的计算.md)
  - [计算1到100的累加和](docs/第2部分_实模式/第7章_比高斯更快的计算.md#计算1到100的累加和)
  - [累加和各个数位的分解与显示](docs/第2部分_实模式/第7章_比高斯更快的计算.md#累加和各个数位的分解与显示)
  - [计算1到100的累加和](docs/第2部分_实模式/第7章_比高斯更快的计算.md#计算1到100的累加和)
  - [8086处理器的寻址方式](docs/第2部分_实模式/第7章_比高斯更快的计算.md#8086处理器的寻址方式)
    - [寄存器寻址](docs/第2部分_实模式/第7章_比高斯更快的计算.md#寄存器寻址)
    - [立即寻址](docs/第2部分_实模式/第7章_比高斯更快的计算.md#立即寻址)
    - [内存寻址](docs/第2部分_实模式/第7章_比高斯更快的计算.md#内存寻址)
      - [直接寻址](docs/第2部分_实模式/第7章_比高斯更快的计算.md#直接寻址)
      - [基址寻址](docs/第2部分_实模式/第7章_比高斯更快的计算.md#基址寻址)
      - [变址寻址](docs/第2部分_实模式/第7章_比高斯更快的计算.md#变址寻址)
      - [基址变址寻址](docs/第2部分_实模式/第7章_比高斯更快的计算.md#基址变址寻址)
- [第8章_硬盘和显卡的访问与控制](docs/第2部分_实模式/第8章_硬盘和显卡的访问与控制.md)

