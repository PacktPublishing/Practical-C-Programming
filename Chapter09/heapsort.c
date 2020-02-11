# include <stdio.h>
#define max 20
int heap[max],len;

void insheap(int h);
int delsheap(int j);

int main()
{
       int arr[max],numb,i,j;
       printf("How many elements to sort? ");
       scanf("%d",&len);
       printf("Enter %d values \n", len);
       for(i=0;i<len;i++)
       {
		 scanf("%d",&numb);
		 insheap(numb);
       }
       j=len-1;
       for(i=0;i<len;i++)
       {
	 arr[i]=delsheap(j);
	 j--;
        }
       printf("\nThe Descending order is: \n");
       for(i=0;i<len;i++)
	 printf("%d\n",arr[i]);
       return 0;
}

void insheap(int value)
{
	static int x;
	int par,cur,temp;
	if(x==0)
	{
		heap[x]=value;
		x++;
	}
	else
	{
		heap[x]=value;
		par=(x-1)/2;
		cur=x;
		do{
			if(heap[cur]>heap[par])
			{
				temp=heap[cur];
				heap[cur]=heap[par];
				heap[par]=temp;
				cur=par;
				par=(cur-1)/2;
				
			}
			else break;
		} while(cur!=0);
		x++;
	}
}

int delsheap(int j)
{
	int loc,n=0,pos,lc=0,rc=0,temp=0;
	loc=j;
	pos=0;
	n=heap[pos];
	heap[pos]=heap[loc];
	if(loc==0 || loc==1) return (n);
	loc--;
	lc=2*pos+1;
	rc=2*pos+2;
	while (rc <=loc)
	{
		if((heap[pos]>heap[lc] && heap[pos]>heap[rc]))
			 return(n);
		else
		{
			if(heap[lc]>heap[rc])
			{
				temp=heap[lc];
				heap[lc]=heap[pos];
				heap[pos]=temp;
				pos=lc;
			}
			else
			{
				temp=heap[rc];
				heap[rc]=heap[pos];
				heap[pos]=temp;
				pos=rc;
			}
			lc=2*pos+1;
			rc=2*pos+2;
		}
	}
	if(lc==loc)
	{
		 if(heap[pos]<heap[lc])
		 {
			   temp=heap[pos];
			   heap[pos]=heap[lc];
			   heap[lc]=temp;
			   pos=lc;
		 }
	}
	return(n);
}