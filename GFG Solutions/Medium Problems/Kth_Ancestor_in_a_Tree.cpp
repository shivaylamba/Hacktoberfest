/*
Kth Ancestor in a Tree
Given a binary tree of size  N, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
Note:
1. It is guaranteed that the node exists in the tree.
2. All the nodes of the tree have distinct values.
Example 1:
Input:
K = 2 Node = 4
Output: 1
Explanation:
Since, K is 2 and node is 4, so we
first need to locate the node and
look k times its ancestors.
Here in this Case node 4 has 1 as his
2nd Ancestor aka the Root of the tree.
Example 2:

Input:
k=1 
node=3
      1
    /   \
    2     3

Output:
1
Explanation:
K=1 and node=3 ,Kth ancestor of node 3 is 1.
Your Task:
You are asked to complete the function kthAncestor() which accepts root of the tree, k and node as input parameters, and returns the kth ancestor of Node which contains node as its value.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1<=N<=105
1<= K <= 100
1 <= Node.data <= N
*/
//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
// Time Complexity O(n)
// Space Complexity O(n)
Node* solve(Node* root,int &k,int node){
    //Base Case
    if(!root) return nullptr;
    if(root->data == node)return root;
    
        Node* leftAns = solve(root->left,k,node);
            Node* rightAns = solve(root->right,k,node);
    
    // if leftNode not null ans rightNode is nullptr
    if(leftAns && !rightAns){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;}
            return leftAns;
    }
    // if rightNode not null ans LeftNode is nullptr
    if(!leftAns && rightAns){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;}
            return rightAns;
    }
    return nullptr;

}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node* ans = solve(root,k,node);
    //  if ans Node is nullptr or or ans->data is the root node data
    if(ans==nullptr || ans->data == node){
        return -1;
    }
        return ans->data;
    
}