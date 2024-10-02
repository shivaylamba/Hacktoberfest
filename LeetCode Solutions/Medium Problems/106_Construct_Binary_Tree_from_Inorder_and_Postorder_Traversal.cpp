/*
106. Construct Binary Tree from Inorder and Postorder Traversal
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]

Constraints:
1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
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
    Msot Optimized APproach
    Time COmplexity o(n*log(m))
    Space COmplexity o(n)
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap; 
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inMap);
    }
    
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd, 
                    vector<int>& postorder, int postStart, int postEnd, 
                    unordered_map<int, int>& inMap) {
        if (inStart > inEnd || postStart > postEnd) return nullptr;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);  
        int inRoot = inMap[root->val];  
        int numsLeft = inRoot - inStart;  
        
        root->left = build(inorder, inStart, inRoot - 1, 
                           postorder, postStart, postStart + numsLeft - 1, inMap);
        root->right = build(inorder, inRoot + 1, inEnd, 
                            postorder, postStart + numsLeft, postEnd - 1, inMap);
        
        return root;
    }
};

/*
    Optimized APproach
    Time COmplexity o(n*m)
    Space COmplexity o(n)
*/
class Solution {
private:
int findPosition(vector<int>inorder,int x ,int st,int en){
    for(int i = st ; i<=en;i++){
        if(inorder[i] == x){return i;}
    }
    return -1;
}
TreeNode* solve(vector<int>inorder, vector<int>postorder,int &postIndex , int inorderStart,int inorderEnd ,int n){
    if( postIndex < 0 || inorderStart > inorderEnd){
        return nullptr;
    }
    int element = postorder[postIndex--];
    TreeNode* root = new TreeNode(element);
    int positionIn = findPosition(inorder,element,inorderStart , inorderEnd);

    // Recursive Call LRN
    // Right Recursion
    root->right = solve(inorder,postorder,postIndex , positionIn+1 ,inorderEnd,n);
    // Left Recursion
    root->left = solve(inorder,postorder,postIndex ,inorderStart, positionIn-1 ,n);

return root;
}
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      int n = inorder.size();
      int postIndex  = n-1;
      TreeNode* ans = solve(inorder,postorder,postIndex , 0 , n-1,n);
      return ans;   
    }
};