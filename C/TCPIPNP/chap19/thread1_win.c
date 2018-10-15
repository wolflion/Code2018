#include <stdio.h>
#include <windows.h>
#include <process.h>   /* _beginthreadex, _endthreadex */
unsigned WINAPI ThreadFunc(void *arg);

int main(int argc, char* argv[])
{
	HANDLE hThread;
	unsigned threadID;
	int param = 5;

	hThread = (HANDLE)_beginthreadex(NULL,0,ThreadFunc,(void*)&param,0,&threadID);  // 将ThreadFunc作为线程的main的函数，并向其传递param的地址值
	if (hThread == 0)
	{
		puts("_beginthreadex() error");
		return -1;
	}
	Sleep(3000);  // Sleep函数以1/1000秒为单位进入阻塞状态，因此，传入3000时将等待3秒
	puts("end of main");
	return 0;
}

unsigned WINAPI ThreadFunc(void *arg)  // WINAPI是Windows固有的关键字，它用于指定参数传递方向、分配的栈返回方式等函数调用相关规定。
{
	int i;
	int cnt = *((int*)arg);
	for (i=0;i<cnt;i++)
	{
		Sleep(1000);
		puts("running thread");
	}
	return 0;
}