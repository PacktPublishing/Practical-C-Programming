#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#define MSGSIZE     255

struct msgstruc { 
    	long mtype; 
    	char mesg[MSGSIZE]; 
}; 


int main()
{
    	int msqid;
    	key_t key;
	struct msgstruc rcvbuffer;

	if ((key = ftok("messagefile", 'a')) == -1) {
      		perror("ftok");
      		exit(1);
   	}
    	if ((msqid = msgget(key, 0666)) < 0)
	{
      		perror("msgget");
      		exit(1);
	}
    	if (msgrcv(msqid, &rcvbuffer, MSGSIZE, 1, 0) < 0)
  	{
      		perror("msgrcv");
      		exit(1);
	}
    	printf("The message received is %s\n", rcvbuffer.mesg);
	return 0;
}