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
    int solve(TreeNode* root, int& res)
    {
    if(root==NULL)
        return 0;
    int lt=solve(root->left,res);
    int rt=solve(root->right,res);
    if(lt<0) lt=0;
    if(rt<0) rt=0;
    if(root->val + lt + rt > res)res=lt + rt + root->val;
        // res is storing the current maximum path sum
    return root->val +=max(lt,rt);
    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        solve(root,res);
        return res;
    }
};