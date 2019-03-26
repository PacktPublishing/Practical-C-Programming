#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
#include <stdlib.h>
  
int main() 
{ 
	int shmid;
	char * str;
    
	key_t key = ftok("sharedmem",'a'); 
      	if ((shmid = shmget(key, 1024,0666|IPC_CREAT)) < 0) {
        		perror("shmget");
        		exit(1);
    	}
      	if ((str = shmat(shmid, NULL, 0)) == (char *) -1) {
        		perror("shmat");
        		exit(1);
    	} 
    	printf("Data read from memory: %s\n",str); 
          	shmdt(str); 
    	shmctl(shmid,IPC_RMID,NULL); 
	return 0;
} 