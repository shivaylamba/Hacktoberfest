#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
class node {
public:
	int data;
	node* left;
	node* right;
	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};
node* buildtreeLevel()
{
	queue<node*>q;
	int d;
	cin >> d;
	node* root = new node(d);
	q.push(root);
	int c1, c2;
	while (!q.empty())
	{
		node* f = q.front();
		q.pop();
		cin >> c1 >> c2;
		if (c1 != -1)
		{
			f->left = new node(c1);
			q.push(f->left);
		}
		if (c2 != -1)
		{
			f->right = new node(c2);
			q.push(f->right);
		}
	}
	return root;
}

void leftView(node *root){
    if(root==NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=1;i<=n;i++){
            node* temp=q.front();
            q.pop();
            if(i==1){
                cout<<temp->data<<" ";
            }
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }
}
int main(){
    node* root = buildtreeLevel();
    leftView(root);
}
