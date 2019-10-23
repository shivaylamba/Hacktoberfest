#include<iostream>
#include<string>
#include<queue>>
#include<map>
using namespace std;
struct node{
    int data;
    node * left;
    node * right;

    node(int data){
        this->data = data;
        left = right = NULL;
    }
};
int height(node * root){
    if(!root){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left,right)+1;
}
node * create(){
    int data;
    cin>>data;
    node * root = NULL;
    if(data!=-1){
        root = new node(data);
    }
    queue<node *>q;
    q.push(root);
    while(!q.empty()){
        node * top = q.front();
        q.pop();
        cin>>data;
        if(data!=-1){
            node * temp = new node(data);
            top->left = temp;
            q.push(temp);
        }

        cin>>data;
        if(data!=-1){
            node * temp = new node(data);
            top->right = temp;
            q.push(temp);
        }
    }
    return root;
}
void preorder(node * root){
    if(!root){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}
void vertical(node*root,map<int,pair<int,int>> & mymap,int k)
{
    if(!root)
    {
        return;
    }
    int h=height(root);
    //map<int,pair<int,int>>::iterator it;
    if(mymap.find(k)==mymap.end())
    {
           mymap[k]=make_pair(root->data,h);
    }
    else
    {
        pair<int,int>p=mymap[k];
        if(h<=p.second)
        {
    mymap[k]=make_pair(root->data,h);
        }
}
    vertical(root->left,mymap,k-1);
    vertical(root->right,mymap,k+1);
}
void printv(map<int,pair<int,int>>mymap)
{
    map<int,pair<int,int>>::iterator it;
    pair<int,int>p;
    for(it=mymap.begin();it!=mymap.end();it++)
    {
        p=it->second;
        cout<<p.first<<" ";
    }
}
int main()
{
    node*root=create();
    map<int,pair<int,int>> mymap;
    vertical(root,mymap,0);
    printv(mymap);

}
