# 插入第五章

## 环境准备

编译debug版本的*make CFLAGS="-g -O0" -j 4*，先关的信息:

​		Reading symbols **from** /root/gdbtest/redis-4.0.11/src/redis-server...done.



## run命令

当 GDB 触发断点或者使用 Ctrl + C 命令中断下来后。可以使用run重新开始跑



## continue

当 GDB 触发断点或者使用 Ctrl + C 命令中断下来后，想让程序继续运行，只要输入 **continue** 命令即可（简写为 c）。当然，如果 **continue** 命令继续触发断点，GDB 就会再次中断下来。

## 

## break

break命令 简写b 既为我们添加断电和命令，可以使用一下方式添加断电

1.break functionname     		在函数

2.break LineNo 				在当前文件行号为LineNo处添加一个断电

3.break  filename:LineNo 		在filename文件行号为line  No处添加一个断点



## backtrace 与 frame 命令

1.可以通过 **backtrace** 命令来查看当前的调用堆栈

2.frame 某一个编号的堆栈信息



## info break、enable、disable 和 delete 命令

info break 查看断点的信息<br>enable       使能断点<br>disable      关闭断点<br>delete       删除断点



## list用法和熟悉 

作用是显示问题

https://blog.csdn.net/sfeng177/article/details/53014289

对于这个命令的理解:

这个命令的作用意义不大，看代码得最好的方式在vscode



## print 和 ptype 命令

### print 

​	作用:方便查看某个变量的值

​	打印某个地址的值:	 	p &server.port 

​        p a + b + c		      	三个变量的值

​	p func()			   	打印函数的返回值

​        p strerror(errno)		   打印系统环境变量

​			

### ptype  

​	作用打印某个变量的类型