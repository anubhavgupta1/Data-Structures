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

