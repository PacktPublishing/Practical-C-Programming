#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
 
#define BUFFSIZE 255

void main (int argc, char* argv[]) 
{
   	FILE *fp;
  	char buffer[BUFFSIZE];
  	int n, i, count=0;

  	fp = fopen (argv [1],"r");
  	if (fp == NULL) {
    		printf("%s file does not exist\n", argv[1]);
    		exit(1); 
  	} 
	printf("The file content is :\n");
  	while (!feof(fp))
  	{
    		fgets(buffer, BUFFSIZE, fp); 
    		puts(buffer);
		n=strlen(buffer);
		for(i=0;i<n;i++)
		{
			if(buffer[i]=='a' || buffer[i]=='e' || buffer[i]=='i' || buffer[i]=='o' || buffer[i]=='u' || buffer[i]=='A' || buffer[i]=='E' || buffer[i]=='I' || buffer[i]=='O' || buffer[i]=='U') count++;
		}	
  	}
	printf("The number of vowels are %d\n",count);
  	fclose(fp);
} 
