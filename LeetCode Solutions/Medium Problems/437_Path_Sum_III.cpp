/*
437. Path Sum III
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
Example 1:
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
Example 2:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
Constraints:
The number of nodes in the tree is in the range [0, 1000].
-109 <= Node.val <= 109
-1000 <= targetSum <= 1000
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
private:
void pathSumFast(TreeNode* root,int k , int &count,vector<long long int>&path){
    if(!root) return ;

    path.push_back(root->val);
    pathSumFast(root->left,k,count,path);
    pathSumFast(root->right,k,count,path);
    long long int sum = 0;
    for(long long int i=path.size()-1;i>=0;i--){
        sum+=path[i];
        if(sum==k)
            count++;
    }
    path.pop_back();
}
public:
    int pathSum(TreeNode* root, int targetSum) {
        int count =0;
        vector<long long int> path;
        pathSumFast(root,targetSum,count,path);
        return count;
    }
};