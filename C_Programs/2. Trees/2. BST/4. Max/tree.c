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
 

tree findMax(tree root)
{
	if(root==NULL) return NULL;
	else if(root->right== NULL) return root;
	else return findMax(root->right);	
}

void main()
{
	tree root = getData();
	tree temp = findMax(root);
	printf("The Maximum element is : %d",temp->data);
}


