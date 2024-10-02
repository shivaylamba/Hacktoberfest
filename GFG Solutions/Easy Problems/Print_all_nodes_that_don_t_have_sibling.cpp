/*
Print all nodes that don't have sibling
Given a Binary Tree of n nodes, find all the nodes that don't have any siblings. You need to return a list of integers containing all the nodes that don't have a sibling in sorted order (Increasing).

Two nodes are said to be siblings if they are present at the same level, and their parents are the same.

Note: The root node can not have a sibling so it cannot be included in our answer.

Example 1:

Input :
       37
      /   
    20
    /     
  113 

Output: 
20 113
Explanation: 
Nodes 20 and 113 dont have any siblings.

Example 2:

Input :
       1
      / \
     2   3 

Output: 
-1
Explanation: 
Every node has a sibling.
Your Task:  
You don't need to read input or print anything. Complete the function noSibling() which takes the root of the tree as input parameter and returns a list of integers containing all the nodes that don't have a sibling in sorted order. If all nodes have a sibling, then the returning list should contain only one element -1.

Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(Height of the tree)

Constraints:
1 ≤ n ≤ 104
*/

//User function Template for C++

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/*-------------------------------------- DFS --------------------------------------------*/
void dfs(Node* root,vector<int>&ans){
    if(!root)return;
    if(root->left && root->right){
        dfs(root->left,ans);
        dfs(root->right,ans);
    }
    else if(root->right){
        ans.push_back(root->right->data);
        dfs(root->right,ans);
    }
    else if(root->left){
        ans.push_back(root->left->data);
        dfs(root->left,ans);
    }
}
vector<int> noSibling(Node* node)
{
    // code here
    if(!node || (!node->left && !node->right)) return{-1};
    vector<int> ans;
    dfs(node,ans);
    if(ans.size()==0) return {-1};
    sort(ans.begin(),ans.end());
    return ans;
}

/*-------------------------------------- BFS --------------------------------------------*/
//User function Template for C++

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

vector<int> noSibling(Node* root)
{
    // code here
     // Base case  
  if (root == NULL)  
   return {-1};  
   
  queue<Node *> q1;
  q1.push(root);
 
  int flag=0;
  vector<int> v;
 
  // While q1 is not empty
  while(q1.empty() == false)
  {
       Node * temp=q1.front();
      q1.pop();
 
      // Check if temp->left is not
      // NULL and temp->right is NULL
      if(temp->left != NULL && 
                      temp->right == NULL)
      {
          flag=1;
          v.push_back(temp->left->data);
      }
 
      // Check if temp->left is equal
      // NULL and temp->right is not NULL
      if(temp->left == NULL && 
                        temp->right != NULL)
      {
          flag=1;
          v.push_back(temp->right->data);
      }
 
      // Check if temp->left is not
      // NULL
      if(temp->left != NULL)
      {
          q1.push(temp->left);
      }
     
      // Check if temp->right is not
      // NULL
      if(temp->right != NULL)
      {
          q1.push(temp->right);
      }
      
  }
       // Sort v in increasing order
  sort(v.begin(), v.end());
  if(v.size()==0) return {-1};
      return v;
}