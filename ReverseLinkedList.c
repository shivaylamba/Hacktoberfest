
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
void  Listtraversal(struct node *ptr)
{
    while(ptr!=NULL)
    {
     printf("%d  ",ptr->data);
         ptr=ptr->next;
    }
       
}
 
 void function1(struct node* head)
{
  if(head == NULL)
    return;
  
  function1(head->next); 
  printf("%d  ", head->data);
}

int main()
{
struct node *head;
struct node *second;
struct node *third;
struct node *fourth;
struct node *fifth;

head= (struct node *)malloc(sizeof(struct node*));
second=(struct node*)malloc(sizeof(struct node*));
third=(struct node*)malloc(sizeof(struct node *));
fourth=(struct node *)malloc(sizeof(struct node *));
fifth=(struct node*)malloc(sizeof(struct node));
head->data=7; 
head->next=second;
 second->data=3;
second->next=third;
third->data=8;
third->next=fourth;
fourth->data=9;
fourth->next=fifth; 
fifth->data=1;
fifth->next=NULL;
Listtraversal(head);

printf(" \nthe reverse Linked List is - \n");
function1(head); 

}