#include <stdlib.h>
#include <stdio.h>

#define max 20

enum Setmarked{Y,N};
struct node
{
	char nme;
	struct node *vrt;
	struct node *edg;
	enum Setmarked marked;
};

struct node *que[max];
int rear=-1,front=-1;
void queue(struct node *paramNode);
struct node *dequeue();

int main()
{
	int numb,i,j,noe;
	char v1,v2;
	struct node *startList,*newNode,*temp1,*temp2, *temp3;
	printf ("How many vertices are there ?");
	scanf("%d",&numb);
	startList=NULL;
	printf("Enter all vertices names\n");
	for(i=1;i<=numb;i++)
	{
		if (startList==NULL)
		{
			newNode =malloc(sizeof (struct node));
			scanf (" %c",&newNode->nme);
			/* There is a space before %c */
			startList=newNode;
			temp1=newNode;
			newNode->vrt=NULL;
			newNode->edg=NULL;
			newNode->marked=N;
		}
		else
		{
			newNode=malloc(sizeof (struct node));
			scanf (" %c",&newNode->nme);
			/* There is a space before %c */
			newNode->vrt=NULL;
			newNode->edg=NULL;
			newNode->marked=N;
			temp1->vrt=newNode;
			temp1=newNode;
		}
	}
	printf("Enter the edges between vertices. Enter v1 v2, if there is an edge\n");
	printf("between v1 and v2. Enter 0 0 if over\n");
	noe=numb*(numb-1);
	for(j=1;j<=noe;j++)
	{
		scanf(" %c %c",&v1,&v2);
		/* There is a space before %c */
		if(v1=='0' && v2=='0')break;
		temp1=startList;
		while(temp1!=NULL && temp1->nme!=v1)
			temp1=temp1->vrt;
		if(temp1==NULL)
		{
			printf("Sorry no vertex exist by this name\n");
			break;
		}
		temp2=temp1;
		while(temp2->edg!=NULL)temp2=temp2->edg;
		newNode=malloc(sizeof (struct node));
		newNode->nme=v2;
		temp2->edg=newNode;
		newNode->edg=NULL;
		newNode->vrt=NULL;
	}
	printf ("\nAdjacency List representation of Graph is\n");
	temp1=startList;
	while (temp1!=NULL)
	{
		printf ("%c\t",temp1->nme);
		temp2=temp1->edg;
		while(temp2 !=NULL)
		{
			printf("%c\t",temp2->nme);
			temp2=temp2->edg;
		}
		printf("\n");
		temp1=temp1->vrt;
	}
	printf("\nBreadth First traversal of the graph is \n");
	temp1=startList;
	if(temp1==NULL)
		printf("Sorry no vertices in the graph\n");
	else
		queue(temp1);
	while(rear !=-1)
	{
		temp3=dequeue();
		temp1=startList;
		while(temp1->nme !=temp3->nme)temp1=temp1->vrt;
		temp3=temp1;
		if(temp3->marked==N)
		{
			printf("%c\t",temp3->nme);
			temp3->marked=Y;
			temp2=temp3->edg;
			while(temp2!=NULL)
			{
				queue(temp2);
				temp2=temp2->edg;
			}
		}
	}
	return 0;
}

void queue(struct node *paramNode)
{
	rear++;
	que[rear]=paramNode;
	if(front==-1)front=0;
}

struct node *dequeue()
{
	struct node *tempNode;
	if(front==rear)
	{
		tempNode=que[front];
		front=-1;
		rear=-1;
	}
	else
	{
		tempNode=que[front];
		front++;
	}
return(tempNode);
}



