//Using Second Approach

// I WOULD PREFER YOU TO SEE THE APPROACH BY DIRECTLY SCROLLING DOWN TO THE "SOLUTION" CLASS.
// It is a approach that is using stack for implementing or flattening a Binary Tree

//Time Complexity: O(n)
//Space Complexity: O(n)


#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left,right;
}
Node* newNode(int x){
    Node* node=new Node;
    node->data=x;
    node->left=node->right=NULL;
    return node;
}
Node* buildTree(string str){
    if(str.length()==0 || str[0]=='N')return NULL;
    vector<string> ip;
    istringstream iss(str);
    for(string str;iss>>str;){
        ip.push_back(str);
    }
    Node* root=newNode(stoi(ip[i]));
    queue<Node*> q;
    q.push(root);
    int i=1;
    wihle(!q.empty() && i<ip.size()){
        Node* currNode=q.front();
        q.pop();
        string currVal=ip[i];
        if(currVal!='N'){
            currNode->left=newNode(stoi(ip[i]));
            q.push(currNode->left);
        }
        i++;
    }
    return root;
}
void inorder(Node* root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
class Solution{
    public :
    
    void flatten(Node* root){
        stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        Node* curr=s.top();
        s.pop();

        //push right pointer first into the stack as the current node will point to the topmost 
        //stack element that will be(after poppinf out the current node) the left pointer of the current node
        if(curr->right)s.push(curr->right);
        if(curr->left)s.push(curr->left);

        //make changes to the left and right pointer of the current node
        if(!s.empty()){
        curr->right=s.top();
        curr->left=NULL;}
    }
    }
};
int main(){
    int t;
    cin>>t;
    getchar();
    while(t--){
        string str;
        getline(cin,str);
        Node* root=buildTree(str);
        Solution ob;
        ob.flatten(root);
        inorder(root);

        cout<<endl;
    }
    return 0;
}