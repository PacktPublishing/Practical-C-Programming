#include<stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

void push(struct node *NewNode,struct node **Top);
struct node *pop(struct node **Top);

int main()
{
	struct node *newNode,*top, *recNode;
	int n=0;
	top=NULL;
	while(n!=3)
	{
		printf("\n1. Pushing an element into the stack\n");
		printf("2. Popping out an element from the stack\n");
		printf("3. Quit\n");
		printf("Enter your choice 1/2/3:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:	newNode=(struct node *)malloc(sizeof(struct node));
					printf("Enter the value to push: ");
					scanf("%d",&newNode->data);
					push(newNode,&top);
					printf("Value %d is pushed to stack\n", newNode->data);
					break;
		       case 2:	recNode=pop(&top);
					if(recNode==NULL)printf("Stack is empty\n");
			      		else
					      printf("The value popped is %d\n",recNode->data);
					break;
		}
	}
	return 0;
}

void push(struct node *NewNode,struct node **Top)
{
	NewNode->next=*Top;
	*Top=NewNode;
}

struct node *pop(struct node **Top)
{
	struct node * temp;
	if(*Top==NULL) return(NULL);
	else
	{
		temp=*Top;
		(*Top)=(*Top)->next;
		return(temp);
	}
}
