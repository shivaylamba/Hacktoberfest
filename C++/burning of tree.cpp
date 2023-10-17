/*Given a binary tree and target node. By giving the fire to the target node and fire starts to spread in a complete tree. The task is to print the sequence of the burning nodes of a binary tree.
Rules for burning the nodes : 

Fire will spread constantly to the connected nodes only.
Every node takes the same time to burn.
A node burns only once.
Examples: 

Input : 
                       12
                     /     \
                   13       10
                          /     \
                       14       15
                      /   \     /  \
                     21   24   22   23
target node = 14

Output :
14
21, 24, 10
15, 12
22, 23, 13

Explanation : First node 14 burns then it gives fire to it's 
neighbors(21, 24, 10) and so on. This process continues until 
the whole tree burns.


Input :
                       12
                     /     \
                  19        82
                 /        /     \
               41       15       95
                 \     /         /  \
                  2   21        7   16
target node = 41

Output :
41
2, 19
12
82
15, 95
21, 7, 16
*/

// C++ implementation to print the sequence
// of burning of nodes of a binary tree
#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
	int key;
	struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}

// Utility function to print the sequence of burning nodes
int burnTreeUtil(Node* root, int target, queue<Node*>& q)
{
	// Base condition
	if (root == NULL) {
		return 0;
	}

	// Condition to check whether target
	// node is found or not in a tree
	if (root->key == target) {
		cout << root->key << endl;
		if (root->left != NULL) {
			q.push(root->left);
		}
		if (root->right != NULL) {

			q.push(root->right);
		}

		// Return statements to prevent
		// further function calls
		return 1;
	}

	int a = burnTreeUtil(root->left, target, q);

	if (a == 1) {
		int qsize = q.size();

		// Run while loop until size of queue
		// becomes zero
		while (qsize--) {
			Node* temp = q.front();

			// Printing of burning nodes
			cout << temp->key << " , ";
			q.pop();

			// Check if condition for left subtree
			if (temp->left != NULL)
				q.push(temp->left);

			// Check if condition for right subtree
			if (temp->right != NULL)
				q.push(temp->right);
		}

		if (root->right != NULL)
			q.push(root->right);

		cout << root->key << endl;

		// Return statement it prevents further
		// further function call
		return 1;
	}

	int b = burnTreeUtil(root->right, target, q);

	if (b == 1) {
		int qsize = q.size();
		// Run while loop until size of queue
		// becomes zero

		while (qsize--) {
			Node* temp = q.front();

			// Printing of burning nodes
			cout << temp->key << " , ";
			q.pop();

			// Check if condition for left subtree
			if (temp->left != NULL)
				q.push(temp->left);

			// Check if condition for left subtree
			if (temp->right != NULL)
				q.push(temp->right);
		}

		if (root->left != NULL)
			q.push(root->left);

		cout << root->key << endl;

		// Return statement it prevents further
		// further function call
		return 1;
	}
}

// Function will print the sequence of burning nodes
void burnTree(Node* root, int target)
{
	queue<Node*> q;

	// Function call
	burnTreeUtil(root, target, q);

	// While loop runs unless queue becomes empty
	while (!q.empty()) {
		int qSize = q.size();
		while (qSize > 0) {
			Node* temp = q.front();

			// Printing of burning nodes
			cout << temp->key;
			// Insert left child in a queue, if exist
			if (temp->left != NULL) {
				q.push(temp->left);
			}
			// Insert right child in a queue, if exist
			if (temp->right != NULL) {
				q.push(temp->right);
			}

			if (q.size() != 1)
				cout << " , ";

			q.pop();
			qSize--;
		}
		cout << endl;
	}
}

// Driver Code
int main()
{
	/*	 10
		/ \
		12 13
			/ \
			14 15
			/ \ / \
		21 22 23 24

		Let us create Binary Tree as shown
		above */

	Node* root = newNode(10);
	root->left = newNode(12);
	root->right = newNode(13);

	root->right->left = newNode(14);
	root->right->right = newNode(15);

	root->right->left->left = newNode(21);
	root->right->left->right = newNode(22);
	root->right->right->left = newNode(23);
	root->right->right->right = newNode(24);
	int targetNode = 14;

	// Function call
	burnTree(root, targetNode);

	return 0;
}
