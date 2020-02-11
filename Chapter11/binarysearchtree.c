#include <stdio.h>
#include <stdlib.h>

#define max 10

struct tree
{
	int data;
	struct tree *right;
	struct tree *left;
};

void build(int Arr[], int Len);
struct tree *makeroot(int val);
void rightchild(struct tree * rootNode, int val);
void leftchild(struct tree *rootNode, int val);
void travino(struct tree *node);

int main()
{
	int arr[max],i,len;
	printf("How many elements are there for making the binary search tree? ");
	scanf("%d", &len);
	printf("Enter %d elements in array \n",len);
	for(i=0;i<len;i++)
		scanf("%d",&arr[i]);
	build(arr,len);
	return 0;
}

void build(int Arr[], int Len)
{
	struct tree *temp, *rootNode;
	int j;
	rootNode=makeroot(Arr[0]);
	for(j=1;j<Len;j++)
	{
		temp=rootNode;	
		while (1)
		{
			if(Arr[j] < temp->data )
			{
				if(temp->left !=NULL)
				{
					temp=temp->left;
					continue;
				}
				leftchild(temp,Arr[j]);
			}
			if(Arr[j] >temp->data)
			{
				if(temp->right !=NULL)
				{
					temp=temp->right;
					continue;
				}
				rightchild(temp,Arr[j]);
			}
			break;
		}
	}
	printf ("Binary Search Tree is created\n");
	printf("The inorder traversal of the tree is as follows:\n");
	travino(rootNode);
}

struct tree *makeroot(int val)
{
	struct tree *rootNode;
	rootNode=(struct tree *)malloc(sizeof(struct tree));
	rootNode->data=val;
	rootNode->right=NULL;
	rootNode->left=NULL;
	return rootNode;
}

void leftchild(struct tree *rootNode, int val)
{
	struct tree *newNode;
	newNode=(struct tree *)malloc(sizeof(struct tree));
	newNode->data=val;
	newNode->left=NULL;
	newNode->right=NULL;
	rootNode->left=newNode;
}

void rightchild(struct tree *rootNode, int val)
{
	struct tree *newNode;
	newNode=(struct tree *)malloc(sizeof(struct tree));
	newNode->data=val;
	newNode->left=NULL;
	newNode->right=NULL;
	rootNode->right=newNode;
}

void travino(struct tree *node)
{
	if (node!=NULL)
	{
		travino(node->left);
		printf ("%d\t",node->data);
		travino(node->right);
	}
}

