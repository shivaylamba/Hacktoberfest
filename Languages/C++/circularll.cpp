#include<iostream>
using namespace std;
struct node{
int data;
node * next;
node(int data)
{
    this->data=data;
    next=NULL;
}
};
node* create(){
cout<<"Enter elemets\n";
int data;
cin>>data;
node* head;
if(data!=-1)
{
    head=new node(data);
}
else{
    return NULL;
}
node *tail=head;
cin>>data;
while(data!=-1)
{
    int f=0;
    node*h=head;
    while(h!=NULL)
    {
        if(h->data==data)
        {
            f=1;
            tail->next=h;
            break;
        }
        h=h->next;
    }
    if(f==1)
        break;
    node * temp=new node(data);
    tail->next=temp;
    tail=temp;
    cin>>data;
}
return head;

}
void print(node*head)
{
    if(head==NULL)
    {
        return;
    }
    cout<<head->data<<" ";
    print(head->next);
    return;
}
void breakc(node*head)
{
    if(!head)
    {
        return;
    }
    node*hh=head;
    int f=0;
    node*h=head;
    while(h->next!=NULL)
    {
        hh=head;
        while(hh!=h)
        {
            if(hh->data==h->next->data)
            {
                f=1;
                h->next=NULL;
                break;
            }
            hh=hh->next;
        }
        if(f==1)
            break;
        h=h->next;

    }
}
int main()
{
    node * head=create();
    breakc(head);
    print(head);
}

