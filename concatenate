#include <iostream>
using namespace std;
struct node
{
           int data;
           node *next;
};
class circular_linked_list
{
           public:
                        node *head,*tail;
                        circular_linked_list()
                        {
                                 head=NULL;
                                 tail=NULL;
                        }
                        void insert_node(int x)
                        {
                                   node *temp=new node;
                                   temp->data=x;
                                   temp->next=NULL;
                                   if(head==NULL)
                                   {
                                              head=temp;
                                              tail=temp;
                                   }
                                   else
                                   {
                                              tail->next=temp;
                                              temp->next=head;
                                              tail=temp;
                                   }
                        }
                        node* assign_begin()
                        {
                                   node *ptr;
                                   ptr=head;
                                   return ptr;
                        }
};
node *combine(node *p,node *q)
{
           node *ptr;
           if(p==NULL)
           {
                      p=q;
                      return p;
           }
           else if(q==NULL)
           {
                      return p;
           }
           else
           {
                      ptr=p;
                      while(ptr!=NULL)
                      {
                                 ptr=ptr->next;
                      }
                      ptr->next=q;
                      while(ptr!=NULL)
                      {
                                 ptr=ptr->next;
                      }
                      ptr->next=p;
                      return ptr;
           }
}
void display(node *temp)
{
           while(temp!=NULL)
           {
                      cout<<temp->data<<" ";
                      temp=temp->next;
           }
}
int main()
{
           circular_linked_list a,b;
           node *last1,*last2,*temp;
           int n1,n2;
           cout<<"Enter the number of elements you want to enter in first linked list:";
           cin>>n1;
           for(int  i=0;i<n1;i++)
           {
                      a.insert_node(i+1);
           }
           cout<<"Enter the number of elements you want to enter in second linked list:";
           cin>>n2;
           for(int  i=0;i<n2;i++)
           {
                      b.insert_node(i+1+n1);
           }
           last1=a.assign_begin();
           last2=b.assign_begin();
           temp=combine(last1,last2);
           display(temp);
           return 0;
}
