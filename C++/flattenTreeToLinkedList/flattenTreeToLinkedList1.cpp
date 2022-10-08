//Using First Approach

// I WOULD PREFER YOU TO SEE THE APPROACH BY DIRECTLY SCROLLING DOWN TO THE "SOLUTION" CLASS.
// It is a simple recursive approach

//Time Complexity: O(n)
//Space Complexity: O(1)


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
    // "prev" pointer is to store the right pointer of the current node in the recursive call 
    Node* prev=NULL;
    void flatten(Node* root){
        if(root==NULL){
            return;
        }
        //move to the rightmost part till null node reaches
        flatten(root->right);
        //after the above step move the leftmost part 
        flatten(root->left);
        //make changes to the left and right pointer of the current node
        root->right=prev;
        root->left=NULL;
        //move to the node of the upper recursive call
        prev=root;
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