#include <string.h> 
#include <stdio.h> 
#include <stdlib.h>

 struct data{                              
    char str[ 255 ];   
}; 

void main (int argc, char* argv[]) 
{
   
   	FILE *fp;
 	struct data line;
	int n,nol,i;
  	fp = fopen (argv[1], "rb"); 
  	if (fp == NULL) {
     		perror ("An error occurred in opening the file\n"); 
    		exit(1); 
  	} 
 	fseek(fp, 0L, SEEK_END);       
   	n = ftell(fp);
	nol=n/sizeof(struct data);
	printf("The content of random file in reverse order is :\n");
    	for (i=1;i<=nol;i++)
    	{
		fseek(fp, -sizeof(struct data)*i, SEEK_END);  
		fread(&line,sizeof(struct data),1,fp);
		puts(line.str);
	}
  	fclose(fp);
} 

