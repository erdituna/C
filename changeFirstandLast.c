#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
   int number;
   struct node *next;
};

struct node *changeFirstAndLast(struct node *head)
{
   struct node *temp = head;
   struct node *yeniilk = head->next;
   struct node *sondanonceki = NULL;
   while (temp->next != NULL)
   {
      sondanonceki = temp;
      temp = temp->next;
   }
   sondanonceki->next = head;
   head->next = NULL;
   temp->next = yeniilk;
   return temp;
};

int main()
{
	typedef struct node node;
	struct node *head;
	struct node *iter;
   //ptr = (float*) malloc(100 * sizeof(float));

   head = (node*)malloc(sizeof(node));
   if (head == NULL)
   {
      printf("Error! No memory allocated.");
      exit(0);
   }
   iter = head;
   int i;
   for (i= 0; i < 10; i++)
   {
      head->number = i * 10;
      if (i == 9)
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
   iter = changeFirstAndLast(iter);
   while (iter != NULL)
   {
      printf("%d\n", iter->number);
      iter = iter->next;
   }

   return 0;
}
