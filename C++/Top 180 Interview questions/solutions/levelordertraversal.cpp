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
    vector<vector<int>> levelOrder(TreeNode* root) { 
        vector<vector<int>> v;
        if(root==NULL)
            return v;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()!=true)
        {
            int sz=q.size();
            // storing the current size of the queue
            // means all the nodes in the current level
            vector<int> temp;
            while(sz--)
            {
                TreeNode* curr=q.front();
                temp.push_back(curr->val);
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
            v.push_back(temp);
        }
        return v;
    }
};