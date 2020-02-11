#include <time.h> 
#include <stdio.h>
  
void somefunction() 
{ 
    for (int i=0; i<32000; i++) 
    { 
    	for (int j=0; j<32000; j++) ;
    } 
} 
  
int main() 
{ 
    clock_t clocktickstart, clocktickend; 
    double timeconsumed;
    clocktickstart = clock();  
    somefunction(); 
    clocktickend = clock(); 
    timeconsumed = (double)(clocktickend - clocktickstart) / CLOCKS_PER_SEC; 
    printf("Number of clocks ticks required in running the function is : %.3f\n",  (double)(clocktickend - clocktickstart)); 
    printf("Time taken by program is : %.2f sec\n", timeconsumed); 
    return 0; 
} 