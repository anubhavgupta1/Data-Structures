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
