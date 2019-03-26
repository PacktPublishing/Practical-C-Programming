/* Deleting an element from an array */

#include<stdio.h> 
void main()
{
	int p[100],i,n,a;
	printf("Enter the length of array: ");
	scanf("%d",&n);
	printf("Enter %d elements of array \n",n);
	for(i=0;i<=n-1;i++)
		scanf("%d",&p[i]); 
	printf("\nThe array is:\n");
	for(i=0;i<=n-1;i++)
		printf("%d\n",p[i]);
	printf("Enter the position/ location to delete: ");
	scanf("%d",&a);
	a--;
	for(i=a;i<=n-2;i++)
	{
		p[i]=p[i+1];
		/* All values from bottom of the array are shifted up till the location of the element to be deleted */
	}
	p[n-1]=0;
	/* The vacant position created at the bottom of the array is set to 0 */
	printf("Array after deleting the element is\n"); 
	for(i=0;i<= n-2;i++)
		printf("%d\n",p[i]);
}