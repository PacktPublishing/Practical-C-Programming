#include<stdio.h>   
# include<string.h> 

int ifexists(char u, char z[],  int v)
{
	int i;
	for (i=0; i<v;i++)
		if (z[i]==u) return (1);
	return (0);
}

void main()
{
	char str1[80],str2[80];
	int n,i,x;
	printf("Enter a string: ");
	scanf("%s",str1);
	n=strlen(str1);
	str2[0]=str1[0];
	x=1; 
	for(i=1;i < n;  i++)
	{
		if(ifexists(str1[i], str2, x))
		{
			printf("The first repetitive character in %s is %c", str1, str1[i]);
			break;
		}
		else
		{
			str2[x]=str1[i];
			x++;
		}
	}
	if(i==n)
		printf("There is no repetitve character in the string %s", str1);
}




