#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * first;

void Delete_end(struct Node *p)
{
    if (first->data == 0)
    {
        printf("\nThe node is empty");
    }
    else if (first->data == 1)
    {
        p = p->next;
        printf("\nThe deleted node is : %d", p->data);
        free(p);
        first->data = 0;
        first->next = first;
        return;
    }
    while ((p->next)->next != first)
    {
        p = p->next;
    }
    printf("\nThe deleted node is : %d", (p->next)->data);
    free(p->next);
    p->next = first;
    --(first->data);
}

void Delete_front(struct Node *p)
{
    if (first->data == 0)
    {
        printf("\nThe node is empty");
        return;
    }

    p = p->next;
    first->next = p->next;
    printf("\nThe deleted node is : %d", p->data);
    free(p);
    --(first->data);
    return;
}

void Delete_pos(struct Node *p)
{
    int pos;
    printf("\nEnter a position between 1 - %d \nPosition :", p->data);
    scanf("%d", &pos);
    if (pos < 1 || pos > p->data)
    {
        printf("\nInvalid location!!\nPlease try again");
        return;
    }

    int count = 1;
    while ((count++) < pos)
    {
        p = p->next;
    }
    struct Node *temp = p->next;
    p->next = temp->next;
    printf("\nThe deleted node is %d", temp->data);
    free(temp);
    --(first->data);
}

void Delete_item(int item)
{
    if (first->data == 0)
    {
        printf("\nEmpty List- Deletion not possible!");
        return;
    }

    struct Node *curr = first, *prev;

    while (curr->data != item)
    {
        if (curr->next == first)
        {
            printf("\nElement Not found!");
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    if (curr->next == first)
    {
        printf("\nElement deleted is: %d", curr->data);
        prev->next = first;
        free(curr);
        printf("\nThe element was deleted successfully!\n");
        --(first->data);
        return;
    }

    prev->next = curr->next;
    prev = curr;
    curr = curr->next;
    free(prev);
    printf("\nThe element was deleted successfully!\n");
    --(first->data);
    return;
}

void Delete(struct Node *p)
{
    if (first->data == 0)
    {
        printf("\nThe node is empty");
        return;
    }
    int ch, item;
    printf("\nENTER\n1 : Delete form front\n2 : Delete from end\n3 : Delete positionwise\n4 : Delete itemwise\nCHOICE : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        Delete_front(p);
        break;
    case 2:
        Delete_end(p);
        break;
    case 3:
        Delete_pos(p);
        break;
    case 4:
        printf("\tEnter item to be deleted: ");
        scanf("%d", &item);
        Delete_item(item);
        break;

    default:
        printf("\nInvalid Input");
        break;
    }
}
void Insert_sort(struct Node *p)
{
    int x;
    struct Node *q = NULL;
    printf("  Enter the value to be inserted: ");
    scanf("%d", &x);
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first->data == 0)
    {

        first->next = t;
        t->next = first;
        (first->data)++;
    }

    else
    {

        if (first->next->data > x)
        {
            t->next = p->next;
            p->next = t;
            (first->data)++;
        }

        else
        {
            p = first->next;

            while (p->data < x)
            {
                if (p != first)
                {
                    q = p;
                    p = p->next;
                }

                else
                {
                    break;
                }
            }

            if (p == first)
            {
                q->next = t;
                t->next = first;
                (first->data)++;
            }

            else
            {
                t->next = q->next;
                q->next = t;
                (first->data)++;
            }
        }
    }
}

void Insert_unsort(struct Node *ptr)
{
    int index, item, i;
    struct Node *t;
    printf("  Enter the position between 1 - %d for insertion: ", first->data + 1);
    scanf("%d", &index);
    if (index < 1 || index > first->data + 1)
    {
        printf("\nInvalid location!!\nPlease try again");
        return;
    }

    printf("  Enter the data value to be inserted: ");
    scanf("%d", &item);

    if (index == 1)
    {

        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = item;

        if (first->next == first)
        {
            first->next = t;
            t->next = first;
            (first->data)++;
        }

        else
        {
            while (ptr->next != first->next)
            {

                ptr = ptr->next;
            }

            t->next = ptr->next;
            ptr->next = t;
            (first->data)++;
        }
    }

    else
    {
        for (i = 1; i < index; i++)
        {
            ptr = ptr->next;
        }

        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = item;
        t->next = ptr->next;
        ptr->next = t;
        (first->data)++;
    }
}

void Insert(struct Node *p)
{
    int ch;
    printf("\nENTER\n1 : Insert in sorted linked list\n2 : Insert in unsorted linked list\nCHOICE : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        Insert_sort(p);
        break;
    case 2:
        Insert_unsort(p);
        break;

    default:
        printf("\nInvalid Input");
        break;
    }
}

void Display(struct Node *q)
{
    printf("\n");
    if (first->data == 0)
    {
        printf("List is empty\n");
    }

    else
    {
        while (q != first)
        {
            printf("%d ", q->data);
            q = q->next;
        }
        printf("\n\n");
    }
}
int main()
{
    int ch;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = 0;
    first->next = first;

    do
    {
        printf("\n1. Insertion");
        printf("\n2. Deletion");
        printf("\n3. Display");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:

            Insert(first);
            break;

        case 2:

            Delete(first);
            break;

        case 3:

            Display(first->next);
            break;
        case 0:

            exit(0);
            break;
        default:
            printf("\nYou have entered a wrong input\nPlease try again\n\n");
        }
    } while (1);

    return 0;
}
