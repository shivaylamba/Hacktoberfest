/*
Inorder Traversal (Iterative)
Given a binary tree. Find the inorder traversal of the tree without using recursion.
Example 1
Input:
           1
         /    \
       2       3
      /   \
    4     5
Output: 4 2 5 1 3
Explanation:
Inorder traversal (Left->Root->Right) of 
the tree is 4 2 5 1 3.
Example 2
Input:
            8
          /   \
            1      5
             \    /  \
             7   10   6
             \  /
          10 6
Output: 1 7 10 8 6 10 5 6
Explanation:
Inorder traversal (Left->Root->Right) 
of the tree is 1 7 10 8 6 10 5 6.
Your task:
You don't need to read input or print anything. Your task is to complete the function inOrder() which takes the root of the tree as input and returns a list containing the inorder traversal of the tree, calculated without using recursion.
Expected time complexity: O(N)
Expected auxiliary space: O(N)
Constraints:
1 <= Number of nodes <= 105
1 <= Data of a node <= 105
*/
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    Node* findPredcessor(Node* curr){
        Node* temp =curr;
        if(!temp->left) return nullptr;
        temp = temp->left;
        while(temp->right!=nullptr && temp->right != curr ) temp = temp->right;
        
        return temp;
    }
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> ans;
        Node*curr = root;
        while(curr){
            if(!curr->left){
                ans.push_back(curr->data);
                curr=curr->right;
            }
            else{
                Node* predcessor = findPredcessor(curr);
                if(!predcessor->right){
                    predcessor->right = curr;
                    curr = curr->left;
                }
                else{
                    predcessor->right = nullptr;
                      ans.push_back(curr->data);
                    curr =curr->right;
                }
            }
        }
        return ans;
    }
};