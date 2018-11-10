void printList(list head) 
{ 
    list last; 
    printf("\nTraversal in forward direction \n"); 
    while(head) 
	{ 
        printf(" %d\t ", head->data); 
        last = head; 
        head = head->next; 
    } 
  
    printf("\nTraversal in reverse direction \n"); 
    while(last) 
	{ 
        printf(" %d\t ", last->data); 
        last = last->prev; 
    } 
}
