// 书中代码例子61/515
/* who02.c - read /etc/utmp and list info there in
 *            -- suppresses empty records
 *            -- formats time nicely
 */
#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

//#define SHOWHOST    //include remote machine on output
void showtime(long);
void show_info(struct utmp  *);

int main(int argc, char const *argv[])
{
    struct utmp utbuf;  // read info into here
    int utmpfd;    // read from this descriptor

    if((utmpfd = open(UMTP_FILE,O_RDONLY)) == -1){
        perror(UMTP_FILE);     // UTMP_FILE is in utmp.h
        exit(1);
    }

    while(read(utmpfd,&utbuf,sizeof(utbuf))  == sizeof(utbuf))
    {
        show_info(utmpfd);
    }
    close(utmpfd);
    return 0;     // went ok
}

/* 
 * show_info()
 * displays contents of the utmp struct 
 *        in human readable form
 *        *displays nothing if record has no user name
 */
show_info(struct utmp *utbufp)
{
    if(utbufp->ut_type != USER_PROCESS)
        return;
    printf("%-8.8s",utbufp->ut_name);  // the logname
    printf(" ");                        // a space
    printf("%-8.8s",utbufp->ut_line);  // the tty
    printf(" ");                       // a space
    printf("%10ld",utbufp->ut_time);  // login time
    printf(" ");                       // a space
    #ifdef SHOWHOST
    if(utbufp->ut_host[0] != '\0')
        printf("(%s)",utbufp->ut_host);  // the host
    #endif
    printf("\n");                      // newline
}


/*
 * displays time in a format fit for human consumption
 * uses ctime to build a string then picks parts out of it
 * Note: %12.12s prints a string 12 chars wide and LIMITS
 * it to 12chars.
 */
void showtime(long timeval)
{
    char *cp;  // to hold address of time
    cp = ctime(&time_val);  // convert time to string
    // string looks like Mon Feb 4 00:46:40 EST 1991 0123456789012345.
    printf("%12.12s",cp+4);  // pick 12 chars from pos 4
}