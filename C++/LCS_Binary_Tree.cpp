//In this file i am going to give the solution for how to find lowest common ancestor of a given binary tree
class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
    
       if(!root or root->data==n1 or root->data==n2)
       return root;
       Node* left=lca(root->left,n1,n2);
       Node* right=lca(root->right,n1,n2);
       if(!left) return right;
       else if(!right) return left;
       else return root;
    }
};
