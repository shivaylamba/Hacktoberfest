/*
Height of Binary Tree
Given a binary tree, find its height.

Example 1:

Input:
     1
    /  \
   2    3
Output: 2
Example 2:

Input:
  2
   \
    1
   /
 3
Output: 3   
Your Task:
You don't need to read input or print anything. Your task is to complete the function height() which takes root node of the tree as input parameter and returns an integer denoting the height of the tree. If the tree is empty, return 0. 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= Number of nodes <= 105
1 <= Data of a node <= 109
*/
//{ Driver Code Starts
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
    if(!node) return 0;
    return 1+ max(height(node->left),height(node->right));
    }
};
//-------------------------------------------------------------------------------------------//
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
    int ans = 0 ;
    if(!node) return 0;
    ans = 1+ max(height(node->left),height(node->right));
    return ans;
    }
};
//-------------------------------------------------------------------------------------------//
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        if(node==nullptr){return 0;}
        int left = height(node ->left);
                int right = height(node ->right);
            int ans = max(left,right)+1;
        return ans ;

    }
};
