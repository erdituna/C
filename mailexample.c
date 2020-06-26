#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user{
    char name[20];
    char surname[20];
    char birthYear[5];
    char mail[50];
    struct user * next;
};

char * emailOner(struct user *link){
    char mail1[50]="", mail2[50]="", mail3[50]="", mail4[50]="", temp[2]="";
    int index;
    strcat(mail1, link->name);
    strcat(mail1, ".");
    strcat(mail1, link->surname);
    strcat(mail1, "@gmail.com");
   
    strcat(mail2, link->surname);
    mail2[strlen(mail2)] =link->name[0];
    mail2[strlen(mail2)+1] ='\0';
    strcat(mail2, "@hotmail.com");
    
    strncpy(temp,link->name,1);
    strcat(mail3, temp);
    strcat(mail3, link->surname);
    strncpy(temp,link->birthYear+2,2);
    strcat(mail3, temp);
    strcat(mail3, "@gmail.com");
    
    strncpy(temp,link->name,2);
    strcat(mail4, temp);
    strcat(mail4, link->surname);
    strcat(mail4, link->birthYear);
    strcat(mail4, "@hotmail.com");

yazdir:  
    printf("\nE-posta adayi onerisi:");
    printf("\n1)%s", mail1);
    printf("\n2)%s", mail2);
    printf("\n3)%s", mail3);
    printf("\n4)%s", mail4);
    printf("\nSecmis oldugunuz e-postanin numarasini giriniz: ");
    scanf("%d",&index);
    printf("\n");
    
    switch(index){
        case 1: return mail1; 
        case 2: return mail2; 
        case 3: return mail3; 
        case 4: return mail4; 
        default: printf("Hatali giris!");
            goto yazdir;
        
    }

}

void swap(char * data1, char *data2){
	char temp[50];
	strcpy(temp,data1);
	strcpy(data1,data2);
	strcpy(data2,temp);
}

//baðlý listelerde buble sort
void bubleSort(struct user *head){
	if(head!=NULL){
		int i, j, temp, n=1; 
		struct user *ptr=head;
		
		//n deðeri listedeki eleman sayýsýný tutar
	    while(ptr->next!=NULL){
			n++;
			ptr=ptr->next;
		}
	
	  	for (i = 0; i < n-1; i++) {
	  		ptr=head;
	        for (j = 0; j < n-i-1; j++)  {
	            if (strcmp(ptr->birthYear,ptr->next->birthYear)>0) {//j. eleman ile kendisinden sonra gelen j+1. elemanýnýn karþýlaþtýrýlmasý
	            	//swap iþlemi struct user içindeki verileri yer deðiþtirir
	            	//eðer istenirse swap iþlemi listedeki nodlarýn yeri deðiþtirilerek de uygulanabilir
	              	swap(ptr->name,ptr->next->name);
	              	swap(ptr->surname,ptr->next->surname);
	              	swap(ptr->birthYear,ptr->next->birthYear);
	              	swap(ptr->mail,ptr->next->mail);
			    }
	            ptr=ptr->next;
		    }
	    }
	}
}


