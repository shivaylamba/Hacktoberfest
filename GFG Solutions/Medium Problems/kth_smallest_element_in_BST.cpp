/*
k-th smallest element in BST
Given a BST and an integer K. Find the Kth Smallest element in the BST using O(1) extra space. 
Example 1:
Input:
      2
    /   \
   1     3
K = 2
Output: 2
Explanation: 2 is the 2nd smallest element in the BST
Example 2:
Input:
        2
      /  \
     1    3
K = 5
Output: -1
Explanation: There is no 5th smallest element in the BST as the size of BST is 3
Your Task
You don't need to read input or print anything. Your task is to complete the function KthSmallestElement() which takes the root of the BST and integer K as inputs and returns the Kth smallest element in the BST, if no such element exists return -1.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
Constraints:
1<=Number of nodes<=10^5
*/
/*Complete the function below

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

class Solution {
  public:
          int count = 0;
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int k) {
        // add code here.
        if(!root) return -1;
        int left = KthSmallestElement(root->left,k);
    if(left!=-1) return left;
    count++;
    if(count==k) return root->data;
    return KthSmallestElement(root->right,k);
    }
};