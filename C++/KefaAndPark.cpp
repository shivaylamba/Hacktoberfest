// Kefa decided to celebrate his first big salary by going to the restaurant.

// He lives by an unusual park. The park is a rooted tree consisting of n vertices with the root at vertex 1. Vertex 1 also contains Kefa's house. Unfortunaely for our hero, the park also contains cats. Kefa has already found out what are the vertices with cats in them.

// The leaf vertices of the park contain restaurants. Kefa wants to choose a restaurant where he will go, but unfortunately he is very afraid of cats, so there is no way he will go to the restaurant if the path from the restaurant to his house contains more than m consecutive vertices with cats.

// Your task is to help Kefa count the number of restaurants where he can go.


//-----------जय श्री राम-----------




#include <bits/stdc++.h>

using namespace std;

#define int long long

#define all(x) (x).begin(), (x).end()

#define pb(x) push_back(x)

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int N=1e5+7;
int n,m;
vector<int> v[N];
vector<int> level(N,0);
vector<int> vis(N,0);
vector<int> con(N,0);
int arr[N];

void dfs(int i){
	vis[i]=1;
	for(auto&ch:v[i]){
		if(vis[ch])continue;
		if(arr[ch]==0)con[ch]=0;
		else con[ch]=con[i]+1;
		level[ch]=max(level[i],con[ch]);
		dfs(ch);
	}
}

signed main(){
     cin>>n>>m; 
    for(int i=1;i<=n;i++){
    	cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
    	int x,y;cin>>x>>y;
    	v[x].push_back(y);
    	v[y].push_back(x);
    }
    vis[1]=1;
    level[1]=arr[1];
    con[1]=arr[1];
    dfs(1);int ans=0;
    for(int i=2;i<=n;i++){
    	if(level[i]<=m and v[i].size()==1){
    		ans++;
    	}
    	
    }
    cout<<ans;
}
// input:
// 4 1
// 1 1 0 0
// 1 2
// 1 3
// 1 4
// 
// output:
// 2
