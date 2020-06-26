#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct evenodd
{
   int x;
   struct evenodd *next;
} node;

int main()
{
   node *head;
   head = malloc(sizeof(node));
   if (head == NULL)
   {
      printf("Error! No memory allocated.");
      exit(0);
   }
   head->next = NULL;
   node *iter;
   iter = head;
   printf("Sayilari girin(sonlandirmak icin -1 girin:\n");
   int x;
   scanf("%d", &x);
   if (x == -1)
      printf("\n-1 girdiniz program sonlandirildi.\n");
   else
      head->x = x;
   while (1)
   {
      scanf("%d", &x);
      if (x == -1)
         break;
      if (x % 2 == 0)
      {
         node *newnode;
         newnode = malloc(sizeof(node));
         if (newnode == NULL)
         {
            printf("Error! No memory allocated.");
            exit(0);
         }
         newnode->x = x;
         newnode->next = NULL;
         head->next = newnode;
         head = newnode;
      }
      else
      {
         node *newnode;
         newnode = malloc(sizeof(node));
         if (newnode == NULL)
         {
            printf("Error! No memory allocated.");
            exit(0);
         }
         newnode->x = x;
         newnode->next = iter;
         iter = newnode;
      }
   }
   printf("\n\n-1 girdiniz program sonlandirildi.\nListe:\n");
   while (iter != NULL)
   {
      printf("%d\n", iter->x);
      iter = iter->next;
   }
   return 0;
}

void print(node *r)
{
   while (r != NULL)
   {
      printf("%d", r->x);
      r = r->next;
   }
}
