#include <stdio.h>
#include <windows.h>
#include <process.h>   /* _beginthreadex, _endthreadex */
unsigned WINAPI ThreadFunc(void *arg);

int main(int argc, char* argv[])
{
	HANDLE hThread;
	unsigned threadID;
	int param = 5;

	hThread = (HANDLE)_beginthreadex(NULL,0,ThreadFunc,(void*)&param,0,&threadID);  // ��ThreadFunc��Ϊ�̵߳�main�ĺ����������䴫��param�ĵ�ֵַ
	if (hThread == 0)
	{
		puts("_beginthreadex() error");
		return -1;
	}
	Sleep(3000);  // Sleep������1/1000��Ϊ��λ��������״̬����ˣ�����3000ʱ���ȴ�3��
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