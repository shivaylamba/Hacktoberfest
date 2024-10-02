/*
Given two decimal numbers, num1 and num2, represented by linked lists of size n and m respectively. The task is to return a linked list that represents the sum of these two numbers.

For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

Example 1:

Input:
n = 2
num1 = 45 (4->5->null)
m = 3
num2 = 345 (3->4->5->null)
Output: 
3->9->0->null  
Explanation: 
For the given two linked list (4 5) and (3 4 5), after adding the two linked list resultant linked list will be (3 9 0).
Example 2:

Input:
n = 4
num1 = 0063 (0->0->6->3->null)
m = 2
num2 = 07 (0->7->null)
Output: 
7->0->null
Explanation: 
For the given two linked list (0 0 6 3) and (0 7), after adding the two linked list resultant linked list will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the sum list.   

Expected Time Complexity: O(n+m)
Expected Auxiliary Space: O(max(n,m)) for the resultant list.

Constraints:
1 <= n, m <= 104
*/
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    struct Node* reverse(struct Node* head){
        if(!head) return head;
        Node* prev = nullptr , *curr = head , *nxt = nullptr;
        while(curr){
            nxt = curr->next;
            curr->next=prev;
            prev= curr;
            curr= nxt;
        }
        return prev;
    }
    void insertAtEnd(struct Node*&head,struct Node*&tail,int data){
                Node* node = new Node(data);
        if(!head){
            head = node;
            tail = node;
            return ;
        }
        tail->next = node;
        tail=node;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // code here
        int carry = 0 ;
        while(num1->data==0 && num1->next){
            num1 = num1->next;
        }
        while(num2->data==0 && num2->next){
            num2 = num2->next;
        }
        // if(!num1)return num2;
        // if(!num2)return num1;
        // if(!num1 && !num2)return new Node(0);
        num1 = reverse(num1);
        num2 = reverse(num2);
        Node* ansHead = nullptr;
        Node* ansTail = nullptr;
        while(num1 || num2 || carry){
            int n1 = 0 , n2  = 0 ;
            
            if(num1) n1 = num1->data;
            if(num2) n2 = num2->data;
            
            int sum = n1 +n2+carry;
            int digit = sum%10;
            insertAtEnd(ansHead,ansTail,digit);
            
            carry = sum/10;
            
          if(num1)  num1 = num1->next;
          if(num2)  num2=num2->next;
        }
        ansHead = reverse(ansHead);
        return ansHead;
    }
};