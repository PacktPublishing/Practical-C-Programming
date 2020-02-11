#include <stdio.h>
#define max 10
int main()
{
	static int edg[max][max],i,j,v1,v2, numb;
	printf("How many vertices are there? ");
	scanf("%d",&numb);
	printf("We assume that the vertices are numbered from : ");
	for(i=1;i<=numb;i++) printf("%d   ", i);
	printf("\nEnter the edges of the graph. Like  1 4 if there is an \n");
	printf("edge between vertex 1 and 4. Enter 0 0 when over\n");
	for(i=1;i<=numb*(numb-1);i++)
	{
		/* The for loop will run for at most numb*(numb-1) times because, the number of edges are at most numb*(numb-1) where numb is the number of vertices */
		scanf("%d %d",&v1,&v2);
		if(v1==0 && v2==0)break;
		edg[v1][v2]=1;
		edg[v2][v1]=1;
	}
	printf("\nThe adjacency matrix for the graph is \n");
	for(i=1;i<=numb;i++) printf("\t%d", i);
	printf("\n----------------------------------------------------------\n");
	for(i=1;i<=numb;i++)
	{
		printf("%d |\t",i);
		for(j=1;j<=numb;j++)
		{
			printf("%d\t",edg[i][j]);
		}
		printf("\n");
	}
	return 0;
}
