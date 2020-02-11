#include <stdio.h>
#include <string.h>

struct users
{
  char name[10];
  int  orderid;
};

int main(void)
{
	struct users user1;
	char userid[]="administrator";
	user1.orderid=101;
	strcpy(user1.name, userid);
	printf("Information of the user - Name %s, Order number %d\n", user1.name, user1.orderid);
}


