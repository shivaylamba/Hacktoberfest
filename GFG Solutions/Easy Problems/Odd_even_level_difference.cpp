/*
Odd even level difference
Given a Binary Tree. Find the difference between the sum of node values at even levels and the sum of node values at the odd levels.
Example 1:
Input:
            1
          /   \
         2     3

Output: -4
Explanation:
sum at odd levels - sum at even levels
= (1)-(2+3) = 1-5 = -4
Example 2:
Input:
            10
          /    \
        20      30
       /  \         
     40    60      

Output: 60
Explanation:
sum at odd levels - sum at even levels
= (10+40+60) - (20+30)
= 110 - 50
= 60
Your Task:  
You dont need to read input or print anything. Complete the function getLevelDiff() which takes root node as input parameter and returns an integer.
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
Constraints:
1 ≤ N ≤ 10^5
*/
/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution{
  public:
    /*You are required to complete this function*/
    int getLevelDiff(Node *root)
    {
       //Your code here
       queue<Node*> q;
       q.push(root);
       int i  =1 ,odd = 0,even = 0;
       while(!q.empty()){
           int n = q.size();
           int sum = 0 ;
           for(int i = 0 ; i<n;i++){
               Node* frontNode = q.front();
               q.pop();
               sum += frontNode->data;
               if(frontNode->left) q.push(frontNode->left);
               if(frontNode->right) q.push(frontNode->right);
           }
           if(i&1) odd +=sum;
           else even+=sum;
           i++;
       }
       return (odd-even);
    }
};
