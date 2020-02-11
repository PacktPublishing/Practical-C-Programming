# include<stdio.h>
#include <math.h>
#define max 20
int main()
{
       int arr[max],k,e,len,i,j,digit,x,numbdig;
       int temp[10][max];
       printf("How many numbers to sort ? ");
       scanf("%d",&len);
       printf("How many number of digits in each numerical ? ");
       scanf("%d",&numbdig);
       printf("Enter %d values\n", len);
       for(i=0;i<len;i++)
		 scanf("%d",&arr[i]);
       for(i=0;i<10;i++)
       {
		for(j=0;j<max;j++)
		{
			temp[i][j]=-1;
		}
       }
       for(k=1;k<=numbdig;k++)
       {
		e=pow(10,k-1);
		for(i=0;i<len;i++)
		{
			 digit=(arr[i]/e)%10;
			 x=0;
			 while(temp[digit][x]!=-1)x++;
			 temp[digit][x]=arr[i];
		}
		x=0;

		for(i=0;i<10;i++)
		{
			for(j=0;j<max;j++)
			{
				if (temp[i][j]!=-1)
				{
					arr[x]=temp[i][j];
					x++;
				}
		       	}
	      	 }
		printf("\nThe output of pass %d  is \n",k);
		for(i=0;i<len;i++)printf("%d\t",arr[i]);
		printf("\n");
		for(i=0;i<10;i++)
		{
		       for(j=0;j<max;j++)
		       {
			temp[i][j]=-1;
		       }
	      	 }
       }
       return 0;
}
