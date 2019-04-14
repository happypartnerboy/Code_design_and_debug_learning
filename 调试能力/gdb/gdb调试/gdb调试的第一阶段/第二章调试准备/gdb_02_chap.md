# 启动 GDB 调试 

1.gdb filename 					直接调试目标程序

2.gdb attach pid				      附加进程

3.gdb filename corename		      调试core文件



## 1.直接调试目标程序

在开发阶段或者研究别人的项目时，当编译成功生成目标二进制文件后，可以使用 **gdb filename** 直接启动这个程序的调试其中 **filename** 是需要启动的调试程序文件名，这种方式是直接使用 GDB 启动一个程序进行调试



## 2.附加进程

情况：

​	在某些情况下，一个程序已经启动了，我们想调试这个程序，但是又不想重启这个程序。假设有这样一个场景，我们的聊天测试服务器程序正在运行，运行一段时间之后，发现这个聊天服务器不能接受新的客户端连接了，这时肯定是不能重启程序的，如果重启，当前程序的各种状态信息就丢失了。怎么办呢？可以使用**gdb attach 进程 ID** 来将 GDB 调试器附加到聊天测试服务器程序上



## 3.调试core文件

有时候，服务器程序运行一段时间后会突然崩溃，这并不是我们希望看到的，需要解决这个问题。只要程序在崩溃的时候有 core 文件产生，就可以使用这个 core 文件来定位崩溃的原因。

### 3.1开启core文件的方法

​	**ulimit -c unlimited**

​	/etc/profile 

### 3.2自定义core文件的名称

- 自定义 core 文件的名称和目录

<font color = red> /proc/sys/kernel/core_uses_pid</font> 主要是向这个文件中写入控制格式来决定输出的方式

具体格式如下:

各个参数的说明如下：

| 参数名称 | 参数含义（英文）                                          | 参数含义（中文）                               |
| -------- | --------------------------------------------------------- | ---------------------------------------------- |
| %p       | insert pid into filename                                  | 添加 pid 到 core 文件名中                      |
| %u       | insert current uid into filename                          | 添加当前 uid 到 core 文件名中                  |
| %g       | insert current gid into filename                          | 添加当前 gid 到 core 文件名中                  |
| %s       | insert signal that caused the coredump into the filename  | 添加导致产生 core 的信号到 core 文件名中       |
| %t       | insert UNIX time that the coredump occurred into filename | 添加 core 文件生成时间（UNIX）到 core 文件名中 |
| %h       | insert hostname where the coredump happened into filename | 添加主机名到 core 文件名中                     |
| %e       | insert coredumping executable name into filename          | 添加程序名到 core 文件名中                     |

假设现在的程序叫 **test**，我们设置该程序崩溃时的 core 文件名如下：

echo "/root/testcore/core-%e-%p-%t" > /proc/sys/kernel/core_pattern

生成core文件的目录:/root/testcore/

生成core文件的名称:core-test-13154-1547445291

![img](https://images.gitbook.cn/1abcbda0-1809-11e9-90f4-4f5962647553)

<font color = red> 注意:</font>

需要注意的是，您使用的用户必须对指定 core 文件目录具有写权限，否则生成时 会因为权限不足而导致无法生成core 文件

