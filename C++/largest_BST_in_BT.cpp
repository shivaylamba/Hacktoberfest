// Largest BST in a Binary Tree.
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child and a
pointer to right child */
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

/* Helper function that allocates a new
node with the given data and NULL left
and right pointers. */
struct Node* newNode(int data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;

	return(node);
}

// Approach - TC O(N) SC O(N)

// Information to be returned by every
// node in bottom up traversal.
class Info {
public:
    // minNode -> minimum node in subtree
    // maxNode -> maximum node in subtree
    // maxSize -> maximum size of subtree which is BST
    int minNode, maxNode, maxSize;
    
    Info(int minNode, int maxNode, int maxSize) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

// Utility function -> traverse tree in bottom up fashion
Info largestBSTutil(Node* root) {
    // An empty tree is a BST of size 0.
    if (!root) return Info(INT_MAX, INT_MIN, 0); // set min as INT_MAX and max as INT_MIN
                                                 // so that it can return true at every condition
    
    
    // Get values from left and right subtree of current tree.
    auto left = largestBSTutil(root->left);
    auto right = largestBSTutil(root->right);
    
    // Current node is greater than max in left AND smaller than min in right, it is a BST.
    if (left.maxNode < root->data && root->data < right.minNode) {
        return Info(min(root->data, left.minNode), // minNode -> minimum of root data and minimum in left subtree
                    max(root->data, right.maxNode), // maxNode -> maximum of root data and maximum in right subtree
                    left.maxSize + right.maxSize + 1); // maxSize -> size of left and right + curr node
    }
    
    // Otherwise, return [-inf, inf] so that parent can't be valid BST
    return Info(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize)); // maxSize max of left and right
}

// function returns the size of largest bst in given binary tree
int largestBSTBT(Node* root){
    // call this util function and return the size of BST
    return largestBSTutil(root).maxSize;
}

/* Driver program to test above functions*/
int main() {
	/* Let us construct the following Tree
		60
	   / \
	  65 70
	 /
	50 */

	Node *root = newNode(60);
	root->left = newNode(65);
	root->right = newNode(70);
	root->left->left = newNode(50);
	cout << " Size of the largest BST is " << largestBSTBT(root) << endl;
	return 0;
}