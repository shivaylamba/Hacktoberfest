/*
445. Add Two Numbers II
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
 

Follow up: Could you solve it without reversing the input lists?
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
private :
ListNode* reverse(ListNode* head){
    ListNode* prev = nullptr , * curr = head, *nxt =nullptr;
    while(curr!=nullptr){
        nxt=curr->next;
        curr->next=prev;
        prev = curr;
        curr= nxt;
    }
    return prev;
}
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
         l1 = reverse(l1);
        l2 = reverse(l2);
      ListNode* ans = add(l1,l2);
      ans = reverse(ans);
     return ans;
    }
};