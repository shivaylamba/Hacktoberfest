#include<iostream>
using namespace std;

class node
{
  public:
    int data;
    node* next;   // a pointer'next' to store the address of a node
    node(int val)  // Constructor declaration. 'val' is given by the user
    {
       data=val;
       next=NULL;
    }
};
bool search(node* head,int target)
{
    node* temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==target)
      {   
        cout<<target<<" found : ) \n ";
        return true;
      }
      temp=temp->next; //to move ahead to the next links
    }
    cout<<target<<" not found :(\n";
    return false;
}

void insertathead(node* &head,int val)
{
    node* N=new node(val);  // a pointer N to point to a new node that will be inserted
    N->next=head;  // N will point to that node where head is pointing to
    head=N;
}
void insertattail(node* &head,int val)
{
    node*N = new node(val);
    node*temp=head;
    if(head==NULL)
     {
        head=N;
        return;
     } 
    else
     {
       while(temp->next!=NULL)   // We traverse to find the last node
        {
          temp=temp->next;
        }
      temp->next=N;
     }
}
void deletion(node* &head, int target)
{
  node  *temp=head;
  if(head==NULL) // if no node is present
  {
    cout<<"NO node in the list ! \n";
    return;
  }
  if(head->next==NULL && head->data==target) // If only one node is present
  {
    cout<<target<<" deleted \n";
    delete temp;
    return;
  }
  
  while(temp->next->data!=target) // we need to stop at the node just before the node to be deleted.
  {
    temp=temp->next;
  }
  if(temp==NULL)
  {
    cout<<target<<" not found. \n";
    return;
  }
  // now we are at the node thats just before the node to be deleted
  node *todelete= temp->next;
  temp->next=temp->next->next;
  cout<<target<<" deleted ! \n";
  delete todelete;
}
void display(node* head)
{
  if(head==NULL)
  {
    cout<<" No node to display ! The list is empty \n";
    return;
  }
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
  node* head=NULL;
  cout<<"Insertion at tail: \n";
  insertattail(head,5);
  insertattail(head,6);
  insertattail(head,7);
  display(head);
  search(head,10);
  
  insertathead(head,4);
  insertathead(head,3);
  insertathead(head,2);
  insertathead(head,1); 
  cout<<"Insertion at head:\n";
  display(head);
  search(head,2);
  deletion(head,3);
  display(head);
  deletion(head,1);
 deletion(head,2);
 deletion(head,4);
 deletion(head,5);
 deletion(head,6);
 deletion(head,7);
 display(head);

  
}