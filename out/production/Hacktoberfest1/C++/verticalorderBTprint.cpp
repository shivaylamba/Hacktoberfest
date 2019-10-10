#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;
struct node{
    int data;
    node * left;
    node * right;
    node(int data){
        this->data=data;
        left=right=NULL;
    }
};
node * createBtree(){
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
void preTraversal(node * root, map<int,vector <int> >&mymap, int key){
    if(!root){
        return;
    }
    mymap[key].push_back(root->data);
    preTraversal(root->left,mymap,key-1);
    preTraversal(root->right,mymap,key+1);
    return;
}
int main(){
    int n;
    cin>>n;
    node * root= createBtree();
    map<int,vector <int>> mymap;
    preTraversal(root,mymap,0);
    map<int,vector <int>> :: iterator it;
    for(it= mymap.begin(); it!=mymap.end();it++){
        vector<int> :: iterator it2;
        for(it2=it->second.begin();it2!=it->second.end();it2++){
            cout<<*it2<<" ";
        }
        cout<<endl;
    }
    return 0;
}


