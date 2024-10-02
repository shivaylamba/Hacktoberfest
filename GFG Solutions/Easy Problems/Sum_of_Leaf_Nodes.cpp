/*
Sum of Leaf Nodes
Given a Binary Tree of size N. The task is to complete the function sumLeaf(), that should return the sum of all the leaf nodes of the given binary tree.
Input:
First line of input contains number of testcases T. For each testcase, there will be two lines, first of which containing the number of edges (between two nodes) in the tree. Next line contains N pairs (considering a and b) with a 'L' (means node b on left of a) or 'R' (means node b on right of a) after a and b.
Output:
For each testcase, there will be a single line containing the sum of all leaf nodes in the tree.
User Task:
The task is to complete the function sumLeaf() which takes root reference as argument and returns the sum of all leaf nodes.
Constraints:
1 <= T <= 100
1 <= N <= 103
Example:
Input:
2
2
1 2 L 1 3 R
5
10 20 L 10 30 R 20 40 L 20 60 R 30 90 L
Output:
5
190
Explanation:
Testcase 1: Leaf nodes in the tree are 2 and 3, and their sum is 5.
*/
/*Structure of the node of the binary tree is as
struct Node
{
	int data;
	Node *left, *right;
};*/
// function should return the sum of all the 
// leaf nodes of the binary tree 
void solve(Node* root,int&sum){
     if(!root) return;
    if(root && !root->left && !root->right){sum+=root->data;}
    solve(root->left,sum);
    solve(root->right,sum);
}
int sumLeaf(Node* root)
{
    // Code here
    int sum = 0;
    solve(root,sum);
    return sum;
}