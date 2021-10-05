/* Author : VANSH KAPILA */

/* "The greatest glory in living lies not in never falling, but in rising every time we fall." -*/

#include <bits/stdc++.h>
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define int long long
#define ld long double
#define endl "\n";

#define f(a,b) for(int i=a;i<b;i++)
#define fr(a,b) for(int i=a;i>b;i--)

const int mod = 1000000007;
using namespace std;

class node
{
public:
	node* right;
	node* left;
	int data;
};

node* buildtree()
{
	int d;
	cin >> d;

	if (d == -1)
	{
		return NULL;
	}

	node* root = new node();
	root->data = d;
	root->left = buildtree();
	root->right = buildtree();

	return root;
}

void print(node* root)
{
	if (root == NULL)
	{
		return;
	}
}

int height(node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int l = height(root->left);
	int r = height(root->right);

	if (l <= r)
	{
		return r + 1;
	}
	else
	{
		return l + 1;
	}
}

void printlevel(node* root, int k)
{
	if (root == NULL)
	{
		return;
	}

	if (k == 1)
	{
		cout << root->data << ' ';
		return;
	}

	printlevel(root->left, k - 1);
	printlevel(root->right, k - 1);




}

void bfs(node* root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	
	while (!q.empty())
	{
		node* x = q.front();
		q.pop();
        
        if (x == NULL)
		{	
			cout << endl; 
			if(!q.empty()){
			q.push(NULL);}
			continue;
		}
		
		cout << x->data << ' ';
		
		if (x!=NULL and x->left != NULL) {
			q.push(x->left);
		}

		if (x!=NULL and x->right != NULL) {
			q.push(x->right);
		}
	}
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	node* root;

	root = buildtree();

	bfs(root);
	return 0;
}