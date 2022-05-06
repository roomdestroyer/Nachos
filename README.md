#### Nachos 简介

---

Nachos是由加州大学伯克利分校的Tom Anderson教授基于C++实现的一个教学用操作系统。在学习了操作系统的概念与原理之后，通过阅读Nachos中相关内容的源代码并实践编程信号量、扩展文件系统、系统调用的部分功能，可以更加深入地理解操作系统的相关概念与工作原理，掌握实际操作系统的开发过程与方法。

掌握操作系统设计与实现方法的最有效途径就是阅读一个真正操作系统的实现代码。Nachos操作系统设计精良、结构紧凑，由大约9,500行C++代码和少量汇编程序组成，并做了大量的注释，被全球众多高校用来辅助操作系统课程的教学。

Nachos系统运行在像Ubuntu之类的Linux操作系统之上，它作为Linux的一个进程来运行。



#### 实验索引

---

<a href=https://github.com/roomdestroyer/Nachos/tree/main/code/lab1>LAB1</a>

##### 目的：

1. 安装编译Nachos系统，理解Nachos系统的组织结构与安装过程；

2. 安装测试gcc MIPS交叉编译器；

3. 掌握利用Linux调试工具GDB调试跟踪Nachos的执行过程；

4. 安装成功后，根据Nachos的输出结果，分析分析跟踪Nachos的C++程序及汇编代码，理解Nachos中线程的创建方法以及上下文切换的过程。

5. 阅读Nachos的相关源代码，理解Nachos内核的启动与停机过程。

6. 理解Nachos的运行参数的含义与使用。



<a href=https://github.com/roomdestroyer/Nachos/tree/main/code/lab2>LAB2</a>

**目的：**

1. 熟悉Nachos的makefiles的结构；

2. 熟悉如何在几个lab文件目录中构造相应的Nachos系统；



<a href=https://github.com/roomdestroyer/Nachos/tree/main/code/lab3>LAB3</a>

**目的：**

1. 进一步理解Nachos中如何创建线程；

2. 理解Nachos中信号量与P、V操作是如何实现的

3. 如何创建与使用Nachos的信号量

4. 理解Nachos中是如何利用信号量实现producer/consumer problem；

5. 理解Nachos中如何测试与调试程序；

6. 理解Nachos中轮转法（RR）线程调度的实现；



<a href=https://github.com/roomdestroyer/Nachos/tree/main/code/lab4>LAB4</a>

**目的：**

1. 理解Nachos硬盘是如何创建的；

2. 熟悉查看Nachos硬盘上的内容的方法；

3. 理解硬盘初始化的过程（如何在硬盘上创建一个文件系统）；

4. 了解Nachos文件系统提供了哪些命令，哪些命令已经实现，哪些需要你自己实现；

5. 理解已经实现的文件系统命令的实现原理；

6. 理解硬盘空闲块的管理方法；

7. 理解目录文件的结构与管理；

8. 理解文件的结构与文件数据块的分配方法；

9. 了解一个文件系统命令执行后，硬盘的布局；

10. 分析目前Nachos不能对文件进行扩展的原因，考虑解决方案；



<a href=https://github.com/roomdestroyer/Nachos/tree/main/code/lab5>LAB5</a>

**目的：**

1. 理解文件系统中文件操作的实现方法，如文件打开、读、写、扩展、定位、关闭等；

2. 理解如何管理硬盘空闲块；

3. 创建文件时，如何为文件分配目录项及文件头（FCB）；

4. 理解文件扩展时，如何为要扩展的数据查找并分配空闲块；

5. 理解文件扩展后，文件大小是如何记录与保存的；

6. 文件被删除后，如何回收为其分配的资源，如文件头、目录项、硬盘块等；

拓展：有精力可进一步尝试多级目录（目录树）的设计与实现方法。



<a href=https://github.com/roomdestroyer/Nachos/tree/main/code/lab6>LAB6</a>

**目的：**

1. 理解Nachos可执行文件的格式与结构；

2. 掌握Nachos应用程序的编程语法，了解用户进程是如何通过系统调用与操作系统内核进行交互的；

3. 掌握如何利用交叉编译生成Nachos的可执行程序；

4. 理解系统如何为应用程序创建进程，并启动进程；

5. 理解如何将用户线程映射到核心线程，核心线程执行用户程序的原理与方法；

6. 理解当前进程的页表是如何与CPU使用的页表进行关联的；



<a href=https://github.com/roomdestroyer/Nachos/tree/main/code/userprog>LAB7-8</a>

**目的：**

1. 理解如何系统对空闲帧的管理；

2. 理解如何加载另一个应用程序并为其分配地址空间，以支持多进程机制；

3. 理解进程的pid；

4. 理解进程退出所要完成的工作；
5. 实现系统调用Exec()与Exit()。

