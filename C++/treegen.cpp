#include <iostream>
#include<vector>
#include<queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInputlevelwise()
{
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size()!=0)
	{
		TreeNode<int>* front=pendingNodes.front();
		pendingNodes.pop();
		cout<<"Enter number of children of"<<front->data<<endl;
		int numChild;
		cin>>numChild;
		for(int i=0;i<numChild;i++)
		{
			int childData;
			cout<<"enter "<<i<<"th child of "<<front->data<<endl;
			cin>>childData;
			TreeNode<int> child(childData);
			front->children.push_back(&child);
		}
	}
}
void printAtLevelK(TreeNode <int>*root,int k)
{
	if (root == NULL) {
		return;
	}
	if(k==0)
	{
		cout<<root->data<<endl;
		return;
	}
	for(int i=0;i<root->children.size();i++)
	{
		printAtLevelK(root->children[i],k-1);
	}
}
void printLevelWise(TreeNode<int>* root) {
    if (root == NULL) {
		return;
	}
	
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        cout<<pendingNodes.front()->data<<":";
        for (int i = 0; i < pendingNodes.front()->children.size(); i++) 
        {
			cout << pendingNodes.front()->children[i]->data;
            if(i < pendingNodes.front()->children.size()-1)cout<<",";
		}
        cout<<endl;
        for (int i = 0; i < pendingNodes.front()->children.size(); i++) 
        {
			pendingNodes.push(pendingNodes.front()->children[i]);
		}
        pendingNodes.pop();
    }
}

void preorder(TreeNode<int>*root)
{
	if(root == NULL)
	{
		return;
	}
	cout<< root->data <<" ";
	for(int i=0;i< root->children.size();i++)
	{
		preorder(root->children[i]);
	}
}

int numNodes(TreeNode<int>* root)
{
	int ans=1;
	for(int i=0;i<root->children.size();i++)
	{
		ans+=numNodes(root->children[i]);
	}
	return ans;
}

TreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	int n;
	cout << "Enter num of children of " << rootData << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}
	return root;
}

void printTree(TreeNode<int>* root) {
	if (root == NULL) {
		return;
	}

	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size() ; i++) {
		printTree(root->children[i]);
	}
}

void deleteTree(TreeNode<int>* root)
{
	for(int i=0;i<root->children.size();i++)
	{
		deleteTree(root->children[i]);
	}
	delete root;
}

int main() {
	/*TreeNode<int>* root = new TreeNode<int>(1);
	TreeNode<int>* node1 = new TreeNode<int>(2);
	TreeNode<int>* node2 = new TreeNode<int>(3);
	root->children.push_back(node1);
	root->children.push_back(node2);
	*/
	TreeNode<int>* root = takeInput();
	printTree(root);
	cout<<numNodes(root);
	preorder(root);
	// TODO delete the tree
}

  