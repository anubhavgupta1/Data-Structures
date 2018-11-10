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
