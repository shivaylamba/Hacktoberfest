/*
230. Kth Smallest Element in a BST
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
Constraints:
The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
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
    MOST OPtimized Approach (Using COUNTER)
Time Complexity O(n);
Space Complexity O(n);
*/
class Solution {
public:
    int solve(TreeNode* root,int &counter,int k){
     if(!root) return -1;
     int left  = solve(root->left,counter,k);
     if(left!=-1) return left;
     counter++;
     if(counter==k) return root->val;
     return solve(root->right,counter,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        return solve(root,counter,k);
    }
};
/*
    Not OPtimized Approach (Using INORDER TRAVERSAL ARRAY)
Time Complexity O(n);
Space Complexity O(n);
*/
class Solution {
public:
vector<int>  inorder(TreeNode* root){
    vector<int> ans;
    if(!root) return {};

    vector<int> left = inorder(root->left);
    ans.insert(ans.end(),left.begin(),left.end());
    ans.push_back(root->val);
    vector<int> right = inorder(root->right);
    ans.insert(ans.end(),right.begin(),right.end());

return ans;
}
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans = inorder(root);
        if(ans.size()<k) return -1;
        return ans[k-1];
    }
};