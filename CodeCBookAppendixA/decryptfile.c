#include <stdio.h> 
#include <stdlib.h>
#include <string.h>  
 
#define BUFFSIZE 255

void main (int argc, char* argv[]) 
{
   	FILE *fp,*fq;
   	int  i,n;
  	char buffer[BUFFSIZE];

 	fp = fopen (argv [1],"r");
  	if (fp == NULL) {
    		printf("%s file does not exist\n", argv[1]);
    		exit(1); 
  	} 

  	fq = fopen (argv[2], "w"); 
  	if (fq == NULL) {
     		perror ("An error occurred in creating the file\n"); 
    		exit(1); 
  	} 
    	while (!feof(fp))
  	{
    		fgets(buffer, BUFFSIZE, fp); 
    		n=strlen(buffer);
		for(i=0;i<n;i++)
			buffer[i]=buffer[i]+45;
	      	fputs(buffer,fq);
  	}
    	fclose (fp); 
   	fclose (fq);  
} 
