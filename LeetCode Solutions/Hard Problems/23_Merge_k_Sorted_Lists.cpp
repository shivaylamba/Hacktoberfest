/*
23. Merge k Sorted Lists
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.
Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:
Input: lists = []
Output: []
Example 3:
Input: lists = [[]]
Output: []
Constraints:
k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
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
ListNode* merge(ListNode* l1 , ListNode* l2){
    ListNode* ans = new ListNode(-1);
    ListNode* temp = ans;
    while(l1!=nullptr && l2!=nullptr){
        if(l1->val > l2->val){
            temp->next = l2;
            temp=l2;
            l2 = l2->next;
        }
        else{
            temp->next = l1;
            temp=l1;
            l1 = l1->next;
        }
        }
        if(l1!=nullptr){temp->next = l1;}
        else{temp->next=l2;}
        return ans->next;
}
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0){return nullptr;}
        if(k==1){return lists[0];}
           ListNode* head=lists[0];
           for(int i=1;i<k;i++){
            head = merge(head,lists[i]);
           }
           return head;
    }
};