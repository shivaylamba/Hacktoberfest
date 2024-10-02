/*
Remove Half Nodes
You are given a binary tree and you need to remove all the half nodes (which have only one child). Retrn the root node of the modified tree after removing all the half-nodes.
Note: The output will be judged by the inorder traversal of the resultant tree, inside the driver code.
Examples:
Input: tree = 5
            /   \
          7     8
        / 
      2
Output: 2 5 8
Explanation: In the above tree, the node 7 has only single child. After removing the node the tree becomes  2<-5->8. Hence, the answer is 2 5 8 & it is in inorder traversal.
Input:  tree = 2   
              / \   
            7   5 
Output: 7 2 5
Explanation: Here there are no nodes which has only one child. So the tree remains same.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(height of the binary tree)
Constraints:
1<=number of nodes<=104
*/
/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Return the root of the modified tree after removing all the half nodes.
class Solution {
  public:
    Node *RemoveHalfNodes(Node *root) {
        // code here
        if(!root) return root;
        root->left = RemoveHalfNodes(root->left);
        root->right = RemoveHalfNodes(root->right);
        if (!root->left && !root->right) return root;
        if(!root->left){ Node* temp = root->right ; free(root);return temp; }
        if(!root->right){ Node* temp = root->left ; free(root);return temp;;}
        
        
        return root;
    }
};