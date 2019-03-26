#include <stdio.h>

void main()
{
	char str[255], *ptr1, *ptr2, temp ;
	int n,m;
	printf("Enter a string: ");
	scanf("%s", str);
	ptr1=str;
	n=1;
	while(*ptr1 !='\0')
	{
		ptr1++;
		n++;
	}
	ptr1--;
	ptr2=str;
	m=1;
	while(m<=n/2)
	{
		temp=*ptr1;
		*ptr1=*ptr2;
		*ptr2=temp;
		ptr1--;
		ptr2++;;
		m++;
	}
	printf("Reverse string is %s", str);
}