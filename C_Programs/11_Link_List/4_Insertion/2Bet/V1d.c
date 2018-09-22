#include<stdio.h> 
#include<stdlib.h> 
struct Node 
{ 
	int data; 
	struct Node *next; 
}; 


void insertAfter(struct Node* prev_node, int new_data) 
{ 
   /*1. check if the given prev_node is NULL */
   if (prev_node == NULL) 
   { 
     printf("the given previous node cannot be NULL");	 
     return; 
   }
   
   /* 2. allocate new node */
   struct Node* new_node =(struct Node*) malloc(sizeof(struct Node)); 
   
   /* 3. put in the data */
   new_node->data = new_data; 
    
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next; 
    
    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node; 
} 
 


void printList(struct Node *n) 
{ 
  while (n != NULL) 
  { 
     printf(" %d\t ", n->data); 
     n = n->next; 
  } 
} 
int main() 
{ 
	int x;
        printf("Enter the new value = ");
	scanf("%d",&x);
	struct Node* head = NULL; 
	struct Node* second = NULL; 
	struct Node* third = NULL;  
	head = (struct Node*)malloc(sizeof(struct Node)); 
	second = (struct Node*)malloc(sizeof(struct Node)); 
	third = (struct Node*)malloc(sizeof(struct Node)); 
	head->data = 1;
	head->next = second;  
	second->data = 2; 
	second->next = third;  
	third->data = 3;  
	third->next = NULL;
        printf("\nLink List before insertion");
        printList(head);
        insertAfter(head,x);
	printf("\nLink List after insertion");
        printList(head);
	return 0; 
} 
