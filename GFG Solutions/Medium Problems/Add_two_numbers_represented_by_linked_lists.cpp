/*
Add two numbers represented by linked lists
Given two decimal numbers represented by two linked lists of size N and M respectively. The task is to return a linked list that represents the sum of these two numbers.

For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the sum list.   

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(Max(N,M)) for the resultant list.

Constraints:
1 <= N, M <= 5000
*/
// Optimized Approach (General)
// Time Complexity O(n+m)
// Space Complexity O(Max(n,m))
class Solution
{
    private:
    struct Node* reverse(struct Node* head){
        Node* curr = head , *prev = nullptr , *nxt = nullptr;
        while(curr!=nullptr){
            nxt = curr ->next;
            curr->next= prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
   
    void insertAtTail(struct Node* &head,struct Node* &tail , int x){
                Node * node = new Node(x);
        if(head==nullptr){
            head=node ;
            tail = node;
            return ;
        }
       else{
            tail->next = node;
        tail= node;
       }
    }
    //Function to add two numbers represented by linked list.
    struct Node* add(struct Node* first, struct Node* second){
        
          Node* ansHead = NULL;
        Node* ansTail = NULL; 
        
            int carry = 0;
    while(first!=nullptr || second!=nullptr || carry!=0){
        
        int val1 = 0;
        if(first!=nullptr){
            val1 = first->data;
        }
    
       int val2 = 0;
        if(second!=nullptr){
            val2 = second->data;
        }
        
        int sum = val1 +val2 + carry;
        int digit = sum%10;
    //create node and add in answer Linked List
        insertAtTail(ansHead,ansTail,digit);
                carry = sum/10;
        if(first!=nullptr){
            first=first->next;
        }
        if(second!=nullptr){
            second = second->next;
        }
    }
    return ansHead;
    }
     public:
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
     //step 1 -  reverse input LL
        first = reverse(first);
        second = reverse(second);
        
        //step2 - add 2 LL
        Node* ans = add(first, second);
        
        //step 3 
        ans = reverse(ans);
        
        return ans;
    }
};
// Optimized Approach (Not General)
class Solution
{
    private:
    struct Node* reverse(struct Node* head){
        Node* curr = head , *prev = nullptr , *nxt = nullptr;
        while(curr!=nullptr){
            nxt = curr ->next;
            curr->next= prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    public:
    void insertAtTail(struct Node* &head,struct Node* &tail , int x){
                Node * node = new Node(x);
        if(head==nullptr){
            head=node ;
            tail = node;
            return ;
        }
       else{
            tail->next = node;
        tail= node;
       }
    }
    //Function to add two numbers represented by linked list.
    struct Node* add(struct Node* first, struct Node* second){
        
          Node* ansHead = NULL;
        Node* ansTail = NULL; 
        
            int carry = 0;
    while(first!=nullptr && second!=nullptr){
        int sum = first->data + second->data + carry;
        int digit = sum%10;
    //create node and add in answer Linked List
        insertAtTail(ansHead,ansTail,digit);
                carry = sum/10;
        first=first->next;
        second = second->next;
    }
    
        while(first!=nullptr){
        int sum = first->data + carry;
        int digit = sum%10;
        insertAtTail(ansHead,ansTail,digit);
                carry = sum/10;
        first=first->next;
    }
    
        while( second!=nullptr){
        int sum = second->data + carry;
        int digit = sum%10;
        carry = sum/10;
        insertAtTail(ansHead,ansTail,digit);
        second = second->next;
    }
    
    while(carry!=0){
        int sum = carry;
        int digit = sum%10;
        insertAtTail(ansHead,ansTail,digit);
           carry = sum/10;
    }
    return ansHead;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
     //step 1 -  reverse input LL
        first = reverse(first);
        second = reverse(second);
        
        //step2 - add 2 LL
        Node* ans = add(first, second);
        
        //step 3 
        ans = reverse(ans);
        
        return ans;
    }
};