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
void print_inorder(node* root){
	if(root==NULL){
		return;
	}
	print_inorder(root->left);
	cout<<root->data<<" ";
	print_inorder(root->right);
}
void print_postorder(node* root){
	if(root==NULL){
		return;
	}
	print_postorder(root->left);
	print_postorder(root->right);
	cout<<root->data<<" ";
}
int main(){
	node* root=buildTree();
	print(root);
	cout<<endl;
	print_inorder(root);
	cout<<endl;
	print_postorder(root);
}
