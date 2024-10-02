/*
Maximum sum of Non-adjacent nodes
Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.                                       
Example 1:
Input:
     11
    /  \
   1    2
Output: 11
Explanation: The maximum sum is sum of
node 11.
Example 2:
Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16
Explanation: The maximum sum is sum of
nodes 1 4 5 6 , i.e 16. These nodes are
non adjacent.
Your Task:
You don't need to read input or print anything. You just have to complete function getMaxSum() which accepts root node of the tree as parameter and returns the maximum sum as described.
Expected Time Complexity: O(Number of nodes in the tree).
Expected Auxiliary Space: O(Height of the Tree).
Constraints:
1 ≤ Number of nodes in the tree ≤ 10000
1 ≤ Value of each node ≤ 100000
*/
//User function Template for C++

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
/*
Expected Time Complexity: O(Number of nodes in the tree).
Expected Auxiliary Space: O(Height of the Tree).
*/
class Solution{
private:
    pair<int,int> solve(Node* root){
        if(!root){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
    // Traversing the Left and right Subtree using Recursion 
    pair<int,int> leftAns  = solve(root->left);
    pair<int,int> rightAns  = solve(root->right);
    
    int maxLeftAns =  max(leftAns.first,leftAns.second);
    int maxRightAns =  max(rightAns.first,rightAns.second);
    pair<int,int> ans;
    // if we include current node than we select the maximum and add current node
    ans.first = leftAns.second + rightAns.second + root->data;
    
    // if We exclude the current node than we we select the maximum and don't add the current node
    ans.second = maxLeftAns + maxRightAns;
    
    return ans;
    
    
    }
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
        // Solving By using Pair
    // first = include node at current Level
    // second = exclude nodes at currnet level
        pair<int,int> ans = solve(root);
        return max(ans.first,ans.second);
    }
};