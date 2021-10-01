// Dijkstra's algorithm for shortest path/

#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6;
const int MOD = 1e9 + 7;
int n, p[N], dis[N];
vector<pair<int, int> > graph[N];
bool vis[N];

void dijkstra(int i){
	dis[i] = 0;
	set<pair<int, int> > s;
	s.insert({0, i}); 	// dis - node;
	while(!s.empty()){
		int e = s.begin()->second;
		int cost = s.begin()->first;
		s.erase(s.begin());
		for(auto edge : graph[e]){
			if(cost + edge.second < dis[edge.first]){
				dis[edge.first] = cost + edge.second;
				s.insert({dis[edge.first], edge.first});
			}
		}
	}
}

int main(){
	fast;
	ll t; cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; ++i){
			cin >> p[i];
			graph[i].push_back({i + 1, 1});
			graph[i].push_back({i - 1, 1});
			graph[i].push_back({p[i], 0});
		}
		for(int i = 1; i <= n; ++i) dis[i] = 1e9;
		dijkstra(1);
		cout << dis[n] << "\n";
		for(int i = 1; i <= n; ++i) graph[i].clear();
	}
	return 0;
}
