#include <stdio.h>
#include <string.h>

struct users
{
  char name[10];
  int  orderid;
};

int main(void)
{
	int strsize;
	struct users user1;
	char userid[]="administrator";
	user1.orderid=101;
	strsize=sizeof(user1.name);
	strncpy(user1.name, userid,strsize);
	if (user1.name[strsize-1] != '\0') 
		user1.name[strsize-1] = '\0';
	printf("Information of the user - Name %s, Order number %d\n", user1.name, user1.orderid);
}


