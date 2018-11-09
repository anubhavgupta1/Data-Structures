#include"createBeg.h"
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

