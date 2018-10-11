#include <string>
#include <ctype.h>
#include <malloc.h>  // malloc等
#include <limits> // INT MAX等
#include <stdio.h> // EOF(=^Z或F6),NULL
#include <stdlib.h> // atoi()
#include <io.h> // eof()
#include <math.h> // floor(),ceil(),abs()
#include <process.h> // exit()
#include <iostream> // cout,cin

// 函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
//#define OVERFLOW 2  //math.h里已定义了OVERFLOW，并标为3
typedef int Status;   // Status是函数的类型，其值是函数结果状态代码，如OK
typedef int Boolean;  // Boolean是布尔类型，其值是TRUE或FALSE