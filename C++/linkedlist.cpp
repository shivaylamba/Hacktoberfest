#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void traversal(struct node *ptr){
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
//case 1:
struct node * insertAtFirst(struct node *head, int data){
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    return ptr;     //we have to always return head, but here ptr is the new head.
}
// case 2:
struct node * insertAtIndex(struct node *head, int data, int index){
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p =head;
    ptr->data=data;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
//case 3:
struct node * insertAtEnd(struct node *head, int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p=head;
    ptr->data=data;
    while(p->next!=NULL){
        p=p->next;
    }
    ptr->next=NULL;
    p->next=ptr;
    return head;
}

//deleting a node by its given value:
struct node*deleteByValue(struct node *head, int value){
    struct node *p=head;
    struct node *q=head->next;  //note q pointer is just a step forward to p pointer.
    while(q->data!=value &&q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data==value){
        p->next=q->next;
        free(q);
    }
    return head;
}
int main(){
    struct node *head = (struct node* )malloc(sizeof(struct node));
    cout<<"Enter the data of head node: ";
    cin>>head->data;
    head->next=NULL;
    int n=0;
    int data;
    while(n!=6){
        cout<<"\nEnter the choices:\n 1. to insert element at end\n 2. to insert at beginning\n 3. Index at which u want to insert\n 4. traversal\n 5. deletion\n 6. exit"<<endl;
        cin>>n;
        switch(n){
            case 1:
                cout<<"Enter the element u want to insert at end: ";
                cin>>data;
                head=insertAtEnd(head,data);
                break;
            case 2:
                cout<<"Enter the element u want to insert at beginning: ";
                cin>>data;
                head=insertAtFirst(head, data);
                break;
            case 3:
                cout<<"Enter the index at which u want to insert: ";
                int index;
                cin>>index;
                cout<<"Enter the data which u want to insert: ";
                cin>>data;
                head=insertAtIndex(head, data, index);
                break;
            case 4:
                cout<<"Linked list: "<<endl;
                traversal(head);
                break;
            case 5:
                cout<<"Enter the element u want to delete: ";
                cin>>data;
                head=deleteByValue(head, data);
                break;
        }
    }
    return 0;
}