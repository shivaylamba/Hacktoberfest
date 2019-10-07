#include <bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[], int x, int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
}

bool bfs(vector<int>adj[], int src, int des, int v, int pred[], int dist[]){
    queue<int> q;
    bool visited[v]; 
	for (int i = 0; i < v; i++) { 
		visited[i] = false; 
		dist[i] = INT_MAX; 
		pred[i] = -1; 
	} 
    visited[src] = true;
    dist[src] = 0;
    q.push(src);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++){
            if(visited[adj[u][i]]==false){
                visited[adj[u][i]]=true;
                dist[adj[u][i]] = dist[u]+1;
                pred[adj[u][i]] = u;
                q.push(adj[u][i]);
                
                if(adj[u][i]==des) return true;
            }
        }
    }
    return false;
}

void psd(vector<int> adj[], int src, int des, int v){
    int pred[v], dist[v];
    if(bfs(adj, src, des, v, pred, dist)==false){
        cout<<"Not connected";
        return;
    }

    vector<int>path;
    int crawl = des;
    path.push_back(crawl);
    while(pred[crawl]!=-1){
        crawl = pred[crawl];
        path.push_back(crawl);
    }
    
    for(int i = path.size()-1; i>=0; i--){
        cout<<path[i]<<" ";
    }
}

int main()
{
	int v = 8; 
	vector<int> adj[v]; 
	add_edge(adj, 0, 1); 
	add_edge(adj, 0, 3); 
	add_edge(adj, 1, 2); 
	add_edge(adj, 3, 4); 
	add_edge(adj, 3, 7); 
	add_edge(adj, 4, 5); 
	add_edge(adj, 4, 6); 
	add_edge(adj, 4, 7); 
	add_edge(adj, 5, 6); 
	add_edge(adj, 6, 7); 
	int source = 0, dest = 7; 
	psd(adj, source, dest, v); 
	return 0;
}
