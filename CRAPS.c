#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){
	
	int a,b,i=1;
	int toplam=0;	
	srand(time(NULL));
	printf("Attigin Zarlar:\n");
	

		a=rand()%6+1;
		b=rand()%6+1;
		toplam=a+b;	
		printf("%d\n%d\n",a,b);
		printf("Toplam: %d\n",toplam);
		
		if(toplam==7||toplam==11)
			printf("OYUNU KAZANDINIZ :) ");
		else if(toplam==2||toplam==3||toplam==12)
			printf("OYUNU KAYBETTINIZ :( "); 
			
					printf("Puanin: %d Tekrar Atiniz...\n",toplam);
					printf("Attigin Zarlar:\n");
					a=rand()%6+1;
					b=rand()%6+1;
					int toplam2=a+b;	
					printf("%d\n%d\n",a,b);
					printf("Toplam: %d\n",toplam2);
				
					if(toplam==toplam2)
						printf("KAZANDINIZ...");
					else if(toplam2==7)
						printf("Ayni Zar gelmedi ve Kaybettiniz...");
					else
						printf("Tekrar Zar Atiniz...");
						
	return 0;
}
