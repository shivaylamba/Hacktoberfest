/*
Find the Sum of Last N nodes of the Linked List
Given a single linked list of size N, calculate the sum of the last M nodes.

Example 1:

Input:
N = 6, M = 3
5 9 6 3 4 10
Output:
17
Explanation:
Sum of last three nodes in the linked list is 3 + 4 + 10 = 17.
Example 2:

Input:
N = 2,  M = 2
1 2
Output:
3
Explanation:
Sum of last two nodes in the linked list is 2 + 1 = 3.
Your Task:
You don't need to read input or print anything. Your task is to complete the function sumOfLastN_Nodes(), which takes two arguments as input, the reference pointer to the head of the linked list and the integer N. Return an Integer which is the sum of last M nodes.

Constraints:
1<=T<=100
1<=N<=M<=1000
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
};

void append(struct Node** headRef, int newData)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *last = *headRef;
	new_node->data = newData;
	new_node->next = NULL;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}

int sumOfLastN_Nodes(struct Node* head, int n);

// Driver program to test above
int main()
{
    int t;
    cin>>t;
    while(t--){
        struct Node* head = NULL;
        int n,m,tmp;
        cin>>m>>n;
        while(m--){
            cin>>tmp;
            append(&head, tmp);
        }
        cout<<sumOfLastN_Nodes(head, n)<<endl;
    }
	return 0;
}

// } Driver Code Ends


/*Structure of the node of the linled list is as

struct Node {
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
};
*/
// your task is to complete this function 
// function should return sum of last n nodes
int getLength(struct Node* head){
    int count =0;
    if(head==nullptr){
        return count ;
    }
    while(head!=nullptr){
        count++;
        head=head->next;
    }
    return count;
}
// Optimized Approach
// Time Complexity O(n);
// Space Complexity O(1);
int sumOfLastN_Nodes(struct Node* head, int n)
{
      // Code here
      int len = getLength(head);
      int k = len - n;
      Node* temp = head ; 
      int i = 0 ,ans=0;
      while(i<k && head!=nullptr){
          head = head->next;
          i++;
      }
      while(head!=nullptr){
          ans += head->data;
          head=head->next;
      }
      return ans;
}