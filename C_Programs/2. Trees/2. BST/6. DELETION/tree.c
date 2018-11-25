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
tree findMin(tree root)
{
	if(root==NULL) return NULL;
	else if(root->left== NULL) return root;
	else return findMin(root->left);	
} 

tree deleteNode(tree root, int key) 
{ 
    // base case 
    if (root == NULL) 
	{
		printf("Tree is empty create tree first : \n");
		root = getData();
		return root;	
	} 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->data) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->data) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            tree temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            tree temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        tree temp = findMin(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->data = temp->data; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->data); 
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
	int n,a;
	printf("\nTraversal Choices : ");
	printf("\nPreorder: 1\nInorder : 2\nPostOrder : 3");
	printf("\nDeleteNode : 4");
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
			
			case 4:
			printf("\nGive data to delete : ");
			scanf("%d",&a);
			root = deleteNode(root,a);
			break;
			
			default:
			exit(0);
		}
	}
	return 0;
}
