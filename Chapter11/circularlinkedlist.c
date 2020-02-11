#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *startList=NULL;

void addlist(struct node **h);
void disp();

int main()
{
	struct node *newNode;
	int n=0,i,k;
	while(n!=3)
       	{
		printf("\n1. Adding elements to the circular linked list\n");
		printf("2. Displaying elements of the circular linked list\n");
		printf("3. Quit\n");
		printf("Enter your choice 1/2/3: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:	printf("How many values are there ");
					scanf("%d",&k);
					printf("Enter %d values\n",k);
					for(i=1;i<=k;i++)
					{
						newNode=(struct node *)malloc(sizeof(struct node));
						scanf("%d",&newNode->data);
						addlist(&newNode);
					}
					printf("Values added in Circular Linked List \n");
					break;
		       case 2:  	disp();
					break;
		}
	}
	return 0;
}

void addlist(struct node **NewNode)
{
	struct node *temp;
	if(startList==NULL)
	{
		startList=*NewNode;
		startList->next=startList;
	}
	else
	{       
		temp=startList;
		while(temp->next !=startList)
			temp=temp->next;
		temp->next=*NewNode;
		temp=*NewNode;
		temp->next=startList;
	}
}

void disp()
{
	struct node *temp;
	if (startList==NULL)
		printf("The circular linked list is empty\n");
	else
	{
		printf("Following are the elements in circular linked list:\n");
		printf("%d\n",startList->data);
		temp=startList->next;
		while(temp !=startList)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
}
