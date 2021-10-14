#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    public:
    node(int val)
    {
        data = val;
        next= NULL;
    }
    
};

class singlylinkedlist  
{
    node* head;
    public:
    //insertion at end
    void append(int val)
    {
        node* n = new node(val);
        if(head==NULL)
        {head=n;
        return;}
        node* temp= head ;
          while(temp->next!=NULL)
          {temp = temp->next;}
           temp->next=n;
    }

    //insertion at head
    void prepend(int val)
    {
      node* n = new node(val);
      n->next = head;
      head = n;
      
    }

    //print the linked list
    void show()
    {
      node* temp = head;
      while(temp!=NULL)
      {
          cout<<temp->data<<"->";
          temp = temp->next;
      }
      cout<<"NULL"<<endl;

    }

    //insertion at desired position
    void insert(int position , int val)
    {
        node * n = new node(val);
    }

};

int main()
{
    int z;
    cin >>z;
  singlylinkedlist s1;
  singlylinkedlist s2;
  s1.append(1);
  s1.prepend(2);
  s1.append(3);
  s2.append(4);
  s2.append(5);
  s2.append(6);
  s1.prepend(z);
  s1.show();
  cout<<endl;
  s2.show();

}
