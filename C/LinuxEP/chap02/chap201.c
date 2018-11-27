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
