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
    
    TreeNode* func(unordered_map<int,int>& um, int start,int end,int& preindex, vector<int>& preorder, vector<int>& postorder)
    {
        if(start>end)
            return NULL;
        TreeNode* node= new TreeNode(preorder[preindex++]);
        // starting with the very root of the tree
        if(start==end)
            return node;
        // same hi index ho jayega
        int temp=um[node->val];
        // this will give us the index
        node->left=func(um,start,temp-1,preindex,preorder,postorder);
        node->right=func(um,temp+1,end,preindex,preorder,postorder);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> um;
        // to store the inorder index , so that it is easy to search the key
        int start=0;
        int end=inorder.size()-1;
        // inorder bole toh left null right
        for(int i=0; i < inorder.size(); i++)
        {
            um[inorder[i]]=i;
        }
        int preindex=0;
        TreeNode* root=func(um,start,end,preindex,preorder,inorder);
        // start end keeps the indexs in the bound of inorder array
        return root;
    }
};