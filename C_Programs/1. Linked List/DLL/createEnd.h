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
