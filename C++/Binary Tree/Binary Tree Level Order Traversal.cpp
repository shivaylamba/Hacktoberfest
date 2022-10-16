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

int height(node* root){
	if(root==NULL){
		return 0;
	}
	int ls=height(root->left);
	int rs=height(root->right);
	return max(ls,rs)+1;
}
//print kth level
void print_kth_level(node* root,int k){
	if(root==NULL){
		return;
	}
	if(k==1){
		cout<<root->data<<" ";
		return;
	}
	print_kth_level(root->left,k-1);
	print_kth_level(root->right,k-1);
	return;
}
//print all levels
void print_all_levels(node* root){
	int h=height(root);
	for(int i=1;i<=h;i++){
		print_kth_level(root,i);
		cout<<endl;
		
	}
	return;
}
int main(){
	node* root=buildTree();
	print_kth_level(root,3);
	cout<<endl<<endl;
	print_all_levels(root);
	
	return 0;
}
