#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* link;
    int data;
};
Node* insert(Node* head, int val){
    Node* curr=head;
    while(curr->link!=NULL){
        curr=curr->link;
    }
    Node* temp=new Node();
    temp->data=val;
    temp->link=NULL;
    curr->link=temp;
    return head;
}
void print(Node* head){
    Node* curr=head->link;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->link;
    }
    cout<<endl;
}
int main(){
    Node* head=new Node();
    cout<<head->link;
    cout<<head->data;
    /*int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        insert(head,a);
    }
    print(head);
    */

}