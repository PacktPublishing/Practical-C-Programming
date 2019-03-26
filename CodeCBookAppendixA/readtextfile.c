#include <stdio.h> 
#include <stdlib.h>
 
#define BUFFSIZE 255

void main (int argc, char* argv[]) 
{
   FILE *fp;
  char buffer[BUFFSIZE];

  fp = fopen (argv [1],"r");
  if (fp == NULL) {
    printf("%s file does not exist\n", argv[1]);
    exit(1); 
  } 
  while (!feof(fp))
  {
    fgets(buffer, BUFFSIZE, fp); 
    puts(buffer);
  }
  fclose(fp);
} 
