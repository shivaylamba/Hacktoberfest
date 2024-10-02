/*
113. Path Sum II
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
Example 2:
Input: root = [1,2,3], targetSum = 5
Output: []
Example 3:
Input: root = [1,2], targetSum = 0
Output: []
Constraints:
The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
*/
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
/*
       MOST OPTIMIZED APPROACH
    Time Complexity O(n)
    Space Complexity O(2^h-1)
*/
class Solution {
public:
    // Logic -
    // Keep track of current sum of each node,and path till that node
    // if current node is leaf and sum = target sum -> save that 
    void solve(TreeNode* root, int targetSum, int currSum, vector<int>& curr, vector<vector<int>>&ans){
        // BC
        if(root == NULL){
            return ;
        }
        // Extra 1 case
        curr.push_back(root->val);
        currSum += root -> val;
        if(root -> left == NULL && root -> right == NULL && (currSum == targetSum)){
            ans.push_back(curr);
        }
        solve(root->left,targetSum,currSum,curr,ans);
        solve(root->right,targetSum,currSum,curr,ans);

        // BT - do when taking curr vector by reference
        curr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(root,targetSum,0,curr,ans);
        return ans;
    }
};
/*
       MOST OPTIMIZED APPROACH
    Time Complexity O(n)
    Space Complexity O(2^h-1)
*/
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        vector<vector<int>> res;
        vector<int> path;
        findPath(root, targetSum, path, res);
        return res;
    }

    void findPath(TreeNode* root, int target, vector<int>& path, vector<vector<int>>& res) {
        if (!root) {
            return;
        }

        path.push_back(root->val);
        if (!root->left && !root->right && target == root->val) {
            res.push_back(path);
        }

        findPath(root->left, target - root->val, path, res);
        findPath(root->right, target - root->val, path, res);
        path.pop_back();
    }
};
/*
     OPTIMIZED APPROACH
    Time Complexity O(n)
    Space Complexity O(2^h-1)
*/
class Solution {
private:
void solve(TreeNode* root,int targetSum,vector<vector<int>>&res,vector<int> ans){
    if(!root) return;
    ans.push_back(root->val);
    if(root->val == targetSum && !root->left && !root->right){
        res.push_back(ans);
        return;
    }
    solve(root->left,targetSum-root->val,res,ans);
    solve(root->right,targetSum-root->val,res,ans);
}
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> ans;
        solve(root,targetSum,res,ans);
 
 return res;
    }
};
