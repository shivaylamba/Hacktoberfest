#include <iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

//Accepts the old root node & data and returns the new root node 
node* insertInBST(node *root,int data){
    //Base Case
    if(root==NULL){
        return new node(data);
    }
    //Rec Case - Insert in the Subtree and Update Pointers
    if(data<=root->data){
        root->left = insertInBST(root->left,data);
    }
    else{
        root->right = insertInBST(root->right,data);
    }
    return root;
}

node* build(){
    //Read a list of numbers till -1 and also these numbers will be inserted into BST
    int d;
    cin>>d;

    node*root = NULL;

    while(d!=-1){
        root = insertInBST(root,d);
        cin>>d;
    }
    return root;
}

//Inorder Print
void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<",";
    inorder(root->right);
}
//searching
/*bool search(node* root,int data){
	if(root==NULL){
		return false;
	}
	if(root->data==data){
		return true;
	}
	//recursively search in left and right subtree
	if(data<=root->data){
		return search(root->left,data);
	}
	else{
		return search(root->right,data);
	}
}*/
node* delete_in_bst(node* root,int data){
	if(root==NULL){
		return NULL;
	}
	else if(data<root->data){
		root->left=delete_in_bst(root->left,data);
		
		
	}
	else if(data==root->data){
		//found the nodes to delete 3 cases
		//1. node with 0 children-leaf node
		if(root->left==NULL and root->right==NULL){
			delete root;
			return NULL;
		}
		//2.only one child
		if(root->left!=NULL and root->right==NULL){
			node *temp=root->left;
			delete root;
			return temp;
		}
		if(root->right!=NULL and root->left==NULL){
			node *temp=root->right;
			delete root;
			return temp;
		}
		//3. Node with two children
		//find the node to replace
		node *replace=root->right;
		while(replace->left!=NULL){
			replace=replace->left;
		}
		root->data=replace->data;
		root->right=delete_in_bst(root->right,replace->data);
		return root;
		
	}
	else{
		root->right=delete_in_bst(root->right,data);
	}
	
}
int main(){ 
    node*root = build();
    inorder(root);
    cout<<endl;
    int s;
    cin>>s;
    root=delete_in_bst(root,s);
    inorder(root);
    
    

return 0;
}
