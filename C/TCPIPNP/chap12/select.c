#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/select.h>
#define BUF_SIZE 30

int main(int argc, char *argv[])
{
	fd_set reads,temps;
	int result,str_len;
	char buf[BUF_SIZE];
	struct timeval timeout;
	
	FD_ZERO(&reads);        // 初始化fd_set变量
	FD_SET(0,&reads);   // 0 is standard input(console)   将文件描述符0对应的位设置为1。即，需要监视标准输入的变化
	
	/*
	timeout.tv_sec = 5;
	timeout.tv_usec = 5000;
	*/
	
	while(1)
	{
		temps = reads;  // 将准备好的fd_set变量reads内容复制到temps变量   **调用select后，除发生变化的文件描述符对应位外，剩下的所有位将初始化为0**。
		timeout.tv_sec = 5;
		timeout.tv_usec = 0;
		result = select(1, &temps,0,0,&timeout);
		if(result == -1)
		{
			puts("select() error!");
			break;
		}
		else if(result == 0)
		{
			puts("Time-out!");
		}
		else
		{
			if(FD_ISSET(0,&temps))
			{
				str_len = read(0,buf,BUF_SIZE);
				buf[str_len] = 0;
				printf("message from console: %s", buf);
			}
		}
	}
	return 0;
}
