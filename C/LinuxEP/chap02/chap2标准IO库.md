##  缘起
+ 2017-09-05开始看；

##  内容

### 2.1 stdin、stdout和stderr
+ C库中与文件描述表（0、1和2）对应的是文件指针（stdin、stdout和stderr）。
+ 去[glibc](http://ftp.gnu.org/gnu/glibc/)下载了2.26.tar.gz看了一下glibc-2.26/libio/stdio.h里`extern struct _IO_FILE *stdin;`它们确实是文件指针。
+ C标准库要求stdin、stdout和stderr是宏定义，所以在C库的代码中又定义了同名宏。`_IO_FILE *stdin = (FILE *) &_IO_2_1_stdin_;`（这是书中的例子，我就没搜路径在哪？）。
+ **结论：** stdin、stdout和stderr都是FILE类型的文件指针，是由C库静态定义的，直接与文件描述符0、1和2相关联，所以应用程序可以直接使用它们。

### 2.2 I/O缓存引出的趣题
+ C库的I/O接口对文件I/O进行了封装，为提高性能，引入了 **缓存机制**
    + 全缓存：访问真正的磁盘文件。
    + 行缓存：访问终端。
    + 无缓存：引发实际的I/O操作。
+ [那一年， fork() 函数弄晕了多少Windows程序猿](http://blog.csdn.net/stpeace/article/details/38827671) 有点类似这个意思。
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    printf("Hello "); //无\n换行
    if (0 == fork())
    {
        printf("child\n");
        return 0;
    }
    printf("parent \n");
    return 0;
}
```
输出结果是： Hello parent 换行 Hello Child 或者 Hello Child 换行 hello Parent

### 2.3 fopen和open标志位对比
+ glibc源代码中`_IO_new_file_open()`我目前还没找到。
+ fopen的标志位是`r`，而open标志位是`O_RDONLY`

### 2.4 fdopen与fileno
+ Linux提供了文件描述符，而C库又提供了文件流。C库提供了两个API用于两者的切换 
    + `FILE *fdopen(int fd, const char *mode)`//从文件描述符fd生成一个文件流FILE。
    + `int fileno(FILE *stream)` // 从文件流FILE得到对应的文件描述符 
    + 

### 2.5 同时读写的痛若

### 2.6 ferror的返回值
+ 源码

### 2.7 clearerr的用途
+ 用于清除文件流的文件结束位和错误位

### 2.8 小心fgetc和getc

### 2.9 注意fread和fwrite的返回值

### 2.10 创建临时文件
+ `char *tmpnam(char *s)`

