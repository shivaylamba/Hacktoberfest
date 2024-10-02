/*
111. Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 2
Example 2:
Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
Constraints:
The number of nodes in the tree is in the range [0, 105].
-1000 <= Node.val <= 1000
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
class Solution {
public:
    void dfs(TreeNode* node, int &ans, int depth) {
        if(!node) return;
        if(!node->left && !node->right) {
            ans = min(ans, depth);
            return;
        }
        dfs(node->left, ans, depth + 1);
        dfs(node->right, ans, depth + 1);
    }

    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int ans = INT_MAX;
        dfs(root, ans, 1);
        return ans;
    }
};