/*
110. Balanced Binary Tree
Given a binary tree, determine if it is 
height-balanced
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:
Input: root = []
Output: true
Constraints:
The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Most Optimized Approach
// Time Complexity O(n)
// Space Complexity O(n)
class Solution {
private:
 pair<bool, int> isBalancedFast(TreeNode* root) {
                // base case
        if(root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        pair<int,int> left = isBalancedFast(root->left);
        pair<int,int> right = isBalancedFast(root->right);
        
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool diff = abs (left.second - right.second ) <=1;
        
        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;
        ans.first = (leftAns && rightAns && diff);
        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return 1;
    return isBalancedFast(root).first ; 
    }
};
// Least Optimized Approach
// Time Complexity O(n^2)
// Space Complexity O(n)
class Solution {
private:
int height(TreeNode* root){
    if(root==nullptr)return 0;
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left , right )+1;
    return ans ;
}
public:
    bool isBalanced(TreeNode* root) {
       if(root==nullptr) return 1;
       bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool ans = abs(height(root->left) - height(root->right))<=1;
return (left && right && ans)?1:0;
    }
};