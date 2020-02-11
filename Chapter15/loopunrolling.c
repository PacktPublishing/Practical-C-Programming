#include <stdio.h> 
  
int main() { 
	int sum,i,limit,rem,quot,incr,x, count;
  	sum = 0; 
	printf("Enter limit ");
	scanf("%d", &limit);
	for(i=9;i>=1;i--)
	{
		rem=limit % i;
		if (rem==0) break;
	}
	incr=i;
	count=0;
	for(i=1;i<=limit; i+=incr)
	{
		x=0;
		while(x<incr)
		{
			sum += i+x;
			x++;
		}
	count++;
	}
	printf("The sum of first %d sequence numbers is %d\n",limit, sum);
	printf("The loop executed for %d number of times\n",count);
	return 0;
 } 