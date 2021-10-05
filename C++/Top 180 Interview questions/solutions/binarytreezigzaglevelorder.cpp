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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        int count=2;
        if(root==NULL)
            return v;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()!=true)
        {
            int sz=q.size();
            vector<int> temp;
            while(sz--)
            {
                TreeNode* curr=q.front();
                temp.push_back(curr->val);
                q.pop();
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
            if(count%2==0)
            v.push_back(temp);
            else
            {
                reverse(temp.begin(),temp.end());
                v.push_back(temp);
            }
            count++;
        }
        return v;
    }
};