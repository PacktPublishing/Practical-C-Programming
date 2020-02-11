#include <stdlib.h>
#include <stdio.h>
#define max 20

struct node
{
	int nme;
	int wt;
	struct node *vrt;
	struct node *edg;
};
struct node *startList;

struct lst
{
	int u,v;
	int wt;
	struct lst *next;
}lst;

struct lst *pq=NULL;
struct lst *tr=NULL;
void addpqu(int a, int b, int w);
void maketree();
void disptree();
struct lst *delet();
int visited[max];
int n,nov=0;

int main()
{
	int i,j,noe,w;
	int a,b;
	struct node *newNode,*temp1,*temp2;
	printf ("How many vertices are there ?");
	scanf("%d",&n);
	printf("The vertices are named\n");
	for(i=1;i<=n;i++)printf("%d\t",i);
	printf("for convenience \n");
	startList=NULL;
	for(i=1;i<=n;i++)
	{
		if (startList==NULL)
		{
			newNode =malloc(sizeof (struct node));
			newNode->nme=i;
			startList=newNode;
			temp1=newNode;
			newNode->vrt=NULL;
			newNode->edg=NULL;
		}
		else
		{
			newNode=malloc(sizeof (struct node));
			newNode->nme=i;
			newNode->vrt=NULL;
			newNode->edg=NULL;
			temp1->vrt=newNode;
			temp1=newNode;
		}
	}
	printf("Enter the edges between vertices. Enter 1 3, if there is an edge\n");
	printf("between 1 and 3. Enter 0 0 if over\n");
	noe=n*(n-1);
	for(j=1;j<=noe;j++)
	{
		printf("Enter edge ");
		scanf("%d %d",&a,&b);
		if(a==0 && b==0)break;
		printf("Enter weight ");
		scanf("%d",&w);
		temp1=startList;
		while(temp1!=NULL && temp1->nme!=a)
		{
			temp1=temp1->vrt;
		}
		if(temp1==NULL)
		{
			printf("Sorry no vertex exist by this name\n");
			break;
		}
		temp2=temp1;
		while(temp2->edg!=NULL)temp2=temp2->edg;
		newNode=malloc(sizeof (struct node));
		newNode->nme=b;
		newNode->wt=w;
		temp2->edg=newNode;
		newNode->edg=NULL;
		newNode->vrt=NULL;
		temp1=startList;
		while(temp1!=NULL && temp1->nme!=b)
			temp1=temp1->vrt;
		if(temp1==NULL)
		{
			printf("Sorry no vertex exist by this name\n");
			break;
		}
		temp2=temp1;
		while(temp2->edg!=NULL)temp2=temp2->edg;
		newNode=malloc(sizeof (struct node));
		newNode->nme=a;
		newNode->wt=w;
		temp2->edg=newNode;
		newNode->edg=NULL;
		newNode->vrt=NULL;

	}
	printf ("Adjacency List representation of Graph is\n");
	temp1=startList;
	while (temp1!=NULL)
	{
		printf ("%d\t",temp1->nme);
		temp2=temp1->edg;
		while(temp2!=NULL)
		{
			printf("%d\t",temp2->nme);
			temp2=temp2->edg;
		}
		printf("\n");
		temp1=temp1->vrt;
	}
	temp1=startList;
        		temp2=temp1->edg;
		while(temp2!=NULL)
		{
			addpqu(temp1->nme,temp2->nme, temp2->wt);
			temp2=temp2->edg;
		}
	maketree();
	disptree();
	return 0;
}

void addpqu(int a, int b, int w)
{
	struct lst *lstNode,*findloc1,*findloc2;
	lstNode=malloc(sizeof(struct lst));
	lstNode->u=a;
	lstNode->v=b;
	lstNode->wt=w;
	lstNode->next=NULL;
	if(pq==NULL)
	{
		pq = lstNode;
	}
	else
	{
		if(lstNode->wt < pq->wt)
		{
			lstNode->next=pq;
			pq=lstNode;
		}
		else
		{
			findloc1=pq;
			while((findloc1!=NULL) && (findloc1->wt <= lstNode->wt))
			{
				findloc2=findloc1;
				findloc1=findloc1->next;
			}
			findloc2->next=lstNode;
			lstNode->next=findloc1;
		}
	}
}

struct lst *delet()
{
	struct lst *tempNode;
    	if (pq !=NULL)
    	{
		tempNode=pq;
		pq=pq->next;
		return tempNode;
    	}
	else
		return NULL;
}

void maketree()
{
	struct lst *lstNode,*tempNode1,*tempNode2;
	struct node *x,*y;
	int i,j;
	while(nov <n)
	{
nxt:		lstNode=delet();
		for(i=1;i<=nov;i++)
		{
			if(visited[i]==lstNode->u)
			{
				for(j=1;j<=nov;j++)
					if(visited[j]==lstNode->v) goto nxt;
			}
		}
		for(i=1;i<=nov;i++)
		     if(visited[i]==lstNode->u) goto rpt;
		nov++;
		visited[nov]=lstNode->u;
rpt:    		for(i=1;i<=nov;i++)
		{
		     if(visited[i]==lstNode->v) goto rptt;
		}
		nov++;
		visited[nov]=lstNode->v;
rptt:		lstNode->next=NULL;
		if (tr==NULL)
		{
			tr=lstNode;
			tempNode1=tr;
		}
		else
		{
			tempNode1->next=lstNode;
			tempNode1=lstNode;
		}
		x=startList;
		while(x->nme!=lstNode->v)x=x->vrt;
		y=x->edg;
		pq=NULL;
		while(y!=NULL)
		{
			addpqu(x->nme,y->nme, y->wt);
			y=y->edg;
		}
	}
}

void disptree()
{
	struct lst *t;
	t=tr;
	printf("Minimal Spanning tree with Prims Algorithm is \n");
	while(t!=NULL)
	{
		printf("%d %d\n",t->u,t->v);
		t=t->next;
	}
}