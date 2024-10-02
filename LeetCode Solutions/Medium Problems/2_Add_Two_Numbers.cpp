/*
2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
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
// Optimized Approach
// Time Complexity O(n+m)
// Space Complexity O(Max(n,m))
class Solution {
private :
void insertAtTail(ListNode* &head,ListNode* &tail,int data){
          ListNode * node = new ListNode(data);
        if(head==nullptr){
            head=node ;
            tail = node;
            return ;
        }
       else{
            tail->next = node;
        tail= node;
       }
}
ListNode* add(ListNode* l1 , ListNode* l2){
      ListNode* ansHead = nullptr , *ansTail = nullptr;
        int carry = 0;
        while(l1!=nullptr || l2!=nullptr || carry!=0){
            int v1 = 0 , v2 =0;
            if(l1!=nullptr){
                v1 = l1->val;
            }
            if(l2!=nullptr){
                v2 = l2->val;
            }
            int sum = carry+v1+v2;
            int digit = sum%10;
            carry = sum/10;
            insertAtTail(ansHead,ansTail,digit);
            if(l1!=nullptr){
                l1 = l1->next;
            }
            if(l2!=nullptr){
                l2 = l2->next;
            }
        }
    return ansHead;
}
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* ans = add(l1,l2);
     return ans;
    }
};