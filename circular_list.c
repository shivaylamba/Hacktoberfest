/* menu driven program to implement circular linked list 
   1. create a circular linked list
   2. new node in the beginning
   3. new node at the end
   4. new node after specific node
   5. new node before specific node
   6. delete node at the front
   7. delete node at the end
   8. delete the list
   9. display the linked list */
	
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *start = NULL;

struct node *create(struct node *start)
{
	start = NULL;
	struct node *new_node, *ptr;
	int num;
	printf("Enter -1 to stop.\n");
	printf("Enter data : ");
	scanf("%d",&num);
	while(num!=-1)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->data=num;
		if(start==NULL)
		{
			new_node -> next= new_node;
			start=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next !=start)
				ptr = ptr->next;
			ptr->next = new_node;
			new_node->next=start;
		}
		printf("Enter data : ");
		scanf("%d",&num);
	}
	return start;
}

int count(struct node *start)
{
	struct node *ptr;
	ptr=start;
	int count=0;
	while(ptr->next!=start)
	{
		count++;
		ptr=ptr->next;
	}
	return count+1;
}


struct node *ins_beg(struct node *start)
{
	struct node *new_node,*ptr;
	new_node=(struct node *)malloc(sizeof(struct node));
	printf("Enter the value : ");
	scanf("%d",&new_node->data);
	ptr=start;
	if(start==NULL)
	{
		new_node -> next= new_node;
		start=new_node;
		return start;
	}
	while(ptr->next!=start)
		ptr=ptr->next;
	new_node->next = start;
	ptr->next = new_node;
	start = new_node;
}

struct node *ins_last(struct node *start)
{
	struct node *new_node,*ptr;
	ptr=start;
	if(ptr==NULL)
	{
		start = ins_beg(start);
		return start;
	}
	new_node=(struct node *)malloc(sizeof(struct node));
	printf("Enter the value : ");
	scanf("%d",&new_node->data);
	while(ptr->next!=start)
		ptr=ptr->next;
	ptr->next = new_node;
	new_node->next = start;
	return start;
}

struct node *ins_pos(struct node *start,int pos,int posi)
{
	struct node *new_node,*ptr;
	ptr=start;
	int i=1;
	if(ptr==NULL)
	{		
		start = ins_beg(start);		
		return start;
	}
	if (pos>count(start))
	{
		start = ins_last(start);
		return start;
	}
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->next=start;
	printf("Enter the value : ");
	scanf("%d",&new_node->data);
	while(i<posi)
	{
		ptr=ptr->next;
		i++;		
	}
	new_node->next = ptr->next;
	ptr->next = new_node;
	return start;
}

void display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	if(ptr==NULL)
	{
		printf("The linked list is empty.\n");
		return;
	}
	printf("The linked list : ");
	do
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}while(ptr!=start);
	printf("\n");
}

struct node *del_beg(struct node *start)
{
	struct node *ptr;
	ptr = start;
	if(ptr==NULL)
	{
		printf("List Underflow.\n");
		return start;
	}
	if(ptr->next==start)
	{
		free(start);
		start=NULL;
		return start;
	}
	while(ptr->next!=start)
		ptr=ptr->next;
	ptr->next = start->next;
	free(start);
	start=ptr->next;
	return start;
}

struct node *del_end(struct node *start)
{
	struct node *ptr,*preptr;
	ptr = start;
	if(ptr==NULL)
	{
		printf("List Underflow.\n");
		return start;
	}
	if(ptr->next==start)
	{
		free(start);
		start=NULL;
		return start;
	}
	while(ptr->next!=start)
	{
		preptr = ptr;
		ptr=ptr->next;
	}
	preptr->next = ptr->next;
	free(ptr);
	return start;
}

struct node *delete(struct node *start)
{
	struct node *ptr,*preptr;
	ptr=start;
	if(ptr==NULL)
	{
		printf("List Underflow.\n");
		return start;
	}
	else if(ptr->next==start)
	{
		free(start);
		start=NULL;
		return start;
	}
	else
	{
		while(ptr->next!=start)
		{
			preptr = ptr;
			ptr=ptr->next;
			free(preptr);
		}
		free(ptr);
		start=NULL;
		return start;
	}
}

int main()
{
	printf("Enter :\n1 to create the circular list\n2 to insert a new node in the beginning\n3 to insert a new node at the end\n4 to insert a new node after a specific node\n5 to insert a new node before specific node\n6 to delete node at the front\n7 to delete node at the end\n8 to delete the circular list\n9 to display the circular linked list\n10 to exit\n");
	int pos;
	int choice;
	do
	{
		printf("Enter choice : ");	
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				start = create(start);
				break;
			case 2:
				start = ins_beg(start);
				break;
			case 3:
				start = ins_last(start);
				break;
			case 4:
				printf("Enter the position : ");
				scanf("%d",&pos);
				start = ins_pos(start,pos,pos);
				break;
			case 5:
				printf("Enter the position : ");
				scanf("%d",&pos);
				start =ins_pos(start,pos,pos-1);
				break;
			case 6:
				start = del_beg(start);
				break;
			case 7:
				start = del_end(start);
				break;
			case 8:
				start = delete(start);
				break;
			case 9:
				display(start);
				break;
			case 10:
				break;	
			default:
				printf("Wrong Input.\n");
		}
	} while(choice!=10);
}
