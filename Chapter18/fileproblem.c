#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFSIZE 255

void main (int argc, char* argv[]) 
{
   	FILE *fp;
  	char str[BUFFSIZE];
 	if (symlink("file2.txt","file1.txt") != 0) {
      		perror("symlink() error");
      		unlink("file2.txt");
  		exit(1); 
   	 }
	else
	{
  		fp = fopen ("file1.txt","w");
		if (fp == NULL) {
     			perror ("An error occurred in creating the file\n"); 
    			exit(1); 
  		} 
  		printf("Enter content for the file\n");
  		gets(str);
  		while(strcmp(str, "stop") !=0){
      			fputs(str,fp);
      			gets(str);
  		} 
	}
  	fclose(fp);
}
