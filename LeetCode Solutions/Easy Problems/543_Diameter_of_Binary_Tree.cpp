/*
543. Diameter of Binary Tree
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.
Example 1:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:
Input: root = [1,2]
Output: 1
Constraints:
The number of nodes in the tree is in the range [1, 104].
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

// Approach -1 
// Time Complexity O(n)
// Space Complexity O(n)
class Solution {
private:
pair<int,int> diameterFast(TreeNode* root){
    if(root==nullptr){ pair<int,int> p = make_pair(0,0) ;return p;}

    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);

    int opt1 = left.first , opt2 = right.first;
    int opt3 = left.second + right.second;

    pair<int,int> ans;
    ans.first = max(opt1,max(opt2,opt3));
    ans.second= max(left.second,right.second)+1;
    return ans;
}
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        return  diameterFast(root).first;
    }
};
// Approach -2 fast Approach
// Time Complexity O(n)
// Space Complexity O(n)
class Solution {
public:
    // Function to calculate the diameter and height of a subtree recursively
    pair<int, int> calculateDiameterAndHeight(TreeNode* root) {
        if (root == nullptr) {
            // Base case: Empty subtree has diameter and height 0
            return {0, 0};
        }

        // Get diameter and height information for left and right subtrees
        auto leftData = calculateDiameterAndHeight(root->left);
        auto rightData = calculateDiameterAndHeight(root->right);

        // Calculate current subtree's diameter:
        // - Maximum path passing through root
        // - Maximum diameter in left or right subtree
        int currentDiameter = max(leftData.second + rightData.second, 
                                  max(leftData.first, rightData.first));

        // Calculate current subtree's height (maximum path through root)
        int currentHeight = max(leftData.second, rightData.second) + 1;

        return {currentDiameter, currentHeight};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // The diameter of the entire tree is the maximum diameter found across subtrees
        return calculateDiameterAndHeight(root).first;
    }
};