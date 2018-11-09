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

