/*
All Basics Features of Double Linked List
@author: nmanish_0128

- creating a Double Linked list Node
- printing a Double linked list
- inserting in a element
- deleting a element
- searching a element
*/

#include <iostream>
using namespace std;
 
// class for Node
class node {
    public:
    int data;
    node* prev;
    node* next;
    node(){
        next=NULL;
        prev=NULL;
    }
};

// printing an Linked List
void print(node* head){
    node* ptr = head;
    if(head==NULL){
        cout<<"Linked List is empty"<<endl;
    }else{
        do{
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }while(ptr!=NULL);
    }
}

// inserting an element in a Linked List

//insert at head
void insertHead(node* &head,int val){
    node* new_node = new node();
    new_node->data = val;
    if(head==NULL){
        head=new_node;
        new_node->next=NULL;
    }else{
        head->prev= new_node;
        new_node->next = head;
        head=new_node;
    }
}

//insert at tail
void insertTail(node* head,int val){
    node* ptr = head;
    node* new_node = new node();
    new_node->data=val;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    new_node->prev=ptr;
    ptr->next=new_node;
}

// insert before a given val
void insertBefore(node* head,int key,int val){
    node* ptr = head;
    while(ptr->next->data!=key){
        if(ptr->next->next==NULL){
            cout<<"key not found - insertBefore key("<<key<<")"<<endl;
            return;                
        }
        ptr=ptr->next;
    }
    node* new_node= new node();
    new_node->data=val;
    ptr->next->prev=new_node;
    new_node->next=ptr->next;
    new_node->prev=ptr;
    ptr->next = new_node;
}

//insert after a given val
void insertAfter(node* head,int key,int val){
    node* ptr = head;
    while(ptr->data!=key){
        if(ptr->next==NULL){
            cout<<"key not found - insertAfter key("<<key<<")"<<endl;
            return;
        }
        ptr=ptr->next;
    }
    node* new_node= new node();
    new_node->data=val;
    ptr->next->prev=new_node;
    new_node->next=ptr->next;
    new_node->prev=ptr;
    ptr->next = new_node;
}

//delete a given element
void Delete(node* &head,int key){
    node* ptr = head;
    if(ptr->data==key){
        node* temp=ptr;
        head=ptr->next;
        head->prev=NULL;
        free(temp);
        return;
    }
    while(ptr->next->data!=key){
        if(ptr->next->next==NULL){
            cout<<"key not found - Delete key("<<key<<")"<<endl;
            return;
        }
        ptr=ptr->next;
    }
    node* temp=ptr->next;
    temp->next->prev=ptr;
    ptr->next = temp->next;
    free(temp);
}

//search a element in a Linked List
void Search(node* head,int key){
    node* ptr = head;
    while(ptr->data!=key){
        if(ptr->next==NULL){
            cout<<"key not found - search key("<<key<<")"<<endl;
            return;
        }
        ptr=ptr->next;
    }
    cout<<"key found"<<endl;
}

int main(){
    node* head=NULL;
    insertHead(head,3);
    insertHead(head,9);
    insertTail(head,8);
    insertTail(head,4);
    insertBefore(head,8,1);
    insertAfter(head,8,0);
    Delete(head,8);
    Search(head,0);
    print(head);
    return 0;
}

/*
All Basics Features of Double Linked List
@author: nmanish_0128
*/
