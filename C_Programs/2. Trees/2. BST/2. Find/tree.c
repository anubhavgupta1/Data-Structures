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
    tree temp =  (tree)malloc(sizeof(node)); 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
}

tree create(tree root, int key) 
{ 
	/* If the tree is empty, return a new node */
    if (root == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < root->data) 
        root->left  = create(root->left, key); 
    else if (key > root->data) 
        root->right = create(root->right, key);    
  
    /* return the (unchanged) node pointer */
    return root; 
} 
 
tree getData()
{
	char ch;int n; tree root = NULL;
	printf("Enter root : ");
	scanf("%d",&n);
	root = create(root,n);
	printf("Do you want to enter more data?(y/n):");
	scanf("\n%c",&ch); fflush(stdin);
	while(ch=='y'||ch=='Y')
	{
		printf("Give data : "); scanf("%d",&n);
		create(root,n);
		printf("Do you want to enter more data?(y/n):");
		scanf("\n%c",&ch); fflush(stdin);
	}
	return root;
}
tree find(tree root, int data)
{
	if(root==NULL)
	{
		return NULL;
	}
	if (data<root->data)
	{
		return find(root->left,data);
	}
	else if (data>root->data)
	{
		return find(root->right,data);
	}
	return root;
}
void main()
{
	tree root = getData();
	printf("Enter the Element to search : ");
	int n; scanf("%d",&n);
	tree temp = find(root,n);
	if(temp->data == n)
	{
		printf("%d is present at location : %u ",n,temp);
	}
}
