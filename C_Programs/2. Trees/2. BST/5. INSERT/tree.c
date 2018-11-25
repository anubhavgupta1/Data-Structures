#include<stdio.h>
#include<stdlib.h>

typedef struct node_type  
{ 
    int data; 
    struct node_type *left; 
    struct node_type *right;
}node; 
typedef node *tree;

tree insert(tree root, int n)
{
	if(root==NULL)
	{
		root = (tree)malloc(sizeof(node));
		if(root==NULL)
		{
			printf("Memory Error");	
		}
		else
		{
			root->data = n;
			root->left = root->right = NULL;	
		}	
	}
	else
	{
		if(n<root->data)
		{
			root->left = insert(root->left,n);	
		}
		else if(n>root->data)
		{
			root->right = insert(root->right,n);	
		}	
	}
	return root;
} 
 
tree getData()
{
	char ch;int n; tree root = NULL;
	printf("Enter root : ");
	scanf("%d",&n);
	root = insert(root,n);
	printf("Do you want to enter more data?(y/n):");
	scanf("\n%c",&ch); fflush(stdin);
	while(ch=='y'||ch=='Y')
	{
		printf("Give data : "); scanf("%d",&n);
		insert(root,n);
		printf("Do you want to enter more data?(y/n):");
		scanf("\n%c",&ch); fflush(stdin);
	}
	return root;
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

void inorder(tree root)
{
    if(root)
    {
        inorder(root->left); 
		printf("%d\t",root->data);        
        inorder(root->right);       
    }
}

int main() 
{
	printf("\nif(null) then Give Data : -1\n");
	tree root = getData();
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
