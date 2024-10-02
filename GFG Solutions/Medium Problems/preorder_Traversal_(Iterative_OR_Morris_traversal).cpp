/*
Inorder_Traversal_(Iterative_OR_Morris_traversal)
Given a Binary tree. Find the preorder traversal of the tree without using recursion.
Example 1:
Input:
           1
         /   \
        2     3
      /  \
     4    5
Output: 1 2 4 5 3
Explanation:
Preorder traversal (Root->Left->Right) of 
the tree is 1 2 4 5 3.
Example 2
Input:
            8
          /   \
         1      5
          \    /  \
           7  10   6
            \  /
            10 6
Output: 8 1 7 10 5 10 6 6 
Explanation:
Preorder traversal (Root->Left->Right) 
of the tree is 8 1 7 10 5 10 6 6.
Your task:
You don't need to read input or print anything. Your task is to complete the function preOrder() which takes the root of the tree as input and returns a list containing the preorder traversal of the tree, calculated without using recursion.
Expected time complexity: O(N)
Expected auxiliary space: O(N)
Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105
*/
//User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};
*/
class Solution{
    public:
    Node* findPredcessor(Node* curr){
        Node* temp = curr;
        if(!temp->left) return nullptr;
        temp = temp->left;
        while(temp->right && temp->right!=curr) temp= temp->right;
        
    return temp;
    }
    vector<int> preOrder(Node* root)
    {
        //code here
        vector<int> ans;
        Node* curr = root;
        while(curr){
            if(!curr->left){
                ans.push_back(curr->data);
                curr = curr->right;
            }
            else{
                Node* pre = findPredcessor(curr);
                if(!pre->right){
                    pre->right =curr;
                    ans.push_back(curr->data);
                    curr = curr->left;
                }
                else {
                    pre->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};