//baðlý listelerde binary search
int binarySearch(struct user *head, int l, int r, char * x){
	int i;
	struct user *midUser=head;

    if (r >= l) { 
        int mid = l + (r - l) / 2; 
		for(i=0;i<mid;i++)
		{
			midUser=midUser->next;
		}
		
        if (strcmp(midUser->birthYear, x)==0) 
		{    
			return mid+1; 
		}
  
        if (strcmp(midUser->birthYear, x)>0) 
            return binarySearch(head, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(head, mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 

}

void print(struct user *head){
    printf("\n");
    while(head!=NULL)
    {
        printf("\n\nAd Soyad: %s %s\nDogum Tarihi:%s\nMail Adresi:%s",head->name,head->surname,head->birthYear,head->mail);
        head=head->next;
    }
}
    
struct user * insert(struct user *head, char *name, char * surname, char *birthYear)
{
    struct user *link=(struct user*)malloc(sizeof(struct user));
    
    strcpy(link->name,name);
    strcpy(link->surname,surname);
    strcpy(link->birthYear,birthYear);

    strcpy(link->mail,emailOner(link));
    link->next=NULL;
    
    struct user *temp=head;
    
    //ilk eleman olarak ekle
    link->next=head;
    head=link;
    
    /*
    if(head==NULL)
    	head=link;
    else{
    	while(temp->next!=NULL){
    		temp=temp->next;}
    	temp->next=link;
    }*/
    
    return head;
}

//buble sort
char * gizliKelimeyiBul(char *kelime){

	int i, j, n=1;
	char temp;
	n=strlen(kelime);

  	for (i = 0; i < n-1; i++) {
  		// i eleman en sonda sýralý olduðu için n-1-i defa çalýþtýrýlr
        for (j = 0; j < n-i-1; j++)  {
            if (kelime[j]>kelime[j+1]) {
            	temp=kelime[j];
            	kelime[j]=kelime[j+1];
            	kelime[j+1]=temp;
		    }
	    }
    }
	return kelime;
}

//binary search
int searchKey(char *kelime, int l, int r, char x){
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        if (kelime[mid]==x) {
			return mid+1; 
		}
  
        if (kelime[mid]>x) {
            return searchKey(kelime, l, mid - 1, x); 
  		}

        return searchKey(kelime, mid + 1, r, x); 
    } 

    return -1; 

}



int main()
{
	
	printf("Gizli Kelimeyi Bul\n---------------------\n");
	char kelime[20]="ztou";
	printf("%s\n",kelime);
	strcpy(kelime,gizliKelimeyiBul(kelime));
	printf("Gizli kelime: %s\n",kelime);
	printf("u karakterinin indeksi: %d\n",searchKey(kelime,0,strlen(kelime)-1,'u'));
	printf("a karakterinin indeksi: %d\n",searchKey(kelime,0,strlen(kelime)-1,'a'));
    
	printf("\n**************************************************************************\n\nKullanici Listesi\n---------------------\n");
	
	
	
	int i, size=1; 
    struct user *head=NULL;
    
	//kullanýcý bilgileri ekrandan girilir, bunun için insert fonksiyonunda da deðiþiklik yapýlmalýdýr
	/*printf("Girilecek kullanici sayisi: ");
	int no;
	char name[20],surname[20],birthYear[20];
    scanf("%d", &no);
    for ( i=0;i< no;i++) {
	    printf("Ad:");
	    scanf("%s", name);
	    printf("Soyad:");
	    scanf("%s", surname);
	    printf("Dogm Yili:");
	    scanf("%s", birthYear);
    
        head=insert(head, name, surname, birthYear);
    }
  */  
	head=insert(head,"erdi","tuna","1989");
	head=insert(head,"ahmet","tan","1996");
	head=insert(head,"cem","ali","1975");
	head=insert(head,"mustafa","kaya","1998");
/*	head=insert(head,"elif","sagbas","2003");
	head=insert(head,"adnan","altin","2007");
	head=insert(head,"serdar","selim","1999");
	head=insert(head,"derya","nur","1989");
	head=insert(head,"fatih","genc","1952");
	head=insert(head,"cagin","bilge","1963");*/
	
    struct user *ptr=head;
    while(ptr->next!=NULL){
		size++;
		ptr=ptr->next;
	}
	
	printf("\nListenin boyutu: %d",size);
	printf("\nKullanici listesi:");
	print(head);
	
	printf("\n\nDogum tarihine gore siralanmis kullanici listesi:\n------------------------------------------");
    bubleSort(head);
	print(head);
	

	printf("\n\n1986 dogum yilina sahip kullanicinin indeksi: %d",binarySearch(head,0,size-1,"1986"));
	printf("\n\n1996 dogum yilina sahip kullanicinin indeksi: %d\n",binarySearch(head,0,size-1,"1996"));
    
	


    return 0;
}

