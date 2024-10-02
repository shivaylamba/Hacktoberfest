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
    vector<int> postorderTraversal(TreeNode* root) {
          vector<int> ans;
  if(root==NULL) return ans;
  vector<int> left =postorderTraversal(root->left);
  ans.insert(ans.end(),left.begin(),left.end());
  vector<int> right =postorderTraversal(root->right);
  ans.insert(ans.end(),right.begin(),right.end());
 ans.push_back(root->val);
 return ans;
    }
    vector<int> postorderTraversal1(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        if(root) st.push(root);
        while(!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();
            ans.push_back(cur->val);
            if(cur->left) st.push(cur->left);
            if(cur->right) st.push(cur->right);
        }
        for(int i=0;i<ans.size()/2;i++)
            swap(ans[i],ans[ans.size()-1-i]);
        return ans;
        
    }
};