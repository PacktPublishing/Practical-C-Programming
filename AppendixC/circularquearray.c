# include<stdio.h>
#define max 5
int cque[max];

void addq(int *Front,int *r,int h);
int delq(int *Front,int *Rear);
int isQueueEmpty(int *Front);

int main()
{
	int rear,front,n=0,fromq,val;
	rear=front=-1;
	while(n!=3)
	{
		printf("\n1. Adding an element into the circular queue\n");
		printf("2. Deleting an element from the circular queue\n");
		printf("3. Quit\n");
		printf("Enter your choice 1/2/3: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:	printf("Enter the value to add to the circular queue: ");
				scanf("%d",&val);
				addq(&front,&rear,val);
				break;
			case 2:	if(!isQueueEmpty(&front))
				{
					fromq=delq(&front,&rear);
					printf("The value removed from the circular queue is %d\n",fromq);
				}
				else
					printf("The circular queue is empty\n");
				break;
		}
	}
	return 0;
}

void addq(int *Front,int *Rear,int Val)
{
	int oldR;
	if(*Rear >=max-1)
	{
		oldR=*Rear;
		*Rear=(*Rear+1)%5;
		if(*Rear<*Front)
		{
			cque[*Rear]=Val;
			printf("Value %d is added in circular queue\n", Val);
		}
		else
		{
			*Rear=oldR;
			printf("Sorry the circular queue is full\n ");
		}
	}
	else
	{
		(*Rear)++;
		if(*Rear !=*Front)
		{
			cque[*Rear]=Val;
			printf("Value %d is added in circular queue\n",Val);
		}
		else
		{
			(*Rear)--;
			printf("Sorry, the circular queue is full\n");
		}
	}
	if(*Front==-1)
		*Front=*Rear;
}

int isQueueEmpty(int *Front)
{
	if(*Front==-1)
		return (1);
	else
		return (0);
}

int delq(int *Front,int *Rear)
{
	int val=0;
	if(*Front==*Rear)
	{
		val=cque[*Front];
		*Front=*Rear=-1;
	}
	else
	{
		if(*Front >=max)
		{
			*Front=*Front%5;
			if (*Front<*Rear)
			{
				val=cque[*Front];
				(*Front)++;
			}
			else
			{
				if(*Front==*Rear)
				{
					val=cque[*Front];
					*Front=*Rear=-1;
				}
			}
		}
		else
		{
			val=cque[*Front];
			(*Front)++;
		}
	}
	return(val);
}