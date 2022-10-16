#include<iostream>
#include<queue>
#include<math.h>
#include<map>
#include<vector>
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
//pass map by reference
void vertical_order_print(node*root,int d, map<int,vector<int>> &m){
	//base case
	if(root==NULL){
		return;
	}
	//otherwise
	m[d].push_back(root->data);
	vertical_order_print(root->left,d-1,m);
	vertical_order_print(root->right,d+1,m);
	return;
	
	
}
	




int main()
{   
    int N;
    cin>>N;
	node* root = buildtreeLevel();
	map<int,vector<int>>m;
	int d=0;
	
	vertical_order_print(root,d,m);
	for(auto p:m){
		//cout<<p.first<<"->";
		for(int x:p.second){
			cout<<x<<",";
		}
		cout<<endl;
	}
	
}
