#include <string>
#include <ctype.h>
#include <malloc.h>  // malloc��
#include <limits> // INT MAX��
#include <stdio.h> // EOF(=^Z��F6),NULL
#include <stdlib.h> // atoi()
#include <io.h> // eof()
#include <math.h> // floor(),ceil(),abs()
#include <process.h> // exit()
#include <iostream> // cout,cin

// �������״̬����
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
//#define OVERFLOW 2  //math.h���Ѷ�����OVERFLOW������Ϊ3
typedef int Stutus;   // Status�Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��OK
typedef int Boolean;  // Boolean�ǲ������ͣ���ֵ��TRUE��FALSE