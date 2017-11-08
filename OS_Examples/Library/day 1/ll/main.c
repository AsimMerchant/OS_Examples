#include<stdio.h>
#include<stdlib.h>
#include "atul.h"
#include "/home/batch1/OS/day 1/ll/Link.h"
struct node
{
	int data;
	struct node *next;
};
int main()
{
	struct node *head=NULL;
	int n,c,d;
	while(1)
	{
		printf("1. Insert end\n2. Delete\n3. Display\n4. Insert begin\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			printf("Enter value\n");
			scanf("%d",&n);
			head=inend(head,n);
			break;
			case 2:
			printf("Enter value to delete\n");
			scanf("%d",&d);
			head=del(head,d);
			break;
			case 3:
			display(head);
			break;
			case 4:
			printf("Enter value\n");
			scanf("%d",&n);
			head=insertbeg(head,n);
			break;
			default:
			printf("Goto hell\n");
			break;

		}
	}
}
