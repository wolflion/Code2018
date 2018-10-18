#include <stdio.h>
#include <termios.h>
main()
{
	struct termios info;
	int rv;
	
	rv = tcgetattr(0,&info);   // read values from driver
	if(rv == -1){
		perror("tcgetattr");
		exit(1);
	}
	if(info.c_lflag &ECHO)
		printf("echo is on, since its bits is 1\n");
	else
		printf("echo is OFF, since its bits is 0\n");
}
