
#include<iostream>
using namespace std;

class Node{
    public:
        int key;
        int data;
        Node *next;
//      Node *root;
        
    Node(){
        key = 0;
        data = 0;
        next = NULL;
//      root = NULL;
    }
    
    Node(int k, int d){
        key = k;
        data = d;
    }
};

class SinglyLinkedList{
    public:
        Node * head;
    
    SinglyLinkedList(){
        head = NULL;
    }
    
    SinglyLinkedList(Node * n){
        head = n;
    }
    
    // Node exists or not
    Node * nodeExists(int k){
        Node * temp = NULL;
        Node * ptr = head;
        
        while(ptr != NULL){
            if(ptr -> key == k){
                temp = ptr;
            }
            ptr = ptr -> next;
        }
        return temp;
    }
    
    // Appending node
    void appendNode(Node * n){
        
        if(nodeExists(n -> key) != NULL){
            cout<<"Node already exists in the linked list with key value : "<<n -> key<<". Append another node with different key value"<<endl;
        }
        
        else{
            if(head == NULL){
                head = n;
                cout<<"Node Appended"<<endl;
            }
            else{
                Node * ptr = head;
                while(ptr -> next != NULL){
                    ptr = ptr -> next;
                }
                ptr -> next = n;
                cout<<"Node Appended"<<endl;
            }
        }
    }
    
    void printList(){
        
        if(head == NULL){
            cout<<"No Nodes in Singly Linked List"<<endl;
        }
        
        else{
            cout<<"Singly Linked List Values : ";
            Node * temp = head;
            
            while(temp != NULL){
                cout<<"("<<temp -> key<<","<<temp -> data<<")-->"; 
                temp = temp -> next;
            }
        }
    }
};

int main(){
    SinglyLinkedList s;
    int option;
    Node* data = NULL;
    int key1, k1,data1;
    
    do{
        cout<<"1. appendNode()"<<endl;
        cout<<"6. print()"<<endl;
        
        cin>>option;
        Node * n1 = new Node();
        
        switch (option){
            case 1:
                cout<<"Append Node Operation\n Enter key and data of the Node to be Appended"<<endl;
                cin>>key1;
                cin>>data1;
                n1 -> key = key1;
                n1 -> data = data1;
                s.appendNode(n1);
                break;
            case 6:
                s.printList();
                cout<<endl;
                break;
        }   
    }while(option!=0);
    
    int odd = 0, even = 0;
    Node* ptr = data;
    while (ptr != NULL) {
 
        if (ptr->data % 2 == 0)
            even += ptr->data;
 
        else
            odd += ptr->data;
 
    }
 
    cout << "Even Sum = " << even << endl;
    cout << "Odd Sum = " << odd << endl;
    return 0;
}

