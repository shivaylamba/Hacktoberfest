#include<iostream>
#include<queue>
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
void bfs(node* root){
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		node* f=q.front();
		cout<<f->data<<" ";
		q.pop();
		if(f->left){
			q.push(f->left);
			
		}
		if(f->right){
			q.push(f->right);
		}
		
	}
	return;
}
int main(){
	node* root=buildTree();
	bfs(root);

	
	return 0;
}
