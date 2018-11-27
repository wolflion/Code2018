#include <stdio.h>
#include <stdlib.h>

static void callback1(void)
{
	printf("callback1\n");
}

static void callback2(void)
{
	printf("callback2\n");
}

static void callback3(void)
{
	printf("callback3\n");
}

int main(void)
{
	atexit(callback1);
	atexit(callback2);
	atexit(callback3);

	printf("main exit\n");
	return 0;
}


// ��ע��ĺ��
/*
main exit
callback3
callback2
callback1
*/