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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // this is a very good question
        vector<vector<int>> v;
        // THIS  will be out answer
        unordered_map<int,vector<int>> um;
        // to store the array of nodes having the same distance and their corresponding
        // distance
        queue<pair<TreeNode*, int>>q;
        q.push(make_pair(root,0));
        int mini=INT_MAX;
        int maxi=INT_MIN;
        // this min and max value will help in printing
        while(!q.empty())
        {
            TreeNode* curr= q.front().first;
            int val=q.front().second;
            // this val is basically the distance
            q.pop();
            mini=min(mini,val);
            maxi=max(maxi,val);
            um[val].push_back(curr->val);
            // setting the unordered map at that value
            // setting up its entire array
            if(curr->left)
                q.push(make_pair(curr->left,val-1));
            if(curr->right)
                q.push(make_pair(curr->right,val+1));
            // on the left the distance needs to be reduced to one and
            // on the right the distance needs to be increased to 1
        }
        while(mini<=maxi)
        {
        vector<int> temp;
            // temporary vector to push into the main result
        if(um.find(mini)!=um.end())
        {
            for(auto it : um[mini])
                temp.push_back(it);
        }
            v.push_back(temp);
            mini=mini+1;
        }
        return v;
    }
};