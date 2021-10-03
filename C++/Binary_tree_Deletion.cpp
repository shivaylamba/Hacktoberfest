#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left,*right;
    Node(int value)
    {
        data=value;
        right=left=NULL;
    }
};

void  printBST(Node* root)
{
   if(root==NULL) return;
   printBST(root->left);
   cout<<root->data<<" ";
   printBST(root->right);
}

Node* inorderSucessor(Node* root)
{
  Node* curr =root;
  while(curr&&curr->left)
  {
    curr = curr->left;
  }
  return curr;
}

Node* DeleteBST(Node* root,int k)
{
  if (root == NULL) return root;

   if(root->data<k) root->right = DeleteBST(root->right,k);
   else if(root->data>k) root->left = DeleteBST(root->left,k);
   else
   {
     if(root->left==NULL&&root->right==NULL) {
         free(root);
         return NULL;
      }
     else if(root->left==NULL) {
           Node* t = root->right;
           free(root);
           return t;
        }
        else if(root->right==NULL) {
           Node* t = root->left;
           free(root);
           return t;
        }
        else{
            Node* temp = inorderSucessor(root->right);
            root->data = temp->data;
            root->right = DeleteBST(root->right,temp->data);
        }
   }
   return root;
}

int main()
{

  Node* root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(5);
  root->left->left = new Node(1);
  root->left->right = new Node(3);
  root->right->right = new Node(6);
  cout<<"before = ";
  printBST(root);
  cout<<endl;

int k;
cout<<"entre delete value = ";
cin>>k;
cout<<endl;
  root = DeleteBST(root,k);
  cout<<"after = ";
  printBST(root);

}
