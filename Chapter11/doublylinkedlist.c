#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
  int data;
  struct node *next, *prev;
};

struct node *startList, *endList;
void createdoubly();
void list_lifo();
void list_fifo();

int main()
{


	int n=0;
	while(n!=4)
	{
	       printf("\n1. Creating a doubly linked list\n");
	       printf("2. Displaying elements in L.I.F.O. order\n");
	       printf("3. Displaying elements in F.I.F.O. order\n");
	       printf("4. Quit\n");
	       printf("Enter your choice 1/2/3/4: ");
	       scanf("%d",&n);
	       switch(n)
	       {
		    case 1:	createdoubly();
				break;
		    case 2:	list_lifo();
				break;
		    case 3:	list_fifo();
			break;

		 }
	}
	return 0;
}

void createdoubly()
{
	char k[10];
	struct node *newNode;
	startList=NULL;
	strcpy(k,"yes");
	while(strcmp(k,"yes")==0 || strcmp(k, "Yes")==0)
	{
    		if(startList==NULL)
    		{
			newNode=(struct node *)malloc(sizeof(struct node));
			printf("Enter the value to add: ");
			scanf("%d",&newNode->data);
			newNode->next=NULL;
			newNode->prev=NULL;
			startList = newNode;
			endList=startList;
		}
		else
		{
			newNode=(struct node *)malloc(sizeof(struct node));
			printf("Enter the value to add: ");
			scanf("%d",&newNode->data);
			newNode->next=NULL;
			newNode->prev=endList;
			endList->next = newNode;
			endList=newNode;
		}
		printf("Want to add more yes/no? ");
		scanf("%s",k);
	}
	printf("Doubly linked list is created\n");
}

void list_lifo()
{
	struct node *temp;
	temp=endList;
	if(temp !=NULL)
	{
		printf("The elements of the doubly linked list in L.I.F.O. order :\n");
		while(temp!=NULL)
		{
		printf("%d\n",temp->data);
		temp=temp->prev;
		}
	}
	else
		printf("The doubly linked list is empty\n");
}

void list_fifo()
{
	struct node *temp;
	temp=startList;
	printf("The elements of the doubly linked list in F.I.F.O. order: \n");
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}

