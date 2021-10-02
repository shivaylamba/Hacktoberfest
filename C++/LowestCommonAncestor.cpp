/*problem statement : Find lowest common ancestor.
  Input Format : 7
                 1 2 3 4 5 6 7
                 4 6
   Output :      1
*/
#include<bits/stdc++.h>
using namespace std;

struct Tree
{
  int key;
  struct Tree *left,*right;
};
//create Nodes
Tree *Node(int data)
{
  Tree * node=(Tree*)malloc(sizeof(Tree));
  node->key=data;
  node->left=node->right=NULL;
  return (node);
}

Tree* LevelOrder(int arr[],Tree* root,int i , int n)
{
  if(i<n)
  {
    Tree* tmp=Node(arr[i]);
    root=tmp;

    //left child
    root->left = LevelOrder(arr,root->left,2*i+1,n);

    //right child
    root->right=LevelOrder(arr,root->right,2*i+2,n);
  }

  return root;
}

Tree* LowestComAncestor(Tree* root ,int p,int q)
{
  if(root==NULL)
    return NULL;
  if(root->key == p || root->key == q) {
        return root;
    } else {
        // left sub tree
        struct Tree  *left = LowestComAncestor(root->left , p , q);
        // right sub tree
        struct Tree *right = LowestComAncestor(root->right , p, q);

        //if one node is in left and one is in right then root is LCA
        if(left && right) {
            return root;
        }
        /* If both nodes are in left sub tree
         return left  otherwise right */
        if(left) {
            return left;
        } else {
            return right;
        }
}
}

int main()
{

  int n,num;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
  cin>>arr[i];
  }
  //create tree from array
  Tree* root=LevelOrder(arr,root,0,n);

  int p,q;
  cin>>p>>q;
  cout<<LowestComAncestor(root,p,q)->key;
}
