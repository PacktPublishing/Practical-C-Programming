#include <stdio.h>
#define max 5
int front=-1,rear=-1;

void addq(int Que[], int Val);
int delq(int Que[]);
int IsQueueEmpty();

int main()
{
       int que[max];
       int val,n=0;
       while(n!=3)
       {
		printf("\n1. Adding an element into the queue\n");
		printf("2. Deleting an element from the queue\n");
		printf("3. Quit\n");
		printf("Enter your choice 1/2/3: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:	if(rear >=max-1)
						printf("Sorry the queue is full\n");
					else
					{
						printf("Enter the value to add to queue: ");
						scanf("%d",&val);
						addq(que,val);
						printf("Value %d is added to queue\n", val);
					}
					break;
			case 2:  	if(!IsQueueEmpty())
				{

					val=delq(que);
						printf("Value removed from queue %d\n",val);
				}
				else
				printf("Sorry, the queue is empty\n");
				 	break;
		}
	}
	return 0;
}

void addq(int Que[], int Val)
{
	rear++;
	Que[rear]=Val;
	if(front==-1)
		front=rear;
}

int IsQueueEmpty()
{
	if(front==-1)
			return (1);
	else
		return (0);


}

int delq(int Que[])
{
	int val;
		if(front==rear)
		{
			val=Que[front];
			front=-1;
			rear=-1;
		}
		else
		{
			val=Que[front];
			front++;
		}
		return(val);
}
