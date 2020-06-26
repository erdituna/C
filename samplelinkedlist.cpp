#include <stdio.h>
#include <stdlib.h>

struct ogrenci{
	int numara;
	struct ogrenci *sonraki;
};
typedef struct ogrenci node;

node* CreateList(void);
void PrintList(node*);
node* InsertList(node*);
node* DeleteList(node*);

int main(void){
	node *head;
	head = CreateList();
	head = InsertList(head);
	head = DeleteList(head);
	PrintList(head);
	return 0;
}
node* CreateList(void){
	node *head,*p,*newNode;
	int n;
	
	printf("Listeye Kac eleman eklemek istiyorsun:");
	scanf("%d",&n);
	fflush(stdin);
	
	for(int i=0;i<n;i++){
		if(i==0){
			head=(node*)malloc(sizeof(node));
			p=head;
		}else{
			newNode=(node*)malloc(sizeof(node));
			p->sonraki = newNode;
			p=newNode;
		}
		printf("\n%d. Ogrencinin Numarasini Gir:",i+1);
		scanf("%d",&p->numara);
		fflush(stdin);
	}
	p->sonraki = NULL;
	return head;
}

void PrintList(node* head){
	node *p;
	p = head;
	int counter=1;
		printf("\n******** Listedeki Ogrenciler*********\n");
	while(p!=NULL){
		printf("%d.Ogrencinin Numarasi:%d\n",counter,p->numara);
		counter++;
		p=p->sonraki;
	}
		printf("\n******** Listedeki Ogrenciler*********\n");
	
}

node* InsertList(node* head){
	
	node *newNode,*p,*q;
	int ogrNo;
	
	 newNode=(node*)malloc(sizeof(node));
	 printf("Eklenecek Ogrencinin Numarasini Gir:");
	 scanf("%d",&newNode->numara);
	 newNode->sonraki = NULL;
	 fflush(stdin);
	 
	 printf("\nHangi Ogrenci numarasindan once eklenecek:");
	 scanf("%d",&ogrNo);
	 fflush(stdin);
	 
	p=head;
	q=p;
	if(p->numara == ogrNo){
		newNode->sonraki = head;
		head = newNode;
	}else{
		while(p!=NULL){
			if(p->numara == ogrNo){
			   break;	
			}else{
			  q=p;
			  p=p->sonraki;	
			}
		}
		q->sonraki = newNode;
		newNode->sonraki = p;
	}
	return head;
}
node* DeleteList(node* head){
	node *p,*q;
	int ogrNo;
	

	 printf("Silinecek Ogrencinin Numarasini Gir:");
	 scanf("%d",&ogrNo);
	 fflush(stdin);
	p=head;
	q=p;
	if(p->numara == ogrNo){
		head = p->sonraki;
		free(p);
	}else{
		while(p!=NULL){
			if(p->numara == ogrNo){
			   break;	
			}else{
			  q=p;
			  p=p->sonraki;	
			}
		}
		q->sonraki = p->sonraki;
		free(p);
	}
	return head;
}

