## 缘起

+ 20181123读第一遍

## 内容

### 3.1、main是C程序的开始吗？

+ [beforemain.c]
  + `gcc -v beforemain.c`时能看到不少C库二进制文件参与进来。
  + `ld -verbose` **”组装“的过程中，是由链接器ld的链接脚本决定的。没有指定链接脚本的情况下，会使用ld的默认脚本**。
  + `__attribute__((constructor))`就是将函数的对应指令归属于`.ctors section`中。
  + `objdump`命令

### 3.2、”活雷锋“exit

+ **正常退出会执行exit；进程崩溃或kill掉时，只会执行内核退出进程的操作**。

### 3.3、atexit介绍

+ 3.3.1 使用atexit
  + atexit用于注册进程正常退出时的回调函数。**多个时，后进先出**。
  + [atexit.c]
+ 3.3.2 atexit的局限性
  + [atexit01.c]
+ 3.3.3 atexit的实现机制
  + glibc中的atexit源码。

### 3.4、小心使用环境变量

+ [putenv.c]
+ [setenv.c]

### 3.5、使用动态库

+ 3.5.1 动态库和静态库
+ 3.5.2 编译生成和使用动态库
+ 3.5.3 程序的”平滑无缝“升级

### 3.6、避免内存问题

+ 3.6.1 尴尬的realloc
+ 3.6.2 如何防止内存越界
+ 3.63 如何定位内存问题

### 3.7、”长跳转“longjmp

+ 3.7.1 setjmp与longjmp的使用
+ 3.7.2 ”长跳转“的实现机制
+ 3.7.3 ”长跳转“的陷阱