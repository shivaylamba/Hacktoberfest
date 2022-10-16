#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
class node {
public:
	int data;
	node* left;
	node* right;
	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};
node* buildtreeLevel()
{
	queue<node*>q;
	int d;
	cin >> d;
	node* root = new node(d);
	q.push(root);
	int c1, c2;
	while (!q.empty())
	{
		node* f = q.front();
		q.pop();
		cin >> c1 >> c2;
		if (c1 != -1)
		{
			f->left = new node(c1);
			q.push(f->left);
		}
		if (c2 != -1)
		{
			f->right = new node(c2);
			q.push(f->right);
		}
	}
	return root;
}

//assumption both a and b are present in the tree , all keys are unique.
node* lca(node*root,int a,int b){
	//base case
	if(root==NULL){
		return NULL;
	}
	//if root itself contains a and b
	if(root->data==a or root->data==b){
		return root;
	}
	//search in left and right subtree
	node*leftans=lca(root->left,a,b);
	node*rightans=lca(root->right,a,b);
	if(leftans!=NULL and rightans!=NULL){
		return root;
	}
	if(leftans!=NULL){
		return leftans;
	}
	return rightans;
	
}
int main(){
	node* root=buildtreeLevel();
	
	int a=6;
	int b=9;
	cout<<lca(root,6,9)->data<<endl;
}
