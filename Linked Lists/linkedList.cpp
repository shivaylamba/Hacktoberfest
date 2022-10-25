#include <iostream>
using namespace std;

struct Node
{
    struct Node *next;
    int data;
};

void Insert(Node** pointerToHead, int x)
{
    struct Node *temp = (Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (*pointerToHead != NULL)
        temp->next = *pointerToHead;
    *pointerToHead = temp;
};

void print(Node *head)
{
    printf("List is :");
    while (head != NULL)
    {
        printf(" %d", head->data);
        head = head->next;
    }
    printf("\n");
};

int main()
{
    Node *head = NULL;
    printf("How many numbers you want to put in the list?\n");
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the number :");
        scanf("%d", &x);
        Insert(&head, x);
        print(head);
    }
};