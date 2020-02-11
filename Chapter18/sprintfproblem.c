#include <stdio.h>

struct users
{
  char name[10];
  int  orderid;
};

int main(void)
{
	struct users user1;
	user1.orderid=101;
	sprintf(user1.name, "%s","bintuharwani");
	printf("Information of the user - Name %s, Order number %d\n", user1.name, user1.orderid);
}


