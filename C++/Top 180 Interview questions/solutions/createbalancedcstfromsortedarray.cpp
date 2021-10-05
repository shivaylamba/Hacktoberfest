// C++ implementation to construct a BST
// from its level order traversal
#include <bits/stdc++.h>

using namespace std;


// node of a BST
struct Node
{
	int data;
	Node *left, *right;
};


// function to get a new node
Node* getNode(int data)
{
	// Allocate memory
	Node *newNode =
		(Node*)malloc(sizeof(Node));
	
	// put in the data	
	newNode->data = data;
	newNode->left = newNode->right = NULL;	
	return newNode;
}


// function to construct a BST from
// its level order traversal
Node *LevelOrder(Node *root , int data)
{
	if(root==NULL){	
		root = getNode(data);
		return root;
	}
	if(data <= root->data)
	root->left = LevelOrder(root->left, data);
	else
	root->right = LevelOrder(root->right, data);
	return root;	
}

Node* constructBst(int arr[], int n)
{
	if(n==0)return NULL;
	Node *root =NULL;

	for(int i=0;i<n;i++)
	root = LevelOrder(root , arr[i]);
	
	return root;
}

// function to print the inorder traversal
void inorderTraversal(Node* root)
{
	if (!root)
		return;
	
	inorderTraversal(root->left);
	cout << root->data << " ";
	inorderTraversal(root->right);	
}


// Driver program to test above
int main()
{
	int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	Node *root = constructBst(arr, n);
	
	cout << "Inorder Traversal: ";
	inorderTraversal(root);
	return 0;	
}
