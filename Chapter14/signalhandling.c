#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sighandler1(int signum) {
   	printf("Ctrl + C is auto pressed \n");
}

void sighandler2(int signum) {
   	printf("You have pressed Ctrl+c\n");
	printf("Press Ctrl+c again to exit\n");
	(void) signal(SIGINT, SIG_DFL);
}

int main () {
	int x=1;
   	signal(SIGINT, sighandler1);
   	while(x<=5) {
      		printf("Signal will be raised automatically after 5 seconds\n");
		x++;
      		sleep(1); 
   	}
  	raise(SIGINT);
   	signal(SIGINT, sighandler2);
   	while(1) {
      		printf("Infinite loop, press Ctrl+C to raise signal\n");
      		sleep(1); 
   	}
   	return(0);
}

