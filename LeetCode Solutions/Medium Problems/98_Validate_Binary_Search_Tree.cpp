/*
98. Validate Binary Search Tree
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left 
subtree
 of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
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
            INRODER TRAVERSAL
=>  The idea is to use Inorder traversal of a binary search tree generates output, sorted in 
    ascending order. So generate inorder traversal of the given binary tree and check if the 
    values are sorted or not
=>Follow the below steps to solve the problem:
    - Do In-Order Traversal of the given tree and store the result in a temp array. 
    - Check if the temp array is sorted in ascending order, if it is, then the tree is BST.
Time Complexity: O(N), Where N is the number of nodes in the tree
Auxiliary Space: O(H), Here H is the height of the tree and the extra space is used due 
                 to the function call stack. 
*/
class Solution {
private:
    bool dfs(TreeNode* root,TreeNode*&prev){
        if(root){
            if(!dfs(root->left,prev)) return 0;
            if( prev!=nullptr && root->val <=prev->val) return 0;

            prev = root;    
        return   dfs(root->right,prev);
        }
        return 1;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return 1;
        TreeNode* prev = nullptr;
        return dfs(root,prev);
    }
};
/*
        =>Check BST using specified range of minimum and maximum values of nodes:
The isBSTUtil() function is a recursive helper function that checks whether a subtree 
(rooted at a given node) is a BST within the specified range of minimum (min) and 
maximum (max) values. If any node violates this range, the function returns false; 
otherwise, it continues checking the left and right subtrees.
    - Time Complexity: O(N), Where N is the number of nodes in the tree
    - Auxiliary Space: O(1), if Function Call Stack size is not considered, otherwise 
                             O(H) where H is the height of the tree
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
     bool validate(TreeNode* root, long long min, long long max) {
        if (root == nullptr) {
            return true;
        }

        if (root->val <= min || root->val >= max) {
            return false;
        }

        return validate(root->left, min, root->val) && validate(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root,LLONG_MIN,LLONG_MAX);      
    }
};