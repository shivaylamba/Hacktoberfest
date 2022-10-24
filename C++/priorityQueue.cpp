#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// structure for the priority queue
struct PQueue
{
    char n[4];
    int pr;
    struct PQueue *next;
};
// global variables for the priority queue
struct PQueue *front = NULL;
struct PQueue *rear = NULL;
int size = 0;
// function to insert a node into the priority queue
void enqueue(char n[], int pr)
{
    struct PQueue *newNode = (struct PQueue *)malloc(sizeof(struct
                                                            PQueue));
    strcpy(newNode->n, n);
    newNode->pr = pr;
    newNode->next = NULL;
    // first element
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    // insert at begin
    else if (front->pr > pr)
    {
        newNode->next = front;
        front = newNode;
    }
    // general case
    else
    {
        struct PQueue *p = front;
        struct PQueue *q = NULL;
        while (p != NULL && pr >= p->pr)
        {
            q = p;
            p = p->next;
        }
        newNode->next = p;
        q->next = newNode;
        if (p == NULL)
            rear = newNode;
    }
    size++;
}
// function to remove a node from the priority queue
char *dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return NULL;
    }
    struct PQueue *ptr = front;
    // variable for returning the data
    char *n = (char *)malloc(sizeof(char) * 4);
    strcpy(n, ptr->n);
    front = front->next;
    size--;
    free(ptr);
    return n;
}
// function to get front and rear nodes of the priority queue
void frontAndRear()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        printf("Front element is %s\n", front->n);
        printf("Rear element is %s\n", rear->n);
    }
}
// function to check if the priority queue is empty
int isEmpty()
{
    if (front == NULL)
        return 1;
    else
        return 0;
}
// function to get the size of the priority queue
int totalElements()
{
    return size;
}
// function to print the priority queue
void display()
{
    struct PQueue *p = front;
    if (p == NULL)
    {
        printf("\nQueue is empty");
        return;
    }
    printf("\nQueue is : ");
    while (p != NULL)
    {
        printf("[ %s | %d ] --> ", p->n, p->pr);
        p = p->next;
    }
    printf("NULL\n");
}
int main()
{
    int choice = 0;
    char element[4];
    int priority;
    printf("20BCS059 Ijlal Ahmad\n");
    while (choice != 7)
    {
        printf("\n========= MENU =======");
        printf("\n1- Enqueue");
        printf("\n2- Dequeue");
        printf("\n3- Front and Rear");
        printf("\n4- IsEmpty");
        printf("\n5- Total No of Elements");
        printf("\n6- Display");
        printf("\n7- Exit");
        printf("\n=======================\n");
        printf("\nEnter Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter Element:");
            scanf("%s", element);
            printf("Enter Priority:");
            scanf("%d", &priority);
            enqueue(element, priority);
            display();
            break;
        case 2:
            printf("\nDequeued Element: %s\n", dequeue());
            display();
            break;
        case 3:
            frontAndRear();
            break;
        case 4:
            if (isEmpty() == 1)
                printf("\nQueue is empty\n");
            else
                printf("\nQueue is not empty\n");
            break;
        case 5:
            printf("\nTotal No of Elements : %d\n", totalElements());
            break;
        case 6:
            display();
            break;
        case 7:
            break;
        default:
            printf("\nInvalid Choice\n");
            break;
        }
    }
}