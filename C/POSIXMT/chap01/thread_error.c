#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>  // 原书中没写这行

int main(int argc, char* argv[])
{
	pthread_t thread;
	int status;
	
	status = pthread_join(thread,NULL);
	if(status != 0)
		fprintf(stderr,"error %d: %s\n",status,strerror(status));
	return status;
}

// 看了这个示例，才琢磨明白的。 【strerror -- 识别错误代码，返回描述的字符串】  https://blog.csdn.net/CPU1994GHz/article/details/78685431

// [pthread_join函数介绍和使用实例] https://blog.csdn.net/qq_37858386/article/details/78185064  


// gcc thread_error.c -pthread
