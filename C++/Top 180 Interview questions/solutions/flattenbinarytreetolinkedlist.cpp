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
    void flatten(TreeNode* root) {
        // very good approach
    if(root==NULL)
        return;
        // base condition
    stack<TreeNode*> s;
        s.push(root);
    while(s.empty()!=true)
    {
        TreeNode* curr=s.top();
        s.pop();
        if(curr->right!=NULL)
            s.push(curr->right);
        // because we want the right to be traversed later on
        if(curr->left!=NULL)
            s.push(curr->left);
        // it is preorder traversal
        // we want left to be traversed first
        if(!s.empty())
            curr->right=s.top();
        curr->left=NULL;
    }
    }
};