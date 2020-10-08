#include <stdio.h>
#include <stdlib.h>

//max refers to the maximum time limit allowed for each process
const int max = 5;
//"p" is the no. of processes------> length of queue
int p;

//pop fun pops the front element and modifies the front
int pop(int *queue, int *front)
{
    int temp = queue[*front];
    *front = (*front + 1) % p;
    return temp;
}

//push fun push the residue process
void push(int *queue, int *rear, int val)
{
    *rear = (*rear + 1) % p;
    queue[*rear] = val;
}

int main()
{

    //"i" --> loop counter
    int i, front, rear;
    printf("\nEnnter the array length\nlength : ");
    scanf("%d", &p);

    //dynamically creating the queue(array)
    int *queue = (int *)malloc(100 * sizeof(int));

    //taking the input of the queue
    printf("\nEnter the time");
    for (i = 0; i < p; ++i)
    {
        printf("\n Enter time: ");
        scanf("%d", (queue + i));
    }

    //since the length of
    front = 0;
    rear = p - 1;
    i = 0;
    while (front != rear)
    {

        //if the time is less than or equal to time limit then pop the element
        if (queue[front] <= max)
        {
            printf("\nP%d -> %d", i, pop(queue, &front));
            i = (i + 1) % p;
        }

        //if the time is greater than time limit than pop the time from front and add it to the rear
        else if (queue[front] > max)
        {
            printf("\nP%d -> %d", i, max);
            queue[front] = queue[front] - max;
            int val = pop(queue, &front);
            i = (i + 1) % p;
            push(queue, &rear, val);
        }
    }

    //when the controller will come out of the while loop the last process(or time element) will still be left so we have to print it separately
    printf("\nP%d -> %d", i, queue[front]);

    return 0;
}
