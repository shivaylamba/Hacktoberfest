/*
Predecessor and Successor
There is BST given with the root node with the key part as an integer only. You need to find the in-order successor and predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.
Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor. 
Example 1:
Input:
      8
    /   \
   1     9
    \     \
     4    10
    /
   3
key = 8 
Output: 4 9
Explanation: 
In the given BST the inorder predecessor of 8 is 4 and inorder successor of 8 is 9.
Example 2:

Input:
        10
      /   \
     2    11
   /  \ 
  1    5
      /  \
     3    6
      \
       4
key = 11
Output: 10 -1
Explanation:In given BST, the inorder predecessor of 11 is 10 whereas it does not have any inorder successor.
Your Task: You don't need to print anything. You need to update pre with the predecessor of the key or NULL if the predecessor doesn't exist and succ to the successor of the key or NULL if the successor doesn't exist. pre and succ are passed as an argument to the function findPreSuc(). Please note, The key may be located either inside or outside the tree.
Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).
Constraints: 
1 <= Number of nodes <= 104
1 <= key of node <= 107
1 <= key <= 107
*/
/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
/*
   WITHOUT USING RECURSION
Time Complexity o(n)
Space Complexity o(1)
*/
class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
          Node* temp=root;
        Node* pred=NULL;
        Node* succ=NULL;
        while(temp!=NULL&&temp->key!=key)
        {
            if(temp->key>key)
            {   succ=temp;
                temp=temp->left;
            }
            else{
                pred=temp;
                temp=temp->right;
            }
        }
        if(temp!=NULL)
        {
              Node* lefttree=temp->left;
        while(lefttree!=NULL)
        {
            pred=lefttree;
            lefttree=lefttree->right;
        }
          Node* righttree=temp->right;
        while(righttree!=NULL)
        {
            succ=righttree;
            righttree=righttree->left;
        }
        }
        pre=pred;
        suc=succ;
    }
};
/*
    USING RECURSION
Time Complexity o(n)
Space Complexity o(n)
*/
class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        if(!root) return ;
        if(root->key > key){
            if(!suc || suc &&suc->key >root-> key) suc =root;
        }
        else if(root->key < key){
            if(!pre || pre &&pre->key < root-> key) pre =root;
        }
        findPreSuc(root->left,pre,suc,key);
        findPreSuc(root->right,pre,suc,key);
    }
};