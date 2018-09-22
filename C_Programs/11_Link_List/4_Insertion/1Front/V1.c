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
void push(struct Node **head, int x)
{
  struct Node *new_Node = (struct Node*)malloc(sizeof(struct Node));
  new_Node->data = x;
  new_Node->Next = (*head);
  (*head) = new_Node;
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
   push(&head,x);
   printf("\n-------------------------------\n");
   printf("\nLink list after insertion\n");
   printList(head);
   printf("\n-------------------------------\n");
   return 0;
}
