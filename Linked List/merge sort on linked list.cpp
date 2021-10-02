#include <bits/stdc++.h>
//This is our linked list class
using namespace std;
class Node{
public:
    Node * Next;
    int data;
    Node(int data )
    {
        this->data=data;
        Next=NULL;
    }


};
//This function is used to take our linked lists as input from the user
Node *takeinput(){
int data;
cin>>data;
Node *head=NULL;
Node *tail=NULL;
    while(data!=-1){
        Node*newnode= new Node(data);
        if(head==NULL)
        {
            head=newnode;tail=newnode;

        }
        else{
           tail->Next=newnode;
           tail=tail->Next;

        }
        cin>>data;
    }
    return head;

}
//through this function we are going to merge our two halves of the linked list iteratively by comparing the individual elements of both the linked lists.
Node *mergel(Node*head1,Node* head2)
{
    Node *finalh;
     Node*finalt;
     if(head1->data<head2->data){
        finalh=head1;
        finalt=head1;
        head1=head1->Next;
        }
     else{
        finalh=head2;
        finalt=head2;
        head2=head2->Next;
        }
     while(head1!=NULL&&head2!=NULL){
        if(head1->data<=head2->data){
            finalt->Next=head1;
            finalt=finalt->Next;
            head1=head1->Next;

        }
        else{
            finalt->Next=head2;
           finalt=finalt->Next;
            head2=head2->Next;
        }

     }
     if(head1==NULL)
        finalt->Next=head2;
        else
        finalt->Next=head1;
return finalh;

}
//This function is used to find the mid point of a linked list
void midp(Node*head,Node **a,Node**b)
{
Node * slow = head ;
Node *fast = head->Next;
Node *temp = head;
while(fast!=NULL&&fast->Next!=NULL)
{






    fast=fast->Next->Next;
    slow=slow->Next;


}

*a=head;
*b=slow->Next;
slow->Next=NULL;


}
//this is our main merge sort function
//here what we are doing is that we first divides our whole linkedlist in two halves through the mid point function and then like the normal merge sort algorithm, first we will sort our both halves recursively and then we will merge our both halves through merge function .
void mergesort(Node**head){
    Node*fh = *head;
    Node *a;
    Node *b;
    if(fh==NULL||fh->Next==NULL)
    {
        return;
    }
midp(fh,&a,&b);
mergesort(&a);
mergesort(&b);
*head=mergel(a,b);





}


//this function is used to print the resulting linked list.
void print(Node *head){
while(head!=NULL){
cout<<head->data;
head=head->Next;}
}


int main(){




Node *head=takeinput();
mergesort(&head);
print(head);
return 0;

}
