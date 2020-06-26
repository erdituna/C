#include <stdio.h>
#include <stdlib.h> 


struct ogrenci{
	int numara;
	struct ogrenci *next;
};

typedef struct ogrenci node;

node *arrayToList(int arr[], int n) 
{ 
    node *root = NULL; 
    for (int i = 0; i < n; i++) 
        insert(&root, arr[i]); 
    return root; 
} 

void insert(node** root, int item) 
{ 
    node* temp = malloc(sizeof(node));
    node* ptr; 
    temp->numara = item; 
    temp->next = NULL; 
  
    if (*root == NULL) 
        *root = temp; 
    else { 
        ptr = *root; 
        while (ptr->next != NULL) 
            ptr = ptr->next; 
        ptr->next = temp; 
    } 
} 

void PrintList(node* head){

	while(head!=NULL){
		printf("%d \t", head->numara);
		head = head->next;
	}
	
}

void removeDuplicates(node* head) 
{ 
	
	node* current = head; 

	
	node* next_next; 
	
	
	if (current == NULL) 
	return; 

	
	while (current->next != NULL) 
	{ 
       
		if (current->numara == current->next->numara) 
        { 		
            	
			next_next = current->next->next; 
            free(current->next); 
            current->next = next_next; 
        } 
        
        { 
            current = current->next; 
        } 
	} 
} 

void printNthFromLast(node* head, int n) 
{ 
    int len = 0, i; 
    node *temp = head; 
  
    
    while (temp != NULL) 
    { 
        temp = temp->next; 
        len++; 
    } 
  
   
    if (len < n) 
        return; 
  
    temp = head; 
  
    
    for (i = 1; i < len-n+1; i++) 
        temp = temp->next; 
  
    printf ("%d \n", temp->numara); 
  
    return; 
} 


int main(void){
	int arr[] = {20, 13, 13, 11, 11, 11, 9}; 
    int n = sizeof(arr) / sizeof(arr[0]);

	node* head = arrayToList(arr, n);
	PrintList(head);
    removeDuplicates(head);
	printf("\nLinked list after duplicate removal \n");
    PrintList(head);

	printf("\n2nd element from last is ");	
	printNthFromLast(head, 2); 
	return 0;
}
