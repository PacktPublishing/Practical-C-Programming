#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
  

void *runThread(void *arg) 
{ 
	int i;
    	printf("Running Thread \n"); 
	for(i=1;i<=5;i++) printf("%d\n",i);
    	return NULL; 
} 
   
int main() 
{ 
    	pthread_t tid; 
    	printf("In main function\n"); 
    	pthread_create(&tid, NULL, runThread, NULL); 
    	pthread_join(tid, NULL); 
    	printf("Thread over\n"); 
	return 0;
}