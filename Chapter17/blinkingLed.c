#include<reg52.h>          

sbit LED = P1^0;           
void Delay(int);
void main (void)
{
    while(1)                
    {
        LED = 0;            
        Delay(500);
        LED = 1;            
        Delay(500);
    }
}

void Delay(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<100;j++);
    }
}

