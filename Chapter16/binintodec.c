#include <stdio.h>
 
void main()
{
	int num,bin,temp,dec=0,topower=0;
     
    	printf("Enter the binary number: ");
    	scanf("%d",&bin);
	temp=bin;
    	while(bin >0)
	{
		num=bin %10;
		num=num<<topower;
		dec=dec+num;
		topower++;
		bin=bin/10;
	}     
    	printf("The decimal of %d is %d\n",temp,dec);
}