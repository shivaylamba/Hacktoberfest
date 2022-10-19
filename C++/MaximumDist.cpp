//-----------जय श्री राम-----------




#include <bits/stdc++.h>

using namespace std;

#define int long long

#define all(x) (x).begin(), (x).end()

#define pb(x) push_back(x)

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


int n,m;
const int N=1e5+7;
vector<int> vis(N,0);
vector<int> level(N,0);
vector<int> v[N];


void dfs(int i){
	vis[i]=1;
	// cout<<i<<" ";
	for(auto&x:v[i]){
		if(vis[x])continue;
		level[x]=level[i]+1;
		dfs(x);
	}
}
void reset(){
	for(auto&x:vis)x=0;
	for(auto&x:level)x=0;
}
void solve(){
	//start
    cin>>n>>m;
    for(int i=0;i<m;i++){
    	int x,y;cin>>x>>y;
    	v[x].pb(y);
    	v[y].pb(x);
    }
    
    dfs(1);
    // cout<<endl;
    int mx=0;
    int node=1;
    for(int i=1;i<=n;i++){
    	if(level[i]>mx){
    		node=i;
    		mx=level[i];
    	}
    }
    // cout<<mx;
    reset();
    int ans=0;
    dfs(node);
    for(int i=1;i<=n;i++){
    	ans=max(ans,level[i]);
    }
    cout<<ans;

}
signed main(){
    fast;
    int t=1;
    while(t--){
        solve();
        cout<<endl;
    }
}
