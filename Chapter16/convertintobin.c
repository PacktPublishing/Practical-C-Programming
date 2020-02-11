#include<stdio.h>
 
void main()
{
	int num,i,x,temp;;
	int p[10]; 
	printf("Enter Decimal Number : ");
	scanf("%d",&num);
	temp=num;
	x=0;
	while(num > 0)
   	{
   		if((num & 1) == 0 )
		{
			p[x]=0;
			x++;
		}
   		else
		{
			p[x]=1;
			x++;
		}
  		num = num >> 1;
   	}
	printf("Binary of %d is ",temp);
	for(i=x-1;i>=0;i--)printf("%d",p[i]);
}