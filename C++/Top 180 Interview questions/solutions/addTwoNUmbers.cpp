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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* l3=head;
        // just made the l3 pointer to point to some node containing val 0
        int carry=0;
        
        while(l1!=NULL || l2!=NULL){
            int l1val= (l1!=NULL)?l1->val : 0;
            int l2val= (l2!=NULL)?l2->val : 0;
            // if from the very beginning it is null then the value can be assigned as 0
            
            int currSum=l1val + l2val + carry;
            carry= currSum / 10;
            int lastDigit=currSum % 10;
            
            ListNode* newNode= new ListNode(lastDigit);
            l3->next= newNode;
            l3=l3->next;
            
            if(l1!=NULL) l1=l1->next;
            if(l2!=NULL) l2=l2->next;
        }
        if(carry > 0){
            ListNode* newNODE= new ListNode(carry);
            l3->next=newNODE;
            l3=l3->next;
        }
        return head->next;
    }
};