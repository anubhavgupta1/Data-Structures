#include<stdio.h>
#include<stdlib.h>

typedef struct node_type
{
	int data;
	struct node_type *next;
}node;typedef node *list;

list createBeg(list head)
{
	printf("\ninsert data at Begining : \n");
	int n; char ch; list temp;
	head = temp = NULL;
	printf("Enter Data ? (y/n) ");
	scanf("\n%c",&ch);fflush(stdin);
	while(ch =='y'||ch=='Y')
	{
		printf("Give data : ");
		scanf("%d",&n);
		temp = (list)malloc(sizeof(node));
		temp->data = n;
		temp->next = head;
		head = temp;
		printf("Enter more Data ? (y/n) ");
		scanf("\n%c",&ch);fflush(stdin);	
	}
	return head;
}
list createEnd(list *head)
{
	printf("\ninsert data at End : \n");
	int n; char ch; list curr, prev,temp;
	curr = (*head);
	if(!curr)
	{			
		printf("\nCreate the node First : ");
		curr 	= createBeg(curr);
		(*head)	= curr;
	}
	while(curr)
	{
		prev = curr;
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
		prev->next = temp;
		prev = prev->next;
		printf("\nEnter data?(y/n) ");
		scanf("\n%c",&ch);fflush(stdin);
	}
}
void insertRandom(list *head)
{
	int count = 1,n,pos;
	list curr,prev,newNode;
	newNode = (list) malloc(sizeof(node));
	if(!newNode)
	{
		printf("Memory Error"); return;
	}
	printf("\nGive data : ");
	scanf("%d",&n);
	newNode->data=n;
	curr = (*head);
	printf("\nGive Position : ");
	scanf("%d",&pos);
	//Insert at begining
	if(pos==1)
	{
		newNode->next = curr;
		(*head) = newNode;
	}
	else
	{
		while((curr!=NULL)&&(count<pos))
		{
			count = count + 1;
			prev = curr;
			curr = curr->next;
		}
		prev->next = newNode;
		if(!curr)
		{
			newNode->next= NULL;
		}
		else
		{
			newNode->next = curr;
		}
	}
}
void deleteNode(list *head)
{
	int count = 1, pos;
	printf("\nGive position to delete : ");
	scanf("%d",&pos);
	list curr,prev;
	if((*head)==NULL)
	{
		printf("\nListEmpty : Create the list first");
		return;
	}
	curr = (*head);
	//deletion from begining
	if(pos==1)
	{
		(*head) = (*head)->next;
		free(curr);return;
	}
	else
	{
		while((curr!=NULL)&&count<pos)
		{
			count = count + 1;
			prev = curr;
			curr = curr->next;
		}
		if(curr==NULL)
		{
			printf("\nposition does not exist");
		}
		else
		{
			prev->next = curr->next;
			free(curr);
		}
	}
}
void printList(list head)
{
	printf("\nThe link list is : \n");
	while(head)
	{
		printf("[%d]\t",head->data);
		head = head->next;
	}
}
void choice()
{	
	int n;
	list head = NULL;
	printf("\nChoice 1 = createBeg()\nChoice 2 = createEnd()");
	printf("\nChoice 3 = insertRandom()\nChoice 4 = deleteNode()");
	printf("\nchoice 5 = printList()");
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
