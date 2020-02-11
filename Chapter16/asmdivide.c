#include <stdio.h>

void main() {
	int var1=19,var2=4, var3=0, remainder, quotient;
  	asm("divl %%ebx;"
      		"movl %%edx, %0"
      		: "=b" (remainder) ,  "=r" (quotient) 
       		: "a" (var1), "b" (var2), "d" (var3)  
  
	);
	printf ("On dividing %d by %d, you get %d quotient and %d remainder\n", var1, var2, quotient, remainder);
}
