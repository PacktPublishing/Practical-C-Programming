#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
 
void main (int argc, char* argv[]) 
{
   	FILE *fp;
  	char line[255], nline[300], str1[80], str2[80];
  	int i,ll, ls1,ls2, x,k, w, oldi;

  	fp = fopen (argv [1],"r");
  	if (fp == NULL) {
    		printf("%s file does not exist\n", argv[1]);
    		exit(1); 
  	} 
	printf("Enter a string to be replaced: ");
	scanf("%s", str1);
	printf("Enter the new string ");
	scanf("%s", str2);
	ls1=strlen(str1);
	ls2=strlen(str2);
	x=0;
  	while (!feof(fp))
  	{
    		fgets(line, 255, fp); 
		ll=strlen(line);

    		for(i=0;i<ll;i++)
		{
			w=0;
			if(line[i]==str1[w])
			{
				oldi=i;	
				while(w<ls1)
				{
					if(line[i] != str1[w])
						break;
					else
					{
						i++;
						w++;
					}
				}
				if(w==ls1)
				{
					
					i=oldi;
					for (k=0;k<ls2;k++)
					{
						nline[x]=str2[k];
						x++;
					}
					i=i+ls1-1;
				}
				else
				{
					i=oldi;
					nline[x]=line[i];
					x++;	
				}				

			}
			else
			{
				nline[x]=line[i];
				x++;
			}

		} 
		nline[x]='\0';
    		puts(nline);
 	 }
  	fclose(fp);
} 
