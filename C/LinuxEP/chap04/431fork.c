#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <wait.h>

int g_int = 1;   // 位于数据段的全局变量
int main()
{
    int local_int = 1;    // 位于栈的局部变量
    int *malloc_int = malloc(sizeof(int));   // 位于堆上malloc自动分配的变量

    *malloc_int = 1;
    pid_t pid = fork();

    if(pid == 0)  // 子进程
    {
        local_int = 0;
        g_int = 0;
        *malloc_int = 0;

        fprintf(stderr, "[CHILD ] child change local global malloc value to 0\n");
        free(malloc_int);

        sleep(10);
        fprintf(stderr,"[CHILD ] child exit\n");
        exit(0);
    }
    else if(pid < 0)  // 小于0,一般是出错了，大于0的时候，交给父进程处理
    {
        printf("fork failed (%s)",strerror(errno));
        return 1;
    }

    fprintf(stderr,"[PARENT] wait child exit\n");
    waitpid(pid,NULL,0);
    fprintf(stderr,"[PARENT] child have exit\n");

    printf("[PARENT] g_int = %d\n",g_int);    // printf()和fprintf()的区别？
    printf("[PARENT] local_int = %d\n",local_int);
    printf("[PARENT] malloc_int = %d\n",local_int);

    free(malloc_int);
    return 0;
}

/*
[PARENT] wait child exit
[CHILD ] child change local global malloc value to 0
[CHILD ] child exit
[PARENT] child have exit
[PARENT] g_int = 1
[PARENT] local_int = 1
[PARENT] malloc_int = 1
*/
