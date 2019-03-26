/* Finding whether the entered number is an armstrong number or not */

# include <stdio.h>
# include <math.h>

#define max 10

int top=-1;
int stack[max];

void push(int);
int pop();
int findarmstrong(int );

void main()
{
  	int n;
  	printf("Enter a number ");
  	scanf("%d",&n);
	if (findarmstrong(n))
		printf("%d is an armstrong number",n);
	else printf("%d is not an armstrong number", n); 
}
  
int findarmstrong(int numb)
{
  	int j, remainder, temp,count,value;
	temp=numb;
	count=0;
  	while(numb >0)
  	{
     		remainder=numb%10;
     		push(remainder);
		count++;
     		numb=numb/10;
  	}
	numb=temp;
	value=0;
  	while(top >=0)
  	{
     		j=pop();
		value=value+pow(j,count);
  	}
	if(value==numb)return 1;
	else return 0;
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
  	else
  	{
    		j=stack[top];
    		top--;
    		return(j);
  	}
}

