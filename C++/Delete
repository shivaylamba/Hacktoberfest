#include<iostream>
using namespace std;
struct node
{
           int data;
           node *next;
};
node* insert_end(node *start,int x)
{
           node *temp=new node;
           temp->data=x;
           temp->next=NULL;
           if(start==NULL)
           {
                      start=temp;
                      start->next=start;
                      return start;
           }
           node *ptr=start;
           while(ptr->next!=start)
           {
                      ptr=ptr->next;
           }
           ptr->next=temp;
           temp->next=start;
           return start;
}
void display(node *start)
{
           node *ptr=start;
           while(ptr->next!=start)
           {
                      cout<<ptr->data<<" ";
                      ptr=ptr->next;
           }
           cout<<ptr->data;
}
node *delete_front(node *start)
{
           node *temp=start;
           node *ptr=start;
           while(ptr->next!=start)
           {
                      ptr=ptr->next;
           }
           ptr->next=start->next;
           start=start->next;
           free(temp);
           return start;
}
node *delete_last(node *start)
{
           node *ptr1=start;
           node *ptr2=start;
           while(ptr2->next!=start)
           {
                      ptr1=ptr2;
                      ptr2=ptr2->next;
           }
           ptr1->next=start;
           free(ptr2);
           return start;
}
node *delete_random(node *start,int pos)
{
           node *temp=start;
           node *ptr;
           for(int i=1;i<pos;i++)
           {
                      ptr=temp;
                      temp=temp->next;
           }
           ptr->next=temp->next;
           free(temp);
           return start;
}
int main()
{
           node *sample=NULL;
           sample=insert_end(sample,10);
           sample=insert_end(sample,20);
           sample=insert_end(sample,30);
           sample=insert_end(sample,40);
           sample=insert_end(sample,50);
           sample=insert_end(sample,60);
           cout<<"List:";
           display(sample);
           sample=delete_front(sample);
           cout<<"\nList:";
           display(sample);
           sample=delete_last(sample);
           cout<<"\nList:";
           display(sample);
           sample=delete_random(sample,2);
           cout<<"\nList:";
           display(sample);
           return 0;
}
