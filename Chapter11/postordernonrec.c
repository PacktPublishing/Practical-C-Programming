#include <stdio.h>
#include <stdlib.h>

struct tree
{
	int data;
	struct tree *right;
	struct tree *left;
};

struct stackstruc
{
	int valueArray[15];
	struct tree *nodeArray[15];
};

struct stackstruc stack;
int top=-1;

struct tree *makeroot(int val);
void rightchild(struct tree *rootNode, int val);
void leftchild(struct tree *rootNode, int val);
void nontravpost(struct tree *node);
void pushNode (struct tree *node, int val);
struct tree *popNode();
int popVal();

int main()
{
	struct tree *temp, *rootNode;
	int val;
	printf ("Enter elements of tree and 0 to quit\n");
	scanf("%d",&val);
	rootNode=makeroot(val);
	scanf("%d",&val);
	while(val !=0)
	{
		temp=rootNode;
		while (1)
		{
			if(val < temp->data )
			{
				if(temp->left !=NULL)
				{
					temp=temp->left;
					continue;
				}
				leftchild(temp,val);
			}
			if(val >temp->data)
			{
				if(temp->right !=NULL)
				{
					temp=temp->right;
					continue;
				}
				rightchild(temp,val);
			}
			break;
		}
		scanf("%d",&val);
	}
	printf ("\nTraversal of tree in Postorder without using recursion: \n");
		nontravpost(rootNode);
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

void nontravpost(struct tree *node)
{
	struct tree *temp;
	int val;
	temp=node;
	while (1)
	{
		while(temp!=NULL)
		{
			pushNode(temp,0);
			temp=temp->left;
		}
		while(top >=0)
		{
			temp=popNode();
			val=popVal();
			if (val==0)
			{
				if (temp->right !=NULL)
				{
					pushNode(temp,1);
					temp=temp->right;
					break;
				}
			}
			printf("%d\n",temp->data);
			continue;
		}

		if((temp==NULL) || (top <0)) break;
		else continue;
	}
}

void pushNode (struct tree *node, int val)
{
	top++;
	stack.nodeArray[top]=node;
	stack.valueArray[top]=val;
}

struct tree *popNode()
{
	return (stack.nodeArray[top]);
}

int popVal()
{
	 return(stack.valueArray[top--]);
 }
