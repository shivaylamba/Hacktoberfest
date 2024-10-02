/*
Given a singly linked list having n nodes, your task is to remove every kth node from the linked list. 

Example 1:

Input:
n = 8
linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 
k = 2
Output: 
1 -> 3 -> 5 -> 7
Explanation: 
After removing every 2nd node of the linked list, the resultant linked list will be: 1 -> 3 -> 5 -> 7.
Example 2:

Input:
n = 10
linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 
k = 3
Output: 
1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10
Explanation: 
After removing every 3rd node of the linked list, the resultant linked list will be: 1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10.
Your Task:
The task is to complete the function deleteK() which takes head of linked list and integer k as input parameters and delete every kth node from the linked list and return its head.

Expected Time Complexity :  O(n)
Expected Auxiliary Space :  O(1)

Constraints:
1 <= n <= 105
-109 <= elements of linked list <= 109
1 <= k <= n
*/
/* Link list Node 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */
/*
-----------------------------------Approach------------------------------------
(1) Traverse list and do following
   (a) Count node before deletion.
   (b) If (count == k) that means current 
        node is to be deleted.
      (i)  Delete current node i.e. do

          //  assign address of next node of 
          // current node to the previous node
          // of the current node.
          prev->next = ptr->next i.e.

       (ii) Reset count as 0, i.e., do count = 0.
   (c) Update prev node if count != 0 and if
       count is 0 that means that node is a
       starting point.
   (d) Update ptr and continue until all 
       k-th node gets deleted.

Input: 1->2->3->4->5->6  
       k = 1
Output: Empty list 
All nodes need to be deleted

Time Complexity : O(n) 
Auxiliary Space : O(1)
*/
class Solution {
    public:
    Node* deleteK(Node *head,int k){
      //Your code here
      if(!head || k==1) return nullptr;
      int count = 0;
      Node* prev = nullptr , *temp = head;
      while(temp){
            count++;
          if(count==k){
              prev->next=temp->next;
               // set count = 0 to reach further 
            // k-th Node 
            count = 0; 
          }
          // update prev if count is not 0 
          if(count!=0){
              prev =temp;
          }
          temp=prev->next;
      }
      return head;
    }
};