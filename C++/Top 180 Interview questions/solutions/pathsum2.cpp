class Solution {
public:
    void func(vector<vector<int>>& paths,vector<int>& path, TreeNode* root, int target)
    {
        if(!root)
          return;
        path.push_back(root->val);
        if(!root->left && !root->right && target==root->val)
            paths.push_back(path);
        func(paths,path,root->left,target-root->val);
        func(paths,path,root->right,target-root->val);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;
        func(paths,path,root,targetSum);
        return paths;
    }
};