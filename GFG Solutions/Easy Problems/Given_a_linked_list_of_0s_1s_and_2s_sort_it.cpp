/*
Given a linked list of 0s, 1s and 2s, sort it
Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. 
The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate 
to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.
Example 1:
Input:
N = 8
value[] = {1,2,2,1,2,0,2,2}
Output: 0 1 1 2 2 2 2 2
Explanation: All the 0s are segregated
to the left end of the linked list,
2s to the right end of the list, and
1s in between.
Example 2:
Input:
N = 4
value[] = {2,2,0,1}
Output: 0 1 2 2
Explanation: After arranging all the
0s,1s and 2s in the given format,
the output will be 0 1 2 2.
Your Task:
The task is to complete the function segregate() which segregates the nodes in 
the linked list as asked in the problem statement and returns the head of the 
modified linked list. The printing is done automatically by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
Constraints:
1 <= N <= 106
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
struct Node *start = NULL;
// } Driver Code Ends
/*
 
  Node is defined as
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
    //Function to sort a linked list of 0s, 1s and 2s.
// Approach-1 Most Optimized Approach
// Time COmplexity O(n)
// Space Complexity O(1)
void insertAtTail(Node* &tail, Node* curr ) {
    tail -> next = curr;
    tail = curr;
}
Node* sortList(Node *head)
{
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    
    // create separate list 0s, 1s and 2s
    while(curr != NULL) {
        
        int value = curr -> data;
        
        if(value == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail(oneTail, curr);
        }
        else if(value == 2) {
            insertAtTail(twoTail, curr);
        }       
        curr = curr -> next;
    }
    
    //merge 3 sublist
    
    // 1s list not empty
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
    }
    else {
        //1s list -> empty
        zeroTail -> next = twoHead -> next;
    }
    
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    
	//setup head 
    head = zeroHead -> next;
    
    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}
// Approach-2 Optimized Approach
// Time COmplexity O(n)
// Space Complexity O(1)
    Node* segregate(Node *head) {
        // Add code here
        int zero = 0;
        int one = 0;
        int two = 0;
        Node* curr = head;
        while(curr!=nullptr){
            if(curr->data==0){
                zero++;
            }
            else if(curr->data==1){
                one++;
            }
            else if(curr->data==2){
                two++;
            }
            curr=curr->next;
        }
        curr = head;
        while(curr!=nullptr){
            if(zero!=0){
                curr->data=0;
                zero--;
            }
            else if(one!=0){
                curr->data = 1;
                one--;
            }
            else if(two!=0){
                curr->data=2;
                two--;
            }
            curr=curr->next;
        }
        return head;
    }

};
//{ Driver Code Starts.
// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends