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
  	fp = fopen (argv[1], "wb"); 
  	if (fp == NULL) {
     		perror ("An error occurred in creating the file\n"); 
    		exit(1); 
  	} 
	printf("Enter file content:\n");
	gets(line.str);
  	while(strcmp(line.str, "stop") !=0){
     		fwrite( &line, sizeof(struct data), 1, fp );
		gets(line.str);
	}
  	fclose(fp);
} 

