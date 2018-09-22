#include<stdio.h>
#include<stdlib.h>
struct Node
{
   int data;
   struct Node *Next;
};
void printList(struct Node *n)
{
   while(n!=NULL)
   {
      printf("%d\t",n->data);
      n = n->Next;
   }
}
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
    new_node->Next = prev_node->Next; 
    
    /* 5. move the next of prev_node as new_node */
    prev_node->Next = new_node; 
} 
int main()
{
   int i,n,x;
   struct Node* head     = NULL;
   struct Node* new_node = NULL;
   struct Node* p        = NULL;
   head = (struct Node*)malloc(sizeof(struct Node));
   printf("Enter the Value of header");
   scanf("%d",&x);
   head->data = x;
   p = head;
   printf("\n-------------------------------\n");
   printf("Enter the number of nodes");
   scanf("%d",&n);
   printf("\n-------------------------------\n");
   for(i=0;i<n-1;i++)
   {
      printf("Enter the Value of next node");
      scanf("%d",&x);
      new_node = (struct Node*)malloc(sizeof(struct Node));
      new_node->data = x;
      new_node->Next = NULL;
      p->Next = new_node;
      p = new_node;
   }
   printf("\nLink list before insertion\n");
   printList(head);
   printf("\n-------------------------------\n");
   printf("Enter the value for new node = ");
   scanf("%d",&x);
   insertAfter(head,x);
   printf("\n-------------------------------\n");
   printf("\nLink list after insertion\n");
   printList(head);
   printf("\n-------------------------------\n");
   return 0;
}
