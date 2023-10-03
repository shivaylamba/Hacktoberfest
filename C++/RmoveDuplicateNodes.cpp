// Remove duplicates from an sorted linked list


#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(){
        int data = data;
        Node* next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
Node* print(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void removeduplicates(Node* head){
    if(head == NULL || head ->next == NULL){
        return;
    }
    Node* curr = head;
    while(curr != NULL){
        if((curr->next == NULL)&& (curr->data ==curr->next->data)){
        //    Node* temp = curr->next;
            curr->next == curr->next->next;
          //  temp->next = NULL;
            //delete temp;
        }
        else{
            curr = curr->next;
        }
    }
    
}
int main(){
    Node* head = new Node(10);
    Node* first = new Node(20);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(40);
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    
    print(head);
    removeduplicates(head);
    print(head);
    
 
    return 0;
    
}