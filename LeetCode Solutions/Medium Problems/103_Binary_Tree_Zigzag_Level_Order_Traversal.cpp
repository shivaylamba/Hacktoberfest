/*
103. Binary Tree Zigzag Level Order Traversal
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:
Input: root = [1]
Output: [[1]]
Example 3:
Input: root = []
Output: []
Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
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
// Approach-1 using Indexing 
// Time Complexity o(n)
// Space Complexity o(n)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = 1;
        while(!q.empty()){
            int n = q.size();
            vector<int> res(n);
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                int idx = leftToRight ? i: n - i -1;
                res[idx] = temp->val;

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right) ;
            }
            leftToRight = !leftToRight;
            ans.push_back(res);
        }

        return ans;
    }
};

// Approach-2 Avoid Indexing and Using Reverse Function
// Time Complexity o(n)
// Space Complexity o(n)

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
        vector<vector<int>> ans;
        if(root==nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = 1;
        while(!q.empty()){
            int n = q.size();
            vector<int> res(n);
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                res[i]=temp->val;

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right) ;
            }
            if(leftToRight==0){
                if(n >1) reverse(res.begin(),res.end());
                }
            leftToRight = !leftToRight;
            ans.push_back(res);
        }

        return ans;
    }
};