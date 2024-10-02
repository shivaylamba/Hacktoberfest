/*
Normal BST to Balanced BST
Given a Binary Search Tree, modify the given BST such that it is balanced and has minimum possible height. Return the balanced BST.
Example1:
Input:
       30
      /
     20
    /
   10
Output:
     20
   /   \
 10     30
Example2:
Input:
         4
        /
       3
      /
     2
    /
   1
Output:
      3            3           2
    /  \         /  \        /  \
   1    4   OR  2    4  OR  1    3   
    \          /                  \ 
     2        1                    4

Your Task:
The task is to complete the function buildBalancedTree() which takes root as the input argument and returns the root of tree after converting the given BST into a balanced BST with minimum possible height. The driver code will print the height of the updated tree in output itself.
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
Here N denotes total number of nodes in given BST.
Constraints:
1 <= N <= 105
1 <= Node data <= 109
*/
/*Structure of the Node of the BST is as
struct Node
{
	int data;
	Node* left, *right;
};
*/

class Solution{
    
    public:
    // Your are required to complete this function
    // function should return root of the modified BST
    void inorder(Node* root,vector<int>&ans){
        if(!root) return ;
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    Node* inorderBST(int st,int en,vector<int>in){
        if(st>en) return nullptr;
        int mid = st +(en-st)/2;
        Node*node = new Node(in[mid]);
        node->left = inorderBST(st,mid-1,in);
        node->right = inorderBST(mid+1,en,in);
        
        return node;
    }
    Node* buildBalancedTree(Node* root)
    {
    	// Code here
    	vector<int> ans;
    	inorder(root,ans);
        return 	inorderBST(0,ans.size()-1,ans);
    	
    }
};