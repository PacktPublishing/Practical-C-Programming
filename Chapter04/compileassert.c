#include <stdio.h>
#include <assert.h>

struct customers
{
         int orderid;
         char customer_name[20];
         float amount;
};

static_assert(sizeof(struct customers) == 28, "The structure is consuming unexpected number of bytes"); 

int main(void)
{
	printf("sizeof(int) %d\n",sizeof(int));
 	printf("sizeof(float) %d\n",sizeof(float));
	printf("sizeof(char) %d\n",sizeof(char));
	printf("sizeof(struct customers) %d\n",sizeof(struct customers));
   	return 0;
}