/*
515. Find Largest Value in Each Tree Row
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).
Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]
Example 2:
Input: root = [1,2,3]
Output: [1,3]
Constraints:
The number of nodes in the tree will be in the range [0, 104].
-231 <= Node.val <= 231 - 1
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
        BFS METHODS (ITERATION)
    Time Complexity O(n)
    Space Complexity O(n)
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
     vector<int> ans;
     if(!root) return ans;
     queue<TreeNode*> q;
     q.push(root);
     while(!q.empty()){
        int n = q.size();
        int maxa =INT_MIN;
        for(int i = 0 ; i<n;i++){
            TreeNode* front = q.front();
            q.pop();
            maxa =max(maxa,front->val);
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
        ans.push_back(maxa);
     }   
     return ans;
    }
};
/*
        DFS METHODS (RECURSION)
    Time Complexity O(n)
    Space Complexity O(n)
 */
class Solution {
    void check(TreeNode* root, int h, vector <int> & ans) {
        if(root==NULL) return ;
        if(h==ans.size()) ans.push_back(root->val);
        else if(h<ans.size() && ans[h] <root->val) ans[h]=root->val;
        check(root->left,h+1,ans); 
        check(root->right,h+1,ans); 
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector <int> ans;
        check(root,0,ans);
        return ans;
    }
};