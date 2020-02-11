#include <stdio.h>

#define max 20

int main()
{
	int len,i,arr[max],incr,j,temp;

	printf("How many values to be sorted ?");
	scanf("%d",&len);
	printf("Enter %d values\n", len);
	for(i=0;i<len;i++)
		scanf("%d",&arr[i]);
	printf("\nOriginal array is\n");
	for(i=0;i<len;i++)
		printf("%d\t",arr[i]);
	printf("\n");
	incr=5;
	while(incr >=1)
	{
		for(i=0;i<len-incr;i++)
		{
			for(j=i+incr;j<len;j+=incr)
			{
				if(arr[i]>arr[j])
				{
					temp=arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
				}
			}
		}
		printf("\nThe array when increment is %d\n",incr);
		for(i=0;i<len;i++)
			printf("%d\t",arr[i]);
		printf("\n");
		incr=incr-2;
	}
	return 0;
}
