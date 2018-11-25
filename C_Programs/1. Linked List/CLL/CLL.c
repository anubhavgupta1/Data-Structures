#include<stdio.h>
#include<stdlib.h>

typedef struct node_type
{
	int data;
	struct node_type *next;
}node;typedef node *list;

list createBeg(list head)
{
	list temp,curr;
	temp = NULL;
	curr = head;
	int n; char ch;
	printf("Enter data? (y/n) :");
	scanf("\n%c",&ch);fflush(stdin);
	while(ch=='y'||ch=='Y')
	{
		printf("\nGive data : ");
		scanf("%d",&n);
		temp= (list)malloc(sizeof(node));
		temp->data = n;
		while(curr->next != head )
		{
			curr = curr->next;
		}
		temp->next = temp;
		if(!head)
		{
			head = temp;
		}
		else
		{
			temp->next = head;
			curr->next = temp;
			head = temp;
		}
		printf("Enter data? (y/n) :");
		scanf("\n%c",&ch);fflush(stdin);
	}
	return head;
}
void printList(list head)
{
	list curr = head;
	if(!head)
	{
		printf("\nlist Empty");
		return;
	}
	do
	{
		printf("%d\t",curr->data);
		curr = curr->next;
	}while(curr!=head);
}
void main()
{
	list head;
	head = createBeg(head);
	printList(head);
}
