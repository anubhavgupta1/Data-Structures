#include<stdio.h>
#include<stdlib.h>
typedef struct node_type
{
	int data;
	struct node_type *next;
	struct node_type *prev;
}node; typedef node *list;

list createBeg(list head)
{
	printf("\ninsert data Begining : \n");
	list temp; int n; char ch;
	temp = head = NULL;
	printf("Enter data?(y/n) : ");
	scanf("\n%c",&ch);fflush(stdin);
	while(ch=='y'||ch=='Y')
	{
		printf("\nGive data : ");
		scanf("%d",&n);
		temp = (list)malloc(sizeof(node));
		temp->data = n;
		temp->next = head;
		temp->prev = NULL;
		if(head) head->prev = temp;
		head = temp;
		printf("Enter more data?(y/n) : ");
		scanf("\n%c",&ch);fflush(stdin);
	}
	return head;
}
list createEnd(list *head)
{
	printf("\ninsert data at End : \n");
	int n; char ch; list curr, pprev,temp;
	curr = (*head);
	if(!curr)
	{			
		printf("\nCreate the node First : ");
		curr 	= createBeg(curr);
		(*head)	= curr;
	}
	while(curr)
	{
		pprev = curr;
		curr = curr->next; 
	}
	printf("\nEnter data?(y/n) ");
	scanf("\n%c",&ch);fflush(stdin);
	while(ch=='y'||ch=='Y')
	{
		printf("Give data: ");
		scanf("%d",&n);
		temp = (list)malloc(sizeof(node));
		temp->data = n; 
		temp->next = NULL;
		temp->prev = pprev;
		pprev->next = temp;
		pprev = pprev->next;
		printf("\nEnter data?(y/n) ");
		scanf("\n%c",&ch);fflush(stdin);
	}
}
void insertRandom(list *head)
{
	printf("\ninsert data at random position : \n");
	int count = 1, n, pos;
	printf("\nGive data : ");
	scanf("%d",&n);
	printf("\nGive position : ");
	scanf("%d",&pos);
	list pprev,curr,newNode;
	newNode = (list)malloc(sizeof(node));
	if(!newNode)
	{	
		printf("\nMemory Error"); 
		return;	
	}
	newNode->data = n;
	if(pos==1)
	{
		newNode->next = (*head);
		newNode->prev = NULL;
		if((*head)) (*head)->prev = newNode;
		(*head) = newNode;
		return;
	}
	curr = (*head);
	while((count<pos-1) && (!(curr->next)))
	{
		curr = curr->next;
		count = count + 1;
	}
	if(count!=pos)
	{
		printf("\nPosition does not exist"); return;
	}
	newNode->next = curr->next;
	newNode->prev = curr;
	if(curr->next)
	{
		curr->next->prev = newNode;
	}
	curr->next = newNode;
	return; 	
}
void deleteNode(list *head)
{
	int count = 1,pos;
	list curr = (*head),pprev;
	printf("\nGive Position : ");
	scanf("%d",&pos);
	if(!(*head))
	{
		printf("\nList is Empty");
		return;
	}
	if(pos==1)
	{
		(*head) = (*head)->next;
		if(!(*head))
		{
			(*head)->prev = NULL;
		}
		free(curr);
		return;
	}
	while((count<pos)&&(curr->next!=NULL))
	{
		curr = curr->next;
		count = count + 1;
	}
	if(count!=pos)
	{
		printf("Position does not exist");
	}
	pprev = curr->prev;
	pprev->next = curr->next;
	if(curr->next)
	{
		curr->next->prev = pprev;
	}
	free(curr);
	return;
}
void printList(list head) 
{ 
    list last; 
    printf("\nTraversal in forward direction \n"); 
    while(head) 
	{ 
        printf(" %d\t ", head->data); 
        last = head; 
        head = head->next; 
    } 
  
    printf("\nTraversal in reverse direction \n"); 
    while(last) 
	{ 
        printf(" %d\t ", last->data); 
        last = last->prev; 
    } 
}

void choice()
{	
	int n;
	list head = NULL;
	printf("\nChoice 1 = createBeg()\nChoice 2 = createEnd()");
	printf("\nChoice 3 = insertRandom()\nChoice 4 = deleteNode()");
	printf("\nChoice 5 = printList()");
	while(1)
	{
		printf("\nEnter the choice : ");scanf("%d",&n);
		switch(n)
		{
			case 1:
			head = createBeg(head);
			break;
		
			case 2 :
			createEnd(&head);
			break;

			case 3 :
			insertRandom(&head);
			break;

			case 4 :
			deleteNode(&head);
			break;
			
			case 5 :
			printList(head);
			break;

			default:
			exit(0);
		}
	}	
}
void main()
{
	choice();
}

