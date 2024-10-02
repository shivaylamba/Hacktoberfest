/*
21 Merge two sorted linked lists
Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.
 

Example 1:

Input:
N = 4, M = 3 
valueN[] = {5,10,15,40}
valueM[] = {2,3,20}
Output: 2 3 5 10 15 20 40
Explanation: After merging the two linked
lists, we have merged list as 2, 3, 5,
10, 15, 20, 40.
Example 2:

Input:
N = 2, M = 2
valueN[] = {1,1}
valueM[] = {2,4}
Output:1 1 2 4
Explanation: After merging the given two
linked list , we have 1, 1, 2, 4 as
output.
Your Task:
The task is to complete the function sortedMerge() which takes references to the heads of two linked lists as the arguments and returns the head of merged linked list.

Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N, M <= 104
0 <= Node's data <= 105
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
// Time Complexity O(n)
// Space Complexity O(1)
class Solution {
private:
    void insertAtTail(ListNode* &tail,int x){
        ListNode* node = new ListNode(x);
        tail->next= node;
        tail = node;
     }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans  = new ListNode(-1);
        ListNode* temp = ans;
        if(list1==nullptr && list2==nullptr){
            return nullptr;
        }
        if(list2==nullptr){
            return list1;
        }
        if(list1==nullptr){
            return list2;
        }
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val == list2->val){
                insertAtTail(temp,list1->val);
                insertAtTail(temp,list2->val);
                list1 = list1 ->next;
                list2=list2->next;
            }
            else if(list1->val > list2->val){
                insertAtTail(temp,list2->val);
                list2=list2->next;
            }
             else{
                insertAtTail(temp,list1->val);
                list1=list1->next;
            }
        }
        if(list1!=nullptr){
            temp->next=list1;
        }
        else{
            temp->next=list2;
        }
        ans = ans->next;
        return ans;
    }
};