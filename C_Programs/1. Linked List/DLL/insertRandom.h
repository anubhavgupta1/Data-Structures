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
