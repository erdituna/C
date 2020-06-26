#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
   int number;
   struct node *next;
};

struct node *cutlastaddhead(struct node *head)
{
   struct node *temp = head;
   struct node *sondanonceki = NULL;
   while (temp->next != NULL)
   {
      sondanonceki = temp;
      temp = temp->next;
   }
   sondanonceki->next = NULL;
   temp->next = head;
   head = temp;
   return head;
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
   for (i = 0; i < 5; i++)
   {
      head->number = i * 10;
      if (i == 4)
         break;
      node *yeninode = malloc(sizeof(node));
      if (yeninode == NULL)
      {
         printf("Error! No memory allocated.");
         exit(0);
      }
      yeninode->next = NULL;
      head->next = yeninode;
      head = yeninode;
   }
   iter = cutlastaddhead(iter);
   while (iter != NULL)
   {
      printf("%d\n", iter->number);
      iter = iter->next;
   }

   return 0;
}
