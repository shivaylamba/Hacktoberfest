/*
Duplicate Subtrees
Given a binary tree, your task is to find all duplicate subtrees from the given binary tree.
Duplicate Subtree : Two trees are duplicates if they have the same structure with the same node values.
Note:  Return the root of each tree in the form of a list array & the driver code will print the tree in pre-order tree traversal in lexicographically increasing order.
Examples:
Input :    1
          / \
         2   3
        /   / \
       4   2  4
          / \
         4
Output: 2 4   
        4
Explanation: The above tree have two duplicate subtrees.i.e 
  2
 /
4  and 4. Therefore, you need to return the above tree root in the form of a list.  
Input:     5
          / \
         4   6
        / \
       3   4
          / \
         3   6
Output: 
3
6
Explanation: In the above tree, there are two duplicate subtrees.i.e
3 and 6. Therefore, you need to return the above subtrees root in the form of a list. Here, 4 3  is not considered because for a subtree to be equal, it should have the same values as well as structure. If we consider the first subtree on the left, it has  
two children, 3 on the left and 4 3 6   on the right. And for the second subtree it has 3 on the left and 6 on the right.
Since the structures are not same for the subtrees hence they are not equal
*/
class Solution {
  public:
    string dfs(Node* root,vector<Node*>&ans,unordered_map<string,int>&map){
        if(!root) return "N"; // base case
        string s = to_string(root->data)   +','+    // Follow 
                   dfs(root->left,ans,map) +','+   // PreOrder (NLR) 
                   dfs(root->right,ans,map);       
        map[s]++;                                  
        if(map[s]==2){
            ans.push_back(root);
        }
        return s;
    }
    vector<Node*> printAllDups(Node* root) {
        // Code here
        unordered_map<string,int> map;
        vector<Node*> ans;
        dfs(root,ans,map);
        return ans;
    }
};