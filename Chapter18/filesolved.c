#include <stdio.h> 
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFSIZE 255

void main (int argc, char* argv[]) 
{
	int ifp;
   	FILE *fp;
  	char str[BUFFSIZE];
 	if (symlink("file2.txt","file1.txt") != 0) {
      		perror("symlink() error");
      		unlink("file2.txt");
  		exit(1); 
   	 }
	else
	{
    		unlink("file1.txt");
		ifp = open("file1.txt", O_WRONLY | O_CREAT | O_EXCL, 0600); 
    		if (ifp == -1) {
        			perror("An error occurred in creating the file\n");
			exit(1); 
    		}
		fp = fdopen(ifp, "w");
		if (fp == NULL) {
     			perror ("Could not be linked to the stream\n"); 
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
