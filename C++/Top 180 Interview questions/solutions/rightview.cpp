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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(root==NULL)
            return v;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()!=true)
        {
            int sz=q.size();
            for(int i=1 ; i<=sz; i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(i==sz)
                {
                   v.push_back(temp->val); 
                }
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return v;
    }
};