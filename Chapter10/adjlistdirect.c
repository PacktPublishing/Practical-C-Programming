#include <stdlib.h>
#include <stdio.h>

struct node
{
	char nme;
	struct node *vrt;
	struct node *edg;
};

int main()
{
	int numb,i,j,noe;
	char v1,v2;
	struct node *startList,*newNode,*temp1,*temp2;
	printf ("How many vertices are there ? ");
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
		}
		else
		{
			newNode=malloc(sizeof (struct node));
			scanf (" %c",&newNode->nme); 
			/* There is a space before %c */
			newNode->vrt=NULL;
			newNode->edg=NULL;
			temp1->vrt=newNode;
			temp1=newNode;
		}
	}
	printf("Enter the edges between vertices. Enter v1 v2, if there is an edge\n");
	printf("between v1 and v2. Enter 0 0 if over\n");
	noe=numb*(numb -1);
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
		while(temp2!=NULL)
		{
			printf("%c\t",temp2->nme);
			temp2=temp2->edg;
		}
		printf("\n");
		temp1=temp1->vrt;
	}
}