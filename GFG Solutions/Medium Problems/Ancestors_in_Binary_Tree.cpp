/*
Ancestors in Binary Tree
Given a Binary Tree and an integer target. Find all the ancestors of the given target.
Note:
The ancestor of node x is node y, which is at the upper level of node x, and x is directly connected with node y. Consider multiple levels of ancestors to solve this problem.
In case there are no ancestors available, return an empty list.
Examples:
Input:
         1
       /   \
      2     3
    /  \    /  \
   4   5  6   8
  /
 7
target = 7
Output: [4 2 1]
Explanation: The given target is 7, if we go above the level of node 7, then we find 4, 2 and 1. Hence the ancestors of node 7 are 4 2 and 1
Input:
        1
      /   \
     2     3
target = 1
Output: [ ]
Explanation: Since 1 is the root node, there would be no ancestors. Hence we return an empty list.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(height of tree)
Constraints:
1 ≤ no. of nodes ≤ 103
1 ≤ data of node ≤ 104
*/
// User function template for C++
/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/
/*
    Most OPTIMZED APPROACH - 1
*/
class Solution {
  public:
    // Function should return all the ancestor of the target node
    bool solve(struct Node* root,int x,vector<int>&ans){
        if(!root) return 0;
        if(root->data  == x) return 1;
        
        if(solve(root->left,x,ans) || solve(root->right,x,ans)){
            ans.push_back(root->data);
            return 1;
        }
        return 0;
    }
    vector<int> Ancestors(struct Node *root, int target) {
        // Code here
        vector<int> ans;
        solve(root,target,ans);
        return ans;
    }
};
/*
    Most OPTIMZED APPROACH - 1
*/
class Solution {
  public:
    // Function should return all the ancestor of the target node
    struct Node* solve(struct Node* root,int x,vector<int>&ans){
        if(!root) return nullptr;
        if(root->data == x) return root;
    //  Search for the Target Nodes
    Node* leftAns = solve(root->left,x,ans);
    Node* rightAns = solve(root->right,x,ans);
    
    // backtrack
    if(!leftAns && rightAns){ ans.push_back(root->data); return rightAns;}
    else if(!rightAns && leftAns){ans.push_back(root->data); return leftAns;}
    else return nullptr;    
    }
    vector<int> Ancestors(struct Node *root, int target) {
        // Code here
        if(!root || root->data == target) return {};
        vector<int> ans;
        solve(root,target,ans);
        return ans;
    }
};