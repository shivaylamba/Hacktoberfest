//BFS
#include <stdio.h>
#include <stdlib.h>

//Queue
struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

int isEmpty()
{
    if (front == NULL)
    {
        return 1;
    }
    return 0;
}
void enqueue(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node *t;
    if (front == NULL)
    {
        printf("Queue is empty");
    }
    {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

//Implementation of Breadth first search
void BFS(int G[][7], int start, int n)
{
    int i = start;
    int visited[7] = {0};
    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);
    while (!isEmpty())
    {
        i = dequeue();
        for (int j = 0; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}
int main()
{
    // Adjacency matrix
    int G[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };

    // Graph
    //        1
    //     /     \
    //    2       3
    //     \    /
    //       4
    //     /   \
    //    5     6
    BFS(G, 1, 7);
    return 0;
}