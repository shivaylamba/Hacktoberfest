/*
Populate Inorder Successor for all nodes
Given a Binary Tree, complete the function to populate the next pointer for all nodes. The next pointer for every node should point to the Inorder successor of the node.
You do not have to return or print anything. Just make changes in the root node given to you.

Note: The node having no in-order successor will be pointed to -1. You don't have to add -1 explicitly, the driver code will take care of this.

Examples :

Input:
       10
       /  \
      8   12
     /
    3
Output: 3->8 8->10 10->12 12->-1
Explanation: The inorder of the above tree is : 3 8 10 12. So the next pointer of node 3 is pointing to 8 , next pointer of 8 is pointing to 10 and so on.And next pointer of 12 is pointing to -1 as there is no inorder successor of 12.
Input:
       1
      /  
     2 
   /
 3  
Output: 3->2 2->1 1->-1
Explanation: The inorder of the above tree is: 3 2 1. So the next pointer of node 3 is pointing to 2 , next pointer of 2 is pointing to 1. And next pointer of 1 is pointing to -1 as there is no inorder successor of 1.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1<= no. of nodes <=105
1<= data of the node <=105
*/
/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/
class Solution {
  public:
void inorder(Node *root,vector<Node*>&ans){
      //base case
      if(root != NULL){
      //recursive case
      inorder(root->left,ans);
      ans.push_back(root);
      inorder(root->right,ans);
  }
  }
    void populateNext(Node *root) {
        // code here
        vector<Node*>ans;
        inorder(root,ans);
        for(int i=0;i<ans.size()-1;i++){
            ans[i]->next=ans[i+1];
        }
    }
};