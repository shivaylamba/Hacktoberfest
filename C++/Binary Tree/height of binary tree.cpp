#include<iostream>
using namespace std;

class node{
public:
	int data;
	node*left;
	node*right;
	
	node(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};
node* buildTree(){
	int d;
	cin>>d;
	if(d==-1){
		return NULL;
	}
	node* root=new node(d);
	root->left=buildTree();
	root->right=buildTree();
	return root;
}
void print(node* root){
	if(root==NULL){
		return;
	}
	//otherwise  , print the root first followed by subtrees
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}
int height(node* root){
	if(root==NULL){
		return 0;
	}
	int ls=height(root->left);
	int rs=height(root->right);
	return max(ls,rs)+1;
}
int main(){
	node* root=buildTree();
	print(root);
	cout<<endl;
	cout<<height(root)<<endl;
	
	return 0;
}
