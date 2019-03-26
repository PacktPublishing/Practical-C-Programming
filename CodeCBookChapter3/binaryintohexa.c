/* Converting binary to hexa */

# include <stdio.h>
#include  <math.h>

#define max 10

int top=-1;
int stack[max];

void push();
int pop();
char prnhexa(int);
int intodecimal(int);
void intohexa(int, int);

void main()
{
  	int b,d;
  	printf("Enter a number in binary number ");
  	scanf("%d",&b);
                  d=intodecimal(b);
   	printf("The decimal of binary number %d is %d\n", b, d);
	intohexa(b,d);
}

int intodecimal(int bin)
{
	int deci, remainder,exp,j;
  	while(bin >0)
  	{
     		remainder=bin%10;
     		push(remainder);
     		bin=bin/10;
  	}
    	deci=0;
  	exp=top;
  	while(top >=0)
  	{
     		j=pop();
     		deci=deci+j*pow(2,exp);
     		exp--;
   	}
	return (deci);
}

void intohexa(int bin, int deci)
{
	int remainder,j;
   	while(deci >0)
  	{
     		remainder=deci%16;
     		push(remainder);
     		deci=deci/16;
  	}
	printf("The hexa decimal format of binary number %d is ",bin);
  	while(top >=0)
  	{
     		j=pop();
		if(j<10)printf("%d",j);
		else printf("%c",prnhexa(j));
   	}
}

void push(int m)
{
  	top++;
  	stack[top]=m;
}

int pop()
{
  	int j;
  	if(top==-1)return(top);
	j=stack[top];
    	top--;
    	return(j);
}

char prnhexa(int v)
{
	switch(v)
	{
		case 10: return ('A');
			break;
		case 11: return ('B');
			break;
		case 12: return ('C');
			break;
		case 13: return ('D');
			break;
		case 14: return ('E');
			break;
		case 15: return ('F');
			break;
	}
}


