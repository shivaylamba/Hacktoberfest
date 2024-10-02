/*
Sum of Left Leaf Nodes
Given a Binary Tree of size N. Find the sum of all the leaf nodes that are left child of their parent of the given binary tree.

Example 1:

Input:
       1
     /   \
    2     3
Output: 2

Example 2:

Input : 
         1
        /  \
       2    3
     /  \     \
    4    5     8 
  /  \        /  \
 7    2      6    9
Output: 13
Explanation:
sum = 6 + 7 = 13
Your Task:
You don't need to read input or print anything. Your task is to complete the function leftLeavesSum() which takes the root node of the tree as input and returns the sum of all the left leaf nodes present in the given binary tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1<=Number of nodes<=105
*/
//-------------------------------------APPROACH -1 ----------------------------------------//
/*Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// function should return the sum of all 
// left leaf node
int leftLeavesSum(Node *root)
{
    // Code here
    int sum  = 0 ;
    if(!root) return 0;
    if(root->left && !root->left->left && !root->left->right) sum+=root->left->data;
    sum += leftLeavesSum(root->left) + leftLeavesSum(root->right);
return sum;
}
//-------------------------------------APPROACH -2 ----------------------------------------//
/*Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// function should return the sum of all 
// left leaf nodes
void sumLeftLeaves(Node* root,int &sum){
    if(!root) return;
    sumLeftLeaves(root->left,sum);
    sumLeftLeaves(root->right,sum);
    if(root->left && !root->left->left && !root->left->right) sum+=root->left->data;
    
}
int leftLeavesSum(Node *root)
{
    // Code here
    int sum  = 0 ;
    sumLeftLeaves(root,sum);
    return sum ; 
}