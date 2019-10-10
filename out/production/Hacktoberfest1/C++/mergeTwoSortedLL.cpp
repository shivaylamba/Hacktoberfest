#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
};

node *head1 = NULL, *head2 = NULL, *tail1 = NULL, *tail2 = NULL ;
node *temp1 = NULL, *temp2 = NULL, *temp = NULL;

void createNode1(int value){
    node *temp = new node;
    temp->data = value;
    if(head1==NULL){
        head1 = temp;
        tail1 = temp;
    } else {
        tail1->next = temp;
        tail1 = temp;
    }
}

void createNode2(int value){
    node *temp = new node;
    temp->data = value;
    if(head2==NULL){
        head2 = temp;
        tail2 = temp;
    } else {
        tail2->next = temp;
        tail2 = temp;
    }
}

void MoveNode(node** destRef, node** sourceRef)  {  
    node* newNode = *sourceRef;  
    assert(newNode != NULL);  
    *sourceRef = newNode->next;  
    newNode->next = *destRef;  
    *destRef = newNode;  
}  

node* SortedMerge(node* a, node* b)  {  
    node dummy;  
    node* tail = &dummy;  
    dummy.next = NULL;  
    while (1)  
    {  
        if (a == NULL) {  
            tail->next = b;  
            break;  
        }  
        else if (b == NULL)  {  
            tail->next = a;  
            break;  
        }  
        if (a->data <= b->data)  
            MoveNode(&(tail->next), &a);  
        else
            MoveNode(&(tail->next), &b);  
        tail = tail->next;  
    }  
    return(dummy.next);  
} 

void display(node *head) {
    node *temp = new node;
    temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
}

int main(){
    for(int i=1;i<3;i++){
        createNode1(i);
    }
    for(int i=1;i<6;i++){
        createNode2(i);
    }
    node * head = SortedMerge(head1, head2);
    display(head);
}