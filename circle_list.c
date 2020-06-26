#include <stdio.h>
#include <stdlib.h>


struct {
	
	int data;
	struct node *next;
	struct node *last;
	
	
	
};



void addlast(struct node *head,int key)
{
	
	if(head==NULL)
	{
		head=(struct node *)malloc(sizeof(struct node));
		head->data=key;
		head->next=head;
	}
	else
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		struct node *iter=head;
		while(iter->next!=head)
			iter=iter->next;
		iter->next=temp;
		head=temp->next;
		last=temp;
		
			
			
			
	}
	
void addnewlist(struct node *head1,struct node *head2)
{
	
	if(list1==NULL)
	{
		head1=head2;
	}
	else
	{
		struct node *last=head1;
		while(last->next!=head1)
		{
			last=last->next;
		}
		last->next=head2;
		list2->prev=last;
		last=head2;		
		while(last->next!=head2)
		{
			last=last->next;
		}
		last->next=head1;
		head1->prev=last;
	}
}

void remove(struct node *head,int key){
	
	
	struct node *temp;
	if(head->data==key)
	{
		head=head->next;
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
}
	
	
	
	
	
	
}

