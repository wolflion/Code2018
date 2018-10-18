#include <stdio.h>
#include <termios.h>

#define oops(s,x) {perror(s);exit(x);}

main(int ac, char* av[])
{
	struct termios ttyinfo;     // this struct holds tty info
	if(tcgetattr(0,&ttyinfo) == -1){  // get info
		perror("Cannot get params about stdin");
		exit(1);
	}
	// show info
	showbaud(cfgetospeed(&ttyinfo));  // get + show baud rate
	printf("The erase character is ascii %d,Ctrl-%c\n",
		ttyinfo.c_cc[VERASE],ttyinfo.c_cc[VERASE]-1+'A');
	printf("The line kill character is ascii %d,Ctrl-%c\n",
		ttyinfo.c_cc[VKILL],ttyinfo.c_cc[VKILL]-1+'A');
	show_some_flags(&ttyinfo);             // show misc. flags	
}

showbaud(int thespeed)
{
	printf("the baud rate is");
	switch(thespeed){
		case B300: printf("300\n");break;
		case B600: printf("600\n");break;
		case B1200: printf("1200\n");break;
		case B1800: printf("1800\n");break;
		case B2400: printf("2400\n");break;
		case B4800: printf("4800\n");break;
		case B9600: printf("9600\n");break;
		default:printf("Fast\n");break;
	}
}

struct flaginfo{int fl_value; char* fl_name;};

struct flaginfo input_flags[] = {
	IGNBRK, "Ignore break condition",
};

struct flaginfo local_flags[] = {
	ISIG, "Enable signals",
	};

show_some_flags(struct termios **ttyp)
{
	show_flagset(ttyp->c_iflag,input_flags);
	show_flagset(ttyp->c_lflag,local_flags);
}

show_flagset(int thevalue, struct flaginfo thebitnames[])
{
	int i;
	for(i=0;thebitnames[i].fl_value;i++){
		printf("%s is ", thebitnames[i].fl_name);
		if(thevalue & thebitnames[i].fl_value)
			printf("ON\n");
		else
			printf("OFF\n");
		}
}
