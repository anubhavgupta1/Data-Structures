#include<stdio.h> 
#include<stdlib.h> 
struct Node 
{ 
	int data; 
	struct Node *next; 
}; 
void printList(struct Node *n,int x) 
{ 
  while (n != NULL) 
  { 
     printf(" %d\t ", n->data + x); 
     n = n->next; 
  } 
} 
int main() 
{ 
	int i,n,x;	
	struct Node* head   = NULL;
        struct Node* new_node = NULL;
        struct Node* p = NULL; 
	printf("Enter the header value");
        scanf("%d",&x);	
	head = (struct Node*)malloc(sizeof(struct Node)); 
	head->data = x;
        printf("Enter the number of nodes");
        scanf("%d",&n);
        p=head;
        for(i=0;i<n;i++)
        {
          printf("Enter the value");
          scanf("%d",&x);
          new_node = (struct Node*)malloc(sizeof(struct Node)); 
	  new_node->data = x;
	  new_node->next = NULL;
          p->next=new_node;
          p=new_node;
        }
	printf("Enter the value");
        scanf("%d",&x);
	printList(head,x);
	return 0; 
} 
