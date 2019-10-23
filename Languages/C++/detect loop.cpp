#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
};

struct node *head = NULL, *tail = NULL;

void createNode(int value) {
    node *temp = new node;
    temp->data = value;
    if(head==NULL){
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}


bool detectLoop() {
    node *temp = new node;
    temp = head;
    unordered_set<node*> s;
    while(temp!=NULL){
        if(s.find(temp)!=s.end()){
            return true;
        }
        s.insert(temp);
        temp = temp->next;
    }
    return false;
}

void display() {
    node *temp = new node;
    temp = head;
    while(temp!=NULL){
        cout<<temp->data;
        temp = temp->next;
    }
}

int main(){
    for(int i=0;i<3;i++)
    createNode(i);
    head->next->next->next = head;
    if(detectLoop()){
        cout<<"yes";  
    } else {
        cout<<"No";
    } 
}