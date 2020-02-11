#include <stdio.h>
#define max 5

int dq[max];


void addInFront(int *Front,int *r,int h);
void addInRear(int *Front,int *r,int h);
int delFFront(int *Front,int *Rear);
int delFRear(int *Front,int *Rear);
int isDQueueEmpty(int *Front);
int isDQueueFull(int *Front, int *Rear);


int main()
{
	int rear,front,n=0,fromdq,val;
	rear=-1;
	front=-1;

	while(n !=5)
	{
		printf("\n1. Adding element in front into the dequeue\n");
		printf("2. Adding element at rear into the dequeue\n");
		printf("3. Deleting an element from the front in dequeue\n");
		printf("4. Deleting an element from the rear in dequeue\n");
		printf("5. Quit\n");
		printf("Enter your choice 1/2/3/4/5: ");
		scanf("%d",&n);


		switch(n)
		{
			case 1:	printf("Enter the value to be added to the front in dequeue: ");
				scanf("%d",&val);
				addInFront(&front,&rear,val);
				break;
			case 2:	printf("Enter the value to be added at the rear in dequeue: ");
				scanf("%d",&val);
				addInRear(&front,&rear,val);
				break;
			case 3:	if(!isDQueueEmpty(&front))
				{
					fromdq=delFFront(&front,&rear);
					printf("The value removed from the front in dequeue is %d\n",fromdq);
				}
				else
					printf("The dequeue is empty\n");
				break;
			case 4:	if(!isDQueueEmpty(&front))
				{
					fromdq=delFRear(&front,&rear);
					printf("The value removed from the rear in dequeue is %d\n",fromdq);
				}
				else
					printf("The dequeue is empty\n");
				break;
		} 
	} 
	return 0;
}


int isDQueueEmpty(int *Front)
{
	if(*Front==-1)
		return (1);
	else
		return (0);
}

int isDQueueFull(int *Front, int *Rear)
{
	if((*Front==0) && (*Rear==max-1))
		return (1);
	if(*Front==(*Rear+1))
		return (1);
	return (0);
}


void addInRear(int *Front,int *Rear, int Val)
{
	int oldR;
	if(*Rear ==max-1)
	{
		oldR=*Rear;
		*Rear=(*Rear+1)%5;
		if(*Rear < *Front)
		{
			dq[*Rear]=Val;
			printf("Value %d is added in dequeue\n", Val);
		}
		else
		{
			*Rear=oldR;
			printf("Sorry the dequeue is full\n ");
		}
	}
	else
	{
		(*Rear)++;
		if(*Rear !=*Front)
		{
			dq[*Rear]=Val;
			printf("Value %d is added in dequeue\n",Val);
		}
		else
		{
			(*Rear)--;
			printf("Sorry, the dequeue is full\n");
		}
	}
	if(*Front==-1)
		*Front=*Rear;
}


void addInFront(int *Front,int *Rear,int Val)
{
	if (*Front == -1) 
    	{ 
        		*Front = 0; 
        		*Rear = 0; 
    	} 
	else
	{
		if (*Front ==0)
			*Front=max-1;
		else
			*Front=(*Front) -1;
	}
	dq[*Front]=Val;
}

int delFFront(int *Front,int *Rear)
{
	int val=0;
	if(*Front==*Rear)
	{
		val=dq[*Front];
		*Front=*Rear=-1;
	}
	else
	{
		if(*Front >=max)
		{
			*Front=*Front%5;
			if (*Front<*Rear)
			{
				val=dq[*Front];
				(*Front)++;
			}
			else
			{
				if(*Front==*Rear)
				{
					val=dq[*Front];
					*Front=*Rear=-1;
				}
			}
		}
		else
		{
			val=dq[*Front];
			(*Front)++;
		}
	}
	return(val);
}

int delFRear(int *Front,int *Rear)
{
	int val=0;
	if(*Front==*Rear)
	{
		val=dq[*Front];
		*Front=*Rear=-1;
	}
    	else
	{
 		if (*Rear == 0) 
		{
			val=dq[*Rear];
			*Rear=max-1;
		}
    		else
		{
			val=dq[*Rear];
        			*Rear = *Rear-1; 
		}
	}
	return(val);
}


