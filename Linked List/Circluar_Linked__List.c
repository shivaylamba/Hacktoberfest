// circular linked list in cpp
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
node *head=NULL, *tail=NULL, *temp=NULL;
void create(){
    int x;
    cin>>x;
    node *n=new node(x);
    if(head==NULL){
        head=tail=temp=n;
        n->next=head;
    }
    else{
        temp->next=n;
        n->next=head;
        tail=n;
        temp=n;
    }
}
void display(){
    node *temp=head;
    while(temp->next!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<" ";
}
void insertend(){
     int x;
    cin>>x;
    node *n=new node(x);
    if(head==NULL){
        head=tail=temp=n;
        n->next=head;
    }
    else{
        tail->next=n;
        n->next=head;
    }
}
void insertbegin(){
     int x;
    cin>>x;
    node *n=new node(x);
    if(head==NULL){
        head=tail=temp=n;
        n->next=head;
    }
    else{
        n->next=head;
        tail->next=n;
        head=n;
    }
}
void insertatp(){
    int x,position;
    cin>>position>>x;
    node *n=new node(x);
    node *temp=head;
    int i=0;
    while(i+1<position-1){
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;
}
void deletebegin(){
    node *temp=head;
    head=head->next;
    tail->next=head;
    delete(temp);
}
void deleteend(){
    node *temp=head;
    while(temp->next!=tail){
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=head;
    tail=temp;
}
void reverse(){
    node *current=head;
    node *prev=NULL,*next=NULL;
    do{
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    while(current!=head);
    head->next=prev;
    head=prev;
}
int main(){
    create();
    create();
    create();
    insertbegin();
    insertend();
    insertatp();
    deletebegin();
    deletend();
    reverse();
    display();
}

//hope you like it

Circular Linked List
#include <stdio.h>
#include <stdlib.h>
struct Node
{
 int data;
 struct Node *next;
}*Head;
void create(int A[],int n)
{
 int i;
 struct Node *t,*last;
 Head=(struct Node*)malloc(sizeof(struct Node));
 Head->data=A[0];
 Head->next=Head;
 last=Head;

 for(i=1;i<n;i++)
 {
 t=(struct Node*)malloc(sizeof(struct Node));
 t->data=A[i];
 t->next=last->next;
 last->next=t;
 last=t;
 }
}
void Display(struct Node *h)
{
 do
 {
 printf("%d ",h->data);
 h=h->next;
 }while(h!=Head);
 printf("\n");
}
void RDisplay(struct Node *h)
{
 static int flag=0;
 if(h!=Head || flag==0)
 {
 flag=1;
 printf("%d ",h->data);
 RDisplay(h->next);
 }
 flag=0;
}
int Length(struct Node *p)
{
 int len=0;
 do
 {
 len++;
 p=p->next;

 }while(p!=Head);
 return len;
}
void Insert(struct Node *p,int index, int x)
{
 struct Node *t;
 int i;
 if(index<0 || index > Length(p))
 return;

 if(index==0)
 {
 t=(struct Node *)malloc(sizeof(struct Node));
 t->data=x;
 if(Head==NULL)
 {
 Head=t;
 Head->next=Head;
 }
 else
 {
 while(p->next!=Head)p=p->next;
 p->next=t;
 t->next=Head;
 Head=t;
 }

 }
 else
 {
 for(i=0;i<index-1;i++)p=p->next;
 t=(struct Node *)malloc(sizeof(struct Node));
 t->data=x;
 t->next=p->next;
 p->next=t;

 }
}
int Delete(struct Node *p,int index)
{
 struct Node *q;
 int i,x;

 if(index <0 || index >Length(Head))
 return -1;
 if(index==1)
 {
 while(p->next!=Head)p=p->next;
 x=Head->data;
 if(Head==p)
 {
 free(Head);
 Head=NULL;
 }
 else
 {
 p->next=Head->next;
 free(Head);
 Head=p->next;
 }
 }
 else
 {
 for(i=0;i<index-2;i++)
 p=p->next;
 q=p->next;
 p->next=q->next;
 x=q->data;
 free(q);
 }
 return x;
}
int main()
{
 int A[]={2,3,4,5,6};
 create(A,5);

 Delete(Head,8);

 RDisplay(Head);
 return 0;
}
