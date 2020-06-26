#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
   int number;
   struct node *next;
};

struct node *DeleteMiddle(struct node *head)
{
   struct node *temp = head;
   struct node *deleting;
   int i = 0;
   while (temp != NULL)
   {
      i++;
      temp = temp->next;
   }
   printf("%d\n", i);
   temp = head;
   if (i == 1 || i == 2 || i == 3)
   {
      temp = head->next;
      free(head);
      return temp;
   }
   else
   {
      i = i / 2;
      while (i != 2)
      {
         i--;
         temp = temp->next;
      }
      deleting = temp->next;
      temp->next = temp->next->next;
      free(deleting);
      return head;
   }
};

int main()
{

   typedef struct node node;
   node *head = malloc(sizeof(node));
   if (head == NULL)
   {
      printf("Error! No memory allocated.");
      exit(0);
   }
   node *iter = head;
   int i;
   for ( i = 0; i < 2; i++)
   {
      head->number = i * 10;
      if (i == 1)
         break;
      node *yeninode = malloc(sizeof(node));
      if (head == NULL)
      {
         printf("Error! No memory allocated.");
         exit(0);
      }
      yeninode->next = NULL;
      head->next = yeninode;
      head = yeninode;
   }
   iter = DeleteMiddle(iter);
   while (iter != NULL)
   {
      printf("%d\n", iter->number);
      iter = iter->next;
   }
   return 0;
}
