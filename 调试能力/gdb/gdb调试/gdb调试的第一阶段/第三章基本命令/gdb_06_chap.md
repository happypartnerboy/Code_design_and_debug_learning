# 第六章

## info 和 thread 

info  break 	查看当前相关的段点



<font color=red> 显示线程</font><br> info thread

作用显示当前程序存在的线程

例如:

**Id**   Target **Id**         Frame

 **Id**   Target **Id**         Frame
4    **Thread**    0x7fffef7fd700 (LWP 53065) "redis-server" 0x00007ffff76c4945 **in** pthread_cond_wait@@GLIBC_2.3.2 () **from** /lib64/libpthread.so.0
3     **Thread**   0x7fffefffe700 (LWP 53064) "redis-server" 0x00007ffff76c4945 **in** pthread_cond_wait@@GLIBC_2.3.2 () **from** /lib64/libpthread.so.0
2      **Thread**   0x7ffff07ff700 (LWP 53063) "redis-server" 0x00007ffff76c4945 **in** pthread_cond_wait@@GLIBC_2.3.2 () **from** /lib64/libpthread.so.0

*1    **Thread**   0x7ffff7fec780 (LWP 53062) "redis-server" 0x00007ffff73ee923 **in** epoll_wait () **from** /lib64/libc.so.6

解析:

(1)一共产生了 4 个线程，包括一个主线程和三个工作线程

(2)三个工作线程（2、3、4）分别阻塞在 Linux API pthread_cond_wait 处，而主线程（1）阻塞在 epoll_wait 处。

(3)53065 53064 53063 53062 表示线程ID

(4)带*  表示gdb正在作用于那个线程



<font color=red>线程的堆栈</font>

现在有 4 个线程，也就有 4 个调用堆栈，如果此时输入 **backtrace** 命令查看调用堆栈，由于当前 GDB 作用在线程 1，因此 **backtrace** 命令显示的一定是线程 1 的调用堆栈：

thread 2 表示切换到那个线程，在使用backtrace确定这个线程的相关信息



info args	

命令还可以用来查看<font color= red>当前函数的参数值</font>



具体info的其他的用法

查看:info help



## gdb函数控制流的几个命令

### next  **step** 

<font color = red> next </font><br>

含义:**next** 命令（简写为 n）是让 GDB 调到下一条命令去执行。

**next** 命令用调试的术语叫“<font color =red>单步调试</font>”（step over），即遇到函数调用直接跳过，不进入函数体内部.

<font color = red>step</font><br> 含义： **step** 命令（简写为 **s**）就是“单步步入”（step into），顾名思义，就是遇到函数调用，进入函数内部。



### finish  return 

<font color = red>finish</font><br>

含义：实际调试时，我们在某个函数中调试一段时间后，不需要再一步步执行到函数返回处，希望直接执行完当前函数并回到上一层调用处，就可以使用 **finish** 命令 <br> 

<font color = red>  return </font> 

含义: 命令是立即结束,执行当前函数并返回.不会执行相关的命令



### until  jump

until 命令:可以指定程序运行到某一行停下来. 这样可以不用单步执行



jump <location>  location 可以是行号或者地址

<font color = red> jump </font>的使用时需要注意的地方

































