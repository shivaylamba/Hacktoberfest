#include<bits/stdc++.h> 
using namespace std; 

void addEdge(vector<int> adj[], int u, int v) { 
	adj[u].push_back(v); 
	adj[v].push_back(u); 
} 

void DFSUtil(int u, vector<int> adj[], vector<bool> &visited) { 
	visited[u] = true; 
	cout << u << " "; 
	for (int i=0; i<adj[u].size(); i++) 
		if (visited[adj[u][i]] == false) 
			DFSUtil(adj[u][i], adj, visited); 
} 

void DFS(vector<int> adj[], int V) { 
	vector<bool> visited(V, false); 
	for (int u=0; u<V; u++) 
		if (visited[u] == false) 
			DFSUtil(u, adj, visited); 
} 

int main() { 
	int V,E,a,b;
	cin>>V>>E;
	vector<int> adj[V]; 
	for(int i=0;i<E;i++){
	    cin>>a>>b;
	    addEdge(adj, a, b);
	}
	DFS(adj, V); 
	return 0; 
} 
