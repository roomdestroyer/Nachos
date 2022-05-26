# Nachos 项目总报告

## 目录

- [Lab1 Nachos系统的安装与调试](#Lab1 Nachos系统的安装与调试)
  - [1. 函数地址](#1. 函数地址)
  - [2. 对象地址](#2. 对象地址)
  - [3. ret 地址](#3. ret 地址)
  - [4. SWITCH 地址](#4. SWITCH 地址)
  - [5. Extended tasks](#5. Extended tasks)

- [Lab2 Nachos的MAKEFILES](#Lab2 Nachos的MAKEFILES)

- [Lab3 利用信号量实现线程同步](#Lab3 利用信号量实现线程同步)
  - [1. Nachos 创建线程的流程：](#1. Nachos 创建线程的流程：)
  - [2. 信号量 `P & V` 操作的实现：](#2. 信号量 `P & V` 操作的实现：)
  - [3. Nachos 如何创建与使用信号量：](#3. Nachos 如何创建与使用信号量：)
  - [4. Nachos 信号量机制](#4. Nachos 信号量机制)
  - [5. Nachos 中如何测试与调试程序：](#5. Nachos 中如何测试与调试程序：)
  - [6. Nachos 中时间片轮转法（RR）的实现：](#6. Nachos 中时间片轮转法（RR）的实现：)

- [Lab4 Nachos 的文件系统](#Lab4 Nachos 的文件系统)
  - [1. Nachos 的硬盘是如何创建的](#1. Nachos 的硬盘是如何创建的)
  - [2. 查看 Nachos 硬盘上内容的方法](#2. 查看 Nachos 硬盘上内容的方法)
  - [3. 硬盘初始化的过程](#3. 硬盘初始化的过程)
  - [4. 了解 Nachos 文件系统提供了哪些命令](#4. 了解 Nachos 文件系统提供了哪些命令)
  - [5. 文件系统命令的实现原理](#5. 文件系统命令的实现原理)
  - [6. 硬盘空闲块的管理方法](#6. 硬盘空闲块的管理方法)
  - [7. 目录文件的结构与管理](#7. 目录文件的结构与管理)
  - [8. 文件的结构与文件数据块的分配方法](#8. 文件的结构与文件数据块的分配方法)
  - [9. 一个文件系统命令执行后硬盘的布局](#9. 一个文件系统命令执行后硬盘的布局)
  - [10. 目前 Nachos 不能对文件进行扩展的原因及解决方案](#10. 目前 Nachos 不能对文件进行扩展的原因及解决方案)

- [Lab5 扩展 Nachos 的文件系统](#Lab5 扩展 Nachos 的文件系统)
  - [1. 结果演示](#1. 结果演示)
  - [2. 实现过程](#2. 实现过程)

- [Lab6 Nachos 用户程序与系统调用](#Lab6 Nachos 用户程序与系统调用)
  - [1. Nachos 可执行程序.noff 文件的格式组成](#1. Nachos 可执行程序.noff 文件的格式组成)
  - [2. 用户进程与系统内核交互的逻辑](#2. 用户进程与系统内核交互的逻辑)
  - [3. 交叉编译生成 Nachos 可执行程序](#3. 交叉编译生成 Nachos 可执行程序)
  - [4. 命令行参数-x 的处理过程](#4. 命令行参数-x 的处理过程)
  - [5. 用户线程映射到核心线程的方法](#5. 用户线程映射到核心线程的方法)
  - [6. 进程页表与 CPU 页表关联的方法](#6. 进程页表与 CPU 页表关联的方法)

- [Lab7 地址空间的扩展](#Lab7 地址空间的扩展)
  - [1. Nachos 创建应用程序进程的详细过程](#1. Nachos 创建应用程序进程的详细过程)
  - [2 多进程机制](#2 多进程机制)
  - [3. SpaceId](#3. SpaceId)
  - [4. 为了实现 Join(pid)，考虑如何在该进程相关联的核心线程中保存进程号](#4. 为了实现 Join(pid)，考虑如何在该进程相关联的核心线程中保存进程号)
  - [5. 根据进程创建时系统为其所做的工作，考虑进程退出时应该做哪些工作](#5. 根据进程创建时系统为其所做的工作，考虑进程退出时应该做哪些工作)
  - [6. 考虑系统调用 Exec() 与 Exit() 的设计实现方案](#6. 考虑系统调用 Exec() 与 Exit() 的设计实现方案)

- [Lab8 系统调用 Exec()与 Exit()](#Lab8 系统调用 Exec()与 Exit())
  - [1. 程序总体结构图](#1. 程序总体结构图)
  - [2. 阅读 `../userprog/exception.cc`，理解 `Halt` 的实现原理：](#2. 阅读 `../userprog/exception.cc`，理解 `Halt` 的实现原理：)
  - [3. 编程实现系统调用 Exec() 与 Exit() ](#3. 编程实现系统调用 Exec() 与 Exit() )





## Lab1 Nachos系统的安装与调试

### 1. 函数地址

-  **在你所生成的** **Nachos** **系统中，下述函数的地址是多少？并说明找到这些函数地址的过程及方法。**

  i. InterruptEnable()

  ii. SimpleThread()

  iii. ThreadFinish()

  iv. ThreadRoot()

  为各函数设置断点，例如： b InterruptEnable ，观察到它们的地址分别是： 0x3027 

  0x3275 、 0x2ffc 、 0x4e7c 。 



### 2. 对象地址

- **下述线程对象的地址是多少？并说明找到这些对象地址的过程及方法。**

- i. `the main thread of the Nachos`

  ii. `the forked thread created by the main thread` 

  - 为 `Initialize` 函数设置断点，执行 `run` 运行程序到该函数入口；

  - 依次执行 `step` 步进程序，当函数调用 `currentThread = new Thread("main")` 后，打印其地址： `print currentThread` ，得到 `main thread` 的地址为 ``0x56563ca0`； 

  - 为 `ThreadTest` 函数设置断点，继续执行程序： `continue` ，进入该函数并执行 Thread `*t = new Thread("forked thread")` 后，执行语句 `print t` ，得到 `forked thread` 的地址为 `0x5655df40` 。



### 3. ret 地址

- **当主线程第一次运行 SWITCH()函数，执行到函数 SWITCH()的最后一条指令 ret 时，CPU 返回的地址是多少？ 该地址对应程序的什么位置？**

- `Scheduler::Run()` 函数调用了 `SWITCH()` 函数，实现线程的上下文切换。执行 `b SWITCH` 设置断点， `run` 执行到该处后暂停，利用 `ni` 单步执行，执行完 `SWITH` 进入到 `ThreadRoot` 后，观察 `SWITCH` 的最后一行之后的第一行地址 `0x56559e78` 就是 `ret` 的返回地址。

  ![image-20220526212725314](https://s2.loli.net/2022/05/26/N63ZvzoXO7Cih9E.png)

- 在 `MIPS` 架构下，寄存器 `$ra` 的值由语句 `lw ra`, `PC(a1)` 装入进来，其中， `a1` 表示指向新线程的指针。
- Fork 方法分配一块固定大小的内存作为线程的堆栈，在栈顶放入 ThreadRoot 的地址。当新线程被调上 CPU 时，要用 SWITCH 函数切换线程图像， SWITCH 函数返回时，会从栈顶取出返回地址，于是将 ThreadRoot 放在栈顶，在 SWITCH 结束后就会立即执行 ThreadRoot 函数。ThreadRoot 是所有线程的入口，它会调用 Fork 的两个参数，运行用户指定的函数； Yield 方法用于本线程放弃处理机。 Sleep 方法可以使当前线程转入阻塞态，并放弃 CPU，直到被另一个线程唤醒，把它放回就绪线程队列。在没有就绪线程时，就把时钟前进到一个中断发生的时刻，让中断发生并处理此中断，这是因为在没有线程占用 CPU 时，只有中断处理程序可能唤醒一个线程，并把它放入就绪线程队列。
- 线程要等到本线程被唤醒后，并且又被线程调度模块调上 CPU 时，才会从 Sleep 函数返回，新取出的就绪线程有可能就是这个要睡眠的线程。例如，如果系统中只有一个 A 线程，A 线程在读磁盘的时候会进入睡眠，等待磁盘操作完成。因为这时只有一个线程，所以 A 线程不会被调下 CPU，只是在循环语句中等待中断。当磁盘操作完成时，磁盘会发出一个磁盘读操作中断，此中断将唤醒A 线程，把它放入就绪队列。这样，当 A 线程跳出循环时，取出的就绪线程就是自己。这就要求线程的正文切换程序可以将一个线程切换到自己， Nachos 的线程正文切换程序 SWITCH 可以做到这一点，于是 A 线程实际上并没有被调下CPU，而是继续运行下去了。



### 4. SWITCH 地址

-  **当调用 Fork() 新建的线程首次运行 SWITCH() 函数时，当执行到函数 SWITCH() 的最后一条指令ret 时，CPU 返回的地址是多少？ 该地址对应程序的什么 位置？**

- 设置断点 b SWITCH , 第一次进入 SWITCH 后，执行 c 进入到下一次调用 SWITCH 的位置。如下图，函数 Scheduler::Run 的地址 0x56556a26 就是 ret 返回的地址。

- ![image-20220526212910514](https://s2.loli.net/2022/05/26/y5fIi6bWuOV42tl.png)

- Scheduler::Run() 函数调用了 SWITCH() 函数，实现线程的上下文切换。Nachos 的主线程 main 中的语句 t->Fork(SimpleThread, 1) 调用 Thread::Fork() 创建了一个子线程（命名为 forked thread ），将子线程设为就绪状态并 进入就绪队列的尾部，子线程被调度时所执行的代码是 SimpleThread(1) ； 主 线 程 main 被 调 度 时 所 执 行 的 执 行 的 代 码 为 SimpleThread(0) ； 

- Thread::Yield () 中 将 子 线 程 从 就 绪 队 里 中 取 出： nextThread = scheduler- \>FindNextToRun() ，将主线程的状态从执行转到就绪并放入就绪队列尾 ： scheduler- \>ReadyToRun(this) ，将子线程设为执行状态： currentThread = nextThread， currentThread->setStatus(RUNNING) ，然后第调用 SWITCH() 将主线的上下文切换到 子线程的上下文，子线程开始执行： scheduler->Run(nextThread） 。这里的 SWITCH() 是第一次被调用。 这次 SWITCH() 的返回到 ThreadRoot() 的第一条指令处开始执行，由于子线程是 从头开始执行，因此 ThreadRoot() 是所有利用 Thread::Fork() 创建的线程的入口。 子线程开始执行后，后续与主函数发生的上下文切换都是从上次被中断的地方开 始执行，即Scheduler::Run() 中语句 SWITCH(oldThread, nextThread) 之后。

  

### 5. Extended tasks

Nachos 广泛采用线程的概念，是多线程操作系统。线程是 Nachos 处理机调度的单位，在Nachos 中线程分成两类，一类是系统线程。所谓系统线程是只运行核心代码的线程，它运行在核心态下，并且占用宿主机的资源，系统线程共享Nachos操作系统本身的正文段和数据段；一个系统线程完成一件独立的任务，比如在 Nachos 网络部分，有一个独立的线程一直监测有无发给自己的数据报。

Nachos 的另一类线程同 Nachos 中的用户进程有关。Nachos 中用户进程由两部分组成，核心代码部分和用户程序部分。用户进程的进程控制块是线程控制块基础上的扩充。每当系统接收到生成用户进程的请求时，首先生成一个系统线程，进程控制块中有保存线程运行现场的空间，保证线程切换时现场不会丢失。该线程的作用是给用户程序分配虚拟机内存空间，并把用户程序的代码段和数据段装入用户地址空间，然后调用解释器解释执行用户程序；由于 Nachos 模拟的是一个单机环境，多个用户进程会竞争使用 Nachos唯一的处理机资源，所以在 Nachos 用户进程的进程控制块中增加有虚拟机运行现场空间以及进程的地址空间指针等内容，保证用户进程在虚拟机上的正常运行。

当线程运行终止时，由于当前线程仍然运行在自己的栈空间上，所以不能直接释放空间，只有借助其他的线程释放自己。系统中，有两个与机器相关的函数，正文切换过程依赖于具体的机器，这是因为系统线程切换是借助于宿主机的正文切换，正文切换过程中的寄存器保护，建立初始调用框架等操作对不同的处理机结构是不一样的。其中一个函数是**ThreadRoot**，它是所有线程运行的入口；另一个函数是**SWITCH**，它负责线程之间的切换。**Scheduler** 类用于实现线程的调度。它维护一个就绪线程队列，当一个线程可以占用处理机时，就可以调用 ReadyToRun 方法把这个线程放入就绪线程队列，并把线程状态改成就绪态。FindNextToRun 方法根据调度策略，取出下一个应运行的线程，并把这个线程从就绪线程队列中删除。如果就绪线程队列为空，则此函数返回空(NULL)。现有的调度策略是先进先出策略(FIFO)，Thread 类的对象既用作线程的控制块，相当于进程管理中的 PCB，作用是保存线程状态、进行一些统计，又是用户调用线程系统的界面。



## Lab2 Nachos的MAKEFILES

在本节中学习了  `Nachos` 各文件夹的 `Makefile` 文件编写逻辑和组织逻辑，对一些常用的命令行有了初步的了解，对大型 `C++` 文件编译和链接的逻辑有了初步的了解，以下是对实验指导书中实操部分的报告：

- 迁移后的 `lab2` 目录文件：

![image-20220318222533740](https://s2.loli.net/2022/05/26/uxnC5yFTgGp2mBk.png)

- `make` :

![image-20220318222611862](https://s2.loli.net/2022/05/26/Y9vmo2LtyIlfRMz.png)

![image-20220318222653915](https://s2.loli.net/2022/05/26/5Et84O2TWzZxnB1.png)

- `touch scheduler.h && make`  :

![image-20220318222734189](https://s2.loli.net/2022/05/26/Y2uK3176cBPyEHX.png)

- `touch ../threads/scheduler.h && make` :

![image-20220318222826427](https://s2.loli.net/2022/05/26/irgGW3Q4xbR85Kp.png)



## Lab3 利用信号量实现线程同步

### 1. Nachos 创建线程的流程：

​		在本实验中，程序进入 `main` 后，调用函数 `ProdCons` 创建生产者线程和消费者线程。在函数 `ProdCons` 中，程序初始化了生产者线程和消费者线程需要使用到的同步信号量和互斥信号量，初始化了生产者线程和消费者线程所使用的共享环形缓冲区，然后使用两个 `for` 循环分别创建生产者线程和消费者线程，并将它们放到线程就绪队列中。

​		以创建生产者进程为例，首先使用线程类 `thread` 动态分配一个新对象，表示一个新线程，然后对该线程调用 `Fork` 函数，参数为线程分配到的执行内容及参数（生产者函数及参数）。在 `Fork` 函数中，程序先为线程分配函数堆栈（待执行对象的程序和数据堆栈），然后使用 `scheduler` 对象调用该线程，将其放入就绪队列中。在函数 `ReadyToRun` 中，函数首先把线程状态设置为就绪态 `READY`，然后调用 `Append` 方法将其放入就绪队列。

​		如下图所示，当函数 `ProdCons` 调用完毕后，实际上就完成了所有生产者线程和消费者线程的创建过程。

~~~~bash
After function ProdCons, invoke Scheduler->Print():
~~~ 
Now all threads for producers and customers are created.
Ready list contents:
producer_0, producer_1, producer_2, consumer_0, consumer_1,
~~~
~~~~



---



### 2. 信号量 `P & V` 操作的实现：

​		本实验一共涉及到 3 个信号量：互斥信号量 `mutex`，同步信号量 `nfull` 与 `nempty` 。信号量的私有属性有信号量的值，它是一个阀门。线程等待队列中存放所有等待该信号量的线程。信号量有两个操作：`P` 操作和 `V` 操作，这两个操作都是原子操作。

- `P` 操作：① 当 `value == 0` 时，将当前运行线程放入线程等待队列，当前线程进入睡眠状态，并且切换到其它线程运行。② 当 `value > 0` 时，`value--`。
- `V` 操作：① 如果线程等待队列中有等待该信号量的线程，取出其中一个将其设置成就绪态，准备运行。② `value++`。



---



### 3. Nachos 如何创建与使用信号量：

- `Nachos` 需要两个同步信号量和一个互斥信号量，信号量的创建在全局变量中：

  ~~~c++
  Semaphore *nempty, *nfull; //two semaphores for empty and full slots
  Semaphore *mutex;          //semaphore for the mutual exclusion
  ~~~

- 信号量的初始化在线程创建函数 `ProdCons` 中，表示当前信号量只有生产者线程和消费者线程使用：

  ~~~c++
  mutex = new Semaphore("mutex", 1);
  nfull = new Semaphore("nfull", 0);
  nempty = new Semaphore("nempty", BUFF_SIZE);
  ~~~

- 对于单个生产者线程，信号量的使用如下：

  ~~~c++
  nempty->P();
  mutex->P();
  ring->Put(message);
  mutex->V();
  nfull->V();
  ~~~

  其中，两个互斥信号量必须在生产操作 `ring->Put(message);` 的紧挨着的两边，保证该操作是原子的，防止了死锁的出现。`nempty->P()` 表示生产消息之前先把缓冲区的空闲量 `-1`， `nfull->V()` 表示生产结束后把缓冲区消息量 `+1`。

- 对于单个消费者线程，信号量的使用如下：

  ~~~
  nfull->P();
  mutex->P();
  ring->Get(message);
  mutex->V();
  nempty->V();
  ~~~

  其设置逻辑与生产者线程类似。



---



### 4. Nachos 信号量机制

​		当执行命令为 `./nachos` 时，生产者线程和消费者线程按照 `FCFS` 规则调度，即生产者线程先依次填满缓冲区，消费者线程再依次取出缓冲区，然后生产者线程再依次填满缓冲区，如此循环。由于消费者线程中的循环设置为：

~~~c++
    for (; ; ) {
        ......
    }
~~~

​		因此，**即使有多个消费者线程，也永远只有第一个消费者能够占据处理机运行。**

​		考虑第一轮，打印中间调试信息，其执行顺序如下：

~~~~c++
~~~
===========================================
Now in thread "producer_0"
Ready list contents:
producer_1, producer_2, consumer_0, consumer_1, 
producer_0 put msg 0
producer_0 put msg 1
producer_0 put msg 2
producer_0 put msg 3
producer_0 put msg 4

===========================================
Now in thread "producer_1"
Ready list contents:
producer_2, consumer_0, consumer_1, 

===========================================
Now in thread "producer_2"
Ready list contents:
consumer_0, consumer_1, 

===========================================
Now in thread "consumer_0"
Ready list contents:
consumer_1, 
consumer_0 get msg 0
consumer_0 get msg 1
consumer_0 get msg 2
consumer_0 get msg 3
consumer_0 get msg 4

===========================================
Now in thread "consumer_1"
Ready list contents:
producer_1, producer_2, 

~~~
~~~~

​		可以发现，当缓冲区大小为 `5` 时，第一轮执行顺序为 `producer_0 -> producer_1 -> producer_2 -> consumer_0 -> consumer_1 `，其中，`producer_0` 在第一轮就填满了缓冲区，因此其工作完毕后， `producer_1` 和 `producer_2` 都不会执行，这两个线程会先从就绪队列中取出，查询缓冲区是否还有余量，发现并没有，然后会调用信号量 `P` 操作的 `currentThread->Sleep();` 函数，进入睡眠状态。

![image-20220320164908595](https://s2.loli.net/2022/05/26/avdshLXjCPlp94G.png)

​		在 `Sleep` 方法中，线程的状态设置为 `BLOCKED` ，**此时线程并没有放回到就绪队列中，而是在 `while` 循环中不断等待就绪队列中的下一个线程运行**，直到下一个线程运行完毕，就绪队列中没有线程后，阻塞的线程才会继续运行。

​		观察第二轮的输出结果：

~~~~c++
~~~
===========================================
Now in thread "producer_1"
Ready list contents:
producer_2, 
producer_1 put msg 0
producer_1 put msg 1
producer_1 put msg 2
producer_1 put msg 3
producer_1 put msg 4

===========================================
Now in thread "producer_2"
Ready list contents:
consumer_0, consumer_1, 

===========================================
Now in thread "consumer_0"
Ready list contents:
consumer_1, 
consumer_0 get msg 0
consumer_0 get msg 1
consumer_0 get msg 2
consumer_0 get msg 3
consumer_0 get msg 4
    
===========================================
Now in thread "consumer_1"
Ready list contents:
producer_2, 

~~~
~~~~

​		由于第一轮中线程 `producer_0` 已经运行完毕，于是第二轮是线程 `producer_1` 上处理机运行（按照被阻塞的顺序），线程 1 生产完毕后，消费者线程 `consumer_0` 取走生产出的消息。

​		第三轮的输出结果为：

~~~
===========================================
Now in thread "producer_2"
Ready list contents:

producer_2 put msg 0
producer_2 put msg 1
producer_2 put msg 2
producer_2 put msg 3
producer_2 put msg 4

===========================================
Now in thread "consumer_0"
Ready list contents:
consumer_1, 
consumer_0 get msg 0
consumer_0 get msg 1
consumer_0 get msg 2
consumer_0 get msg 3
consumer_0 get msg 4

===========================================
Now in thread "consumer_1"
Ready list contents:

~~~

​		规律如同以上分析，第三轮中只有线程 `producer_2` 在生产，消费者 `consumer_0` 紧随其后取走缓冲区的内容，当生产者线程全部结束后，只留下消费者线程 `consumer_0` 在原地踏步等待，而 `consumer_1` 及之后的线程则在就绪队列中等待（但永远没有机会占据处理机，除非更改消费者线程的执行函数，如 `for` 循环的退出条件）。



---

### 5. Nachos 中如何测试与调试程序：

- 首先是可以使用 `gdb` 命令，在相应函数口设置断点，观察程序在整个过程中需要进过哪些步骤，在哪些步骤处变量的值发生了改变，根据变量的值改变情况梳理程序的执行逻辑与出错点。

- 其次，可以在关键函数处打印相应的提示信息，例如，可以在函数 `ProdCons` 的末尾执行 `scheduler->Print()` 观察当前就绪队列中有哪些线程，以此来观察线程的创建顺序。

- 由于直接使用 `print` 在控制台打印不方便其它模块调试，因此可以使用内置的 `DEBUG` 方法，例如，如果要在某个调试点打印如下内容：

  ~~~c
  printf("%s get msg %d\n", currentThread->getName(), message->value);
  ~~~

  则可以改为：

  ~~~c++
  DEBUG('m', "%s get msg %d\n", currentThread->getName(), message->value);
  ~~~

  然后，在控制台使用如下命令：

  ~~~bash
  ./nachos -d m
  ~~~

  就可以自定义调试输出了。



---



### 6. Nachos 中时间片轮转法（RR）的实现：

​		在之前的操作中，`Nachos` 总是按照 `FCFS` 来调度线程的，即按照线程创建的顺序来调度，如果有线程被阻塞，就按照其阻塞的顺序来唤醒。这样做的缺点是降低了系统的并发性和效率，实际的操作系统需要根据各个线程优先级、执行时间来完成调度，放置低优先级、运行时间长的线程占据处理机过长时间。 `Nachos` 中实现了时间片轮转法调度 `RR` ，使用如下命令可以执行时间片轮转的线程调度算法：

~~~
./nachos -rs <random seed #>
~~~

​		其中， `<random seed #>` 是一个随机种子，例如 ，可以输入 `10`。下面从几个方面来介绍该算法：

- 时钟中断模块（文件 `timer.cc  timer.h`）

  该模块的作用是模拟时钟中断。Nachos 虚拟机可以如同实际的硬件一样，每隔一定的时间会发生一次时钟中断。这是一个可选项，目前 Nachos 还没有充分发挥时钟中断的作用，只有在 Nachos 指定线程随机切换时启动时钟中断，在每次的时钟中断处理的最后，加入了线程的切换。**时钟中断相当于机器的脉搏，只有每隔一段时间发生了时钟中断，机器才有机会停下当前的事去思考下一步该干什么。**

  时钟中断间隔由 `TimerTicks` 宏决定（100倍 `Tick` 的时间）。在系统模拟时，如果系统就绪进程不止一个的话，每次时钟中断都一定会发生进程的切换，定义在 `system.cc` 中 `TimerInterruptHandler` 函数：

  ~~~c++
  TimerInterruptHandler(_int dummy)
  {
      if (interrupt->getStatus() != IdleMode)
  	interrupt->YieldOnReturn();
  }
  ~~~

  所以运行 Nachos时，如果以同样的方式提交进程，系统的结果将是一样的。这不符合操作系统的运行不确定性的特性。所以在模拟时钟中断的时候，加入了一个**随机因子**，如果该因子设置的话，时钟中断发生的时机将在一定范围内是随机的。这样有些用户程序在同步方面的错误就比较容易发现。但是这样的时钟中断和真正操作系统中的时钟中断将有不同的含义。不能像真正的操作系统那样通过时钟中断来计算时间等等。是否需要随机时钟中断可以通过设置选项 `-rs` 来实现。

​		Timer 类的设计如下：

- ```c++
  class Timer {
    public:
    	// 初始化方法
      Timer(VoidFunctionPtr timerHandler, _int callArg, bool doRandom);
      ~Timer() {}
      // 发生时钟中断时调用
      void TimerExpired();
      // 计算下一次时钟中断发生的时间
      int TimeOfNextInterrupt();  
    private:
      // 是否需要随机时钟中断标志
      bool randomize;	
      // 时钟中断处理函数
      VoidFunctionPtr handler;
      // 时钟中断处理函数的参数
      _int arg;			
  };
  ```

- 当设置参数 `-rs` 后，实际上时钟中断处理类成员 `randomize` 被设置为 `doRandom`，`TimerHandler` 会调用函数 `TimerExpired` 处理中断，之所以不直接调用 `TimerExpired`， 是因为 `C++` 不允许直接引用一个类内部方法的指针，要想**单独保存函数和参数**，就必须嵌套一层来调用。

  在 `TimerExpired` 中有如下调用：

  ~~~
  interrupt->Schedule(TimerHandler, (_int) this, TimeOfNextInterrupt(), TimerInt);
  (*handler)(arg);
  ~~~

  `interrupt->Schedule` 函数做了如下操作：

  - 设置时钟中断 `TimerHandler` 的发生时间为 `when = stats->totalTicks + TimeOfNextInterrupt()` 
  - 创建一个新中断，其处理函数为 `TimerHandler`，参数为 `(_int) this`，发生时间为 `when` ，中断类型为 `TimerInt`
  - 将创建的新中断插入到中断就绪队列中

  因此，当创建了一个时钟中断类后，其构建函数首先调用了 `timerHandler` 方法，然后该方法继续调用了 `TimerExpired` 方法，该方法插入了一个随机时间后会发生的中断，同时又调用了 `timerHandler` 方法执行中断，该方法又调用 `TimerExpired` 方法插入一个随机时间后会发生的中断，不断往复，实现了系统时钟中断发生和处理模块的构造。

- 计算下一个中断将要发生的时间的方法如下：

  ~~~
  ===============================================
  define TimerTicks 	100
  ===============================================
  int Timer::TimeOfNextInterrupt() 
  {
      if (randomize)
  		return 1 + (Random() % (TimerTicks * 2));
      else
  		return TimerTicks; 
  }
  ===============================================
  int Random()
  {
      return rand();
  }
  ===============================================
  void RandomInit(unsigned seed)
  {
      srand(seed);
  }
  ===============================================
  ~~~

  在 `Nachos` 中，命令 `-rs` 的参数调用了 `RandomInit` 函数，生成了随机种子然后函数 `TimeOfNextInterrupt` 调用 `rand` 函数，基于随机种子生成了随机数 `Random()` ，最终得到的时间是一个 `1 ~ 201` 之间的数，即每隔这个时间就生成一个时钟中断，将当前线程让出处理机，调度下一个线程上处理机运行。

- 如何实现线程的轮转：

  当插入时钟中断到中断队列后，接下来就是执行中断的模块。中断等待队列是 Nachos 虚拟机最重要的数据结构之一，它记录了当前虚拟机可以预测的将在未来发生的所有中断。当系统进行了某种操作可能引起未来发生的中断时，如磁盘的写入、向网络写入数据等都会将中断插入到中断等待队列中；对于一些定期需要发生的中断，如**时钟中断**、终端读取中断等，系统会在中断处理后将下一次要发生的中断插入到中断等待队列中。中断的插入过程是一个优先队列的插入过程，其优先级是中断发生的时间，也就是说，**先发生的中断将优先得到处理**。当时钟前进或者系统处于 Idle 状态时，Nachos 会判断中断等待队列中是否有要发生的中断，如果有中断需要发生，则将该中断从中断等待队列中删除，调用相应的中断处理程序进行处理。

![image-20220320180158683](https://s2.loli.net/2022/05/26/5qaLnWPviSA7tlB.png)

- 系统每执行一个操作，都会将时钟滴答一次：`OneTick`，而在该函数中，又存在如下语句：

  ~~~
  while (CheckIfDue(FALSE));		// check for pending interrupts
  ~~~

  该语句检查中断就绪队列中的中断，如果某条中断应该在当前时间点发生，则执行它；否则，什么也不做。实际上，中断处理类 `Timer` 的构造函数中使用了中断处理函数 `TimerInterruptHandler`，其方法定义如下：

  ~~~
  static void TimerInterruptHandler(_int dummy)
  {
      if (interrupt->getStatus() != IdleMode)
  	interrupt->YieldOnReturn();
  }
  ~~~

  它表明，只要处理了该时钟中断，就需要当前线程让出处理机，具体的方法在函数 `YieldOnReturn` 中。



## Lab4 Nachos 的文件系统

### 1. Nachos 的硬盘是如何创建的

1. 磁盘设备模拟了一个物理磁盘。Nachos 用宿主机中的一个文件来模拟一个单面物理磁盘，该磁盘由道组成，每个道由扇区组成，而每个扇区的大小是固定的。和实际的物理磁盘一样，Nachos 以扇区为读取/写入的最小单位，每个扇区有唯一的扇区地址，具体的计算方法是：

   ~~~
   SectorSize * sectorNumber + MagicSize
   ~~~

   该物理磁盘是一个异步的物理磁盘，同终端设备和网络设备一样，当系统发出读磁盘的请求，立即返回，只有具体的磁盘终端到来的时候，整个过程才算结束。

- 磁盘开始的4个字节是硬盘标识，其值为0x456789ab，用于指明该硬盘是一个 Nachos 硬盘：

  ![image-20220401153541280](https://s2.loli.net/2022/05/26/8jO45Ha3XvuwBPe.png)

  Nachos 在文件 `disk.cc` 中定义了磁盘类 `Disk` 的具体方法，具体包括初始化、销毁、读/写特定扇区、计算读写磁盘时间。初始化磁盘时，除初始化一些必要的参数外，还通过系统调用新建/打开一个名为 `*name` 的文件，该文件就是 Nachos 模拟的磁盘。由于在 FCB 中可以通过文件名来定位 iNode，因此通过文件名可唯一访问磁盘。新建文件后，首先把把 `MagicNumber` 写入到开始位置，然后将文件指针便宜磁盘大小 `DiskSize` 的位移定位到文件尾，在文件尾写入 `0`，实际上代表 `EOF` 标志。

  > Nachos 中磁盘读写时间 = 寻道时间 + 扇区定位时间 + 数据传输时间。由于 Nachos 只是模拟了磁盘的物理结构，读写数据时以扇区为单位，因此对于给定的地址应计算磁道便宜量+扇区偏移量，并计算各自的时间。同时，定位磁道时，磁针有可能处于扇区中间，此时 Nachos 也模拟了扇区对准的时间。对准扇区后，再循环磁盘定位目标扇区。

- 磁盘 `Disk` 大小为 `DiskSize = MagicSize + (NumSectors * SectorSize) `，Nachos 并没有直接访问物理地址，而是通过偏移量来模拟磁盘地址的。



### 2. 查看 Nachos 硬盘上内容的方法

- `./nachos -D` : 显示硬盘 DISK 中的文件系统；

- `od -c DISK` : 每一行输出 16 个字符，字符在文件中的偏移量（左边数字）以 8 进制表示； 

  ![image-20220406093316950](https://s2.loli.net/2022/05/26/Xc1Mgk5Wi2qU3uy.png)

- `hexdump -c DISK` : 每一行输出 16 个字符，字符在文件中的偏移量（左边数字）以 16 进制表示；

  ![image-20220406093410999](https://s2.loli.net/2022/05/26/xR4HCP6uLvkJDpG.png)

- `hexdump -C DISK` : 每一行输出 16 个字符，以 ASCII 形式输出文件内容。

  ![image-20220406093448360](https://s2.loli.net/2022/05/26/efw4RjPOaXQCUvY.png)



### 3. 硬盘初始化的过程

- Nachos 在 `disk.cc` 中调用构造函数初始化磁盘，通过打开文件并赋予该文件特定的大小来模拟磁盘大小，具体的初始化流程在 `1` 中介绍。对于文件系统，传入参数为 `-f` 时，Nachos 在函数 `Initialize` 中执行 `bool format = FALSE;` 接着调用 `synchDisk = new SynchDisk("DISK");` 初始化磁盘，该类的私有成员包括磁盘类 `Disk` ，用于读写的锁和信号量，方法包括读扇区、写扇区、读写扇区完毕后的后处理操作。在其后调用 `fileSystem = new FileSystem(format);` 初始化了文件系统。

  > 读写完毕后，要把信号量增加或把锁释放。

- Nachos 模拟的磁盘是异步设备。当发出访问磁盘的请求后立刻返回，当从磁盘读出或写入数据结束后，发出磁盘中断，说明一次磁盘访问真正结束。Nachos 是一个多线程的系统，如果多个线程同时对磁盘进行访问，会引起系统的混乱。所以必须作出这样的限制：同时只能有一个线程访问磁盘当发出磁盘访问请求后，必须等待访问的真正结束。这两个限制就是实现同步磁盘的目的。

- 当线程向磁盘设备发出读访问请求后，等待磁盘中断的到来。一旦磁盘中断来到，中断处理程序执行semaphore->V()操作，ReadSector 得以继续运行。对磁盘同步写也基于同样的原理。在 `Disk` 构造函数中，Nachos 将引导块和大小写入磁盘中；在 `FileSystem` 构造函数中，Nachos 将位图、根目录文件写入其中：

  语法： FileSystem (bool format)
  参数： format: 是否进行格式化的标志
  功能： 在同步磁盘的基础上建立一个文件系统。当 format 标志设置时，建立一个新的文件系统；否则使用原来文件系统中的内容。具体有：

  - 如果 format 标志没有设置，则使用原有的文件系统
  - 打开位图文件和目录文件，返回
  - 2 如果 format 标志设置，则生成一个新的文件系统
  - 生成新的位图和空白的根目录
  - 生成位图 FileHeader 和目录 FileHeader
  - 在位图中标识 0 和 1 号扇区被占用（虽然此时还没有占用）
  - 为位图文件和目录文件申请必要的空间，如果申请不到，系统出错返回
  - 将位图 FileHeader 和目录 FileHeader 写回 0 和 1 号扇区（这时候位图文件和
  - 目录文件所在的位置已经确定）
  - 打开位图文件和目录文件
  - 将当前的位图和目录写入相应的文件中（位置确定，内容终于可以写入）而
  - 且这两个文件保持打开状态

  

### 4. 了解 Nachos 文件系统提供了哪些命令

​		目前 Nachos 已实现初始化磁盘、挂载文件、删除文件、打印磁盘内容、查看位示图文件、按不同格式打印文件等操作。还需要实现扩展文件系统等操作。



### 5. 文件系统命令的实现原理

~~~
class FileSystem {
  public:
    FileSystem(bool format);                     // 生成文件系统
    bool Create(char *name, int initialSize);    // 生成一个文件
    OpenFile* Open(char *name);                  // 打开一个文件
    bool Remove(char *name);                     // 删除一个文件
    void List();                                 // 列出文件系统所有文件
    void Print();                                // 列出文件系统所有文件及其内容
  private:
   OpenFile* freeMapFile;                        // 位图文件打开结构
   OpenFile* directoryFile;                      // 根目录文件打开结构
};
~~~

- `Create` 方法：在当前的文件系统中创建一个固定大小的文件。首先，在根目录下搜寻该文件名，如果搜索到，出错返回；如果没有搜索到，申请文件 FileHeader 所需的空间，为新文件申请 FileHeader，根据新文件的大小申请相应块数的扇区，将所有有变化的数据结构写入磁盘。最终，如果生成成成功，返回 TRUE，否则返回 FALSE。

  > 在 Nachos 的文件系统中，对目录对象和位图对象的操作应该是临界区操作。因为如果两个线程同时需要向同一个目录中写入一个文件，可能会出现两个线程同时申请到同一个目录项；在空闲块分配时，也会出现相类似的情况。但是目前 Nachos 没有对此进行处理。

- `Open` 方法：在当前的文件系统中打开一个已有的文件，首先在根目录下搜寻该文件名，如果搜索到，寻找其对应的扇区位置，然后打开该文件并返回打开文件结构。

- `Remove` 方法：在当前的文件系统中删除一个已有的文件，首先在根目录下搜寻该文件名，如果没有搜索到，返回 FALSE；反之，如果搜索到，打开该文件并返回打开文件控制块，将该文件从目录中删除，释放 FileHeader 所占用的空间，释放文件数据块占用的空间，将对位图和目录的修改写回磁盘。如果删除成功，返回 TRUE；否则返回 FALSE。





### 6. 硬盘空闲块的管理方法

- 硬盘采用位示图（BitMap）的思想管理硬盘的空闲块，即根据硬盘的扇区数建立一个位置图，当一个扇区空闲，位示图中对应的位为 0，否则为 1。位示图也是一个文件，由文件头+数据块组成，文件头保存在第 0 号扇区中，数据块存放位示图数据。

- 由于硬盘共有 1024 个扇区，需要 1024 位表示每个扇区的状态，因此位示图文件大小应为 1024/8=128 字节，故位示图文件也可以恰好存储在一个扇区中。

  ~~~
  class BitMap {
    public:
      BitMap(int nitems);	 // 初始化位图，将所有位置0
      ~BitMap();
      void Mark(int which);  // 标记第 which 位为占用
      void Clear(int which); // 清除第 which 位的占用状态 
      bool Test(int which);  // 测试第 which 位是否被占用
      int Find();            // 从头开始找第一个未被占用的位，标志其为占用
      int NumClear();        // 返回还有多少位空闲
      void Print();          // 打印位图
  
      void FetchFrom(OpenFile *file); 	// 读位图
      void WriteBack(OpenFile *file); 	// 写位图
  
    private:
      int numBits;          // 8
      int numWords;         // 32
      unsigned int *map;    
  };
  ~~~

  



### 7. 目录文件的结构与管理

- 一般的文件系统都采用树状目录结构，有的 UNIX 文件系统还有目录之间的勾连，形成图状文件系统结构。Nachos 则比较简单，只有一级目录，也就是只有根目录，所有的文件都在根目录下。而且根目录中可以存放的文件数是有限的。Nachos 文件系统的根目录同样也是通过文件方式存放的，它的 inode 占据了 1 号扇区。

- Nachos 采用一级目录表结构，目录表中的每个单元是一个名为 `DirectoryEntry` 的结构：

  ~~~
  class DirectoryEntry {
    public:
      bool inUse;                      // 文件是否被占用(1B)
      int sector;                      // 文件头所在扇区号(4B)
      char name[FileNameMaxLen + 1];   // 文件名称(9+1=10B)
  };
  ~~~

  文件目录表大小由下语句定义：

  ~~~
  #define NumDirEntries 		10
  #define DirectoryFileSize 	(sizeof(DirectoryEntry) * NumDirEntries)
  ~~~

  由于C++有空间对其操作，因此 `sizeof(DirectoryEntry) == 20` ，理论上来说，文件目录表所占空间最大可以是10条记录即10*20=200B，但由于 Nachos 限制了根目录文件头只能在第二个扇区，因此实际上只能容纳128/20=6个文件。当访问一个文件时，根据文件名查找目录表，找到该文件文件头所在的扇区号， 文件头中包含了文件大小、文件数据所占用的块数以及为文件数据所分配的盘块号。当删除一个文件时，只是将该文件对应的目录项中的 inUser 标记位清 0，其余两项并没有清除，便于文件的恢复。



### 8. 文件的结构与文件数据块的分配方法

- 一个文件由 ”文件头+数据块“ 组成，文件头相当于 `iNode`，说明文件的具体属性以及文件的数据块在硬盘上的位置信息，`Nachos` 的文件头结构如下：

  ~~~
  int numBytes;                   // 文件大小，以字节为单位(4B)
  int numSectors;	                // 文件所分配的扇区数(4B)
  int dataSectors[NumDirect];     // 文件每个数据块所对应的扇区号(120B)
                                  // 总：128B
  ~~~

  一个文件头限制最多占一个扇区，文件的扇区分配索引表最大空间为120B，因此一个文件最多占30个扇区，即30*128KB=3840B。Nachos 分配文件数据块时采用了 UNIX 中的直接块管理方式，一个文件的各数据块可以存放到不同的扇区中，但系统为文件分配数据块时，尽量将文件的数据分配到连续的扇区中，并依次将各数据块所在的扇区号记录在数组 `dataSectors[NumDirect]` 中。



### 9. 一个文件系统命令执行后硬盘的布局

- `hexdump -C DISK` :

  ![image-20220406102649958](https://s2.loli.net/2022/05/26/qpV3BNOCPzdE2kF.png)

- `nachos -cp test/small small` :

  ![image-20220406101034571](https://s2.loli.net/2022/05/26/z71JOyAcwYFZHEi.png)

- `nachos -cp test/medium medium` :

  ![image-20220406101108847](https://s2.loli.net/2022/05/26/ES5DX1O97VvuUkB.png)

- `nachos -cp test/big big` :

  ![image-20220406104111549](https://s2.loli.net/2022/05/26/lF1oRtvYQ7NsxWe.png)

  ![image-20220406101147909](https://s2.loli.net/2022/05/26/FykR2OZNfJsP9W5.png)

- 当系统中同时有 3 个文件时，磁盘的前三个扇区内容如下所示：

  ![image-20220406101730180](https://s2.loli.net/2022/05/26/EKF48Swt5Cxh7Bl.png)

  - `0x0~0x3 字节`：硬盘开始的 4 个字节（0x0~0x3）是该磁盘的标识（ MagicNumber ）， 为0x456789ab，显然数据采用小端存储。

  - `0x4~0x83`：扇区 0，128 字节；存放位示图文件头（FCB，i-node）；文件头由三部分组成：（int numBytes, int numSectors, int dataSectors[NumDirect];），即文件头所描述的三元组<文件的大小，占用的扇区数，各数据块所在扇区列表>，对应如下：

    - `0x4~0x7`：4 个字节，位示图文件所占的字节数，值为 0x80，表示位示图文件大小为 0x80=128 字节；
    - `0x8~0xB`：4 个字节，系统为位示图文件数据所分配的扇区数，其值为 0x1，表示位示图文件数据只需要一个扇区；
    - `0xC~0xF`：位示图文件数据块所在的扇区号，其值为 0x2，说明系统将位示图文件的数据保存在第 2 号扇区中。

  - `0x84~0x103`：扇区 1，128 字节；存放目录表文件头；对应文件头由三部分（int numBytes, int numSectors, int dataSectors[NumDirect]）如下：

    - `0x84~0x87`：4 个字节，目录表文件大小，值为 0xC8，表示目录表文件大小为 0xC8=200 字节；
    - `0x88~0x8B`：4 个字节，系统为存放目录表所分配的扇区数，其值为 0x02，表示目录文件数据需要 2 个扇区（目录文件大小为 200 字节，需要占用两个扇区）；
    - `0x8C~0x8F`：系统为目录表的前半部分分配的扇区号，其值为 0x3；
    - `0x90~0x93`：系统为目录表的后半部分分配的扇区号，其值为 0x4；

  - `0x104~0x183`：扇区 2，128 字节；位示图的数据块，存储位示图文件内容，值为 0xff ff。

  - `0x184~0x203`扇区 3 & `0x204~0x283`扇区 4：这两个扇区存放目录表，其值如下：

    ![image-20220406104439437](https://s2.loli.net/2022/05/26/VwT4EaLXe8Yxr3B.png)

​			每一个目录项占用空间为 20 字节，注意到目录项的内容为：

~~~
class DirectoryEntry {
  public:
    bool inUse;                      // 文件是否被占用(1B)
    int sector;                      // 文件头所在扇区号(4B)
    char name[FileNameMaxLen + 1];   // 文件名称(9+1=10B)
};
~~~

​			由于对齐操作，0x05 表示第一个文件头所在扇区为第 5 号，0x73 6d 61 6c 6c 对应的 ASCII 码为 `small` ，存放该文件的名称；最后四个字节值为 0x01，表示该文件已被占用；同理，第二个文件头所在扇区为第 7 号，第三个文件头所在扇区为第 10 号。

​			再执行 `nachos -D` :

![image-20220406105353717](https://s2.loli.net/2022/05/26/423szOIwDmuc67N.png)

​			可以发现，此时系统中存在 3 个文件，前 16 个扇区被占用，各文件所占扇区分别为 6、8~9 、11~15.





### 10. 目前 Nachos 不能对文件进行扩展的原因及解决方案

- 一个文件的大小是在创建时定的，在header，allocate时候，传入参数fileSize，按fileSize分配恰好合适大小的扇区数量；在openfile的write时，当写的位置超过fileSize时，会直接切掉超出部分，只是write不超出部分；所以一个文件的大小从创建开始是不会改变的，这导致 Nachos 文件扩展困难。





![QQ图片20220401140027](https://s2.loli.net/2022/05/26/7ra52tjqvoOnhBS.png)



---

### 思考1

为什么将空闲块管理的位示图文件头，与目录表文件头存放在0号与1号这两个特殊的扇区中？

由于系统启动时需要根据目录文件的文件头访问根目录，因此为这两个特殊的结构分配到 0 号扇区与 1 号扇区这两个特殊的扇区中，是为了便于系统启动时从已知的、固定的位置访问它们。系统启动时可以很快地将它们装载入程序中，根据位示图文件头查找位示图的位置，去位示图中查看哪些扇区是空闲的，哪些扇区是满的；根据目录表文件头查找根目录表，去目录表中寻找文件信息。



### 思考2

Nachos 文件系统设计上的不足。

- 必须在文件生成时创建索引表。所以 Nachos 在创建一个文件时，必须给出文件的大小；而且当文件生成后，就不能改变文件的大小。
- 目前该文件系统没有 Cache 机制目前文件系统的健壮性不够强。
- 当正在使用文件系统时，如果突然系统中断，文件系统中的内容可能不保证正确。



## Lab5 扩展 Nachos 的文件系统

### 1. 结果演示

- **nachos [-d f] –ap Unix_filename Nachos_filename**

  > 该命令的功能是将一个 UNIX 文件（unix_filename）附加到一个 Nachos 文件（nachos_filename）的后面，目的是用来测试当我们在一个 Nachos 的文件尾部追加数据后，文件大小是否会增加；

  	`rm -rf DISK && make clean && make && nachos -f && nachos -cp test/small small && hexdump -C DISK` ：

![image-20220408152517147](https://s2.loli.net/2022/04/08/RSUH7zl5siCYVKf.png)

​	  `nachos -ap test/small small && hexdump -C DISK` ：

![](https://s2.loli.net/2022/05/26/Xp4AQv5Go8jV1Wm.png)

​		可以发现，small 文件在原有文件的基础上进行了扩展，文件大小由 `0x54` 变成了 `0xa8`，是原来的 2 倍。

 	  `rm -rf DISK && make clean && make && nachos -f && nachos -cp test/empty empty && hexdump -C DISK` :

![image-20220408160332337](https://s2.loli.net/2022/05/26/kNM6fagXCAFxUT9.png)

​		可以发现，挂载空文件的操作也得到了实现。



- **nachos [-d f] –hap Unix_filename Nachos_filename**

  > 该命令的功能是从一个 Nachos 文件（nachos_filename）的中间（文件大小的 1/2）位置开始，将一个 UNIX 文件（unix_filename）写入到该 Nachos 文件中。如果这个UNIX 文件大于 Nachos 文件的一半，则该目录执行后，新的 Nachos 文件的大小将增加。 

​	  `rm -rf DISK && make clean && make && nachos -f && nachos -cp test/medium medium && hexdump -C DISK` ：

![image-20220408155929700](https://s2.loli.net/2022/04/08/XDEugTqpzo2FB4J.png)

​	  `nachos -hap test/big medium && hexdump -C DISK` :

![image-20220408155955494](https://s2.loli.net/2022/05/26/2u8cGFSPmaxHv7U.png)

​		可以发现，该操作将 big 文件从 medium 文件的中间往后覆盖写入，并且文件长度实现了扩展。

- **nachos [-d f] –nap Nachos_filename1 Nachos_filename1**

  > 该命令的功能是将一个 Nachos 文件（unix_filename1）附加到一个 Nachos 文件(nachos_filename2)的后面，目的是用来测试当我们在一个 Nachos 的文件尾部写入数据时，文件大小是否会增加；

​	 `rm -rf DISK && make clean && make && nachos -f && nachos -cp test/small small && nachos -cp test/medium medium && hexdump -C DISK` ：

![image-20220408161135754](https://s2.loli.net/2022/05/26/EXYfABnLVuJUbig.png)

​	  `nachos -nap small medium && hexdump -C DISK ` :

![image-20220408161154244](https://s2.loli.net/2022/05/26/4UaPWyqxCSuQipr.png)

可以发现，small 文件已经挂载到了 medium 文件的尾部，文件大小得到了扩充。



### 2. 实现过程

1. 当传入参数为 `-ap` 时，主程序中实际调用了函数 `Append` ，理解该函数的实现逻辑，需要扩充以下点：

   ~~~
   (1) Append() 函数调用了OpenFile::Write()，OpenFile::Write()又调用了OpenFile::WriteAt()，因此考虑如何修改OpenFile::WriteAt()成员函数以实现；
   (2) 在 Append() 函数中实现 while 读写逻辑，每次从读文件中获取特定大小的数据，循环写入写文件中。
   ~~~


   （1）Append() 函数中 whlie 循环的实现：

   ~~~
buffer = new char[TransferSize];
    while ((amountRead = fread(buffer, sizeof(char), TransferSize, fp)) > 0) 
    {
        int result;
        result = openFile->Write(buffer, amountRead);  //**********//
        // 文件过大，或空闲磁盘块不足
        if (result < 0)
        {
            printf("---ERROR---\n");
            printf("Insufficient Disk Space, or File is Too Big\n");
            printf("Writing Terminated\n");
            printf("----------\n");
            break;
        }
        ASSERT(result == amountRead);
        // 每次写操作都从上次写入的数据之后开始进行
        start += amountRead;
    }
    delete [] buffer;
   ~~~

   （2）openFile->Write(buffer, amountRead) 函数的实现：

   ~~~
int OpenFile::Write(char *into, int numBytes)
{
   int result = WriteAt(into, numBytes, seekPosition);  //**********//
   seekPosition += result;
   return result;
}
   ~~~

   （3）WriteAt(into, numBytes, seekPosition) 函数的实现：

   ~~~
int OpenFile::WriteAt(char *from, int numBytes, int position)
{
    int fileLength = hdr->FileLength();
    int i, firstSector, lastSector, numSectors;
    bool firstAligned, lastAligned;
    char *buf;

    if ((numBytes <= 0) || (position > fileLength))
    	return -1;
    // 如果条件 (position + numBytes) > fileLength 成立，说明文件需要扩展
    if ((position + numBytes) > fileLength) 
    {
    	// 计算文件需要扩展的大小
        int incrementBytes = (position + numBytes) - fileLength;
        // 取出位示图文件（自己实现）
        BitMap *freeBitMap = fileSystem-> getBitMap();//**********//
        bool hdrRet;
        // 扩充文件，修改位示图（自己实现）
        hdrRet = hdr->Allocate(freeBitMap, fileLength, incrementBytes);//**********//
        if ( !hdrRet ) // Insuficient Disk Space, or File is Too Big
            return -1;
        // 修改位示图，写入磁盘（自己实现）
        fileSystem-> setBitMap(freeBitMap);//**********//
    }
    
	// ......
}
   ~~~

   （4）getBitMap 和 setBitMap 函数的实现：

   - 当文件需要扩展时，获取空闲块位示图文件（BitMap *freeBitMap = fileSystem-> getBitMap()），然后判断是否需要为写入数据新分配扇区，如果需要为扩展数据新分配扇区，就修改新分配扇区在位示图对应位的状态（hdr->Allocate(freeBitMap, fileLength, incrementBytes)），然后写回硬盘原来的扇区（fileSystem-> setBitMap(freeBitMap)）；其中，getBitMap()与setBitMap()完成从硬盘读取位示图文件与将位示图文件写回硬盘操作；

   - getBitMap()调用了../userprog/bitmap.cc中BitMap类的FetchFrom(OpenFile *)，setBitMap()调用了BitMap类的WriteBack(OpenFile *)完成。

   - fileSystem中的FileSystem类没有定义实现getBitMap()与setBitMap()，需要你自己实现；

   - 直观上，类FileSystem在其构造函数中，维护了两个一直处于打开状态的文件句柄OpenFile* freeMapFile与OpenFile* directoryFile;directoryFile，freeMapFile = new OpenFile(FreeMapSector)，File* directoryFile;directoryFile = new OpenFile(DirectorySector)，一个是硬盘DISK上的位示图文件，一个DISK上的目录文件（参见./filesys/filesys.h与./filesys/filesys.cc），我们可以直接使用它们实现对DISK上位示图文件与目录文件的读与写操作（BitMap类中位示图的读写函数FetchFrom(OpenFile *)与WriteBack(OpenFile *)就是使用freeMapFile实现的），由于这两个OpenFile对象是FileSystem类的私有变量，因此需要在FileSystem类中定义实现getBitMap()与setBitMap()；

   ~~~
// 返回位示图
BitMap* FileSystem::getBitMap()
{
    BitMap* freeBitMap = new BitMap(NumSectors);
    freeBitMap->FetchFrom(freeMapFile);
    return freeBitMap;
}

// 把修改后的位示图写回磁盘
void FileSystem::setBitMap(BitMap* freeMap)
{
    freeMap->WriteBack(freeMapFile);
}
   ~~~

   （5）Allocate(freeBitMap, fileLength, incrementBytes) 函数的实现：

   > 该函数需要在文件 `filehdr.cc` 中重载函数，而不是在原有函数的基础上修改
   >
   > 如果原来文件最后一个扇区的剩余空间足以容纳要写入的numBytes个字节，就不需要为写入操作分配新的扇区，在原文件的最后一个扇区中写入数据即可；但要修改文件头中文件大小属性；文件写操作结束后将文件头写回硬盘原来的扇区中；
   >
   > 如果原来文件最后一个扇区的剩余空间太小，无法容纳要写入的numBytes个字节，就需要为写入操作分配新的扇区，在原文件的最后一个扇区写满后，将剩余数据写入新分配的扇区中;
   >
   > 这里要修改文件头中文件大小属性，同时要将新分配的扇区在空闲块管理位示图中对应的位置1（已分配），然后将位示图写回硬盘原来的扇区中；文件写操作结束后将文件头写回硬盘原来的扇区中；

   ~~~
bool FileHeader::Allocate(BitMap *freeMap, int fileSize, int incrementBytes)
{
    if (numSectors > 30)
        return false;

    // 在一个空文件后追加数据
    if (fileSize == 0 && incrementBytes > 0)
    {
        // 空闲扇区不够
        if (freeMap->NumClear() < 1)
            return false;
        // 为添加数据先分配一个空闲磁盘块，并更新文件头信息
        dataSectors[0] = freeMap->Find();
        numSectors = 1;
        numBytes = 0;
    }

    numBytes = fileSize;

    // 原文件最后一个扇区数据块偏移量
    int offset = numBytes % SectorSize;
    // 最后一个扇区空闲数据块, 例如1个扇区100块, offset=39, freeSize=61
    int freeSize = SectorSize - offset;
    int newSectorBytes = incrementBytes - freeSize;

    // 最后一个扇区块剩余空间足以容纳追加数据，不需要分配新的扇区块
    if (newSectorBytes <= 0)
    {
        numBytes += incrementBytes;
        return true;
    }

    // 最后一个扇区的剩余空间不足以容纳追加数据，需要重新分配块
    // 新增的扇区块数
    int moreSectors = divRoundUp(newSectorBytes, SectorSize);
    // 文件超出30个磁盘块或磁盘无足够的空闲块
    if (numSectors + moreSectors > 30 || freeMap->NumClear() < moreSectors)
        return false;

    // 没有超出文件大小限制，且磁盘有足够的空闲块
    for (int i = numSectors; i < numSectors + moreSectors; i++)
        dataSectors[i] = freeMap->Find();
    // 更新后的文件大小
    numBytes += incrementBytes;
    // 更新后的文件扇区数
    numSectors += moreSectors;

    return TRUE;
}
   ~~~

   - FileHeader::Allocate(BitMap *freeMap, int fileSize)函数根据文件大小为文件分配所需的所有扇区块，并在位示图中标记所分配的扇区块，设置头文件三元组< numBytes, numSectors, dataSectors[30] >，我们可以重载FileHeader::Allocate(BitMap *freeMap, int fileSize, int incrementBytes)，以根据要扩展的数据大小incrementBytes判断是否需要分配新的扇区块，并更新文件头三元组。

   

2. 当传入参数为 `-nap` 时，主程序中实际调用了函数 `NAppend` ，理解该函数的实现逻辑，分析fstest.cc中的NAppend()函数可以看出，NAppend()函数也是调用OpenFile::Write()实现文件的写操作，我们也知道，OpenFile::Write()通过调用OpenFile::WriteAt()实现，我们已经修改了OpenFile::WriteAt()，实现了从文件的任何位置开始写入数据；因此，只需在fstest.cc中的NAppend()函数中与Append()做同样的修改即可。

   ~~~
   void NAppend(char *from, char *to)
   {
       // ......
       
       buffer = new char[TransferSize];
       openFileFrom->Seek(0);
       while ( (amountRead = openFileFrom->Read(buffer, TransferSize)) > 0) 
       {
           int result;
   		result = openFileTo->Write(buffer, amountRead);
   
   		ASSERT(result == amountRead);
   		start += amountRead;
       }
       delete [] buffer;
   	
   	// ......
   }
   ~~~

   

## Lab6 Nachos 用户程序与系统调用

### 1. Nachos 可执行程序.noff 文件的格式组成

Nachos 的应用程序是作者自己定义的一种文件类型，文件头部分结构相对简单，编程方便。分析析../test/Makefile 可以看出，首先利用交叉编译器提供的 gcc、as、ld 等工具将nachos 应用程序 .c 编译链接成 .coff 文件，然后利用../bin/arch/unknown-i386-linux/bin/coff2noff 将 coff 文件转变成 noff 文件：

~~~
......
$(all_coff): $(obj_dir)/%.coff: $(obj_dir)/start.o $(obj_dir)/%.o
	@echo ">>> Linking" $(obj_dir)/$(notdir $@) "<<<"
	$(LD) $(LDFLAGS) $^ -o $(obj_dir)/$(notdir $@)

$(all_noff): $(bin_dir)/%.noff: $(obj_dir)/%.coff
	@echo ">>> Converting to noff file:" $@ "<<<"
	$(coff2noff) $^ $@
	ln -sf $@ $(notdir $@)
......
~~~

简单的可执行文件头结构便于程序实现（参见 AddrSpace:: AddrSpace()中将程序装入主存，并设置 PC 的值部分代码）。

- ##### coff 文件架构

  > COFF——通用对象文件格式（Common Object File Format），是一种很流行的对象文件格式，coff文件本质上就是代码在编译阶段产生的文件。COFF文件一共有8种数据，如下表所示，其中段落头和段落数据可以有多节。默认情况下，COFF文件包含3个段：`.text`：通常包含可执行代码；`.data`：通常包含已初始化的数据；`.bss`：通常为未初始化的数据保留空间。其中，文件头~行号入口表与加载文件密切相关。

|     COFF文件结构      |   说明   |                             描述                             |
| :-------------------: | :------: | :----------------------------------------------------------: |
|      File header      |  文件头  |    用来保存COFF文件的基本信息,如文件标识,各个表的位置等等    |
|    Optional Header    |  可选头  | 类似于文件头，也是用来保存信息的，主要保存在文件头中没有描述到的信息。 |
|    Section Header     |  段落头  | 用来描述段落信息的，每个段落都有一个段落头来描述，段落的数目会在文件头中指出。 |
|     Section Data      | 段落数据 | 段落数据通常是COFF文件中最大的数据段，每个段落真正的数据就保存在这个位置，可以从段落头的描述中看到相关信息。 |
| Relocation Directives | 重定位表 | 这个表通常只存在于目标文件中，他用来描述COFF文件中符号的重定位信息。 |
|     Line Numbers      |  行号表  |                                                              |
|     Symbol Table      |  符号表  | 用来保存COFF文件中所用到的所有符号的信息，链接多个COFF文件时，这个表帮助我们重定位符号。调试程序时也要用到它。 |
|     String Table      | 字符串表 | 保存字符串的。用于保存一些字符个数超出了符号表和去段头的名称数组最大个数的字符串。 |

- noff 文件架构

~~~
#define NOFFMAGIC	0xbadfad 	

typedef struct segment {
  int virtualAddr;		    /* location of segment in virt addr space */
  int inFileAddr;		    /* location of segment in this file */
  int size;			        /* size of segment */
} Segment;

typedef struct noffHeader {
   int noffMagic;		    /* should be NOFFMAGIC */
   Segment code;		    /* executable code segment */ 
   Segment initData;		/* initialized data segment */
   Segment uninitData;		/* uninitialized data segment should be zero'ed before use */
} NoffHeader;
~~~

可以看出，文件头给出了每个段的大小，在文件中的开始位置，以及程序的入口地址等信息；AddrSpace 的构造函数在将 NOFF 文件装入内存之前，先打开该文件，读入文件头，然后根据文件头信息确定程序所占用的空间，将相应的段装入内存，将程序的入口地址，给 PC 赋值。



### 2. 用户进程与系统内核交互的逻辑

- **阅读../test 目录下的几个 Nachos 应用程序，理解 Nachos 应用程序的编程语法，了解用户进程是如何通过系统调用与操作系统内核进行交互的；**

- halt.s

  ~~~
  	.file	1 "halt.c"
  gcc2_compiled.:
  __gnu_compiled_c:
  	.text
  	.align	2
  	.globl	main
  	.ent	main
  main:
  	.frame	$fp,40,$31		# vars= 16, regs= 2/0, args= 16, extra= 0
  	.mask	0xc0000000,-4
  	.fmask	0x00000000,0
  	subu	$sp,$sp,40
  	sw	$31,36($sp)
  	sw	$fp,32($sp)
  	move	$fp,$sp
  	jal	__main
  	li	$2,3			# 0x00000003
  	sw	$2,24($fp)
  	li	$2,2			# 0x00000002
  	sw	$2,16($fp)
  	lw	$2,20($fp)
  	addu	$3,$2,-1
  	sw	$3,20($fp)
  	lw	$2,16($fp)
  	lw	$3,20($fp)
  	subu	$2,$2,$3
  	lw	$3,24($fp)
  	addu	$2,$3,$2
  	sw	$2,24($fp)
  	jal	Halt
  $L1:
  	move	$sp,$fp
  	lw	$31,36($sp)
  	lw	$fp,32($sp)
  	addu	$sp,$sp,40
  	j	$31
  	.end	main
  
  ~~~

  ![image-20220415143345960](https://s2.loli.net/2022/05/26/PukK98HsgVxQlvG.png)

  在该汇编代码中，main 函数的帧栈首先通过 $sp 开辟 40 个大小的空间，保存返回地址，将帧指针 $sp 指向栈顶，并将返回地址保存到 $fp 中，接着移交 $fp 和 $sp，运行当前程序，在当前程序运行结束后，根据保存的返回地址恢复到之前的运行例程中。

  进入目录 `../userprog` ，运行以下代码：

  ~~~
  make clean
  make
  ./nachos -x ../test/halt.noff -d m
  ~~~

  程序有如下输出：

  ~~~
  Starting thread "main" at time 120
  At PC = 0x0: JAL 52
  At PC = 0x4: SLL r0,r0,0
  At PC = 0xd0: ADDIU r29,r29,-40
  At PC = 0xd4: SW r31,36(r29)
  At PC = 0xd8: SW r30,32(r29)
  At PC = 0xdc: JAL 48
  At PC = 0xe0: ADDU r30,r29,r0
  At PC = 0xc0: JR r0,r31
  At PC = 0xc4: SLL r0,r0,0
  At PC = 0xe4: ADDIU r2,r0,3
  At PC = 0xe8: SW r2,24(r30)
  At PC = 0xec: ADDIU r2,r0,2
  At PC = 0xf0: SW r2,16(r30)
  At PC = 0xf4: LW r2,16(r30)
  At PC = 0xf8: SLL r0,r0,0
  At PC = 0xfc: ADDIU r3,r2,-1
  At PC = 0x100: SW r3,20(r30)
  At PC = 0x104: LW r2,16(r30)
  At PC = 0x108: LW r3,20(r30)
  At PC = 0x10c: SLL r0,r0,0
  At PC = 0x110: SUBU r2,r2,r3
  At PC = 0x114: LW r3,24(r30)
  At PC = 0x118: SLL r0,r0,0
  At PC = 0x11c: ADDU r2,r3,r2
  At PC = 0x120: JAL 4
  At PC = 0x124: SW r2,24(r30)
  At PC = 0x10: ADDIU r2,r0,0
  At PC = 0x14: SYSCALL
  Exception: syscall
  Machine halting!
  ~~~

  可以发现，Nachos 生成 Nachos 可执行程序的过程，实际上是将 c++ 程序编译后的 coff 对象文件再做一次转换，将 coff 文件在特定的格式上转换成 noff 文件，然后生成相应的汇编代码，再在 Nachos 模拟的处理机上运行。实际上，Nachos 的汇编和 g++ 生成的汇编是差不多的。

- **Nachos 对内存、寄存器以及CPU的模拟** 

  Nachos 机器模拟很重要的部分是内存和寄存器的模拟。**Nachos寄存器组模拟了全部32个MIPS机（R2/3000）的寄存器，同时加上有关 Nachos 系统调试用的 8 个寄存器**，以期让模拟更加真实化并易于调试。

  Nachos 用宿主机的一块内存模拟自己的内存。为了简便起见，每个内存页的大小同磁盘扇区的大小相同，而整个内存的大小远远小于模拟磁盘的大小。由于 Nachos 是一个教学操作系统，在内存分配上和实际的操作系统是有区别的。事实上，Nachos 的内存只有当需要执行用户程序时用户程序的一个暂存地，而作为操作系统内部使用的数据结构不存放在 Nachos 的模拟内存中，而是申请 Nachos 所在宿主机的内存。所以 Nachos的一些重要的数据结构如线程控制结构等的数目可以是无限的，不受 Nachos 模拟内存大小的限制。

  在用户程序运行过程中，会有很多系统陷入核心的情况。系统陷入有两大类原因：**进行系统调用陷入**和**系统出错陷入**。系统调用陷入在用户程序进行系统调用时发生。系统调用可以看作是软件指令，它们有效地弥补了机器硬件指令不足；系统出错陷入在系统发生错误时发生，比如用户程序使用了非法指令以及用户程序逻辑地址同实际的物理地址映射出错等情况。不同的出错陷入会有不同的处理，比如用户程序逻辑地址映射出错会起页面的重新调入，而用户程序使用了非法指令则需要向用户报告等等。Nachos 处理的陷入有：

  ~~~
  SyscallException 系统调用陷入
  PageFaultException 页面转换出错
  ReadOnlyException 试图访问只读页面
  BusErrorException 总线错，转换用户程序页面时出错
  AddressErrorException 页面访问没有对齐，或者超出了页面的大小
  OverflowException 加减法时整数溢出
  IllegalInstruException 非法指令访问
  ~~~

  模拟机的机器指令由操作代码和操作数组成的，其类定义和实现如下所示：

  ~~~
  class Instruction {
  public:
  	void Decode(); // 将指令的二进制表示转换成系统方便处理的表示
  	unsigned int value; // 指令的二进制表示
  	char opCode; // 分析出的操作代码
  	char rs, rt, rd; // 分析出的指令的三个寄存器的值
  	int extra; // 分析出的指令立即数
  };
  ~~~

  Machine 类的定义如下所示：

  ~~~
  class Machine {
  public:
  	Machine(bool debug); // 初始化方法
  	~Machine(); // 析构方法
  	void Run(); // 运行一个用户程序
  	int ReadRegister(int num); // 读出寄存器中的内容
  	void WriteRegister(int num, int value); // 向一个寄存器赋值
  	void OneInstruction(Instruction *instr); // 执行一个用户程序指令
  	void DelayedLoad(int nextReg, int nextVal); // 执行一次延迟载入
  	bool ReadMem(int addr, int size, int* value); // 读出内存 addr 地址中的内容
  	bool WriteMem(int addr, int size, int value); // 向内存 addr 地址中写入内容
  	ExceptionType Translate(int virtAddr, int* physAddr, int size,bool writing);
  // 将用户程序逻辑转换成物理地址
  	void RaiseException(ExceptionType which, int badVAddr);
  // 执行出错陷入处理程序
  	void Debugger(); // 调用用户程序调试器
  	void DumpState(); // 打印机器寄存器和内存状态
  	char *mainMemory; // 模拟内存
  	int registers[NumTotalRegs]; // CPU 寄存器模拟
  	TranslationEntry *tlb; // TLB 页面转换表
  	TranslationEntry *pageTable; // 线性页面转换表
  	unsigned int pageTableSize; // 线性页面转换表大小
  private:
  	bool singleStep; // 单步执行标志
  	int runUntilTime; // 调试时钟
  };
  ~~~

  需要注意的是，虽然这里的很多方法和属性规定为 public 的，但是它们只能在系统核心内被调用。定义 Machine 类的目的是为了执行用户程序，如同许多其它系统一样，用户程序不直接使用内存的物理地址，而是使用自己的逻辑地址，在用户程序逻辑地址和实际物理地址之间，就需要一次转换，系统提供了两种转换方法的接口：**线性页面地址转换方法**和 **TLB 页面地址转换方法**

- 无论是线性页面地址转换还是 TLB 页面地址转换，都需要一张地址转换表，地址转换表是由若干个表项（Entry）组成的。每个表项记录程序逻辑页到内存实页的映射关系，和实页的使用状态、访问权限信息。类 TranslationEntry 描述了表项的结构：

  ~~~
  class TranslationEntry {
  public :
  	int virtualPage; // 逻辑页号
  	int physicalPage; // 内存物理页号
  	boot valid; // 该 Entry 是否使用，TRUE 表示在使用
  	bool readOnly; // 对应页的访问属性，TRUE 示只读，否则为读写
  	bool use; // 该 Entry 是否被使用过，每次访问后置为 TRUE
  	bool dirty; // 对应的物理页使用情况，TRUE 表示被写过
  }
  ~~~

  **线性页面地址转换**是一种较为简单的方式，即用户程序的逻辑地址同实际物理地址之间的关系是线性的。在作转换时，给出逻辑地址，计算出其所在的逻辑页号和页中偏移量，通过查询转换表（实际上在使用线性页面地址转换时，TranslationEntry 结构中的 virtualPage 是多余的，线性页面转换表的下标就是逻辑页号），即可以得到实际物理页号和其页中偏移量。在模拟机上保存有线性页面转换表，它记录的是当前运行用户程序的页面转换关系；在用户进程空间中，也需要保存线性页面转换表，保存有自己运行用户程序的页面转换关系。当其被切换上模拟处理机上运行时，需要将进程的线性页面转换表覆盖模拟处理机的线性页面转换表。

  ![image-20220415152105372](https://s2.loli.net/2022/05/26/w9gsSxE63rO5aXn.png)

  **TLB 页面转换**则不同，TLB 转换页表是硬件来实现的，表的大小一般较实际的用户程序所占的页面数要小，所以一般 TLB 表中只存放一部分逻辑页到物理页的转换关系。这样就可能出现逻辑地址转换失败的现象，会发生 PageFaultException 异常。在该异常处理程序中，就需要借助用户进程空间的线性页面转换表来计算出物理页，同时 TLB表中增加一项。如果 TLB 表已满，就需要对 TLB 表项做 LRU 替换。使用 TLB 页面转换表处理起来逻辑较线性表为复杂，但是速度要快得多。由于 TLB 转换页表是硬件实现的，所以指向 TLB 转换页表的指针应该是只读的，所以 Machine 类一旦实例化，TLB 指针值不能改动。

  在实际的系统中，线性页面地址转换和 TLB 页面地址转换只能二者取一，为简便起见，**Nachos 选择了前者。**另外，由于 Nachos 可以在多种平台上运行，各种运行平台的数据表达方式不完全一样，有的是高位在前，有的是高位在后。为了解决跨平台的问题，特地给出了四个函数作数据转换，它们是 WordToHost、ShortToHost、WordToMachine 和 ShortToMachine。



### 3. 交叉编译生成 Nachos 可执行程序

- **阅读../test/Makefile，掌握如何利用交叉编译生成 Nachos 的可执行程序；**

- 分析析../test/Makefile 可以看出，首先利用交叉编译器提供的 gcc、as、ld 等工具将nachos 应用程序 .c 编译链接成 .coff 文件，然后利用../bin/arch/unknown-i386-linux/bin/coff2noff 将 coff 文件转变成 noff 文件：

~~~
......
$(all_coff): $(obj_dir)/%.coff: $(obj_dir)/start.o $(obj_dir)/%.o
	@echo ">>> Linking" $(obj_dir)/$(notdir $@) "<<<"
	$(LD) $(LDFLAGS) $^ -o $(obj_dir)/$(notdir $@)

$(all_noff): $(bin_dir)/%.noff: $(obj_dir)/%.coff
	@echo ">>> Converting to noff file:" $@ "<<<"
	$(coff2noff) $^ $@
	ln -sf $@ $(notdir $@)
......
~~~



### 4. 命令行参数-x 的处理过程

- **阅读../threads/main.cc，../userprog/ progtest.cc，根据对命令行参数-x 的处理过程，理解系统如何为应用程序创建进程，并启动进程的**

- 在 `main.cc` 中，检测到命令行参数 `-x` 后，程序会调用 `StartProcess(*(argv + 1))` 过程：

  ~~~
  void StartProcess(char *filename)
  {
      OpenFile *executable = fileSystem->Open(filename);
      AddrSpace *space;
  
      if (executable == NULL) {
  	printf("Unable to open file %s\n", filename);
  	return;
      }
      space = new AddrSpace(executable);    
      currentThread->space = space;
  
      delete executable;			// close file
  
      space->InitRegisters();		// set the initial register values
      space->RestoreState();		// load page table register
  
      machine->Run();			// jump to the user progam
      ASSERT(FALSE);			// machine->Run never returns;
  }
  ~~~

  在本函数中，Nachos 会根据输入的文件名以打开文件结构的方式打开该文件，然后调用 ` space = new AddrSpace(executable); ` 为其分配地址空间，把当前线程的空间赋值给该地址空间，然后关闭打开文件，初始化相应的地址空间和寄存器空间后，调用处理机模拟例程 `machine` 来执行该用户程序。

  > 在类 AddrSpace 中添加成员函数 Print()，在为一个应用程序新建一个地址空间后调用该函数，输出该程序的页表（页面与帧的映射关系），显示信息有助于后续程序的调试与开发。 
  >
  > ![image-20220415145331891](https://s2.loli.net/2022/05/26/YHm7M3QcepGKRVf.png)

- 在类 `AddrSpace` 中，实际上是做了用户程序地址空间到内核地址空间的映射过程，包括页表的映射等，实际上并不保存用户进程的信息，只需要在运行用户程序的线程中保存相应的映射结果然后运行即可。Nachos 的 参 数 -x（ nachos –x filename ） 调 用 ../userprog/ progtest.cc 的 StartProcess(char *filename)函数，为用户程序创建 filename 创建相应的进程，并启动该进程的执行。

- 系统要运行一个应用程序，需要为该程序创建一个用户进程，为程序分配内存空间，将用户程序（代码段与数据段，数据段包括初始化的全局变量与未初始化的全局变量，以及静态变量）装入所分配的内存空间，创建相应的页表，建立虚页与实页（帧）的映射关系；（ AddressSpace:: AddressSpace()）。然后将用户进程映射到一个核心线程；（StartProcess() in progtest.cc）

- 为使该核心线程能够执行用户进程的代码，需要核心在调度执行该线程时，根据用户进程的页表读取用户进程指令；因此需要将用户页表首地址传递给核心的地址变换机构；（machine.h 中维护一个 pageTable 指针，指向当前正在 运行的 Nachos 应用进程的页表）





### 5. 用户线程映射到核心线程的方法

- **阅读../userprog/ progtest.cc，../threads/scheduler.cc（Run()），理解如何将用户线程映射到核心线程，以及核心线程执行用户程序的原理与方法**

- Nachos的用户进程由两部分组成：核心部分和用户程序部分。核心部分同一般的系统线程没有区别，它共用了Nachos的正文段和数据段，运行在宿主机上；而用户程序部分则有自己的正文段、数据段和栈段，它存储在Nachos的模拟内存中，运行在Nachos的模拟机上。在控制结构上，Nachos的用户进程比系统线程多了以下内容：

  ~~~
  int userRegisters[NumTotalRegs];	//	虚拟机的寄存器组
  void SaveUserState();				//	线程切换时保存虚拟机寄存器组
  void RestoreUserState();			//	线程切换时恢复虚拟机寄存器组
  AddrSpace *space;					//	线程运行的用户程序
  ~~~

  其中，用户程序空间有AddrSpace类来描述：

  ~~~
  class AddrSpace {
  public:
      AddrSpace(OpenFile *executable);	//	根据可执行文件构成用户程序空间
  	~AddrSpace();						//	析构方法
      void InitRegisters();				//	初始化模拟机的寄存器组
  	void SaveState();					//	保存当前机器页表状态	
      void RestoreState();				//	恢复机器页表状态
  private:
      TranslationEntry *pageTable;		//	用户程序页表
  	unsigned int numPages;				//	用户程序的虚页数
  };
  ~~~

  > 在Linux系统中，使用gcc交叉编译技术将C程序编译成R2/3000可以执行的目标代码，通过Nachos提供的**coff2noff**工具将其转换成Nachos可以识别的可执行代码格式，拷贝到Nachos的文件系统中才能执行。

- 生成方法：

| 语法 | AddrSpace (OpenFile *executable)                             |
| ---- | ------------------------------------------------------------ |
| 参数 | Executable:	需要执行代码的打开文件结构                    |
| 功能 | 初始化用户程序空间。                                         |
| 实现 | 1. 判断打开文件是否符合可执行代码的格式，如果不符合，出错返回    2. 将用户程序的正文段、数据段以及栈段一起考虑，计算需要空间大小。如果大于整个模拟的物理内存空间，出错返回。   3. 生成用户程序线性页表。   4. 将用户程序的正文段和数据段依次调入内存，栈段记录的是用户程序的运行状态，它的位置紧接于数据段之后。 |
| 返回 | 无。                                                         |

- InitRegisters方法

| 语法： | Void InitRegisters ()                                        |
| ------ | ------------------------------------------------------------ |
| 参数： | 无。                                                         |
| 功能： | 初始化寄存器，让用户程序处于可以运行状态。                   |
| 实现： | 设置PC指针、栈指针的初值，并将其它寄存器的值设置为0。同时，设置NextPCReg寄存器的值为4，方便PC得到下地址运行。 |
| 返回： | 无。                                                         |

- SaveState方法

| 语法： | Void SaveState ()        |
| ------ | ------------------------ |
| 参数： | 无。                     |
| 功能： | 存储用户程序空间的状态。 |
| 实现： | 目前为空。               |
| 返回： | 无。                     |

- RestoreState方法

| 语法： | Void RestoreState ()           |
| ------ | ------------------------------ |
| 参数： | 无。                           |
| 功能： | 恢复处理机用户程序空间的状态。 |
| 实现： | 赋值实现。                     |
| 返回： | 无。                           |



目前Nachos在运行用户程序时，有如下的限制：

  (1) 系统一次只能有运行一个用户程序，所以目前的线性转换页表比较简单，虚拟页号同物理页号完全一样。

  (2) 系统能够运行的用户程序大小是有限制的，必须小于模拟的物理内存空间大小，否则出错。在虚拟内存实现以后，这部分内容也将做改动。

**当用户程序空间初始化之后（设由space指针指向），真正的启动运行过程如下：**

~~~
space -> InitRegisters();		//	初始化模拟机寄存器组
space -> RestoreState();		//	恢复处理机用户程序空间的状态，实际上是将用户程序空间的转换页表覆盖
                                //  模拟机的转换页表
machine -> Run();			    //	运行用户程序
~~~



### 6. 进程页表与 CPU 页表关联的方法

- **阅读../userprog/ progtest.cc，../machine/translate.cc，理解当前进程的页表是如何与 CPU 使用的页表进行关联的；**

- 在 `AddrSpace` 类的构造函数中，有如下操作：

  ~~~
  pageTable = new TranslationEntry[numPages];
  for (i = 0; i < numPages; i++) {
  	pageTable[i].virtualPage = i;	// for now, virtual page # = phys page #
  	pageTable[i].physicalPage = i;
  	pageTable[i].valid = TRUE;
  	pageTable[i].use = FALSE;
  	pageTable[i].dirty = FALSE;
  	pageTable[i].readOnly = FALSE; 
  }
  ~~~

  它为用户程序的每一页都分配了相应的虚拟页号到物理页号的映射。在文件 `translate.cc` 中，类 `TranslationEntry` 定义如下：

  ~~~
  class TranslationEntry {
    public:
      int virtualPage;
      int physicalPage;
      bool valid; 
      bool readOnly;
      bool use; 
      bool dirty; 
  };
  ~~~

  二者的关系就是如此构造起来的。Nachos 为用户程序分配地址空间，地址空间中调用 `TranslationEntry` 为程序分配页表。再看程序 `Machine::Translate(int virtAddr, int* physAddr, int size, bool writing)` ，它涉及到物理页和虚拟页的转换。





## Lab7 地址空间的扩展

### 1. Nachos 创建应用程序进程的详细过程

- **阅读 …/prog/protest.cc，深入理解 Nachos 创建应用程序进程的详细过程；**

#### 地址空间映射

观察 …/test/Makefile 文件可知，Nachos 利用了交叉编译器提供的 gcc、as、ld 工具用于编译。

![image-20220504085414151](https://s2.loli.net/2022/05/04/yYQVb3J2gFiECMW.png)

![image-20220504085650103](https://s2.loli.net/2022/05/26/pqVPWSy1lCzUkhA.png)

编译的目标文件是 .noff 文件和 .flat 文件，编译过程是先通过 .c 文件编译出 .o 文件，再通过 .o 文件编译出 .coff 文件，再通过 .coff 文件编译出 .noff 文件与 .flat 文件。

![image-20220504090809052](https://s2.loli.net/2022/05/04/vyCMzXJLIdbpgPQ.png)

整个执行过程的流程图请访问链接查看：（图中黑色线段部分）

![image-20220506152740468](https://s2.loli.net/2022/05/26/Iv6K9cRqZwGuk1x.png)

https://bucket011.obs.cn-north-4.myhuaweicloud.com:443/lab6-8.tiff?AccessKeyId=EPMCKIK9NRITQHB3EEVR&Expires=1682926038&Signature=S192G8/tf6%2B3OQMTHr3v%2BFihlTw%3D

其中 .noff 文件头结构如下所示：

~~~
#define NOFFMAGIC	0xbadfad      // Nachos 文件的魔数

typedef struct segment {
  int virtualAddr;              // 段在虚拟地址空间中的位置
  int inFileAddr;               // 段在文件中的位置
  int size;                     // 段大小
} Segment;

typedef struct noffHeader {
   int noffMagic;               // noff 文件的魔数
   Segment code;                // 可执行代码段 
   Segment initData;            // 已初始化数据段
   Segment uninitData;          // 未初始化数据段, 文件使用之前此数据段应为空
} NoffHeader;
~~~

我们可以继续观察 Addrspace 类的构造函数，观察 Nachos 是如何创建一个地址空间用于运行用户程序，以及如何打开 noff 文件进行文件空间计算：

~~~
class AddrSpace {
  private:
    TranslationEntry *pageTable;    // 线性页表（虚拟页-物理页）
    unsigned int numPages;	         // 应用程序页数
};

AddrSpace::AddrSpace(OpenFile *executable) {
    // 可执行文件中包含了目标代码文件
    NoffHeader noffH;               // noff文件头
    unsigned int i, size;

    executable->ReadAt((char *)&noffH, sizeof(noffH), 0);   // 读出noff文件
    if ((noffH.noffMagic != NOFFMAGIC) && (WordToHost(noffH.noffMagic) == NOFFMAGIC))
    	SwapHeader(&noffH);		      // 检查noff文件是否正确
    ASSERT(noffH.noffMagic == NOFFMAGIC);
  	// 确定地址空间大小，其中还包括了用户栈大小
    size = noffH.code.size + noffH.initData.size + noffH.uninitData.size + UserStackSize;	
    numPages = divRoundUp(size, PageSize);  // 确定页数
    size = numPages * PageSize;             // 计算真实占用大小
    ASSERT(numPages <= NumPhysPages);       // 确认运行文件大小可以运行
	// 第一步，创建页表，并对每一页赋初值
    pageTable = new TranslationEntry[numPages];
    for (i = 0; i < numPages; i++) {
      pageTable[i].virtualPage = i;         // 虚拟页
      pageTable[i].physicalPage = i;        // 虚拟页与物理页一一对应
      pageTable[i].valid = TRUE;
      pageTable[i].use = FALSE;
      pageTable[i].dirty = FALSE;
      pageTable[i].readOnly = FALSE;        // 只读选项
    }
    // 第二步，初始化物理内存
    bzero(machine->mainMemory, size);
    // 第三步，将noff文件数据拷贝到物理内存中
    // 拷贝程序段
    if (noffH.code.size > 0) {
      executable->ReadAt(&(machine->mainMemory[noffH.code.virtualAddr]),
      	noffH.code.size, noffH.code.inFileAddr); // ReadAt调用了bcopy函数
    }
    // 拷贝数据段
    if (noffH.initData.size > 0) {
      executable->ReadAt(&(machine->mainMemory[noffH.initData.virtualAddr]),
		noffH.initData.size, noffH.initData.inFileAddr);
    }
}
~~~

在 Nachos 中，页表实现了虚页与实页的对应关系，系统根据页表实现存储保护，页面置换算法根据页表信息进行页面置换。我们查看 …/machine/translate.h 文件得到如下页表项结构：

~~~
class TranslationEntry {
  public:
    int virtualPage;    // 虚拟内存中的页编号
    int physicalPage;   // 物理内存中的页编号（相对于主存位置）
    bool valid;         // valid = 1, 该转换有效（已经被初始化）
    bool readOnly;      // readOnly = 1, 该页内容不允许修改
    bool use;           // use = 1, 该页被引用或修改（变量由硬件修改）
    bool dirty;         // dirty = 1, 该页被修改（变量由硬件修改）
};
~~~

通过上述代码，我们可以发现系统要运行一个应用程序，需要为该程序创建一个用户进程，为程序分配内存空间，将用户程序数据装入所分配的内存空间，并创建相应的页表，建立虚页与实页的映射关系。然后将用户进程映射到一个核心线程。

为了使核心线程能够执行用户进程指令，Nachos 根据用户进程的页表读取用户进程指令，并将用户页表传递给了核心线程的地址变换机构。



#### 用户程序的创建与启动

1. **StartProcess 函数**

   查看 …/threads/main.cc 文件可以发现 Nachos 的参数 -x 调用了 …/userprog/progtest.cc 中的 StartProcess(char *filename); 函数：

   ~~~
   if (!strcmp(*argv, "-x")) {        	// run a user program
       ASSERT(argc > 1);
       StartProcess(*(argv + 1));
       argCount = 2;
   }
   ~~~

   具体函数内容如下。由于下述文件中出现了打开文件的操作，因此我们查看 …/userprog/Makefile.local 文件可以发现在用户程序中的宏定义为 FILESYS_STUB，即并非使用实验四、五中的文件系统对 DISK 上的文件进行操作，而是直接对 UNIX 文件进行操作。

   ~~~
   void StartProcess(char *filename) {             // 传入文件名
       OpenFile *executable = fileSystem->Open(filename);  // 打开文件
       AddrSpace *space;                           // 定义地址空间
   
       if (executable == NULL) {
         printf("Unable to open file %s\n", filename); // 无法打开文件
         return;
       }
       space = new AddrSpace(executable);  // 初始化地址空间
       currentThread->space = space;       // 将用户进程映射到一个核心线程
     
       delete executable;          // 关闭文件
       space->InitRegisters();     // 设置 Machine 的寄存器初值
       space->RestoreState();      // 将应用程序页表加载到了Machine中
       machine->Run();             // machine->Run()代码中有死循环，不会返回
       ASSERT(FALSE);
   }
   
   #define StackReg 29             // 用户栈指针
   #define PCReg 34                // 当前存储PC值的寄存器 
   #define NextPCReg 35            // 存储下一个PC值的寄存器 
   #define PrevPCReg 36            // 存储上一次PC值的寄存器
   void AddrSpace::InitRegisters() {
       for (int i = 0; i < NumTotalRegs; i++)      // 每个寄存器初值置0
         machine->WriteRegister(i, 0);
       machine->WriteRegister(PCReg, 0);           // PC寄存器初值为0 
       machine->WriteRegister(NextPCReg, 4);       // 下一个PC值为4
       // 栈指针赋初值, 减去一个数值避免越界
       machine->WriteRegister(StackReg, numPages * PageSize - 16);
   }
   
   void AddrSpace::RestoreState() {
       machine->pageTable = pageTable;     // 将应用程序页表赋给Machine
       machine->pageTableSize = numPages;
   }
   
   ~~~

2. **Instruction 类**

   Instruction 类封装了一条 Nachos 机器指令，具体信息如下：

   ~~~
   class Instruction {
     public:
       void Decode();	        // 解码二进制表示的指令
       unsigned int value;     // 指令的二进制表达形式
       char opCode;     		// 指令类型
       char rs, rt, rd; 		// 指令的 3 个寄存器
     	int extra;       		// 立即数（带符号） 或 目标 或 偏移量
   };
   ~~~

3. **Machine::ReadMem() 函数**

   继续查看 Machine 类，可以看到将虚拟地址数据读取到实际地址的函数，Machine::ReadMem();，如下所示：

   ~~~
   // 此函数将虚拟内存addr处的size字节的数据读取到value所指的物理内存中，读取错误则返回false。
   bool Machine::ReadMem(int addr, int size, int *value) {     // 虚拟地址、读取字节数、物理地址
       int data, physicalAddress;
       ExceptionType exception;        // 异常类型    
       // 进行虚实地址转换
       exception = Translate(addr, &physicalAddress, size, FALSE);
       if (exception != NoException) {
         machine->RaiseException(exception, addr);     // 抛出异常, 返回false
         return FALSE;
       }
       switch (size) {	        // 对字节大小进行分类处理
         case 1:               // 读取一个字节, 放入value所指地址
           data = machine->mainMemory[physicalAddress];
           *value = data;
           break;
         case 2:               // 读取两个字节，即一个short类型
           data = *(unsigned short *) &machine->mainMemory[physicalAddress];
           *value = ShortToHost(data);         // 短字转为主机格式
           break;
         case 4:               // 读取四个字节，即一个int类型
           data = *(unsigned int *) &machine->mainMemory[physicalAddress];
           *value = WordToHost(data);          // 字转为主机格式
           break;
         default: ASSERT(FALSE);
       }
       return (TRUE);      // 读取正确
   }
   ~~~

4. **Machine::OneInstruction() 函数**

   Nachos 将虚拟地址转化为物理地址后，从物理地址取出指令放入 Machine::OneInstruction(Instruction *instr) 函数进行执行，该函数具体代码如下所示：

   ~~~
   #define PCReg 34 					// 当前存储PC值的寄存器 
   #define NextPCReg 35 				// 存储下一个PC值的寄存器 
   #define PrevPCReg 36 				// 存储上一次PC值的寄存器
   
   // 执行一条用户态的指令。如果执行指令过程中有异常或中断发生，则调出异常处理装置，待其处理完成后再继续运行。
   void Machine::OneInstruction(Instruction *instr) {
       int raw, nextLoadReg = 0, nextLoadValue = 0;  	// nextLoadValue记录延迟的载入操作，用于之后执行
       //	读取指令数据到raw中
       if (!machine->ReadMem(registers[PCReg], 4, &raw)) return;	  // 发生异常
       instr->value = raw; // 指令数据赋值
       instr->Decode();    // 指令解码
       int pcAfter = registers[NextPCReg] + 4; // 计算下下个PC指令地址
       int sum, diff, tmp, value;
       unsigned int rs, rt, imm;
       // 59条指令分类执行
       switch (instr->opCode) {
         case:		// 59个case
           ...
         default:
           ASSERT(FALSE);
       }
     	// 执行被延迟的载入操作
       DelayedLoad(nextLoadReg, nextLoadValue);
     	// 增加程序计数器（PC）
       registers[PrevPCReg] = registers[PCReg];    // 记录上一个PC值，用于之后调试
       registers[PCReg] = registers[NextPCReg];    // 将下一个PC值赋给NOW_PC寄存器
       registers[NextPCReg] = pcAfter;         // 将下下个PC值赋给NEXT_PC寄存器
   }
   ~~~

5. **Machine::Run() 函数**

   Nachos 中调用了 Machine::Run() 函数循环调用上述 Machine::OneInstruction(Instruction *instr) 函数执行程序指令，具体函数代码如下所示：

   ~~~
   // 模拟用户程序的执行，该函数不会返回
   void Machine::Run() {
       Instruction *instr = new Instruction;   // 用于存储解码后的指令
       interrupt->setStatus(UserMode);         // 将中断状态设为用户模式
       for (;;) {
         OneInstruction(instr);	           // 执行指令
         interrupt->OneTick();             // 用户模式下执行一条指令，时钟数为1
         // 单步调试
         if (singleStep && (runUntilTime <= stats->totalTicks))	Debugger();
       }
   }
   ~~~

   



### 2 多进程机制

- 阅读理解类 AddrSpace，然后对其进行修改，使 Nachos 能够支持多进程机制，允许 Nachos 同时运行多个用户进程

1. **在类 AddrSpace 中添加完善的 Print() 函数（在实验六中已给出）**

   ~~~
   void AddrSpace::Print()
   {
       printf("page table dump: %d pages in total\n", numPages);
       printf("=============================\n");
       printf("\tVirtPage, \tPhysPage\n");
       for (int i=0; i < numPages; i++)
       {
           printf("\t %d, \t\t%d\n", pageTable[i].virtualPage, pageTable[i].physicalPage);
       }
       printf("============================================\n\n");
   }
   ~~~

   

2. **在类 AddrSpace 中实例化类 BitMap 的一个全局对象，用于管理空闲帧**

   ~~~
   private:
       static BitMap *userMap;// 全局位图
   ~~~




### 3. SpaceId

- **如果将 SpaceId 直接作为进程号 Pid 是否合适？如果不合适，应该如何为进程分配相应的 Pid？**

不合适，应该动态地分配和管理进程Pid，在 AddrSpace 类中添加 spaceId，用于标识一个地址空间；userMap 用于分配物理页表；pidMap 用于分配 spaceId；Print() 用于输出该地址空间的页表。

~~~
private:
    static BitMap *userMap, *pidMap;// 全局位图
    TranslationEntry *pageTable;	// 线性页表
    unsigned int numPages, spaceId; // 页表中的页表项以及地址编号
~~~



### 4. 为了实现 Join(pid)，考虑如何在该进程相关联的核心线程中保存进程号

将用户线程映射到核心线程的过程中，调用AddrSpace构造函数为其动态管理进程号，AddrSpace类的具体定义如下：

~~~
class AddrSpace {
  public:
    AddrSpace(OpenFile *executable);	// Create an address space,
					// initializing it with the program
					// stored in the file "executable"
    ~AddrSpace();			// De-allocate an address space

    void InitRegisters();		// Initialize user-level CPU registers,
					// before jumping to user code

    void SaveState();			// Save/restore address space-specific
    void RestoreState();		// info on a context switch 
    void Print();

    unsigned int getSpaceId() { return spaceId; }

#ifdef FILESYS
    OpenFile *fileDescriptor[UserProgramNum];   // 文件描述符，0、1、2分别为stdin、stdout、stderr
    int getFileDescriptor(OpenFile *openfile);
    OpenFile *getFileId(int fd);
    void releaseFileDescriptor(int fd);
#endif

  private:
    static BitMap *userMap, *pidMap;
    TranslationEntry *pageTable;	// Assume linear page table translation
					// for now!
    unsigned int numPages, spaceId;		// Number of pages in the virtual
					// address space
};
~~~

其构造函数的具体实现如下：

~~~
AddrSpace::AddrSpace(OpenFile *executable) {
    ASSERT(pidMap->NumClear() >= 1);  // 保证还有线程号可以分配
    spaceId = pidMap->Find() + 100;     // 0-99留给内核线程

    // 可执行文件中包含了目标代码文件

    NoffHeader noffH;               // noff文件头
    unsigned int i, size;

    executable->ReadAt((char *)&noffH, sizeof(noffH), 0);   // 读出noff文件
    if ((noffH.noffMagic != NOFFMAGIC) && (WordToHost(noffH.noffMagic) == NOFFMAGIC))
        SwapHeader(&noffH);           // 检查noff文件是否正确
    ASSERT(noffH.noffMagic == NOFFMAGIC);
    // 确定地址空间大小，其中还包括了用户栈大小
    size = noffH.code.size + noffH.initData.size + noffH.uninitData.size + UserStackSize;
    numPages = divRoundUp(size, PageSize);  // 确定页数
    size = numPages * PageSize;             // 计算真实占用大小
    ASSERT(numPages <= NumPhysPages);       // 确认运行文件大小可以运行

    DEBUG('a', "Initializing address space, num pages %d, size %d\n", numPages, size);
    // 第一步，创建页表，并对每一页赋初值
    pageTable = new TranslationEntry[numPages];

    ASSERT(userMap->NumClear() >= numPages);    // 确认页面足够分配
    for (i = 0; i < numPages; i++) {
        pageTable[i].virtualPage = i;         // 虚拟页
        pageTable[i].physicalPage = userMap->Find();  // 在位图找空闲页进行分配
        pageTable[i].valid = TRUE;
        pageTable[i].use = FALSE;
        pageTable[i].dirty = FALSE;
        pageTable[i].readOnly = FALSE;        // 只读选项
    }
    // 第二步，将noff文件数据拷贝到物理内存中
    if (noffH.code.size > 0) {
        int pagePos = pageTable[noffH.code.virtualAddr/PageSize].physicalPage * PageSize;
        int offSet = noffH.code.virtualAddr % PageSize;

        executable->ReadAt(&(machine->mainMemory[pagePos+offSet]),
                           noffH.code.size, noffH.code.inFileAddr); // ReadAt调用了bcopy函数
    }
    if (noffH.initData.size > 0) {
        int pagePos = pageTable[noffH.initData.virtualAddr/PageSize].physicalPage * PageSize;
        int offSet = noffH.initData.virtualAddr % PageSize;

        executable->ReadAt(&(machine->mainMemory[pagePos+offSet]),
                           noffH.initData.size, noffH.initData.inFileAddr);
    }
#ifdef FILESYS
    for(int i = 3; i < 10; i++) fileDescriptor[i] = NULL;
    OpenFile *StdinFile = new OpenFile("stdin");
    OpenFile *StdoutFile = new OpenFile("stdout");
    OpenFile *StderrFile = new OpenFile("stderr");
    /* 输出、输入、错误 */
    fileDescriptor[0] = StdinFile;
    fileDescriptor[1] = StdoutFile;
    fileDescriptor[2] = StderrFile;
#endif
}
~~~

获取地址空间ID的方法如下：

~~~
OpenFile* AddrSpace::getFileId(int fd) {
    ASSERT((fd >= 0) && (fd < UserProgramNum));
    return fileDescriptor[fd];
}
~~~

在将用户线程映射到核心线程的过程中，应该为用户线程记录好分配的地址空间的ID号，具体方法如下：

~~~
......

AddrSpace *space = new AddrSpace(executable);

delete executable;   // close file

// 创建一个核心线程，将该应用程序映射到该核心线程
char *forkedThreadName = filename;
Thread *thread = new Thread(filename);
thread->Fork(StartProcess, space->getSpaceId());
// 用户线程映射到核心线程
thread->space = space;
DEBUG('q', "filenale = %s, which address space is:\n", filename);
thread->space->Print();

......
                
~~~



### 5. 根据进程创建时系统为其所做的工作，考虑进程退出时应该做哪些工作

线程退出时，应该将线程状态设置为终止态，然后将其放入终止队列中，以便之后Join系统调用的实现。同时，应该将子线程相关的寄存器清零，然后恢复寄存器上下文，处理完系统调用后，应该步进PC寄存器，然后将父线程加入到调度队列中进行调度。



### 6. 考虑系统调用 Exec() 与 Exit() 的设计实现方案

**Exec()系统调用实现方案：**

**1、修改exception.cc，根据系统调用类型对各系统调用进行处理；**
(1) 从2号寄存器中获取当前的系统调用号(type=machine->ReadRegister(2)), 根据type对系统调用分别处理；

(2) 获取系统调用参数（寄存器4、5、6、7，可以携带4个参数）
在Exec(char *filename)的处理代码中：
(a) 从第4号寄存器中获取Exec()的参数filename在内存中的地址（addr=machine->ReadRegister(4)）；
(b) 利用Machine::ReadMem()从该地址读取应用程序文件名filename；
(c) 打开该应用程序（OpenFile *executable = fileSystem->Open(filename)）；
(d) 为其分配内存空间、创建页表、分配pid（space = new AddrSpace(executable)），至此为应用程序创建了一个进程；

- 需要修改AddrSpace:: AddrSpace()实现上述功能；同时，需要修改AddrSpace:: ~AddrSpace()，进程退出时释放pid，为其所分配的帧也应释放（修改空闲帧位示图）；
- 因此需要修改AddrSpace:: AddrSpace()与AddrSpace:: ~AddrSpace()；

(e) 创建一个核心线程，并将该进程与新建的核心线程关联（thread = new Thread(forkedThreadName)，thread->Fork(StartProcess, space->getSpaceID())）；

- 需要特别指出的是，通过Thread::Fork()创建的线程需要指明该线程要执行的代码（函数）及函数所需的参数；
- 我们可以重载函数StartProcess(int spaceId)，作为新建线程执行的代码，并将进程的pid传递给系统，供其它系统调用（如Join()）使用；
- 当调度到该线程时，就启动应用程序进程的执行；



**2、修改progtest.cc，重载函数StatProcess(char \*filename)**

将该函数作为应用程序进程所关联的核心线程的执行代码，当调度到该线程时，Exec(filename)中filename所对应的应用程序进程随即执行；

~~~
void StartProcess(int spaceId)
{
    space->InitRegisters();	// set the initial register values
    space->RestoreState();		// load page table register

    machine->Run();			// jump to the user progam
    ASSERT(FALSE);		// machine->Run never returns;
				      	// the address space exits by doing the syscall "exit"
}
~~~



**3、修改AddrSpace::AddrSpace()及AddrSpace::~AddrSpace()**

- 为管理空闲帧，建立一个全局的空闲帧管理位示图；

- 为管理pid（spaceId），建立一个全局的pid数组；

- 从内存的第一个空闲帧为Exec(filename)中的filename分配内存空间，创建该进程页表，建立虚实页表的映射关系，分配pid；

- 在释放应用程序内存空间时，应该清除空闲帧位示图相应的标志，释放pid，释放页表。

- AddrSpace::AddrSpace()及AddrSpace::~AddrSpace()的代码参考如下：

  ~~~
  AddrSpace::AddrSpace(OpenFile *executable) {
      ASSERT(pidMap->NumClear() >= 1);  // 保证还有线程号可以分配
      spaceId = pidMap->Find() + 100;     // 0-99留给内核线程
  
      // 可执行文件中包含了目标代码文件
  
      NoffHeader noffH;               // noff文件头
      unsigned int i, size;
  
      executable->ReadAt((char *)&noffH, sizeof(noffH), 0);   // 读出noff文件
      if ((noffH.noffMagic != NOFFMAGIC) && (WordToHost(noffH.noffMagic) == NOFFMAGIC))
          SwapHeader(&noffH);           // 检查noff文件是否正确
      ASSERT(noffH.noffMagic == NOFFMAGIC);
      // 确定地址空间大小，其中还包括了用户栈大小
      size = noffH.code.size + noffH.initData.size + noffH.uninitData.size + UserStackSize;
      numPages = divRoundUp(size, PageSize);  // 确定页数
      size = numPages * PageSize;             // 计算真实占用大小
      ASSERT(numPages <= NumPhysPages);       // 确认运行文件大小可以运行
  
      DEBUG('a', "Initializing address space, num pages %d, size %d\n", numPages, size);
      // 第一步，创建页表，并对每一页赋初值
      pageTable = new TranslationEntry[numPages];
  
      ASSERT(userMap->NumClear() >= numPages);    // 确认页面足够分配
      for (i = 0; i < numPages; i++) {
          pageTable[i].virtualPage = i;         // 虚拟页
          pageTable[i].physicalPage = userMap->Find();  // 在位图找空闲页进行分配
          pageTable[i].valid = TRUE;
          pageTable[i].use = FALSE;
          pageTable[i].dirty = FALSE;
          pageTable[i].readOnly = FALSE;        // 只读选项
      }
      // 第二步，将noff文件数据拷贝到物理内存中
      if (noffH.code.size > 0) {
          int pagePos = pageTable[noffH.code.virtualAddr/PageSize].physicalPage * PageSize;
          int offSet = noffH.code.virtualAddr % PageSize;
  
          executable->ReadAt(&(machine->mainMemory[pagePos+offSet]),
                             noffH.code.size, noffH.code.inFileAddr); // ReadAt调用了bcopy函数
      }
      if (noffH.initData.size > 0) {
          int pagePos = pageTable[noffH.initData.virtualAddr/PageSize].physicalPage * PageSize;
          int offSet = noffH.initData.virtualAddr % PageSize;
  
          executable->ReadAt(&(machine->mainMemory[pagePos+offSet]),
                             noffH.initData.size, noffH.initData.inFileAddr);
      }
  #ifdef FILESYS
      for(int i = 3; i < 10; i++) fileDescriptor[i] = NULL;
      OpenFile *StdinFile = new OpenFile("stdin");
      OpenFile *StdoutFile = new OpenFile("stdout");
      OpenFile *StderrFile = new OpenFile("stderr");
      /* 输出、输入、错误 */
      fileDescriptor[0] = StdinFile;
      fileDescriptor[1] = StdoutFile;
      fileDescriptor[2] = StderrFile;
  #endif
  }
  ~~~





**Exit()系统调用实现方案：**

- 系统调用void Exit(int status)的参数status是用户程序的退出状态。系统调用int Join(SpaceId id)需要返回该退出状态status。由于可能在id结束之后，其它程序（如parent）才调用Join(SpaceId id)，因此在id执行Exit(status)退出时需要将id的退出码ststus保存起来，以备Join()使用。

- 关于系统调用Exit()的实现，首先从4号寄存器读出退出码，然后释放该进程的内存空间及其其表，释放分配给该进程的实页（帧），释放其pid（参见AddrSpace::~AddrSpace()），调用currentThread->Finish结束该进程对应的线程。

- 管理空闲帧的位示图以及pid结构不能释放，因为它们是全局的。

- 实现代码形如：

  ~~~
  case SC_Exit:{
     int ExitStatus=machine->ReadRegister(4);  
     machine->WriteRegister(2,ExitStatus);
     currentThread->setExitStatus(ExitStatus);
  if (ExitStatus == 99)  //parent process exit, delele all terminated threads
  { 
     List *terminatedList = scheduler->getTerminatedList();
     scheduler->emptyList(terminatedList);             
  }  
  delete currentThread->space;
     currentThread->Finish();    
     AdvancePC();           
     break;
  }
  ~~~

- 同时，要借助Thread类实现Join系统调用。





## Lab8 系统调用 Exec()与 Exit()

### 1. 程序总体结构图

![image-20220506161200063](https://s2.loli.net/2022/05/26/QVtfMr9evzSyUj6.png)

通过访问链接查看：

https://bucket011.obs.cn-north-4.myhuaweicloud.com:443/lab6-8.tiff?AccessKeyId=EPMCKIK9NRITQHB3EEVR&Expires=1682928392&Signature=RExX9DS4hNPNM%2BSM3TiC8DY2Oz0%3D

### 2. 阅读 `../userprog/exception.cc`，理解 `Halt` 的实现原理：

Nachos 系统调用对应的宏在 `../userprog/syscall.h` 中声明如下：

~~~
#define SC_Halt		0
#define SC_Exit		1
#define SC_Exec		2
#define SC_Join		3
#define SC_Create	4
#define SC_Open		5
#define SC_Read		6
#define SC_Write	7
#define SC_Close	8
#define SC_Fork		9
#define SC_Yield	10
~~~

Nachos 目前仅实现了系统调用 `Halt()` ， 其实现代码见 `../userprog/exception.cc` 中的函数 `void ExceptionHandler(ExceptionType which)`，其余的几个系统调用都没有实现。该函数实现如下：

~~~
void ExceptionHandler(ExceptionType which)
{
    int type = machine->ReadRegister(2);

    if ((which == SyscallException) && (type == SC_Halt)) {
	DEBUG('a', "Shutdown, initiated by user program.\n");
   	interrupt->Halt();
    } else {
	printf("Unexpected user mode exception %d %d\n", which, type);
	ASSERT(FALSE);
    }
}
~~~

- 系统调用如何执行

  从 `../machine/machine.cc` 及 `mipssim.cc` 中的实现可以看出，每一条用户程序中的指令在虚拟机中被读取后，被包装成一个 `OneInstruction` 对象，然后在 `mipssim.cc` 中调用 `Machine::OneInstruction(Instruction *instr)` 对其解码执行。

  具体而言，在 `../threads/main.c` 中，当读取到系统调用请求后，函数执行的方法如下：

  ~~~
  #ifdef USER_PROGRAM
          if (!strcmp(*argv, "-x")) {        	// run a user program
  	    	ASSERT(argc > 1);
              StartProcess(*(argv + 1));
              argCount = 2;
          }
          ......
  	    interrupt->Halt();
  	}
  #endif
  ~~~

  函数首先会调用过程 `StartProcess`，其定义在文件 `../lab7-8/progtest.cc` 中， 如下：

  ~~~
  void StartProcess(char *filename)
  {
      OpenFile *executable = fileSystem->Open(filename);
      AddrSpace *space;
      space = new AddrSpace(executable);    
      currentThread->space = space;
  
      delete executable;
  
      space->InitRegisters();		// set the initial register values
      space->RestoreState();		// load page table register
  
      machine->Run();			    // jump to the user progam
      ASSERT(FALSE);
  }
  ~~~

  它首先为将要运行的用户程序分配地址空间，然后将用户程序的地址空间映射到当前核心线程的地址空间，将核心线程的地址空间映射到寄存器中，然后调用 `machine->Run();` 模拟核心态执行用户程序的操作。其中，`machine-Run()` 的具体实现在 `../machine/mipssim.cc` 中，其具体实现如下：

  ~~~
  void Machine::Run()
  {
      Instruction *instr = new Instruction;
  
      if(DebugIsEnabled('m')) {
          printf("Starting thread \"%s\" at time %d\n", currentThread->getName(), stats->totalTicks);
      }
      interrupt->setStatus(UserMode);
      for (;;) {
          OneInstruction(instr);
  		interrupt->OneTick();
  		if (singleStep && (runUntilTime <= stats->totalTicks))
  	  		Debugger();
      }
  }
  ~~~

  语句 `interrupt->setStatus(UserMode);` 模拟用户态和核心态切换的过程，由于当前是核心态，需要执行用户态的程序，所以把机器寄存器状态设置为用户程序寄存器状态的值。

  在 `for` 循环中不断调用 `Machine::OneInstruction(Instruction *instr)` 对用户态的程序进行解码并执行。`Machine::OneInstruction(Instruction *instr)` 中有一个非常大的 `SWITCH` 语句，该语句分析所取出的指令类型执行这条指令。

  `switch` 语句对 `Nachos` 系统调用的处理方法是当 `Nachos` 的 `CPU` 检测到该条指令是执行一个 `Nachos` 的系统调用，则抛出一个异常 `SyscallException` 以便从用户态陷入到核心态去处理这个系统调用，代码如下：

  ~~~
  case OP_SYSCALL:
  	RaiseException(SyscallException, 0);
  ~~~

  该异常在 `../userprog/exception.cc` 中进行处理，代码如下：

  ~~~
  void
  ExceptionHandler(ExceptionType which)
  {
      int type = machine->ReadRegister(2);
  
      if ((which == SyscallException) && (type == SC_Halt)) {
  		DEBUG('a', "Shutdown, initiated by user program.\n");
     		interrupt->Halt();
      } else {
  		printf("Unexpected user mode exception %d %d\n", which, type);
  		ASSERT(FALSE);
      }
  }
  ~~~

  从上述代码中可以看出，系统将系统调用号保存在 `MIPS` 的 `2` 号寄存器 `$2` 中，语句 `type = machine->ReadRegister(2) ` 从寄存器 `$2` 中获取系统调用号，如果该条指令要调用 `0` 号系统调用（对应的宏是 `SC_Halt`），则执行 `Halt()` 系统调用的处理程序：

  ~~~
  void
  Interrupt::Halt()
  {
      printf("Machine halting!\n\n");
      stats->Print();
      Cleanup();     // Never returns.
  }
  ~~~

  ~~~
  void
  Cleanup()
  {
      printf("\nCleaning up...\n");
  #ifdef NETWORK
      delete postOffice;
  #endif
      
  #ifdef USER_PROGRAM
      delete machine;
  #endif
  
  #ifdef FILESYS_NEEDED
      delete fileSystem;
  #endif
  
  #ifdef FILESYS
      delete synchDisk;
  #endif
      
      delete timer;
      delete scheduler;
      delete interrupt;
      
      Exit(0);
  }
  ~~~

  它清空所有态寄存器的状态，释放所有动态内存并退出程序，至此一个 `Halt` 系统调用被成功执行。`Nachos` 目前除了实现了系统调用 `Halt()`，其它的系统调用均未实现。



### 3. 编程实现系统调用 Exec() 与 Exit() 

- 基于实验 6、7 中所完成的工作，利用 Nachos 提供的文件管理、内存管理及线程管理等功能，编程实现系统调用 Exec() 与 Exit()（至少实现这两个）。

- 用户程序的创建与启动过程（图中黑色部分）：

  ![image-20220506153846617](https://s2.loli.net/2022/05/26/tHiwmAaBe2Wp6rP.png)

  - StartProcess 函数

    - 查看 …/threads/main.cc 文件可以发现 Nachos 的参数 -x 调用了 …/userprog/progtest.cc 中的 StartProcess(char *filename); 函数。

    - 具体函数内容如下。由于下述文件中出现了打开文件的操作，因此我们查看 …/userprog/Makefile.local 文件可以发现在用户程序中的宏定义为 FILESYS_STUB，即并非使用实验四、五中的文件系统对 DISK 上的文件进行操作，而是直接对 UNIX 文件进行操作。

    ~~~
    void StartProcess(char *filename) {             // 传入文件名
        OpenFile *executable = fileSystem->Open(filename);  // 打开文件
        AddrSpace *space;                           // 定义地址空间
    
        if (executable == NULL) {
          printf("Unable to open file %s\n", filename); // 无法打开文件
          return;
        }
        space = new AddrSpace(executable);  // 初始化地址空间
        currentThread->space = space;       // 将用户进程映射到一个核心线程
      
        delete executable;          // 关闭文件
        space->InitRegisters();     // 设置Machine的寄存器初值
        space->RestoreState();      // 将应用程序页表加载到了Machine中
        machine->Run();             // machine->Run()代码中有死循环，不会返回
        ASSERT(FALSE);
    }
    ~~~

    - 通过上述代码，我们可以发现系统要运行一个应用程序，需要为该程序创建一个用户进程，为程序分配内存空间，将用户程序数据装入所分配的内存空间，并创建相应的页表，建立虚页与实页的映射关系。然后将用户进程映射到一个核心线程。

    - 为了使核心线程能够执行用户进程指令，Nachos 根据用户进程的页表读取用户进程指令，并将用户页表传递给了核心线程的地址变换机构。

  - Instruction 类

    Instruction 类封装了一条 Nachos 机器指令，具体信息如下。

    ~~~
    class Instruction {
      public:
        void Decode();	         // 解码二进制表示的指令
        unsigned int value;     // 指令的二进制表达形式
        char opCode;     		// 指令类型
        char rs, rt, rd; 		// 指令的 3 个寄存器
      	int extra;       		// 立即数（带符号） 或 目标 或 偏移量
    };
    ~~~

  - Machine::ReadMem() 函数

    继续查看 Machine 类，可以看到将虚拟地址数据读取到实际地址的函数，Machine::ReadMem();，如下所示。

    ~~~
    // 此函数将虚拟内存addr处的size字节的数据读取到value所指的物理内存中，读取错误则返回false。
    bool Machine::ReadMem(int addr, int size, int *value) {     // 虚拟地址、读取字节数、物理地址
        int data, physicalAddress;
        ExceptionType exception;        // 异常类型    
        // 进行虚实地址转换
        exception = Translate(addr, &physicalAddress, size, FALSE);
        if (exception != NoException) {
          machine->RaiseException(exception, addr);     // 抛出异常, 返回false
          return FALSE;
        }
        switch (size) {	        // 对字节大小进行分类处理
          case 1:               // 读取一个字节, 放入value所指地址
            data = machine->mainMemory[physicalAddress];
            *value = data;
            break;
          case 2:               // 读取两个字节，即一个short类型
            data = *(unsigned short *) &machine->mainMemory[physicalAddress];
            *value = ShortToHost(data);         // 短字转为主机格式
            break;
          case 4:               // 读取四个字节，即一个int类型
            data = *(unsigned int *) &machine->mainMemory[physicalAddress];
            *value = WordToHost(data);          // 字转为主机格式
            break;
          default: ASSERT(FALSE);
        }
        return (TRUE);      // 读取正确
    }
    ~~~

  - Machine()::Translate() 函数

    可以看到在 ReadMem() 函数中调用了 Translate() 函数进行了虚实地址转换，因此我们继续查看 Machine::Translate() 函数，如下所示。

    ~~~
    /*  该函数主要功能是使用页表或TLB将虚拟地址转换为物理地址，并检查地址是否对齐以及其它错误。
    	如果没有错误，则在页表项中设置use、dirty位初值，并将转换后的物理地址保存在physAddr变量中。
    	virAddr - 虚拟地址，physAddr - 存储转换结果、size - 写或读的字节数
    	writing - 可写标记，需要检查TLB中的"read-only"变量。 */
    ExceptionType Machine::Translate(int virtAddr, int* physAddr, int size, bool writing) {
        int i;
        unsigned int vpn, offset, pageFrame;
        TranslationEntry *entry;	// 页表项
    	// 检查对齐错误，即如果size = 4，则地址为4的倍数，即低两位为0；
    	// 若size = 2，则地址为2的倍数，即最低位为0
        if (((size == 4) && (virtAddr & 0x3)) || ((size == 2) && (virtAddr & 0x1)))
            return AddressErrorException;
      	// TLB与页表必须有一个为空，有一个不为空
        ASSERT(tlb == NULL || pageTable == NULL);   // tlb、pageTable均定义在Machine类中
        ASSERT(tlb != NULL || pageTable != NULL)    // 通过虚拟地址计算虚拟页编号以及页内偏移量
        vpn = (unsigned) virtAddr / PageSize;       // 虚拟页编号
        offset = (unsigned) virtAddr % PageSize;    // 页内偏移量
      
        if (tlb == NULL) {          // TLB为空，则使用页表
          if (vpn >= pageTableSize)     // vpn大于页表大小, 即返回地址错误
            return AddressErrorException;
          else if (!pageTable[vpn].valid)   // vpn所在页不可用，即返回页错误
            return PageFaultException;            
          entry = &pageTable[vpn];	         // 获得页表中该虚拟地址对应页表项
        } else {									// TLB不为空，则使用TLB
            for (entry = NULL, i = 0; i < TLBSize; i++)     // 遍历TLB搜索
        	    if (tlb[i].valid && ((unsigned int)tlb[i].virtualPage == vpn)) {
                entry = &tlb[i];            // 找到虚拟地址所在页表项！
                break;
              }
            // 在TLB中没有找到，返回页错误
            if (entry == NULL) return PageFaultException;    
        }
        // 想要向只读页写数据，返回只读错误
        if (entry->readOnly && writing) return ReadOnlyException;
      	// 由页表项可得到物理页框号
        pageFrame = entry->physicalPage;
        // 物理页框号过大，返回越界错误
        if (pageFrame >= NumPhysPages) return BusErrorException;
        // 设置该页表项正在使用
      	entry->use = TRUE;
      	// 设置该页表项被修改了，即dirty位为true
        if (writing) entry->dirty = TRUE;
        // 得到物理地址
      	*physAddr = pageFrame * PageSize + offset;
      	// 物理地址不可越界
        ASSERT((*physAddr >= 0) && ((*physAddr + size) <= MemorySize));
      	// 返回没有错误
        return NoException;
    }
    ~~~

  - Machine::OneInstruction() 函数

    Nachos 将虚拟地址转化为物理地址后，从物理地址取出指令放入 Machine::OneInstruction(Instruction *instr) 函数进行执行，该函数具体代码如下所示。

    ~~~
    #define PCReg 34 					// 当前存储PC值的寄存器 
    #define NextPCReg 35 				// 存储下一个PC值的寄存器 
    #define PrevPCReg 36 				// 存储上一次PC值的寄存器
    
    // 执行一条用户态的指令。如果执行指令过程中有异常或中断发生，则调出异常处理装置，待其处理完成后再继续运行。
    void Machine::OneInstruction(Instruction *instr) {
        int raw, nextLoadReg = 0, nextLoadValue = 0;  	// nextLoadValue记录延迟的载入操作，用于之后执行
        //	读取指令数据到raw中
        if (!machine->ReadMem(registers[PCReg], 4, &raw)) return;	  // 发生异常
        instr->value = raw; // 指令数据赋值
        instr->Decode();    // 指令解码
        int pcAfter = registers[NextPCReg] + 4; // 计算下下个PC指令地址
        int sum, diff, tmp, value;
        unsigned int rs, rt, imm;
        // 59条指令分类执行
        switch (instr->opCode) {
          case:		// 59个case
            ...
          default:
            ASSERT(FALSE);
        }
      	// 执行被延迟的载入操作
        DelayedLoad(nextLoadReg, nextLoadValue);
      	// 增加程序计数器（PC）
        registers[PrevPCReg] = registers[PCReg];    // 记录上一个PC值，用于之后调试
        registers[PCReg] = registers[NextPCReg];    // 将下一个PC值赋给NOW_PC寄存器
        registers[NextPCReg] = pcAfter;         // 将下下个PC值赋给NEXT_PC寄存器
    }
    ~~~

  - Machine::Run() 函数

    Nachos 中调用了 Machine::Run() 函数循环调用上述 Machine::OneInstruction(Instruction *instr) 函数执行程序指令，具体函数代码如下所示。

    ~~~
    // 模拟用户程序的执行，该函数不会返回
    void Machine::Run() {
        Instruction *instr = new Instruction;   // 用于存储解码后的指令
        interrupt->setStatus(UserMode);         // 将中断状态设为用户模式
        for (;;) {
          OneInstruction(instr);	           // 执行指令
          interrupt->OneTick();             // 用户模式下执行一条指令，时钟数为1
          // 单步调试
          if (singleStep && (runUntilTime <= stats->totalTicks))	Debugger();
        }
    }
    ~~~

  - AddrSpace::RestoreState() 函数

    由上述执行过程中调用的函数代码可知，我们需要将用户进程的页表传递给 Machine 类维护的页表，才能执行用户程序指令。该过程由函数 AddrSpace::RestoreState() 实现，将用户进程的页表传递给 Machine 类，而用户进程的页表再为用户进程分配地址空间时就创建了。AddrSpace::RestoreState() 函数如下所示。

    ~~~
    // 通过一次上下文切换，保存machine的状态使得地址空间得以运行
    void AddrSpace::RestoreState() {
        machine->pageTable = pageTable;     // 页表项
        machine->pageTableSize = numPages;  // 页表大小
    }
    ~~~

    为了便于上下文切换时保存与恢复寄存器状态，Nachos 设置了两组寄存器，一组是 CPU 使用的寄存器 int registers[NumTotalRegs]，用于保存执行完一条机器指令时该指令的执行状态；另一组是运行用户程序时使用的用户寄存器 int userRegisters[NumTotalRegs]，用户保存执行完一条用户程序指令后的寄存器状态。

  - Machine 类

    接下来我们通过查看 Machine 类来了解 CPU 使用的寄存器的定义，具体定义代码如下。

    ~~~
    /*
    	模拟主机工作硬件，包括CPU寄存器、主存等。
    	用户程序无法分辨他们运行在模拟器上还是真实的硬件上，除非他们发现了该模拟器不支持浮点运算。
    	模拟器有10条系统调用，但UNIX有200条系统调用。
    */
    class Machine {
      public:
        Machine(bool debug);        // 模拟硬件的构造函数，用于运行用户程序
        ~Machine();	                // 析构函数
        // 运行用户程序的函数
        void Run();                 // 运行用户程序
        int ReadRegister(int num);  // 读取CPU寄存器中的内容
        void WriteRegister(int num, int value); // 保存value到num编号的CPU寄存器中
    	// 模拟硬件的实现过程
        void OneInstruction(Instruction *instr);    // 执行一条用户程序指令
        void DelayedLoad(int nextReg, int nextVal); // 延迟加载
        bool ReadMem(int addr, int size, int* value); // 读取虚拟地址处的size个字节到value所指物理地址处
        bool WriteMem(int addr, int size, int value); // 将size个字节的value数据写入addr的虚拟地址处
        // 将虚拟地址转换为物理地址，并检查是否有异常
        ExceptionType Translate(int virtAddr, int* physAddr, int size,bool writing);
    	// 抛出异常，陷入系统态
        void RaiseException(ExceptionType which, int badVAddr);
        void Debugger();            // 调出用户程序调试器
        void DumpState();           // 打印出用户CPU和主存状态
    	// 模拟硬件的数据结构
        char *mainMemory;           // 物理内存，用于存储用户程序、代码与数据
        int registers[NumTotalRegs];    // CPU寄存器，用于保存执行完机器指令时该指令执行状态
    	// 虚、实地址转换（mainMemory首地址为0号地址）
        TranslationEntry *tlb;          // 快表，存在唯一，因此指针不可修改，类似于只读指针
        TranslationEntry *pageTable;    // 传统线性页表，可存在多个。
        unsigned int pageTableSize;     // 页表大小
      
      private:
        bool singleStep;                // 单步调试开关，即每次用户指令执行结束是否进入调试器
        int runUntilTime;               // 当运行时间到达该值时，进入调试器
    };
    ~~~

  - Thread 类

    我们继续查看 Thread.h，来查看运行用户程序时使用的用户寄存器。

    ~~~
    /*
    	该类定义了线程控制块。
    	每个线程都拥有（1）线程执行栈（2）数组存储CPU寄存器状态（3）线程状态（运行、可运行、阻塞）
    	用户进程拥有用户地址空间，仅运行在内核态的线程没有地址空间
    */
    class Thread {
      private:
        // 下述两个变量用于上下文切换，位置不可更改
      	int* stackTop;                           // 当前栈指针
        _int machineState[MachineStateSize];    // 所有CPU寄存器状态
    
      public:
        Thread(char* debugName);                // 构造函数 
        ~Thread();                              // 析构函数，运行态线程不可析构
    		// 基础线程操作
        void Fork(VoidFunctionPtr func, _int arg); // 使线程运行在 (*func)(arg) 函数位置
        void Yield();           // 当前线程，运行态 => 可运行态
        void Sleep();           // 当前线程，运行态 => 阻塞态
        void Finish();          // 线程运行结束    
        void CheckOverflow();   // 检查线程栈是否溢出
        void setStatus(ThreadStatus st) { status = st; }    // 设置线程状态
        char* getName() { return (name); }      // 获取线程名
        void Print() { printf("%s, ", name); }  // 输出线程名
    
      private:
        int* stack;             // 栈底指针，主线程栈底指针为NULL
        ThreadStatus status;    // 线程状态（运行、可运行、阻塞）
        char* name;	            // 线程名
        void StackAllocate(VoidFunctionPtr func, _int arg); // 为线程分配栈空间，用于Fork函数内部实现
    
    #ifdef USER_PROGRAM         // 如果为用户程序
      	// 运行用户程序的线程有两组CPU寄存器，一个存储运行用户代码的线程状态，一个存储运行内核代码的线程状态
        int userRegisters[NumTotalRegs];    // 用户态下CPU寄存器状态
    
      public:
        void SaveUserState();       // 保存用户态下寄存器状态
        void RestoreUserState();    // 恢复用户态下寄存器状态
        AddrSpace *space;	          // 运行用户程序时的地址空间
    #endif
    };
    ~~~

    由于 CPU 只有一个，因此 CPU 寄存器也只有一组。但每个用户程序至少需要映射到一个核心线程，因此每个核心线程都可能执行用户程序，所以每个核心线程都需要维护一组用户寄存器 userRegisters[]，用于保存与恢复相应的用户程序指令的执行状态。

  - Scheduler::Run() 函数

    当用户进程进行上下文切换时，即执行用户进程的核心线程发生了上下文切换时，Nachos 就会将老进程的 CPU 寄存器状态保存到用户寄存器 userRegisters[] 中，并将新用户进程的寄存器状态恢复到 CPU 寄存器中，使得 CPU 能够继续执行上次被中断的用户程序。

    在 Scheduler::Run() 中，我们可以看到核心进程切换时对 CPU 寄存器与用户寄存器的保存与恢复，具体代码如下所示。

    ~~~
    // 给CPU分配下一个线程，即进行上下文切换，需要保存旧线程状态并加载新线程状态。
    void Scheduler::Run (Thread *nextThread) {
        Thread *oldThread = currentThread;      // 旧线程
        
    #ifdef USER_PROGRAM                         // 运行用户程序
        if (currentThread->space != NULL) {
            currentThread->SaveUserState();     // 保存用户态下寄存器状态
            currentThread->space->SaveState();  // 保存地址空间状态
        }
    #endif
        
        oldThread->CheckOverflow();             // 检查旧线程是否有栈溢出
        currentThread = nextThread;             // 当前线程切换到下一个线程
        currentThread->setStatus(RUNNING);      // 设置当前线程为运行态
        SWITCH(oldThread, nextThread);          // 新旧线程上下文切换
      	// 一个线程运行结束时不可以直接删除，因为当前仍然运行在其栈空间中
        if (threadToBeDestroyed != NULL) {      // 如果之前设置了需要被删除的线程
            delete threadToBeDestroyed;         // 该变量在 Finish() 函数中设置
            threadToBeDestroyed = NULL;
        }
        
    #ifdef USER_PROGRAM
        if (currentThread->space != NULL) {     // 如果新线程运行用户程序
            currentThread->RestoreUserState();  // 恢复运行用户程序时CPU寄存器状态
            currentThread->space->RestoreState();// 恢复运行用户程序时地址空间
        }
    #endif
    }
    ~~~

- **源代码及注释**

  **修改内容概述**

  实验六是读懂代码，实验七是扩展 AddrSpace 类，实验八是实现各系统调用并且继续修改了 AddrSpace、Thread、Scheduler、List、OpenFile、BitMap、FileHeader、FileSystem 类以及 exception.cc 文件，接下来依次列出各文件的修改内容。

  此处需要注意 BitMap、FileHeader、FileSystem 的修改均为实验五中修改的内容，因此下面代码中不再重复列出。

  - AddrSpace

    - AddrSpace 类

      在 AddrSpace 类中添加 spaceId，用于标识一个地址空间；userMap 用于分配物理页表；pidMap 用于分配 spaceId；Print() 用于输出该地址空间的页表。

      FILESYS 部分的内容用于实现基于 FILESYS 的文件系统调用，主要是分配和释放文件 Id。

      ~~~
      class AddrSpace {
        public:
          AddrSpace(OpenFile *executable);	// 创建地址空间
          ~AddrSpace();			            // 析构函数
      
          void InitRegisters();		// 初始化CPU寄存器
          void SaveState();			// 保存、储存地址空间
          void RestoreState();		// 恢复地址空间
          void Print();               // 打印页表
          unsigned int getSpaceId() { return spaceId; }
      
      #ifdef FILESYS
          OpenFile *fileDescriptor[UserProgramNum];   // 文件描述符，0、1、2分别为stdin、stdout、stderr
          int getFileDescriptor(OpenFile *openfile);
          OpenFile *getFileId(int fd);
          void releaseFileDescriptor(int fd);
      #endif
      
        private:
          static BitMap *userMap, *pidMap;// 全局位图
          TranslationEntry *pageTable;	// 线性页表
          unsigned int numPages, spaceId; // 页表中的页表项以及地址编号
      };
      ~~~

      - AddrSpace::AddrSpace()

      ~~~
      #define MAX_USERPROCESSES 256
      
      BitMap *AddrSpace::userMap = new BitMap(NumPhysPages);
      BitMap *AddrSpace::pidMap = new BitMap(MAX_USERPROCESSES);
      
      AddrSpace::AddrSpace(OpenFile *executable) {
          ASSERT(pidMap->NumClear() >= 1);  // 保证还有线程号可以分配
          spaceId = pidMap->Find()+100;     // 0-99留给内核线程
      
          // 可执行文件中包含了目标代码文件
          NoffHeader noffH;               // noff文件头
          unsigned int i, size;
      
          executable->ReadAt((char *)&noffH, sizeof(noffH), 0);   // 读出noff文件
          if ((noffH.noffMagic != NOFFMAGIC) && (WordToHost(noffH.noffMagic) == NOFFMAGIC))
              SwapHeader(&noffH);           // 检查noff文件是否正确
          ASSERT(noffH.noffMagic == NOFFMAGIC);
          // 确定地址空间大小，其中还包括了用户栈大小
          size = noffH.code.size + noffH.initData.size + noffH.uninitData.size + UserStackSize;   
          numPages = divRoundUp(size, PageSize);  // 确定页数
          size = numPages * PageSize;             // 计算真实占用大小
          ASSERT(numPages <= NumPhysPages);       // 确认运行文件大小可以运行
      
          DEBUG('a', "Initializing address space, num pages %d, size %d\n", numPages, size);
          // 第一步，创建页表，并对每一页赋初值
          pageTable = new TranslationEntry[numPages];
      
          ASSERT(userMap->NumClear() >= numPages);    // 确认页面足够分配 
          for (i = 0; i < numPages; i++) {
            pageTable[i].virtualPage = i;         // 虚拟页
            pageTable[i].physicalPage = userMap->Find();  // 在位图找空闲页进行分配
            pageTable[i].valid = TRUE;
            pageTable[i].use = FALSE;
            pageTable[i].dirty = FALSE;
            pageTable[i].readOnly = FALSE;        // 只读选项
          }
          // 第二步，将noff文件数据拷贝到物理内存中
          if (noffH.code.size > 0) {
            int pagePos = pageTable[noffH.code.virtualAddr/PageSize].physicalPage * PageSize;
            int offSet = noffH.code.virtualAddr % PageSize;
      
            executable->ReadAt(&(machine->mainMemory[pagePos+offSet]),
              noffH.code.size, noffH.code.inFileAddr); // ReadAt调用了bcopy函数
          }
          if (noffH.initData.size > 0) {
            int pagePos = pageTable[noffH.initData.virtualAddr/PageSize].physicalPage * PageSize;
            int offSet = noffH.initData.virtualAddr % PageSize;
      
            executable->ReadAt(&(machine->mainMemory[pagePos+offSet]),
                      noffH.initData.size, noffH.initData.inFileAddr);
          }
      #ifdef FILESYS
          for(int i = 3; i < 10; i++) fileDescriptor[i] = NULL;
          OpenFile *StdinFile = new OpenFile("stdin");
          OpenFile *StdoutFile = new OpenFile("stdout");
          OpenFile *StderrFile = new OpenFile("stderr");
          /* 输出、输入、错误 */
          fileDescriptor[0] = StdinFile;
          fileDescriptor[1] = StdoutFile;
          fileDescriptor[2] = StderrFile;
      #endif
      }
      ~~~

      - AddrSpace::~AddrSpace()

        该函数需要将地址空间所分配到的物理空间、spaceId 等释放。

      ~~~
      AddrSpace::~AddrSpace() {
        pidMap->Clear(spaceId-100);
        for(int i = 0; i < numPages; i++)
          userMap->Clear(pageTable[i].physicalPage);
        delete [] pageTable;
      }
      ~~~

      - AddrSpace::Print()

        该函数用于打印地址空间分配的页表。

      ~~~
      void AddrSpace::Print() {
          printf("page table dump: %d pages in total\n",numPages);
          printf("============================================\n");
          printf("\tVirtPage, \tPhysPage\n");
      
          for(int i = 0; i < numPages; i++)
              printf("\t%d,\t\t%d\n",pageTable[i].virtualPage,pageTable[i].physicalPage);
          printf("============================================\n\n");
      }
      ~~~

      - AddrSpace 中寄存器保存与恢复

      ~~~
      void AddrSpace::SaveState() {
        pageTable = machine->pageTable;
        numPages = machine->pageTableSize;
      }
      
      void AddrSpace::RestoreState() {
          machine->pageTable = pageTable;
          machine->pageTableSize = numPages;
      }
      ~~~

      - AddrSpace 中基于 FILESYS 实现的函数

      ~~~
      #ifdef FILESYS
      int AddrSpace::getFileDescriptor(OpenFile *openfile) {
        for(int i = 3; i < 10; i++)
          if(fileDescriptor[i] == NULL){
            fileDescriptor[i] = openfile;
            return i;
          }
        return -1;
      }
      
      OpenFile* AddrSpace::getFileId(int fd) {
        ASSERT((fd >= 0) && (fd < UserProgramNum));
        return fileDescriptor[fd];
      }
      
      void AddrSpace::releaseFileDescriptor(int fd) {
        ASSERT((fd >= 0) && (fd < UserProgramNum));
        fileDescriptor[fd] = NULL;
      }
      #endif
      ~~~

      

  - Thread

    - Thread 类

      在 Thread 类中，首先增加了 TERMINATED 进程状态，并定义了 waitProcessSpaceId、 waitProcessExitCode、exitCode 等变量用于 Join() 系统调用的实现，以及一系列函数关于这三个变量的访问与设定。

      ~~~
      // 线程状态
      enum ThreadStatus { JUST_CREATED, RUNNING, READY, BLOCKED, TERMINATED };
      
      class Thread {
        private:
          // 下述两个变量用于上下文切换，位置不可更改
          int* stackTop;			 // 当前栈指针
          _int machineState[MachineStateSize];  // 所有CPU寄存器状态
      
          int* stack;             // 栈底指针，主线程栈底指针为NULL
          char *name;
          ThreadStatus status;    // 线程状态（运行、可运行、阻塞）
          // 为线程分配栈空间，用于Fork函数内部实现
          void StackAllocate(VoidFunctionPtr func, _int arg);
      
      #ifdef USER_PROGRAM
          // 运行用户程序的线程有两组CPU寄存器，一个存储运行用户代码的线程状态，一个存储运行内核代码的线程状态
      
          int userRegisters[NumTotalRegs];    // 用户态下CPU寄存器状态
          int waitProcessSpaceId, waitProcessExitCode, exitCode;    
      #endif
      
        public:
          AddrSpace *space;			// 运行用户程序时的地址空间
          Thread(char* debugName);		// 构造函数 
          ~Thread(); 				// 析构函数，运行态线程不可析构
          
          // 下述为基础线程操作
          void Fork(VoidFunctionPtr func, _int arg); 	// 使线程运行在 (*func)(arg) 函数位置
          void Yield();  		// 当前线程，运行态 => 可运行态，调度其它线程
          void Sleep();  		// 当前线程，运行态 => 阻塞态，调度其它线程
          void Finish();  	// 线程运行结束
          
          void CheckOverflow();   	// 检查线程栈是否溢出
          void setStatus(ThreadStatus st) { status = st; }    // 设置线程状态
          char* getName() { return (name); }      // 获取线程名
          void Print() { printf("%s\n", name); }  // 输出线程名
      
      #ifdef USER_PROGRAM
          void SaveUserState();		// 保存用户态下寄存器状态
          void RestoreUserState();	// 恢复用户态下寄存器状态
          void Join(int SpaceId);
          void Terminated();
          int userProgramId() { return space->getSpaceId(); }
          int ExitCode() { return exitCode; }
          int waitExitCode() { return waitProcessExitCode; }
          int setWaitExitCode(int tmpCode) { waitProcessExitCode = tmpCode; }
          int setExitCode(int tmpCode) { exitCode = tmpCode; }
      #endif
      };
      ~~~

      - Thread::Thread()

      针对 Thread 类成员的增加，构造函数也需要作出一定的修改。

      ~~~
      Thread::Thread(char* threadName) {
          name = new char[50];
          strcpy(name,threadName);
          stackTop = NULL;
          stack = NULL;
          status = JUST_CREATED;
      #ifdef USER_PROGRAM
          space = NULL;
      #endif
      }
      ~~~

      - Thread::Finish()

      该函数用于结束一个进程，并将其对应的 Joiner 从等待队列中唤醒。

      ~~~
      void Thread::Finish () {
          (void) interrupt->SetLevel(IntOff);		
          ASSERT(this == currentThread);
      #ifdef USER_PROGRAM
          // 运行结束, 执行Exit()命令时已获取退出码
          // Joinee 运行结束, 唤醒 Joiner
          List *waitingList = scheduler->getWaitingList();
          // 检查 Joiner 是否在等待队列中
          ListElement *first = waitingList->listFirst(); // 队列首
          while(first != NULL){
              Thread *thread = (Thread *)first->item;     // 强转成Thread指针
              if(thread->waitProcessSpaceId == userProgramId()){       // 在队列中
                  // printf("yes\n");
                  // 将子线程退出码赋给父进程的等待退出码
                  thread->setWaitExitCode(exitCode);
                  scheduler->ReadyToRun((Thread *)thread);
                  waitingList->RemoveItem(first);
                  break;
              }
              first = first->next;
          }
          Terminated();
      #else
          DEBUG('t', "Finishing thread \"%s\"\n", getName());
          threadToBeDestroyed = currentThread;
          Sleep();
      #endif
      }
      ~~~

      - Thread::Join()

      该函数也属于 Join() 系统调用实现的一部分。

      ~~~
      void Thread::Join(int SpaceId) {
          IntStatus oldLevel = interrupt->SetLevel(IntOff);       // 关中断
          waitProcessSpaceId = SpaceId;                        // 设置当前线程所等待进程的spaceId
          List *terminatedList = scheduler->getTerminatedList();  // 终止队列
          List *waitingList = scheduler->getWaitingList();        // 等待队列
          // 确定Joinee在不在终止队列中
          bool interminatedList = FALSE;
          ListElement *first = terminatedList->listFirst(); // 队列首
          while(first != NULL){
              Thread *thread = (Thread *)first->item;     // 强转成Thread指针
              if(thread->userProgramId() == SpaceId){       // 在队列中
                  interminatedList = TRUE;
                  waitProcessExitCode = thread->ExitCode();  // 设置父线程等待子线程退出码
                  break;
              }
              first = first->next;
          }
          // Joinee不在终止队列中, 可运行态或阻塞态
          if(!interminatedList){
              waitingList->Append((void *)this);  // 阻塞Joiner
              currentThread->Sleep();             // Joiner阻塞
          }
          // 被唤醒且Joinee在终止队列中，在终止队列中删除Joinee
          scheduler->deleteTerminatedThread(SpaceId);
          (void) interrupt->SetLevel(oldLevel);   // 开中断
      }
      ~~~

      - Thread::Terminated()

      该函数为将一个进程终止并加入终止队列的具体代码。

      ~~~
      void Thread::Terminated() {
          List *terminatedList = scheduler->getTerminatedList();
          ASSERT(this == currentThread);
          ASSERT(interrupt->getLevel() == IntOff);
          status = TERMINATED;
          terminatedList->Append((void *)this);
          Thread *nextThread = scheduler->FindNextToRun();
          while(nextThread == NULL){
              // printf("yes\n");
              interrupt->Idle();
              nextThread = scheduler->FindNextToRun();
          }
          scheduler->Run(nextThread);
      }
      ~~~

  - **Scheduler**

    - Scheduler 类

      在 Scheduler 类中，增加了进程等待、终止队列并添加了这两个队列所对应的函数，具体代码如下所示：

      ~~~
      class Scheduler {
        public:
          Scheduler();			// 初始化调度队列
          ~Scheduler();			// 析构函数
      
          void ReadyToRun(Thread* thread);	// 将线程放入可运行队列
          Thread* FindNextToRun();		  // 找到第一个可运行态线程
          void Run(Thread* nextThread);	// 运行线程
          void Print();			// 打印可运行线程队列
          
        private:
          List *readyList;      // 可运行态线程的队列
      
      #ifdef USER_PROGRAM
        public:
          List *getReadyList() { return readyList; }
          List *getWaitingList() { return waitingList; }
          List *getTerminatedList() { return terminatedList; }
          void deleteTerminatedThread(int deleteSpaceId);
          void emptyList(List *tmpList) { delete tmpList; }
        private:
          List *waitingList;    // 等待运行线程的队列
          List *terminatedList; // 终止运行但未释放线程的队列
      #endif
      };
      ~~~

      - Scheduler::Scheduler()

      由于添加了新的类成员，因此需要在构造函数对类成员进行初始化。

      ~~~
      Scheduler::Scheduler() { 
          readyList = new List; 
      #ifdef USER_PROGRAM
          // 如果 Joinee 没有退出，Joiner 进入等待
          waitingList = new List;
          // 线程调用 Finish() 进入该队列，Joiner 通过检查该队列确定 Joinee 是否已经退出
          terminatedList = new List;
      #endif
      } 
      ~~~

      - Scheduler::~Scheduler()

      ~~~
      Scheduler::~Scheduler() { 
          delete readyList; 
          delete waitingList;
          delete terminatedList;
      } 
      ~~~

      - Scheduler::deleteTerminatedThread()

      该函数用于将一个线程从终止队列中移除，依然用于 Join() 系统调用的实现。

      ~~~
      #ifdef USER_PROGRAM
      void Scheduler::deleteTerminatedThread(int deleteSpaceId) {
          ListElement *first = terminatedList->listFirst();
          while(first != NULL){
              Thread *thread = (Thread *)first->item;
              if(thread->userProgramId() == deleteSpaceId){
                  terminatedList->RemoveItem(first);
                  break;
              }
              first = first->next;
          }
      }
      #endif
      ~~~

  - **List**

    该部分内容的修改主要是辅助 Scheduler 中针对队列操作，具体修改部分如下所示。

    - List 类

      在该类中主要添加了两个函数，分别是 `void RemoveItem(ListElement *tmp)` 与 `ListElement *listFirst()`，均用于 Scheduler 中的队列操作。

      ~~~
      class List {
        public:
          List();		// 初始化 List
          ~List();    // 析构函数 
      
          void Prepend(void *item); 	// 将 item 放到 List 首
          void Append(void *item); 	// 将 item 放到 List 尾
          void *Remove(); 	 // 将 item 从 List 首移除
          void Mapcar(VoidFunctionPtr func);	// 对 List 中每个元素应用 "func"
          bool IsEmpty();		// List 是否为空
          void RemoveItem(ListElement *tmp);  // 移除 List 中一个元素
          
          // Routines to put/get items on/off list in order (sorted by key)
          void SortedInsert(void *item, int sortKey);	// Put item into list
          void *SortedRemove(int *keyPtr); 	  	   // Remove first item from list
          ListElement *listFirst() { return first; }
      
        private:
          ListElement *first;  	// List 首，NULL 则为空
          ListElement *last;		// List 尾
      };
      ~~~

      - List::RemoveItem()

        该函数用于从 List 中删除一个 ListElement，用于实现 Scheduler 类中从终止队列中移除一个元素的功能。

      ~~~
      void List::RemoveItem(ListElement *tmp) {
          bool isFind = FALSE;
          ListElement *now = first, *pre = NULL;
          while(now != NULL){
              if(now->item == tmp->item) { isFind = TRUE; break;}
              pre = now;
              now = now->next;
          }
          if(isFind){
              if(first == last) first = last = NULL;  // 队里只有一个元素
              else{
                  if(pre == NULL) first = first->next;    // 删队首
                  else if(now == last) {last = pre; last->next = NULL;}   // 删队尾
                  else{   // 删中间
                      pre->next = now->next;
                  }
              }
          }
      }
      ~~~

  - **OpenFile**

    该部分内容的修改主要是用于基于 FILESYS 的文件系统调用的实现，具体修改部分如下所示。

    - OpenFile 类

      该类的修改主要针对于后续基于 FILESYS 实现的文件系统调用的实现。

      ~~~
      #ifdef FILESYS	
      class FileHeader;
      
      class OpenFile {
        public:
          OpenFile(int sector);   // 打开一个文件头在 sector 扇区的文件（DISK）
          ~OpenFile();			// 关闭文件
      
          void Seek(int position); 	// 定位文件读写位置
          // 读取 numBytes 字节数据到 into 中，返回实际读取字节
          int Read(char *into, int numBytes);
          // 将 from 中 numByters 数据写入 OpenFile 中
          int Write(char *from, int numBytes);
          // 从 OpenFile 的 pos 位置读取字节到 into 中
          int ReadAt(char *into, int numBytes, int position);
          // 从 from 中的 pos 位置读取字节到 OpenFile 中 
          int WriteAt(char *from, int numBytes, int position);
          int Length();       // 返回文件字节数
          void WriteBack();   // 将文件头写回 DISK 中
      
      #ifdef FILESYS
          OpenFile(char *type) {}
          int WriteStdout(char *from, int numBytes);
          int ReadStdin(char *into, int numBytes);
      #endif
          
        private:
          FileHeader *hdr;	// 文件头
          int seekPosition, hdrSector; // 文件当前读取位置，文件头所在扇区号
      };
      #endif
      ~~~

    - OpenFile::WriteStdout()

      将数据写入输出对应的 OpenFile 中。

      ~~~
      int OpenFile::WriteStdout(char *from, int numBytes) {
          int file = 1;
          WriteFile(file,from,numBytes);  // 将from文件数据写入file中
          return numBytes;
      }
      ~~~

    - OpenFile::ReadStdin()

      将 OpenFile 中的数据写入对应的 into 文件中。

      ~~~
      int OpenFile::ReadStdin(char *into, int numBytes) {
          int file = 0;
          return ReadPartial(file,into,numBytes); // 将file文件数据写入into中
      }
      ~~~

  - **exception.cc**

    该代码主要实现了实验中要求实现的各个系统调用，包括 Exec()、Exit()、Join()、Yield() 基础系统调用以及基于文件系统的 Create()、Open()、Write()、Read()、Close() 系统调用，此处分别实现了基于 FILESYS_STUB 与 FILESYS 两套文件系统的文件系统调用。

    - Exec()

      该系统调用主要用于执行一个新的 Nachos 文件，在 FILESYS 中从 DISK 中寻找该文件，在 FILESYS_STUB 中则在 UNIX 系统中寻找文件。

      ~~~
      void AdvancePC(){
          machine->WriteRegister(PrevPCReg,machine->ReadRegister(PCReg));		// 前一个PC
          machine->WriteRegister(PCReg,machine->ReadRegister(NextPCReg));		// 当前PC
          machine->WriteRegister(NextPCReg,machine->ReadRegister(NextPCReg)+4);	// 下一个PC
      }
      
      void StartProcess(int spaceId) {
      	// printf("spaceId:%d\n",spaceId);
          ASSERT(currentThread->userProgramId() == spaceId);
          currentThread->space->InitRegisters();     // 设置寄存器初值
          currentThread->space->RestoreState();      // 加载页表寄存器
          machine->Run();             // 运行
          ASSERT(FALSE);
      }
      
      case SC_Exec:{
      	printf("This is SC_Exec, CurrentThreadId: %d\n",(currentThread->space)->getSpaceId());
      	int addr = machine->ReadRegister(4);
      	char filename[50];
      	for(int i = 0; ; i++){
      		machine->ReadMem(addr+i,1,(int *)&filename[i]);
      		if(filename[i] == '\0') break;
      	}
      	OpenFile *executable = fileSystem->Open(filename);
      	if(executable == NULL) {
      		printf("Unable to open file %s\n",filename);
      		return;
      	}
      	// 建立新地址空间
      	AddrSpace *space = new AddrSpace(executable);
      	// space->Print();   // 输出新分配的地址空间
      	delete executable;	// 关闭文件
      	// 建立新核心线程
      	Thread *thread = new Thread(filename);
          printf("new Thread, SpaceId: %d, Name: %s\n",space->getSpaceId(),filename);
      	// 将用户进程映射到核心线程上
      	thread->space = space;
      	thread->Fork(StartProcess,(int)space->getSpaceId());
      	machine->WriteRegister(2,space->getSpaceId());
      	AdvancePC();
      	break;
      }
      ~~~

    - Exit()

      该系统调用用于一个用户程序的退出，具体代码如下所示。

      ~~~
      case SC_Exit:{
          printf("This is SC_Exit, CurrentThreadId: %d\n",(currentThread->space)->getSpaceId());
      	int exitCode = machine->ReadRegister(4);
      	machine->WriteRegister(2,exitCode);
      	currentThread->setExitCode(exitCode);
      	// 父进程的退出码特殊标记，由 Join 的实现方式决定
      	if(exitCode == 99)
      		scheduler->emptyList(scheduler->getTerminatedList());
      	delete currentThread->space;
      	currentThread->Finish();
          AdvancePC();
      	break;
      }
      ~~~

    - Join()

      该系统调用用于一个父线程（Joiner）等待一个子线程（Joinee）运行结束后再继续运行，常用于同步设计中。

      ~~~
      case SC_Join:{
          printf("This is SC_Join, CurrentThreadId: %d\n",(currentThread->space)->getSpaceId());
      	int SpaceId = machine->ReadRegister(4);
      	currentThread->Join(SpaceId);
      	// waitProcessExitCode —— 返回 Joinee 的退出码
      	machine->WriteRegister(2, currentThread->waitExitCode());
      	AdvancePC();
      	break;
      }
      ~~~

    - Yield()

      ~~~
      case SC_Yield:{
          printf("This is SC_Yield, CurrentThreadId: %d\n",(currentThread->space)->getSpaceId());
          currentThread->Yield();
          AdvancePC();
          break;
      }
      ~~~

    - FILESYS_STUB - Create()

      该系统调用基于 FILESYS_STUB 实现了文件系统调用 Create()，即在 UNIX 系统中创建一个新文件，具体代码如下所示。

      ~~~
      case SC_Create:{
          int addr = machine->ReadRegister(4);
          char filename[128];
          for(int i = 0; i < 128; i++){
              machine->ReadMem(addr+i,1,(int *)&filename[i]);
              if(filename[i] == '\0') break;
          }
          int fileDescriptor = OpenForWrite(filename);
          if(fileDescriptor == -1) printf("create file %s failed!\n",filename);
          else printf("create file %s succeed, the file id is %d\n",filename,fileDescriptor);
          Close(fileDescriptor);
          // machine->WriteRegister(2,fileDescriptor);
          AdvancePC();
          break;
      }
      ~~~

    - FILESYS_STUB - Open()

      该系统调用基于 FILESYS_STUB 实现了文件系统调用 Open()，即在 UNIX 系统中打开一个已经存在的文件，具体代码如下所示。

      ~~~
      case SC_Open:{
          int addr = machine->ReadRegister(4);
          char filename[128];
          for(int i = 0; i < 128; i++){
              machine->ReadMem(addr+i,1,(int *)&filename[i]);
              if(filename[i] == '\0') break;
          }
          int fileDescriptor = OpenForWrite(filename);
          if(fileDescriptor == -1) printf("Open file %s failed!\n",filename);
          else printf("Open file %s succeed, the file id is %d\n",filename,fileDescriptor);                
          machine->WriteRegister(2,fileDescriptor);
          AdvancePC();
          break;
      }
      ~~~

    - FILESYS_STUB - Write()

      该系统调用基于 FILESYS_STUB 实现了文件系统调用 Write()，即在 UNIX 系统中将数据写入一个已经存在的文件中，具体代码如下所示。

      ~~~
      case SC_Write:{
          // 读取寄存器信息
          int addr = machine->ReadRegister(4);
          int size = machine->ReadRegister(5);       // 字节数
          int fileId = machine->ReadRegister(6);      // fd
          
          // 打开文件
          OpenFile *openfile = new OpenFile(fileId);
          ASSERT(openfile != NULL);
      
          // 读取具体数据
          char buffer[128];
          for(int i = 0; i < size; i++){
              machine->ReadMem(addr+i,1,(int *)&buffer[i]);
              if(buffer[i] == '\0') break;
          }
          buffer[size] = '\0';
      
          // 写入数据
          int writePos;
          if(fileId == 1) writePos = 0;
          else writePos = openfile->Length();
          // 在 writePos 后面进行数据添加
          int writtenBytes = openfile->WriteAt(buffer,size,writePos);
          if(writtenBytes == 0) printf("write file failed!\n");
          else printf("\"%s\" has wrote in file %d succeed!\n",buffer,fileId);
          AdvancePC();
          break;
      }
      ~~~

    - FILESYS_STUB - Read()

      该系统调用基于 FILESYS_STUB 实现了文件系统调用 Read()，即在 UNIX 系统中将数据从一个已经存在的文件中读出，具体代码如下所示。

      ~~~
      case SC_Read:{
          // 读取寄存器信息
          int addr = machine->ReadRegister(4);
          int size = machine->ReadRegister(5);       // 字节数
          int fileId = machine->ReadRegister(6);      // fd
      
          // 打开文件读取信息
          char buffer[size+1];
          OpenFile *openfile = new OpenFile(fileId);
          int readnum = openfile->Read(buffer,size);
      
          for(int i = 0; i < size; i++)
              if(!machine->WriteMem(addr,1,buffer[i])) printf("This is something Wrong.\n");
          buffer[size] = '\0';
          printf("read succeed, the content is \"%s\", the length is %d\n",buffer,size);
          machine->WriteRegister(2,readnum);
          AdvancePC();
          break;
      }
      ~~~

    - FILESYS_STUB - Close()

      该系统调用基于 FILESYS_STUB 实现了文件系统调用 Close()，即将一个已经分配的文件 Id 关闭，但不是删除这个文件。再次使用该文件需要重新打开，具体代码如下所示。

      ~~~
      case SC_Close:{
          int fileId = machine->ReadRegister(4);
          Close(fileId);
          printf("File %d closed succeed!\n",fileId);
          AdvancePC();
          break;
      }
      ~~~

    - FILESYS - Create()

      该系统调用基于 FILESYS 实现了文件系统调用 Create()，即在 Nachos 系统中创建一个新文件，具体代码如下所示。

      ~~~
      case SC_Create:{
          int addr = machine->ReadRegister(4);
          char filename[128];
          for(int i = 0; i < 128; i++){
              machine->ReadMem(addr+i,1,(int *)&filename[i]);
              if(filename[i] == '\0') break;
          }
          if(!fileSystem->Create(filename,0)) printf("create file %s failed!\n",filename);
          else printf("create file %s succeed!\n",filename);
          AdvancePC();
          break;
      }
      ~~~

    - FILESYS - Open()

      该系统调用基于 FILESYS 实现了文件系统调用 Open()，即在 Nachos 系统中打开一个已经存在于 模拟硬盘 DISK 中的文件，具体代码如下所示。

      ~~~
      case SC_Open:{
          int addr = machine->ReadRegister(4), fileId;
          char filename[128];
          for(int i = 0; i < 128; i++){
              machine->ReadMem(addr+i,1,(int *)&filename[i]);
              if(filename[i] == '\0') break;
          }
          OpenFile *openfile = fileSystem->Open(filename);
          if(openfile == NULL) {
              printf("File \"%s\" not Exists, could not open it.\n",filename);
              fileId = -1;
          }
          else{
              fileId = currentThread->space->getFileDescriptor(openfile);
              if(fileId < 0) printf("Too many files opened!\n");
              else printf("file:\"%s\" open succeed, the file id is %d\n",filename,fileId);
          }
          machine->WriteRegister(2,fileId);
          AdvancePC();
          break;
      }
      ~~~

    - FILESYS - Write()

      该系统调用基于 FILESYS 实现了文件系统调用 Write()，即在 Nachos 系统中将数据写入模拟硬盘 DISK 中已经存在的文件中，具体代码如下所示。

      ~~~
      case SC_Write:{
          // 读取寄存器信息
          int addr = machine->ReadRegister(4);       // 写入数据
          int size = machine->ReadRegister(5);       // 字节数
          int fileId = machine->ReadRegister(6);      // fd
          
          // 创建文件
          OpenFile *openfile = new OpenFile(fileId);
          ASSERT(openfile != NULL);
      
          // 读取具体写入的数据
          char buffer[128];
          for(int i = 0; i < size; i++){
              machine->ReadMem(addr+i,1,(int *)&buffer[i]);
              if(buffer[i] == '\0') break;
          }
          buffer[size] = '\0';
      
      
          // 打开文件
          openfile = currentThread->space->getFileId(fileId);
          if(openfile == NULL) {
              printf("Failed to Open file \"%d\".\n",fileId);
              AdvancePC();
              break;
          }
          if(fileId == 1 || fileId == 2){
              openfile->WriteStdout(buffer,size);
              delete []buffer;
              AdvancePC();
              break;
          }
      
          // 写入数据
          int writePos = openfile->Length();
          openfile->Seek(writePos);
      
          // 在 writePos 后面进行数据添加
          int writtenBytes = openfile->Write(buffer,size);
          if(writtenBytes == 0) printf("Write file failed!\n");
          else if(fileId != 1 & fileId != 2)
              printf("\"%s\" has wrote in file %d succeed!\n",buffer,fileId);
          AdvancePC();
          break;
      }
      ~~~

    - FILESYS - Read()

    该系统调用基于 FILESYS 实现了文件系统调用 Read()，即在 Nachos 系统中将数据从模拟硬盘 DISK 中一个已经存在的文件中读出，具体代码如下所示。

    ~~~
    case SC_Read:{
        // 读取寄存器信息
        int addr = machine->ReadRegister(4);
        int size = machine->ReadRegister(5);       // 字节数
        int fileId = machine->ReadRegister(6);      // fd
    
        // 打开文件
        OpenFile *openfile = currentThread->space->getFileId(fileId);
    
        // 打开文件读取信息
        char buffer[size+1];
        int readnum = 0;
        if(fileId == 0) readnum = openfile->ReadStdin(buffer,size);
        else readnum = openfile->Read(buffer,size);
    
        // printf("readnum:%d,fileId:%d,size:%d\n",readnum,fileId,size);
        for(int i = 0; i < readnum; i++)
            machine->WriteMem(addr,1,buffer[i]);
        buffer[readnum] = '\0';
    
        for(int i = 0; i < readnum; i++)
            if(buffer[i] >= 0 && buffer[i] <= 9) buffer[i] = buffer[i]+0x30;
        char *buf = buffer;
        if(readnum > 0){
            if(fileId != 0)
                printf("Read file (%d) succeed! the content is \"%s\", the length is %d\n",fileId,buf,readnum);
        }
        else printf("\nRead file failed!\n");
        machine->WriteRegister(2,readnum);
        AdvancePC();
        break;
    }
    
    ~~~

    - FILESYS - Close()

      该系统调用基于 FILESYS 实现了文件系统调用 Close()，即将一个已经分配的文件 Id 清楚，但不是删除这个文件。再次使用该文件需要重新打开，具体代码如下所示。

      ~~~
      case SC_Close:{
          int fileId = machine->ReadRegister(4);
          OpenFile *openfile = currentThread->space->getFileId(fileId);
          if(openfile != NULL) {
              openfile->WriteBack(); // 将文件写入DISK
              delete openfile;
              currentThread->space->releaseFileDescriptor(fileId);
              printf("File %d closed succeed!\n",fileId);
          }
          else printf("Failed to Close File %d.\n",fileId);
          AdvancePC();
          break;
      }
      ~~~

- **实验测试结果：**

  - Exec() 系统调用：

    ![image-20220506161218406](https://s2.loli.net/2022/05/26/NouzMW3OYBrTq1A.png)

  - Exit() 系统调用：

    ![image-20220506161235333](https://s2.loli.net/2022/05/26/LAXGf4dnHFsPg3D.png)
