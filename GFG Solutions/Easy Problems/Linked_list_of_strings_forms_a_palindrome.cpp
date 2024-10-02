/*
Linked list of strings forms a palindrome
Given a linked list with string data, check whether the combined string formed is palindrome. If the combined string is palindrome then return true otherwise return false.
Example:
Input:
Output : true
Explanation: As string "abcddcba" is palindrome the function should return true.
Input:
Output : false
Explanation: As string "abcdba" is not palindrome the function should return false.
Expected Time Complexity:  O(n)
Expected Auxiliary Space: O(n)
Constraints:
1 <= Node.data.length<= 103
1<=list.length<=103
*/
/*
The structure of linked list is the following
struct Node
{
    string data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    bool compute(Node* head) {
        // Your code goes here
        string ans ="";
        while(head){
            ans+=head->data;
            head = head->next;
        }
        int i = 0 , j  = ans.size()-1;
        while(i<j){
            if(ans[i++]!=ans[j--]) return 0;
        }
        return 1;
    }
};
