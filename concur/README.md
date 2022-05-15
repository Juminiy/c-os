# OS

在 preface-intro 直播中，jyy说：”GCC和Clang的编译器做的太差了，Clang的所谓**优化**把我的程序结构弄得一团糟，我如果手写x86_64汇编绝对比机器给我编译的要好。我相信未来的编译器是智能的，这也是我们在做的事。“ 至于有没有可能将用C语言写的冒泡排序变为快速排序，甚至优于原始程序的性能？他认为这是有可能的。既然有公有网络和ML以及炼丹炉，就可能通过程序合成的方式做到智能编译，更有可能发展为一个平台，会有越来越多的学者去探索，未来是无可限量的！

[视频课程](https://space.bilibili.com/202224425/channel/collectiondetail?sid=192498)，[原书教材PDF](https://pages.cs.wisc.edu/~remzi/OSTEP)，[秃头链接](https://jyywiki.cn/)

## chapter-1 CPU-Intro

操作系统三个特性：虚拟，并发，持久化

并发，共享，虚拟，异步

os创造错觉对一个实际的cpu，时分复用技术time sharing CPU，时分复用技术在所有现代计算机中都实现了

Process API

任何的现代化的操作系统都可用

- 创建

  操作系统必须实现创建进程的方式，当我们在shell输入命令或者双击一个图标

- 销毁

  也必须提供强制销毁进程的接口，对于那些后台的进程

- 等待

  等待一些进程去停止运行

- 杂项控制

  挂起一段时间,然后恢复它

- 状态

  必须为用户提供查看进程信息的接口,来显示进程的运行状态,例如: 多长时间的使用,他所处的状态(就绪,运行,阻塞),cpu和内存占用率

### 创建

> 一件关键的事情程序如何转变为进程

os将程序和静态数据最开始被放置到`disk`(SSDs),程序是一种可执行的格式，加载程序进程将他们（code and static data），加载到内存，进入进程地址空间

早期操作系统是在运行前全部加载到内存，现代操作系统是懒加载的（仅仅加载执行期间需要的），那么paging和swapping对现代操作系统尤为重要，这是虚拟化内存的一部分

os对于运行时stack，内存必须被分配

os可能分配一些内存对于程序的heap，如C的 ：malloc() free()，堆是需要一些有趣的数据结构的，运行时动态调度来满足用户需求

通过加载代码和动态数据到内存中，通过创建和初始化栈，做I/O设置，终于完成了程序执行的初始化，在执行点开始执行，即：程序的入口位置，通常是main()，当然会有特例

### 状态

- Running 执行
- Ready 就绪
- Blocked 阻塞

被os调度，ready-> running 

被os挂起，running-> ready

I/O操作：running-> blocked

I/O完成：blocked-> ready

进程在OS的discretion中决定状态是 running 还是 ready，当然被阻塞的情况有可能是I/O，也有可能是其他的case（从磁盘读或者是网络I/O）

PDF第七页很好的说明了这个问题

双进程模式：p0，p1

p0 运行时可能有I/O，p0则被阻塞，cpu运行p1，当p0的I/O完成后，p1仍运行，p0阻塞，到p1运行完成后，p0运行直到完成

### 数据结构

os是个程序，用数据结构来保存数据，跟踪进程信息，例如：在阻塞的程序I/O完成后，os应该调度唤醒其重新运行

在本书的示例os，xv6 架构的cpu，模拟的context结构为：

````c
// xv6 os will save the registers info 
struct context { 
    int eip;
    int esp;
    int ebx;
    int ecx;
    int edx;
    int esi;
    int edi;
    int dbp;
};

// 进程的状态 
enum proc_state { UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };  

// 进程数据结构 xv6跟踪的进程信息
struct proc {
    char *mem; // 进程起始地址
    uint sz;   // 进程占用内存大小
    char *kstack; // 内核栈底
    
    enum proc_state state;// state
    int pid;              // 进程id
    struct proc *parent;  // 父进程
    void *chan;           // !zero , sleeping on chan
    int killed;           // !zero , has been killed
    struct file *ofile[NOFILE]; // open files
    struct inode *cwd;          // current directory 
    struct context context;     // 保存的寄存器info
    struct trapframe *tf;       // 当前中断的陷阱框架
}; 
````

停止进程：进程的当前context结构保存在内存中，在running后重新恢复restore，我们会在后续章节学到有关`context switch`的内容

有时os会设置进程创建初期的初始状态，僵尸进程是没有被清理但是已经完成的



并发程序

我根本不会使用gcc工具链

 ````bash
 gcc hi.c -lpthread
 ./a.out | head -n 100000 | sort -nk 6 | uniq -c  
 
 gcc hi.c =lpthread && ./a.out 
 top # 查看hi.c 的 cpu利用率 
 ````

一旦程序变为了多线程并发执行模式的时候，那么情况将会变得复杂和难以预料

## chapter-2 CPU Mechanism

为了虚拟化CPU，OS必须做时分复用。

- 性能：不给操作系统添加额外负载
- 控制：尤其的重要

在保证高性能的情况下维持控制是构建os的一个核心挑战

基础的技术：限制直接执行

这是所有OS开发者的一个解决方案，不直接执行程序

一个新的处理模式：user mode: 严格的，进程不可以处理I/O，会导致处理器抛出异常，os可能杀死进程 

与之对应的就是：kernel mode，任何类型的操作都不被限制

为了使得用户程序能够执行一些操作（磁盘读/写），提供`system call`方式

为了执行`system call`提供陷入`trap`指令

