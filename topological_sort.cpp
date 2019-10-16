# include <bits/stdc++.h>
#define flash ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define endl '\n'
#define ll long long int
#include <tr1/unordered_map>
#define ld long double
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f(i,a,b)  for(long long i=a;i<b;i++)
#define all(c) (c).begin(),(c).end()
#include <map>
using namespace std;
vector <int> vect[100];
bool vis[100];
int sol[100];
void ini()
{
	for(int i=0;i<10;i++)
	{
		vis[i]=false;
	}
}
int dfs(int i,int j)
{
	vis[j]=true;
	for(int k=0;k<vect[j].size();k++)
	{
		if(vis[vect[j][k]]==false)
		{
			i=dfs(i,vect[j][k]);
		}
	}
	sol[i]=j;
	return i-1;

}
void topo(int n)
{
	int i=n-1;
	for(int j=1;j<=n;j++)
	{
		if(vis[j]==false)
		{
			i=dfs(i,j);
		}
	}

}


int main()
{

#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\user\\Desktop\\coding problems\\in.txt","r",stdin);
    freopen("C:\\Users\\user\\Desktop\\coding problems\\output.txt","w",stdout);
  #endif


     flash;
     ///////////////////////////////////////////////////////////////////////////////////////

     
int n,e;
cin>>n>>e;
for(int i=0;i<e;i++)
{
int x,y;
cin>>x>>y;
vect[x].push_back(y);

}
topo(n);
for(int i=0;i<n;i++)
{
	cout<<sol[i]<<" ";
}





    ///////////////////////////////////////////////////////////////////////////////////////

     return 0;

}
