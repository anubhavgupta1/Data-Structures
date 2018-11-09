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

