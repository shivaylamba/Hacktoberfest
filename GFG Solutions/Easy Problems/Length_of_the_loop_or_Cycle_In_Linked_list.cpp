#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    // Contructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    // destructor
    ~Node(){
        int value = this->data;
        // Memroy Free
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memroy is free for node with data: "<<value<<endl;
     }
};
// Traversal of the Singly Linked List
//   Time Complexity O(n)
void LinkedListTraversal(Node* head){
  if(head==nullptr){
    cout<<"Nothing to Traverse"<<endl;
    return;
  }
  Node* temp = head;
  while(temp!=nullptr){
  cout<<temp->data<<"->";
  temp=temp->next;
  }
  cout<<"NULL"<<endl;
}
//----------------------------Insertion at the end or tail -----------------------------//
// Time Complexity: O(n)
// Auxiliary Space: O(1)
void InsertAtTail(Node* &head,int n){
    Node* node  = new Node(n);
    if(head==NULL){
        head = node;
    }
    else{
        Node * temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = node;
        node->next=NULL;
    }
}
// Used Make Cycle Function 
void makeCycle(Node* &head,int k){
    Node* temp = head;
    Node* startNode ; 
    int i=1;
    while(temp->next!=nullptr){ // stop at last node
        if(i==k){
            startNode=temp; // go to position and make the startNode
        }
        temp = temp->next; // traverse the temp pointer
        i++;
    }
    temp->next=startNode; // connect the last node to the startNode to Create Cycle
}
//-------------------------Detection of Cycle--------------------------------------------//
// Detect loop in a linked list using Hashing (using map):
// Time complexity: O(N), Only one traversal of the loop is needed.
// Auxiliary Space: O(N), N is the space required to store the value in the hashmap.
int detectCycleByMap(Node* head){
    if(head==nullptr){
        return 0;
    }
    map<Node*,bool> visited;
    Node * temp = head;
    while(temp!=nullptr){
        if(visited[temp]==1){
            // return 1;
            return temp->data; // we can also returned the first element where cycl start
        }
        visited[temp] =1;
        temp = temp->next;
    }
    return 0;
}
Node* floydDetectLoop(Node* head) {
    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;
    while(slow != NULL && fast !=NULL) {
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }
        slow = slow -> next;
        if(slow == fast) {
            return slow;
        }
    }
    return NULL;
}
// With the Help of FloydCycle Detection Algorithm
Node* getStartingNode(Node* head) {
    if(head == NULL) 
        return NULL;

    Node* intersection = floydDetectLoop(head);
    
    if(intersection == NULL)
        return NULL;
    
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  

    return slow;
}
// Without the Help of FloydCycle Detection Algorithm
Node* getStartingNode2(Node* head){
    map<Node*,bool> visited;
    if(head==nullptr){
        return nullptr;
    }
    Node* temp = head;
    while(temp!=nullptr){
        if(visited[temp]==1){
            return temp;
        }
        visited[temp]=1;
        temp = temp->next;
    }
    return nullptr;
}
//-----------------length of loop------------------------------------//
int countNodes(struct Node* n)
{
    int res = 1;
    struct Node* temp = n;
    while (temp->next != n) {
        res++;
        temp = temp->next;
    }
    return res;
}
 
/* This function detects and counts loop
   nodes in the list. If loop is not there
   then returns 0 */
int countNodesinLoop(struct Node* list)
{
   unordered_map<Node*,bool> m;
   Node* temp = list;
   while(temp!=nullptr){
       if(m[temp]==1){
           return countNodes(temp);
       }
       m[temp]=1;
       temp=temp->next;
   }
   return 0;
}
//-------------------------Removal of Cycle or Loop in the Linked List--------------------------------------------//
Node *removeLoop(Node *head)
{
    if( head == NULL)
        return NULL;

    Node* startOfLoop = getStartingNode2(head);
    
    if(startOfLoop == NULL)
        return head;
    
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    } 

    temp -> next = NULL;
    return head;
}
//------------Find length of loop/cycle in given Linked List--------//
int countNodes(Node* n)
{
    int res = 1;
    Node* temp = n;
    while (temp->next != n) {
        res++;
        temp = temp->next;
    }
    return res;
}
 
/* This function detects and counts loop
   nodes in the list. If loop is not there
   then returns 0 */
int countNodesinLoop(Node* head)
{
     Node *slow = head, *fast = head;
 
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
 
        /* If slow_p and fast_p meet at
        some point then there is a loop */
        if (slow == fast)
            return countNodes(slow);
    }
    /* Return 0 to indicate that
       there is no loop*/
    return 0;
}
int main(){
    Node* head=nullptr;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    InsertAtTail(head,5);
    InsertAtTail(head,6);
    InsertAtTail(head,7);
    InsertAtTail(head,9);
    makeCycle(head,4);
    // LinkedListTraversal(head);
    if(floydDetectLoop(head)==nullptr){
        cout<<"No loop in the LinkedList"<<endl;
    }
    else{
        cout<<"loop present in the LinkedList"<<endl;
    }
cout<<"Detect loop in a linked list using Hashing(map):"<<endl;
Node* loop = getStartingNode(head);
cout<<"Node where the Loop is Started : "<<loop->data<<endl;
cout<<" length of loop/cycle in given Linked List : "<<countNodesinLoop(head)<<endl;
removeLoop(head);
    if(floydDetectLoop(head)==nullptr){
        cout<<"No loop in the LinkedList"<<endl;
    }
    else{
        cout<<"loop present in the LinkedList"<<endl;
    }
LinkedListTraversal(head);
cout<<" length of loop/cycle in given Linked List : "<<countNodesinLoop(head)<<endl;
return 0 ;
}