/*
1008. Construct Binary Search Tree from Preorder Traversal
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.
It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.
A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.
A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.
Example 1:
Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
Example 2:
Input: preorder = [1,3]
Output: [1,null,3]
Constraints:
1 <= preorder.length <= 100
1 <= preorder[i] <= 1000
All the values of preorder are unique.
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
    USING INT_MIN and INT_MAX
    Time Complexity O(n)
    Space Complexity O(n)
*/
class Solution {
public:
    TreeNode* solve(vector<int>pre,int &mina,int &maxa,int &idx){
        if(idx >= pre.size()) return nullptr;

        if(pre[idx] < mina || pre[idx] > maxa) return nullptr;

        TreeNode* root = new TreeNode(pre[idx++]);
        root->left = solve(pre,mina,root->val,idx);
        root->right = solve(pre,root->val,maxa,idx);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mina = INT_MIN , maxa =INT_MAX , idx = 0;
        TreeNode* ans = solve(preorder,mina,maxa,idx);
        return ans;
    }
};
/*
    Time Complexity O(n*log(n))
    Space Complexity O(n)
*/
class Solution {
public:
    int findPos(vector<int>arr,int x,int st,int en){
        for(int i=st;i<=en;i++) if(arr[i]==x) return i;
        return -1;
    }
    TreeNode* solve(vector<int>in,vector<int>pre,int&idx,int st,int en,int n){
        if(idx>=n || st>en) return nullptr;

        int element = pre[idx++];
        TreeNode* root = new TreeNode(element);
        int pos = findPos(in,element,st,en);

        root->left = solve(in,pre,idx,st,pos-1,n);
        root->right = solve(in,pre,idx,pos+1,en,n);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preOrderIdx = 0 , n = preorder.size();
        vector<int> inorder(preorder.begin(),preorder.end());
        sort(inorder.begin(),inorder.end());
        TreeNode* ans = solve(inorder,preorder,preOrderIdx,0,n-1,n);
        return ans;
    }
};