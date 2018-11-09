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

