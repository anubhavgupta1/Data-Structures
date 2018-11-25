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
void inorder(tree root)
{
    if(root)
    {
        inorder(root->left); 
		printf("%d\t",root->data);        
        inorder(root->right);       
    }
}

void preorder(tree root)
{
    if(root)
    {
        printf("%d\t",root->data);
		preorder(root->left);         
        preorder(root->right);       
    }
}
void postorder(tree root)
{
    if(root)
    {
		postorder(root->left);         
        postorder(root->right);
		printf("%d\t",root->data);       
    }
}
int main() 
{
	printf("\nif(null) then Give Data : -1\n");
	tree root = create(root);
	int n;
	printf("\nTraversal Choices : ");
	printf("\nPreorder: 1\nInorder : 2\nPostOrder : 3");
	while(1)
	{
		printf("\n\nEnter choice : ");scanf("%d",&n);
		switch(n)
		{
			case 1:
			printf("\nPreOrder Traversal : \n");
			preorder(root);
			break;
			
			case 2:
			printf("\nInOrder Traversal : \n");
			inorder(root);
			break;
			
			case 3:
			printf("\nPostOrder Traversal : \n");
			postorder(root);
			break;
			
			default:
			exit(0);
		}
	}
	return 0;
}
