//Github: https://github.com/outoftune2000
//A program to insert , delete and display elements in a linked list
#include<stdio.h>
#include<stdlib.h>
struct list{
	struct list *link;
	int data;
	};
struct list* head=NULL;
struct list *ptr,*ptr1;
//The function for allocating and inserting an element to the end of the list
allocation(){
	int data;
	struct list *temp=(struct list*)malloc(sizeof(struct list ));
	printf("Enter data to the list");
	scanf("%d",&data);
	temp->data=data;
	if (head==NULL){
		head=temp;
		temp->link=NULL;
		}
	else {
		ptr=head;
		while (ptr->link!=NULL){
			ptr1=ptr;
			ptr=ptr->link;
			}
		ptr->link=temp;
		temp->link=NULL;
		}
	}
//Function for printing the list
void PrintL(){
	ptr=head;
	if (head==NULL)
	{
		printf("LIST IS EMPTY\n");}
	else{
		while (ptr->link!=NULL){
			printf("%d -> ",ptr->data);
			ptr=ptr->link;
			}
		printf("%d -> NULL\n",ptr->data);
		}
	}
//Function for deleting list element from the end of the list
void deletedata(){
	ptr=head;
	if(head==NULL){
		printf("EMPTY LIST");
		}
	else{
		while(ptr->link!=NULL){
			ptr1=ptr;
			ptr=ptr->link;
		}
		if(ptr!=head){
			ptr1->link=NULL;
			free(ptr);
	}
		else
			head=NULL;
	}
}
void main(){
	int c;
	char ch='y';
	while(ch=='y'){
		printf("\nEnter your choice:\n 1. PRINT LIST\n 2.ENTER DATA \n 3.DELETE DATA\n 4. EXIT \n");
		scanf("%d",&c);
		switch(c)
			{
				case 1: PrintL();
					break;
				case 2:allocation();
					break;
				case 3:deletedata();
					break;
				case 4: ch='n';
					break;
				default: printf("INVALID CHOICE\n");
			}
		}
	}
