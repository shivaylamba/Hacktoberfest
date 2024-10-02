/*
Root to leaf path sum
Given a binary tree and an integer s, check whether there is a root-to-leaf path with its sum as s.

Example 1:

Input:
Tree = 
            1
          /   \
        2      3
s = 2

Output: 0

Explanation:
There is no root to leaf path with sum 2.
Example 2:

Input:
Tree = 
            1
          /   \
        2      3
s = 4

Output: 1

Explanation:
The sum of path from leaf node 3 to root 1 is 4.

Your Task:  
You don't need to read input or print anything. Complete the function hasPathSum() which takes root node and target sum s as input parameters and returns true if the path exists otherwise, it returns false.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)

Constraints:
1 ≤ N ≤ 10^4
1 ≤ s ≤ 10^6
*/
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*you are required to
complete this function */
class Solution {
 public:
  bool hasPathSum(TreeNode* root, int sum) {
    if (root == nullptr)
      return false;
    if (root->val == sum && root->left == nullptr && root->right == nullptr)
      return true;
    return hasPathSum(root->left, sum - root->val) ||
           hasPathSum(root->right, sum - root->val);
  }
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)return 0;
        if(!root->right && !root->left) return root->val==targetSum;

      bool left =  hasPathSum(root->left,targetSum-root->val);
      bool right =   hasPathSum(root->right,targetSum-root->val);

    return left || right;
    }
};
class Solution
{
    public:
    bool hasPathSum(Node *Node, int sum) {
    // Your code here
  if (Node == NULL)
        return 0;
 
    bool ans = 0;
 
    int subSum = sum - Node->data;
 
    /* If we reach a leaf node and sum becomes 0 then return
     * true*/
    if (subSum == 0 && Node->left == NULL
        && Node->right == NULL)
        return 1;
 
    /* otherwise check both subtrees */
    if (Node->left)
        ans = ans || hasPathSum(Node->left, subSum);
    if (Node->right)
        ans = ans || hasPathSum(Node->right, subSum);
 
    return ans;
        
    }
};