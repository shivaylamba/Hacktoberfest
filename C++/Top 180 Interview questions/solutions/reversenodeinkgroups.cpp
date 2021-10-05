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
    ListNode* reverseKGroup(ListNode* head, int k) {
      if(head==NULL || k==1) return head;
        // reverse is not possible only
       ListNode* dummy = new ListNode(0);
        dummy ->next = head;
        // creating a dummy node
        ListNode * cur= dummy;
        ListNode * pre= dummy;
        ListNode * nex= dummy;
        int count = 0;
        while(cur->next!=NULL)
        {
            cur=cur->next;
            count++;
        }
        // now we starting the iteration with the first set up
        while(count>=k)
        {
            cur = pre->next;
            nex= cur->next;
            for(int i = 1; i < k ; i++)
            {
                cur->next= nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
            }
            pre=cur;
            count-=k;
        }
        return dummy->next;
    }
};