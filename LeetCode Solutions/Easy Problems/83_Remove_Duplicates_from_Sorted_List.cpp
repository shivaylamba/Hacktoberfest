/*
83. Remove Duplicates from Sorted List
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,1,2]
Output: [1,2]
Example 2:


Input: head = [1,1,2,3,3]
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
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
class Solution {
//Function to remove duplicates from sorted linked list.
// Optimized Approach
// Time Complexity O(n)
// Space Complexity O(1)
ListNode *removeDuplicates(ListNode *head)
{
 // your code goes here
 if(head==nullptr){
     return nullptr;
 }
 ListNode* curr = head;
 while(curr!=nullptr){
     if(curr->next!=nullptr && curr->data == curr->next->data){
         ListNode* pointToNextNodeOfDelete = curr->next->next;
         ListNode* nodeToDelete = curr->next;
         delete(nodeToDelete);
         curr->next = pointToNextNodeOfDelete;
     }
     else{
          curr=curr->next;
     }
     }
     return head;
 }
 // Most Optimized Approach
// Time Complexity O(n)
// Space Complexity O(1)
 ListNode *removeDuplicates2(ListNode *head)
{
  ListNode *curr = head;
  while (curr != nullptr && curr->next != nullptr)
  {
    if (curr->val == curr->next->val)
    {
      curr->next = curr->next->next;
    }
    else
    {
      curr = curr->next;
    }
  }
  return head;
}
// Optimized Approach // set
// Time Complexity O(n)
// Space Complexity O(n)
ListNode *removeDuplicates3(ListNode *head)
{
 // your code goes here
 if(head==nullptr){
     return nullptr;
 }
 ListNode* curr = head;
 ListNode* prev = nullptr;
 set<int> set;
 while(curr!=nullptr){
     if(set.count(curr->data)){
         prev->next = curr->next;
     }
     else{
         set.insert(curr->data);
         prev = curr;
     }
     curr=curr->next;
 }
 return head;
 }
 // Optimized Approach // unoredered_Set
// Time Complexity O(n)
// Space Complexity O(n)
 ListNode *removeDuplicates(ListNode *head)
{
 // your code goes here
 if(head==nullptr){
     return nullptr;
 }
 ListNode* curr = head;
 ListNode* prev = nullptr;
 unordered_set<int> set;
 while(curr!=nullptr){
     if(set.find(curr->data)!=set.end()){
         prev->next = curr->next;
     }
     else{
         set.insert(curr->data);
         prev = curr;
     }
     curr=curr->next;
 }
 return head;
 }
};

