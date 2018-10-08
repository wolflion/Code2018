#include <stdio.h>
#include <unistd.h>
#define BUF_SIZE 30

int main(int argc, char *argv[])
{
	int fds1[2],fds2[2];
	char str1[] = "Who are you?";
	char str2[] = "Thank you for your message";
	char buf[BUF_SIZE];
	pid_t pid;
	
	pipe(fds1),pipe(fds2);    // 创建两个管道
	pid = fork();
	if(pid == 0)
	{
		write(fds[1],str1,sizeof(str1));
		read(fds2[0],buf,BUF_SIZE);
		printf("Child proc output: %s \n", buf);
	}
	else
	{
		read(fds1[0],buf,BUF_SIZE);     //  line17,23行， 子进程可以通过数组fds1指向的管道向父进程传输数据。
		printf("Parent proc output: %s \n", buf);
		write(fds2[1], str2, sizeof(str2));  //  line18,25行， 父进程可以通过数组fds2指向的管道向子进程传输数据。
		sleep(3);    // 没有太大的意义，只是为了延迟父进程终止而插入的代码
	}
	return 0;
}

// gcc pipe3.c -o pipe3
