#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *inend(struct node *head,int val)
{
	struct node *t,*t1;
	t1=(struct node *)malloc(sizeof(struct node));
	t1->next=NULL;
	t1->data=val;
	if(head==NULL)
		return t1;
	t=head;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	
	t->next=t1;
	return head;
}
struct node *del(struct node *head,int val)
{	
	struct node *t,*t1;
	if(head==NULL)
	{
		printf("The list is empty\n");
		return head;
	}
	t=head;
	if(t->data==val)
	{
		head=t->next;
		free(t);
		return head;
	}
	while(t->next!=NULL)
	{
		if(t->next->data==val)
		{
			t1=t->next;
			t->next=t->next->next;
			free(t1);
			return head;
		}
		t=t->next;
	}
	return head;	
}
