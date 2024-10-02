/*
Remove duplicates from an unsorted linked list
Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List. When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.

Example 1:

Input:
N = 4
value[] = {5,2,2,4}
Output: 5 2 4
Explanation:Given linked list elements are
5->2->2->4, in which 2 is repeated only.
So, we will delete the extra repeated
elements 2 from the linked list and the
resultant linked list will contain 5->2->4
Example 2:

Input:
N = 5
value[] = {2,2,2,2,2}
Output: 2
Explanation:Given linked list elements are
2->2->2->2->2, in which 2 is repeated. So,
we will delete the extra repeated elements
2 from the linked list and the resultant
linked list will contain only 2.
Your Task:
You have to complete the method removeDuplicates() which takes 1 argument: the head of the linked list.  Your function should return a pointer to a linked list with no duplicate element.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= size of linked lists <= 106
0 <= numbers in list <= 104
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution
{
    public:
 // Optimized Approach // Set
// Time Complexity O(n)
// Space Complexity O(n)
    Node * removeDuplicates(Node* head){
        Node* curr= head;
        Node* prev = nullptr;
        set<int> set;
        while(curr!=nullptr){
            if(set.count(curr->data)){
                prev->next = curr->next;
            }
            else{
                prev=curr;
                set.insert(curr->data);
            }
            curr=curr->next;
        }
        return head;
    }
 // Optimized Approach // unoredered_Set
// Time Complexity O(n)
// Space Complexity O(n)
    Node * removeDuplicates1(Node* head){
        Node* curr= head;
        Node* prev = nullptr;
        unordered_set<int> set;
        while(curr!=nullptr){
            if(set.find(curr->data)!=set.end()){
                prev->next = curr->next;
            }
            else{
                prev=curr;
                set.insert(curr->data);
            }
            curr=curr->next;
        }
        return head;
    }
 //Least Optimized Approach 
// Time Complexity O(n^2)
// Space Complexity O(1)
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates2( Node *head) 
    {
     // your code goes here
     Node* curr = head;
     while(curr!=nullptr ){
         Node* temp = curr->next;
         while(temp!=nullptr){
             if(temp->data==curr->data){
                 curr->next= temp->next->next;
             }
             else{
                 temp = temp->next;
             }
         }
       curr=curr->next;
         
     }
     return head;
        
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}
// } Driver Code Ends