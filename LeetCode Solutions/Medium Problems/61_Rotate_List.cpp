/*
61. Rotate List
Given the head of a linked list, rotate the list to the right by k places.
Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]
Constraints:
The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
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
ListNode* FindNthNode(ListNode* head,int k){
    int i =1;
    while(head!=nullptr){
        if(i==k){
            return head;
        }
        i++;
        head=head->next;
    }
    return head;
}
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || k ==0){
            return head;
        }
        int len = 1;
        ListNode* tail = head;
        while(tail->next!=nullptr){
            tail=tail->next;
            len++;
        }
        if(k%len==0) return head;
        tail->next = head;
        k%=len;
        ListNode* newEndNode = FindNthNode(head,len-k);
        head= newEndNode->next;
        newEndNode ->next=nullptr;
        return head;

    }
};