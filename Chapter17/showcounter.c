#include<stdio.h>
#include<reg52.h> 
                                  
void delay(void);        
void main()
     {
unsigned char i;  
      i=0x00;                    
      while(++i)
        { 
          P3=i;                                   
          delay();             
        }              
     }

void delay(void)
{
    int j;
    int i;
    for(i=0;i<1000;i++)
    {
        for(j=0;j<10000;j++)
        {
        }
    }
}
