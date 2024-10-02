/*
Reverse List In K Groups
Sample Input 1:
6
5 4 3 7 9 2
4 
Sample Output 1:
7 3 4 5 9 2
Explanation of the Sample Input 1:
For the given test case, we reverse the nodes in groups of four. But for the last 2 elements, we cannot form a group of four, so leave them as they are. 
The linked list becomes 7->3->4->5->9->2. Hence the output is 7 3 4 5 9 2
Sample Input 2:
4
4 3 2 8
4
Sample Output 2:
8 2 3 4
Expected Time Complexity:
Try to solve this in O(n). 
Expected Space Complexity:
Try to solve this using O(1) extra space.    
Constraints:
1 <= n <= 10^4
1 <= k <= n
Time Limit: 1 sec
*/
/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
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
// Get the length from the current head to last node
    int getLength(ListNode* head) {
        int count = 0;
        if (head == nullptr) {
            return count;
        }
        while (head != nullptr) {
            head = head->next;
            count++;
        }
        return count;
    }
// Time Complexity O(n) for reversing the k nodes in Linkedlist
// Space complexity O(n) for the Recursive calls which taking a constant space 
    ListNode* reverseKGroup(ListNode* head, int k) {
    // base case
    if(head==nullptr){return head;}
    // step-1 : reverse the first k nodes
    int  count =0;
// getting the length from the current lenth from the head to last node
    int n = getLength(head);
//step-2 check if the current length is smaller than the k(group size) than we cannot perform reverse operation
// so we just simply return head
// if we don't use this we get the reverse linkedlist irrespective of its size
    ListNode* prev =nullptr , *curr = head ,*nxt = nullptr;
    if(n<k){return head;}
// step-3 Reverse the K nodes in the Linkedlist
    while(count<k && curr!=nullptr){
        nxt= curr->next;
        curr->next = prev;
        prev=curr;
        curr=nxt;
        count++;
    }
//step-4 reverse using the recursion
    if(nxt!=nullptr){
        head->next = reverseKGroup(nxt,k);
    }
    return prev;
    }
};