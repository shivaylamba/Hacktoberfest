#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct queue{
	int front;
	int rear;
	int q[MAX];
};

struct queue Q;

void insert(void);
void del(void);
int isEmpty(void);
int isFull(void);
void display(void);

int isFull(){
	if(Q.rear == MAX-1) return 1;
	else return 0;
}

int isEmpty(){
	if(Q.front == -1||Q.front>Q.rear) return 1;
	else return 0;
}

void insert(){
	int item;
	printf("Enter item to be inserted: ");
	scanf("%d",&item);
	printf("\n");
	if(isFull()) printf("Queue is full \n");
	else{
		if(Q.front == -1) Q.front = 0;
		Q.rear++;
		Q.q[Q.rear] = item;
	}
}

void del(){
	if(isEmpty()) printf("Queue is empty \n");
	else{
		printf("Element removed from the queue is %d \n",Q.q[Q.front]);
		Q.front++;
	}
}

void display(){
	int i=0;
	if(Q.front==-1)printf("Queue is empty \n");
	else{
		printf("Elements in the queue are: \n");
		for(i=Q.front;i<=Q.rear;i++){
			printf("%d\n",Q.q[i]);
		}
	}
}

int main(void){
	Q.front = -1;
	Q.rear = -1;
	while(1){
	int option;
	printf("Enter the option number: \n");
	printf("\t\t1.Insert\n");
	printf("\t\t2.Delete\n");
	printf("\t\t3.Display\n");
	printf("\t\t4.Exit\n");
	scanf("%d",&option);
	switch(option){
		case 1:
			insert();
			break;
		case 2:
			del();
			break;
		case 3:
			display();
			break;
		case 4:
			printf("Exiting...\n");
			exit(0);
		default:
			printf("Enter a valid option.\n");
	}
}
	return 0;
}
