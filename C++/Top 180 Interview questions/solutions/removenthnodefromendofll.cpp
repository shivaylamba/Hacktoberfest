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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newNode = new ListNode();
        newNode->next = head;
        ListNode* slow = newNode;
        ListNode* fast = newNode;
        for(int i = 1 ; i <= n ; i++)
        {
            fast = fast->next;
        }
        while(fast->next!=NULL)
        {
            slow = slow->next;
            fast=fast->next;
        }
        slow->next= slow->next->next;
        return newNode->next;
    }
};