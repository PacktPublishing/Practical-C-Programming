#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MSGSIZE     255

struct msgstruc { 
    long mtype; 
    char mesg[MSGSIZE]; 
}; 

int main()
{
    	int msqid, msglen;
    	key_t key;
	struct msgstruc msgbuf;
   	system("touch messagefile");
	if ((key = ftok("messagefile", 'a')) == -1) {
      		perror("ftok");
      		exit(1);
   	}  
  	if ((msqid = msgget(key, 0666 | IPC_CREAT)) == -1) {
      		perror("msgget");
      		exit(1);
   	} 
    	msgbuf.mtype = 1;
    	printf("Enter a message to add to message queue : ");
    	scanf("%s",msgbuf.mesg);
 	msglen = strlen(msgbuf.mesg);
 	if (msgsnd(msqid, &msgbuf, msglen, IPC_NOWAIT) < 0)
   		perror("msgsnd");
    	printf("The message sent is %s\n", msgbuf.mesg);
	return 0;
}