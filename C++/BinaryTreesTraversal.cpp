// PreOrder Traversal left side (---)
/* inorder traversal  
(
    left -> root -> right subtree
)
left trevel  => mark if no left look for right go back mark and see right

------------------------------------------------------------
POSTORDER TRAVERSAL

travell all left and right sub tree first then note post order sequence 

*/
#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inOrder(struct Node* root){

    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(struct Node* root){

    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void preorder(struct Node* root){

    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

int main(){

    struct Node* root =new Node(1);
    root -> left = new Node(2);
    root -> right =new Node(3);
    root -> right ->left  =new Node(4);
    root -> right ->right =new Node(5);
    preorder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);

    return 0;    
}
