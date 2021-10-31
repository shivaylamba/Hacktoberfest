#include <iostream>
using namespace std;
struct node{
  int data;
  struct node *right,*left;
};
struct node *new_node(int val){
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->data=val;
    n->left=n->right=NULL;
    return n;
}
struct node *insert(struct node *root,int val){ //already having a binary tree
    if(root==NULL){
        return new_node(val);
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }else{
        root->right=insert(root->right,val);
    }
    return root;
}
void inorder(struct node *root){
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {
    
   struct node *root=NULL;
   int vals[]={15,10,20,8,12,16,25};
   for(int val:vals){
       root=insert(root,val);
   }
   inorder(root);

    return 0;
}
