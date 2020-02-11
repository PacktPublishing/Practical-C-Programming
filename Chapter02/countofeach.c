#include<stdio.h>   
# include<string.h> 

int ifexists(char u, char p[],  int v, int q[])
{
	int i;
	for (i=0; i<=v;i++)
	{
		if (p[i]==u) 
		{
		q[i]++;
		return (1);
		}
	}
	if(i>v) return (0);
}

void main()
{
	char str[80],chr[80];
	int n,i,x,count[80];
	printf("Enter a string: ");
	scanf("%s",str);
	n=strlen(str);
	chr[0]=str[0];
	count[0]=1;
	x=0; 
	for(i=1;i < n;  i++)
	{
		if(!ifexists(str[i], chr, x, count))
		{	
			x++;		
			chr[x]=str[i];
			count[x]=1;
		}
	}
	printf("The count of each character in the string %s is \n", str);
	for (i=0;i<=x;i++)
		printf("%c\t%d\n",chr[i],count[i]);
}




