#include <stdio.h>
#include <stdlib.h>

struct node
{
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
     first->next = first;

     list *current = first;

     printf("Enter the rest of the elements of the list ");
     for (int i = 1; i < n; i++)
     {
          list *t;
          t = (list *)malloc(1 * sizeof(list));
          int n;
          scanf("%d", &n);
          t->data = n;
          t->next = first;
          current->next = t;
          current = t;
     }
}

int Count()
{
     list *p = first;
     int cnt = 0;
     do
     {
          cnt++;
          p = p->next;
     } while (p != first);
     return cnt;
}

void Display()
{
     list *p = first;
     do
     {
          printf("%d ", p->data);
          p = p->next;
     } while (p != first);
     printf("\n");
}

int LSearch()
{
     int x;
     printf("Enter the element you are looking for: ");
     scanf("%d", &x);
     list *p = first;
     int pos = 1;
     do
     {
          if (p->data == x)
               break;
          p = p->next;
          pos++;
     } while (p != first);
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
               list *t = first;
               list *p = (list *)malloc(1 * sizeof(list));
               p->data = x;
               p->next = first;
               do
               {
                    t = t->next;
               }while (t->next != first);
               t->next = p;
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
               list *q = first;
               x = first->data;
               do
               {
                    q = q->next;
               }while (q->next != first);
               q->next = first->next;
               first = first->next;
               free(t);
          }
          else
          {
               list *p = first;
               list *q = NULL;
               for (int i = 0; i < pos - 1; i++)
               {
                    q = p;
                    p = p->next;
               }
               q->next = p->next;
               x = p->data;
               free(p);
          }
          return x;
     }
}

void Replace()
{
     int x, pos;
     printf("Enter an element and the position where you want to replace it with ");
     scanf("%d %d", &x, &pos);
     list *p = first;
     do
     {
          p = p->next;
     } while (p != first);
     p->data = x;
}

int main()
{
     int n;
     printf("Enter the initial number of elements:\n");
     scanf("%d", &n);
     Create(n);
     printf("\nOperations you wanna perform on the above list\n1)Print the elements of the list...\n2)Count the number of elements in the list...\n3)Search any element in the list...\n4)Insert a new element into the list...\n5)Delete an existing element from the list...\n6)Replace an existing element with a new one...\n");
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
          Replace();
          Display();
          break;
     default:
          printf("Wrong choice!");
     }
}