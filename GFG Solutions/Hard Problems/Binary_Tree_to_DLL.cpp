/*
Binary Tree to DLL
Given a Binary Tree (BT), convert it to a Doubly Linked List (DLL) in place. The left and right pointers in nodes will be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be the same as the order of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.
Note: h is the tree's height, and this space is used implicitly for the recursion stack.
TreeToList
Examples:
Input:
      1
    /  \
   3    2
Output:
3 1 2 
2 1 3
Explanation: DLL would be 3<=>1<=>2
Input:
       10
      /   \
     20   30
   /   \
  40   60
Output:
40 20 60 10 30 
30 10 60 20 40
Explanation:  DLL would be 40<=>20<=>60<=>10<=>30.
Expected Time Complexity: O(no. of nodes)
Expected Space Complexity: O(height of the tree)
Constraints:
1 ≤ Number of nodes ≤ 105
0 ≤ Data of a node ≤ 105
*/
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
class Solution {
  public:
  vector<Node*> inorder(Node* root){
      vector<Node*> ans;
      if(!root) return ans;
      vector<Node*> left = inorder(root->left);
      ans.insert(ans.end(),left.begin(),left.end());
      ans.push_back(root);
      vector<Node*> right = inorder(root->right);
      ans.insert(ans.end(),right.begin(),right.end());
      return ans;
  }
    Node* bToDLL(Node* root) {
        // code here
        vector<Node*>ans = inorder(root);
        root = ans[0];
        Node* node = root;
        node->left = nullptr;
        for(int i=1;i<ans.size();i++){
            Node* temp =  ans[i];
            node->right = temp;
            temp->left = node;
            node =temp;
        }
        node->right = nullptr;
        return root;
    }
};