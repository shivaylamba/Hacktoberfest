#include<stdio.h>
#include<stdlib.h>

typedef struct linkedlist
{
	int data;
	struct linkedlist *next;
}node;

node* insert(node*);
node* del(node*);
void display(node*);
node* insert(node* last)
{
	node *curr=last;
	node *temp;
	temp=(node*)malloc(sizeof(node));
	
	printf("enter a number : ");
	scanf("%d",&temp->data);
	if(last==NULL)
	{
		temp->next=temp;
		last=temp;
	}
	else
	{
		temp->next=last->next;
		last->next=temp;
	}
	return last;
}

node* del(node* last)
{
	node *curr;
	if(last==NULL)
	{
		printf("already empty !!");
	}
	if(last->next==last)
	{
		printf("%d is deleted",last->data);
		return NULL;
	}
	else
	{
		curr=last->next;
		printf("%d is deleted",curr->data);
		last->next=curr->next;
	}
	return last;
}

void display(node* last)
{
	node *curr;
	if(last==NULL)
	{
		printf("fill me");
	}
	else
	{
		printf("%d ",last->next->data);
		curr=last->next->next;
		while(curr!=last->next)
		{
			printf("%d ",curr->data);
			curr=curr->next;
		}
	}
}

main()
{
	node *last=NULL;
	int ch;
	
	do
	{
		printf("\n1.insert\n2.del\n3.display\n4.exit\n");
		printf("enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
				last=insert(last);
				break;
			case 2:
				last=del(last);
				break;
			case 3: 
				display(last);
				break;
			case 4: 
				exit(0);
			default: 
				printf("please enter a valid choice");
				break;
		}
	}while(ch>=1||ch<=4);
}
