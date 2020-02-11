#include <stdio.h>
#include <assert.h>

float findaverage(int *Ptr, int Count);
int main()
{
	int arr[]={3,9,1,6,2};
	float average;
	int *ptr=NULL,count;

	ptr=arr;
	count=5;
	average=findaverage(ptr, count);
	printf("Average of values is %f\n", average);
	return(0);
}

float findaverage(int *Ptr, int Count)
{
	int sum,i;
	float Average;
    	assert(Ptr != NULL && "Pointer is not pointing to any array");
	sum=0;
	for(i=0;i<Count;i++)
	{
		sum+=*Ptr;
		Ptr++;
	}
	Average=(float)sum/Count;
	return(Average);
}
