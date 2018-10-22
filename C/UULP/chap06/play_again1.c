/*play_again1.c
 * purpose: ask if user wants another transaction
 * method: set tty into char-by-char mode, read char, return result
 * returns: 0=>yes,1=>no
 * better: do no echo inappropriate input
 */
 
#include <stdio.h>
#include <termios.h>
 
#define QUESTION "Do you want another transaction"
int get_response(char *);
 
int main()
{
	int response;
	tty_mode(0);             // save tty mode
	set_crmode();            // set chr-by-chr mode
	response = get_response(QUESTION); // get some answer
	tty_mode(1);                 // restore tty mode
	return response;
}

int get_response(char* question)
{
	int input;
	printf("%s(y/n)?",question);
	while(1){
		switch(input = getchar()){
			case 'y':
			case 'Y': return 0;
			case 'n':
			case 'N':
			case EOF: return 1;
			default:
				printf("\ncannot understand %c, ",input);
				printf("Please type y or no \n");
		}
	}
}

set_crmode()
{
	struct termios ttystate;
	tcgetattr(0,&ttystate);   // read curr.setting
	ttystate.c_lflag  &= ~ICANON; // no buffering
	ttystate.c_cc[WMIN]   = 1;  // get 1 char at a time
	tcsetattr(0,TCSANOW,&ttystate);  // install settings
}

tty_mode(int how)
{
	static struct termios original_mode;
	if(how == 0)
		tcgetattr(0,&original_mode);
	else
		return tcsetattr(0,TCSANOW,&original_mode);
}
