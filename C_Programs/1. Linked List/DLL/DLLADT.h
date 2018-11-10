#include<stdio.h>
#include<stdlib.h>
typedef struct node_type
{
	int data;
	struct node_type *next;
	struct node_type *prev;
}node; typedef node *list;
