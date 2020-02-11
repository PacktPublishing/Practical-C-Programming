#include <stdio.h> 
#include <pthread.h> 
#include<unistd.h> 
#include <stdlib.h>

#define max 10
pthread_mutex_t pop_mutex;
pthread_mutex_t push_mutex;
int stack[max];
int top=-1;

void * push(void *arg) {
	int n;
	pthread_mutex_lock(&push_mutex);
	pthread_mutex_lock(&pop_mutex);
	printf("Enter the value to push: ");
	scanf("%d",&n);
	top++;
	stack[top]=n;
	pthread_mutex_unlock(&pop_mutex);
	pthread_mutex_unlock(&push_mutex);
	printf("Value is pushed to stack \n");
}


void * pop(void *arg) {
	int k;
	pthread_mutex_lock(&pop_mutex);
	pthread_mutex_lock(&push_mutex);
	k=stack[top];
	top--;
	printf("Value popped is %d \n",k);
	pthread_mutex_unlock(&push_mutex);
	pthread_mutex_unlock(&pop_mutex);
}


int main() {
	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,&push,NULL);
	pthread_create(&tid2,NULL,&pop,NULL);
	printf("Both threads are created\n");
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	return 0;
}