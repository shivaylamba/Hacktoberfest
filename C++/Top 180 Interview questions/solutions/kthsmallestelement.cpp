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
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)
            return 0;
        int count = 0;
        TreeNode * temp = root;
        stack<TreeNode*> s;
        while(true)
        {
            while(temp)
            {
                s.push(temp);
                temp = temp->left;
            }
            // we 
            // first we go to the extreme left
            // as in we are considering the inorder traversal
            temp = s.top();
            s.pop();
            count++;
            if(count==k)
                return temp->val;
            temp = temp->right;
        }
        return count;
    }
};