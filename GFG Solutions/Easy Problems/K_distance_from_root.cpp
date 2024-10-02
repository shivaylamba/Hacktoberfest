/*
K distance from root
Given a binary tree having n nodes and an integer k. Print all nodes that are at distance k from the root (root is considered at distance 0 from itself). Nodes should be printed from left to right.

Example 1:

Input:
k = 0
      1
    /   \
   3     2
Output: 
1
Explanation: 
1 is the only node which is 0 distance from the root 1.
Example 2:

Input:
k = 3
        1
       /
      2
       \
        1
      /  \
     5    3
Output: 
5 3
Explanation:  
5 and 3 are the nodes which are at distance 3 from the root 3.
Here, returning 3 5 will be incorrect.
Your Task:
You don't have to take input. Complete the function Kdistance() that accepts root node and k as parameters and returns the value of the nodes that are at a distance k from the root.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= n <= 104
0 <= k <= 30
*/
// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/*
        DFS TRAVERSAL
    Time Complexity: O(n) where n is number of nodes in the given binary tree.
    Space Complexity : O(height of the binary tree).
If it’s true print the node – Always check the K distance == 0 at every node
the left or right subtree – Decrement the distance by 1 when you are passing to its subtree 
*/
class Solution
{
    private:
    void solve(struct Node* root,int k,vector<int>&ans){
         if(!root || k<0) return;
      if(k==0){
        ans.push_back(root->data);
        }
      solve(root->left,k-1,ans);
      solve(root->right,k-1,ans);
    }
    public:
    // function should print the nodes at k distance from root
    vector<int> Kdistance(struct Node *root, int k)
    {
      // Your code here
      vector<int> ans;
      solve(root,k,ans);
      return ans;
    }
};
/*
        LEVEL ORDER TRAVERSAL
    Time Complexity: O(n) where n is number of nodes in the given binary tree.
    Space Complexity: O(n) where n is number of nodes in the given binary tree.
*/
class Solution
{
    public:
    // function should print the nodes at k distance from root
    vector<int> Kdistance(struct Node *root, int k)
    {
      // Your code here
      if(!root) return {};
      if(k==0) return {root->data};
      vector<int> ans;
      queue<Node*> q;
      q.push(root);
      int dis = 0;
      while(!q.empty()){
          int n = q.size();
          if(k==dis){
              for(int i = 0 ; i<n;i++){
              ans.push_back(q.front()->data);
              q.pop();
          }
          return ans;
          }
          for(int i = 0 ; i<n;i++){
              Node* front = q.front();
              q.pop();
              if(front->left) q.push(front->left);
              if(front->right) q.push(front->right);
          }
          dis++;
      }
      return {};
    }
};