#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define INFILE "./in.txt"
#define OUTFILE "./out.txt"
#define MODE S_IRUSR | S_IWUSR | S_IRGRP| S_IWGRP|S_IROTH

int main(void)
{
    int fd_in,fd_out;
    char buf[1024];

    memset(buf,0,1024);
    fd_in = open(INFILE, O_RDONLY);

    if(fd_in<0)
    {
        fprintf(stderr, "failed to open %s, reason(%s)\n",INFILE, strerror(errno));
        return 1;
    }

    fd_out = open(OUTFILE, O_WRONLY|O_CREAT|O_TRUNC,MODE);
    if(fd_out < 0)
    {
        fprintf(stderr, "failed to open %s, reason(%s)\n",OUTFILE, strerror(errno));
        return 1;
    }

    fork();  // �˴����Դ�����

    while(read(fd_in,buf,2) > 0)
    {
        printf("%d: %s",getpid(),buf);
        sprintf(buf,"%d Hello,World!\n",getpid());
        write(fd_out,buf,strlen(buf));
        sleep(1);
        memset(buf,0,1024);
    }
}

/*
������������������һ��
*/
