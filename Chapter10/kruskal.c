#include <stdlib.h>
#include <stdio.h>
#define max 20

struct node
{
	int nme;
	int wt;
	struct node *v;
	struct node *e;
};

typedef struct lst
{
	int u,v;
	int wt;
	struct lst *nxt;
}lst;

lst *pq=NULL;
lst *tr=NULL;
void addpqu(int a, int b, int w);
void maketree();
void disptree();
lst *delet();
int parent[max];

int main()
{
	int n,i,j,noe,w;
	int a,b;
	struct node *adj,*newNode,*p,*q;
	printf ("How many vertices are there ? ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)parent[i]=0;
	printf("The vertices are named\n");
	for(i=1;i<=n;i++)printf("%d\t",i);
	printf("for convenience \n");
	for(i=1;i<=n;i++)
	{
		if (i==1)
		{
			newNode =malloc(sizeof (struct node));
			newNode->nme=i;
			adj=newNode;
			p=newNode;
			newNode->v=NULL;
			newNode->e=NULL;
		}
		else
		{
			newNode=malloc(sizeof (struct node));
			newNode->nme=i;
			newNode->v=NULL;
			newNode->e=NULL;
			p->v=newNode;
			p=newNode;
		}
	}
	printf("Enter the edges between vertices. Enter 1 3, if there is an edge\n");
	printf("between 1 and 3. Enter 0 0 if over\n");
	noe=n*(n-1);
	for(j=1;j<=noe;j++)
	{
		printf("Enter edge: ");
		scanf("%d %d",&a,&b);
		if(a==0 && b==0)break;
		printf("Enter weight: ");
		scanf("%d",&w);
		p=adj;
		while(p!=NULL && p->nme!=a)
			p=p->v;
		if(p==NULL)
		{
			printf("Sorry no vertex exist by this name\n");
			break;
		}
		q=p;
		while(q->e!=NULL)q=q->e;
		newNode=malloc(sizeof (struct node));
		newNode->nme=b;
		newNode->wt=w;
		q->e=newNode;
		newNode->e=NULL;
		newNode->v=NULL;
		addpqu(a,b,w);
	}
	printf ("Adjacency List representation of Graph is\n");
	p=adj;
	while (p!=NULL)
	{
		printf ("%d\t",p->nme);
		q=p->e;
		while(q!=NULL)
		{
			printf("%d\t",q->nme);
			q=q->e;
		}
		printf("\n");
		p=p->v;
	}
	maketree();
	disptree();
	return 0;
}

void addpqu(int a, int b, int w)
{
	lst *newNode,*k,*h;
	newNode=(lst *)malloc(sizeof(lst));
	newNode->u=a;
	newNode->v=b;
	newNode->wt=w;
	newNode->nxt=NULL;
	if(pq==NULL)
		pq = newNode;
	else
	{
		if(newNode->wt < pq->wt)
		{
			newNode->nxt=pq;
			pq=newNode;
		}
		else
		{
			k=pq;
			while((k!=NULL) &&(k->wt <= newNode->wt))
			{
				h=k;
				k=k->nxt;
			}
			h->nxt=newNode;
			newNode->nxt=k;
		}
	}
}

lst *delet()
{
lst *q;
if (pq !=NULL)
{
	q=pq;
	pq=pq->nxt;
	return q;
}
else
	return NULL;
}

void maketree()
{
	lst *newNode,*p;
	int x,y,r1,r2;
	newNode=delet();
	while(newNode !=NULL)
	{
		newNode->nxt=NULL;
		x=newNode->u;
		y=newNode->v;
		while(x>0)
		{
			r1=x;
			x=parent[x];
		}
		while(y>0)
		{
			r2=y;
			y=parent[y];
		}
		if(r1 !=r2)
		{
			parent[r2]=r1;
			if (tr==NULL)
			{
				tr=newNode;
				p=tr;
			}
			else
			{
				p->nxt=newNode;
				p=newNode;
			}
		}
		newNode=delet();
	}
}

void disptree()
{
	lst *t;
	t=tr;
	printf("Minimal Spanning tree with Kruskal Algorithm is \n");
	while(t!=NULL)
	{
		printf("%d %d\n",t->u,t->v);
		t=t->nxt;
	}
}