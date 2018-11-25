#include<stdio.h>
#include<stdlib.h>

typedef struct node_type  
{ 
    int data; 
    struct node_type *left; 
    struct node_type *right;
}node; 
typedef node *tree;

tree newNode(int data) 
{   
	tree temp = (tree)malloc(sizeof(node)); 
	temp->data = data; 
	temp->left = NULL; 
	temp->right = NULL; 
	return(temp); 
} 
tree create(tree root)
{
   int n;
   printf("\nGive data : ");
   scanf("%d",&n);
   root= newNode(n);
   if(n==-1) return NULL;
   printf("\nEnter the left child of %d ",n);
   root->left = create(root->left);
   printf("\nEnter the right child of %d ",n);
   root->right = create(root->right);
   return root;
}  

unsigned int leafNodes(tree root)
{
	tree x,y;
	if(root==NULL){return 0;}
	else if (root->left == NULL && root->right == NULL){return 1;}
	else
	{
		return leafNodes(root->left) + leafNodes(root->right);
	}
}

void main()
{
	tree root = create(root);
	unsigned int x = leafNodes(root);
	printf("Leaf count of the tree is %u", x);
}
