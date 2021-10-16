

#include<bits/stdc++.h>
using namespace std;
 
// A binary tree node
struct Node
{
    int data;
    struct Node* left, *right;
};
 
//  insertion of a nw node dynamically
struct Node* newNode(int data)
{
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return (newNode);
}
 
// returns overall maximum path sum in 'res'

int findMaxUtil(Node* root, int &res)
{
    //Base Case
    if (root == NULL)
        return 0;
 
    // l and r store maximum path sum going through left and right child of root resp.
    
    int l = findMaxUtil(root->left,res);
    int r = findMaxUtil(root->right,res);
 
   
    int max_single = max(max(l, r) + root->data, root->data);
 
    
    int max_top = max(max_single, l + r + root->data);
 
    res = max(res, max_top); // Store the Maximum Result.
 
    return max_single;
}
 
// Returns maximum path sum in tree with given root
int findMaxSum(Node *root)
{
    // Initializing res
    int res = INT_MIN;
 
   
    findMaxUtil(root, res);
    return res;
}
 
// Driver code
int main(void)
{
    struct Node *root = newNode(10);
    root->left        = newNode(2);
    root->right       = newNode(10);
    root->left->left  = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left   = newNode(3);
    root->right->right->right  = newNode(4);
    cout << "Max path sum is " << findMaxSum(root);
    return 0;
}