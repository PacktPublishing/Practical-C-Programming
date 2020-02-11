#include <stdio.h>

int getdata() {
  	char cdigit = getchar_unlocked();
	int cnumb = 0;
  	while(cdigit<'0' || cdigit>'9') cdigit = getchar_unlocked();
  	while(cdigit >='0' && cdigit <='9') {
    		cnumb = 10 * cnumb + cdigit - 48;
    		cdigit = getchar_unlocked();
  	}
  	return cnumb;
}

int main()
{
   	int numb;
   	printf("Enter a number ");
   	numb=getdata();
   	printf("The number entered is %d\n",numb);
   	return 0;
}