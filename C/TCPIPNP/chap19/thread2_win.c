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

	hThread = (HANDLE)_beginthreadex(NULL,0,ThreadFunc,(void*)&param,0,&threadID);  // ��ThreadFunc��Ϊ�̵߳�main�ĺ����������䴫��param�ĵ�ֵַ
	if (hThread == 0)
	{
		puts("_beginthreadex() error");
		return -1;
	}
	
	if ((wr == WaitForSingleObject(hThread,INFINITE)) == WAIT_FAILED)   // ����WaitForSingleObject�����ȴ��߳���ֹ
	{
		puts("thread wait error");
		return -1;
	}

	printf("wait result: %s \n", (wr == WAIT_OBJECT_0) ? "signaled":"time-out");  // ����WaitForSingleObject�����ķ���ֵ�鿴����ԭ��
	puts("end of main");
	return 0;
}

unsigned WINAPI ThreadFunc(void *arg)  // WINAPI��Windows���еĹؼ��֣�������ָ���������ݷ��򡢷����ջ���ط�ʽ�Ⱥ���������ع涨��
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