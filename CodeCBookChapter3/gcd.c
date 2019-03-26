#include <stdio.h>
int gcd(int p, int q);

void main()
{
	int u,v,g;
	printf("Enter two numbers: ");
	scanf("%d %d",&u,&v);
	g=gcd(u,v);
	printf("Greatest Common Divisor of %d and %d is %d",u,v,g);
}

int gcd(int a, int b)
{
	int m;
	m=a%b;
	if(m==0)
		return(b);
	else
		gcd(b,m);
}
