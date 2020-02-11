#include <stdio.h>
#define max 20

int binary_search(int[], int, int);

int main()
{
	int len,found,numb,arr[max],i;
	printf("Enter the length of an array: ");
	scanf("%d",&len);
	printf("Enter %d values in sorted order \n", len);
	for(i=0;i< len;i++)
		scanf("%d",&arr[i]);
	printf("Enter the value to search ");
	scanf("%d",&numb);
	found=binary_search(arr,numb,len);
	if(found==numb)
		printf("Value %d is found in the list\n",numb);
	else
		printf("Value %d is not found in the list \n", numb);
	return 0;
}

int binary_search(int arr[], int pnumb,int plen)
{
	int lindex=0,mid,uindex=plen, nfound;
	while(uindex >=lindex)
	{
		mid=(uindex+lindex)/2;
		if(pnumb==arr[mid])
		{
			nfound=arr[mid];
			break;
		}
		else
		{
			if(pnumb>arr[mid])
				lindex=mid+1;
			else
				uindex=mid-1;
		}
	}
	return(nfound);
}
