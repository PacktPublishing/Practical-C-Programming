#include <stdio.h>
#define max 100
/* All the elements of the principal diagonal of the  Identity matrix  are ones and rest all are zero elements  */
void main ()
{
	static int arr[max][max];
	int i,j,r,c, bool;
     	printf("How many rows and columns are in this matrix ? ");
     	scanf("%d %d", &r, &c);
	if (r !=c)
	{
		printf("An identity matrix is a square matrix\n");
		printf("Because this matrix is not a square matrix, so it is not an identity matrix\n");
	}
	else
	{
	 	printf("Enter elements in the matrix :\n");
       		for(i=0;i<r;i++)
        		{
            			for(j=0;j<c;j++)
            			{
	           		scanf("%d",&arr[i][j]);
            			}
        		}
		printf("\nThe entered matrix is \n");
		for(i=0;i<r;i++)
        		{
            			for(j=0;j<c;j++)
            			{
	           		printf("%d\t",arr[i][j]);
            			}
			printf("\n");
        		}
		bool=1;
       		for(i=0;i<r;i++)
        		{
     			for(j=0;j<c;j++)
            			{
				if(i==j)
				{
					if(arr[i][j] !=1)
					{
						bool=0;
						break;
					}
				}
				else
				{
					if(arr[i][j] !=0)
					{
						bool=0;
						break;
					}
				}
			}

		}
		if(bool)printf("\nMatrix is an identity matrix\n");		
		else printf("\nMatrix is not an identity matrix\n");
	}
}