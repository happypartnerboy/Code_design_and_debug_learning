# GDB相关命令详解

## set args 和 show args 命令

<font color = font>set args</font>

很多程序需要我们传递命令行参数set args，进行传递参数



<font color = red>show args</font>

 查看命令行参数是否设置成功



## tbreak 命令

命令也是添加一个断点，第一个字母“**t**”的意思是 temporarily（临时的），也就是说这个命令加的断点是临时的，所谓临时断点，就是一旦该断点触发一次后就会自动删除。



## watch命令和display 命令

**watch** 命令是一个强大的命令，它可以用来监视一个变量或者一段内存，当这个变量或者该内存处的值发生变化时，GDB 就会中断下来。被监视的某个变量或者某个内存地址会产生一个 watch point（观察点）。

<font color = red> 目的</font>：如何快速地定位到该变量在哪里被修改了？答案是“硬件断点”。具体什么是硬件断点，我将在后面高级调试课程中介绍，而 watch 命令就可以通过添加硬件断点来达到监视数据变化的目的。watch 命令的使用方式是“watch 变量名或内存地址”，一般有以下几种形式：

形式一:整形变量

int i;

watch i



形式二:指针类型

char *p

watch p 与 watch *p



<font color = red> 对某一段的内存进行检查</font> 或者数组

char buf[128]

watch  buf

这里是对buf的128个数据进行了监视，此时不是采用硬件断电，而是软件中断实现的。

注明:

**注意**：当设置的观察点是一个局部变量时，局部变量无效后，观察点也会失效。在观察点失效时 GDB 可能会提示如下信息：

```
Watchpoint 2 deleted because the program has left the block in which its expression is valid.
```



## display命令

具体使用方法:

**display** 命令监视的变量或者内存地址，每次程序中断下来都会自动输出这些变量或内存的值。例如，假设程序有一些全局变量，每次断点停下来我都希望 GDB 可以自动输出这些变量的最新值，那么使用“**display 变量名**”设置即可

info display

delete diaplay

