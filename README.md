---
date: 2022-09-11T15:41:49+08:00  # 创建日期
author: "Rustle Karl"  # 作者

title: "Assembly 学习笔记"  # 文章标题
description: "纸上得来终觉浅，学到过知识点分分钟忘得一干二净，今后无论学什么，都做好笔记吧。"
url:  "posts/assembly/README"  # 设置网页永久链接
tags: [ "assembly", "README" ]  # 标签
categories: [ "Assembly 学习笔记" ]  # 分类

index: true  # 是否可以被索引
toc: true  # 是否自动生成目录
draft: false  # 草稿
---

# Assembly 学习笔记

> 纸上得来终觉浅，学到过知识点分分钟忘得一干二净，今后无论学什么，都做好笔记吧。

包括入门基础教程、标准库/第三方库详解、源码分析、数据结构与算法、面试题解析等。

尽管汇编语言也是一种计算机语言，但却是与众不同的，与它的同类们格格不入。处理器的工作是执行指令并获得结果，而为了驾驭处理器，汇编语言为每一种指令提供了简单好记、易于书写的符号化表示形式。

一直以来，人们对于汇编语言的认识和评价可以分为两种，一种是觉得它非常简单，另一种是觉得它学习起来非常困难。

说汇编语言难学，这没有道理。学习任何一门计算机语言，都需要一些数制和数制转换的知识，也需要大体上懂得计算机是怎么运作的。在这个前提下，汇编语言是最贴近硬件实体的，也是最自然和最朴素的。最朴素的东西反而最难掌握，这实在说不过去。因此，原因很可能出在我们的教科书上，那些一上来就搞一大堆寻址方式的书，往往以最快的速度打败了本来激情高昂的初学者。

但是，说汇编语言好学，也同样有些荒谬。据我的观察，很多人掌握了若干计算机指令，会编写一个从键盘输入数据，然后进行加减乘除或者归类排序的程序后，就认为自己掌握了汇编语言。

尽管汇编语言不适合用来编写大型程序，但它对于理解计算机原理很有帮助，特别是处理器的工作原理和运行机制。就算是为了这个目的，也应该让汇编语言回归它的本位，那就是访问和控制硬件（包括处理器），而不仅仅是编写程序，输入几个数字，找出正数有几个、负数有几个，大于30 的有几个。

## 目录结构

- `assets`: 存储图片及模板文件
  - `assets/templates`: 笔记模板

- `algorithm`: 数据结构与算法
  - `algorithm/structures`: [数据结构](algorithm/structures/README.md)
  - `algorithm/math`: [基础数学](algorithm/math/README.md)

- `docs`: 基础教程，成体系的，或者分类的文章笔记
  - `docs/grammar`: [语法](docs/grammar/README.md)
  - `docs/internal`: [内部实现](docs/internal/README.md)

- `examples`: [实现单个简单功能的项目示例合集](examples/README.md)

- `interview`: [面试题](interview/README.md)

- `libraries`: 常用库详解笔记
  - `libraries/standard`: [标准库详解](libraries/standard/README.md)
  - `libraries/tripartite`: [第三方库详解](libraries/tripartite/README.md)

- `quickstart`: 基础用法、简介
  - `quickstart/cli`: [命令行](quickstart/cli/README.md)
  - `quickstart/feature`: [新特性](quickstart/feature/README.md)

- `tools`: [常用工具笔记](tools/README.md)

- `src`: 与以上目录一一对应的源码存储目录

## 新建笔记

安装模板生成工具 [Toolkit-Py](https://github.com/fujiawei-dev/toolkit-py)：

```bash
pip install -U toolkit-py -i https://pypi.douban.com/simple
```

然后根据 `assets/templates` 目录下的模板创建笔记：

```bash
project notes article --article-path path/to/file
```
