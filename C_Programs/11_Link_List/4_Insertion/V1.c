#include<stdio.h>
#include<stdlib.h>
//#include<malloc.h>
typedef struct node_type
{
  int data;
  struct node_type *next;
}node;

typedef node *list;

void create (list *head)
{
    list temp;
   char ch;
   int n;
   *head = NULL;
   printf("Enter Data ? (Y/N)\n");
   scanf("%c",&ch);
   fflush(stdin);
   while(ch=='Y' || ch=='y')
   {
     printf("Give Data : ");
     scanf("%d",&n);
     temp = (list)malloc(sizeof(node));
     temp->data = n;
     temp->next = *head;
     *head = temp;
     printf("Enter More Data ? (Y/N)");
     scanf("\n%c",&ch);
     fflush(stdin);
   }
  temp = *head;

}
void printList(list head)
{
  while(head!=NULL)
  {
     printf("%d\t",head->data);
     head = head->next;
  }
}

int main()
{
   list head;
   create(&head);
   printList(head);
  return 0;
}
