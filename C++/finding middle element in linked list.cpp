//@soumyaagr427

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends

class Solution{
    public:
  
    int getMiddle(Node *head)
    {   
        int length=0; 
        
        struct Node *fast=head; //fast pointer
        struct Node *slow=head; // slow pointer
        
        if(head!=NULL)
        {
            while(fast!=NULL  &&  fast->next!=NULL)
            {
                fast = fast->next->next; // moving 2X
                slow = slow->next;       // moving 1x
            }
        }
        
        return slow->data;
    }
};


// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        cout << ob.getMiddle(head) << endl;
    }
    return 0;
}
