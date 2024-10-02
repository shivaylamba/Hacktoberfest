/*
203. Remove Linked List Elements
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50
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
// Most Optimized Approach
// Time Complexity O(n);
// Space Complexity O(1);
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return head;
        }
       
        while(head!=NULL&&head->val==val){
            head=head->next;
        }
        ListNode*temp=head;
        while(temp!=NULL&&temp->next!=NULL){
            if(temp->next->val==val){
                temp->next=temp->next->next;
            }
            else{
                temp=temp->next;
            }
        }
        return head;
    }
};
// Optimized Approach
// Time Complexity O(n);
// Space Complexity O(1);
class Solution {
    private:
    void insertAtTail(ListNode* &tail,int x){
        ListNode* node = new ListNode(x);
        tail->next= node;
        tail=node;
    }
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ans = new ListNode(-1);
        ListNode* node = ans;
        while(head!=nullptr){
            if(head->val!=val){
                insertAtTail(node,head->val);
            }
            head=head->next;
        }
        return ans->next;
    }
};