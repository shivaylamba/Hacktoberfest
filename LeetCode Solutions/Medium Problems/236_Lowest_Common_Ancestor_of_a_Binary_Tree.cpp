/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//          Approach-1
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if(root==NULL){
             return NULL;
         }
         if(root->val==p->val)
            return p;
         if(root->val==q->val)
            return q;
        TreeNode* leftAns=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns=lowestCommonAncestor(root->right,p,q);
        if(leftAns==NULL && rightAns==NULL){
            return NULL;
        }
        else if(leftAns!=NULL && rightAns==NULL)  
           return leftAns;
        else if(leftAns==NULL && rightAns!=NULL)
            return rightAns;
        else{
            return root;
        }
    }
};

//          Approach-2
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     if(root==NULL) return NULL;
     if(root->val==p->val || root->val==q->val){return root;}

     TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
     TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);

     if(leftAns && rightAns) return root;
     else if(!leftAns && rightAns) return rightAns;
     else if(leftAns && !rightAns) return leftAns;
     else return nullptr;
     }
};