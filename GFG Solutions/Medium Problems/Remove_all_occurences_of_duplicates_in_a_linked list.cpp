/*
Remove all occurences of duplicates in a linked list
Given a sorted linked list, delete all nodes that have duplicate numbers (all occurrences), leaving only numbers that appear once in the original list, and return the head of the modified linked list. 
Examples:

Input: Linked List = 23->28->28->35->49->49->53->53
Output: 23 35
Explanation: 
The duplicate numbers are 28, 49 and 53 which are removed from the list.

Input: Linked List = 11->11->11->11->75->75
Output: Empty list
Explanation: 
All the nodes in the linked list have duplicates. Hence the resultant list would be empty.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)
Constraints:
1 ≤ size(list) ≤ 105
*/
// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/
/*
    MOST OPTIMIZED APPROACH
Time Complexity: O(n)
Auxiliary Space: O(1) because extra space is not required in removal of duplicates
*/
class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        // code here
        Node* ans = new Node(-1);
        ans ->next = head ;
        Node* prev = ans ,*curr = head;
        while(curr){
            while(curr->next  && prev->next->data == curr->next->data){
                curr= curr->next;
            }
                if(prev->next == curr) prev = prev->next;
                else    prev->next = curr->next;
                
                curr = curr->next;
            head = ans->next;
        }
        return head;
        
    }
};