#include <iostream>
#include <array>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
};
Node * newNode (int key){
    Node * node = new Node();
    node -> data = key;
    node -> left = node -> right = nullptr;
    return node;
}

void inorder(Node * root){
    if(root== nullptr){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node * insert(Node * root, int key){
    if(root == nullptr){
        return newNode(key);
    }
    if(key < root-> data){
        root->left=insert(root->left,key);
    }
    else if(key > root-> data){
        root->right=insert(root->right,key);
    }
    return root;
}
int main(){
    Node * root = nullptr;
    array<int,7> keys{15,10,20,8,12,16,25};
    for(int i=0;i<keys.size();i++){
        root= insert(root,keys[i]);
    }
    inorder(root);
    return 0;
}
