/*
Lowest Common Ancestor in a BST
Given a Binary Search Tree (with all values unique) and two node values n1 and n2 (n1!=n2). Find the Lowest Common Ancestors of the two nodes in the BST.
Example 1:
Input:
              5
            /   \
          4      6
         /        \
        3          7
                    \
                     8
n1 = 7, n2 = 8
Output: 7
Example 2:
Input:
     2
   /   \
  1     3
n1 = 1, n2 = 3
Output: 2
Your Task:
You don't need to read input or print anything. Your task is to complete the function LCA() which takes the root Node of the BST and two integer values n1 and n2 as inputs and returns the Lowest Common Ancestor of the Nodes with values n1 and n2 in the given BST. 
Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).
Constraints:
1 <= N <= 104
*/
//Function to find the lowest common ancestor in a BST.
/*
  Time Complexity: O(H). where H is the height of the tree
Auxiliary Space: O(1). The space complexity of the above solution is constant.
*/
class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
            while (root != NULL) {
        // If both n1 and n2 are smaller than root,
        // then LCA lies in left
        if (root->data > n1 && root->data > n2)
            root = root->left;
        // If both n1 and n2 are greater than root,
        // then LCA lies in right
        else if (root->data < n1 && root->data < n2)
            root = root->right;
        else
            break;
    }
    return root;
        } 
};
/*
  Time Complexity: O(H). where H is the height of the tree.
Auxiliary Space: O(H), If recursive stack space is ignored, the space complexity of the above solution is constant.
*/
class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
            // code here
            if(!root) return nullptr;
            int curr = root->data;
            if(curr < n1 && curr <n2) return  LCA(root->right,n1,n2);
            if(curr > n1 && curr > n2)return  LCA(root->left,n1,n2);
            return root;
        } 
};
