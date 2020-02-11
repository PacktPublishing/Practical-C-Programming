# include<stdio.h>
# define stacksize 10
#define arrsize 20
int top1=-1,top2=-1;
int stack1[stacksize];
int stack2[stacksize];
int arr[arrsize];

int quick(int, int);
void pushstk1(int);
void pushstk2(int);
int popstk1();
int popstk2();

int main()
{
	int sindex,eindex,lindex,uindex,k,pivot,i, len;
	printf("How many numerical to sort? ");
	scanf("%d",&len);
	printf("Enter %d numericals:\n", len);
	for(i=0;i<=len-1;i++)
		scanf("%d",&arr[i]);
	lindex=0;
	uindex=len-1;
	pushstk1(lindex);
	pushstk2(uindex);
	while(top1!=-1)
	{
		sindex=popstk1();
		eindex=popstk2();
		pivot=quick(sindex,eindex);
		if(sindex<pivot-1)
		{
			pushstk1(sindex);
			pushstk2(pivot-1);
		}
		if(pivot+1<eindex)
		{
			pushstk1(pivot+1);
			pushstk2(eindex);
		}
	}
	printf("\nAscending order using Quick Sort is:\n");
	for(i=0;i<=len-1;i++)
		printf("%d\n",arr[i]);
	return 0;
}

int quick(int si,int ei)
{
	int li,temp;
	li=si;
	while(1)
	{
	while(arr[ei]>=arr[li] && li !=ei)
		ei--;
	if(li==ei) return(li);
	if(arr[li]>arr[ei])
	{
		temp=arr[li];
		arr[li]=arr[ei];
		arr[ei]=temp;
		li=ei;
	}
	while(arr[si]<=arr[li] && li!=si)
		si++;
	if(li==si) return(li);
	if(arr[si]>arr[li])
	{
		temp=arr[si];
		arr[si]=arr[li];
		arr[li]=temp;
		li=si;
	}
	}
	return 0;
}

void pushstk1(int s)
{
	   top1++;
	   stack1[top1]=s;
}

void pushstk2(int e)
{
	   top2++;
	   stack2[top2]=e;
}

int popstk1()
{
      return(stack1[top1--]);
}

int popstk2()
{
      return(stack2[top2--]);
}