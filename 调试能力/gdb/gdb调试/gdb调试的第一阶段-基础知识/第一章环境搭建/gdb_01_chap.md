# 12调试信息与调试原理

![gcc调用关系](C:\Users\Administrator\Desktop\gcc调用关系.png)





## 环境安装

yum install gcc 

yum install g++

yum install gdb



## 调试符号

为了能清晰地看到调试的每一行代码、调用的堆栈信息、变量名和函数名等信息。

需要调试程序含有<font color = red>调试符号</font>信息 

gcc -g -o hello_server hello_server.c	//加入-g 选项

那么如何判断 hello_server 是否带有调试信息呢?

方法<br> 	**gdb hello_server** 

​	<font color =red>Reading symbols **from** /root/testclient/hello_server...done.</font>

即读取符号文件完毕，说明该程序含有调试信息 

如果不加上-g
	(no debugging symbols found)

如果使用<font color = red>strip</font> 也是无法调试处 (no debugging symbols found)



## 额外

- 本课程里虽然以 gcc 为例，但 -g 选项实际上同样也适用于使用 makefile 、cmake 等工具编译生成的 Linux 程序。
- 在实际生成调试程序时，一般不仅要加上 -g 选项，也建议关闭编译器的程序优化选项。编译器的程序优化选项一般有五个级别，从 O0 ~ O4 （ 注意第一个 O0 ，是字母 O 加上数字 0 ）， O0 表示不优化，从 O1 ~ O4 优化级别越来越高，O4 最高。这样做的目的是为了调试的时候，符号文件显示的调试变量等能与源代码完全对应起来



























