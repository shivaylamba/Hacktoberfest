/*
142. Linked List Cycle II
Given the head of a linked list, return the node where the cycle begins. 
If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list 
that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. 
Note that pos is not passed as a parameter.
Do not modify the linked list.
Example 1:Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
Constraints:
The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
Follow up: Can you solve it using O(1) (i.e. constant) memory?
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//---------------------------Approach -1 ----------------------------------------//
//Most Optimized Approach
// Time Complexity O(n)
// Space Complexity O(1)
Node* floydDetectLoop(Node* head) {
    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;
    while(slow != NULL && fast !=NULL) {
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }
        slow = slow -> next;
        if(slow == fast) {
            return slow;
        }
    }
    return NULL;
}
// With the Help of FloydCycle Detection Algorithm
Node* getStartingNode(Node* head) {
    if(head == NULL) 
        return NULL;

    Node* intersection = floydDetectLoop(head);
    
    if(intersection == NULL)
        return NULL;
    
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  

    return slow;
}
Node *firstNode(Node *head)
{
    //    Write your code here.
        if(head==nullptr){
            return nullptr;
        }
  return getStartingNode(head);
}
// ---------------------------Approach -1 ----------------------------------------//
// Optimized Approach
// Time Complexity O(n^2)
// Space Complexity O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                slow = head;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return NULL;
    }
};
//---------------------------Approach -1 ----------------------------------------//
// Optimized Approach
// Time Complexity O(n)
// Space Complexity O(1)
class Solution {
public:
ListNode* cyclePresent(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next;
        if(fast->next!=nullptr){
            fast = fast->next;
        }
        if(fast==slow){
            return slow;
        }
    }
    return nullptr;
}
    ListNode *detectCycle(ListNode *head) {
        if(cyclePresent(head)==nullptr || head->next==nullptr){
            return nullptr;
        }
     map<ListNode*,bool> visited;
     ListNode* temp=head;
     while(temp!=nullptr){
         if(visited[temp]==1){
             return temp;
         }
         visited[temp]=1;
         temp=temp->next;
     }   
     return nullptr;
    }
};