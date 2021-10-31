
#include <iostream>
using namespace std;
struct node{
  int data;
  struct node *prev,*next;
};
struct node *head,*tail;
void create(int x){
    struct node *new_node=(struct node*)malloc(sizeof(node*));
    new_node->data=x;
    if(head==NULL){
        head=tail=new_node;
    }else{
        tail->next=new_node;
      //  new_node->prev=tail;
        tail=new_node;
    }
    
}
void sort_list(node *head){
    struct node *curr=NULL,*index=NULL;
    int temp;
    for(curr=head;curr->next!=NULL;curr=curr->next){
        for(index=curr->next;index->next!=NULL;index=index->next){
            if(curr->data>index->data){
                temp=curr->data;
                curr->data=index->data;
                index->data=temp;
            }
        }
    }
}

void print(node *head){
    struct node *temp=head;
    cout<<"Doubly linked list:";
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}
int main() {
    int n,i;
    cout<<"enter n"<<endl;
    cin>>n;
    int arr[n];
        cout<<"enter data"<<endl;
        for(i=0;i<n;i++){
            cin>>arr[i];
            create(arr[i]);
        }
        sort_list(head);
        print(head);

    return 0;
}
