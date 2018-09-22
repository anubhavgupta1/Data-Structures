#include<stdio.h>
#include<stdlib.h>
typedef struct node_type
{
  int data;
  struct node_type *next
}node;

typedef node *list;

void create(list *head)
{
  
   list temp; 
   char ch;
   int n;
   head = NULL;
   printf("Enter Data ? (Y/N)\n");
   scanf("%c",&ch);fflush(stdin);
   while(ch=='Y' || ch=='y')
   {
     printf("Give Data : ");
     scanf("%d",&n);
     temp = (list)malloc(sizeof(node));
     temp->data = n;
     temp->next = *head;
     *head = temp;
     printf("\nEnter More Data ? (Y/N)\n");
     scanf("%c",&ch);
     fflush(stdin);
   }

}

int main()
{
   list head;
   create(&head);
}
