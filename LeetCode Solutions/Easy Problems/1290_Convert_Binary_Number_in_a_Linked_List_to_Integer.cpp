/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.

 

Example 1:
Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0
 

Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
//  Most Optimized Approach 
    int getDecimalValue(ListNode* head) {
        int i=0;
        ListNode *ptr=head;
        while(ptr!=nullptr)
        {
            i+=ptr->val;
            ptr=ptr->next;
            if(ptr!=nullptr)
                 i=i*2;
        }
        return i;
    }
//  Optimized Approach 
//  Time Complexity O(n);
//  Space Complexity O(1);
int getLength(ListNode* head){
    int count =0;
    if(head==NULL) return 0; 
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count ;
}
    int getDecimalValue(ListNode* head) {
        int n = getLength(head);
      int ans = 0;
      while(head!=NULL){
      n--;
      ans +=(head->val)*pow(2,n);
      head=head->next;
    }
    return ans;
    }
};