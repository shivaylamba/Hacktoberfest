#include <iostream>

using namespace std;

class node{
	public:
	int data;
	node * lchild;
	node * rchild;
};

node * insert(node *p,int key){
	node *t;
	if(p==NULL){
		t=new node;
		t->data=key;
		t->lchild=t->rchild=NULL;
		p=t;
	}
	else if(key<p->data){
		p->lchild=insert(p->lchild,key);
	}
	else if(key>p->data){
		p->rchild=insert(p->rchild,key);
	}
	return p;
	
}

void indisplay(node *p){
	if(p!=NULL){
		indisplay(p->lchild);
		cout<<p->data<<" ";
		indisplay(p->rchild);
	}
}

void predisplay(node *p){
	if(p!=NULL){
		cout<<p->data<<" ";
		predisplay(p->lchild);
		predisplay(p->rchild);
	}
}

int search(node *p,int key){
	if(p==NULL)
	   return 0;
	if(p->data==key)
	   return 1;
	else if(key<p->data)
	   search(p->lchild,key);
	else if(key>p->data)
	   search(p->rchild,key);
	
}

int main(){
	node * root=NULL;
	root=insert(root,10);
	insert(root,4);
	insert(root,11);
	insert(root,21);
	insert(root,1);
	insert(root,91);
	insert(root,81);
	cout<<"Inorder traversal: ";
	indisplay(root);
	cout<<endl;
	cout<<"Preorder traversal: ";
	predisplay(root);
	cout<<endl;
	cout<<"Enter a key to search: ";
	int key;
	cin>>key;
	search(root,key)?cout<<"Key found":cout<<"Key not found";
	
	return 0;
}
