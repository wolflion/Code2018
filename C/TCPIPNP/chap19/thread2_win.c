#include <stdio.h>
#include <windows.h>
#include <process.h>   /* _beginthreadex, _endthreadex */
unsigned WINAPI ThreadFunc(void *arg);

int main(int argc, char* argv[])
{
	HANDLE hThread;
	DWORD wr;
	unsigned threadID;
	int param = 5;

	hThread = (HANDLE)_beginthreadex(NULL,0,ThreadFunc,(void*)&param,0,&threadID);  // 将ThreadFunc作为线程的main的函数，并向其传递param的地址值
	if (hThread == 0)
	{
		puts("_beginthreadex() error");
		return -1;
	}
	
	if ((wr == WaitForSingleObject(hThread,INFINITE)) == WAIT_FAILED)   // 调用WaitForSingleObject函数等待线程终止
	{
		puts("thread wait error");
		return -1;
	}

	printf("wait result: %s \n", (wr == WAIT_OBJECT_0) ? "signaled":"time-out");  // 利用WaitForSingleObject函数的返回值查看返回原因
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