#include<iostream>
#include<queue>
using namespace std;
struct node{
    int data;
    node*left;
    node*right;
    node(int data)
    {
        this->data=data;
        left=right=NULL;
    }
    };
     node * create(){
    //cout<<"Enter data of root and -1 if empty"<<endl;
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
        //cout<<"Enter data for left of "<<top->data<<"-1 if empty"<<endl;
        cin>>data;
        if(data!=-1){
            node * temp = new node(data);
            top->left = temp;
            q.push(temp);
        }
        //cout<<"Enter data for right of "<<top->data<<"-1 if empty"<<endl;
        cin>>data;
        if(data!=-1){
            node * temp = new node(data);
            top->right = temp;
            q.push(temp);
        }
    }
    return root;
}
      void leftview(node*root)
{
    queue<node*>q1;
    q1.push(root);
    queue<node*>q2;
    while(!q1.empty() || !q2.empty())
        {
            int f=0;
    while(!q1.empty())
    {
        node*top=q1.front();
        q1.pop();
        if(f==0)
        {
        cout<<top->data<<" ";
        f=1;
        }
        if(top->left)
        {
            q2.push(top->left);
        }
        if(top->right)
        {
            q2.push(top->right);
        }

    }
    f=0;

            while(!q2.empty()){
        node*top=q2.front();
        q2.pop();
        if(f==0)
        {
        cout<<top->data<<" ";
        f=1;
        }
        if(top->left)
        {
            q1.push(top->left);
        }
        if(top->right)
        {
            q1.push(top->right);
        }
            }

    }
}


// 8 14 23 1 2 -1 7 -1 -1 -1 -1  5 -1 -1 -1
int main(){
node * root  = create();
leftview(root);
}
