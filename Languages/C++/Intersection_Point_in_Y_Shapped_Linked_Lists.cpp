// C++ program to get intersection point of two linked list 
#include <bits/stdc++.h> 
using namespace std; 
  
class Node { 
public: 
    int data; 
    Node* next; 
}; 
  

int intersectPoint(Node* head1, Node* head2)
{
    Node* ptr1;
    Node* ptr2;
    int c1=0,c2=0;
    for(ptr1=head1;ptr1;ptr1=ptr1->next)
    c1++;
    for(ptr2=head2;ptr2;ptr2=ptr2->next)
    c2++;
    int d=abs(c1-c2);
    ptr1=head1;
    ptr2=head2;
    if(c1>c2)
    {
        ptr1=head1;
        while(d--)
        {
            ptr1=ptr1->next;
        }
    }
    else
    {
         ptr2=head2;
        while(d--)
        {
            ptr2=ptr2->next;
        }
    }
    
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1==ptr2)
        return ptr1->data;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}

// Driver Code 
int main() 
{ 
    /*  
        Create two linked lists  
      
        1st 3->6->9->15->30  
        2nd 10->15->30  
      
        15 is the intersection point  
    */
  
    Node* newNode; 
  
    // Addition of new nodes 
    Node* head1 = new Node(); 
    head1->data = 10; 
  
    Node* head2 = new Node(); 
    head2->data = 3; 
  
    newNode = new Node(); 
    newNode->data = 6; 
    head2->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 9; 
    head2->next->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 15; 
    head1->next = newNode; 
    head2->next->next->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 30; 
    head1->next->next = newNode; 
  
    head1->next->next->next = NULL; 
  
    cout << "The node of intersection is " << intersectPoint(head1, head2); 
} 