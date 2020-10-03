#include <iostream>
using namespace std;

class node{
    public:
    node *next;
    int data;
    node(int d){
        next = NULL;
        data = d;
    }
};

node* insertInList(int val, node* root){
    if(root==NULL){
        node *root = new node(val);
        return root;
    }
    if(val<=root->data){
        node* cur = new node(val);
        cur->next = root;
        root = cur;
        return root;
    }
    node *temp = root;
    node* prev = NULL;
    while(temp!=NULL && temp->data<val){
        prev = temp;
        temp = temp->next;
    }
    node *cur = new node(val);
    cur->next = temp;
    prev->next = cur;
    return root;
}

node* deleteFromList(int val, node* root){
    if(root==NULL){
        cout<<"Underflow!"<<endl;
        return NULL;
    }
    if(root->data==val){
        node *temp = root;
        root = root->next;
        delete temp;
        cout<<"Deleted successfully!\n";
        return root;
    }
    node *temp = root;
    node *prev = NULL;
    while(temp!=NULL && temp->data!=val){
        prev = temp;
        //cout<<prev->data;
        temp = temp->next;
        
    }
    if(temp==NULL){
        cout<<"Value not found!"<<endl;
        return root;
    }
    prev->next = temp->next;
    delete temp;
    cout<<"Deleted successfully!\n";
    return root;
}

node *searchInLL(int val, node *root){
    if(root==NULL){
        cout<<"List is empty!"<<endl;
        return NULL;
    }
    node *temp = root;
    while(temp!=NULL and temp->data!=val){
        temp=temp->next;
    }
    if(temp==NULL){
        cout<<"Element not found!\n";
        return NULL;
    }
    return temp;
}

void printLL(node *root){
    node *temp = root;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    node *root = NULL;
    int n;
    do {
        cout<<"Enter 1 for inserting, 2 for searching & 3 for deleting an element in the list. Press 4 to print the list, and 5 to exit."<<endl;
        cin>>n;
        switch(n){
            case 1: {
                cout<<"Enter element to be inserted: ";
                int elt;
                cin>>elt;
                root = insertInList(elt, root);
                cout<<"Element inserted successfully!\n";
                break;
            }
            case 2:{
                cout<<"Enter element to be searched: ";
                int elt;
                cin>>elt;
                node *val = searchInLL(elt, root);
                if(val!=NULL){
                    cout<<elt<<" is present in list!\n";
                }
                break;
            }
            case 3:{
                int elt;
                cout<<"Enter element to be deleted: ";
                cin>>elt;
                root = deleteFromList(elt, root);
                break;
            }
            case 4:{
                cout<<"--------------LIST-------------\n";
                printLL(root);
                break;
            }
            case 5:{
                break;
            }
            default: cout<<"Invalid input!\n";
        }
    }while(n!=5);
    cout<<"Program has ended!"<<endl;
    return 0;
}
