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
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
        if(root==NULL)
            return 0;
        // we wany leaf nodes
        if(!root->left && !root->right) return isLeft ? root->val : 0;
        return sumOfLeftLeaves(root->left,true) + sumOfLeftLeaves(root->right,false);
    }
};