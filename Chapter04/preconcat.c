#include <stdio.h> 
#include <string.h>

#define pizzaprice(a, b) a##b
#define convertIntoStr(str) #str 

int main() 
{ 
	float smallnormal=5;
	float mediumnormal=7;
	float largenormal=10;
	float smallextra=7;
	float mediumextra=9;
	float largeextra=12;
	char pizzasize[30];
	char topping[20];

	printf("What size pizza you want? small/medium/large: ");
	scanf("%s", pizzasize);
	printf("Normal or with extra cheese? normal/extra: ");
	scanf("%s",topping);
	if(strcmp(topping, "normal")==0)
	{
		if(strcmp(pizzasize, "small")==0)
			printf("The prize for %s size pizza with %s toppings is $%.2f \n", pizzasize, topping, pizzaprice(small, normal));
		else
			if(strcmp(pizzasize, "medium")==0)
				printf("The prize for %s size pizza with %s toppings is $%.2f \n", pizzasize, topping, pizzaprice(medium, normal));
			else
				printf("The prize for %s size pizza with %s toppings is $%.2f \n", pizzasize, topping, pizzaprice(large, normal));
	}
	if(strcmp(topping, "extra")==0)
	{
		if(strcmp(pizzasize, "small")==0)
			printf("The prize for %s size pizza with %s toppings is $%.2f \n", pizzasize, topping, pizzaprice(small, extra));
		else
			if(strcmp(pizzasize, "medium")==0)
				printf("The prize for %s size pizza with %s toppings is $%.2f \n", pizzasize, topping, pizzaprice(medium, extra));
			else
				printf("The prize for %s size pizza with %s toppings is $%.2f \n", pizzasize, topping, pizzaprice(large, extra));
	}
	printf(convertIntoStr(Thanks for visiting us)); 
    	return 0; 
}