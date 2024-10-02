/*
Decimal Equivalent of Binary Linked List
Given a singly linked list of length n. The link list represents a binary number, 
ie- it contains only 0s and 1s. Find its decimal equivalent.
The significance of the bits decreases with the increasing index in the linked list.
An empty linked list is considered to represent the decimal value 0.
Since the answer can be very large, answer modulo 109+7 should be printed.
Example 1:
Input:
n = 3
Linked List = {0, 1, 1}
Output:
3
Explanation:
0*22 + 1*21 + 1*20 =  1 + 2 + 0 = 3
Example 2:
Input:
n = 4
Linked List = {1, 1, 1, 0}
Output:
14
Explanation:
1*23 + 1*22 + 1*21 + 0*20 =  8 + 4 + 2 + 0 = 14
Your Task:
You do not have to take any input or print anything. Complete the function decimalValue() 
which takes a head node of a linked list as an input parameter and returns decimal 
representation of it.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
0 <= n <= 100
Data of each node is either 0 or 1
*/
//{ Driver Code Starts
// Program to check if linked list is empty or not
#include<iostream>
using namespace std;
const long long unsigned int MOD = 1000000007;
/* Link list Node */
struct Node
{
    bool data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
// } Driver Code Ends
/* Below global variable is declared in code for modulo arithmetic
const long long unsigned int MOD = 1000000007; */
/* Link list Node/
struct Node
{
    bool data;   // NOTE data is bool
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */
class Solution
{
    public:
        // Should return decimal equivalent modulo 1000000007 of binary linked list 
        long long unsigned int decimalValue(Node *head)
        {
           // Your Code Here
    long long unsigned int i=0;
        Node *ptr=head;
        while(ptr!=nullptr)
        {
            i+=ptr->data;
            ptr=ptr->next;
            if(ptr!=nullptr)
                 i=i*2;
        
            i%=MOD;
        }
        return i;
        }
};
//{ Driver Code Starts.
void append(struct Node** head_ref, struct Node **tail_ref, bool new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
bool isEmpty(struct Node *head);
/* Driver program to test above function*/
int main()
{
    bool l;
    int i, n, T;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
        Solution obj;
        cout << obj.decimalValue(head) << endl;
    }
    return 0;
}
// } Driver Code Ends