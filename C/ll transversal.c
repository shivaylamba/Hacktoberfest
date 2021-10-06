#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkedlisttraversal(struct Node *ptr){
    while(ptr!=NULL){
        cout<<"Elements :"<<ptr->data<<endl;
        ptr=ptr->next;
    }
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));
    head->data=44;
    head->next=second;
    second->data=22;
    second->next=third;
    third->data=33;
    third->next=fourth;
    fourth->data=11;
    fourth->next=NULL;
    linkedlisttraversal(head);
    return 0;
}


