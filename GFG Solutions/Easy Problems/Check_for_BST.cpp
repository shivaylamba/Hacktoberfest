/*
Check for BST
Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
Input:
   2
 /    \
1      3
Output: 1 
Explanation: 
The left subtree of root node contains node
with key lesser than the root nodes key and 
the right subtree of root node contains node 
with key greater than the root nodes key.
Hence, the tree is a BST.
Example 2:

Input:
  2
   \
    7
     \
      6
       \
        5
         \
          9
           \
            2
             \
              6
Output: 0 
Explanation: 
Since the node with value 7 has right subtree 
nodes with keys less than 7, this is not a BST.
Your Task:
You don't need to read input or print anything. Your task is to complete the function isBST() which takes the root of the tree as a parameter and returns true if the given binary tree is BST, else returns false. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
0 <= Number of edges <= 100000
*/
/*
    APPROACH - 1
    - If the current node is null then return true
    - If the value of the left child of the node is greater than or equal to the current node then return false
    - If the value of the right child of the node is less than or equal to the current node then return false
    - If the left subtree or the right subtree is not a BST then return false
    - Else return true
Note: It is assumed that you have helper functions minValue() and maxValue() that return the min or max int value from a non-empty tree

Time Complexity: O(N2), As we visit every node just once and our helper method also takes O(N) time, so overall time complexity becomes O(N) * O(N) = O(N2)
Auxiliary Space: O(H), Where H is the height of the binary tree, and the extra space is used due to the function call stack.
*/
class Solution
{
    public:
    int maxValue(Node* node)
{
    if (node == NULL) {
        return INT16_MIN;
    }
    int value = node->data;
    int leftMax = maxValue(node->left);
    int rightMax = maxValue(node->right);
 
    return max(value, max(leftMax, rightMax));
}

    int minValue(Node* node)
{
    if (node == NULL) {
        return INT16_MAX;
    }
    int value = node->data;
    int leftMax = minValue(node->left);
    int rightMax = minValue(node->right);
 
    return min(value, min(leftMax, rightMax));
}
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* node) 
    {
  if (node == NULL)
        return 1;
 
    /* false if the max of the left is > than us */
    if (node->left != NULL
        && maxValue(node->left) >= node->data)
        return 0;
 
    /* false if the min of the right is <= than us */
    if (node->right != NULL
        && minValue(node->right) <= node->data)
        return 0;
 
    /* false if, recursively, the left or right is not a BST
     */
    if (!isBST(node->left) || !isBST(node->right))
        return 0;
 
    /* passing all that, it's a BST */
    return 1;
        
    }
};
/*
        =>Check BST using specified range of minimum and maximum values of nodes:
The isBSTUtil() function is a recursive helper function that checks whether a subtree 
(rooted at a given node) is a BST within the specified range of minimum (min) and 
maximum (max) values. If any node violates this range, the function returns false; 
otherwise, it continues checking the left and right subtrees.
    - Time Complexity: O(N), Where N is the number of nodes in the tree
    - Auxiliary Space: O(1), if Function Call Stack size is not considered, otherwise 
                             O(H) where H is the height of the tree
*/
class Solution{
public:
int isBSTUtil(Node* node, int min, int max);
 
/* Returns true if the given
tree is a binary search tree
(efficient version). */
int isBST(Node* node)
{
    return (isBSTUtil(Node, INT_MIN, INT_MAX));
}
 
/* Returns true if the given
tree is a BST and its values
are >= min and <= max. */
int isBSTUtil(Node* node, int min, int max)
{
    /* an empty tree is BST */
    if (node == NULL)
        return 1;
 
    /* false if this node violates
    the min/max constraint */
    if (node->data < min || node->data > max)
        return 0;
 
    /* otherwise check the subtrees recursively,
    tightening the min or max constraint */
    return isBSTUtil(node->left, min, node->data - 1)
       
           && // Allow only distinct values
           isBSTUtil(node->right, node->data + 1,
                     max); // Allow only distinct values
}
};
/*
                INRODER TRAVERSAL
=>  The idea is to use Inorder traversal of a binary search tree generates output, sorted in 
    ascending order. So generate inorder traversal of the given binary tree and check if the 
    values are sorted or not
Follow the below steps to solve the problem:
    - Do In-Order Traversal of the given tree and store the result in a temp array. 
    - Check if the temp array is sorted in ascending order, if it is, then the tree is BST.
Time Complexity: O(N), Where N is the number of nodes in the tree
Auxiliary Space: O(H), Here H is the height of the tree and the extra space is used due to the function call stack. 
*/
class Solution
{
    public:
bool isBSTUtil(Node* root, Node*& prev)
{
    // traverse the tree in inorder fashion and
    // keep track of prev node
    if (root) {
        if (!isBSTUtil(root->left, prev))
            return false;
 
        // Allows only distinct valued nodes
        if (prev != NULL && root->data <= prev->data)
            return false;
 
        prev = root;
 
        return isBSTUtil(root->right, prev);
    }
 
    return true;
}
 
bool isBST(Node* root)
{
    Node* prev = NULL;
    return isBSTUtil(root, prev);
}
};