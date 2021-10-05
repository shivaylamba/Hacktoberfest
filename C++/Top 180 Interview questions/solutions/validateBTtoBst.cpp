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
    bool isValidBST(TreeNode* root, TreeNode* mini = NULL, TreeNode* maxi= NULL) {
     if(root==NULL)
        return true;
        // means we would have reached almost at the end
     if((mini && root->val<=mini->val) ||(maxi && root->val>=maxi->val))
         return false;
      return isValidBST(root->left,mini,root) && isValidBST(root->right,root,maxi);
        // the mini and the maxi values will change
    }
};