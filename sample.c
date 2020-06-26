#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
   int age;
   struct node *next;

} node;

node *DeleteNode(node *head, int x)
{
   int i = 0;
   node *temp = head;
   node *befdelnode = NULL;
   while (temp->next != NULL)
   {
      if (temp->age == x)
      {
         i++;
         if (i == 2)
         {
            befdelnode->next = temp->next;
            free(temp);
            return head;
         }
      }
      befdelnode = temp;
      temp = temp->next;
   }
}

int main()
{
   node *head;
   head = malloc(sizeof(node));
   if (head == NULL)
   {
      printf("Error! No memory allocated.");
      return;
   }
   head->next = NULL;
   node *iter;
   iter = head;
   printf("Ogrenci yaslarini girin(bitirmek icin 0 girin):\n");
   int x;
   scanf("%d", &x);
   if (x == 0)
   {
      printf("0 girdiniz yas alimi ve program sonlandirildi.");
      exit(0);
   }
   else
   {
      head->age = x;
   }
   while (x != 0)
   {
      node *newnode;
      newnode = malloc(sizeof(node));
      if (newnode == NULL)
      {
         printf("Error! No memory allocated.");
         exit(0);
      }
      newnode->age = x;
      newnode->next = NULL;
      head->next = newnode;
      head = newnode;
      scanf("%d", &x);
   }
   node *iter2 = iter;
   printf("\n\nYas silinmeden once liste:\n");
   while (iter != NULL)
   {
      printf("%d\n", iter->age);
      iter = iter->next;
   }
   DeleteNode(iter2, 12);
   printf("\n\nYas silindikten sonra liste:\n");
   while (iter2 != NULL)
   {
      printf("%d\n", iter2->age);
      iter2 = iter2->next;
   }

   return 0;
}
