/*
Delete without head pointer
You are given a node del_node of a Singly Linked List where you have to delete a value of the given node from the linked list but you are not given the head of the list.
By deleting the node value, we do not mean removing it from memory. We mean:
The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before & after the del_node node should be in the same order.
Note:
Multiple nodes can have the same values as the del_node, but you must only remove the node whose pointer del_node is given to you.
It is guaranteed that there exists a node with a value equal to the del_node value and it will not be the last node of the linked list.
Example 1:

Input:
Linked List = 1 -> 2
del_node = 1
Output: 
2
Explanation: 
After deleting 1 from the linked list, 
we have remaining nodes as 2.
Example 2:
Input:
Linked List = 10 -> 20 -> 4 -> 30
del_node = 20
Output: 
10 4 30
Explanation: 
After deleting 20 from the linked list, 
we have remaining nodes as 10, 4, 30.
Your Task:
You don't need to read or print anything. You only need to complete the function deleteNode() which takes a reference of the deleting node value & your task is to delete the given node value.
Expected Time Complexity: O(1).
Expected Auxilliary Space: O(1).
Constraints:
2 <= n <= 103  
1 <= elements of the linked list <= 109
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
/* Link list node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
Node *findNode(Node* head, int search_for)
{
    Node* current = head;
    while (current != NULL)
    {
        if (current->data == search_for)
            break;
        current = current->next;
    }
    return current;
}
void insert()
{
    int n,i,value;
    Node *temp;
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        scanf("%d",&value);
        if(i==0)
        {
            head=new Node(value);
            temp=head;
            continue;
        }
        else
        {
            temp->next= new Node(value);
            temp=temp->next;
            temp->next=NULL;
        }
    }
}
/* Function to print linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}
// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
*/
class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del_node)
    {
       // Your code here
        if(del_node==nullptr){return ;}
        Node* temp = del_node->next;
        if(del_node->next==nullptr){return ;}
        del_node->data = del_node->next->data;
        del_node->next = temp->next;
        delete(temp);
    }
};
//{ Driver Code Starts.
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */

    int t,k,n,value;
    
    scanf("%d",&t);
    while(t--)
    {
        insert();
        scanf("%d",&k);
        Node *del = findNode(head, k);
        Solution ob;
        if (del != NULL && del->next != NULL)
        {
            ob.deleteNode(del);
        }
        printList(head);
    }
    return(0);
}
// } Driver Code Ends