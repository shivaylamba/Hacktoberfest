/*
2816. Double a Number Represented as a Linked List
You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

Return the head of the linked list after doubling it.

 

Example 1:


Input: head = [1,8,9]
Output: [3,7,8]
Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.
Example 2:


Input: head = [9,9,9]
Output: [1,9,9,8]
Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998. 
 

Constraints:

The number of nodes in the list is in the range [1, 104]
0 <= Node.val <= 9
The input is generated such that the list represents a number that does not have leading zeros, except the number 0 itself.
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
/*
----------------------------- Most Optimized Solution-----------------------------
    Time Complexity O(n)
    Space Complexity O(n)
*/
class Solution {
public:
    ListNode*reverse(ListNode*head){
        ListNode*temp=head;
        ListNode*prev=NULL;
        while(temp){
            ListNode*front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        head=reverse(head);
        ListNode*temp=head;
        ListNode*prev;
        int carry=0;
        while(temp){
            int sum=carry+2*temp->val;
            carry=sum/10;
            temp->val=sum%10;
            prev=temp;
            temp=temp->next;
        }
        if(carry){
            ListNode*x=new ListNode(carry);
            prev->next=x;
        }
        head=reverse(head);
        return head;
    }
};
/*
----------------------------- Optimized Solution-----------------------------
    Time Complexity O(n)
    Space Complexity O(n)
*/
class Solution {
private:
ListNode* reverse(ListNode* head){
    ListNode* curr = head , *prev = nullptr , *nxt = nullptr;
    while(curr){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}
void insertAtEnd(ListNode*&head,ListNode*&tail,int x){
    ListNode* node = new ListNode(x);
    if(!head){
        head = node;
        tail = node;
        return ;
    }
    tail->next = node;
    tail=node;
}
public:
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        int carry = 0 ;
        ListNode* ansHead = nullptr,*ansTail = nullptr;
        while(carry || head){
            int n = 0;
            if(head){
                n = head->val * 2;
            }
             n+=carry;
            int digit = n%10;
             carry = n/10;
            insertAtEnd(ansHead,ansTail,digit);
           if(head) head=head->next;
        }
        return reverse(ansHead);
    }
};