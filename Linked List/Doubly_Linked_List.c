#include <stdio.h>
#include <stdlib.h>

struct node
{
     struct node *prev;
     int data;
     struct node *next;
};

typedef struct node list;

list *first = NULL;

void Create(int n)
{
     printf("Enter the first element of the list ");
     int x;
     scanf("%d", &x);
     first = (list *)malloc(1 * sizeof(list));
     first->data = x;
     first->prev = NULL;
     first->next = NULL;

     list *current = first;

     printf("Enter the rest of the elements of the list ");
     for (int i = 1; i < n; i++)
     {
          list *t;
          t = (list *)malloc(1 * sizeof(list));
          int n;
          scanf("%d", &n);
          t->data = n;
          t->next = NULL;
          t->prev = current;
          current->next = t;
          current = t;
     }
}

int Count()
{
     list *p = first;
     int cnt = 0;
     while (p)
     {
          cnt++;
          p = p->next;
     }
     return cnt;
}

void Display()
{
     list *p = first;
     while (p)
     {
          printf("%d ", p->data);
          p = p->next;
     }
     printf("\n");
}

int LSearch()
{
     int x;
     printf("Enter the element you are looking for: ");
     scanf("%d", &x);
     list *p = first;
     int pos = 1;
     while (p)
     {
          if (p->data == x)
               break;
          p = p->next;
          pos++;
     }
     if (p)
          return pos;
     else
          return -1;
}

void Insert()
{
     int x, pos;
     printf("Enter the element and its position at which you want to insert ");
     scanf("%d %d", &x, &pos);
     if (pos < 1 || pos > Count())
          return;
     else
     {
          if (pos == 1)
          {
               list *p = (list *)malloc(1 * sizeof(list));
               p->data = x;
               p->prev = NULL;
               p->next = first;
               first->prev = p;
               first = p;
          }
          else
          {
               list *p = first;
               for (int i = 0; i < pos - 1; i++)
               {
                    p = p->next;
               }
               list *t = (list *)malloc(1 * sizeof(list));
               t->data = x;
               t->next = p->next;
               t->prev = p;
               if (p->next)
                    p->next->prev = t;
               p->next = t;
          }
     }
}

int Delete()
{
     int pos;
     printf("Enter the position of element which you want to delete ");
     scanf("%d", &pos);
     if (pos < 1 || pos > Count())
          return -1;
     else
     {
          int x;
          if (pos == 1)
          {
               list *t = first;
               x = first->data;
               first = first->next;
               free(t);
               if (first)
                    first->prev = NULL;
          }
          else
          {
               list *p = first;
               for (int i = 0; i < pos - 1; i++)
               {
                    p = p->next;
               }
               p->prev->next = p->next;
               if (p->next)
                    p->next->prev = p->prev;
               x = p->data;
               free(p);
          }
          return x;
     }
}

void Reverse()
{
     list *p = first;
     int temp;
     while (p)
     {
          temp = p->next;
          p->next = p->prev;
          p->prev = temp;
          p = p->prev;
          if (p->next == NULL)
               first = p;
     }
}

int main()
{
     int n;
     printf("Enter the initial number of elements:\n");
     scanf("%d", &n);
     Create(n);
     printf("\nOperations you wanna perform on the above list\n1)Print the elements of the list...\n2)Count the number of elements in the list...\n3)Search any element in the list...\n4)Insert a new element into the list...\n5)Delete an existing element from the list...\n6)Reverse the list...\n");
     int z;
     scanf("%d", &z);
     switch (z)
     {
     case 1:
          Display();
          break;
     case 2:
          Count();
          break;
     case 3:
          LSearch();
          break;
     case 4:
          Insert();
          Display();
          break;
     case 5:
          Delete();
          Display();
          break;
     case 6:
          Reverse();
          Display();
          break;
     default:
          printf("Wrong choice!");
     }
}