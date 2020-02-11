/* Converting Decimal to Binary using masking */

#include <stdio.h>
void main()
{
	int i, totbits;
	unsigned mask,num; 

	printf("Enter decimal value: ");
	scanf("%d", &num); 
	totbits=32;
	mask = 1 << (totbits - 1); 
	for(i = 0; i < totbits; i++) 
	{
		if((num & mask) == 0 )
			printf("0");
   		else
			printf("1");
		mask >>= 1; 
	}
}
