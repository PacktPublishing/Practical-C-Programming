#include<stdio.h> 
#define max 100

int ifexists(int z[], int u, int v)
{
	int i;
	if (u==0) return 0;
		for (i=0; i<=u;i++)
			if (z[i]==v) return (1);
	return (0);
}


void main()
{
	int p[max], q[max], r[max];
	int m,n;
	int i,j,k;
	k=0;
	printf("Enter length of first array:"); 
	scanf("%d",&m); 
	printf("Enter %d elements of first array\n",m); 
	for(i=0;i<m;i++ )
		scanf("%d",&p[i]); 
	printf("\nEnter length of second array:"); 
	scanf("%d",&n); 
	printf("Enter %d elements of second array\n",n); 
	for(i=0;i<n;i++ )
		scanf("%d",&q[i]); 
	k=0;
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			if (p[i]==q[j])
			{
				if(!ifexists(r,k,p[i]))
				{
					r[k]=p[i];
					k++;
				}
			}
		}
	}
	if(k>0)
	{
	printf("\nThe common elements in the two array are:\n"); 

	for(i = 0;i<k;i++)
		printf("%d\n",r[i]); 
	}
	else
		printf("There are no common elements in two arrays\n");
}
