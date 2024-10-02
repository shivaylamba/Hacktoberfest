/*
Delete node in Doubly Linked List

Given a doubly linked list and a position. The task is to delete a node from given position (position starts from 1) in a doubly linked list.

Example 1:

Input:
LinkedList = 1 <--> 3 <--> 4 
x = 3
Output: 1 3  
Explanation: After deleting the node at
position 3 (position starts from 1),
the linked list will be now as 1->3.
Example 2:

Input:
LinkedList = 1 <--> 5 <--> 2 <--> 9  
x = 1
Output: 5 2 9
Your Task:
The task is to complete the function deleteNode() which should delete the node at given position and return the head of the linkedlist.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(1)

Constraints:
2 <= size of the linked list(n) <= 105
1 <= x <= n
1 <= node.data <= 109
*/
//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>

/* a Node of the doubly linked list */
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  
  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};


// } Driver Code Ends
/* Structure of Node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  
  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};
*/

class Solution
{
    public:
    Node* deleteNode(Node *head_ref, int x)
    {
      //Your code here
     if(x==1){
         head_ref=head_ref->next;
         head_ref->prev =nullptr;
         return head_ref;
     }
      Node* prv  = nullptr , * curr= head_ref;
      int i=1;
      while(i<x){
          prv = curr;
              curr=curr->next;
        i++;
          
      }
      if(curr->next==nullptr){
          prv->next=nullptr;
          return head_ref;
      }
      curr->next->prev = prv;
      prv->next = curr->next;
      return head_ref;
    }
};

//{ Driver Code Starts.

/* Function to print Nodes in a given doubly linked list
   This function is same as printList() of singly linked lsit */
void printList(struct Node *node)
{
  while(node!=NULL)
  {
    printf("%d ", node->data);
    node = node->next;
  }
   printf("\n");
}
 
/* Drier program to test above functions*/
int main()
{
  int t, x, n, i;
  scanf("%d",&t);
  
  while(t--)
  {
      /* Start with the empty list */
      struct Node *temp,*head = NULL;
      scanf("%d",&n);
      
      temp = NULL;
      
      for(i=0;i<n;i++){
        scanf("%d",&x);
        
        if(head == NULL){
            head = new Node(x);
            temp = head;
        }
        else{
            Node *temp1 = new Node(x);
            temp->next = temp1;
            temp1->prev = temp;
            temp = temp->next;
        }
      }
  
    scanf("%d",&x);
      
    Solution ob;  
    head = ob.deleteNode(head,x); 
      
        
        printList(head);           
        while(head->next!=NULL)
        {
    	    temp=head;
    	    head=head->next;
    	    free(temp);
    	}
    	
    	free(head);
	}
	return 0;
}

// } Driver Code Ends