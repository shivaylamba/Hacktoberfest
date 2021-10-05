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
class Solution {a
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val > l2->val) std::swap(l1,l2);
        // you can simply swap off the lists, their address will be swapped
        ListNode *res = l1;
        // assigning the result to the value which is lower
        //two iterations will be used
        while(l1!=NULL && l2!=NULL)
        {
            ListNode *temp=NULL;
            while(l1!=NULL && l1->val <= l2->val)
            {
                temp=l1;
                l1 = l1->next;
            }
            if(temp!=NULL)temp->next= l2;
            std::swap(l1,l2);
        }
        return res;
    }
};