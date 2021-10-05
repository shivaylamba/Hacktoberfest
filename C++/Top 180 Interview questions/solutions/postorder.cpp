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
    void func(TreeNode* root, vector<int>& v)
    {
    if(root==NULL)
        return;
    func(root->left, v);
        func(root->right,v);
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
    // vector<int> v;
    // if(root==NULL)
    //     return v;
    // TreeNode* temp;
    // stack<pair<TreeNode*,int>> s1;
    // stack<pair<TreeNode*,int>> s2;
    // s1.push(make_pair(root,root->val));
    // while(s1.empty()!=true)
    // {
    // s2.push(make_pair(s1.top().first,s1.top().second));
    // temp=s1.top().first;
    // s1.pop();
    // if(temp->left!=NULL)
    // {
    // s1.push(make_pair(temp->left,temp->left->val));
    // }
    // if(temp->right!=NULL)
    // {
    // s1.push(make_pair(temp->right,temp->right->val));
    // }
    // }
    // while(s2.empty()!=true)
    // {
    //  v.push_back(s2.top().second);
    //  s2.pop();
    // }
    //     return v;
    vector<int> v;
    func(root, v);
    return v;
    }
};