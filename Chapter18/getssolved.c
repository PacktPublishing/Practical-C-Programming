#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct users
{
  char name[10];
  int  orderid;
};

int main(void)
{
	struct users user1;
	int n;
	printf("Enter order number ");
	scanf("%d", &user1.orderid);
	fpurge(stdin);
	printf ("Enter user name ");
	fgets(user1.name, sizeof(user1.name), stdin);
 	n = strlen(user1.name)-1;
  	if(user1.name[n] == '\n') 
     		user1.name[n] = '\0';
	printf("Information of the user is - Name %s, Order number %d\n", user1.name, user1.orderid);
}


