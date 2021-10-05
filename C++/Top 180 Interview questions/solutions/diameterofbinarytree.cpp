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
    int height(struct TreeNode * root, int &ans)
    {
        if(root==NULL)
            return 0;
        // as there is not even a single 0
        int lh=height(root->left,ans);
        int rh=height(root->right,ans);
        ans=max(ans,lh+rh);
        // storing the addition max of lh and the rh
        return 1 + max(lh,rh);
        // just a bit modified version of height of the binary tree
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
     int ans=0;
     height(root,ans);
     return ans;
       
    }
};