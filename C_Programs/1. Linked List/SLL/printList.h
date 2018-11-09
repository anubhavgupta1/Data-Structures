void printList(list head)
{
	printf("\nThe link list is : \n");
	while(head)
	{
		printf("[%d]\t",head->data);
		head = head->next;
	}
}

