/*
24. Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:
Input: head = []
Output: []
Example 3:
Input: head = [1]
Output: [1]
Constraints:
The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode * temp = head->next->next;
        ListNode * newHead = head->next;

        head->next->next = head;
        head->next =  swapPairs(temp);

        return newHead;
    }
};
//------------------------------------------------------------------------------------//
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* ans = new ListNode();
        if(!head || !head->next) return head;
        ListNode* prev = ans , *curr=head;
        while(curr && curr->next){
            prev->next = curr->next;
            curr->next = prev->next->next;
            prev->next->next = curr;
            prev = curr;
            curr=curr->next;
        }
        return ans->next;
    }
};