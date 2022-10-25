// #include<bits/stdc++.h>
// using namespace std;

// struct node{
//     int data;
//     struct node *prev;
//     struct node *next;
// };



// int main(){
//     struct node* head;
//     struct node *first= (struct node *)malloc(sizeof(struct node));
//     struct node *second= (struct node *)malloc(sizeof(struct node));
//     struct node *third= (struct node *)malloc(sizeof(struct node));
//     struct node *mid= (struct node *)malloc(sizeof(struct node));

//     first->data=1;
//     first->prev=NULL;
//     first->next=second;
    
//     second->data=2;
//     second->prev=first;
//     second->next=mid;

//     third->data=3;
//     third->prev=mid;
//     third->next=NULL;

//     mid->data=15;
//     mid->prev=second;
//     mid->next=third;

//     head=first;
//     //traversal of doubly linkedlist;
//     while(head!=NULL){
//         cout<<head->data<<endl;
//         head=head->next;
//     }

//     return 0;
// }

#include <iostream>
using namespace std;
struct Node {
   int data;
   struct Node *prev;
   struct Node *next;
};
struct Node* head = NULL;
void insert(int newdata) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->data = newdata;
   newnode->prev = NULL;
   newnode->next = head;
   if(head != NULL)
   head->prev = newnode ;
   head = newnode;
}
void display() {
   struct Node* ptr;
   ptr = head;

   while(ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}
int main() {
   insert(3);
   insert(1);
   insert(7);
   insert(2);
   insert(9);
   cout<<"The doubly linked list is: ";
   display();
   return 0;
}