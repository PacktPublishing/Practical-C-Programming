#include <stdio.h>
void main()
{
    char str[255];
    int  i;
   printf("Enter a sentence: ");
   gets(str);
   i=0;
    while(str[i]!='\0')
    {
        if(str[i]=='a' ||str[i]=='e' ||str[i]=='i' ||str[i]=='o' ||str[i]=='u')
            str[i]=str[i]-32;
        i++;
    }
    printf("The sentence after converting vowels into upper case is:\n");
    puts(str);
}