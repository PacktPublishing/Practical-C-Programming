#include <stdio.h>
#define max 20

void merge(int arr[], int fsi, int fei, int ssi, int sei);
void mergesort(int arr[],int si, int ei);

int main()
{
	int arr[max];
	int si,i,len;
	si=0;
	printf("How many numerical to sort? ");
	scanf("%d",&len);
	printf("Enter %d numericals:\n", len);
	for(i=0;i<=len-1;i++)
		scanf("%d",&arr[i]);
	printf("\nOriginal array is \n");
	for(i=0;i<len;i++)
	printf("%d\t",arr[i]);
	printf("\n");
	mergesort(arr,si,len-1);
	printf("\nSorted array is \n");
	for(i=0;i<len;i++)
	printf("%d\t",arr[i]);
	return 0;
}

void mergesort(int arr[],int si, int ei)
{
	int mid;
	if(ei>si)
	{
		mid=(si+ei)/2;
		mergesort(arr,si,mid);
		mergesort(arr,mid+1,ei);
		merge(arr,si,mid,mid+1,ei);
	}
}

void merge(int arr[], int fsi, int fei, int ssi, int sei)
{
	int mgd[max],x,fh,sh,i;
	fh=fsi;
	sh=ssi;
	x=0;
	while(fh<=fei && sh <=sei)
	{
		if(arr[fh]<arr[sh])
		{
			mgd[x]=arr[fh];
			x++;
			fh++;
		}
		else
		{
			mgd[x]=arr[sh];
			x++;
			sh++;
		}
	}
	while(fh<=fei)
	{
		mgd[x]=arr[fh];
		x++;
		fh++;
	}
	while(sh<=sei)
	{
		mgd[x]=arr[sh];
		x++;
		sh++;
	}
	x=0;
	for(i=fsi;i<=fei;i++)
	{
		arr[i]=mgd[x];
		x++;
	}
	for(i=ssi;i<=sei;i++)
	{
		arr[i]=mgd[x];
		x++;
	}
}