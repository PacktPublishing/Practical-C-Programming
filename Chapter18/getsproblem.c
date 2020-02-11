#include <stdio.h>

struct users
{
  char name[10];
  int  orderid;
};

int main(void)
{
	struct users user1, user2;
	printf("Enter order number ");
	scanf("%d", &user1.orderid);
	fpurge(stdin);
	printf ("Enter first user name ");
	gets(user1.name);
	printf("Enter order number ");
	scanf("%d", &user2.orderid);
	fpurge(stdin);
	printf ("Enter second user name ");
	gets(user2.name);
	printf("Information of first user - Name %s, Order number %d\n", user1.name, user1.orderid);
	printf("Information of second user - Name %s, Order number %d\n", user2.name, user2.orderid);
}


