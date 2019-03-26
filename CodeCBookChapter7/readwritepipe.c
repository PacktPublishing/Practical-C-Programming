#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h>

#define max 50 
  
int main() 
{ 
	char str[max];
    	int pp[2]; 
  
    	if (pipe(pp) < 0) 
        		exit(1); 
   	printf("Enter first message to write into pipe: ");
	gets(str);
    	write(pp[1], str, max); 
   	printf("Enter second message to write into pipe: ");
	gets(str);
    	write(pp[1], str, max); 
  	printf("Messages read from the pipe are as follows:\n"); 
        	read(pp[0], str, max); 
        	printf("%s\n", str); 
        	read(pp[0], str, max); 
        	printf("%s\n", str); 
    	return 0; 
} 