/*
148. Sort List
Given the head of a linked list, return the list after sorting it in ascending order.
Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:
Input: head = []
Output: []
Constraints:
The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
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
private:
// Code to find the middle of the LinkedList
ListNode* findMiddle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast!=nullptr && fast->next!=nullptr){
        slow= slow ->next;
        fast =fast->next->next;
    }
    return slow ;
}
// Merge the Half of the LinkedList
ListNode* merge(ListNode* left,ListNode* right){
    if(left==nullptr){
        return right;
    }
    if(right == nullptr){
        return left;
    }
    ListNode * ans = new ListNode(-1);
    ListNode* temp = ans;
    while(left!=nullptr && right!=nullptr){
        if(left->val > right->val){
            temp->next=right;
            temp=right;
            right=right->next;
        }
        else{
            temp->next=left;
            temp=left;
            left=left->next;
        }
    }
    while(left != NULL) {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
    
    while(right != NULL) {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    ans=ans->next;
    return ans;
}
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
    // get the Middle of the Linkedlist
        ListNode* mid = findMiddle(head);
    // Dividing LinkedList into Two Halves
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next=nullptr;
// Sort the Halves recursively
left = sortList(left);
right = sortList(right);

// Merge the LinkedList
ListNode* res = merge(left,right);
    return res;
    }
};