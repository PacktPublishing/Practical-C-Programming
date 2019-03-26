#include<pthread.h>
#include<stdio.h>

void *runThread1(void *arg){
	int i;
    	printf("Running Thread 1\n"); 
	for(i=1;i<=5;i++)
		printf("Thread 1 - %d\n",i);
}

void *runThread2(void *arg){
	int i;
    	printf("Running Thread 2\n"); 
	for(i=1;i<=5;i++)
		printf("Thread 2 - %d\n",i);
}

int main(){
	pthread_t tid1, tid2;
	pthread_create(&tid1,NULL,runThread1,NULL);
	pthread_create(&tid2,NULL,runThread2,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
    	printf("Both threads are over\n"); 
	return 0;
}

