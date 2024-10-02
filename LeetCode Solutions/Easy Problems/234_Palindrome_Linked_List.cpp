/*
234. Palindrome Linked List
Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
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
  ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
ListNode* getMiddle(ListNode* head){
    ListNode* slow = head ;
    ListNode* fast = head->next;
    while(fast!=nullptr && fast->next!=nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
    bool isPalindrome(ListNode* head) {
        ListNode* middle = getMiddle(head);
        ListNode* temp = middle->next;
        middle->next = reverse(temp);
        ListNode* head1 = head ;
        ListNode* head2 = middle->next;
        while(head2!=nullptr){
            if(head1->val!=head2->val){
                return 0;
            }
            head1= head1->next;
            head2 = head2->next;
        }
        temp = middle->next;
        middle->next = reverse(temp);
        return 1;
    }

        // Optimized Method
// Time Complexity O(n)
// Space Complexity O(n)
bool isPalindrome2(ListNode *head) {
    // Write your code here.
    vector<int> ans ;
    ListNode* curr = head;
    while(curr!=nullptr){
        ans.push_back(curr->data);
        curr = curr->next;
    }
    int i=0 , j = ans.size()-1;
    while(i<j){
        if(ans[i]!=ans[j]){
            return 0;
        }
        i++;j--;
    }
    return 1;
}
};