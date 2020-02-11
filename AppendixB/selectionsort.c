# include<stdio.h>
#define max 20

int main()
{
	int arr[max],i,j,value,len,index,temp;
	printf("How many numbers to sort? ");
	scanf("%d",&len);
	printf("Enter %d values:\n",len);
	for(i=0;i<len;i++)
		scanf("%d",&arr[i]);
	for(i=0;i< len-1;i++)
	{
		value=arr[i];
		index=i;
		for(j=i+1;j<len;j++)
		{
			if(value>arr[j])
			{
				value=arr[j];
				index=j;
			}
		}
		temp=arr[i];
		arr[i]=arr[index];
		arr[index]=temp;
	}
	printf("\nThe ascending order of the element entered is:\n");
	for(i=0;i<len;i++)
		printf("%d\n",arr[i]);
	return 0;
}