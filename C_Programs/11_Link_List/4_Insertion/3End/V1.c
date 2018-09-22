#include<stdio.h> 
#include<stdlib.h> 
struct Node 
{ 
	int data; 
	struct Node *next; 
}; 

void append(struct Node** head_ref, int new_data) 
{ 
	/* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    struct Node *last = *head_ref; /* used in step 5*/
   /* 2. put in the data */
   new_node->data = new_data; 
  /* 3. This new node is going to be the last node, so make next 
		of it as NULL*/
	new_node->next = NULL; 

 /* 4. If the Linked List is empty, then make the new node as head */
	if (*head_ref == NULL) 
	{ 
	  *head_ref = new_node; 
	  return; 
	} 
	
	/* 5. Else traverse till the last node */
	while (last->next != NULL)
       { 
          last = last->next; 
	  /* 6. Change the next of last node */
	  	 
       }
last->next = new_node; 
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
        append(&head,x);
	printf("\nLink List after insertion");
        printList(head);
	return 0; 
} 
