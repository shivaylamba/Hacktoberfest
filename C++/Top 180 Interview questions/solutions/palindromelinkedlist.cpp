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
    ListNode* reverselist(ListNode* head)
    {
        ListNode* temphead=NULL;
        ListNode* temp;
        while(head!=NULL)
        {
            temp= head->next;
            head->next= temphead;
            temphead=head;
            head=temp;
        }
        return temphead;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next==NULL)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next= reverselist(slow->next);
        slow= slow->next;
        while(slow!=NULL)
        {
            if(slow->val != head->val)
                return false;
            slow=slow->next;
            head=head->next;
        }
        return true;
    }
};