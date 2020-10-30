#include<stdio.h>
#include<stdlib.h>

int n=5,front=0,rear=0,q[10];

void enqueue()
{
	if(( (front==0) && (rear==n-1) ) || (front==rear+1) )
	{
		printf("the queue is full\n");
	}
	else
	{
		int k;
		printf("the element to be inserted\n");
		scanf("%d",&k);
		if(rear!=n-1)
		{
			q[rear++]=k;
		}
		else
		{
			q[rear]=k;
			rear=0;
		}
	}
}

void dequeue()
{
	if(front==rear)
	{
		printf("the queue is empty\n");
	}
	else
	{
		printf("the element removed is %d\n",q[front]);
		if(front==n-1)
		{
			front=0;
		}
		else
		{
			front++;
		}
	}
}

void print()
{
	int i;
	if(rear>front)
	{
		printf("the elements in the queue are\n");
		for(i=front;i<rear;i++)
		{
			printf("%d ",q[i]);
		}
		printf("\n");
	}
	if(rear<front)
	{
		printf("the elements in the queue are\n");
		for(i=front;i<n;i++)
		{
			printf("%d ",q[i]);
		}
		for(i=0;i<rear;i++)
		{
			printf("%d ",q[i]);
		}
		printf("\n");
	}
	if(front==rear)
	{
		printf("the queue is empty\n");
	}
}

int main()
{
	while(1)
	{
		int n;
		printf("select any one option\n1.enque\n2.deque\n3.print\n4.exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
					enqueue();
					break;
			case 2:
					dequeue();
					break;
			case 3:
					print();
					break;
			case 4:
					exit(0);						
		}
	}
}
