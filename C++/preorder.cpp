#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
node* buildtree()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node *n=new node(d);
    n->left=buildtree();
    n->right=buildtree();
    return n;
}
void printpreorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right);
}
void printinorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);
}
void printpostorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    printpostorder(root->left);
    printpostorder(root->right);
    cout<<root->data<<" ";
}
void levelorderprint(node *root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node *temp=q.front();
        if(temp==NULL)
        {
            cout<<endl;
            q.pop();
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return;
}
node* levelorderbuild()
{
    int d;
    cin>>d;
    node* root=new node(d);
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        int c1, c2;
        cin>>c1>>c2;
        if(c1!=-1)
        {
            temp->left=new node(c1);
            q.push(temp->left);
        }
        if(c2!=-1)
        {
            temp->right=new node(c2);
            q.push(temp->right);
        }
    }
    return root;
}
int height(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    // if(h1>h2)
    // {
    //     return h1+1;
    // }
    // else return h2+1;
    int h=max(h1,h2)+1;
    return h;
}
int diameter(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int d1=height(root->left)+height(root->right)+1;
    int d2=diameter(root->left);
    int d3=diameter(root->right);
    return max(d1,max(d2,d3));
}
void printroottoleafpath(node* root,vector<int> &path)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        for(int x:path)
        {
            cout<<x<<"->";
        }
        cout<<root->data;
        cout<<endl;
        return;
    }
    path.push_back(root->data);
    printroottoleafpath(root->left,path);
    printroottoleafpath(root->right,path);
    path.pop_back();
    return;
}
bool search(node* root,int n)
{
    if(root==NULL)
    {
        return false;
    }
    if(n==root->data)
    {
        return true;
    }
    if(n<root->data)
    {
        return search(root->left,n);
    }
    return search(root->right,n);
}
bool search2(node*root,int n)
{
    while(root!=NULL)
    {
        if(n<root->data)
        {
            root=root->left;
        }
        else if(n>root->data)
        {
            root=root->right;
        }
        else
        {
            return true;
        }
    }
    return false;
}
int minimum(node* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root->data;
}
int maximum(node* root)
{
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root->data;
}
int main()
{
    node *root=buildtree();
    // printpreorder(root);
    // cout<<endl;
    // printinorder(root);
    // cout<<endl;
    // printpostorder(root);
    // cout<<endl;
    // levelorderprint(root);
    // cout<<endl;
    // cout<<height(root);
    //cout<<height(root)<<endl;
    // vector<int> path;
    // printroottoleafpath(root,path);
    // cout<<diameter(root);
    // cout<<search2(root,2);
    cout<<maximum(root)<<endl;
    cout<<minimum(root)<<endl;
    return 0;
}
//15 6 3 2 -1 -1 4 -1 -1 7 -1 13 -1 9 -1 -1 18 17 -1 -1 20 -1 -1