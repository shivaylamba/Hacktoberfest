/*
Largest BST
Given a binary tree. Find the size of its largest subtree which is a Binary Search Tree.
Note: Here Size equals the number of nodes in the subtree.

Examples :

Input:   1
        /  \
        4   4              
       / \ 
      6   8
Output: 1 
Explanation: There's no sub-tree with size greater than 1 which forms a BST. All the leaf Nodes are the BSTs with size equal to 1.

Input:    6
        /   \
      6      2              
       \    / \
        2  1   3
Output: 3
Explanation: The following sub-tree is a BST of size 3:  2
                                                       /   \
                                                      1     3
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 106
*/
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
     vector<int> solve(Node *root){
        //{//size,TF,mini,maxi} left max<node<right min
        if(root == NULL){//null
            return {0,1,INT_MAX,INT_MIN};
        }
        {
            if(root->left==NULL && root->right==NULL){//leaf
                return {1,1,root->data,root->data};
            }
            vector<int>left=solve(root->left);
            vector<int>right=solve(root->right);
            
            int leftsize=left[0],LTF=left[1],leftmini=left[2],leftmaxi=left[3];
            int rightsize=right[0],RTF=right[1],rightmini=right[2],rightmaxi=right[3];
            if(LTF ==1 && RTF==1 && root->data>leftmaxi && root->data<rightmini){
                return {leftsize+rightsize+1,1,min(root->data,leftmini),max(root->data,rightmaxi)};
            }
            else{
                return {max(leftsize,rightsize),0,0,0};
            }
        }
    }
    
    int largestBst(Node *root)
    {
    	//codeGenius
    	return solve(root)[0];
    }
};