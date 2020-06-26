#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
	struct node *prev;
};

struct node *insertAtFirst( struct node *head, int key){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp -> data=key;
	temp -> next=head;
	temp ->prev=NULL;
	if(head!=NULL)
		head->prev=temp;
	head=temp;
	return head;	
}
struct node *insertAtEnd(struct node *head, int key){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp-> data=key;
	temp->next = NULL;
	if(head==NULL){
		temp->prev=NULL;
		head= temp;		
	}
	else{
		struct node *last=head;
		while(last->next != NULL)
			last = last->next;
		last->next=temp;
		temp->prev=last;			
		
	}
	return head;
}

struct node *deletenode(struct node *head, int key){
	
	if(head==NULL)
		printf("list is empty");
	else {
		struct node *deleted =head;
		if(head->data ==key){
			deleted = head;
			head=head->next;
			free(deleted);
			head->prev=NULL;
		}
		else{
			while(deleted!=NULL && deleted->data!=key)
				deleted=deleted->next;
			if(deleted==NULL){
				printf("listede yok: ");
				return head;
			}
			deleted->prev->next=deleted->next;
			if(deleted->next!=NULL)
				deleted->next->prev=deleted->prev;
			free(deleted);
		}
		return head;
	}	
}
void print(struct node *head){
	if(head!=NULL){
		printf("%d\t",head->data);
		print(head->next);
	}
	
	
}

int main(){
	int secim,data;
	struct node *head = NULL;
	head=insertAtFirst(head,5);
	head=insertAtFirst(head,15);	
	head=insertAtEnd(head,51);	
	head=deletenode(head,15);	
	print(head);
}
