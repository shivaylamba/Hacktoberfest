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
    bool isSameTree(TreeNode* p, TreeNode* q) {
     if(p==NULL && q==NULL)
         return true;
     else if(p==NULL || q==NULL)
         return false;
        // only one is null so doubt thoda
     else if(p->val!=q->val)
         return false;
        // checking value at the current node
     else
         return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        // going left and right at the same time
    }
};