/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's 
next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.
Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
Constraints:
The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
Follow up: Can you solve it using O(1) (i.e. constant) memory?
*/
/*
=>Intuition
=>Floyd’s Cycle Finding Algorithm
=>Approach
-While traversing the linked list one of these things will occur-
--The Fast pointer may reach the end (NULL) this shows that there is no loop in the linked list.
--The Fast pointer again catches the slow pointer at some time therefore a loop exists in the linked list.
=>Pseudocode:
--Initialize two-pointers and start traversing the linked list.
--Move the slow pointer by one position.
--Move the fast pointer by two positions.
--If both pointers meet at some point then a loop exists and if the fast pointer meets the end position then no loop exists.
Complexity
=>Time complexity:O(n), as the loop is traversed once.
=>Space complexity:O(1), only two pointers are used therefore constant space complexity.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast = fast->next->next;
        if(slow==fast){
            return 1;
        }
        }
        return 0;
    }
};