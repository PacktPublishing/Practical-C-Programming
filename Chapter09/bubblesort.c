# include <stdio.h>
#define max 20

int main()
{
	int arr[max],temp,len,i,j;
	printf("How many values are there? ");
	scanf("%d",&len);
	printf("Enter %d values to sort\n",len);
	for(i=0;i<len;i++)
		scanf("%d",&arr[i]);
	for(i=len-2;i>=1;i--)
	{
		for(j=0;j<=i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("The sorted array is:\n");
	for(i=0;i<len;i++)
		printf("%d\n",arr[i]);
	return 0;
}