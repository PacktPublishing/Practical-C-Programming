#include <string.h> 
#include <stdio.h> 
#include <stdlib.h>

void main (int argc, char* argv[]) 
{
   char str[255];
   FILE *fp;
 
  fp = fopen (argv[1], "w"); 
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
  fclose(fp);
} 

