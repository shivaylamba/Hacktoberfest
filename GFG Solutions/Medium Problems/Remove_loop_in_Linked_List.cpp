/*
Remove loop in Linked List
Given a linked list of N nodes such that it may contain a loop.
A loop here means that the last node of the link list is connected to the 
node at position X(1-based index). If the link list does not have any loop, X=0.
Remove the loop from the linked list, if it is present, i.e. unlink the last node 
which is forming the loop.
Example 1:
Input:
N = 3
value[] = {1,3,4}
X = 2
Output: 1
Explanation: The link list looks like
1 -> 3 -> 4
     ^    |
     |____|    
A loop is present. If you remove it 
successfully, the answer will be 1. 
Example 2:
Input:
N = 4
value[] = {1,8,3,4}
X = 0
Output: 1
Explanation: The Linked list does not 
contains any loop. 
Example 3:
Input:
N = 4
value[] = {1,2,3,4}
X = 1
Output: 1
Explanation: The link list looks like 
1 -> 2 -> 3 -> 4
^              |
|______________|
A loop is present. 
If you remove it successfully, 
the answer will be 1. 
Your Task:
You don't need to read input or print anything. Your task is to complete the function removeLoop() which takes the head of the linked list as the input parameter. Simply remove the loop in the list (if present) without disconnecting any nodes from the list.
Note: The generated output will be 1 if your submitted code is correct.
Expected time complexity: O(N)
Expected auxiliary space: O(1)
Constraints:
1 ≤ N ≤ 10^4
*/
//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

bool notOriginal(Node *head, unordered_map<Node *, int>&myMap){
    
    while(head){
        if(myMap.find(head)==myMap.end()) return true;
        if(myMap[head] != (head->data)) return true;
        
        head=head->next;
    }
}




// } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    bool floydDetectLoop(Node* head){
        Node* slow = head , * fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                return 1;
            }
        }
        return 0;
    }
    
    Node* getStartingNode(Node* head){
          map<Node*,bool> visited;
          if(floydDetectLoop(head)==0){
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
    
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node* loop = getStartingNode(head);
        if(loop==nullptr){
            return ;
        }
        Node* temp = loop;
        while(temp->next!=loop){
            temp = temp->next;
        }
        temp->next=nullptr;      
    }
};
//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unordered_map<Node *, int>myMap;        
        int n, num;
        cin>>n;        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);        
        myMap[head]=num;        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
            myMap[tail]=num;
        }  
        int pos;
        cin>> pos;
        loopHere(head,tail,pos); 
        Solution ob;
        ob.removeLoop(head);
        if( isLoop(head) || length(head)!=n || notOriginal(head, myMap))
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}
// } Driver Code Ends