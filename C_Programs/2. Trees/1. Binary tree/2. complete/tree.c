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

unsigned int totalNodes(tree root)
{
	if(root==NULL){return 0;}
	else if (root->left == NULL && root->right == NULL){return 1;}
	else
	{
		return 1 + totalNodes(root->left) + totalNodes(root->right);
	}
}

unsigned int isComplete (tree root, unsigned int index, 
                 unsigned int number_nodes) 
{ 
    unsigned int x,y;
	// An empty tree is complete 
    if (root == NULL) 
        return (1); 
  
    // If index assigned to current node is more than 
    // number of nodes in tree, then tree is not complete 
    if (index >= number_nodes) 
        return (0); 
  
    x = isComplete(root->left, 2*index + 1, number_nodes);
    y = isComplete(root->right, 2*index + 2, number_nodes);
	// Recur for left and right subtrees 
    return ( x && y ); 
} 

void main()
{
	tree root = create(root);
	unsigned int n = totalNodes(root), index = 0;
	unsigned int x = isComplete(root,index,n);
	if(x!=0)
	{
		printf("Complete Binary tree");
	}
	else
	{
		printf("NOT");
	}
}
