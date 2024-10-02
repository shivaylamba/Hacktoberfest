/*
Make Binary Tree From Linked List
Given a Linked List Representation of Complete Binary Tree. Your task is to construct the Binary tree from the given linkedlist and return the root of the tree.
The result will be judged by printing the level order traversal of the Binary tree. 
Note: The complete binary tree is represented as a linked list in a way where if the root node is stored at position i, its left, and right children are stored at position 2*i+1, and 2*i+2 respectively. H is the height of the tree and this space is used implicitly for the recursion stack.

Examples:

Input: list = 1->2->3->4->5
Output: 1 2 3 4 5
Explanation: The tree would look like
      1
    /   \
   2     3
 /  \
4   5
Now, the level order traversal of
the above tree is 1 2 3 4 5.
Input: list = 5->4->3->2->1
Output: 5 4 3 2 1
Explanation: The tree would look like
     5
   /  \
  4    3
 / \
2   1
Now, the level order traversal of
the above tree is 5 4 3 2 1.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).
Constraints:
1 <= size(list) <= 105
1 <= node.data <= 105
*/
class Solution {
  public:
    void convert(Node *head, TreeNode *&root) {
        queue<TreeNode*> q;
        root = new TreeNode(head->data);
        q.push(root);
        if(!head->next) return;
        head = head->next;
        while(head && !q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(head){
                front->left = new TreeNode(head->data);
                q.push(front->left);
                head = head->next;
            }
            if(head){
                front->right = new TreeNode(head->data);
                q.push(front->right);
                head = head->next;
            }
        }
    }
};