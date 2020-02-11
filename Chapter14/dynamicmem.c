#include <stdio.h> 
#include <stdlib.h> 
  
int main() 
{ 
    	int* ptr; 
	int m,n, i;
  
	printf("How many elements are there? ");
	scanf("%d", &n); 
    	ptr = (int*)calloc(n, sizeof(int)); 
    	if (ptr == NULL) { 
        		printf("Memory could not be allocated.\n"); 
        		exit(0); 
    	} 
        	printf("Enter %d elements \n", n); 
        	for (i = 0; i < n; ++i) 
		scanf("%d",&ptr[i]); 
        	printf("\nThe elements entered are: \n"); 
        	for (i = 0; i < n; ++i) 
            		printf("%d\n", ptr[i]); 
	printf("\nHow many elements you want to add more? ");
	scanf("%d",&m);
        	ptr = realloc(ptr, (m+n) * sizeof(int)); 
        	printf("Enter values for %d elements\n",m); 
        	for (i = n; i < (m+n); ++i) 
		scanf("%d",&ptr[i]); 
        	printf("\nThe complete set of elements now are: \n"); 
        	for (i = 0; i < (m+n); ++i) 
            		printf("%d\n", ptr[i]); 
	printf("\nHow many elements you want to keep ? ");
	scanf("%d", &m);
        	ptr = realloc(ptr, (m) * sizeof(int)); 
    	printf("\nThe new set of elements now are: \n"); 
        	for (i = 0; i < m; ++i) 
            		printf("%d\n", ptr[i]); 
    	free(ptr);    
    	return 0; 
}