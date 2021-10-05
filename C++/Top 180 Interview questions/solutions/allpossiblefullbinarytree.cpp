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
    vector<TreeNode*> allPossibleFBT(int n) {
       vector<TreeNode*> res;
       if(n==1)
       {
           TreeNode *temp = new TreeNode(0);
           res.push_back(temp);
           return res;
       }
       n--;
        // for root node
       for(int i = 1 ; i < n ; i = i + 2)
       {
           vector<TreeNode*> lefty = allPossibleFBT(i);
           vector<TreeNode*> righty = allPossibleFBT(n-i);
           for(TreeNode* it : lefty)
           {
               for(TreeNode* it2 : righty)
               {
                   // we will create the root here
                   TreeNode* cur = new TreeNode(0);
                   cur->left = it;
                   cur->right = it2;
                   res.push_back(cur);
               }
           }
       }
        return res;
    }
};